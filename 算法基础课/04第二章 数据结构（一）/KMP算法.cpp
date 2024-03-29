#include <iostream>

#include <vector>

using namespace std;

const int N = 1000010, M = 10000010;

int n, m;
char p[N], s[M]; //p为模式串，s为字符串，p作为子串多次在模式串中出现
int ne[N];

int main() {
	cin >> n >> p >> m >> s; //n为模式串长度，m为字符串长度，n<m
	//构建next表
	//构建模式串的next表
	int i = 0, j = -1;
	ne[0] = -1;
	while (i < n) { //这里应该是n
		if (j < 0 || p[i] == p[j]) {
			j++;
			i++;
			ne[i] = j;
		} else {
			j = ne[j];
		}
	}
	//kmp匹配
	i = 0, j = 0;
	//整个匹配的逻辑我改了一下，你的之前有一个i = i-n的回溯语句，会导致时间复杂度上升
	//现在这个KMP才是正确的，即i只会增加，不会减少
	while (i < m) {
		if (j == -1 || s[i] == p[j]) {
			i++;
			j++;
		} else {
			j = ne[j];
		}
		if (j == n) {
			cout << i - n << " ";
			j = ne[j];
		}
	}
	return 0;
}
