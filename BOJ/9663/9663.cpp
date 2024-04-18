#include <bits/stdc++.h>
using namespace std;

int n, *queen, result;

bool promisingCheck(int row) {//해당 행, 열에 퀸을 놓을수 있는가
	for (int i = 0; i < row; i++) { //입력받은행까지탐색
		if ((queen[i] == queen[row]) || //열의위치가 겹치거나 대각선인경우 불가능함
			//행의위치가 겹칠일은 없으니까 제외함. 말이안되지
			(row - i == (abs(queen[row] - queen[i])))) {
			return false;
		}
	}
	return true;
}

void n_queen(int row) {
	if (row == n) { //n행까지 퀸을 모두 놓았따면 경우의수 +1
		result++;
		return;
	}
	else {
		for (int col = 0; col < n; col++) {
			//행을고정하고 열을 하나씩바꾸면서 가능하면 
			//더 깊이 탐색을하는 DFS에 유망한노드여야만 탐색을하는
			//백트래킹이되겠다.
			queen[row] = col; //row행 col열에 퀸을 놓는다.
			if (promisingCheck(row)) //현재위치가 퀸의 위치로 알맞다면 다음 행을 검사한다.
				n_queen(row + 1); //이게 실행안되면 탐색은종료고, 경우의수는 카운트되지않는다.
		}
	}
}

int main(void) {
	cin >> n;
	queen = new int[n];

	n_queen(0);
	cout << result;

	return 0;
}