#include <bits/stdc++.h>
using namespace std;

int endIndex = 0; 
int currentIndex = 0;
int *maxNum;
int *minNum;
int big = 9, small = 0; // 사용가능한 숫자표기 
bool* sign;

void maxFind() {
	int leftCnt = 0;
	for (int i = currentIndex; i < endIndex; i++) {
		leftCnt++; // 지나온 인덱스갯수 카운트
		if (sign[i]) { // > 을 찾음
			

		}
		else { // 못찾음
			
		}
	}

}

void minFind() {

}


int main(void) {
	cin >> endIndex; endIndex++; //부등호갯수 +1저장
	sign = new bool[endIndex - 1]; //부등호 갯수만큼
	maxNum = new int[endIndex]; //부등호갯수+1 만큼 결괏값을 저장할배열
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