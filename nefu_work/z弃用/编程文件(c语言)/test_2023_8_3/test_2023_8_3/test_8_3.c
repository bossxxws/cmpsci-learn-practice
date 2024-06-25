#include <stdio.h>
int main() //主函数-程序的入口—必须要有main函数且只有一个
{
	char ch = 'X';
	printf("%c\n", ch); //%c打印字符格式的数据
	short age = 20;//向内存申请两个字节 16个bit位，用来存放20
	float weight = 95.6f;
	printf("%d\n", age);//打印整型十进制数据
	printf("~~巧丽~~\n");
	printf("~~巧丽~~\n");
	printf("~~巧丽~~\n");
	return 0;
}