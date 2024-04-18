#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
using std::vector; using std::queue; using std::pair;
int dxy[4][2] = { {-1, 0}, {0, -1}, {0, 1}, {1, 0} };

int main(void) {
	int x = 1, y = 1, map[3][3];

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			scanf("%d", &map[i][j]);

	for (int i = 0; i < 4; i++) {
		int xx = x + dxy[i][0];
		int yy = x + dxy[i][1];
		printf("%d\n", map[xx][yy]);

	}

	return 0;
}