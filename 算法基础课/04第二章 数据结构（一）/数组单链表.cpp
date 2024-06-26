#include<iostream>

using namespace std;

const int N=100010;



//head表示头节点下标 
//e[i]表示节点的值
//ne[i]表示下一个节点的位置
//idx表示当前用到了哪个点 
int head,e[N],ne[N],idx;

void init()
{
	head=-1;
	idx=0;
}

//将x插入到头节点 
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
