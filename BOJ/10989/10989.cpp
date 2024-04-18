#define _CRT_SECURE_NO_WARNINGS //scanf오류 없앰
#include <bits/stdc++.h>
using namespace std;


int main(void) {
	int n, temp;
	int arr[10001] = {0}; //초기화를 해줘야 정상적으로출력
	scanf("%d", &n);
	while (n--) {
		scanf("%d", &temp);
		arr[temp] += 1;
	}
	for (int i = 1; i <= 10000; i++) {
		while (arr[i] > 0) {
			printf("%d\n", i);
			arr[i] -= 1;
		}
	}
}
