#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
using std::pair; using std::vector; using std::queue;
typedef pair<int, int> pii;
typedef pair<vector<int>, int> pvi;
int t;
vector<pair<pii, pii>> list; //시작, 도착좌표
bool visited[8][8];
int dx[] = { -1, 1, 1, -1 };
int dy[] = { 1, 1, -1, -1 };

void clear();
void printAll(vector<int>& v);
void func();
void init();

void init() {
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		char _[4];
		scanf("%s%s%s%s", &_[0], &_[1], &_[2], &_[3]);
		list.push_back({ {8 - (_[1] - '0'), _[0] - 'A'},
			{8 - (_[4] - '0'), _[3] - 'A'} });

		printf(">> %d,%d  =>  %d,%d\n", list[i].first.first, list[i].first.second, list[i].second.first, list[i].second.second);

	}
	
}

//BFS를 이용
void func() {
	queue<pair<pii, pvi>> loc; //현재좌표x,y와 지나온x,y저장한벡터,이동한갯수
	for (int i = 0; i < t; i++) { //서로 다른색의 칸에 있으면 불가능
		if ((list[i].first.first + list[i].first.second) % 2 !=
			(list[i].second.first + list[i].second.second) % 2) {
			printf("Impossible\n");
			continue;
		}
		clear(); //초기화
		//시작좌표
		int start_x = list[i].first.first;
		int start_y = list[i].first.second;
		visited[start_x][start_y] = true;
		vector<int> _;
		_.push_back(start_x);
		_.push_back(start_y);
		loc.push({ {start_x, start_y}, {_, 0} });

		int end_x = list[i].second.first;
		int end_y = list[i].second.second;
		while (!loc.empty()) {
			int x = loc.front().first.first;
			int y = loc.front().first.second;
			vector<int> v = loc.front().second.first;
			int cnt = loc.front().second.second;
			loc.pop();

			if (x == end_x && y == end_y) { //도착지점에 도달시 종료
				printAll(v);
				while (!loc.empty()) loc.pop(); //큐를 비움
				break;
			}
			
			for (int dir = 0; dir < 4; dir++) {
				int xx = x + dx[dir];
				int yy = y + dy[dir];

				if (xx < 0 || yy < 0 || xx == 8 || yy == 8) continue;
				if (!visited[xx][yy]) {
					visited[xx][yy] = true;
					
					vector<int> vv;
					for (int i = 0; i < v.size(); i++) //복사
						vv.push_back(v[i]);
					vv.push_back(xx);
					vv.push_back(yy);
					loc.push({ {xx, yy}, {vv, cnt+1} });
				}
			}

		}


	}
}

void printAll(vector<int>& v) {
	printf("%d ", v.size() / 2 - 1);
	char c[2];
	for (int i = 0; i < v.size(); i++) {
		if (i % 2 == 0) { 
			c[1] = 8 - v[i] + '0'; //x좌표 기록
		}
		else { 
			c[0] = v[i] + 'A'; //y좌표 기록
			printf("%c %c ", c[0], c[1]);
		}
	}
	printf("\n");
}

void clear() {
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			visited[i][j] = false;
}


int main(void) {
	init();
	func();

	return 0;
}