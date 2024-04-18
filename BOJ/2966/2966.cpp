#define _CRT_SECURE_NO_WARNINGS //scanf오류 없앰
#include <bits/stdc++.h>
using namespace std;

int main(void) {
	char Adrian[] = { 'A', 'B' ,'C' }, Bruno[] = { 'B', 'A', 'B', 'C' }, Goran[] = { 'C', 'C', 'A', 'A', 'B', 'B' };
	int number; 
	scanf("%d", &number);
	char *problem;
	problem = new char[number];
	int AdrianIndex=0, BrunoIndex=0, GoranIndex=0; // 각각인덱스
	int a, b, c;
	scanf("%s", problem); //배열을 쓸때는 &쓰지않음
	for (int i = 0; i < number; i++){ //모든 문제를 확인
		char temp = problem[i];

		if (problem[i] == Adrian[i % 3]) {
			AdrianIndex++;
		}
		if (problem[i] == Bruno[i % 4]) {
			BrunoIndex++;
		}
		if (problem[i] == Goran[i % 6]) {
			GoranIndex++;
		}
	}
	int max = 0;
	if (max < AdrianIndex) max = AdrianIndex;
	if (max < BrunoIndex) max = BrunoIndex;
	if (max < GoranIndex) max = GoranIndex;
	printf("%d\n", max);
	if (max == AdrianIndex) printf("Adrian\n");
	if (max == BrunoIndex) printf("Bruno\n");
	if (max == GoranIndex) printf("Goran\n");

}


