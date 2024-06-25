package com.nefu.lessons.experiment_01;

import java.util.Scanner;

public class a04_experiment01_t4
{
    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        while(n>0)
        {
            int a = input.nextInt();
            int b = input.nextInt();
            int k=0;
            int sumx=0;
            for(int i=0;i<b;i++)
            {
                k=k*10+a;
                sumx+=k;
            }
            System.out.print(sumx);
        }

    }

}
