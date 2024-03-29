#include <iostream>
#include <vector>
#include <algorithm>
using namespace std ;
typedef pair<int,int> pii ;
vector<pii> nums,res ;
int main()
{
    int st=-2e9,ed=-2e9 ;                           //ed代表区间结尾，st代表区间开头
    int n ;
    scanf("%d",&n) ; 
    while(n--)
    {
        int l,r ; 
        scanf("%d%d",&l,&r) ;
        nums.push_back({l,r}) ;
    }
    sort(nums.begin(),nums.end()) ;                 //按左端点排序
    for(auto num:nums)                   
    {
        if(ed<num.first)                            //情况1：两个区间无法合并
        {
            if(ed!=-2e9) res.push_back({st,ed}) ;   //区间1放进res数组
            st=num.first,ed=num.second ;            //维护区间2
        }
        else if(ed<num.second)  
            ed=num.second ;                         //区间合并
    }  
    res.push_back({st,ed});
    printf("%d",res.size()) ;         
    return 0 ;
}

