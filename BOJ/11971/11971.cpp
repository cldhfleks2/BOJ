#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
int n, m;
int road_limit[101]; //
int road_run[101]; //

void init() {
	int j1 = 1, j2 = 1;
	scanf("%d %d", &n, &m);
	for (int i = 0, temp1, temp2; i < n; i++) {
		scanf("%d %d", &temp1, &temp2);
		for (int j = j1; j <= j1 + temp1; j++)
			road_limit[j] = temp2;
		j1 += temp1;
	}

	for (int i = 0, temp1, temp2; i < m; i++) {
		scanf("%d %d", &temp1, &temp2);
		for (int j = j2; j <= j2 + temp1; j++)
			road_run[j] = temp2;
		j2 += temp1;
	}
}

void drive() {
	int max = 0;
	for (int i = 0, temp; i <= 100; i++) {
		temp = road_run[i] - road_limit[i];
		//과속 + 최댓값갱신하는경우
		if (max < temp)
			max = temp;
	}

	printf("%d", max);
}

int main(void) {
	init();
	drive();
}