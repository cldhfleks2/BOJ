#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
using namespace std;
int N;
deque<int> input, ropes;

int calculate() { // 정리된 N개의 입력값중 최솟값을 찾음
	int cnt = N;
	sort(input.begin(), input.begin() + cnt); //입력값을 정렬
	//역순으로 진행
	//N, {N, N-1}, {N, N-1, N-2...}, {N, N-1, ..., 1}순에서
	//가장 낮은인덱스의 값을 a 라하면
	//선택한것들의 평균이 이 a 보다 커지면
	//탐색을 멈춤
	int sum = 0;
	int index = 0;
	for (int i = N - 1; i > 0; i--) { //역방향탐색
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
	while(cnt--){ //입력값을 받음
		scanf("%d", &temp);
		input.push_back(temp);
	}



	return 0;
}