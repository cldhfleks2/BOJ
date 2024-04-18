#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string>

int main(void) {
	char S[1001];
	int i;
	scanf("%s%c%d", S, &S[1000], &i);
	
	printf("%c", S[i-1]);


	return 0;
}