#include <iostream>
using namespace std;

int *t, *p, n;

//int solve() {
//	int maxPRICE = 0;
//	for (int i = 1; i <= n; i++) {
//		int totalDAYS = t[i]; // i일 상담을 무조건 시도.
//		int totalPRICE = p[i];
//		if (totalDAYS > n - i + 1) //i일 상담불가 : 현재 남은날수보다 t[i]가 큰경우 중단
//			continue;
//		int j = t[i] + i; //다음 날짜지정
//		int max = 0;
//		while (true) {
//			if (j > n) break; //다음 날짜가 전체범위를 벗어난경우 중단
//			int currentDAYS = t[j];
//			int currentPrice = p[j];
//			if (currentDAYS <= n - j + 1) { //다음 날짜가 상담가능하다면
//				totalPRICE += currentPrice; //임금 추가
//				
//				j = t[j] + j; //다음날짜 지정
//				continue; //아래의 다음날짜지정코드를 건너뜀
//			}
//			j++; //다음날짜는 하루뒤
//		}
//		if (maxPRICE < totalPRICE) maxPRICE = totalPRICE; //최대금액
//	}
//
//	return maxPRICE;
//}

int dp(int number) {
	int currentWork = t[number];
	int currentDay = number;
	int maxPay = 0;
	for (int i = currentDay; i <= n; i++) { //다음날짜(number - currentDay)부터 가능한 n일까지만 반복
		if (n - (i + currentWork) < 0) return 0; //현재 날짜의 상담이 불가능한경우
		int pay = dp(i);
		if (maxPay < pay) {
			maxPay = pay;
		}
	}
	return maxPay;
}

int solve() {
	int maxPay = 0;
	for (int i = 1; i <= n; i++) {
		int temp = dp(i);
		cout << " = " << temp;
		if (maxPay < temp) {
			maxPay = temp;
			cout << " <= 범인";
		}
		cout << endl;
	}

	return maxPay;
}


int main() {	
	cin >> n;
	t = new int[n];
	p = new int[n];
	for (int i = 1; i <= n; i++) { //입력
		int temp, temp2;
		cin >> temp >> temp2;
		t[i] = temp;
		p[i] = temp2;
	}
	cout << solve();

	return 0;
}
