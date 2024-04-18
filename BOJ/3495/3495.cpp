#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
int h, w, ** pic, area=0;

void init() {
	scanf("%d%d", &h, &w);
	pic = new int* [h];
	for (int i = 0; i < h; i++) {
		pic[i] = new int[w];
		char _;
		scanf("%c", &_); //줄바꿈문자지움
		for (int j = 0; j < w; j++) {
			scanf("%c", &_);
			if (_ == '/' || _ == '\\')
				pic[i][j] = 1;
			else
				pic[i][j] = 0;
		}
	}
}

void func() {
	//가로로 탐색해가며, 칠해진정사각형갯수를 찾음
	for (int i = 0; i < h; i++) { 
		int cnt = 0; 
		int crossCnt = 0;
		for (int j = 0; j < w; j++) {
			if (pic[i][j] == 1) {
				crossCnt++;
			if (crossCnt % 2 != 0)  //홀수번째 대각선일때
				cnt = 0;
			else  //짝수번째
				area += cnt;
			}
			else 
				cnt++;
		}
		area += crossCnt / 2;
	}
	printf("%d", area);
}

int main(void) {
	init();
	func();
	
	return 0;
}