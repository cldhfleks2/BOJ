#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
bool numbers[10001] = {}; //�����Ҹ� false�� �ʱ�ȭ
void selfNumber(int num) {
	int result = num;
	std::string num_str = std::to_string(num); //������ string����
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
