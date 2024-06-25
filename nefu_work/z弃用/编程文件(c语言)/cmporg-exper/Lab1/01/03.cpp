//��4������ ./cmd inputfile filterfile outputfile �������� 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<string.h>
#define filterSize 3
#define matrixSize 3

#define AO o_val
#define ZHANG  n_val 
#define ZHANG_AO r

int s[5][5];//��չ���� 

int f[3][3];

int r[5][5];//�洢��� 


struct matrix 
{
  int o_val;
  int n_val;
};//����ṹ�� 

typedef struct matrix Matrix;

int main(int argc, char *argv[]) 
{
	FILE *file1, *file2;

	int iter=1;
	
//	if (argc < 4) 
//	{
//		printf("Usage: ./convolution1 data1.txt filter1.txt 1\n");
//		return 1;
//	}
	
	//file1 = fopen(argv[1], "r");
	file1=fopen("data0.txt","r");
	//file2 = fopen(argv[2], "r");
	file2=fopen("filter0.txt","r"); 
	//file3 = fopen(argv[3], "w");
	
	//iter=atoi(argv[4]);
	
//	if ((file1 == NULL) || (file2 == NULL)) 
//	{
//		printf("Error: Files cannot open\n");
//		//return 1;//�ļ�Ϊ�յ���� 
//	}
//	
	//iter = atoi(argv[3]);//�������� 
	
//	if (iter == 0) 
//	{
//		printf("Error: Invalid iteration\n");
//		//return 1;//��������Ϊ0����� 
//	}
	

  	
  	int num1,num2,num3;
  	
  	int t=0;//��ȡԴ���� 
    while (fscanf(file1, "%d,%d,%d", &num1, &num2, &num3) == 3) 
	{
		s[t][0]=num1;s[t][1]=num2;s[t][2]=num3;
		t++;
    	//printf("��ȡ��������: %d %d %d\n", num1, num2, num3);
	}
	

	
	//��ȡ������ 
	t=2;
	while (fscanf(file2, "%d,%d,%d", &num1, &num2, &num3) == 3) 
	{
		f[t][0]=num1;f[t][1]=num2;f[t][2]=num3;
		t--;
    	//printf("��ȡ��������: %d %d %d\n", num1, num2, num3);
	}
	//��ʱ�Ѿ����·�ת 
	
	//���һ��������� 
	for(int i=0;i<3;i++)
	{
		//swap(f[0][i],f[2][i]);
		t=f[i][0];
		f[i][0]=f[i][2];
		f[i][2]=t;
	}
	

//    for(int i=0;i<3;i++)
//    {
//    	for(int j=0;j<3;j++)
//    	{
//    		printf("%d ",s[i][j]);
//		}
//		printf("\n");
//	}
//	
//	for(int i=0;i<3;i++)
//    {
//    	for(int j=0;j<3;j++)
//    	{
//    		printf("%d ",f[i][j]);
//		}
//		printf("\n");
//	}

    
    while(iter--)//������� 
    {
    	memset(r,0,sizeof r);
//    	//1
//    	int res=0;
//    	
//    	for(int i=0;i<3;i++)//�ߵ���i�� 
//    	{
//    		int res;
//    		for(int j=0;j<3;j++)//�ߵ���j�� 
//    		{
//
//    			res+=s[i][j]*f[i][j];
//			}	
//		}	
//		r[0][0]=res;
		
		//1

		ZHANG_AO[0][0]+=f[2][2]*s[0][0];
		
		//2
		ZHANG_AO[0][1]+=f[2][1]*s[0][0]+f[2][2]*s[0][1];
		
		//3
		
		ZHANG_AO[0][2]+=f[2][0]*s[0][0]+f[2][1]*s[0][1]+f[2][2]*s[0][2];
		
		//4
		
		ZHANG_AO[1][0]+=s[0][0]*f[1][2]+s[1][0]*f[2][2];
		
		//5
		
		ZHANG_AO[1][1]+=s[0][0]*f[1][1]+s[0][1]*f[1][2]+s[1][0]*f[2][1]+s[1][1]*f[2][2];
		
		//6
		
		ZHANG_AO[1][2]+=s[0][0]*f[1][0]+s[0][1]*f[1][1]+s[0][2]*f[1][2]
				+s[1][0]*f[2][0]+s[1][1]*f[2][1]+s[1][2]*f[2][2];
				
		//7
		
		ZHANG_AO[2][0]=s[0][0]*f[0][2]+s[1][0]*f[1][2]+s[2][0]*f[2][2];
		//printf("%d\n",f[2][2]);
		//8
		
		ZHANG_AO[2][1]=s[0][0]*f[0][1]+s[0][1]*f[0][2]
			   +s[1][0]*f[1][1]+s[1][1]*f[1][2]
			   +s[2][0]*f[2][1]+s[2][1]*f[2][2];
		
		//9
		
		int res=0;
		
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			{
				res+=s[i][j]*f[i][j];
			}
		}
		
		ZHANG_AO[2][2]=res;
		
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			{
				s[i][j]=r[i][j];
			}
		}
		
	}
	
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			printf("%d ",s[i][j]);
		}
		printf("\n");
	}
	//printf("%d",s[2][2]);
  	return 0;
}

