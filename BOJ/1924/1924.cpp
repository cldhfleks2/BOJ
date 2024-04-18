#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
using std::string;
int months[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
string weekend[8] = { "", "MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN" };

int main(void) { //1~7 월~일
	int x, y, week = 1;
	scanf("%d%d", &x, &y);
	int m=1, d=1;
	while (1) { 
		if (m == x && d == y) break; //m==x d==y 면종료
		d++;
		week++;
		if (week == 8) week = 1;
		if (months[m] == d-1) {
			d = 1;
			m++;
		}
	}

	printf("%s", weekend[week].c_str());
	return 0;
}