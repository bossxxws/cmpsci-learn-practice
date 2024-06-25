package com.nefu.lessons.multithreading;

public class Myrun implements Runnable
{
    int t=1000;//两个线程共享一个变量会出问题
    @Override
    public void run() {
        for(int i=1;i<=t;i++)
        {
            System.out.println(i);
        }
    }

}
