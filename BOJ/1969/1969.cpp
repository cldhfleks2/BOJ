#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>

int N, M, ** dna;
void HammingDistance();
void input();

void input() {
	scanf("%d %d\n", &N, &M); //\n을 먹어줘야 정상작동
	dna = new int*[N];
	//입력받는 곳
	for (int i = 0; i < N; i++) {
		dna[i] = new int[M];
		char temp;

		for (int j = 0; j < M; j++) {
			dna[i][j] = -1;
			scanf("%c", &temp);
			switch (temp) { //A C G T를 각각 0 1 2 3 숫자로 저장
			case 'A': 
				dna[i][j] = 0;
				break;
			case 'C': 
				dna[i][j] = 1;
				break;
			case 'G': 
				dna[i][j] = 2;
				break;
			case 'T': 
				dna[i][j] = 3;
				break;
			}
		}
		scanf("%c", &temp); //줄바꿈문자를 먹어줘야 정상작동
	}

	HammingDistance();
}

void HammingDistance() {
	int freqNucle[4] = { 0 }; //dna의 앞부분부터 뉴클레오타이드의 빈도수를 각각 기록
	char *findDNA = new char[M];
	for (int i = 0; i < M; i++)
		findDNA[i] = '\0';
	int hammingDistanceSum = 0;
	
	for (int j = 0; j < M; j++) {
		for (int i = 0; i < N; i++) {
			freqNucle[dna[i][j]]++; //dna 목록의 맨앞글자들부터 전부 확인
		}
		
		int findNucle = -1; //최대빈도수의 뉴클레오타이드를(숫자로) 기록
		int findNucleCnt = 0; //최대빈도수의 뉴클레오타이드의 빈도수를 기록
		for (int k = 0; k < 4; k++) {
			if (findNucleCnt < freqNucle[k]) {
				findNucle = k; //어떤종류의 뉴클레오타이드인지 기록
				findNucleCnt = freqNucle[k]; //얼마나 빈도수를 가지는지 기록
			}
		}
		
		hammingDistanceSum += N - findNucleCnt; //출력용 hammingDistance 차이를 기록
		switch (findNucle) { // 출력용 DNA에 뉴클레오타이드를 기록
		case 0: 
			findDNA[j] = 'A';
			break;
		case 1: 
			findDNA[j] = 'C';
			break;
		case 2: 
			findDNA[j] = 'G';
			break;
		case 3: 
			findDNA[j] = 'T';
			break;
		}

		for (int k = 0; k < 4; k++) //초기화
			freqNucle[k] = 0;
	}

	for (int i = 0; i < M; i++) {
		if (findDNA[i] == '\0')
			break;
		printf("%c", findDNA[i]);
	}
	printf("\n%d", hammingDistanceSum);
}

int main(void) {
	input();

	return 0;
}