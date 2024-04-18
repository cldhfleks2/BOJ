#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
using std::vector; using std::pair; using std::queue;
typedef pair<int, int> pii;
/*
map : 초기입력값
virusMap : 임의의 위치에 벽3개를 세운뒤의 맵
visited : BFS에서 중복방문을 막기위한 방문체크용 배열
virus : 바이러스(좌표) 리스트
black : 빈공간(좌표) 리스트
loc : BFS에서 사용할 큐
safetyArea : BFS이후 구해진 안전영역크기의 최댓값
*/
int n, m, **map, safetyArea=0;
int** visited;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
vector<pii> virus, blank;
queue<pii> loc;
void init();
int virusSpread();
void clear();
void resetVirusMap(int a, int b, int c);
void replaceMap(int a, int b, int c);
void selectWallLoc(int num, vector<int>& selected, int cnt);
void func();

void func() {
	vector<int> selected;
	int size = blank.size();
	selectWallLoc(size, selected, 3); //빈공간중 3개를 선택하는 경우를 고름.

	printf("%d", safetyArea); //안전영역 최대크기 출력
}

void selectWallLoc(int num, vector<int>& selected, int cnt) {
	if (cnt == 0) { //3개를 선택한뒤에
		//바이러스맵을만듬
		replaceMap(selected[0], selected[1], selected[2]);
		//만든맵으로 바이러스를 퍼트려봄
		int res = virusSpread();
		if (safetyArea < res) safetyArea = res; 
		//바이러스맵을 초기화
		resetVirusMap(selected[0], selected[1], selected[2]);
		return;
	}
	int cursor = selected.empty() ? 0 : selected.back() + 1;
	for (int i = cursor; i < num; i++) {
		selected.push_back(i); //선택한목록에 넣음
		selectWallLoc(num, selected, cnt - 1); //재귀적으로 cnt개를 선택
		selected.pop_back(); //선택한요소를 뺌
	}
}

void replaceMap(int a, int b, int c) { //빈공간a,b,c에 벽을세움
	map[blank[a].first][blank[a].second] = 1; 
	map[blank[b].first][blank[b].second] = 1;
	map[blank[c].first][blank[c].second] = 1;
}

void resetVirusMap(int a, int b, int c) {//a,b,c에 벽을허물고 빈공간으로
	map[blank[a].first][blank[a].second] = 0;
	map[blank[b].first][blank[b].second] = 0;
	map[blank[c].first][blank[c].second] = 0;
}

//방문 배열 초기화
void clear() {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			visited[i][j] = false;

}

//바이러스를 퍼트리고 남은 안전영역크기를 리턴함
int virusSpread() {
	clear();
	int res = blank.size() - 3; //안전영역 크기 : 벽을3개더세웠으므로 -3
	//처음 바이러스위치를 한번에 큐에 넣고 BFS진행
	for (int k = 0; k < virus.size(); k++) {
		int start_x = virus[k].first;
		int start_y = virus[k].second;
		loc.push({ start_x, start_y });
		visited[start_x][start_y] = true;
	}
	//BFS
	while (!loc.empty()) {
		int x = loc.front().first;
		int y = loc.front().second;
		loc.pop();

		for (int dir = 0; dir < 4; dir++) {
			int xx = x + dx[dir];
			int yy = y + dy[dir];

			if (xx < 0 || yy < 0 || xx == n || yy == m) continue; //맵을벗어나면 제외
			if (map[xx][yy] == 1 || map[xx][yy] == 2) continue; //벽, 바이러스를 만나면 제외
			if (!visited[xx][yy]) { //빈공간이고 처음 방문한곳이면 안전영역크기 -1
				visited[xx][yy] = true;
				res--;
				loc.push({ xx, yy }); //이어서 탐색
			}
		}
	}

	return res;
}

void init() {
	scanf("%d%d", &n, &m);
	map = new int* [n];
	visited = new int* [n];
	for (int i = 0; i < n; i++) {
		map[i] = new int[m];
		visited[i] = new int[m];
		for (int j = 0; j < m; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 2) //바이러스 위치 기록
				virus.push_back({ i, j });
			if (map[i][j] == 0) //빈공간 위치 기록
				blank.push_back({ i, j });
		}
	}
}

int main(void) {
	init();
	func();

	return 0;
}