//�߾��������
//����ֱ���ø߾������㣨�������㣩 
//��Ч�ʱȽϵ�
 
//���ǲ��÷ֽ�������

/*
˼·��
1���ֽ⣨��������ģ���������ת��Ϊ��˵���ʽ 
2��дһ���߾��ȳ˷�
3�� ���� 
*/ 

//��a���� ����p�ĸ��� ��ÿ�����ֽ������������Ҫ�� 
//res��a����=[a/p]+[a/p**2]+........    һֱ�ӵ�p�����ɴη���a��Ϊֹ��������ʾ����ȡ���� 

//1��ɸ��������5000���ڵ�����ɸ����
//2����ÿ�������Ĵ���
//3���ø߾��ȳ˷���ÿ�����������

#include<bits/stdc++.h>

using namespace std;

const int N=5010;

//ɸ����ģ��
int primes[N],cnt;
bool st[N];

int sum[N];

void get_primes(int n)
{
    for(int i=2;i<=n;i++)//ɸѡn���ڵ�����
    {
        if(!st[i])primes[cnt++]=i;//�浽��������
        for(int j=0;primes[j]<=n/i;j++)
        {
            st[primes[j]*i]=true;
            if(i%primes[j] == 0)break;
        }
    }
}


//��n���Ľ׳�������p�ĸ���
int get(int n,int p)
{
    int res=0;
    while(n)//���nΪ0���ʾp�����ɴη��Ѿ���n��
    {
        res+=n/p;
        n/=p;
    }
    return res;
}

vector<int> mul(vector<int> a,int b)
{
    vector<int> c;
    int t=0;//��ʾ��λ����
    for(int i=0;i<a.size();i++)//�Ӹ�λ��ʼ��,ǰ�����ǵ�λ
    {
        t+=a[i]*b;
        c.push_back(t%10);
        t/=10;
    }
    
    while(t)
    {
        c.push_back(t%10);
        t/=10;
    }
    
    return c;
}

int main()
{
    int a,b;
    cin>>a>>b;
    
    get_primes(a);
    
    //��ÿһ�������Ĵ���
    for(int i=0;i<cnt;i++)
    {
        int p=primes[i];
        sum[i]=get(a,p)  -  (get(b,p)  +  get(a-b,p));//��һ�µ�ǰ����������p�Ĵ����Ƕ���
        //������Ϊ�õ����Ǵη���������Ϊ��ʽ����֪����������ģ����Լ�ȥ�η�������
    }
    
    //�ø߾��ȳ˷���ÿ�������ӳ�����
    //tip���κ�һ�������Ա�ʾΪ�����Ĵ�����ӣ���������˸����������������p�Ĵ���
    //     ����Щ������Ӽ��ɣ�����������̫���ø߾��ȳ˷�
    
    vector<int>res;
    res.push_back(1);
    
    for(int i=0;i<cnt;i++)//��ǰ����ö�����е�����
        for(int j=0;j<sum[i];j++)//ö�ٵ�ǰ�����Ĵ�������ǰ�����Ĵ�����sum��i����
            res=mul(res,primes[i]);//�߾��ȳ˷�
            
    for(int i=res.size()-1;i>=0;i--)printf("%d",res[i]);//ע������ȷ��ʽ����𰸣��Ӻ���ǰ
    
    return 0;
}
