package BU.MET.CS755;

import java.io.IOException;  
import java.util.*;

import org.apache.hadoop.fs.Path; 
import org.apache.hadoop.fs.FileSystem; 
import org.apache.hadoop.fs.FSDataOutputStream;
import org.apache.hadoop.io.*;
import org.apache.hadoop.*; 
import org.apache.hadoop.mapred.*; 

public class GADriver {

    public static void usage() throws Exception
    {
	System.out.println("Usage: BU.MET.CS755.GADriver <output dir> <pool size> <target> <generations>");
	System.out.println("  Pool Size must be even");
	System.exit(0);
    }

    public static void createInitChromosomes(String output,
					     int poolSize,
					     int target) throws Exception
    {
	JobClient client = new JobClient(); 
	JobConf conf = new JobConf(GADriver.class); 

	FileSystem fs = FileSystem.get(conf);

	Path outFile = new Path(output + "/init/chromosomes.txt");

	if (fs.exists(outFile)) {
	    System.out.println("Initial chromosomes file already exists!");
	    System.exit(0);
	}

	FSDataOutputStream out = fs.create(outFile);

	for (int index = 0; index < poolSize; index++) {
	    Chromosome c = new Chromosome(target);
	    out.writeChars(c.chromo.toString());
	    out.writeChars("\n");
	}

	out.close();
    }// createGen0

    public static class ScoreMapper extends MapReduceBase implements Mapper<LongWritable, Text, Text, DoubleWritable> {  
	public static int target;
	public void configure(JobConf job) {
	    target = Integer.parseInt(job.get("Target"));
	}
	
	public void map(LongWritable key, Text value, OutputCollector<Text, DoubleWritable> output, Reporter reporter) throws IOException {  
	    StringBuffer sb = new StringBuffer();
	    
	    // :NOTE: 20130718 tgl: Wasted over an hour on this.  The
	    // character encoding between Text & String & StringBuffer
	    // is not the same.  Do this to get the right value into
	    // Chromosome.
	    for (int i = 1; i < value.getLength(); i=i+2) {
		if (49 == value.charAt(i)) {
		    sb.append("1");
		} else {
		    sb.append("0");
		}
	    }

	    Chromosome c = new Chromosome(sb);
	    c.scoreChromo(target);

	    output.collect(new Text(sb.toString()),
			   new DoubleWritable(c.score));
	}  
    }  
    

    /**
     * This mapper groups the populaton.  The reducer can then
     * 'reproduce' within each group.
     */
    public static class SelectMap extends MapReduceBase implements Mapper<LongWritable, Text, VIntWritable, Text> {
	// :NOTE: 20130717 tgl: This value should be adjusted based on
	// overall population size, and memory capacity of Hadoop
	// node.
	public int groups = 10;

	public Random random = new Random();

	public VIntWritable out = new VIntWritable();

	public void map(LongWritable key, Text value, OutputCollector<VIntWritable, Text> output, Reporter reporter) throws IOException {
	    out.set(random.nextInt(groups));
	    output.collect(out, value);
	}
    }

    /**
     * Iterate over the group given by the mapper. Reproduce, report.
     */
    public static class SelectReduce extends MapReduceBase implements Reducer<VIntWritable, Text, Text, DoubleWritable> {  
	public Random rand = new Random();
	public static int target;
	public static int gen;
	public void configure(JobConf job) {
	    target = Integer.parseInt(job.get("Target"));
	    gen = Integer.parseInt(job.get("Generation"));
	}

	public void reduce(VIntWritable key, Iterator<Text> values, OutputCollector<Text, DoubleWritable> output, Reporter reporter) throws IOException {  
	    ArrayList pool = new ArrayList();
	    Iterator<Text> tr = values;
	    Text v;
	    while (tr.hasNext()) {
		v = tr.next();
		
		StringBuffer sb = new StringBuffer();
		// :KLUGE: 20130717 tgl: This again.
		for (int idx = 1; idx < v.getLength(); idx=idx+2) {
		    if (49 == v.charAt(idx)) {
			sb.append("1");
		    } else {
			sb.append("0");
		    }
		}
		
		Chromosome c = new Chromosome(sb);
		pool.add(c);
	    }
	    
	    while (pool.size() > 1) {
		// Select two members
		Chromosome n1 = selectMember(pool);
		Chromosome n2 = selectMember(pool);
				
		// Cross over and mutate
		n1.crossOver(n2);
		n1.mutate();
		n2.mutate();
				
		// Rescore the nodes
		n1.scoreChromo(target);
		n2.scoreChromo(target);
				
		// Check to see if either is the solution
		if (n1.total == target && n1.isValid()) { System.out.println("Generations: " + gen + "  Solution: " + n1.decodeChromo()); return; }
		if (n2.total == target && n2.isValid()) { System.out.println("Generations: " + gen + "  Solution: " + n2.decodeChromo()); return; }
				
		// Add to the new pool
		output.collect(new Text(n1.chromo.toString()),
			       new DoubleWritable(n1.score));
		output.collect(new Text(n2.chromo.toString()),
			       new DoubleWritable(n2.score));
	    }
	}
	
	public Chromosome selectMember(ArrayList l) {
	    // Get the total fitness		
	    double tot=0.0;
	    for (int x=l.size()-1;x>=0;x--) {
		double score = ((Chromosome)l.get(x)).score;
		tot+=score;
	    }
	    double slice = tot*rand.nextDouble();
	    
	    // Loop to find the node
	    double ttot=0.0;
	    for (int x=l.size()-1;x>=0;x--) {
		Chromosome node = (Chromosome)l.get(x);
		ttot+=node.score;
		if (ttot>=slice) { l.remove(x); return node; }
	    }
	    
	    return (Chromosome)l.remove(l.size()-1);
	}// selectMember
    }  
    
    public static void scoreGen0(String path, int target) throws Exception
    {
	JobClient client = new JobClient(); 
	JobConf conf = new JobConf(GADriver.class); 
	conf.setJobName("Genetic Algorithm Gen0 Score"); 
  
	conf.setMapperClass(ScoreMapper.class); 
	conf.setReducerClass(org.apache.hadoop.mapred.lib.IdentityReducer.class);

	conf.setOutputKeyClass(Text.class);
	conf.setOutputValueClass(DoubleWritable.class);
  
	conf.set("Target", Integer.toString(target));

	FileInputFormat.setInputPaths(conf, new Path(path + "/init"));
	FileOutputFormat.setOutputPath(conf, new Path(path + "/gen0"));
  
	client.setConf(conf); 
	try { 
	    JobClient.runJob(conf); 
	} catch (Exception e) { 
	    e.printStackTrace(); 
	} 
    }// scoreGen0

    public static void reproduce(String path, int index, int target) throws Exception
    {
	JobClient client = new JobClient(); 
	JobConf conf = new JobConf(GADriver.class); 
	conf.setJobName("Genetic Algorithm Reproduce"); 
  
	conf.setMapperClass(SelectMap.class); 
	conf.setReducerClass(SelectReduce.class);

	conf.setOutputKeyClass(VIntWritable.class);
	conf.setOutputValueClass(Text.class);
  
	conf.set("Target", Integer.toString(target));
	conf.set("Generation", Integer.toString(index));

	FileInputFormat.setInputPaths(conf, new Path(path + String.format("/gen%d", index)));
	FileOutputFormat.setOutputPath(conf, new Path(path + String.format("/gen%d", index+1)));
  
	client.setConf(conf); 
	try { 
	    JobClient.runJob(conf); 
	} catch (Exception e) { 
	    e.printStackTrace(); 
	} 

    }// reproduce

    public static void main(String[] args) throws Exception
    {
	if (args.length < 4) {
	    usage();
	}	

	String output = args[0];
	int poolSize = Integer.parseInt(args[1]);
	int target = Integer.parseInt(args[2]);
	int generations = Integer.parseInt(args[3]);

	if ((poolSize % 2) != 0) {
	    usage();
	}

	createInitChromosomes(output, poolSize, target);

	scoreGen0(output, target);

	for (int index = 0; index < generations; index++) {
	    reproduce(output, index, target);
	}
    }// main

}
