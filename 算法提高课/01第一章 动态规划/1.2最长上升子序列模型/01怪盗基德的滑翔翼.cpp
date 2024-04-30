#include<bits/stdc++.h>
using namespace std;
const int N =110;
int w[N],up[N],down[N];

//注意开始时候可以在任意一栋建筑上

int main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        memset(up,0,sizeof up);
        memset(down,0,sizeof down);
        int res = 0;
        int n;
        cin>>n;
        if(n==1) res =1;
        for(int i = 0 ;i<n;i++)
        {
            scanf("%d",&w[i]);
            down[i] = 1;up[i] = 1;

            for(int j=0;j<i;j++)
            {
                //up
                if(w[i]<w[j])
                    up[i] = max(up[i],up[j]+1);
                res = max(res ,up[i]);
                //down
                if(w[i]>w[j])
                    down[i] = max(down[i],down[j]+1);
                res = max(res,down[i]);
            }

        }
        printf("%d\n",res);
    }

}


