#define _CRT_SECURE_NO_WARNINGS //scanf���� ����
#include <bits/stdc++.h>
using namespace std;


int main(void) {
	int a, b, v;
	scanf("%d%d%d", &a, &b, &v);
	int day = a - b; //�Ϸ翡 ��ȭ�ϴ���
	int totalDistance = v - b; //�������� �̲������� �Ÿ���ŭ �� ���ٰ� ����.
	int totalDays = totalDistance / day;
	if (totalDistance % day == 0) {
		printf("%d", totalDays);
	}
	else {
		printf("%d", totalDays + 1);
	}

}