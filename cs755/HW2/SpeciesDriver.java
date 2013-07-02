// 
 // Author - Jack Hebert (jhebert@cs.washington.edu) 
 // Copyright 2007 
 // Distributed under GPLv3 
 // 
// Modified - Dino Konstantopoulos (dinok@bu.edu)
// Copyright 2010, BU MET CS 755 Cloud Computing
// Distributed under the "If it works, remolded by Dino Konstantopoulos, 
// otherwise no idea who did! And by the way, you're free to do whatever 
// you want to with it" dinolicense
// 
package BU.MET.CS755;

import org.apache.hadoop.fs.Path; 
import org.apache.hadoop.io.IntWritable; 
import org.apache.hadoop.io.FloatWritable; 
import org.apache.hadoop.io.Text; 
import org.apache.hadoop.*; 
import org.apache.hadoop.mapred.*; 
import org.apache.hadoop.mapred.JobClient; 
import org.apache.hadoop.mapred.JobConf; 
import org.apache.hadoop.mapred.Mapper; 
import org.apache.hadoop.mapred.Reducer; 
import org.apache.hadoop.mapred.SequenceFileInputFormat; 
   
import org.apache.hadoop.mapred.FileInputFormat;
import org.apache.hadoop.mapred.FileOutputFormat;
  
import BU.MET.CS755.XmlInputFormat;

public class SpeciesDriver { 
  

    public static void graphBuilder(String input,
				    String output,
				    double startRank) throws Exception
    {
	JobClient client = new JobClient(); 
	JobConf conf = new JobConf(SpeciesDriver.class); 
	conf.setJobName("Page-rank Species Graph Builder"); 
  
	conf.setMapperClass(SpeciesGraphBuilderMapper.class); 
	conf.setMapOutputKeyClass(Text.class);
	conf.setMapOutputValueClass(Text.class);
  
	conf.setInputFormat(XmlInputFormat.class);

	conf.setReducerClass(SpeciesGraphBuilderReducer.class); 

	FileInputFormat.setInputPaths(conf, new Path(input));
	FileOutputFormat.setOutputPath(conf, new Path(output));
	
	conf.set("StartRank", Double.toString(startRank));
  
	client.setConf(conf); 
	try { 
	    JobClient.runJob(conf); 
	} catch (Exception e) { 
	    e.printStackTrace(); 
	} 
   
    }// graphBuilder

    public static void graphIterator(String input, 
				     String output,
				     double dampFactor) throws Exception
    {
	JobClient client = new JobClient(); 
	JobConf conf = new JobConf(SpeciesDriver.class); 
	conf.setJobName("Page-Rank Species Iter"); 
  
	conf.setNumReduceTasks(5); 
  
	conf.setOutputKeyClass(Text.class); 
	conf.setOutputValueClass(Text.class); 

	FileInputFormat.setInputPaths(conf, new Path(input));
	FileOutputFormat.setOutputPath(conf, new Path(output));
  
	conf.setMapperClass(SpeciesIterMapper2.class); 
	conf.setReducerClass(SpeciesIterReducer2.class); 
	conf.setCombinerClass(SpeciesIterReducer2.class); 

	conf.set("DampFactor", Double.toString(dampFactor));
  
	client.setConf(conf); 
	try { 
	    JobClient.runJob(conf); 
	} catch (Exception e) { 
	    e.printStackTrace(); 
	} 

    }// graphIterator

    public static void graphViewer(String input,
				   String output) throws Exception
    {
	JobClient client = new JobClient(); 
	JobConf conf = new JobConf(SpeciesDriver.class); 
	conf.setJobName("Page-Rank Species Viewer"); 
  
	conf.setOutputKeyClass(FloatWritable.class); 
	conf.setOutputValueClass(Text.class); 
  
	FileInputFormat.setInputPaths(conf, new Path(input));
	FileOutputFormat.setOutputPath(conf, new Path(output));
  
	conf.setMapperClass(SpeciesViewerMapper.class); 
	conf.setReducerClass(org.apache.hadoop.mapred.lib.IdentityReducer.class); 
  
	client.setConf(conf); 
	try { 
	    JobClient.runJob(conf); 
	} catch (Exception e) { 
	    e.printStackTrace(); 
	} 
    }// graphViewer

    public static void main(String[] args)  throws Exception
    { 
	if (args.length < 4) {
	    System.out.println("Usage: BU.MET.CS755.SpeciesDriver <input dir> <starting rank> <runs> <damping factor>");
	    System.exit(0);
	}
	
	String input = args[0];
	double startRank = Double.parseDouble(args[1]);
	int runs = Integer.parseInt(args[2]);
	double dampFactor= Double.parseDouble(args[3]);

	String output = input + "-graph";

	graphBuilder(input, output, startRank);

	String iter_in = output;
	String iter_out = new String("");

	for (int idx = 0; idx < runs; idx++) {
	    iter_out = input + "-iter" + Integer.toString(idx);

	    graphIterator(iter_in, iter_out, dampFactor);
	    graphViewer(iter_out, iter_out + "-view");

	    iter_in = iter_out;
	}
    }// main

 }  
