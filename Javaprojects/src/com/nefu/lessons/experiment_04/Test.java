package com.nefu.lessons.experiment_04;

import com.nefu.lessons.experiment_04.enity.Student;
import com.nefu.lessons.experiment_04.impl.StudentServiceImpl;
import com.nefu.lessons.experiment_04.service.StudentService;
import org.w3c.dom.ls.LSOutput;

import java.util.List;
import java.util.Map;
import java.util.Scanner;

public class Test {
    private static StudentServiceImpl studentService = new StudentServiceImpl();

    public static void main(String[] args) {
        testAddStudent1();
    }

    private static void testAddStudent1(){
        Scanner s=new Scanner(System.in);
        int id=s.nextInt();
        String sexString = s.next();

        Student.Sex sex=Student.Sex.MALE;

        if(sexString.equals("女"))sex=Student.Sex.FEMALE;

        String name=s.next();

        int year=s.nextInt();

        studentService.addStudent(new Student(id,sex,name,year))
                .forEach(a->System.out.println(a));
    }

}
