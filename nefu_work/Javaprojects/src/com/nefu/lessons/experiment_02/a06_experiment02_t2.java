package com.nefu.lessons.experiment_02;

import java.util.Scanner;

class Complex {
    private int a;
    private int b;

    public Complex() {
        this.a = 0;
        this.b = 0;
    }

    public Complex(Complex c) {
        this.a = c.a;
        this.b = c.b;
    }

    public Complex(int a, int b) {
        this.a = a;
        this.b = b;
    }

    public void add(Complex c) {
        this.a += c.a;
        this.b += c.b;
    }

    public void subtract(Complex c) {
        this.a -= c.a;
        this.b -= c.b;
    }

    public void print() {
        if (a == 0 && b == 0) {
            System.out.println("0");
        } else if (a == 0) {
            System.out.println(b + "i");
        } else if (b == 0) {
            System.out.println(a);
        } else {
            System.out.println(a + " " + b + "i");
        }
    }
}

public class a06_experiment02_t2 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);


        int a1 = scanner.nextInt();
        int b1 = scanner.nextInt();
        Complex complex1 = new Complex(a1, b1);


        int a2 = scanner.nextInt();
        int b2 = scanner.nextInt();
        Complex complex2 = new Complex(a2, b2);

        Complex sum = new Complex(complex1);
        sum.add(complex2);

        Complex difference = new Complex(complex1);
        difference.subtract(complex2);

        sum.print();


        difference.print();

        scanner.close();
    }
}
