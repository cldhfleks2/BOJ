#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
using namespace std;
//prime : 2���� num���� ��� ���� ���
//primeList : 2���� num������ �Ҽ� �� ���
deque<bool> prime; 
deque<int> primeList;

void findPrime(int num) {
	prime.push_back(false); //1, 2, 3, ... , num
	int cnt = num;
	while(cnt--)
		prime.push_back(true); //����Ҹ� true�� �ʱ�ȭ
	for (int i = 2; i * i <= num; i++) { //�Ҽ���ã��
		if (!prime[i]) continue;
		for (int j = i + i; j <= num; j += i) 
			//i�� ������ i�ǹ������ ���� �Ҽ����ƴ���check
			prime[j] = false;
	}
	for (int i = 2; i <= num; i++)
		if (prime[i]) primeList.push_back(i);
}

int find(int num) {
	int res = 0;
	for (int i = 0; i <= primeList.size(); i++) { //�Ҽ�������ŭ�ݺ�
		//i�ε����� ���۵Ǵ� �Ҽ�(2,3,5,7...)�� Ž��
		int j = i; //���� Ž�������ε��� (i, i+1, i+2...)
		int sum = 0;
		int primeCnt = primeList.size() - i; //�Ҽ�����Ʈ �ִ���̸�ŭ�ݺ�
		vector<int> temp;
		//i + (i+1) + (i+2)... �ؼ� ���ӼҼ������� �Ҽ����Ǵ���Ȯ��
		while (primeCnt--) { 
			sum += primeList[j]; //�Ҽ������� ���
			temp.push_back(primeList[j]); //������
			if (num == sum) { //���ӼҼ����� �Ҽ����Ǵ°��
				res++; //ã��+1
				sum = 0; //���ʱ�ȭ
				break;
			}
			else if (num < sum) { //�Ҽ��� �Ҽ����Ѿ.. ���������
				sum = 0; //���ʱ�ȭ
				break; //���� �� Ŀ���� ��
			}
			j++; //���� �ε��� Ž��
		}
		//����ο��� ���� i+1��°�� �����ε����� ã������
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