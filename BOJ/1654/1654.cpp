#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
using std::sort;
int k, n, * cable;

void func() {
	//전선의길이이자 이분탐색의범위
	long long start=1, end=cable[k-1], mid=-1, res=0;
	//이분탐색
	while (start <= end) {
		mid = (start + end) / 2;
		long long cnt = 0;
		for (int i = 0; i < k; i++) //모든 전선을 mid길이로
			cnt += cable[i] / mid;


		if (cnt >= n) { //길이를 늘림
			start = mid + 1;
			if (res < mid) res = mid;
		}
		else {
			end = mid - 1;
		}

		
	}

	printf("%d", res);
}

int main(void) {
	scanf("%d%d", &k, &n);
	cable = new int[k];
	//입력
	for (int i = 0; i < k; i++) scanf("%d", &cable[i]);

	//정렬
	sort(cable, cable + k); 

	func();

	return 0;
}