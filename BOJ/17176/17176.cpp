#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
using namespace std;

int main(int n, int temp) {
	scanf("%d", &n);

	int numbers[53] = {0}; //암호문기록하는 변수
	int alphabet[53] = {0}; //평문기록하는 변수 0:공백 1~26:대문자 27~52:소문자

	//암호문 입력받는 부분
	for (int i = 0; i < n - 1; i++) {
		scanf("%d", &temp);
		numbers[temp]++; //해당 숫자갯수를 카운트
	}
	//%d 다음 %c로 읽어올때 줄바꿈문자까지 읽어오므로
	//줄바꿈문자를 미리 읽어주기위함
	scanf("%d\n", &temp);
	numbers[temp]++; //해당 숫자갯수를 카운트

	//평문입력받는 부분
	for (int i = 0; i < n; i++) {
		char temp;
		scanf("%c", &temp);
		if (temp == ' ') { //공백문자라면
			alphabet[0]++;
		}
		else if(65 <= temp && temp <= 90){ //대문자일때 아스키코드
			alphabet[temp - 64]++; //1~26으로 저장
		}
		else if (97 <= temp && temp <= 122) { //소문자
			alphabet[temp - 70]++; //27~52로 저장
		}
	}
	
	//평문과 암호문을 비교하는 부분
	for (int i = 0; i < 53; i++) {
		if (alphabet[i] != numbers[i]) { //틀리다면
			printf("n");
			return 0;
		}
	}

	//여기까지오면 전부 일치한것
	printf("y");
	return 0;
}