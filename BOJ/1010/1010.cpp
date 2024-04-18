#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
using namespace std;

int main(void) {
	int T=0, N=0, M=0;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &N, &M); //mCm  조합수랑 같음
		if (M == N) { //N == M이면 예외
			printf("1\n");
			continue;
		}
		if (N == 0 || M == 0) { //M,N 0이면  다리못놓음
			printf("0\n");
			continue;
		}
		
		long res = 1;
		for (int i = 0; i < N; i++) {
			res *= M - i;
			res /= i + 1;
		}
		printf("%ld\n", res);
	}

	return 0;
}
