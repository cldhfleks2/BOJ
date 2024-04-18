//#define _CRT_SECURE_NO_WARNINGS 
//#include <bits/stdc++.h>
//using std::vector;
//int n, w, b, *** blocks, * lines, ** box, box_h = 0;
//vector<int> heights, res;
//void clear();
//void func();
//bool isRight(int block_num, int start_h);
//void packing(int block_num, int start_h);
//void printAll();
//void debug();
//
//void printAll() {
//	for (int i = 0; i < res.size(); i++)
//		printf("%d ", res[i]);
//}
//
//void clear() { //박스 초기화
//	for (int i = 0; i < b + 10; i++)
//		for (int j = 0; j < w; j++)
//			box[i][j] = 0;
//}
//
//void func() {
//	box = new int* [b + 10];
//	for (int i = 0; i < b + 10; i++)
//		box[i] = new int[w];
//
//	clear(); //처음 초기화
//
//	for (int k = 0; k < n; k++) {
//
//		int start_h; //블럭을 놓을수있는 최소 높이
//		int current_h = heights[k]; //현재블럭의 높이
//		int gap = 0;
//
//		for (start_h = box_h + 1; start_h > 0; start_h--) { //pack의 현재 최대높이 + 1 부터 확인
//			if (!isRight(k, start_h)) { //불가능하면 끝
//				break;
//			}
//			gap++;
//		}
//		if (box_h != 0) //이미 블럭이 쌓여있던경우 그 위칸부터 블럭을 쌓기시작
//			start_h++;
//		//printf(">> >> >> 발견한 시작위치%d\n", start_h);
//
//		if (start_h + current_h > b) { //1.쌓고난뒤 높이가 박스를 초과한경우
//			res.push_back(box_h); //현재 박스최대 높이(인덱스X) 결과로 저장
//			clear(); //박스 리셋
//			box_h = current_h;  //현재 박스최대높이(인덱스X)를 현재블럭높이로 갱신
//			packing(k, 0); //박스바닥부터 블럭을 쌓음
//			//printf(">> %d : 1\n", k);
//		}
//		else if (start_h + current_h == b) { //2.쌓고난뒤 높이가 박스와 일치
//			res.push_back(b); //박스높이를 결과로 저장
//			clear(); //박스 리셋
//			box_h = 0; //박스 최대높이 0으로 갱신
//			//printf(">> %d : 2\n", k);
//		}
//		else { //3.쌓은높이가 아직 박스보다 작을때
//			packing(k, start_h); //실제로 블럭을 쌓음
//			box_h = start_h + current_h; //박스 최대높이 갱신
//			//printf(">> %d : 3\n", k);
//		}
//
//		//마지막에 박스에 쌓은블럭이남았으면 결과로 저장
//		if (k == n - 1 && box_h != 0)
//			res.push_back(box_h);
//
//		//printf(">> 현재 박스 최대높이 : %d\n", box_h);
//	}
//
//}
//
//void debug(int block_num, int start_h) {
//	int** d = new int* [b + 10];
//	for (int i = 0; i < b + 10; i++)
//		d[i] = new int[w];
//
//	for (int i = 0; i < b + 10; i++)
//		for (int j = 0; j < w; j++)
//			d[i][j] = box[i][j];
//
//	for (int i = start_h; i < start_h + heights[block_num]; i++) {
//		for (int j = 0; j < w; j++) {
//			if (blocks[block_num][i - start_h][j] == 1)
//				if (d[i][j] == 1)
//					d[i][j] = -1;
//				else
//					d[i][j] = -2;
//			else if (d[i][j] == 1)
//				d[i][j] = 1;
//			else
//				d[i][j] = -4;
//		}
//	}
//
//	for (int i = 0; i < b + 10; i++) {
//		for (int j = 0; j < w; j++) {
//			if (d[i][j] == -1)
//				printf("?");
//			else if (d[i][j] == -2)
//				printf("B");
//			else if (d[i][j] == 1)
//				printf("X");
//			else
//				printf(".");
//		}
//		printf("\n");
//	}printf("\n");
//}
//
//bool isRight(int block_num, int start_h) { //블럭을 놓을수 있는지 확인
//	//debug(block_num, start_h); //출력용도
//
//	int h = heights[block_num];
//	for (int i = start_h; i < start_h + h; i++) { //블럭이 안겹치는지 확인
//		for (int j = 0; j < w; j++) {
//			//printf("%2d", box[i][j]);
//			//박스와 블럭이 겹치면 안됨
//			if (box[i][j] == 1 && blocks[block_num][i - start_h][j] == 1) {
//				//printf(">>>>>>>>>>>>>>>> %d %d 충돌\n", i, j);
//				return false; //놓을 수 없음
//			}
//		}
//		//printf("\n");
//	}
//	return true;
//}
//
//void packing(int block_num, int start_h) { //pack에 블럭을 쌓음
//	int h = heights[block_num];
//	for (int i = start_h; i < start_h + h; i++) {
//		for (int j = 0; j < w; j++) {
//			if (blocks[block_num][i - start_h][j] == 1) //블럭인부분만
//				box[i][j] = 1;
//		}
//	}
//}
//
//int main(void) {
//	scanf("%d%d%d", &n, &w, &b);
//	blocks = new int** [n]; //blocks 블럭형태
//	for (int k = 0, h; k < n; k++) {
//		scanf("%d", &h);
//		heights.push_back(h);
//		blocks[k] = new int* [h];
//		char c;
//		//블럭이 아래부터쌓으나, 실제 메모리상에는 아래에서 위로 쌓이므로
//		//입력을 상하반전으로 받음.
//		for (int i = h - 1; i >= 0; i--) {
//			blocks[k][i] = new int[w];
//			scanf("%c", &c); //줄바꿈문자지움
//			for (int j = 0; j < w; j++) {
//				scanf("%c", &c); //블럭읽어옴
//				if (c == 'X')
//					blocks[k][i][j] = 1; //블럭
//				else
//					blocks[k][i][j] = 0; //공란
//			}
//		}
//
//	}
//	lines = new int[w]; //lines 너비마다의 현재까지 차오른높이 계산
//	for (int i = 0; i < w; i++)
//		lines[i] = 0;
//
//	func();
//	printAll();
//
//	return 0;
//}