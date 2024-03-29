#include<iostream>

using namespace std;

const int N=100010;



//head��ʾͷ�ڵ��±� 
//e[i]��ʾ�ڵ��ֵ
//ne[i]��ʾ��һ���ڵ��λ��
//idx��ʾ��ǰ�õ����ĸ��� 
int head,e[N],ne[N],idx;

void init()
{
	head=-1;
	idx=0;
}

//��x���뵽ͷ�ڵ� 
void add_to_head(int x)
{
	e[idx]=x;
	ne[idx]=head;
	head=idx;
	idx++;	
}

void add(int k,int x)
{
    e[idx]=x;
    ne[idx]=ne[k];
    ne[k]=idx;
    idx++;
}

void remove(int k)
{
    ne[k] = ne[ne[k]];
    
}
int main()
{
    init();
	int m;
	cin>>m;
	while(m--)
	{
	    int k,x;
    	char op;
    	cin>>op;
    	if(op=='H')
    	{
    	    cin>>x;
    	    add_to_head(x);
    	}
    	else if(op=='D')
    	{
    	    cin>>k;
    	    if(!k)head=ne[head];
    	    remove(k-1);
    	}
    	else
    	{
    	    cin>>k>>x;
    	    add(k-1,x);
    	}
	}
    for(int i=head;i!=-1;i=ne[i])cout<<e[i]<<' ';
    cout<<endl;
	
	return 0;
}
