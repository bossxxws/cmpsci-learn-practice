package com.Ao.numbersort;

import org.apache.hadoop.conf.Configuration;
import org.apache.hadoop.fs.Path;
import org.apache.hadoop.io.LongWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Job;
import org.apache.hadoop.mapreduce.Mapper;
import org.apache.hadoop.mapreduce.Reducer;
import org.apache.hadoop.mapreduce.lib.input.FileInputFormat;
import org.apache.hadoop.mapreduce.lib.output.FileOutputFormat;
import java.io.IOException;
import java.util.TreeMap;

public class NumberSort {
    public static class NumberSortMapper extends Mapper<LongWritable, Text, LongWritable, Text>
    {
        private TreeMap<Long, String> sortedNumbers = new TreeMap<>();
        private LongWritable lineNumber = new LongWritable(1);

        @Override
        protected void map(LongWritable key, Text value, Context context) throws IOException, InterruptedException {

            String[] numbers = value.toString().split("\\s+");

            for (String number : numbers) {
                try {
                    long num = Long.parseLong(number);
                    sortedNumbers.put(num, number);
                } catch (NumberFormatException e) {

                }
            }
        }

        @Override
        protected void cleanup(Context context) throws IOException, InterruptedException {

            for (Long num : sortedNumbers.keySet()) {
                context.write(lineNumber, new Text(sortedNumbers.get(num)));
                lineNumber.set(lineNumber.get() + 1);
            }
        }
    }

    public static void main(String[] args) throws Exception {
        Configuration conf = new Configuration();
        Job job = Job.getInstance(conf, "Number Sort");
        job.setJarByClass(NumberSort.class);
        job.setMapperClass(NumberSortMapper.class);
        job.setOutputKeyClass(LongWritable.class);
        job.setOutputValueClass(Text.class);
        FileInputFormat.addInputPath(job, new Path(args[0]));
        FileOutputFormat.setOutputPath(job, new Path(args[1]));
        System.exit(job.waitForCompletion(true) ? 0 : 1);
    }
}



