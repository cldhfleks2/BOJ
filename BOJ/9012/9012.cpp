#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>

int main(int t) {
	scanf("%d\n", &t);
	while (t--) {
		char s[52];
		scanf("%[^\n]s", &s); //�����Է¹���
		scanf("%c",&s[51]); //�ٹٲ޹��ڴ� �Ⱦ��� �ε����� ������ ����
		int p = 0; //���ñ����Ͱ���..
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