#include <iostream>
#include <vector>
#include <algorithm>
using namespace std ;
typedef pair<int,int> pii ;
vector<pii> nums,res ;
int main()
{
    int st=-2e9,ed=-2e9 ;                           //ed���������β��st�������俪ͷ
    int n ;
    scanf("%d",&n) ; 
    while(n--)
    {
        int l,r ; 
        scanf("%d%d",&l,&r) ;
        nums.push_back({l,r}) ;
    }
    sort(nums.begin(),nums.end()) ;                 //����˵�����
    for(auto num:nums)                   
    {
        if(ed<num.first)                            //���1�����������޷��ϲ�
        {
            if(ed!=-2e9) res.push_back({st,ed}) ;   //����1�Ž�res����
            st=num.first,ed=num.second ;            //ά������2
        }
        else if(ed<num.second)  
            ed=num.second ;                         //����ϲ�
    }  
    res.push_back({st,ed});
    printf("%d",res.size()) ;         
    return 0 ;
}

