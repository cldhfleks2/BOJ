#define _CRT_SECURE_NO_WARNINGS //scanf오류 없앰
#include <bits/stdc++.h>
using namespace std;
int H, W, res, *blocks;

void next() { //모든 블럭을 한칸씩내리는 작업
	for (int i = 0; i < W; i++) {
		blocks[i]--;
	}
}

int main(void) {
	scanf("%d%d", &H, &W);
	blocks = new int[W];
	int rain = 0;
	for (int i = 0 ; i < W; i++) { //모든블럭을 기록
		scanf("%d", &blocks[i]);
	}

	//pre, now : 기둥을 체크할 두 포인터(인덱스기록
	for (int j = 0, pre, now; j < H; j++) { 
		pre = -1; //초기화
		now = 0;
		for (int i = 0, temp; i < W; i++) {
			if (blocks[i] > 0) { //기둥이 있다면
				if (pre == -1) { //처음 기둥을 설정한다면
					pre = i; //이전기둥을 기록하고 이어서
					continue;
				}
				//인덱스1부터
				now = i; //현재기둥갱신
				if (now - pre == 1) { //두기둥이 붙어있다면
					pre = now; //이전기둥위치만 바꾸고 이어서
					continue;
				}
				//이전기둥이 설정된적이 있고 기둥사이거리가 2이상일때
				if(pre != -1 && now - pre > 1){ 
					temp = now - pre - 1; //두기둥사이에 물이고인만큼 저장
					res += temp;
					//printf("%d , %d ,   %d\n", j, i, temp);
					pre = now; //이전기둥을 갱신
				}
			}
		}
		next(); //블럭을 한칸씩내린다.
	}
	printf("%d", res);
}

