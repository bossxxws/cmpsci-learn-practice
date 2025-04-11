#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int L;

int get(int k){
    if(k <= 3500) return k;

    int a[] = {0, 1500, 4500, 9000, 35000, 55000, 80000, 1000000};
    double b[] = {0, 0.03, 0.1, 0.2, 0.25, 0.3, 0.35, 0.45};

    int tax = k - 3500, sum = 0;
    for(int i = 1; i <= 7; i ++){
        if(tax >= a[i]) sum += (a[i] - a[i - 1]) * b[i];
        else{
            sum += (tax - a[i - 1]) * b[i];
            break;
        }
    }
    return k - sum;
}


int main(){
    cin >> L;

    for(int i = 0; ; i += 100){
        if(get(i) == L){
            cout << i << endl;
            break;
        }
    }
}

