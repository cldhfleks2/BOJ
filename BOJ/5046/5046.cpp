#include <iostream>
using namespace std;

int person, money;

int main() {
	int hotelnum, hotelweeknum;
	cin >> person >> money >> hotelnum >> hotelweeknum;
	int cheapPay = 0x7fffffff;
	for (int i = 0, hotelpay, totalpay = 0; i < hotelnum; i++) {
		cin >> hotelpay; //���� ���
		for (int j = 0 , temp; j < hotelweeknum; j++) { //??? ��������?
			cin >> temp; //�ָ��� �ο����� ���
			if (temp >= person) { //�ο������� ��ü�ο����� ũ�� �����ϴ�.
				totalpay = person * hotelpay;
			}
		}
		if (totalpay != 0 && cheapPay > totalpay) {
			cheapPay = totalpay;
		}
	}
	if (cheapPay > money) {
		cout << "stay home";
	}
	else {
		cout << cheapPay;
	}


	return 0;
}