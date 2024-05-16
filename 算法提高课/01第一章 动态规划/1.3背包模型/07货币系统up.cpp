#include<bits/stdc++.h>

using namespace std;

unordered_map<int,string>m;//codeblocks-c++11 哈希表正常使用

typedef long long LL;

const int N=103;

int w[N];//每一种面值都有无穷多张，可以看作完全背包问题
//思路：
//排序，如果后面的大面值的货币能被前面的小面值的货币凑出来，那么这个面值是可以去掉的
//那么集合的状态就+1
//最后用n减去状态集合表示的值就可以了

//集合表示：
bool f[25002];

int main()
{
    int t;

    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;

        for(int i=1;i<=n;i++)
        {
            scanf("%d",&w[i]);
        }
        sort(w+1,w+n+1);
//        for(int i=2;i<=n;i++)
//        {
//            memset(f,0,sizeof f);
//            f[0][0]=1;
//            for(int j=1;j<=i;j++)
//            {
//                for(int k=0;k<=w[i];k++)
//                {
//                    f[j][k]+=f[j-1][k];
//                    if(k>=w[j])
//                    {
//                        f[j][k]+=f[j][k-w[j]];
//                        if(f[j][k]!=0)res++;
//                    }
//                }
//            }
//        }

        int res=0;//最大向量无关组
        int m=w[n];

        memset(f, 0, sizeof f);
        f[0]=true;
        for(int i=1;i<=n;i++)//枚举每一个货币面值
        {

            //先看看这个当前数有没有被筛掉
            if(f[w[i]])continue;//如果这个状态之前能被表示，直接跳过，最大
            res++;//没有跳过则最大向量无关组+1
            for(int j=w[i];j<=m;j++)
            {
                f[j]|=f[j-w[i]];//用当前的面值筛掉后面的能被表示的值
            }
        }


        cout<<res<<endl;
    }

    return 0;
}

