#include<bits/stdc++.h>

using namespace std;

int v0,n;
double c0,t0;
stack< pair<int,double> >his;//存储历史 
pair<int,double>ori;//存储最初的体积和浓度 

void operate(int v,double c)
{
	double t=(double)v*c;//加入的溶液的溶质 
	if(!his.empty())
	{
		double tn=(double)his.top().first*his.top().second;//原来的溶液的溶质 
		double st=t+tn;//总的溶质
		int sv=his.top().first+v;//总体积 
		double nc=st/(double)sv;//最新的浓度 
		pair<int,double> nhis;
		nhis={sv,nc};
		his.push(nhis);
	}
	else
	{
		double tn=(double)ori.first * ori.second;//原来的溶液的溶质 
		double st=t+tn;//总的溶质
		int sv=ori.first+v;//总体积 
		double nc=st/(double)sv;//最新的浓度 
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
