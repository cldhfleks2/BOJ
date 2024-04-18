#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>

int main(int num) {
	int n = 5, sum = 0;
	while (n--) {
		scanf("%d", &num);
		sum += num * num;
	}
	printf("%d", sum % 10);
}