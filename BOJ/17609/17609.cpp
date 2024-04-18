#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
int t;
char c[100001];
void func();
int findSize(char* c);
bool isPalindrome(char* c, int size, int cnt);
bool isPalindrome2(char* c, int size, int cnt);

void func() {
	while (t--) {
		scanf("%s", &c);
		int size = findSize(c);
		if (isPalindrome(c, size, 0)) { //ȸ��
			printf("0\n");
		}
		else {
			bool right = isPalindrome(c, size, 1);
			bool right2 = isPalindrome2(c, size, 1);


			if (right || right2)
				printf("1\n"); //����ȸ��
			else
				printf("2\n"); //�Ϲݹ��ڿ���
		}

	}
}

int findSize(char* c) {
	int size = 0;
	for (int i = 0; i < 100001; i++)
		if (c[i] == '\0')
			break;
		else
			size++;
	return size;
}

bool isPalindrome(char* c, int size, int cnt) {
	int front = 0, back = size - 1;
	bool right = true;
	while (front <= back && right) {
		if (c[front] != c[back]) {
			//printf(">> ���� : %d %c %c %d   => ",front, c[front], c[back], back);
			if (cnt > 0) {
				cnt--;
				//�����ϳ� ��ŵ
				if (front + 1 < size && c[front + 1] == c[back]) {
					//���� ���ڸ� Ȯ�ΰ����Ѱ�? (�ùٸ� �����ΰ�)
					if (front + 2 < size && back - 1 > 0 && front + 2 <= back - 1) {
						//���� ���ڵ� ��ġ�ϸ����
						if (c[front + 2] == c[back - 1]) {
							//printf("1] front++ %c %c\n", c[front + 1], c[back]);
							front++;
							continue;
						} //��ġ���������� �Ʒ� �ڵ������
					}
					else { //���� ���ڵ��� Ȯ�κҰ����ϸ� �̴��
						//printf(">> 2] front++ %c %c\n", c[front + 1], c[back]);
						front++;
						continue;
					}
				}

				if (back - 1 > 0 && c[front] == c[back - 1]) {
					if (back - 2 > 0 && front + 1 < size && front + 1 <= back - 2) {
						if (c[front + 1] == c[back - 2]) {
							//printf(">> 3] back-- %c %c\n", c[front], c[back - 1]);
							back--;
							continue;
						}
					}
					else {
						//printf(">> 4] back-- %c %c\n", c[front], c[back - 1]);
						back--;
						continue;
					}
				}
				//����������� ����
				//printf(">> end %c %c\n", c[front], c[back]);
				right = false;
				break;
			}
			else {
				right = false;
				break;
			}
		}
		front++;
		back--;
	}
	return right;
}

bool isPalindrome2(char* c, int size, int cnt) {
	int front = 0, back = size - 1;
	bool right = true;
	while (front <= back && right) {
		if (c[front] != c[back]) {
			//printf(">> ���� : %d %c %c %d   => ", front, c[front], c[back], back);
			if (cnt > 0) {
				cnt--;
				//�����ϳ� ��ŵ
				if (back - 1 > 0 && c[front] == c[back - 1]) {
					if (back - 2 > 0 && front + 1 < size && front + 1 <= back - 2) {
						if (c[front + 1] == c[back - 2]) {
							//printf(">> 3] back-- %c %c\n", c[front], c[back - 1]);
							back--;
							continue;
						}
					}
					else {
						//printf(">> 4] back-- %c %c\n", c[front], c[back - 1]);
						back--;
						continue;
					}
				}

				if (front + 1 < size && c[front + 1] == c[back]) {
					//���� ���ڸ� Ȯ�ΰ����Ѱ�? (�ùٸ� �����ΰ�)
					if (front + 2 < size && back - 1 > 0 && front + 2 <= back - 1) {
						//���� ���ڵ� ��ġ�ϸ����
						if (c[front + 2] == c[back - 1]) {
							//printf("1] front++ %c %c\n", c[front + 1], c[back]);
							front++;
							continue;
						} //��ġ���������� �Ʒ� �ڵ������
					}
					else { //���� ���ڵ��� Ȯ�κҰ����ϸ� �̴��
						//printf(">> 2] front++ %c %c\n", c[front + 1], c[back]);
						front++;
						continue;
					}
				}

				//����������� ����
				//printf(">> end %c %c\n", c[front], c[back]);
				right = false;
				break;
			}
			else {
				right = false;
				break;
			}
		}
		front++;
		back--;
	}
	return right;
}

int main(void) {
	scanf("%d", &t);
	func();

	return 0;
}