#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>

int main(int n) {
	scanf("%d", &n);
	int num = 665;
	int res = 0;
	while (num++) {
		char temp[10];

		sprintf(temp, "%d", num); //int -> string

		int cnt = 1;
		bool find = false;
		for (int i = 0; i < 10; i++) {
			if (temp[i] == '\0')
				break;
			if (temp[i] == '6') { //6��ã�´�...
				if (find)
					cnt++;
				else {
					find = true;
					cnt = 1;
				}
			} //6�̾ƴϸ� find = false;
			else {
				find = false;
			}

			if (cnt >= 3)
				break;
		}

		if (cnt >= 3) //3���̻󿬼��̸�..
			res++;

		if (res == n) {
			printf("%d", num);
			break;
		}
	}
}