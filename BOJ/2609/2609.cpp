#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>

int logic(int a, int b) {
	if (a > b) { //a< b
		int temp = a;
		a = b;
		b = temp;
	}
	int res = 1;
	bool check = false;
	while (1) {
		for (int i = 2; i <= b; i++) {
			if (a % i == 0 &&
				b % i == 0) {
				check = true; //����üũ
				a /= i; //a, b�� ��� ����� �ٽ�����
				b /= i;
				res *= i; //������
			}
		}
		if (check) {
			check = false;
		}
		else {
			break;
		}
	}
	return res;
}

int LCM(int a, int b) {
	int res = logic(a, b); //�ִ����� ���⿡ a, b�� �������� �������������
	int a_q = a / res; //a, b�� �ִ������� ������ ���� ��ŭ
	int b_q = b / res; //�ִ������鿡 �����ָ� �ִ��������ȴ�.
	res *= a_q * b_q;
	
	return res;
}

int GCD(int a, int b) {
	int res = logic(a, b); //�ִ�����

	return res;
}

int main(void) {
	int a, b;
	scanf("%d%d", &a, &b); 

	printf("%d\n%d", GCD(a, b), LCM(a, b));
	return 0;
}