#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
using namespace std;

int main(int n) {
	queue<int> q;
	scanf("%d\n", &n);
	while (n--) {
		char c[13]; //����ũ�� 11 �������� 2
		scanf("%[^\n]s", &c);
		scanf("%c", &c[12]); //c[12]�� �ʿ���� �ٹٲ޹��ڸ� ����

		if (c[0] == 'p' && c[3] == 'h') { //push�ΰ��
			int cursor = 5; 
			int size = 0; //���ڱ���
			for (int i = cursor; i < 11; i++) //���� ���̸� ��
				size++;
			char* num = new char[size]; //���ڸ���Ÿ�� ���ڿ�
			//���ڸ� ���ڸ��� ����
			for (int i = 0; i < size; i++) {
				num[i] = c[5 + i]; 
			}

			//���ڿ��� ���ڷ�
			int number = atoi(num);

			q.push(number);
		}
		else if (c[0] == 'p') { //pop
			printf("%d\n", q.empty() ? -1 : q.front());
			if (!q.empty())
				q.pop();
		}
		else if (c[0] == 's') { //size
			printf("%d\n", q.size());
		}
		else if (c[0] == 'e') { //empty
			printf("%d\n", q.empty());

		}
		else if (c[0] == 'f') { //front
			printf("%d\n", q.empty() ? -1 : q.front());
		}
		else if (c[0] == 'b') {
			printf("%d\n", q.empty() ? -1 : q.back());
		}
	}

	return 0;
}