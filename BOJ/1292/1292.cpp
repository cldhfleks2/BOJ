#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>


int main(void) {
	int A, B;
	scanf("%d%d", &A, &B);

	int k = 1;
	std::vector<int> seq;
	while (seq.size() < 1000) { //원소갯수가 1000미만일때만
		for (int i = 0; i < k; i++) //정수 k를 k개만큼 넣는다.
			seq.push_back(k); //뒤로넣어야 front부터 오름차순정렬됨
		k += 1;
	}
	int sum = 0;
	for (int i = A-1; i <= B-1; i++) 
		sum += seq[i];
	printf("%d", sum);

	return 0;
}