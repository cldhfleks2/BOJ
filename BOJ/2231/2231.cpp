#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>


int main(int n) {
	scanf("%d", &n);
	int temp = n;
	int q = 0; //0�ǰ��� 10*q
	while (temp/10 > 0) {
		temp /= 10;
		q++;
	}

	char* c = new char[q+1];

	int res = 0;
	for (int i = 1; i < n; i++) {
		sprintf(c, "%d", i); //i�� char�迭�� ��ȯ
		int sum = i;
		for (int j = 0; j <= q; j++) {
			if (c[j] == '\0')
				break;
			sum += c[j] - '0';
		}
		if (sum == n) {
			res = i;
			break;
		}
	}

	printf("%d", res);

	return 0;
}