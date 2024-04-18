#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
using std::vector;
using std::pair;
vector<pair<int, int>> queen, knight, pawn;
int n, m, qn, kn, pn, **map; //map: 입력받은 체스말 위치 기록
bool** res; //안전한곳인지 check

int printAll() {
	int cnt = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (res[i][j])
				cnt++;
	return cnt;
}

void make_map() {
	//맵 선언과 초기화
	map = new int* [n];
	res = new bool* [n];
	for (int i = 0; i < n; i++) {
		map[i] = new int[m];
		res[i] = new bool[m];
		for (int j = 0; j < m; j++) {
			map[i][j] = 0; // 처음엔 모두 빈공간으로 기록
			res[i][j] = true; //처음엔 모두 안전한곳으로 기록
		}
	}

	//queen위치 => 1 기록
	for (int i = 0; i < qn; i++) {
		int x = queen[i].first, y = queen[i].second;
		map[x][y] = 1;
		res[x][y] = false;
	}
	//knight위치 => 2 기록
	for (int i = 0; i < kn; i++) {
		int x = knight[i].first, y = knight[i].second;
		map[x][y] = 2;
		res[x][y] = false;
	}
	//pawn위치 => 3 기록
	for (int i = 0; i < pn; i++) {
		int x = pawn[i].first, y = pawn[i].second;
		map[x][y] = 3;
		res[x][y] = false;
	}
}

void queen_check() { //장애물 상관 O
	for (int k = 0; k < qn; k++) { //퀸갯수만큼반복
		int x = queen[k].first, y = queen[k].second; //현재퀸의 좌표
		
		//← 탐색
		for (int i = y - 1; i >= 0; i--) {
			if (map[x][i] != 0) //장애물만날시 스탑
				break;
			res[x][i] = false; //퀸이 이동가능하므로 안전하지않은곳
		}
		//→ 탐색
		for (int i = y + 1; i < m; i++) {
			if (map[x][i] != 0) 
				break;
			res[x][i] = false; 
		}
		//↑ 탐색
		for (int i = x - 1; i >= 0; i--) {
			if (map[i][y] != 0)
				break;
			res[i][y] = false;
		}
		//↓ 탐색
		for (int i = x + 1; i < n; i++) {
			if (map[i][y] != 0)
				break;
			res[i][y] = false;
		}
		
		//↖ 탐색
		for (int gap = 1; ; gap++) {
			if (x - gap <= -1 || y - gap <= -1) //범위를 벗어난경우 스탑
				break;
			if (map[x - gap][y - gap] != 0) //다른 체스말이 놓인경우 스탑
				break;
			res[x - gap][y - gap] = false;
		}
		//↘ 탐색
		for (int gap = 1; ; gap++) {
			if (x + gap >= n || y + gap >= m) 
				break;
			if (map[x + gap][y + gap] != 0) 
				break;
			res[x + gap][y + gap] = false;
		}
		//↗ 탐색
		for (int gap = 1; ; gap++) {
			if (x - gap < 0 || y + gap >= m) 
				break;
			if (map[x - gap][y + gap] != 0) 
				break;
			res[x - gap][y + gap] = false;
		}
		//↙ 탐색
		for (int gap = 1; ; gap++) {
			if (x + gap >= n || y - gap < 0) 
				break;
			if (map[x + gap][y - gap] != 0) 
				break;
			res[x + gap][y - gap] = false;
		}
	}
}

void knight_check() { //장애물 상관 X
	for (int k = 0; k < kn; k++) {
		int x = knight[k].first, y = knight[k].second;
		//←↖ 
		if (x - 1 >= 0 && y - 2 >= 0)
			res[x - 1][y - 2] = false;
		//↑↖ 
		if (x - 2 >= 0 && y - 1 >= 0)
			res[x - 2][y - 1] = false;
		//↗↑ 
		if (x - 2 >= 0 && y + 1 < m)
			res[x - 2][y + 1] = false;
		//↗→ 
		if (x - 1 >= 0 && y + 2 < m)
			res[x - 1][y + 2] = false;
		//↘→
		if (x + 1 < n && y + 2 < m)
			res[x + 1][y + 2] = false;
		//↘↓
		if (x + 2 < n && y + 1 < m)
			res[x + 2][y + 1] = false;
		//↓↙
		if (x + 2 < n && y - 1 < m)
			res[x + 2][y - 1] = false;
		//←↙
		if (x + 1 < n && y - 2 < m)
			res[x + 1][y - 2] = false;
	}
}

int main(void) {
	scanf("%d %d", &n, &m); 
	scanf("%d", &qn); //퀸입력
	for (int i = 0, x, y; i < qn; i++) {
		scanf("%d %d", &x, &y);
		queen.push_back({ x-1, y-1 }); //인덱스로 계산하기위해 -1씩
	}
	scanf("%d", &kn); //나이트입력
	for (int i = 0, x, y; i < kn; i++) {
		scanf("%d %d", &x, &y);
		knight.push_back({ x-1, y-1 });
	}
	scanf("%d", &pn); //폰입력
	for (int i = 0, x, y; i < pn; i++) {
		scanf("%d %d", &x, &y);
		pawn.push_back({ x-1, y-1 });
	}

	make_map();
	queen_check();
	knight_check();

	printf("%d", printAll()); //출력

	return 0;
}