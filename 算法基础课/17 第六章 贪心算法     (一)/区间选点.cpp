//对于贪心问题：
//一般试一试排序：左端点排序，右端点排序，双关键字排序

//1、将每个区间按右端点从小到大排序
//2、从前往后一次枚举每个区间
//      如果当前区间中已经包含点。则直接pass
//      否则，选择当前区间的右端点
//贪心只看当前一小块的最优解，最终导致全局的最优解（至于最终能不能找到最优解，要证明）

//prove：A=B
//A>=B
//A<=B
//then A=B

//ans<=cnt (ans是所有cnt中的最小值，所以ans<=cnt)
//接下来证明ans>=cnt:
//最终相当于找到了cnt个互相没有交集的区间
//因为cnt中每个cnt的点最多覆盖了一个区间
//然后最小可行方案（ans）需要覆盖所有区间
//所以ans>=cnt
//所以最后证明出ans=cnt
#include<bits/stdc++.h>

using namespace std;

const int N=1e5+10;

struct range
{
    int l,r;
    bool operator<(range w)
    {
        return r<w.r;
    }
};

range srange[N];

int main()
{
    int n;
    cin>>n;
    
    for(int i=0;i<n;i++)
    {
        int l,r;
        cin>>l>>r;
        srange[i]={l,r};
    }
    sort(srange,srange+n);
    
    int res=0;
    int ed=-2e9;//ed表示上一个点的下标
    //因为一开始没有选，就看做负无穷
    
    for(int i=0;i<n;i++)
        if(srange[i].l>ed)
        {
            res++;//找到一个新的点
            ed=srange[i].r;//当前选择点的下标更新为这个区间右端
        }
    
    cout<<res;
    
    return 0;
}
