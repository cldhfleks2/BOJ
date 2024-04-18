#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
int t, *n;
//[t][n]
//[클래스][학생수] 의 이차원배열
int* Max, * Min, ** Score, * gap; 

void init() {
	scanf("%d", &t);
	n = new int[t];
	Max = new int[t];
	Min = new int[t];
	gap = new int[t];
	Score = new int*[t];

	//모든 입력을 받는 부분
	for (int i = 0; i < t; i++) {
		scanf("%d", &n[i]);
		Score[i] = new int[n[i]];

		//점수를 기록하는 부분
		for (int j = 0, temp; j < n[i]; j++) {
			scanf("%d", &temp);
			Score[i][j] = temp;
		}
	}

	//입력받은 점수들을 정렬하는 부분
	for (int i = 0; i < t; i++) {
		int *s = new int[n[i]];
		for (int j = 0; j < n[i]; j++)
			s[j] = Score[i][j];
		std::sort(s, s + n[i]); //정렬후
		for (int j = 0; j < n[i]; j++)
			Score[i][j] = s[j]; //다시 재설정
	}

	//초기화
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
			interval = abs(Score[i][j] - Score[i][j + 1]); //점수간격을 계산
			if (gap[i] < interval) //점수간격의 최댓값만 저장
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