package com.nefu.lessons.experiment_05.resource;

import com.nefu.lessons.experiment_05.enity.College;
import com.nefu.lessons.experiment_05.enity.Student;
import com.nefu.lessons.experiment_05.enity.Teacher;

import java.util.*;

public class DatabaseUtils {
    private static final List<Student> STUDENTS = create();

    private static List<Student> create() {
        College c1 = new College("信息学院");
        College c2 = new College("计控学院");

        Teacher t1 = new Teacher(1001, "吕惠玲");
        t1.setCollege(c1);
        Teacher t2 = new Teacher(1002, "曾志优");
        t2.setCollege(c2);
        Teacher t3 = new Teacher(1003, "郭晓静");


        Student s1 = new Student(202301,"赵阳阳", 2023);
        s1.setTeacher(t1);
        Student s2 = new Student(202302,"邵鹏", 2023);
        s2.setTeacher(t1);
        Student s3 = new Student(202203,"高学斌", 2022);
        s3.setTeacher(t2);
        Student s4 = new Student(202204,"张扬", 2022);
        s4.setTeacher(t2);
        Student s5 = new Student(202405,"张晓莲", 2024);
        s5.setTeacher(t3);
        Student s6 = new Student(202406,"刘静扬", 2024);
        Student s7=null;

        List<Student> students = new ArrayList<>();
        students.add(s1); students.add(s2);
        students.add(s3); students.add(s4);
        students.add(s5); students.add(s6);
        students.add(s7);
        return students;
    }

    public static List<Student> getStudents() {
        return STUDENTS;
    }



}

