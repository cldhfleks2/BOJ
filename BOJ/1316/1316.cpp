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
		scanf("%s", word); // �ܾ ����

		for (int i = 0; i < 101; i++) {
			if (word[i] == NULL) {
				cnt++; //�ܾ��� ���������������� �׷�ܾ�
				break;
			}
			int asci = word[i] - 'a'; //���繮�ڸ� �ƽ�Ű�ڵ尪���� ��ȯ

			//���ӵȰ��
			if (word[i] != word[i - 1] && alphabet[asci] == true) {
				//���ӵ���������쿡 �̹� üũ�� ���ڸ�
				break;
			}
			alphabet[asci] = true;
		}
	}
	printf("%d", cnt);
}