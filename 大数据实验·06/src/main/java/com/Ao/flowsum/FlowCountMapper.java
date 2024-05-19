package com.Ao.flowsum;

import org.apache.hadoop.io.LongWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Mapper;

import java.io.IOException;

public class FlowCountMapper extends Mapper<LongWritable, Text,Text,FlowBean>
{
    Text k=new Text();
    FlowBean v=new FlowBean();
    @Override
    protected void map(LongWritable key, Text value, Context context) throws IOException, InterruptedException {
        String line = value.toString();

        String[] fields=line.split("\t");


        k.set(fields[1]);

        long upFlow=Long.parseLong(fields[fields.length-3]);
        long downFlow=Long.parseLong(fields[fields.length-2]);

        v.setUpFlow(upFlow);
        v.setDownFlow(downFlow);
        //v.set(upFlow,downFlow);

        context.write(k,v);
    }
}
