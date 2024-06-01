package com.nefu.lessons.Test;

interface Arun
{
    void f();
}

class abrun implements Arun{
    public void f()
    {
        System.out.println("i am abrun");
    }
}

class acrun implements Arun{
    public void f()
    {
        System.out.println("i am acrun");
    }
    public static void main(String[] args){
        abrun b=new abrun();
        acrun a=new acrun();
        b.f();
        a.f();
        acrun[] k=new acrun[2];
    }
}

