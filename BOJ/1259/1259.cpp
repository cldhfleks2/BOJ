#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>

int main(void) {
	for (;;) {
		char c[7];
		scanf("%[^\n]s", &c);
		if (c[0] == '0')
			break;
		scanf("%c", &c[6]); //�ٹٲ޹��� ����
		int start = 0;
		int end = 0;
		for (int i = 0; i < 6; i++) { //����ã�ư�
			if (c[i] == '\0')
				break;
			end = i;
		}

		bool isPalindrome = true;

		for (;;) {
			if (end <= start) //�����Ǹ�����
				break;
			if (c[start] != c[end]) { //�յڰ� ���δٸ��� �Ӹ�����̾ƴ�
				isPalindrome = false; 
				break;
			}
			//Ŀ���̵�
			start++;
			end--;
		}

		if (isPalindrome)
			printf("yes\n");
		else
			printf("no\n");
	}
}