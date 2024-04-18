#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
int t, *n;
//[t][n]
//[Ŭ����][�л���] �� �������迭
int* Max, * Min, ** Score, * gap; 

void init() {
	scanf("%d", &t);
	n = new int[t];
	Max = new int[t];
	Min = new int[t];
	gap = new int[t];
	Score = new int*[t];

	//��� �Է��� �޴� �κ�
	for (int i = 0; i < t; i++) {
		scanf("%d", &n[i]);
		Score[i] = new int[n[i]];

		//������ ����ϴ� �κ�
		for (int j = 0, temp; j < n[i]; j++) {
			scanf("%d", &temp);
			Score[i][j] = temp;
		}
	}

	//�Է¹��� �������� �����ϴ� �κ�
	for (int i = 0; i < t; i++) {
		int *s = new int[n[i]];
		for (int j = 0; j < n[i]; j++)
			s[j] = Score[i][j];
		std::sort(s, s + n[i]); //������
		for (int j = 0; j < n[i]; j++)
			Score[i][j] = s[j]; //�ٽ� �缳��
	}

	//�ʱ�ȭ
	for (int i = 0; i < t; i++) {
		gap[i] = 0;
		Max[i] = 0;
		Min[i] = 100; 
	}
}

void calculate() {
	//Max Min
	for (int i = 0; i < t; i++) {
		for (int j = 0, temp; j < n[i];  j++) {
			temp = Score[i][j];
			if (Max[i] <= temp) 
				Max[i] = temp;
			if (Min[i] >= temp)
				Min[i] = temp;
		}
	}

	//gap
	for (int i = 0; i < t; i++) {
		for (int j = 0, interval; j < n[i] - 1; j++) {
			interval = abs(Score[i][j] - Score[i][j + 1]); //���������� ���
			if (gap[i] < interval) //���������� �ִ񰪸� ����
				gap[i] = interval;
		}
	}
}

void printAll() {
	for (int i = 0; i < t; i++) {
		printf("Class %d\nMax %d, Min %d, Largest gap %d\n", i+1, Max[i], Min[i], gap[i]);
	}
}

int main(void) {
	init();
	calculate();
	printAll();
}