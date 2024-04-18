#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
using namespace std;

int main(void) {
	int n;
	scanf("%d", &n);
	int check[3] = { false };

	while (n--) {
		int a, b;
		scanf("%d %d", &a, &b);
		if (a > b) { //a < b·Î ¸ÂÃçÁÜ
			int temp = a;
			a = b;
			b = temp;
		}
		if (a == 1 && b == 3) {
			check[0] = true;
		}
		else if (a == 1 && b == 4) {
			check[1] = true;
		}
		else if (a == 3 && b == 4) {
			check[2] = true;
		}
		else {
			printf("Woof-meow-tweet-squeek");
			return 0;
		}
	}

	if (check[0] && check[1] && check[2]) {
		printf("Wa-pa-pa-pa-pa-pa-pow!");
	}
	else {
		printf("Woof-meow-tweet-squeek");
	}
	return 0;
}