package com.nefu.lessons;
import java.util.Scanner;



class Student {

    private String sNO;

    private String sName;

    private int sJava;



    public Student(String sNO, String sName, int sJava) {

        this.sNO = sNO;

        this.sName = sName;

        this.sJava = sJava;

    }



    public String getSNo() {

        return sNO;

    }



    public void setSNo(String sNO) {

        this.sNO = sNO;

    }



    public String getSName() {

        return sName;

    }



    public void setSName(String sName) {

        this.sName = sName;

    }



    public int getSJava() {

        return sJava;

    }



    public void setSJava(int sJava) {

        this.sJava = sJava;

    }



    public static int getHigh(Student[] students) {

        int maxGrade = Integer.MIN_VALUE;

        for (Student student : students) {

            if (student.getSJava() > maxGrade) {

                maxGrade = student.getSJava();

            }

        }

        return maxGrade;

    }

}

public class a05_experiment02_t1{

    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);

        int numStudents = scanner.nextInt();

        scanner.nextLine();



        Student[] students = new Student[numStudents];



        for (int i = 0; i < numStudents; i++) {

            String sNO = scanner.next();

            String sName = scanner.next();

            int sJava = scanner.nextInt();

            students[i] = new Student(sNO, sName, sJava);

        }



        int highestGrade = Student.getHigh(students);

        System.out.println(highestGrade);



        scanner.close();

    }

}

