#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

// 学生结构体
struct Student {
    string name;
    int score;
};

// 老师结构体
struct Teacher {
    string name;
    Student arr[5]; // 学生数组
};

// 给老师及所带学生赋值
void assignTeachers(Teacher teachers[], int len) {

    string Nameseed = "ABCDE";
    for (int i = 0; i < len; i++) {
        teachers[i].name = Nameseed[i];
        for (int j = 0; j < 5; j++) {
            teachers[i].arr[j].name = Nameseed[j];
            teachers[i].arr[j].score = rand() % 61 + 40;
        }
    }
}

// 打印老师及所带学生数据
void printTeachers(Teacher teachers[], int len) {
    for (int i = 0; i < len; i++) {
        cout << "老师姓名: " << teachers[i].name << endl;
        cout << "所带学生信息：" << endl;
        for (int j = 0; j < 5; j++) {
            cout << "学生姓名: " << teachers[i].arr[j].name << "，";
            cout << "考试分数: " << teachers[i].arr[j].score << endl;
        }
        cout << endl;
    }
}

int main() {
    srand((unsigned int)time(NULL));
    Teacher teachers[3];
    int len = sizeof(teachers) / sizeof(teachers[0]);
    assignTeachers(teachers, len);
    printTeachers(teachers, len);
    //    system("pause");
}