#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
using namespace std;
//prime : 2부터 num까지 모든 숫자 기록
//primeList : 2부터 num까지의 소수 만 기록
deque<bool> prime; 
deque<int> primeList;

void findPrime(int num) {
	prime.push_back(false); //1, 2, 3, ... , num
	int cnt = num;
	while(cnt--)
		prime.push_back(true); //모든요소를 true로 초기화
	for (int i = 2; i * i <= num; i++) { //소수를찾음
		if (!prime[i]) continue;
		for (int j = i + i; j <= num; j += i) 
			//i를 제외한 i의배수들을 전부 소수가아님을check
			prime[j] = false;
	}
	for (int i = 2; i <= num; i++)
		if (prime[i]) primeList.push_back(i);
}

int find(int num) {
	int res = 0;
	for (int i = 0; i <= primeList.size(); i++) { //소수갯수만큼반복
		//i인덱스로 시작되는 소수(2,3,5,7...)를 탐색
		int j = i; //현재 탐색중인인덱스 (i, i+1, i+2...)
		int sum = 0;
		int primeCnt = primeList.size() - i; //소수리스트 최대길이만큼반복
		vector<int> temp;
		//i + (i+1) + (i+2)... 해서 연속소수의합이 소수가되는지확인
		while (primeCnt--) { 
			sum += primeList[j]; //소수의합을 기록
			temp.push_back(primeList[j]); //디버깅용
			if (num == sum) { //연속소수합이 소수가되는경우
				res++; //찾음+1
				sum = 0; //합초기화
				break;
			}
			else if (num < sum) { //소수합 소수를넘어선.. 오류난경우
				sum = 0; //합초기화
				break; //합이 더 커지면 끝
			}
			j++; //다음 인덱스 탐색
		}
		//여기로오면 다음 i+1번째를 시작인덱스로 찾으러감
	}
	return res;
}

int main(void) {
	int N;
	scanf("%d", &N);

	findPrime(N);
	printf("%d", find(N));

	return 0;
}