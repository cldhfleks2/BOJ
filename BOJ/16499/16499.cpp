#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
std::vector<std::pair<std::string, int>> wordList;

void logic() {
	int t;
	int alpha[26]; //0~25 알파벳기록
	scanf("%d", &t);
	while (t--) {
		memset(alpha, 0, sizeof(alpha)); //배열 초기화
		char input[11]; //처음 입력받은 단어
		char output[11]; //완성된단어 (최대크기10 + 1 \0)
		memset(input, '\0', sizeof(input)); 
		memset(output, '\0', sizeof(output)); 
		scanf("%s", input); //단어를 읽어옴
		int i = 0;
		//입력받은단어의 알파벳 누적값을 기록하는 부분
		while (input[i] != '\0') {
//			printf("카운트 :: %c", input[i]);
			alpha[(int)input[i] - 97]++; //알파벳 누적값기록
			i++;
		}

		int k = 0; //output에 쓰일 인덱스
		//단어를 완성하는 부분
		for (int j = 0; j < 26; j++) {
			if (alpha[j] > 0) {
				while (alpha[j]--) { //누적값만큼기록
					output[k] = (char)(j + 97); //단어를 하나씩붙임
					k++;
				}
			}
		}
		std::string s(output); //완성된 단어(string 으로 변환)
//		printf("단어 : %s  \n", output); //검산용

		//리스트에 추가하는부분
		int len = wordList.size();
		int j = 0;
		bool check = false;
		while (len--) {
			if (s.compare(wordList[j].first) == 0) { //같다면
				check = true;
				break;
			}
			j++;
		}
		//j는 맨끝또는 중복된것
		if (check) { //단어가 중복된경우
			int num = wordList[j].second; //누적횟수불러옴
			wordList.erase(wordList.begin() + j); //j번째 원소를 지우고
			wordList.push_back({ s, num + 1 }); //누적값이 1 증가된 원소를 새로 추가
//			printf("%d번 => 중복\n", i);
		}
		else { //단어가 처음등록되는경우
			wordList.push_back({ s, 1 }); //단어리스트추가
//			printf("%d번 => 처음\n", i);
		}
	}
}

void print() {
	printf("%d\n", wordList.size());
}

int main(void) {
	logic();
	print();

	return 0;
}