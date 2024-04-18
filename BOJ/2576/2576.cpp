#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
int min=100, sum=0;


int main(void) {
	for (int i = 0, _; i < 7; i++) {
		scanf("%d", &_);
		if (_ % 2 != 0) {
			if (min > _) min = _;
			sum += _;
		}
	}
	if (sum == 0)
		printf("-1");
	else
		printf("%d\n%d", sum, min);


	return 0;
}