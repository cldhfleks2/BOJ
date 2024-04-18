#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
using std::string;
string s[50];
int t;



int main(void) {
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		char _[51];
		scanf("%s", &_);
		s[i] = _;
	}
	int size = 0;
	for (int i = 0; i < 51; i++)
		if (s[0][i] == '\0')
			break;
		else
			size++;

	for (int i = 0; i < size; i++) {
		char res = s[0][i]; 
		for(int j = 1 ; j < t ; j++)
			if (s[j][i] != res) {
				res = '?';
				break;
			}
		printf("%c", res);
	}



	return 0;
}
