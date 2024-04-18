#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
using std::vector; using std::queue; using std::pair;
int dxy[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
/*
X Y : 상어 좌표(실시간)
S : 상어크기
E : 상어가 먹은 물고기갯수
cnt : 크기가1~6 인 물고기의 갯수를 기록
크기별 물고기갯수를 카운트해놓음 >> cnt

1. 현재상어크기보다 작은 물고기가 없으면 프로그램종료
2. 현재맵에서find
	> 만약 불가능하면 BFS하며 쓰인 시간은 더하지않고 프로그램 종료
3. BFS진행에 들인 시간을 더함
*/ 
int N, map[20][20], X, Y, S = 2, E, cnt[7];

void init() {
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		for (int j = 0, in; j < N; j++) {
			scanf("%d", &in);
			if (in == 9) { //상어위치는 맵에 기록하지않음
				X = i; Y = j;
				continue;
			}
			map[i][j] = in; //물고기 위치를 맵에 기록
			if(1 <= in || in <= 6) {
				cnt[in]++; //물고기 크기별 갯수를 셈
			}
		}
	}
}

/*
BFS진행하며 물고기를 먹으러가서
불가능하다면 -1을 리턴
가능하다면 BFS에 들인 시간을 리턴
*/
struct loc{ //물고기의 위치, 탐색에 쓰인 시간을 기록하는 컨테이너
	int x, y, t; 
};
bool comp(const loc& l1, const loc& l2) { //loc는 x가작고 y가 작은것순으로 정렬된다.
	if (l1.x < l2.x)
		return true;
	else if (l1.x == l2.x)
		return l1.y < l2.y;
	else
		return false;
}

int find() {
	 queue<loc> q;
	 q.push({ X, Y, 0});
	 bool visited[20][20] = { false, };
	 visited[X][Y] = true;

	 int max = 0x7fffffff; //BFS하며 찾을 물고기의 최대 거리
	 vector<loc> list;

	 while (!q.empty()) {
		 int cx = q.front().x;
		 int cy = q.front().y;
		 int ct = q.front().t;
		 q.pop();
		 if (max < ct) continue;

		 if (0 < map[cx][cy] && map[cx][cy] < S) {  //크기가 작은 물고기를 찾은 경우
			 max = ct; //찾을 물고기의 최대거리를 변경
			 list.push_back({ cx, cy, ct }); //기록
		 }

		 for (int dir = 0; dir < 4; dir++) {
			 int nx = cx + dxy[dir][0];
			 int ny = cy + dxy[dir][1];
			 int nt = ct + 1;

			 if (nx < 0 || ny < 0 || nx == N || ny == N || visited[nx][ny]) continue;
			 if (map[nx][ny] > S) continue; //상어크기보다 큰 물고기는 지나갈 수 없다.
			 visited[nx][ny] = true;

			 q.push({ nx, ny, nt});
		 }
	 }

	 if (list.size() == 0)	return -1; //불가능 -1리턴

	 std::sort(list.begin(), list.end(), comp); //x좌표, y좌표순으로 작은것이 먼저 오도록 정렬
	 int x = list[0].x;
	 int y = list[0].y;
	 int t = list[0].t;
	 map[x][y] = 0; //물고기를 먹는다.
	 cnt[map[x][y]]--; //세놓은 물고기 갯수 -1
	 X = x; //상어 위치 이동 
	 Y = y;
	 E++;
	 if (E == S) { //상어가 크기만큼 물고기를 먹으면 크기+1
		 S++;
		 E = 0;
	 }

	 return t; //걸린 시간을 리턴

}

//프로그램 메인
void logic() {
	int res = 0;
	while (1) {
		int end = false;
		for(int i = 1 ; i < S ; i++) 
			if (cnt[i]) { 
				end = true;
				break;
			}

		//상어가 먹을수있는 물고기가 없으면 프로그램종료
		if (!end) break;
		int time = find(); //상어가 물고기를 찾는다.
		if (time == -1) break; //물고기를 못찾았으면 프로그램종료

		res += time; //걸린 시간을 기록
	}

	printf("%d", res);
}

int main(void) {
	init();
	logic();

	return 0;
}