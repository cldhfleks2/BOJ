#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>

int main(int a, int b, int c) {
	scanf("%d%d%d", &a, &b, &c);

	int multi = a * b * c;

	char buff[11];

	sprintf(buff, "%d", multi);

	int res[10];
	memset(res, 0, 10*sizeof(int));
	for (int i = 0; i < 11; i++) {
		char temp = buff[i];
		if (temp == '\0')
			break;
		int num = temp - '0';

		res[num]++;
	}

	for (int i = 0; i < 10; i++)
		printf("%d\n", res[i]);
}