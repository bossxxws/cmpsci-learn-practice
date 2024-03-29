//直接枚举时间复杂度为 O（n*m），n太大了，会超时
//容斥原理的复杂度：2的m次方  

//因为本题1<=m<=16，时间复杂度较小

//一秒能算1e7-1e8次

//下取整真是个好东西

//such as 
//求1-n中p的倍数的个数
//solution: [n/p] ([]表示向下取整)

//容斥原理可以用深度优先搜索实现

//枚举一下所有的选法
//常用的方法是用位运算枚举

//for(int i=1;i<2**n;i++)
//n位二进制数，例如2的五次方
//00101 1表示选这个数，0表示不选这个数

//奇 +
//偶 -

#include<bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N=20;

int n,m;
int p[N];


int main()
{
    cin>>n>>m;
    for(int i=0;i<m;i++)cin>>p[i];//读入质数
    
    int res=0;
    for(int i=1;i<1<<m;i++)//从1枚举到2的m次方，2的m次方可以写成1左移m位
    {
        int t=1;//
        int cnt=0;
        for(int j=0;j<m;j++)//枚举到m位
            if(i>>j&1)//如果第m位有集合（1表示有集合）
            {
                cnt++;//cnt统计有几个集合，++
                if((LL)t* p[j]>n)
                {
                    t=-1;//如果大于n就不用算了，标记一下
                    break;
                }
                t*=p[j];
            }
        if(t!=-1)
        {
             if(cnt%2)res+=n/t;//奇数个集合加上
             else res-=n/t;//偶数个集合减去
        }
    }
    cout<<res<<endl;
    return 0;
}
