#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
using namespace std;
//numList는 0~ 100까지 숫자의 빈도수를 나타냄
vector<int> A;
int N, * B, numList[101] = {}; 
int* relocation_A, * compare_B;

void init() { //초기설정
	relocation_A = new int[N];
	compare_B = new int[N];
	B = new int[N];
	for (int i = 0, temp; i < N; i++) {
		scanf("%d", &temp);
		A.push_back(temp);
	}
	for (int i = 0, temp; i < N; i++) {
		scanf("%d", &temp);
		B[i] = temp; //결괏값계산용 B
		compare_B[i] = temp; //비교용 B
	}
	for (int i = 0; i < N; i++) //빈도수카운트
		numList[B[i]]++; //해당숫자의 빈도수를 + 1
}

int find_min() { //A 배열중 최솟값을 찾아 원소를 삭제후 리턴(pop)
	int min = 0x7fffffff;
	int min_index = 0;
	for (int i = 0; i < A.size(); i++) { //A크기만큼
		if (min > A[i]) {
			min = A[i]; //최솟값갱신
			min_index = i;
		}
	}
	A.erase(A.begin() + min_index);  //해당원소를 지움
	return min;
}

void relocation() { //A배열을 재배치하는함수
	//i : 현재숫자
	for (int i = 100; i >= 0; i--) { //모든 빈도수를 체크
		while (numList[i] > 0) { //빈도수전부..
			for (int j = 0; j < N; j++) { //비교B배열 탐색
				//비교B배열중 현재숫자를 찾음
				if (compare_B[j] == i) { 
					int element = find_min(); //A배열에서 현재 최솟값을 찾음
					//재배열된 A배열에 B와 같은 인덱스에 값을 넣음
					relocation_A[j] = element;
					numList[i]--; //현재숫자 빈도수 감소
					compare_B[j] = -1; //비교 B배열 값삭제
				}
			}
		}
	}
}

void printAll() {
	int s = 0;
	for (int i = 0; i < N; i++) 
		s += relocation_A[i] * B[i];
	printf("%d", s);
}

int main(void) {
	scanf("%d", &N);
	init();
	relocation();
	printAll();

	return 0;
}