#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
bool chess[8][8];
int res = 0;

int main(void) {
	for (int i = 0; i < 8; i++) {
		char _[9];
		scanf("%s", &_);
		for (int j = 0; j < 8; j++) {
			if (_[j] == '.')
				chess[i][j] = false;
			else if (_[j] = 'F')
				chess[i][j] = true;
		}
	}

	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			if ((i + j) % 2 == 0 && chess[i][j])
				res++;

	printf("%d", res);

	return 0;
}