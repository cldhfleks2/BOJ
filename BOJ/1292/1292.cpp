#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>


int main(void) {
	int A, B;
	scanf("%d%d", &A, &B);

	int k = 1;
	std::vector<int> seq;
	while (seq.size() < 1000) { //���Ұ����� 1000�̸��϶���
		for (int i = 0; i < k; i++) //���� k�� k����ŭ �ִ´�.
			seq.push_back(k); //�ڷγ־�� front���� �����������ĵ�
		k += 1;
	}
	int sum = 0;
	for (int i = A-1; i <= B-1; i++) 
		sum += seq[i];
	printf("%d", sum);

	return 0;
}