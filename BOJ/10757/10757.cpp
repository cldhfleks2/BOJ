#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
char s[10100], a[10001], b[10001];
std::string res;
int up = 0, size_a = 0, size_b = 0, cur_a, cur_b;

int main(void) {
	scanf("%s", &a);
	scanf("%s", &b);
	while (a[size_a] != '\0') size_a++;
	while (b[size_b] != '\0') size_b++;
	cur_a = size_a - 1;
	cur_b = size_b - 1;
	while (cur_a >= 0 || cur_b >= 0) {
		int num_a = 0, num_b = 0;
		if (cur_a >= 0)
			num_a = a[cur_a] - '0';
		if (cur_b >= 0)
			num_b = b[cur_b] - '0';

		res += (char)((num_a + num_b + up) % 10 + 48);
		if (num_a + num_b + up > 9) //다음 올림수계산
			up = 1;
		else
			up = 0;
		cur_a--; cur_b--;
	}

	if (up == 1)
		res += '1';

	std::reverse(res.begin(), res.end());

	int cur = 0;
	while (res[cur] != '\0') {
		printf("%c", res[cur]);
		cur++;
	}

	return 0;
}