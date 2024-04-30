package com.nefu.lessons.experiment_04_total;

import org.w3c.dom.ls.LSOutput;

import java.util.*;
import java.util.stream.Collectors;
import java.util.Scanner;


interface StudentService {

    /**

     * 向集合添加一个学生，返回当前全部学生

     * @param student

     * @return

     */

    List<Student> addStudent(Student student);



    /**

     * 返回指定届的全部学生

     * @param year

     * @return

     */

    List<Student> listStudentsByYear(int year);



    /**

     * 返回指定届，指定性别的全部学生的姓名

     * @param year

     * @param sex

     * @return

     */

    List<String> listStudentsNames(int year, Student.Sex sex);



    /**

     * 将所有学生，以性别分组

     * @return

     */

    Map<Student.Sex, List<Student>> mapStudentsBySex();



    /**

     * 删除指定学号的学生，返回是否成功删除

     * @param id

     * @return

     */

    boolean removeStudent(int id);

}

class Student {

    public enum Sex {

        MALE, FEMALE

    }

    private int id;

    private Sex sex;

    private String name;

    private int year;



    public Student(int id, Sex sex, String name, int year) {

        this.id = id;

        this.sex = sex;

        this.name = name;

        this.year = year;

    }



    public int getId() {

        return id;

    }

    public void setId(int id) {

        this.id = id;

    }

    public Sex getSex() {

        return sex;

    }

    public void setSex(Sex sex) {

        this.sex = sex;

    }

    public String getName() {

        return name;

    }

    public void setName(String name) {

        this.name = name;

    }

    public int getYear() {

        return year;

    }

    public void setYear(int year) {

        this.year = year;

    }


    @Override
    public String toString() {
        String s = "女";
        if(sex == Sex.MALE)
            s = "男";
        return "Student{" +
                "id=" + id +
                ", sex=" + s +
                ", name='" + name + '\'' +
                ", year=" + year +
                '}';
    }
}

class  DatabaseUtils {

    private static final List<Student> STUDENTS = create();

    private static List<Student> create() {

        List<Student> students = new ArrayList<>();

        students.add(new Student(201001, Student.Sex.FEMALE, "赵阳阳", 2010));

        students.add(new Student(201002, Student.Sex.MALE, "邵鹏", 2010));

        students.add(new Student(201103, Student.Sex.MALE, "高学斌", 2011));

        students.add(new Student(201104, Student.Sex.MALE, "张扬", 2011));

        students.add(new Student(201205, Student.Sex.FEMALE, "吕惠玲", 2012));

        students.add(new Student(201206, Student.Sex.MALE, "曾志优", 2012));


        return students;

    }



    public static List<Student> getStudents() {

        return STUDENTS;

    }

}

class StudentServiceImpl implements StudentService
{


    @Override
    public List<Student> addStudent(Student student) {
        DatabaseUtils.getStudents().add(student);
        return DatabaseUtils.getStudents();
    }

    @Override
    public List<Student> listStudentsByYear(int year) {
        return DatabaseUtils.getStudents().stream()
                .filter(s->s.getYear()==year)
                .collect(Collectors.toList());
    }

    @Override
    public List<String> listStudentsNames(int year, Student.Sex sex) {
        return DatabaseUtils.getStudents().stream()
                .filter(s -> s.getYear() == year && s.getSex() == sex)
                .map(Student::getName)
                .collect(Collectors.toList());
    }

    @Override
    public Map<Student.Sex, List<Student>> mapStudentsBySex() {
        return DatabaseUtils.getStudents().stream()
                .collect(Collectors.groupingBy(Student::getSex));
    }

    @Override
    public boolean removeStudent(int id) {
        return DatabaseUtils.getStudents().removeIf(s -> s.getId() == id);
    }
}

public class Test {
    private static StudentServiceImpl studentService = new StudentServiceImpl();

    public static void main(String[] args) {
        testAddStudent1();
    }

    private static void testAddStudent1(){
        Scanner s=new Scanner(System.in);
//        int id=s.nextInt();
//        String sexString = s.next();
//
//        Student.Sex sex=Student.Sex.MALE;
//
//        if(sexString.equals("女"))sex=Student.Sex.FEMALE;
//
//        String name=s.next();
//
//        int year=s.nextInt();
//
//        studentService.addStudent(new Student(id,sex,name,year))
//                .forEach(a->System.out.println(a));
//        int y=s.nextInt();
//
//        String n=s.next();
//
//        if(n.equals("男")){
//            studentService.listStudentsNames(y,Student.Sex.MALE)
//                    .forEach(a->System.out.println(a));
//        }
//        else{
//            studentService.listStudentsNames(y,Student.Sex.FEMALE)
//                    .forEach(a->System.out.println(a));
//        }
//        List<Student> total=DatabaseUtils.getStudents();
//
//        System.out.println("女");
//
//        for(Student stu : total){
//            if(stu.getSex()== Student.Sex.FEMALE){
//                System.out.println(stu);
//            }
//        }
//
//        System.out.println("男");
//
//        for(Student stu : total){
//            if(stu.getSex()== Student.Sex.MALE){
//                System.out.println(stu);
//            }
//        }

        List<Student> total=DatabaseUtils.getStudents();

        int t=s.nextInt();

        boolean f=studentService.removeStudent(t);

        for(Student stu: total){
            System.out.println(stu);
        }

    }
}



