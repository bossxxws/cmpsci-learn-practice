#include<bits/stdc++.h>

using namespace std;

const int N=103;
const int S=10005;

int n;

struct node
{
    int s,e,l;
};

node a[N];

int f[S];//ǰi����Ʒ����ʱ�䲻����j����ȡ���������

bool cmp(node a,node b)
{
    return a.s*b.l < b.s*a.l;
}

int main()
{
    int t;
    cin>>t;
    int cnt=0;
    while(t--)
    {
        memset(f, -0x3f, sizeof f);//ǡ�õ�������ȫ����ʼ��Ϊ������
        int time=0;
        
        cin>>n;

        for(int i=1;i<=n;i++)
        {
            int s,e,l;
            cin>>s>>e>>l;
            time+=s;
            a[i]={s,e,l};
        }//�������ݣ������ʱ��time
        
        //��̰��һ�£�����������н��ж�̬�滮
		//����̰����Ŀ��ˣ�Ӽ���ţ
		//֤�� a.s*b.l < b.s*a.l �ĳԷ������Ž⼴�� 
        sort(a+1,a+n+1,cmp);//�������ԭ�������a+n+1����+1�ˣ�������������������
		//���������� 
        
        //ѡǰi������ʱ��Ϊ0�ķ�����״̬����0 
		f[0]=0;
		
        //��ʼʹ�ñ���
        for(int i=1;i<=n;i++)
        {
            for(int j=time;j>=a[i].s;j--)
            {
                //f[j]=f[j];//��ѡ��i��
                f[j]=max(f[j],f[j-a[i].s]+max(0,a[i].e-a[i].l*(j-a[i].s)));//���ϵ�����ʧ�������
                //��Ϊ��ǡ�õ���� ����˵j-a[i]���ǳ�ǰ��ʯͷ���ĵ�����
            }
        }
        int res=0;
        
        for(int i=1;i<=time;i++)res=max(f[i],res);//ÿ��ʱ��״̬��ѡ�����ģ���Ϊ��ǡ�ɣ���һ���ĸ���� 

        printf("Case #%d: %d\n",++cnt,res);
    }

    return 0;
}

