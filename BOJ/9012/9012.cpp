#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>

int main(int t) {
	scanf("%d\n", &t);
	while (t--) {
		char s[52];
		scanf("%[^\n]s", &s); //한줄입력받음
		scanf("%c",&s[51]); //줄바꿈문자는 안쓰는 인덱스에 넣으며 지움
		int p = 0; //스택구조와같음..
		bool isVPS = true;
		for (int i = 0; i < 51; i++) {
			char temp = s[i];
			if (temp == '\0')
				break;
			if (temp == '(')
				p++;
			if (temp == ')')
				p--;
			if (p < 0) {
				isVPS = false;
				break;
			}
		}

		if (p > 0)
			isVPS = false;

		if (isVPS)
			printf("YES\n");
		else
			printf("NO\n");
	}

	return 0;
}