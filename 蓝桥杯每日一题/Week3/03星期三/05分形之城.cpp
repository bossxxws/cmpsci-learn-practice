#include<bits/stdc++.h>

typedef long long LL;

using namespace std;

typedef pair<LL,LL> PLL;

#define x first

#define y second

PLL calc(LL n,LL m)
{
	//n代表城市等级 
	//m代表坐标，从0开始计数 
	if(n==0)return {0,0};
	LL len = 1ll <<(n-1);//本等级内象限的边长/2 
	LL cnt=1ll<<(2*n-2);//当前等级的容量
	PLL pos = calc(n - 1, m % cnt);  // 上一等级的坐标信息 
	LL x=pos.x,y=pos.y;
	int z=m/cnt;//处于哪个象限 
	 if (z == 0)
        return { - y - len, - x + len };
    // 右上象限更换原点（x+len,y+len）
    else if (z == 1)
        return { x + len, y + len };
    // 右下象限更换原点（x+len,y-len）
    else if (z == 2)
        return { x + len, y - len };
    // 左下象限逆转90°（-y,x）沿y对称（y,x）更换原点（y-len,x-len）
    return { y - len, x - len };
}

int main()
{
	
	return 0;
}
