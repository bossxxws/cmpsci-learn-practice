/*
Description
QWQ的朋友QAQ开了一个A工厂，但QAQ不是一个很精明的老板，A工厂只生产三种产品，需要三种原材料，
第一种产品分别消耗第一种原材料a1、第二种原材料b1、第三种原材料c1，第二种产品分别是a2、b2、c2，
第三种产品分别是a3、b3、c3，但原材料总量是有限制的，分别是a、b、c，第一种产品可以盈利d1元，
第二种产品可以盈利d2元，第三种原材料可以盈利d3元，由于每个产品都不可以分解，所以所有产品的生产量一定是整数。
QAQ不知道怎么合理安排生产让他的盈利最大，于是他求助QWQ，QWQ更不知道了，但你一定知道
Input
先输入一个数字t（t<20），代表数组的组数
每组数据包括五行
第一行三个数字a1、b1、c1
第二行三个数字a2、b2、c2
第三行三个数字a3、b3、c3
第四行三个数字a、b、c
第五行三个数字d1、d2、d3
保证所有输入都是非负整数，并且不大于200
Output
输出最大的总盈利
Sample Input
1
1 1 1
1 1 1
1 1 1
3 3 3
1 2 3
Sample Output
9
*/
#include<bits/stdc++.h>

using namespace std;

typedef long long LL;
//int 1e9,1e18 LL
//1-4*1e7,循环输出大概耗时一秒 

int main()

{

    int t,I,a[5],b[5],c[5],d[5],s[300],i,j,k,max;

    while(scanf("%d",&t)!=-1)

    {

        for(I=1;I<=t;I++)

        {

            for(i=1;i<=4;i++)

                scanf("%d%d%d",&a[i],&b[i],&c[i]);

            for(i=1;i<=3;i++)

                scanf("%d",&d[i]);

            max=0;

            for(i=0;i<=200;i++)

            {

                for(j=0;j<=200;j++)

                {

                    for(k=0;k<=200;k++)

                    {

                        if(a[1]*i+a[2]*j+a[3]*k<=a[4]&&b[1]*i+b[2]*j+b[3]*k<=b[4]&&c[1]*i+c[2]*j+c[3]*k<=c[4])

                        {

                            s[i]=i*d[1]+j*d[2]+k*d[3];

                            if(s[i]>max)

                                max=s[i];

                        }

                    }

                }

            }

            printf("%d\n",max);

        }

    }

    return 0;

}
