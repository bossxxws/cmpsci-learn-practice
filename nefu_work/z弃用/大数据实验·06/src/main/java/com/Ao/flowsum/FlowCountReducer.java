package com.Ao.flowsum;

import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Reducer;

import java.io.IOException;

public class FlowCountReducer extends Reducer<Text,FlowBean,Text,FlowBean>
{
    FlowBean v=new FlowBean();
    @Override
    protected void reduce(Text key, Iterable<FlowBean> values, Context context) throws IOException, InterruptedException
    {
        long sum_upFlow=0;
        long sum_downFlow=0;



        for(FlowBean flowBean:values)
        {
            sum_upFlow+=flowBean.getUpFlow();
            sum_downFlow+=flowBean.getDownFlow();
        }



        v.set(sum_upFlow,sum_downFlow);

        context.write(key,v);
    }
}
