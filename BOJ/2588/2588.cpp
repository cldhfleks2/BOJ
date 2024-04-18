#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

int main(void) {
	int first;
	char second[4];

	scanf("%d%s", &first, &second);
	int third = first * (second[2] - '0');
	int fourth = first * (second[1] - '0');
	int fifth = first * (second[0] - '0');
	printf("%d\n%d\n%d\n%d", third, fourth, fifth, third + fourth*10 + fifth*100);


	return 0;
}