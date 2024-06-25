#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

int i, j, height = 20, width = 20;
int gameover, score;
int x, y, fruitX, fruitY, flag;

// 蛇的坐标和长度
int length;
int tailX[100], tailY[100];

// 初始化游戏
void setup() {
    gameover = 0;

    // 初始位置在屏幕中间
    x = height / 2;
    y = width / 2;

    // 初始长度为1
    length = 1;

    // 初始分数为0
    score = 0;

    // 随机生成果实位置
    fruitX = rand() % height;
    if (fruitX == 0)
        fruitX++;
    fruitY = rand() % width;
    if (fruitY == 0)
        fruitY++;

    // 方向 flag
    flag = 0;
}

// 画图
void draw() {
    system("cls");
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            if (i == 0 || i == width - 1 || j == 0 || j == height - 1) {
                printf("#");
            } else {
                if (i == x && j == y)
                    printf("0");
                else if (i == fruitX && j == fruitY)
                    printf("*");
                else {
                    int isPrinted = 0;
                    for (int k = 0; k < length; k++) {
                        if (i == tailX[k] && j == tailY[k]) {
                            printf("o");
                            isPrinted = 1;
                        }
                    }
                    if (isPrinted == 0)
                        printf(" ");
                }
            }
        }
        printf("\n");
    }
    printf("Score:%d", score);
    printf("\n");
    printf("press X to quit the game");
}

// 接收输入
void input() {
    char ch = _getch();
    if (ch) {
        switch (ch) {
        case 'a':
            flag = 1;
            break;
        case 's':
            flag = 2;
            break;
        case 'd':
            flag = 3;
            break;
        case 'w':
            flag = 4;
            break;
        case 'x':
            gameover = 1;
            break;
        }
    }
}

// 逻辑操作
void algorithm() {
    Sleep(0.01);
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = x;
    tailY[0] = y;

    for (int i = 1; i < length; i++) {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

    switch (flag) {
    case 1:
        y--;
        break;
    case 2:
        x++;
        break;
    case 3:
        y++;
        break;
    case 4:
        x--;
        break;
    default:
        break;
    }

    if (x < 0 || x > height || y < 0 || y > width)
        gameover = 1;

    for (int i = 0; i < length; i++) {
        if (tailX[i] == x && tailY[i] == y)
            gameover = 1;
    }

    if (x == fruitX && y == fruitY) {
        score += 10;
        // 生成新的果实
        fruitX = rand() % height;
        if (fruitX == 0)
            fruitX++;
        fruitY = rand() % width;
        if (fruitY == 0)
            fruitY++;
        length++; // 蛇的长度增加
    }
}

int main() {
    int m, n;

    // 游戏初始化
    setup();

    // 游戏循环
    while (!gameover) {
        // 画面
        draw();

        // 接收输入
        input();

        // 逻辑操作
        algorithm();
    }
    system("pause");
    return 0;
}