package com.nefu.lessons.multithreading;

public class test2
{
    public static void main(String[] args) {
        Myrun r=new Myrun();

        Thread t1=new Thread(r);
        Thread t2=new Thread(r);

        t1.start();
        t2.start();

    }


}
