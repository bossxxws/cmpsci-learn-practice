/*
//���ذ�д�� 
//ʱ�临�Ӷȣ�O��nlogn�� 
#include<bits/stdc++.h>

using namespace std;


const int N=1e6+10;


int primes[N],cnt;
bool st[N];

void get_primes(int n)
{
	for(int i=2;i<=n;i++)
	{
		if(!st[i])
		{
			primes[cnt++]=n;
		}
		for(int j=i+i;j<=n;j+=i)
    	{
    		st[j]=true;
    	}
	}

}
 
int main()
{
    int n;
    cin>>n;
    get_primes(n);
    
    cout<<cnt<<endl;
    return 0;
}

*/

//--------------------------------------------------------------------------------
/*
//�Ż���
//����ɸ�� 
//ʱ�临�Ӷȣ�O��nloglogn�� 
#include<bits/stdc++.h>

using namespace std;


const int N=1e6+10;


int primes[N],cnt;
bool st[N];

void get_primes(int n)
{
	for(int i=2;i<=n;i++)
	{
		if(!st[i])
		{
			primes[cnt++]=n;
			for(int j=i+i;j<=n;j+=i)
        	{
        		st[j]=true;
        	}
		}

	}

}
 
int main()
{
    int n;
    cin>>n;
    get_primes(n);
    
    cout<<cnt<<endl;
    return 0;
}

*/

//------------------------------------------------------------------------------
//����ɸ��  O��n��           1e7����Ȱ���ɸ����һ�� 
#include<bits/stdc++.h>

using namespace std;

const int N=1e6+10;

int primes[N],st[N],cnt;


//����һ�����Ա������ӷֽ� 
void get_primes(int n)
{
    for(int i=2;i<=n;i++)//��2��ʼ����n֮ǰ������ 
    {
        if(!st[i])primes[cnt++]=i;//���֮ǰû�б�ɸ�����ʹ浽������primes�� 
    	for(int j=0;primes[j]<=n/i;j++)//��С����ö��������ֹͣ������ ����*iС�ڵ���n 
    	{
    		st[primes[j]*i]=true;//���Ϊ�Ǻ�����ɸ��primes[j]*i����С��������primes[j]�� 
    		if(i%primes[j]==0) break;
			//1.i%primes[j]==0,primes[j]һ����i����С������								 
			//  primes[j]һ����primes[j]*i����С������ 
			
			
			//2.i%primes[j]��=0��primes[j]һ��С��i����С�����ӣ���Ϊ�����Ǵ�С����ö�ٵ����������� 
			//  primes[j]Ҳһ����primes[j]*i����С������ 
			//  ��������¼������ø���������ӣ�ֱ��primes[j]��i����С������ 
    	}
    }

}

int main()
{
	int n;
	cin>>n;
	
	get_primes(n);
	
	cout<<cnt<<endl;
	
	return 0;
} 

