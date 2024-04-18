#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>

int main(void) {
	int T, min=0x7fffffff, max = 0;

	scanf("%d", &T);
	if (T == 1) {
		int temp=0;
		scanf("%d", &temp);
		printf("%d", temp * temp);
	}else{
		while (T--) {
			int temp;
			scanf("%d", &temp);
			if (min > temp)
				min = temp;
			if (max < temp)
				max = temp;
		}
		printf("%d", min * max);
	}
	return 0;
}