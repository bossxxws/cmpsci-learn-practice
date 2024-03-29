#include <iostream>

#include <vector>

using namespace std;

const int N = 1000010, M = 10000010;

int n, m;
char p[N], s[M]; //pΪģʽ����sΪ�ַ�����p��Ϊ�Ӵ������ģʽ���г���
int ne[N];

int main() {
	cin >> n >> p >> m >> s; //nΪģʽ�����ȣ�mΪ�ַ������ȣ�n<m
	//����next��
	//����ģʽ����next��
	int i = 0, j = -1;
	ne[0] = -1;
	while (i < n) { //����Ӧ����n
		if (j < 0 || p[i] == p[j]) {
			j++;
			i++;
			ne[i] = j;
		} else {
			j = ne[j];
		}
	}
	//kmpƥ��
	i = 0, j = 0;
	//����ƥ����߼��Ҹ���һ�£����֮ǰ��һ��i = i-n�Ļ�����䣬�ᵼ��ʱ�临�Ӷ�����
	//�������KMP������ȷ�ģ���iֻ�����ӣ��������
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
