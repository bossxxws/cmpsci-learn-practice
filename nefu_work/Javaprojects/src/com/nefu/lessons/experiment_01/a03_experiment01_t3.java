package com.nefu.lessons.experiment_01;

import java.util.Scanner;

import java.util.Arrays;

public class a03_experiment01_t3
{
    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);


        int n = input.nextInt();

        int numbers[] = new int[n];

        for (int i = 0; i < n; i++)
        {
            numbers[i] = input.nextInt();
        }

        Arrays.sort(numbers);


        for (int i = n - 1; i >= 0; i--)
        {
            System.out.print(numbers[i] + " ");
        }

        input.close();
    }
}
