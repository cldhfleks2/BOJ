#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>

int main(int n, int m) {
	scanf("%d", &n);
	long long* a = new long long[n];
	long long max = 0;
	for (int i = 0; i < n; i++){
		scanf("%lld", &a[i]);
		if (max < a[i]) //ÃÖ´ñ°ªÀ» Ã£À½
			max = a[i];
	}
	std::sort(a, a + n);

	scanf("%d", &m);
	while (m--) {
		long long num;
		scanf("%lld", &num);
		bool find = false;
		int start = 0, mid = n / 2, end = n - 1;
		//ÀÌºÐÅ½»ö
		while (end >= start) {
			//Áß¾Ó°ªÀÌ ÀÏÄ¡ÇÏ¸é Å½»ö¼º°ø
			if (a[mid] == num) {
				printf("1\n");
				find = true;
				break;
			}
			//Áß¾Ó°ª ÀÛÀ¸¸é Å½»ö¹æÇâÀ» ÁÂÃøÀ¸·Î
			else if (a[mid] > num)
				end = mid - 1;
			//Áß¾Ó°ªº¸´Ù Å©¸é Å½»ö¹æÇâÀ» ¿ìÃøÀ¸·Î
			else if (a[mid] < num)
				start = mid + 1;

			mid = (start + end) / 2;
		}
		if(!find)
			printf("0\n");
	}

	return 0;
}