package com.nefu.lessons.multithreading;

public class test1
{
    public static void main(String[] args) throws InterruptedException {

        MyThread thread=new MyThread();

        thread.setName("t1");

        thread.start();//start作用是真正启动一个线程

        thread.run();//不是真正的多线程，启动的是主线程,用this.currentThread().getName()获得的是main

        for(int i=1;i<=100;i++)
        {
            //在哪里用sleep就阻塞哪个线程的运行
            Thread.sleep(1000);//阻塞main程序运行--1000毫秒
            System.out.println(199);
        }
    }
}
