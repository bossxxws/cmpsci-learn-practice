package com.nefu.lessons;
import java.util.Scanner;

public class a01_experiment01_t1
{
        public static void main(String[] args) {
            Scanner input = new Scanner(System.in);


            double fahrenheit = input.nextDouble();

            double celsius = 5 * (fahrenheit - 50) / 9 + 10;

            System.out.printf("The temprature is %.2f.", celsius);

            input.close();
        }

}
