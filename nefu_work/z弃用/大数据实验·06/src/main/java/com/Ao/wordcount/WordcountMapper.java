package com.Ao.wordcount;

import org.apache.hadoop.io.IntWritable;
import org.apache.hadoop.io.LongWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Mapper;

import java.io.IOException;

//map阶段
//key in
//value in
//key out
//value out
public class WordcountMapper extends Mapper<LongWritable, Text,Text, IntWritable>
{
    @Override
    protected void map(LongWritable key, Text value, Context context) throws IOException, InterruptedException {

        //1.将text转化为string
        String line=value.toString();

        //2.根据空格进行切分
        String[] words=line.split(" ");

        //3.遍历输出
        for(String word: words)
        {
            Text k=new Text();
            k.set(word);
            IntWritable v =new IntWritable();
            v.set(1);
            context.write(k,v);
        }



    }
}
