#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
using namespace std;

int main(int n) {
	queue<int> q;
	scanf("%d\n", &n);
	while (n--) {
		char c[13]; //실제크기 11 여유공간 2
		scanf("%[^\n]s", &c);
		scanf("%c", &c[12]); //c[12]에 필요없는 줄바꿈문자를 저장

		if (c[0] == 'p' && c[3] == 'h') { //push인경우
			int cursor = 5; 
			int size = 0; //숫자길이
			for (int i = cursor; i < 11; i++) //숫자 길이를 셈
				size++;
			char* num = new char[size]; //숫자를나타낼 문자열
			//숫자를 한자리씩 저장
			for (int i = 0; i < size; i++) {
				num[i] = c[5 + i]; 
			}

			//문자열을 숫자로
			int number = atoi(num);

			q.push(number);
		}
		else if (c[0] == 'p') { //pop
			printf("%d\n", q.empty() ? -1 : q.front());
			if (!q.empty())
				q.pop();
		}
		else if (c[0] == 's') { //size
			printf("%d\n", q.size());
		}
		else if (c[0] == 'e') { //empty
			printf("%d\n", q.empty());

		}
		else if (c[0] == 'f') { //front
			printf("%d\n", q.empty() ? -1 : q.front());
		}
		else if (c[0] == 'b') {
			printf("%d\n", q.empty() ? -1 : q.back());
		}
	}

	return 0;
}