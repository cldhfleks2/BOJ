#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>

int m, n;

int main(void) {
	scanf("%d %d\n", &m, &n);
	char junk[502];
	int res[5] = { 0, };
	char** arr = new char* [5*m];
	for (int i = 0; i < 5 * m; i++)
		arr[i] = new char[5 * n + 1]; //마지막 \0문자까지 고려한 크기

	//두번재줄인 ############# 은 지워버림
	scanf("%[^\n]s", &junk); //######## 지움

	for (int i = 0; i < 5 * m; i++) {
		scanf("%[\n]c", &junk); //줄바꿈문자를 지움

		for (int j = 0; j < 5 * n + 1; j++) {
			scanf("%c", &arr[i][j]);
		}
	}
	//m x n 행열을 조사한다.
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			int check = 0;
			for (int k = 0; k < 4; k++) { //4줄에 해당하는 블라인드를 탐색
				char c = arr[5 * i + k][5 * j + 1];
				if (c == '.') //닫힌걸발견시 끝냄
					break;
				check++; //아니면 계속반복하여 블라인드 상태를 결정
			}
			//결정된 블라인드 상태에따라 결괏값에 반영
			res[check]++;
		}
	}
	for (int i = 0; i < 5; i++)
		printf("%d ", res[i]);
	
	return 0;
}