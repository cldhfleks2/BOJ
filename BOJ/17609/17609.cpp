#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
int t;
char c[100001];
void func();
int findSize(char* c);
bool isPalindrome(char* c, int size, int cnt);
bool isPalindrome2(char* c, int size, int cnt);

void func() {
	while (t--) {
		scanf("%s", &c);
		int size = findSize(c);
		if (isPalindrome(c, size, 0)) { //회문
			printf("0\n");
		}
		else {
			bool right = isPalindrome(c, size, 1);
			bool right2 = isPalindrome2(c, size, 1);


			if (right || right2)
				printf("1\n"); //유사회문
			else
				printf("2\n"); //일반문자열임
		}

	}
}

int findSize(char* c) {
	int size = 0;
	for (int i = 0; i < 100001; i++)
		if (c[i] == '\0')
			break;
		else
			size++;
	return size;
}

bool isPalindrome(char* c, int size, int cnt) {
	int front = 0, back = size - 1;
	bool right = true;
	while (front <= back && right) {
		if (c[front] != c[back]) {
			//printf(">> 문제 : %d %c %c %d   => ",front, c[front], c[back], back);
			if (cnt > 0) {
				cnt--;
				//문자하나 스킵
				if (front + 1 < size && c[front + 1] == c[back]) {
					//다음 문자를 확인가능한가? (올바른 범위인가)
					if (front + 2 < size && back - 1 > 0 && front + 2 <= back - 1) {
						//다음 문자도 일치하면맞음
						if (c[front + 2] == c[back - 1]) {
							//printf("1] front++ %c %c\n", c[front + 1], c[back]);
							front++;
							continue;
						} //일치하지않으면 아래 코드로진행
					}
					else { //다음 문자들을 확인불가능하면 이대로
						//printf(">> 2] front++ %c %c\n", c[front + 1], c[back]);
						front++;
						continue;
					}
				}

				if (back - 1 > 0 && c[front] == c[back - 1]) {
					if (back - 2 > 0 && front + 1 < size && front + 1 <= back - 2) {
						if (c[front + 1] == c[back - 2]) {
							//printf(">> 3] back-- %c %c\n", c[front], c[back - 1]);
							back--;
							continue;
						}
					}
					else {
						//printf(">> 4] back-- %c %c\n", c[front], c[back - 1]);
						back--;
						continue;
					}
				}
				//여기까지오면 오류
				//printf(">> end %c %c\n", c[front], c[back]);
				right = false;
				break;
			}
			else {
				right = false;
				break;
			}
		}
		front++;
		back--;
	}
	return right;
}

bool isPalindrome2(char* c, int size, int cnt) {
	int front = 0, back = size - 1;
	bool right = true;
	while (front <= back && right) {
		if (c[front] != c[back]) {
			//printf(">> 문제 : %d %c %c %d   => ", front, c[front], c[back], back);
			if (cnt > 0) {
				cnt--;
				//문자하나 스킵
				if (back - 1 > 0 && c[front] == c[back - 1]) {
					if (back - 2 > 0 && front + 1 < size && front + 1 <= back - 2) {
						if (c[front + 1] == c[back - 2]) {
							//printf(">> 3] back-- %c %c\n", c[front], c[back - 1]);
							back--;
							continue;
						}
					}
					else {
						//printf(">> 4] back-- %c %c\n", c[front], c[back - 1]);
						back--;
						continue;
					}
				}

				if (front + 1 < size && c[front + 1] == c[back]) {
					//다음 문자를 확인가능한가? (올바른 범위인가)
					if (front + 2 < size && back - 1 > 0 && front + 2 <= back - 1) {
						//다음 문자도 일치하면맞음
						if (c[front + 2] == c[back - 1]) {
							//printf("1] front++ %c %c\n", c[front + 1], c[back]);
							front++;
							continue;
						} //일치하지않으면 아래 코드로진행
					}
					else { //다음 문자들을 확인불가능하면 이대로
						//printf(">> 2] front++ %c %c\n", c[front + 1], c[back]);
						front++;
						continue;
					}
				}

				//여기까지오면 오류
				//printf(">> end %c %c\n", c[front], c[back]);
				right = false;
				break;
			}
			else {
				right = false;
				break;
			}
		}
		front++;
		back--;
	}
	return right;
}

int main(void) {
	scanf("%d", &t);
	func();

	return 0;
}