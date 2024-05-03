package com.nefu.lessons.experiment_05;

import com.nefu.lessons.experiment_05.enity.College;
import com.nefu.lessons.experiment_05.enity.Student;
import com.nefu.lessons.experiment_05.enity.Teacher;
import com.nefu.lessons.experiment_05.resource.DatabaseUtils;

import java.util.List;
import java.util.Scanner;

public class Test
{

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int index = scanner.nextInt();

        List<Student> students = DatabaseUtils.getStudents();
        if (index >= 0 && index < students.size()) {
            Student student = students.get(index);
            if(student!=null)
            {
                Teacher teacher = student.getTeacher();
                if (teacher != null) {
                    College college = teacher.getCollege();
                    if (college != null) {
                        System.out.println(college.getName());
                    } else
                        {
                        System.out.println("未知学院");
                    }
                } else
                    {
                    System.out.println("未知学院");
                }
                } else
                    {
                    System.out.println("未知学院");
                }
            }
            else
        {
            System.out.println("未知学院");
        }
    }


}
