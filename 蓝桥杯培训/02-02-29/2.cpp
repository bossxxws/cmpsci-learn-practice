#include<bits/stdc++.h>

using namespace std;

int v0,n;
double c0,t0;
stack< pair<int,double> >his;//�洢��ʷ 
pair<int,double>ori;//�洢����������Ũ�� 

void operate(int v,double c)
{
	double t=(double)v*c;//�������Һ������ 
	if(!his.empty())
	{
		double tn=(double)his.top().first*his.top().second;//ԭ������Һ������ 
		double st=t+tn;//�ܵ�����
		int sv=his.top().first+v;//����� 
		double nc=st/(double)sv;//���µ�Ũ�� 
		pair<int,double> nhis;
		nhis={sv,nc};
		his.push(nhis);
	}
	else
	{
		double tn=(double)ori.first * ori.second;//ԭ������Һ������ 
		double st=t+tn;//�ܵ�����
		int sv=ori.first+v;//����� 
		double nc=st/(double)sv;//���µ�Ũ�� 
		pair<int,double> nhis;
		nhis={sv,nc};
		his.push(nhis);
	}
}

int main()
{
	cin>>v0>>c0>>n;
	ori={v0,c0};
	t0=(double)v0/c0;
	
	while(n--)
	{
		char op;
		cin>>op;
		if(op=='P')
		{
			int v;
			double c;
			cin>>v>>c;
			operate(v,c);
			cout<<his.top().first<<" ";
			printf("%.5f\n",his.top().second);
		}
		else
		{
			if(!his.empty())
			{
				his.pop();
				if(!his.empty())
				{
					cout<<his.top().first<<" ";
				    printf("%.5f\n",his.top().second);
				}
				else
				{
					cout<<ori.first<<" ";
					printf("%.5f\n",ori.second);
				}
			}
			else
			{
				cout<<ori.first<<" ";
				printf("%.5f\n",ori.second);
			}
		}
	}
	
	return 0;
}
