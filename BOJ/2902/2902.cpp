#include <bits/stdc++.h>
using namespace std;

int main(void) {
	char input[100];
	scanf("%s", input, sizeof(input));

	string res = "";

	int checkPoint = 0;
	for (int i = 0; i < 100; i++) {
		if (input[i] == '-') {
			res += input[checkPoint];
			checkPoint = i + 1;
		}
	}
	res += input[checkPoint];
	printf("%s", res.c_str());
}