#include <iostream>

using namespace std;

const int N = 100010;

int q[N];

//[hh, tt] 之间为队列（左闭右闭）
int hh = 0;//队头位置

int tt = -1;//队尾位置

//操作次数
int m;

//操作方式
string s;

//入队：队尾先往后移动一格，再放入要插入的数据
void push(int x){
    q[++tt] = x;
}

//出队：队头往后移动一格
void pop(){
    hh++;
}

//[hh, tt]表示队列区间，当tt >= hh时，区间不为空
void empty(){
    if(tt >= hh) cout << "NO" << endl;
    else cout << "YES" << endl;
} 

//hh指向队头，q[hh]代表队头元素
void query (){
    cout << q[hh] << endl;
}

int main(){
    cin >> m;
    while(m--){
        cin >> s;
        //入队
        if(s == "push"){
            int x;
            cin >> x;
            push(x);
        }
        //出队
        if(s == "pop"){
            pop();
        }
        //问空
        if(s == "empty"){
            empty();
        }
        //问队头
        if(s == "query"){
            query();
        }
    }
}

