#define _CRT_SECURE_NO_WARNINGS //scanf오류 없앰
#include <bits/stdc++.h>
using namespace std;


int main(void) {
	int a, b, v;
	scanf("%d%d%d", &a, &b, &v);
	int day = a - b; //하루에 변화하는폭
	int totalDistance = v - b; //마지막날 미끄러지는 거리만큼 더 간다고 가정.
	int totalDays = totalDistance / day;
	if (totalDistance % day == 0) {
		printf("%d", totalDays);
	}
	else {
		printf("%d", totalDays + 1);
	}

}