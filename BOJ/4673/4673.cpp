#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
bool numbers[10001] = {}; //모든원소를 false로 초기화
void selfNumber(int num) {
	int result = num;
	std::string num_str = std::to_string(num); //정수를 string으로
	for (int i = 0; i < num_str.size(); i++)
		result += num_str.at(i) - '0';
	
	if (result <= 10000) numbers[result] = true;
}

void printAll() {
	for (int i = 1; i <= 10000; i++)
		if (!numbers[i])
			printf("%d\n", i);
}

int main(void) {
	for (int i = 1; i <= 10000 ; i++)
		selfNumber(i);
	printAll();
}
