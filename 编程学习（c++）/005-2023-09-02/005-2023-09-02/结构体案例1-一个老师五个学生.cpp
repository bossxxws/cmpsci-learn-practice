#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

// ѧ���ṹ��
struct Student {
    string name;
    int score;
};

// ��ʦ�ṹ��
struct Teacher {
    string name;
    Student arr[5]; // ѧ������
};

// ����ʦ������ѧ����ֵ
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

// ��ӡ��ʦ������ѧ������
void printTeachers(Teacher teachers[], int len) {
    for (int i = 0; i < len; i++) {
        cout << "��ʦ����: " << teachers[i].name << endl;
        cout << "����ѧ����Ϣ��" << endl;
        for (int j = 0; j < 5; j++) {
            cout << "ѧ������: " << teachers[i].arr[j].name << "��";
            cout << "���Է���: " << teachers[i].arr[j].score << endl;
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