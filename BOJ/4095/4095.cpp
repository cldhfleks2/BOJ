#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
int N = 0, M = 0;
int small = 0;
int** matrix; //N x M ���
int res = 0; //�ִ����簢���� �Ѻ��Ǳ���

//for �� ��ø���� dp�� �ذ��ϸ�ȴ�. ��������
int dp(int step) { //���簢�����ִ��� Ȯ�� ������ 0
	if (step == small + 1) return 0;
	//printf("=>step:%d �����մϴ�\n", step);
	//step : �Ѻ��Ǳ���. 
	//��(N, M)�� �»������ �����ϴ�
	//�Ѻ��Ǳ��̰� step�� ���簢���� ã�´�.
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
				res = step; //���
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

		dp(2); //2���� �˻�..
		printf("%d\n", res);
	}




	return 0;
}