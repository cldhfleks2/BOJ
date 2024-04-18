#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
using namespace std;
int N, M, **house;
int r, c, d; //�κ���ġ,  ���� 0)�� 1)�� 2)�� 3)��
/*
0 : û��������������
1 : ��
2 : û����
*/
void clean(); //�Լ�������
int cd(int dir);
int next(int dir);
void move(int dir);
bool f();

void clean() { //���� �κ���ġ�� û��
	if (house[r][c] != 2) {
		house[r][c] = 2; 
	}
}

bool f() { //����� ���� �����°�
	if(next(d) != 0 &&
		next(cd(d)) != 0 &&
		next(cd(cd(d))) != 0 &&
		next(cd(cd(cd(d)))) != 0) {
		return true;
	}
	return false;
}

int cd(int dir) { //������ȯ(�ݽð��������-����)
	dir--;
	if (dir == -1) dir = 3;
	return dir;
}
//dir���� 1ĭ�տ� �������ִ°�
int next(int dir) { 
	//0) û��������������
	//1) ��(�̵��Ұ�, �迭�����������쵵 ����)
	//2) û���Ѱ���
	int now_r = r, now_c = c;
	if (dir == 0) {
		now_r--; //��
	}
	else if (dir == 1) {
		now_c++; //��
	}
	else if (dir == 2) {
		now_r++; //��
	}
	else if (dir == 3) {
		now_c--; //��
	}
	if (now_r < 0 || now_r == N ||
		now_c < 0 || now_c == M) {
		return 1; //�̵��Ұ����Ѱ��� �����λ�����
	}
	return house[now_r][now_c]; //����(0,1,2)�� ���
}

//������ dir�������� �����̴� �Լ�
void move(int dir) { 
	int now_r = r, now_c = c;
	if (dir == 0) {
		now_r--; //��
	}
	else if (dir == 1) {
		now_c++; //��
	}
	else if (dir == 2) {
		now_r++; //��
	}
	else if (dir == 3) {
		now_c--; //��
	}
	r = now_r; //������ġ ���
	c = now_c;
}

void robot() {
	while (true) {
		clean(); //������ġû��

		int dir = cd(d); //�������� �ѹ�����.
		if (next(dir) == 0) {
			//û���������������̶��
			move(dir);
			d = dir;
			continue;
		}

		if (f()) { //����̸������
			dir = cd(cd(d)); //�ι������� ��������
			if (next(dir) == 1) {
				//�ڰ� ���̾��ٸ� �����Ұ��ϴ� ����
				return;
			}
			else {
				//���������ϸ�
				move(dir); //����
				continue;
			}
		}
		//���̳� û���Ѱ��̶�� ���⸸��ȯ
		d = dir;
	}
}

void printAll() { //û���� �� ������ ���
	int res=0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (house[i][j] == 2)
				res++;
	printf("%d", res);
}

int main(void) {
	scanf("%d%d", &N, &M);

	house = new int*[N];
	for (int i = 0; i < N; i++)
		house[i] = new int[M]; //�ʻ���

	scanf("%d%d%d", &r, &c, &d);
	for(int i = 0 ; i < N ; i++) //�ʱ��
		for (int j = 0, temp=0; j < M; j++) {
			scanf("%d", &temp);
			house[i][j] = temp;
		}
	robot();

	printAll();
	return 0;
}