#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
using namespace std;
//numList�� 0~ 100���� ������ �󵵼��� ��Ÿ��
vector<int> A;
int N, * B, numList[101] = {}; 
int* relocation_A, * compare_B;

void init() { //�ʱ⼳��
	relocation_A = new int[N];
	compare_B = new int[N];
	B = new int[N];
	for (int i = 0, temp; i < N; i++) {
		scanf("%d", &temp);
		A.push_back(temp);
	}
	for (int i = 0, temp; i < N; i++) {
		scanf("%d", &temp);
		B[i] = temp; //�ᱣ������ B
		compare_B[i] = temp; //�񱳿� B
	}
	for (int i = 0; i < N; i++) //�󵵼�ī��Ʈ
		numList[B[i]]++; //�ش������ �󵵼��� + 1
}

int find_min() { //A �迭�� �ּڰ��� ã�� ���Ҹ� ������ ����(pop)
	int min = 0x7fffffff;
	int min_index = 0;
	for (int i = 0; i < A.size(); i++) { //Aũ�⸸ŭ
		if (min > A[i]) {
			min = A[i]; //�ּڰ�����
			min_index = i;
		}
	}
	A.erase(A.begin() + min_index);  //�ش���Ҹ� ����
	return min;
}

void relocation() { //A�迭�� ���ġ�ϴ��Լ�
	//i : �������
	for (int i = 100; i >= 0; i--) { //��� �󵵼��� üũ
		while (numList[i] > 0) { //�󵵼�����..
			for (int j = 0; j < N; j++) { //��B�迭 Ž��
				//��B�迭�� ������ڸ� ã��
				if (compare_B[j] == i) { 
					int element = find_min(); //A�迭���� ���� �ּڰ��� ã��
					//��迭�� A�迭�� B�� ���� �ε����� ���� ����
					relocation_A[j] = element;
					numList[i]--; //������� �󵵼� ����
					compare_B[j] = -1; //�� B�迭 ������
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