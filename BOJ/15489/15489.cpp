#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>

int main(void) {
	int R, C, W, **pt;
	scanf("%d%d%d", &R, &C, &W);
	int size = (R + W);
	pt = new int*[size * (size + 1) / 2 + 1];
	//pt[i][j] i번째줄 j번째숫자 (1부터시작)
	for (int i = 1; i <= size; i++) {
		pt[i] = new int[i+1]; //시작인덱스를 1부터셈 
		pt[i][0] = 0;
	}
	for (int i = 1; i <= size; i++) { //i번째줄
		for (int j = 1; j <= i; j++) { //j번째 숫자
			if (j == 1 || j == i) {
				pt[i][j] = 1; //양끝숫자는 1
				//printf("%d ", pt[i][j]);
			}
			else {
			//왼쪽위 오른쪽위숫자합
			pt[i][j] = pt[i - 1][j - 1] + pt[i - 1][j]; 
			//printf("%d  ", pt[i][j]);
			}
		}
		//printf("\n");
	}
	int res = 0;
	for (int i = 1; i <= W; i++) {
		for (int j = 1; j <= i; j++) {
			res += pt[R + i-1][C + j -1];
			//printf("%d  ", pt[i+ C + R -2][j+ C -1]);
		}
		//printf("\n");
	}
	printf("%d", res);

	return 0;
}