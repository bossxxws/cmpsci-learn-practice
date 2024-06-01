package com.nefu.lessons.Test;

public class test_06_01 implements Runnable
{
    public static void main(String[] args) {
        //Thread t=new Thread(new test_06_01());
        Thread t=new Thread();

        t.start();
        System.out.println("main");
        
    }

    @Override
    public void run() {
        System.out.println("t1");
    }
    
    
}