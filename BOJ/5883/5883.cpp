#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>

int* consumer;
std::vector<int> check;

int main(void) {
	int n;
	scanf("%d", &n);
	consumer = new int[n];
	for (int i = 0; i < n; i++) { //입력받는 부분
		scanf("%d", &consumer[i]);
	}

	//몇종류의 용량이 있는지 확인 하는 부분
	for (int i = 0; i < n; i++) {
		int num = consumer[i];
		bool find = false;
		for (int j = 0; j < check.size(); j++) {
			if (check[j] == num) { //기존에 추가했는가
				find = true;
				break;
			}
		}
		if (!find) //기존에 추가하지않았다면 check에 기록
			check.push_back(num);
	}
	if (check.size() == 1) {
		printf("%d", n);
		return 0;
	}

	int maxLength = 1; //최대로 연속되어 줄서있던 길이. 문제에서 구하고자하는 값
	for (int i = 0; i < check.size(); i++) {
		int del_cap = check[i]; //빼버릴 용량

		int preNum = -1;
		int length = 0;
		for (int j = 0; j < n; j++) {
			if (consumer[j] == del_cap) { //빼버릴 용량을 발견시
				if (j == n - 1) //맨 마지막줄이라면
					if (length != 0 && maxLength < length + 1)
						maxLength = length + 1; //이전갯수 고려하여 + 1
				continue;
			}
			if (preNum != consumer[j]) {
				preNum = consumer[j];
				if (length != 0 && maxLength < length + 1)
					maxLength = length + 1;
				length = 0;
			}
			else {
				length++;
			}
		}
		if (length > 0) {
			if (maxLength < length + 1)
				maxLength = length + 1;
			
		}

	}

	printf("%d", maxLength);

	return 0;
}