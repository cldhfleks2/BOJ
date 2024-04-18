#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
char s[101];
int main(void) {
	scanf("%s", &s);
	int cur = 0;
	int alphabet[26] = {0,};
	while (s[cur] != '\0') {
		alphabet[s[cur] - 'a']++;
		cur++;
	}
	for (int i = 0; i < 26; i++)
		printf("%d ", alphabet[i]);

	return 0;
}