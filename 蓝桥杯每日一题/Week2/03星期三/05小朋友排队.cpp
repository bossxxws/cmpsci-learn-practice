#include <iostream>
using namespace std;

#define x first
#define y second

typedef long long LL;
typedef pair<int,int> PII;

const int N = 100010;
PII w[N];
PII temp[N];
LL h[N];
int n;

void merge_sort(int l,int r) {
    if(l >= r) return;

    int mid = l + r >> 1;
    merge_sort(l, mid), merge_sort(mid + 1, r);

    int i = l, j = mid + 1,k = 0;
    while(i <= mid && j <= r) {
        if(w[i] <= w[j]) {
            h[w[i].y] += j - mid - 1;   // 相对于i来说，j 前面的数都比它小
            temp[k ++] = w[i ++];
        }
        else {
            h[w[j].y] += mid - i + 1;   // 相对于j来说，i 后面的数都比它大
            temp[k ++] = w[j ++];
        }
    }

    while(i <= mid) {
        h[w[i].y] += j - mid - 1;
        temp[k ++] = w[i ++];
    }
    while(j <= r){
        h[w[j].y] += mid - i + 1;   // 可以不需要，因为 mid - i + 1 总为0
        temp[k ++] = w[j ++];
    }

    for(i = l,j = 0;i <= r;i ++,j ++) w[i] = temp[j];

}

int main()
{
    cin >> n;

    for(int i = 0;i < n;i ++) scanf("%d",&w[i].x), w[i].y = i;
    merge_sort(0,n - 1);

    LL res = 0;
    for(int i = 0;i < n;i ++) {
        res += (1 + h[i]) * h[i] / 2;
    }
    cout << res << endl;
    return 0;
}



