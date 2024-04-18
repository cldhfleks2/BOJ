#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
using std::queue; using std::string; using std::vector; using std::sort;
int n;
queue<string> numbers;
string prime[6] = { "1", "2", "3", "5", "7", "9"};

bool isPrime(long num) { //�Ҽ����� �Ǻ��ϴ� �Լ�
	if (num < 2) return false;
	for (int i = 2; i <= sqrt(num); i++)
		if (num % i == 0) return false;
	return true;
}

void makeNum(int depth) {
	if (depth <= 0) return;
	if (depth == n) { //�ʱ갪
		for (int i = 1; i <= 4; i++) //2,3,5,7���� ���ڸ����ɼ�����
			numbers.push(prime[i]);
		makeNum(depth - 1);
		return;
	}
	queue<string> buff;
	int size = numbers.size();
	for (int i = 0; i < size; i++) {
		string prev = numbers.front();
		numbers.pop();
		for (int j = 0; j < 6; j++) {
			if (j == 1) //����2�� ���̸� �Ҽ����ƴ�
				continue; 
			string current = prev + prime[j];
			long num = stol(current);
			if (isPrime(num)) {
				buff.push(current);
				if (depth == 1)
					printf("%ld\n", num);
			}
		}
	}
	numbers = buff;
	
	makeNum(depth - 1);
}

void func() {
	makeNum(n);
	if(n == 1)
		for (int i = 0; i < 4; i++) {
			printf("%d\n", stoi(numbers.front()));
			numbers.pop();
		}
}

int main(void) {
	scanf("%d", &n);
	
	func();

	return 0;
}