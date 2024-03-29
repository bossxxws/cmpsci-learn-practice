//通过初等行变换变成一下倒三角的形式（线性代数） 


//最后一行的结果是x（n）=b（n） 
//倒推上去可求出所有的解 


//初等行变换：
//1、把某一行乘一个非零的数
//2、交换某两行
//3、把某行的若干倍加到另一行上去

//完美阶梯型-----唯一解
//0 == 非零 -----无解
//0 == 0    -----无穷多组解（未知方程的数量小于未知数的数量） 


//高斯消元
/*
枚举每一 *列*  *c*
	1、找到绝对值最大的一行（首个未知数系数的绝对值）
	2、将这行换到最上面（消元过的不用被顶掉） 
	3、将该行第一个数变成1
	4、将下面所有行的第c列消成0 
	
	
*/ 
#include<bits/stdc++.h> 

using namespace std;

const int N=110;

//浮点数存的时候是有误差的 
//浮点数直接判断是否是0是有误差的（比如说可能存的是0.001，浮点数也会判断其为0） 
//这里选择如果一个数小于10的负六次方，就认为他小于0 
const double eps=1e-6;

int n;//函数中要用到的变量放到全局里
double a[N][N];

int gauss()//0表示有唯一解，1表示有无穷多组解，2表示无解 
{
	int r,c;
	for(c=0,r=0;c<n;c++)
	{
		int t=r;//t用来存储对于某一列中，拥有最大系数的行的位置 
		for(int i=r;i<n;i++)//找出最小的数 
			if(fabs(a[i][c])>fabs(a[t][c]))t=i;//fabs为float abs，返回浮点数 
			
		//如果目前这一列（第c列）最大一行的已经是0，（就表明已经全是0）就跳过
		if(fabs(a[t][c])<eps)continue; 
		
		//将这一行搞到最上面去，现在这一行到了第r行 
		for(int i=c;i<=n;i++)swap(a[t][i],a[r][i]);
		
		//将该行第一个数变成1（也就是把该行所有数除上这个数a[r][c]） 
		//这里倒着开始除，从最后一列除到第c列 
		for(int i=n;i>=c;i--)a[r][i]/=a[r][c];

		//将下面所有行的第c列消成0
		for(int i=r+1;i<n;i++) 
			if(fabs(a[i][c])>eps)//如果非零，就消成0 
				for(int j=n;j>=c;j--)//倒着处理这一行的每一个数 
					//a[r][j]在j==c的时候为1，然后乘a[i][c] 
					//a[i][j]在j==c的时候为a[i][c],然后减去1*a[i][c]
					//第i行从第c列开始：
					//每个数都要减去第r行的数乘a[i][c](初等行变换规则) 
					a[i][j]-=a[r][j]*a[i][c]; 
								
		r++;//表示这一行已经经过移动，下次交换的就是这一行的下一行 
	}
	
	//r行下面的都是0 
	if(r<n)
	{
		for(int i=r;i<n;i++)
			if(fabs(a[i][n])>eps)return 2;//零等于非0，无解
		return 1;//有无穷多组解 
	} 
	
	//倒着把答案推出来
	for(int i=n-1;i>=0;i--)//从最后一行开始 
	    for(int j=i+1;j<n;j++)
	    	//求出第i行的解
			//这是个方阵，而且是处理过的倒三角
			//每个未知数坐标都是（i，i），是对称的
	        a[i][n]-=a[i][j]*a[j][n]; 
	        
	return 0;//有唯一解 
}

int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n+1;j++)//其中第n个数为方程另一边的b（n） 
		{
			cin>>a[i][j];
		}	
	}
	
	int t = gauss();
	
	if(t==0)
	{
		for(int j=0;j<n;j++)printf("%.2lf\n",a[j][n]);
	} 
	else if(t==1)puts("Infinite group solutions");
	else puts("No solution");
	
	return 0;
}
