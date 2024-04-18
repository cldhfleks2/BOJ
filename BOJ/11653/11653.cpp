#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

int main(void) {
	int N, i;
	scanf("%d", &N);

	for(i = 2 ; i <= N ;i++)
		while (N % i == 0) {  //나누어 떨어지면 소인수임
			N /= i;
			printf("%d\n", i);
		}
		
		

	return 0;
}