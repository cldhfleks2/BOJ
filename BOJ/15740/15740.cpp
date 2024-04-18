#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
using namespace std;

char a[10003] = {}, b[10003] = {}; //10001 + 부호 + 문자열끝서식자 = 10003
string *A;
string *B;
string result = "";
int len_A;
int len_B;
bool bigLength = false; //A길이가 더길면 true B면 false
int least_length = 0; //len_A 또는 len_B에서 긴것이 들어가있음


void sum() {
	//8자리씩 끊어서 계산해보자.
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
	//printf("사이즈:%d ,%d\n", len_A, len_B);

	if (len_A > len_B) {
		bigLength = true;
		least_length = len_A;
	}
	else {
		least_length = len_B;
	}

	if ((A->at(0) == '-' && B->at(0) == '-')) {
		//음수 + 음수
		
	}
	else if ((A->at(0) != '-' && B->at(0) != '-')) {
		//양수 + 양수

		

	}
	else if ((A->at(0) == '-' && B->at(0) != '-') || (A->at(0) != '-' && B->at(0) == '-')){
		//양수 + 음수 또는 음수 + 양수일때
		//substract돌리고, 두수중 더 긴길이 + ...
		//이건생각좀해보자.
		


	}

	

	return 0;
}