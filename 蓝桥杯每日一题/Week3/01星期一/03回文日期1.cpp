#include<bits/stdc++.h>
using namespace std;

int a, b;
long long cnt = 0;

int days[] = {-1, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main(){
    scanf("%d %d", &a, &b);
    for(int month = 1; month <= 12; month ++){
        for(int day = 1; day <= days[month]; day ++){
            int year = 1000 * (day % 10) + 100 * (day / 10) + 10 * (month % 10) + month / 10;
            int date = 10000 * year + 100 * month + day;
            if(date >= a && date <= b) cnt ++;
        }
    }
    printf("%d\n", cnt);
    return 0;
}


