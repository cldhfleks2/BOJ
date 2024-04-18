#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int main(void) {
	int t, cnt = 0;
	scanf("%d", &t);
	while (t--) {
		char word[101];
		bool alphabet[26];
		memset(alphabet, 0, sizeof(alphabet));
		scanf("%s", word); // 단어를 읽음

		for (int i = 0; i < 101; i++) {
			if (word[i] == NULL) {
				cnt++; //단어의 마지막까지왔으면 그룹단어
				break;
			}
			int asci = word[i] - 'a'; //현재문자를 아스키코드값으로 변환

			//연속된경우
			if (word[i] != word[i - 1] && alphabet[asci] == true) {
				//연속되지않은경우에 이미 체크된 문자면
				break;
			}
			alphabet[asci] = true;
		}
	}
	printf("%d", cnt);
}