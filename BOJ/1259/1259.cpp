#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>

int main(void) {
	for (;;) {
		char c[7];
		scanf("%[^\n]s", &c);
		if (c[0] == '0')
			break;
		scanf("%c", &c[6]); //줄바꿈문자 지움
		int start = 0;
		int end = 0;
		for (int i = 0; i < 6; i++) { //끝을찾아감
			if (c[i] == '\0')
				break;
			end = i;
		}

		bool isPalindrome = true;

		for (;;) {
			if (end <= start) //교차되면종료
				break;
			if (c[start] != c[end]) { //앞뒤가 서로다르면 팰린드롬이아님
				isPalindrome = false; 
				break;
			}
			//커서이동
			start++;
			end--;
		}

		if (isPalindrome)
			printf("yes\n");
		else
			printf("no\n");
	}
}