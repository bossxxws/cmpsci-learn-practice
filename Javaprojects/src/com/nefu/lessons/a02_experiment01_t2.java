package com.nefu.lessons;

import java.util.Scanner;

public class a02_experiment01_t2
{
        public static void main(String[] args) {
            Scanner input = new Scanner(System.in);

            int startYear = input.nextInt();
            int endYear = input.nextInt();

            int count = 0;

            for (int year = startYear; year <= endYear; year++) {
                if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
                    System.out.print(year + " ");
                    count++;

                    if (count == 4) {
                        System.out.println();
                        count = 0;
                    }
                }
            }
            input.close();
        }


}
