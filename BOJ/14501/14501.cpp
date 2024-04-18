#include <iostream>
using namespace std;

int *t, *p, n;

//int solve() {
//	int maxPRICE = 0;
//	for (int i = 1; i <= n; i++) {
//		int totalDAYS = t[i]; // i�� ����� ������ �õ�.
//		int totalPRICE = p[i];
//		if (totalDAYS > n - i + 1) //i�� ���Ұ� : ���� ������������ t[i]�� ū��� �ߴ�
//			continue;
//		int j = t[i] + i; //���� ��¥����
//		int max = 0;
//		while (true) {
//			if (j > n) break; //���� ��¥�� ��ü������ ������ �ߴ�
//			int currentDAYS = t[j];
//			int currentPrice = p[j];
//			if (currentDAYS <= n - j + 1) { //���� ��¥�� ��㰡���ϴٸ�
//				totalPRICE += currentPrice; //�ӱ� �߰�
//				
//				j = t[j] + j; //������¥ ����
//				continue; //�Ʒ��� ������¥�����ڵ带 �ǳʶ�
//			}
//			j++; //������¥�� �Ϸ��
//		}
//		if (maxPRICE < totalPRICE) maxPRICE = totalPRICE; //�ִ�ݾ�
//	}
//
//	return maxPRICE;
//}

int dp(int number) {
	int currentWork = t[number];
	int currentDay = number;
	int maxPay = 0;
	for (int i = currentDay; i <= n; i++) { //������¥(number - currentDay)���� ������ n�ϱ����� �ݺ�
		if (n - (i + currentWork) < 0) return 0; //���� ��¥�� ����� �Ұ����Ѱ��
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
			cout << " <= ����";
		}
		cout << endl;
	}

	return maxPay;
}


int main() {	
	cin >> n;
	t = new int[n];
	p = new int[n];
	for (int i = 1; i <= n; i++) { //�Է�
		int temp, temp2;
		cin >> temp >> temp2;
		t[i] = temp;
		p[i] = temp2;
	}
	cout << solve();

	return 0;
}
