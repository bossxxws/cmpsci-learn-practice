//����̰�����⣺
//һ����һ��������˵������Ҷ˵�����˫�ؼ�������

//1����ÿ�����䰴�Ҷ˵��С��������
//2����ǰ����һ��ö��ÿ������
//      �����ǰ�������Ѿ������㡣��ֱ��pass
//      ����ѡ��ǰ������Ҷ˵�
//̰��ֻ����ǰһС������Ž⣬���յ���ȫ�ֵ����Ž⣨���������ܲ����ҵ����Ž⣬Ҫ֤����

//prove��A=B
//A>=B
//A<=B
//then A=B

//ans<=cnt (ans������cnt�е���Сֵ������ans<=cnt)
//������֤��ans>=cnt:
//�����൱���ҵ���cnt������û�н���������
//��Ϊcnt��ÿ��cnt�ĵ���า����һ������
//Ȼ����С���з�����ans����Ҫ������������
//����ans>=cnt
//�������֤����ans=cnt
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
    int ed=-2e9;//ed��ʾ��һ������±�
    //��Ϊһ��ʼû��ѡ���Ϳ���������
    
    for(int i=0;i<n;i++)
        if(srange[i].l>ed)
        {
            res++;//�ҵ�һ���µĵ�
            ed=srange[i].r;//��ǰѡ�����±����Ϊ��������Ҷ�
        }
    
    cout<<res;
    
    return 0;
}
