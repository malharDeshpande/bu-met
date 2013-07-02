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

import java.io.IOException;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

import org.apache.hadoop.io.IntWritable;
import org.apache.hadoop.io.LongWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapred.MapReduceBase;
import org.apache.hadoop.mapred.Mapper;
import org.apache.hadoop.mapred.OutputCollector;
import org.apache.hadoop.mapred.Reporter;

import java.util.*; 
import java.lang.StringBuilder; 
  
 /* 
  * This class reads in a serialized download of wikispecies, extracts out the links, and 
  * foreach link: 
  *   emits (currPage, (linkedPage, 1)) 
  * 
  * 
  */ 
public class SpeciesGraphBuilderMapper extends MapReduceBase implements Mapper<LongWritable, Text, Text, Text> { 
  
    
    public void map(LongWritable key,
                    Text value, 
                    OutputCollector output, 
                    Reporter reporter) throws IOException
    {
        // Prepare the input data. 
        String page = value.toString(); 
        

        String title = this.getTitle(page, reporter); 
        //        System.out.printf("Title: %s\n", title);
        if (title.length() > 0) { 
	    title = title.replace(" ", "_");
	    title = title.replace(":", "-");
	    
            reporter.setStatus(title); 
        } else { 
            return; 
        } 

        ArrayList<String> outlinks = new ArrayList<String>(); 
        
        Pattern regex = Pattern.compile("(== Taxonavigation ==|==Taxonavigation==)([^(==)]+)");
        Matcher match = regex.matcher(page);
        while (match.find()) {
            String p = match.group();
            this.getLinks(p, outlinks);
        }

        StringBuilder builder = new StringBuilder(); 
        for (String link : outlinks) { 
            link = link.replace(" ", "_"); 
            link = link.replace(":", "-"); 
            builder.append(" "); 
            builder.append(link); 
        } 

     if (title == "Calcaria") {
	 System.out.printf("%s -> %s", title, builder.toString());
     }

     if (title.indexOf("Template") != 0) {
	 System.out.printf("%s -> %s", title, builder.toString());
     }

        output.collect(new Text(title), new Text(builder.toString())); 
    } 
    
    public String getTitle(String page, Reporter reporter) throws IOException
    { 
        int pos = page.indexOf("<title>");
        int npos = page.indexOf("</title>");

        if (-1 == pos)
            return "";
        return page.substring(pos + 7, npos);
    } 
    
    public void getLinks(String page, List<String> links)
    { 
        int start = page.indexOf("[[");
        int end; 
        while (start > 0) {
            start = start + 2;
            end = page.indexOf("]]", start);

            if (end == -1) {
                break;
            }

            String toAdd = page.substring(start);
            toAdd = toAdd.substring(0, (end - start));
            links.add(toAdd);
            start = page.indexOf("[[", end + 1);
        }

        return;
    } 
}

