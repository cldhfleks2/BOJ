#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
using namespace std;
int N;
deque<int> input, ropes;

int calculate() { // ������ N���� �Է°��� �ּڰ��� ã��
	int cnt = N;
	sort(input.begin(), input.begin() + cnt); //�Է°��� ����
	//�������� ����
	//N, {N, N-1}, {N, N-1, N-2...}, {N, N-1, ..., 1}������
	//���� �����ε����� ���� a ���ϸ�
	//�����Ѱ͵��� ����� �� a ���� Ŀ����
	//Ž���� ����
	int sum = 0;
	int index = 0;
	for (int i = N - 1; i > 0; i--) { //������Ž��
		index = i;
		sum += input[i];
		double average = (double)sum/ (double)i;
		if (average > input[N - 1])
			break;
	}



}

int main(int cnt, int temp) {
	scanf("%d", &N);
	cnt = N;
	while(cnt--){ //�Է°��� ����
		scanf("%d", &temp);
		input.push_back(temp);
	}



	return 0;
}