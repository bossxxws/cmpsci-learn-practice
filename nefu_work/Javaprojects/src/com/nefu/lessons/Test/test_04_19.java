package com.nefu.lessons.Test;

class People
{
    String name;

    public People() {
        System.out.print(4);
    }

    public People(String name)
    {
        System.out.print(3);
        this.name = name;
    }
}

class child extends People
{
    People father;
    public child(String name) {
        System.out.print(2);
        this.name = name;
        father = new People(name + ":F");
    }
    public child(){ System.out.print(1);}
}

public class test_04_19
{
    public static void main(String[] args)
    {
        new child("mike");
    }
}

