#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
char a[50], b[50];
int sum;
void init();
void makeRoma(int sum);
int calculate(char* c);


void init() {
	scanf("%s", &a);
	scanf("%s", &b);
}

void func() {
	sum = calculate(a) + calculate(b);

	printf("%d\n", sum);
	makeRoma(sum);
}

//아라비아숫자를 로마숫자로
void makeRoma(int sum) {
	char c[50];
	int cur = 0;
	while (sum != 0) {
		if (sum >= 1000) {
			sum -= 1000;
			c[cur] = 'M';
		}
		else if (sum >= 900) {
			sum -= 900;
			c[cur] = 'C';
			c[cur + 1] = 'M';
			cur++;
		}
		else if (sum >= 800) {
			sum -= 800;
			c[cur] = 'D';
			c[cur + 1] = 'C';
			c[cur + 2] = 'C';
			c[cur + 3] = 'C';
			cur++; cur++; cur++;
		}
		else if (sum >= 700) {
			sum -= 700;
			c[cur] = 'D';
			c[cur + 1] = 'C';
			c[cur + 2] = 'C';
			cur++; cur++;
		}
		else if (sum >= 600) {
			sum -= 600;
			c[cur] = 'D';
			c[cur + 1] = 'C';
			cur++;
		}
		else if (sum >= 500) {
			sum -= 500;
			c[cur] = 'D';
		}
		else if (sum >= 400) {
			sum -= 400;
			c[cur] = 'C';
			c[cur + 1] = 'D';
			cur++;
		}
		else if (sum >= 300) {
			sum -= 300;
			c[cur] = 'C';
			c[cur + 1] = 'C';
			c[cur + 2] = 'C';
			cur++; cur++;
		}
		else if (sum >= 200) {
			sum -= 200;
			c[cur] = 'C';
			c[cur + 1] = 'C';
			cur++;
		}
		else if (sum >= 100) {
			sum -= 100;
			c[cur] = 'C';
		}
		else if (sum >= 90) {
			sum -= 90;
			c[cur] = 'X';
			c[cur + 1] = 'C';
			cur++;
		}
		else if (sum >= 80) {
			sum -= 80;
			c[cur] = 'L';
			c[cur + 1] = 'X';
			c[cur + 2] = 'X';
			c[cur + 3] = 'X';
			cur++; cur++; cur++;
		}
		else if (sum >= 70) {
			sum -= 70;
			c[cur] = 'L';
			c[cur + 1] = 'X';
			c[cur + 2] = 'X';
			cur++; cur++;
		}
		else if (sum >= 60) {
			sum -= 60;
			c[cur] = 'L';
			c[cur + 1] = 'X';
			cur++;
		}
		else if (sum >= 50) {
			sum -= 50;
			c[cur] = 'L';
		}
		else if (sum >= 40) {
			sum -= 40;
			c[cur] = 'X';
			c[cur + 1] = 'L';
			cur++;
		}
		else if (sum >= 30) {
			sum -= 30;
			c[cur] = 'X';
			c[cur + 1] = 'X';
			c[cur + 2] = 'X';
			cur++; cur++;
		}
		else if (sum >= 20) {
			sum -= 20;
			c[cur] = 'X';
			c[cur + 1] = 'X';
			cur++;
		}
		else if (sum >= 10) {
			sum -= 10;
			c[cur] = 'X';
		}
		else if (sum >= 9) {
			sum -= 9;
			c[cur] = 'I';
			c[cur + 1] = 'X';
			cur++;
		}
		else if (sum >= 8) {
			sum -= 8;
			c[cur] = 'V';
			c[cur + 1] = 'I';
			c[cur + 2] = 'I';
			c[cur + 3] = 'I';
			cur++; cur++; cur++;
		}
		else if (sum >= 7) {
			sum -= 7;
			c[cur] = 'V';
			c[cur + 1] = 'I';
			c[cur + 2] = 'I';
			cur++; cur++;
		}
		else if (sum >= 6) {
			sum -= 6;
			c[cur] = 'V';
			c[cur + 1] = 'I';
			cur++;
		}
		else if (sum >= 5) {
			sum -= 5;
			c[cur] = 'V';
		}
		else if (sum >= 4) {
			sum -= 4;
			c[cur] = 'I';
			c[cur + 1] = 'V';
			cur++;
		}
		else if (sum >= 3) {
			sum -= 3;
			c[cur] = 'I';
			c[cur + 1] = 'I';
			c[cur + 2] = 'I';
			cur++; cur++;
		}
		else if (sum >= 2) {
			sum -= 2;
			c[cur] = 'I';
			c[cur + 1] = 'I';
			cur++;
		}
		else if (sum >= 1) {
			sum -= 1;
			c[cur] = 'I';
		}
		cur++;
	}

	for (int i = 0; i < cur; i++)
		printf("%c", c[i]);
}

//로마숫자를 아라비아숫자로
int calculate(char* c) {
	int res = 0;
	int cur = 0;
	while (1) {
		if (c[cur] == '\0') break;
		char _ = c[cur];
		if (_ == 'M')
			res += 1000;
		else if (_ == 'D')
			res += 500;
		else if (_ == 'C') {
			if (c[cur + 1] == 'M') {
				res += 900;
				cur++;
			}
			else if (c[cur + 1] == 'D') {
				res += 400;
				cur++;
			}
			else
				res += 100;
		}
		else if (_ == 'L')
			res += 50;
		else if (_ == 'X'){
			if (c[cur + 1] == 'C') {
				res += 90;
				cur++;
			}
			else if (c[cur + 1] == 'L') {
				res += 40;
				cur++;
			}
			else
				res += 10;
		}
		else if (_ == 'V')
			res += 5;
		else if (_ == 'I') {
			if (c[cur + 1] == 'X') {
				res += 9;
				cur++;
			}
			else if (c[cur + 1] == 'V') {
				res += 4;
				cur++;
			}
			else 
				res += 1;
		}

		cur++;
	}

	return res;
}

int main(void) {
	init();
	func();

	return 0;
}