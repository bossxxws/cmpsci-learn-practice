package com.Ao.flowsum;

import org.apache.hadoop.conf.Configuration;
import org.apache.hadoop.fs.Path;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Job;
import org.apache.hadoop.mapreduce.lib.input.FileInputFormat;
import org.apache.hadoop.mapreduce.lib.output.FileOutputFormat;

import java.io.IOException;

public class FlowCountDriver
{
    public static void main(String[] args) throws IOException, ClassNotFoundException, InterruptedException {
        Configuration conf=new Configuration();
        //args=new String[]{"D:\\bigdatatext\\nums.txt","output"};
        Job job=Job.getInstance();

        job.setJarByClass(FlowCountDriver.class);

        job.setMapperClass(FlowCountMapper.class);

        job.setReducerClass(FlowCountReducer.class);

        job.setMapOutputKeyClass(Text.class);

        job.setMapOutputValueClass(FlowBean.class);

        job.setOutputKeyClass(Text.class);

        job.setOutputValueClass(FlowBean.class);

        //设置输入输出路径

        FileInputFormat.setInputPaths(job,new Path(args[0]));

        FileOutputFormat.setOutputPath(job,new Path(args[1]));

        boolean res = job.waitForCompletion(true);

        System.exit(res?0:1);

    }
}
