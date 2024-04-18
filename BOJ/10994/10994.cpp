#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>

int main(int n) {
	scanf("%d", &n);
	int size = 4 * n - 3;
	char** star = new char* [size];
	for (int i = 0; i < size; i++) {
		star[i] = new char[size];
		for (int j = 0; j < size; j++)
			star[i][j] = ' '; //공백문자로 초기화
	}
	
	int start = 0;
	int end = 4 * n - 4;

	for (int i = 0; i < n; i++) {
		for (int j = start; j <= end; j++) {
			star[start][j] = '*'; //상단 한줄

			star[j][start] = '*'; //좌측 한줄

			star[j][end] = '*'; //우측 한줄

			star[end][j] = '*'; //하단 한줄
		}
		start += 2;
		end -= 2;
	}

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++)
			printf("%c", star[i][j]);
		printf("\n");
	}

	return 0;
}
