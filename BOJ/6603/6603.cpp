#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
int S[13], K, lotto[6];

//bottom-up 방법
void makeLotto(int start, int size) { 
	if (size == 6) { 
		for (int i = 0; i < 6; i++)
			printf("%d ", lotto[i]);
		printf("\n");
		return;
	}

	for (int i = start; i < K; i++) {
		lotto[size] = S[i];
		makeLotto(i + 1, size + 1);
	}
}

int main(void) {
	while (1) {
		scanf("%d", &K);
		if (K == 0) break;
		for (int i = 0, temp; i < K; i++) { //입력을 받음
			scanf("%d", &temp);
			S[i] = temp;
		}

		makeLotto(0, 0);
		printf("\n");
	}

	return 0;
}