#include <bits/stdc++.h>
using namespace std;

int** block;

int main(void) {
	int test;
	cin >> test;
	while (test--) {
		int row, col; //행, 열
		cin >> row >> col;
		block = new int*[row];
		int blockCnt = 0;
		int maxFloor = 0; //최대층 높이
		for (int i = 0; i < row; i++) { //2차원배열에 저장
			block[i] = new int[col];
			string temp = "";
			cin >> temp; //공백없이 입력받으므로 string으로 저장후 하나씩 int로 바꿀것
			for (int j = 0; j < col; j++) {
				int num = temp[j] - '0'; //string에서 하나씩 char를 int로
				blockCnt += num; //블럭갯수카운팅
				if (maxFloor < num) maxFloor = num;
				block[i][j] = num; //값을 전부 기록
			}
		}

		int totalArea = 6 * blockCnt;
		int overlapArea = 0;
		while (maxFloor--) {
			for (int i = 0; i < row; i++) {
				for (int j = 0; j < col; j++) {
					int b = block[i][j];
					//b가 2이상 : 축방향?위로보는 겹치는부분존재
					if (b >= 2) overlapArea += 2;
					//(i+1)이 1이상, b가 1이상 : 행방향 겹치는 부분존재
					if (i + 1 < row && block[i + 1][j] >= 1 && b >= 1) overlapArea += 2;
					//(j+1)이 1이상, b가 1이상 : 열방향 겹치는 부분존재
					if (j + 1 < col && block[i][j + 1] >= 1 && b >= 1) overlapArea += 2;
				}	
			}

			for (int i = 0; i < row; i++) {//층을 하나씩 내리는 작업
				for (int j = 0; j < col; j++) {
					block[i][j] -= 1;
				}
			}
		}
		cout << totalArea - overlapArea << endl;

		delete block; //메모리해제
	}
	return 0;
}
