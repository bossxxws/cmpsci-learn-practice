package com.nefu.lessons.experiment_07_total;

import java.util.Scanner;

class Race implements Runnable
{
    private final static int Zhongdian=10000;
    private volatile int len1=0,len2=0;
    String s1,s2;
    public Race(String s1,String s2){
        this.s1=s1;
        this.s2=s2;
    }

    @Override
    public void run() {
        while(true)
        {
            if(Thread.currentThread().getName().equals(s1))//现在是乌龟
            {
                len1=len1+1;
                if(len1>Zhongdian)
                {
                    System.out.println(s1+"到达终点");
                }
                else
                {
                    //显示乌龟距离终点还有多少米
                    System.out.println(s1+"距离终点还有 "+(Zhongdian-len1)+" 米");
                    //判断乌龟是否领先
                    if(len1>len2)
                    {
                        System.out.println(s1+"处于领先地位");
                    }
                }
            }
            else//是兔子的情况
            {
                len2=len2+10;//兔子一下跑10距离
                if(len2>Zhongdian)
                {
                    System.out.println(s2+"到达终点");
                }
                else
                {
                    //兔子距离终点还有多少米
                    System.out.println(s2+"距离终点还有 "+(Zhongdian-len2)+" 米");
                    if(len2>len1)
                    {
                        System.out.println(s2+"处于领先地位");
                        System.out.println(s2+":我跑得快，睡一觉");
                        try {
                            Thread.sleep(1);
                        } catch (InterruptedException e) {
                            e.printStackTrace();
                        }
                    }
                }
            }
            if(len1==len2) System.out.println("二者并列");
            if(len1>Zhongdian || len2>Zhongdian)return;
        }
    }
}

public class Turtle_and_rabbit
{
    public static void main(String[] args) {
        String s1="乌龟",s2="兔子";
        Race r=new Race(s1, s2);
        Thread turtle,rabbit;
        turtle=new Thread(r);
        rabbit=new Thread(r);
        turtle.setName(s1);
        rabbit.setName(s2);
        turtle.start();
        rabbit.start();
    }

}
