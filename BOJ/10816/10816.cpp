#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
std::vector<int> list;
int main(int n, int m, int num) {
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &num);
		list.push_back(num);
	}
	//카드들을 숫자카드로정렬
	std::sort(list.begin(), list.end()); 

	scanf("%d", &m);
	while (m--) {
		scanf("%d", &num);
		auto lower = std::lower_bound(list.begin(), list.end(), num);
		auto upper = std::upper_bound(list.begin(), list.end(), num);
		printf("%d ", upper - lower);
	}

	return 0;
}