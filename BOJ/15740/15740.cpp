#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
using namespace std;

char a[10003] = {}, b[10003] = {}; //10001 + ��ȣ + ���ڿ��������� = 10003
string *A;
string *B;
string result = "";
int len_A;
int len_B;
bool bigLength = false; //A���̰� ����� true B�� false
int least_length = 0; //len_A �Ǵ� len_B���� ����� ������


void sum() {
	//8�ڸ��� ��� ����غ���.
	for (int i = 0; i < least_length / 8; i++) {

	}
}

void substract() {


}

int main(void) {
	scanf("%s%s", &a, &b);
	A = new string(a);
	B = new string(b);
	
	len_A = (*A).size();
	len_B = (*B).size();
	//printf("������:%d ,%d\n", len_A, len_B);

	if (len_A > len_B) {
		bigLength = true;
		least_length = len_A;
	}
	else {
		least_length = len_B;
	}

	if ((A->at(0) == '-' && B->at(0) == '-')) {
		//���� + ����
		
	}
	else if ((A->at(0) != '-' && B->at(0) != '-')) {
		//��� + ���

		

	}
	else if ((A->at(0) == '-' && B->at(0) != '-') || (A->at(0) != '-' && B->at(0) == '-')){
		//��� + ���� �Ǵ� ���� + ����϶�
		//substract������, �μ��� �� ����� + ...
		//�̰ǻ������غ���.
		


	}

	

	return 0;
}