#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
int main(void) {
	int ham[3];
	int cola[2];
	scanf("%d%d%d%d%d", &ham[0], &ham[1], &ham[2], &cola[0], &cola[1]);
	int res1= 0x7fffffff, res2;
	res2 = cola[0] > cola[1] ? cola[1] : cola[0];
	for (int i = 0; i < 3; i++)
		if (res1 > ham[i])
			res1 = ham[i];
	printf("%d", res1 + res2 - 50);


	return 0;
}