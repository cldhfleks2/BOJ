#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>

int main(int n, int num) {
	scanf("%d", &n);
	double *score = new double[n];
	double max = 0;;
	for (int i = 0; i < n; i++) {
		scanf("%d", &num);
		if (max < num)
			max = num;
		score[i] = num;
	}

	double sum = 0;
	for (int i = 0; i < n; i++) {
		sum += (score[i] / max) * 100.0;
	}

	printf("%lf", sum / n);


	return 0;
}