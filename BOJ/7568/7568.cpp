#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
using namespace std;

int main(void) {
	int N;
	scanf("%d", &N);
	vector<pair<int, int>> person;
	int test = N;

	while (test--) {
		int weight=0, tall=0;
		scanf("%d%d", &weight, &tall);
		person.push_back({ weight, tall });
	}

	for (int i = 0; i < N; i++) { //�����Ҹ� �˻�
		int res = N;
		for (int j = 0; j < N; j++) {
			if (i == j) continue;
			if (person[i].first > person[j].first &&
				person[i].second > person[j].second) {
				//i���� �������
				res--;
				continue;
			}
			if ((person[i].first - person[j].first) *
				(person[i].second - person[j].second) <= 0) {
				//�񱳺Ұ���(������쵵����)�Ѱ��
				res--;
			}
		}
		printf("%d ", res);
	}

	return 0;
}