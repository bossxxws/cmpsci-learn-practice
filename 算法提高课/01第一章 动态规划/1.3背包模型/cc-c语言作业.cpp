#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define filterSize 3
#define matrixSize 3

#define zhang matrixSize

struct matrix 
{
  int o_val;
  int n_val;
};

typedef struct matrix Matrix;

//������ڽṹ����
 
int main(int argc, char *argv[]) 
{
	FILE *file1, *file2, *file3;
	int i = 0;
	int filter[filterSize][filterSize];//������ 
	Matrix **data;//�ṹ�� 
	int j, k, l, m;
	int val;
	int iter;
	
	if (argc < 4) 
	{
		printf("Usage: ./convolution1 data1.txt filter1.txt 1\n");
		return 1;
	}
	
	file1 = fopen(argv[1], "r");
	file2 = fopen(argv[2], "r");
	iter = atoi(argv[3]);
	if ((file1 == NULL) || (file2 == NULL)) 
	{
		printf("Error: Files cannot open\n");
		//return 1;
	}
	
	
	
	if (iter == 0) 
	{
		printf("Error: Invalid iteration\n");
		//return 1;
	}
	
	//malloc�Զ������ڴ�����Ŀռ� 
	data = (Matrix **)malloc(sizeof(Matrix *) * matrixSize);
	
	//data��o�洢����
	//data��n�洢������� 
	for (i = 0; i < matrixSize; i++) 
	{
		data[i] = (Matrix *)malloc(sizeof(Matrix) * matrixSize);//��̬����洢�ռ� 
	}
	
	for(int i=0;i<zhang;i++)
	{
		for(int j=0;j<zhang;j++)
		{
			data[i][j].n_val=1;
		}
	}
	printf(data[0][0].n_val);
//	data[0][0].n_val=-1;
//	data[0][1].n_val=-4;
	
	
}

