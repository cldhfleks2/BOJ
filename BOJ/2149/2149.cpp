#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>

int main(void) {
	int keyLength = 0, secretLength = -1, period = 0;
	//input : 처음입력받은키
	//key : 키의 크기에맞게 동적할당되어 저장된 키
	//originKey : key의 복사본
	char input[11], *key, *originKey; 
	scanf("%[^\n]s", &input);
	for (int i = 0; i <= 10; i++) //m의크기를 결정
		if (input[i] == '\0')
			break;
		else
			keyLength++;
	key = new char[keyLength];
	originKey = new char[keyLength];

	for (int i = 0; i < keyLength; i++) {
		originKey[i] = input[i];
		key[i] = input[i];
	}

	char secret[101];
	char c;
	scanf("%c", &c);
	//입력값을 받는 부분
	while (scanf("%c", &c) != EOF) {
		secret[secretLength+1] = c;
		secretLength++;
		if (secretLength > 0 && c == '\n')
			break;
	}
	period = secretLength / keyLength;

	std::sort(key, key + keyLength); //키를 정렬

	//암호문에맞는 행열 데이터를 리스트에 기록
	std::vector<std::pair <char, char*>> list;
	for (int i = 0; i < keyLength; i++) {
		char* s = new char[period]; //주기만큼의 배열 생성
		for (int j = 0; j < period; j++) {
			s[j] = secret[period * i + j];
		}
		list.push_back({ key[i], s });
	}
	std::vector<std::pair<char, char*>> res;

	//암호문에서 평문으로 데이터를 변환하는 부분
	for (int i = 0; i < keyLength; i++) {
		for (int j = 0; j < list.size(); j++) {
			if (originKey[i] == list[j].first) {
				res.push_back({ originKey[i], list[j].second });
				list.erase(list.begin() + j); //리스트에서 해당위치를 삭제
				key[j] = NULL;
				break;
			}

		}
	}

	//평문을 출력하는 부분
	for (int i = 0; i < period; i++) {
		for (int j = 0; j < keyLength; j++) {
			printf("%c", res[j].second[i]);
		}
	}

	return 0;
}