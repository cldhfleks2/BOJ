#define _CRT_SECURE_NO_WARNINGS //scanf오류 없앰
#include <bits/stdc++.h>


int main(void) {
	int cardNum, M, max = 0;
	scanf("%d%d", &cardNum, &M);
	int* card = new int[cardNum];
	for (int i = 0; i < cardNum; i++){ //모든입력을  받음
		scanf("%d", &card[i]);
	}
	
	for (int i = 0; i < cardNum; i++) {
		for (int j = 0; j < cardNum; j++) {
			if (i == j) continue; //중복X
			for (int k = 0; k < cardNum; k++) {
				if (k == j || i == k) continue; //중복 X
				int sum = card[i] + card[j] + card[k];
				if (sum > M) continue; //M을 넘으면 X
				if (max < sum) max = sum; //최댓값 갱신
			}
		}
	}
	printf("%d", max);
}