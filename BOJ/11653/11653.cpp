#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

int main(void) {
	int N, i;
	scanf("%d", &N);

	for(i = 2 ; i <= N ;i++)
		while (N % i == 0) {  //������ �������� ���μ���
			N /= i;
			printf("%d\n", i);
		}
		
		

	return 0;
}