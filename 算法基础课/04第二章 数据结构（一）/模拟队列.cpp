#include <iostream>

using namespace std;

const int N = 100010;

int q[N];

//[hh, tt] ֮��Ϊ���У�����ұգ�
int hh = 0;//��ͷλ��

int tt = -1;//��βλ��

//��������
int m;

//������ʽ
string s;

//��ӣ���β�������ƶ�һ���ٷ���Ҫ���������
void push(int x){
    q[++tt] = x;
}

//���ӣ���ͷ�����ƶ�һ��
void pop(){
    hh++;
}

//[hh, tt]��ʾ�������䣬��tt >= hhʱ�����䲻Ϊ��
void empty(){
    if(tt >= hh) cout << "NO" << endl;
    else cout << "YES" << endl;
} 

//hhָ���ͷ��q[hh]�����ͷԪ��
void query (){
    cout << q[hh] << endl;
}

int main(){
    cin >> m;
    while(m--){
        cin >> s;
        //���
        if(s == "push"){
            int x;
            cin >> x;
            push(x);
        }
        //����
        if(s == "pop"){
            pop();
        }
        //�ʿ�
        if(s == "empty"){
            empty();
        }
        //�ʶ�ͷ
        if(s == "query"){
            query();
        }
    }
}

