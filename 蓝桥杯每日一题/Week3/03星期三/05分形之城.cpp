#include<bits/stdc++.h>

typedef long long LL;

using namespace std;

typedef pair<LL,LL> PLL;

#define x first

#define y second

PLL calc(LL n,LL m)
{
	//n������еȼ� 
	//m�������꣬��0��ʼ���� 
	if(n==0)return {0,0};
	LL len = 1ll <<(n-1);//���ȼ������޵ı߳�/2 
	LL cnt=1ll<<(2*n-2);//��ǰ�ȼ�������
	PLL pos = calc(n - 1, m % cnt);  // ��һ�ȼ���������Ϣ 
	LL x=pos.x,y=pos.y;
	int z=m/cnt;//�����ĸ����� 
	 if (z == 0)
        return { - y - len, - x + len };
    // �������޸���ԭ�㣨x+len,y+len��
    else if (z == 1)
        return { x + len, y + len };
    // �������޸���ԭ�㣨x+len,y-len��
    else if (z == 2)
        return { x + len, y - len };
    // ����������ת90�㣨-y,x����y�Գƣ�y,x������ԭ�㣨y-len,x-len��
    return { y - len, x - len };
}

int main()
{
	
	return 0;
}
