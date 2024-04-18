#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
using namespace std;

int cmp(string a, string b) {
	if (a.length() == b.length()) {
		return a < b;
	}
	else {
		return a.length() < b.length();
	}
}

string words[20000];

int main(int n) {
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) {
		char c[50];
		scanf("%s", &c);
		words[i] = c;
	}

	sort(words, words + n, cmp);

	for (int i = 0; i < n; i++) {
		if (words[i] == words[i - 1]) { 
			continue; 
		}
		printf("%s\n", words[i].c_str());
	}

	return 0;
}