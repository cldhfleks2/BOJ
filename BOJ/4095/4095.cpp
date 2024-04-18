#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
int N = 0, M = 0;
int small = 0;
int** matrix; //N x M 행렬
int res = 0; //최대정사각형의 한변의길이

//for 문 중첩말고 dp로 해결하면된다. 수정하자
int dp(int step) { //정사각형이있는지 확인 없으면 0
	if (step == small + 1) return 0;
	//printf("=>step:%d 시작합니다\n", step);
	//step : 한변의길이. 
	//점(N, M)을 좌상단으로 시작하는
	//한변의길이가 step인 정사각형을 찾는다.
	for (int i = 0; i <= N - step; i++) {
		bool isSquare = false;
		bool n_side = true;
		bool m_side = true;
		if (isSquare) break;
		for (int j = 0; j <= M - step; j++) {
			bool skip = false;
			for(int k = i ; k <= i + step - 1 ; k++)
				for(int l = j ; l <= j + step - 1 ; l++)
					if (!matrix[k][l]) {
						skip = true;
						break;
					}
			if (!skip) {
				//printf("=>(%d:%d , %d)\n", step, i, j);
				res = step; //기록
				isSquare = true;
				break;
			}
		}
	}
	return dp(step + 1);
}

int main(void) {

	while (true) {
		scanf("%d%d", &N, &M);
		if (N == 0 && M == 0) break;
		if (N <= M) {
			small = N;
		}else{
			small = M;
		}
		res = 0;
		matrix = new int* [N];
		for (int i = 0; i < N; i++)
			matrix[i] = new int[M];

		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				scanf("%d", &matrix[i][j]);

		dp(2); //2부터 검색..
		printf("%d\n", res);
	}




	return 0;
}