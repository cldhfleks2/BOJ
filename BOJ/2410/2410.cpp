#define _CRT_SECURE_NO_WARNINGS //scanf���� ����
#include <bits/stdc++.h>


int main(void) {
	int cardNum, M, max = 0;
	scanf("%d%d", &cardNum, &M);
	int* card = new int[cardNum];
	for (int i = 0; i < cardNum; i++){ //����Է���  ����
		scanf("%d", &card[i]);
	}
	
	for (int i = 0; i < cardNum; i++) {
		for (int j = 0; j < cardNum; j++) {
			if (i == j) continue; //�ߺ�X
			for (int k = 0; k < cardNum; k++) {
				if (k == j || i == k) continue; //�ߺ� X
				int sum = card[i] + card[j] + card[k];
				if (sum > M) continue; //M�� ������ X
				if (max < sum) max = sum; //�ִ� ����
			}
		}
	}
	printf("%d", max);
}