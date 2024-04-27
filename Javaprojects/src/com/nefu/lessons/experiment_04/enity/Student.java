package com.nefu.lessons.experiment_04.resource.enity;

public class Student {

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
