package com.nefu.lessons;


interface run
{
}

class A
{
    int a=10;
    public static void pf()
    {
        System.out.println("这是父类的静态函数");
    }

    void pef()
    {
        System.out.println("this is A");
    }

}

class B extends A{
    int a=11;
    public static void pf()
    {
        System.out.println("这是子类的静态函数");
    }

    void pef()
    {
        System.out.println("this is B");
    }
}

public class test0418
{
    public static void main(String[] args)
    {
        A b_to_a=new B();//上转型

        b_to_a.pf();//调用静态函数

        System.out.println(b_to_a.a);//输出类中的变量

        b_to_a.pef();

        byte a=(byte)'的';//强制转换
        char b='的';
        int ss=(int)b;
        A.pf();//调用父类的类方法
        B.pf();//调用子类的类方法

        System.out.println(a);

        System.out.println(b);

        System.out.println(ss);

        //结论：父类的静态函数子类无法重写（意思是写了也无法被覆盖，在定义上是相当于没重写）

    }

}
