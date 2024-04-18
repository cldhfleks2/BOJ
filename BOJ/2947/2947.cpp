#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
int wood[5];

void init() {
	for (int i = 0; i < 5; i++)
		scanf("%d", &wood[i]);
}

void logic() {
	while (true) {
		if (wood[0] == 1 &&
			wood[1] == 2 &&
			wood[2] == 3 &&
			wood[3] == 4 &&
			wood[4] == 5)
			break;
		for (int i = 0, temp; i < 4; i++) {
			if (wood[i] > wood[i + 1]) {
				temp = wood[i];
				wood[i] = wood[i + 1];
				wood[i + 1] = temp;
				printf("%d %d %d %d %d\n", wood[0],
					wood[1], wood[2], wood[3], wood[4]);
			}
		}
	}
}

int main(void) {
	init();
	logic();

	return 0;
}