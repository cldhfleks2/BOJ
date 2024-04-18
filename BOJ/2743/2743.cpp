#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
char c[101];

int main(void) {
	scanf("%s", &c);
	int size = 0;
	for (; size < 101; size++) {
		if (c[size] == '\0')
			break;
	}
	printf("%d", size);

	return 0;
}