package com.nefu;

import java.util.*;
import java.io.*;

// 功能需求:

// 成绩录入:允许老师手动输入学生的成绩信息,包括学号、姓名、成绩。
// 成绩查询:允许查看某个学生的成绩信息,或者查看所有学生的成绩信息。
// 成绩修改:允许修改学生的成绩信息。
// 成绩删除:允许删除学生的成绩信息。
// 成绩统计:可以统计各个分数段的学生人数,并按照分数从高到低排序。
// 等等....(程序可拓展性较好)
// 数据结构设计:

// 使用集合来存储学生成绩信息,选择HashSet
// 每个学生的成绩信息存储为一个对象,包括学号、姓名和成绩。

// 文件操作:
// 将学生成绩信息保存到文件中,使用序列化的方式。
// 在程序启动时,从文件中读取学生成绩数据到内存中的集合。
// 在程序退出时,将内存中的学生成绩数据保存到文件中

// 功能实现:
// 录入成绩:输入学号、姓名和成绩,创建学生成绩对象并添加到集合中。
// 查询成绩:根据学号查询某个学生的成绩信息,或者遍历集合显示所有学生的成绩信息。
// 修改成绩:根据学号查找学生成绩对象,修改对象的成绩属性。
// 删除成绩:根据学号从集合中删除学生成绩对象。
// 成绩统计:遍历集合,统计各个分数段的学生人数,并按照分数从高到低排序输出。

class Student implements Serializable {
    String id;
    String name;
    double score;

    // 构造函数
    public Student(String id, String name, double score) {
        this.id = id;
        this.name = name;
        this.score = score;
    }

    @Override
    public String toString() {
        return "学号：" + id + ", 姓名：" + name + ", 成绩：" + score;
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
            System.out.println("修改完毕");
        } else {
            System.out.println("学生不存在");
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
        if (students.size() != 0) {
            Collections.sort(students, new Comparator<Student>() {
                public int compare(Student s1, Student s2) {
                    return Double.compare(s2.score, s1.score);
                }
            });
        }

    }

    // 分数段统计
    public void scoreSegmentStatistics() {
        int[] segments = new int[10];
        if (students.size() != 0) {
            for (Student student : students) {
                if (student.score == 100) {
                    segments[9]++;
                } else {
                    int segment = (int) student.score / 10;
                    segments[segment]++;
                }
            }
            for (int i = 0; i < 10; i++) {
                System.out.println(i * 10 + "-" + (i + 1) * 10 + ": " + segments[i]);
            }
        } else {
            System.out.println("数据为空");
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
        students = (List<Student>) ois.readObject();
        ois.close();
        fis.close();
    }

    //输出排序后的成绩
    void PrintSortedGrades() {
        sortScores();
        if (students.size() != 0) {
            for (Student t : students) {
                System.out.println(t);
            }
        } else {
            System.out.println("数据为空");
        }

    }

    void deleteAll() {
        for (int i = 0; i < students.size(); i++) {
            students.remove(i);
        }
    }
}

public class JavaTask {
    public static void main(String[] args) throws IOException, ClassNotFoundException, InterruptedException {

        ScoreManager manager = new ScoreManager();
        manager.loadFromFile("scores.txt");
        Scanner scanner = new Scanner(System.in);
        System.out.println("******这是第六小组的PBL作业******");

        System.out.println("本实验由第六小组成员共同完成");
        System.out.println("小组成员：张奥、颜煦桐、刘雅馨、郭贝儿、刘思昀（排名不分先后）");
        String c;
        System.out.println("是否进入学生成绩管理系统？（y/n）");
        c = scanner.next();

        if (c.equals("y")) {
            System.out.println("正在进入学生成绩管理系统......");
            Thread.sleep(2000);
            System.out.println("欢迎来到学生成绩管理系统！");
            while (true) {
                int operation;
                System.out.println("--------------------------------------------------------------------------");
                System.out.println("请输入操作：");
                System.out.println("000： 保存并退出");
                System.out.println("001： 录入成绩分");
                System.out.println("002： 查询成绩");
                System.out.println("003： 修改成绩");
                System.out.println("004： 删除成绩");
                System.out.println("005： 统计平均成绩");
                System.out.println("006： 从高到低显示所有学生成绩");
                System.out.println("007： 分数段统计");
                System.out.println("008： 查询成绩最高的学生");
                System.out.println("009： 删除所有成绩");
                System.out.println("010： 保存");

                System.out.println("按任意非数字键退出");
                System.out.println("--------------------------------------------------------------------------");
                if (scanner.hasNextInt()) {
                    operation = scanner.nextInt();
                    scanner.nextLine();

                    if (operation == 1) {
                        System.out.println("请输入学生ID：");
                        String id = scanner.nextLine();
                        System.out.println("请输入学生姓名：");
                        String name = scanner.nextLine();
                        System.out.println("请输入学生成绩：");
                        double score = scanner.nextDouble();
                        scanner.nextLine();
                        manager.addScore(id, name, score);
                        System.out.println("录入成功");
                        Thread.sleep(2000);
                    } else if (operation == 2) {
                        System.out.println("请输入学生ID：");
                        String id = scanner.nextLine();
                        Student student = manager.queryScore(id);
                        if (student != null) {
                            System.out.println("学生ID: " + student.id + ", 姓名: " + student.name + ", 成绩: " + student.score);
                        } else {
                            System.out.println("未找到该学生的成绩。");
                        }
                        Thread.sleep(2000);
                    } else if (operation == 3) {
                        System.out.println("请输入学生ID：");
                        String id = scanner.nextLine();
                        System.out.println("请输入新的成绩：");
                        double newScore = scanner.nextDouble();
                        scanner.nextLine();
                        manager.modifyScore(id, newScore);
                        Thread.sleep(2000);
                    } else if (operation == 4) {
                        System.out.println("请输入学生ID：");
                        String id = scanner.nextLine();
                        manager.deleteScore(id);
                        System.out.println("删除完毕");
                        Thread.sleep(2000);
                    } else if (operation == 5) {
                        manager.statistics();
                        Thread.sleep(2000);
                    } else if (operation == 6) {
                        manager.PrintSortedGrades();
                        Thread.sleep(2000);
                    } else if (operation == 7) {
                        manager.scoreSegmentStatistics();
                        Thread.sleep(2000);
                    } else if (operation == 8) {
                        manager.sortScores();
                        if (manager.students.size() != 0) System.out.println(manager.students.get(0));
                        else System.out.println("数据为空");
                        Thread.sleep(2000);
                    } else if (operation == 9) {
                        manager.deleteAll();
                        System.out.println("已删除所有成绩数据");
                        Thread.sleep(2000);
                    } else if (operation == 10) {
                        manager.saveToFile("scores.txt");
                        System.out.println("成功保存");
                        Thread.sleep(2000);
                    } else if (operation == 000) {
                        manager.saveToFile("scores.txt");
                        System.out.println("成功保存，正在退出......");
                        break;
                    } else {
                        System.out.println("无效的操作，请重新输入。");
                        Thread.sleep(2000);
                    }
                } else {
                    System.out.println("正在退出......");
                    break;
                }
            }

            scanner.close();
        }
    }
}
