#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>


int main(void) {
	bool cows[11]; //1~10
	int result[11] = {0, };
	bool checks[11];
	memset(checks, false, sizeof(cows));

	int t;
	scanf("%d", &t);
	while (t--) {
		int c, l; //소번호, 위치
		scanf("%d %d", &c, &l);
		if (!checks[c]) { //처음 관찰한경우 시작지점설정
			checks[c] = true;
			cows[c] = (bool)l;
		}
		if (cows[c] != (bool)l) {
			result[c]++;
			cows[c] = !cows[c];
		}
	}
	int cnt = 0;
	for (int i = 1; i <= 10; i++)
		cnt += result[i];
	printf("%d", cnt);
	return 0;
}
