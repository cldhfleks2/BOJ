#define _CRT_SECURE_NO_WARNINGS //scanf오류 없앰
#include <bits/stdc++.h>
using namespace std;

int main(void) {
	char input[1000000]; // scanf는 string으로못받음 char[]로 받는다.
	int alphabet[26] = {0}; //0~25 : A~Z
	scanf("%s", &input);
	for (int i = 0, index; i < 1000000; i++) {
		if (input[i] == NULL) break;
		if (97 <= input[i] && input[i] <= 122) { //소문자 
			index = input[i] - 97;
		}
		else { //대문자
			index = input[i] - 65;
		}
		alphabet[index]++; 
	}
	int max = 0;
	int maxIndex = 0;
	bool overlap = false;
	for (int i = 0; i < 26; i++) {
		if (alphabet[i] > max) {
			max = alphabet[i];
			maxIndex = i;
			overlap = false;
		}
		else if (alphabet[i] == max) {
			overlap = true;
		}
	}
	if (overlap) {
		printf("?");
	}
	else {
		printf("%c", (char)('A' + maxIndex));
	}
}