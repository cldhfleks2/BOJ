#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
int h, w, ** pic, area=0;

void init() {
	scanf("%d%d", &h, &w);
	pic = new int* [h];
	for (int i = 0; i < h; i++) {
		pic[i] = new int[w];
		char _;
		scanf("%c", &_); //�ٹٲ޹�������
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
	//���η� Ž���ذ���, ĥ�������簢�������� ã��
	for (int i = 0; i < h; i++) { 
		int cnt = 0; 
		int crossCnt = 0;
		for (int j = 0; j < w; j++) {
			if (pic[i][j] == 1) {
				crossCnt++;
			if (crossCnt % 2 != 0)  //Ȧ����° �밢���϶�
				cnt = 0;
			else  //¦����°
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