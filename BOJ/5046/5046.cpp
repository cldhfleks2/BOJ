#include <iostream>
using namespace std;

int person, money;

int main() {
	int hotelnum, hotelweeknum;
	cin >> person >> money >> hotelnum >> hotelweeknum;
	int cheapPay = 0x7fffffff;
	for (int i = 0, hotelpay, totalpay = 0; i < hotelnum; i++) {
		cin >> hotelpay; //가격 기록
		for (int j = 0 , temp; j < hotelweeknum; j++) { //??? 변수선언?
			cin >> temp; //주마다 인원제한 기록
			if (temp >= person) { //인원제한이 전체인원보다 크면 가능하다.
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