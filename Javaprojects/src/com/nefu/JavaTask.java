package com.nefu;

import java.util.*;
import java.io.*;

class Student {
    String id;
    String name;
    double score;

    // 构造函数
    public Student(String id, String name, double score) {
        this.id = id;
        this.name = name;
        this.score = score;
    }
}

class ScoreManager {
    List<Student> students = new ArrayList<>();

    // 录入成绩
    public void addScore(String id, String name, double score) {
        students.add(new Student(id, name, score));
    }

    // 查询成绩
    public Student queryScore(String id) {
        for (Student student : students) {
            if (student.id.equals(id)) {
                return student;
            }
        }
        return null;
    }

    // 修改成绩
    public void modifyScore(String id, double newScore) {
        Student student = queryScore(id);
        if (student != null) {
            student.score = newScore;
        }
    }

    // 删除成绩
    public void deleteScore(String id) {
        Student student = queryScore(id);
        if (student != null) {
            students.remove(student);
        }
    }

    // 统计成绩
    public void statistics() {
        double sum = 0;
        for (Student student : students) {
            sum += student.score;
        }
        double average = sum / students.size();
        System.out.println("平均分: " + average);
    }

    // 成绩排序
    public void sortScores() {
        Collections.sort(students, new Comparator<Student>() {
            public int compare(Student s1, Student s2) {
                return Double.compare(s2.score, s1.score);
            }
        });
    }

    // 分数段统计
    public void scoreSegmentStatistics() {
        int[] segments = new int[10];
        for (Student student : students) {
            int segment = (int)student.score / 10;
            segments[segment]++;
        }
        for (int i = 0; i < 10; i++) {
            System.out.println(i*10 + "-" + (i+1)*10 + ": " + segments[i]);
        }
    }

    // 保存到文件
    public void saveToFile(String filename) throws IOException {
        FileOutputStream fos = new FileOutputStream(filename);
        ObjectOutputStream oos = new ObjectOutputStream(fos);
        oos.writeObject(students);
        oos.close();
        fos.close();
    }

    // 从文件加载
    public void loadFromFile(String filename) throws IOException, ClassNotFoundException {
        FileInputStream fis = new FileInputStream(filename);
        ObjectInputStream ois = new ObjectInputStream(fis);
        students = (List<Student>)ois.readObject();
        ois.close();
        fis.close();
    }
}
