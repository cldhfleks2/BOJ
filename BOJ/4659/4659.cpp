#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>

void password(char* c);

void init() {
	while (true) {
		char in[21];
		scanf("%s", &in);
		if ((std::string)in == "end") //종료조건
			break;
		printf("<%s> ", in); //<비번> 까지 출력
		password(in); //나머지 is acceptable or is not acceptable출력
	}
}

void password(char* c) {
	char temp[21] = {'\0'}; //ee, oo가있으면 e, o 로만 저장하는 배열
	int cursor = 0; //위 배열에서쓰일 인덱스
	char pre = NULL; //이전 문자를 저장
	bool last = false; //eee, ooo가 나오는지 확인하기위함
	for (int i = 0; i < 20; i++) { //ee 와 oo를 확인
		if (c[i] == '\0') //끝을 만나면 종료
			break;
		if (pre == c[i]) { //이전문자와 현재문자가 같은경우
			//조건3) 같은글자가 연속적으로 나오면안됨 그러나 ee, oo는 허용
			if (pre == 'e' || pre == 'o') {
				if (!last) { 
					last = true;
				}
				else { //만약 eee , ooo가 나온경우라면 에러
					printf("is not acceptable.\n");
					return;
				}
			}
			else {
				printf("is not acceptable.\n");
				return;
			}
		}
		else {
			last = false;
			pre = c[i];
			temp[cursor] = c[i];
			cursor++;
		}
	}

	int* check = new int[cursor]; //모음과 자음을 1 과 0으로 변환하여 저장하는 배열
	bool vowel = false; //모음이 하나라도 나오는지 확인하기위함
	for (int i = 0; i < cursor; i++) {
		if (temp[i] == 97 ||
			temp[i] == 101 ||
			temp[i] == 105 ||
			temp[i] == 111 ||
			temp[i] == 117) {
			vowel = true;
			check[i] = 1; //모음은 1
		}
		else {
			check[i] = 0; //자음은 0
		}
	}
	if (!vowel) { //조건1) 모음을 반드시 하나이상 포함해야함
		printf("is not acceptable.\n");
		return;
	}
	int preNum = -1; //이전숫자(모음 or 자음)
	int cnt = 1; //연속된 갯수
	for (int i = 0; i < cursor; i++) { //조건2) 모음/자음이 3번이상연달아 나오면안됨
		if (preNum != check[i]) { //모음과 자음이 번갈아나온경우
			cnt = 1;
			preNum = check[i];
		}
		else { //모음 과 모음 또는 자음과 자음이 나온경우
			cnt++;
			if (cnt >= 3) { //연달아 3번나온경우
				printf("is not acceptable.\n");
				return;
			}
		}
	}
	//여기까지오면 모든 조건을 충족한것
	printf("is acceptable.\n");
	return;
}

int main(void) {
	init();

	return 0;
}