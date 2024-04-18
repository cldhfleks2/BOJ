#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>

char input[101]; //입력 받은 문장
std::vector<std::string> res; //단어들을 기록할공간
void translate(bool isJava);
void logic();
void init();

void init() {
	scanf("%s", &input);
}

void logic() {
	bool isJava = false;
	char buffer[101] = {};
	int cursor = 0;
	int endIndex = 0;

	for (int i = 0; i <= 100; i++) { 
		char c = input[i];
		if (endIndex == 0 && c == '\0')
			endIndex = i - 1;

		//첫문자가 대문자나 하이픈이면 에러
		if (i == 0 && 65 <= c && c <= 90) { 
			printf("Error!");
			return;
		}
		if (i == 0 && c == '_') {
			printf("Error!");
			return;
		}
		//그외에 대문자가 쓰이면 자바로 인식. 추후 오류는 아래서 체크
		if (65 <= c && c <= 90) {
			isJava = true;
			break;
		}
	}

	if (input[endIndex] == '_') { //마지막문자가 '_'인경우
		printf("Error!");
		return;
	}

	bool isHyphen = false;
	for (int i = 0; i <= 100; i++) {
		char c = input[i];
		if (c == '_') { //'_' 이 오는경우
			if (!isHyphen) { //연속되지않았으면 체크
				isHyphen = true;
			}
			else { //연속되게 '_' 이 나오면 에러
				printf("Error!");
				return;
			}
			//'_' 다음에 대문자가 오는경우
			if (65 <= input[i + 1] && input[i + 1] <= 90) {
				printf("Error!");
				return;
			}
			continue;
		}
		//'_'이 오지 않은경우
		if (isHyphen) //이전에 '_'이 나온경우 체크해제
			isHyphen = false;
	}

	if (isJava) { //java
		for (int i = 0; i <= 100; i++) { //에러 확인용
			char c = input[i];
			if (c == '_') {
				printf("Error!");
				return;
			}
		}

		for (int i = 0; i <= 100; i++) { //JAVA단어를 자르는 부분
			char c = input[i];
			if (65 <= c && c <= 90) { //대문자면 새로운단어
				std::string s(buffer);
				res.push_back(s); //이전까지 단어를 기록하고
				for (int j = 0; j <= 100; j++)
					buffer[j] = NULL;
				cursor = 0;
				buffer[0] = (char)((int)c + 32); //소문자로바꾸어서 버퍼에기록
				cursor++;
			}
			else { //소문자면 단어가 안끝난것
				buffer[cursor] = c; //버퍼에기록(소문자인 상태)
				cursor++;
			}
		}
		std::string s(buffer);
		res.push_back(s); 

	}
	else { //C++
		for (int i = 0; i <= 100; i++) { //에러 확인용
			char c = input[i];
			if (65 <= c && c <= 90) {
				printf("Error!");
				return;
			}
		}

		for (int i = 0; i <= 100; i++) { //C++ 단어를 자르는부분
			char c = input[i];
			
			if (c == '_') {
				std::string s(buffer);
				res.push_back(s); //이전까지 단어를 기록하고
				for (int j = 0; j <= 100; j++)
					buffer[j] = NULL;
				cursor = 0;
			}
			else {
				buffer[cursor] = c;
				cursor++;
			}

		}
		std::string s(buffer);
		res.push_back(s);

	}

	translate(isJava);
}

void translate(bool isJava) { //단어들을 다른언어로 바꿔주는 부분
	std::string ans;

	if (isJava) { //JAVA
		for (int i = 0; i < res.size(); i++) {
			ans.append(res[i]);
			if (i != res.size() - 1) {
				ans.append("_");
			}
		}
	}
	else { //C++
		for (int i = 0; i < res.size(); i++) {
			if (i == 0) {
				ans.append(res[i]);
			}else{
				ans += (char)((int)res[i][0] - 32); //첫글자 대문자로
				for (int j = 1; j < res[i].length(); j++) {
					ans += res[i][j]; //나머지는 소문자 그대로
				}
			}
		}
	}
	printf("%s", ans.c_str());
}

int main(void) {
	init();
	logic();

	return 0;
}