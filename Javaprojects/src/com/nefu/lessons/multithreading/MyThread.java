package com.nefu.lessons.multithreading;

//创建线程有四个方法
//1、继承Thread类创建线程
//2、是西安Runnable接口创建线程

//thread
public class MyThread extends Thread
{
//    MyThread(String s)
//    {
//        super(s);
//    }
    @Override
    public void run()
    {
        for(int i=1;i<=100;i++)
        {

            System.out.println(this.currentThread().getName()+":"+i);
            System.out.println(this.getName()+":"+i);
        }
    }



}
