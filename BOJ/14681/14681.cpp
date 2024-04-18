#define _CRT_SECURE_NO_WARNINGS 
#include <Windows.h>
#include <bits/stdc++.h>
int main(void) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
	int x, y;
	scanf("%d%d", &x, &y);
	if (x > 0 && y > 0)
		printf("1");
	else if (x < 0 && y > 0)
		printf("2");
	else if (x < 0 && y < 0)
		printf("3");
	else
		printf("4");

	return 0;
}