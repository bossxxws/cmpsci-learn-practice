#include <stdio.h>
int main()
{
    char 姓;
    char 名;
    printf("请输入您的姓、名\n");
    scanf_s("%s %s", 姓,名);
    printf("你的姓为：%s, 你的名为：%s", 姓, 名);
    return 0;
}