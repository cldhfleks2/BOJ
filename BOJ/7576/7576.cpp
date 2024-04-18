#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
using std::vector; using std::pair; using std::queue;
typedef pair<int, int> pii;
/*
안익은 토마토 : 1
익은 토마토는 : -1
days : 토마토가 모두 익는데 걸리는 날짜
ripeTomato : 1회용, 익은토마토 좌표
unripeTomato : 1회용, 안익은 토마토 좌표
changeTomato : BFS로 탐색후 익혀질 토마토 좌표
*/
int n, m, ** tomato, unripeTomatoCnt, **tomatoDays;
bool** visited;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
vector<pii> ripeTomato, unripeTomato, changeTomato;
queue <pair<pii, int>> loc;
void init();
void becomeRipe();
void func();

void func() {
	init();
	becomeRipe();
}

//익은 토마토를 기준으로 모든 안익은토마토를 익힌다.
//BFS사용하되, 모든 익은 토마토 좌표부터 days를 +1 씩 늘려가며 탐색하는데,
//안익은 토마토를 만날때마다 최솟값을 갱신해야함.
//즉 안익은토마토, 하나의 좌표를 여러번 방문해야하므로,
//방문 check를 하지않고 중복방문함
void becomeRipe() { 
	//처음에 모든 익은토마토좌표를 시작점으로 전부 넣음
	for (int k = 0; k < ripeTomato.size(); k++) { 
		int start_x = ripeTomato[k].first;
		int start_y = ripeTomato[k].second;
		loc.push({ {start_x, start_y}, 1 });
	}

	while (!loc.empty()) {
		int x = loc.front().first.first; //현재위치 (x, y)
		int y = loc.front().first.second;
		int days = loc.front().second;
		loc.pop();

		for (int dir = 0; dir < 4; dir++) { //다음 4방향(우,하,좌,상)
			int xx = x + dx[dir]; //다음위치 (xx, yy)
			int yy = y + dy[dir];
			//비정상 범위면 제외
			if (xx < 0 || yy < 0 || xx == n || yy == m) continue; 
			//익은토마토나 빈공간을 만나면 제외
			if (tomato[xx][yy] == -1 || tomato[xx][yy] == 0) continue;
			//해당위치의 토마토가 가지는 일수는 항상 최솟값이어야함
			if (tomatoDays[xx][yy] > days) { 
				tomatoDays[xx][yy] = days;
				loc.push({ {xx, yy}, days + 1 }); //최솟값을때 탐색을 이어나감
			}
		}

	}

	int res = 0; //최종 일수
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			if (tomatoDays[i][j] == 0x7fffffff) { 
				//안익은 토마토의 일수가 초깃값(0x7fffffff)이면 고립된것이므로
				//문제의 조건에의해 -1 출력
				if (tomato[i][j] == 1) { 
					printf("-1");
					return;
				}
			}
			else {
				if (res < tomatoDays[i][j]) //최솟값을 찾아감
					res = tomatoDays[i][j]; 
			}

		}
	
	printf("%d", res);
}

void init() {
	scanf("%d%d", &m, &n);
	tomato = new int* [n];
	visited = new bool* [n];
	tomatoDays = new int* [n];
	for (int i = 0; i < n; i++) {
		tomato[i] = new int[m];
		visited[i] = new bool[m];
		tomatoDays[i] = new int[m];
		for (int j = 0, _; j < m; j++) {
			scanf("%d", &_);
			if (_ == 1) {
				tomato[i][j] = -1; //익은것
				ripeTomato.push_back({ i, j });
			}
			else if (_ == 0) {
				tomato[i][j] = 1; //안익은것
				unripeTomato.push_back({ i, j });
				unripeTomatoCnt++; //안익은토마토갯수셈
			}
			else if(_ == -1)
				tomato[i][j] = 0; //빈공간

			tomatoDays[i][j] = 0x7fffffff; //최댓값으로 초기화
		}
	}

}


int main(void) {
	func();
	return 0;
}