//�ò�ִ���ÿ��λ�ñ�ѯ�ʵĴ���
#include<bits/stdc++.h>

using namespace std;

typedef long long LL;

int n,m;

const int N=1e5+3;

int a[N],b[N];

int main()
{
    cin>>n;
    //cout<<n<<m<<endl;
    for(int i=1;i<=n;i++)
    {
    	scanf("%d",&a[i]);
    }
    cin>>m;
    for(int i=0;i<m;i++)
    {
    	int l,r;
    	cin>>l>>r;
    	//cout<<l<<" "<<r<<endl;
    	b[l]++;
    	b[r+1]--;
    	
    	//�������ˣ�����ǰ׺�ͼ������� ѯ�ʴ��� 
    }
    
    LL sum1=0,sum2=0;//sum1��ԭ���ģ�sum�Ǳ��� 
    
    for(int i=1;i<=n;i++)//���䷶Χ��С�ڵ���n�ģ�����ö�ٵ�n���ɣ�һ��ʼ��ö�ٵ�N�� 
    {
        //cout<<b[i]<<endl;
    	b[i]=b[i]+b[i-1]; 
    	//cout<<b[i]<<endl;
    	sum1+=(LL)a[i]*b[i];
    }
    
    sort(a+1,a+n+1);sort(b+1,b+n+1);
    
    for(int i=1;i<=n;i++)
    {
    	sum2+=(LL)a[i]*b[i];
    }
    
    cout<<sum2-sum1;
    
    return 0;
}
