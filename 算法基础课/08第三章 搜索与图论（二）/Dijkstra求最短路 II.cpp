//���Ż��� ���ڽӱ�����ȶ���  O(mlogn)  mΪ��  nΪ�� 
#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int> PII;

const int N=1e6+10;

int  n,m;

int h[N],e[N],ne[N],idx,w[N];

int dist[N];
bool st[N];

void add(int a,int b,int c)
{
    e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}

int dijkstra()
{
	memset(dist,0x3f,sizeof dist);//�����о����ʼ��Ϊ������ 
	dist[1]=0;//һ�ŵ�ľ����ʼ��Ϊ0 
	
	priority_queue<PII,vector<PII>,greater<PII>> heap;
	heap.push({0,1});//һ�ŵ�ľ���Ϊ0
	
	while(heap.size())
    {
        auto t =heap.top();
        heap.pop();
        
        int ver=t.second;//��ı��
        int distance=t.first;//��ľ���
        if(st[ver])continue;
        for(int i=h[ver];i!=-1;i=ne[i])
        {
            int j=e[i];
            if(dist[j]>distance+w[i])
            {
                dist[j]=distance+w[i];
                heap.push({dist[j],j});
            }
        }
        st[ver]=true;
    }	
    
	if(dist[n]==0x3f3f3f3f)return -1;//��ʾû��·���Դﵽ 
	return dist[n]; 
}

int main()
{
	scanf("%d%d",&n,&m);
	
	memset(h,-1,sizeof h);
	
	while(m--)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		add(a,b,c);
	}
	
	int t=dijkstra();
	
	printf("%d\n",t);
	
	return 0;
} 
