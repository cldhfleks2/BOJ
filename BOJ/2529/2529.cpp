#include <bits/stdc++.h>
using namespace std;

int endIndex = 0; 
int currentIndex = 0;
int *maxNum;
int *minNum;
int big = 9, small = 0; // ��밡���� ����ǥ�� 
bool* sign;

void maxFind() {
	int leftCnt = 0;
	for (int i = currentIndex; i < endIndex; i++) {
		leftCnt++; // ������ �ε������� ī��Ʈ
		if (sign[i]) { // > �� ã��
			

		}
		else { // ��ã��
			
		}
	}

}

void minFind() {

}


int main(void) {
	cin >> endIndex; endIndex++; //�ε�ȣ���� +1����
	sign = new bool[endIndex - 1]; //�ε�ȣ ������ŭ
	maxNum = new int[endIndex]; //�ε�ȣ����+1 ��ŭ �ᱣ���� �����ҹ迭
	minNum = new int[endIndex];
	for (int i = 0; i < endIndex - 1; i++) {
		char temp;
		cin >> temp;
		if (temp == '>') { //true
			sign[i] = true;
		}
		else {
			sign[i] = false;
		}
	}
	maxFind();
	minFind();

	cout << maxNum << endl << minNum;

	return 0;
}