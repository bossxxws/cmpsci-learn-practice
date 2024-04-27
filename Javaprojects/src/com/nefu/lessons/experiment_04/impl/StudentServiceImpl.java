package com.nefu.lessons.experiment_04.resource.impl;

import com.nefu.lessons.experiment_04.resource.DatabaseUtils.DatabaseUtils;
import com.nefu.lessons.experiment_04.resource.enity.Student;
import com.nefu.lessons.experiment_04.resource.service.StudentService;

import javax.xml.crypto.Data;
import java.util.List;
import java.util.Map;
import java.util.stream.Collectors;

public class StudentServiceImpl implements StudentService
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
        return null;
    }

    @Override
    public Map<Student.Sex, List<Student>> mapStudentsBySex() {
        return null;
    }

    @Override
    public boolean removeStudent(int id) {
        return false;
    }
}
