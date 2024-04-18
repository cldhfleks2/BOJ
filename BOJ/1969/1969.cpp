#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>

int N, M, ** dna;
void HammingDistance();
void input();

void input() {
	scanf("%d %d\n", &N, &M); //\n�� �Ծ���� �����۵�
	dna = new int*[N];
	//�Է¹޴� ��
	for (int i = 0; i < N; i++) {
		dna[i] = new int[M];
		char temp;

		for (int j = 0; j < M; j++) {
			dna[i][j] = -1;
			scanf("%c", &temp);
			switch (temp) { //A C G T�� ���� 0 1 2 3 ���ڷ� ����
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
		scanf("%c", &temp); //�ٹٲ޹��ڸ� �Ծ���� �����۵�
	}

	HammingDistance();
}

void HammingDistance() {
	int freqNucle[4] = { 0 }; //dna�� �պκк��� ��Ŭ����Ÿ�̵��� �󵵼��� ���� ���
	char *findDNA = new char[M];
	for (int i = 0; i < M; i++)
		findDNA[i] = '\0';
	int hammingDistanceSum = 0;
	
	for (int j = 0; j < M; j++) {
		for (int i = 0; i < N; i++) {
			freqNucle[dna[i][j]]++; //dna ����� �Ǿձ��ڵ���� ���� Ȯ��
		}
		
		int findNucle = -1; //�ִ�󵵼��� ��Ŭ����Ÿ�̵带(���ڷ�) ���
		int findNucleCnt = 0; //�ִ�󵵼��� ��Ŭ����Ÿ�̵��� �󵵼��� ���
		for (int k = 0; k < 4; k++) {
			if (findNucleCnt < freqNucle[k]) {
				findNucle = k; //������� ��Ŭ����Ÿ�̵����� ���
				findNucleCnt = freqNucle[k]; //�󸶳� �󵵼��� �������� ���
			}
		}
		
		hammingDistanceSum += N - findNucleCnt; //��¿� hammingDistance ���̸� ���
		switch (findNucle) { // ��¿� DNA�� ��Ŭ����Ÿ�̵带 ���
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

		for (int k = 0; k < 4; k++) //�ʱ�ȭ
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