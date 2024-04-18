#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
using std::vector; using std::pair; using std::queue;
typedef pair<int, int> pii;
int x, y, end_x, end_y, n, ***map, **cost;
int max_x = 0, max_y = 0;
bool** visited;
struct obstacle {
	pii p1; pii p2; pii p3; pii p4;
};
int dx[5] = { 0, 0, 1, 0, -1 }; //X, 우, 하, 좌, 상
int dy[5] = { 0, 1, 0, -1, 0 }; //X, 우, 하, 좌, 상 

vector<obstacle> obstacleList;



void DEBUG1();
void DEBUG2();
void placeObstacle(pii p1, pii p2, pii p3, pii p4);
void input();
void makeMAP();
void findMAPSIZE(pii p1, pii p2, pii p3, pii p4);

//로봇 이동하는 함수
void func() {
	
	//<<x, y>, <dir, res>> 
	//dir:이전방향 res:턴한횟수
	//꼭짓점에서의 map[][][0]과 map[][][1] 은 각각 -1 ~ -4
	queue<pair<pii, pii>> move; 
	move.push({ { x,y }, {0, 0} }); 
	cost[x][y] = 0;
	
	while (!move.empty()) {
		int xx = move.front().first.first;
		int yy = move.front().first.second;
		int dir = move.front().second.first;
		int res = move.front().second.second;
		//꺼낸것은 삭제
		move.pop(); 

		//종료조건
		// if (xx == end_x && yy == end_y) continue;

		//다음 위치를 큐에 넣는다.
		if (map[xx][yy][0] <= 0 && map[xx][yy][1] <= 0) { //빈공간과 장애물꼭짓점에 위치한경우
			for (int i = 1; i <= 4; i++) { //나아갈 방향
				int next_x = xx + dx[i];
				int next_y = yy + dy[i];
				int next_dir = i; 
				//맵을 벗어나면 제외
				if (next_x <= 0 || next_y <= 0 || max_x <= next_x || max_y <= next_y) continue;
				// 출발점외에 이전방향과 다음 방향이 다르다면 턴횟수 +1
				int next_res = res;
				if (dir != 0 && dir != next_dir)
					next_res += 1;
				if (cost[next_x][next_y] >= next_res) { //최소비용이면 저장
					cost[next_x][next_y] = next_res;
					//큐에 추가
					move.push({ {next_x, next_y}, {next_dir, next_res} });
					//printf(">> 빈 %d,%d %d:%d\n", next_x, next_y, next_dir, next_res);
				}

			}
		}
		else { //장애물벽따라 움직이는경우
			for (int k = 0; k <= 1; k++) { //가능한 두방향으로 탐색을 이어나감
				int next_dir = map[xx][yy][k];
				int next_x = xx + dx[next_dir];
				int next_y = yy + dy[next_dir];
				
				//맵을 벗어나면 제외
				if (next_x <= 0 || next_y <= 0 || max_x <= next_x || max_y <= next_y) continue;
				int next_res = res;
				if (dir != next_dir) next_res += 1;
				if (cost[next_x][next_y] >= next_res) {
					cost[next_x][next_y] = next_res;
					move.push({ {next_x, next_y}, {next_dir, next_res} });
					//printf(">> 벽 %d,%d %d:%d\n", next_x, next_y, next_dir, next_res);
				}
			}

		}


	}
	//최솟값 출력
	printf("%d", cost[end_x][end_y]); 

	//DEBUG1();
}

//맵상태를 출력하는 함수
void DEBUG1() { //출력용
	printf(">>>>>>>>>>>>맵 \n");
	for (int i = 0; i < max_x; i++) {
		for (int j = 0; j < max_y; j++) {
			if (i == x && j == y) {
				printf("O");
				continue;
			}
			if (i == end_x && j == end_y) {
				printf("X");
				continue;
			}
			if (map[i][j][0] == 0 && map[i][j][1] == 0) {
				printf(".");
			}
			else if (map[i][j][0] == -1 && map[i][j][1] == -2) {
				printf("┌");
			}
			else if (map[i][j][0] == -2 && map[i][j][1] == -3) {
				printf("┐");
			}
			else if (map[i][j][0] == -3 && map[i][j][1] == -4) {
				printf("┘");
			}
			else if (map[i][j][0] == -1 && map[i][j][1] == -4) {
				printf("└");
			}
			else if (map[i][j][0] == 1 && map[i][j][1] == 3) {
				printf("─");
			}
			else if (map[i][j][0] == 2 && map[i][j][1] == 4) {
				printf("│");
			}
		}
		printf("\n");
	}

	printf(">>>>>>>>>>>>cost \n");
	for (int i = 0; i < max_x; i++) {
		for (int j = 0; j < max_y; j++)
			if (i == 0 || j == 0)
				printf("  X");
			else if (i == end_x && j == end_y)
				printf(" !%d", cost[i][j]);
			else if (i == x && j == y)
				printf(" !%d", cost[i][j]);
			else
				printf("%3d", cost[i][j]);
		printf("\n");
	}
}

//맵에 장애물을 설치하는 함수
void placeObstacle(pii p1, pii p2, pii p3, pii p4) {
	int type = -1; 
	int p1x = p1.first, p1y = p1.second;
	int p2x = p2.first, p2y = p2.second;
	int p3x = p3.first, p3y = p3.second;
	int p4x = p4.first, p4y = p4.second;
	int p11x, p11y, p33x, p33y;
	pii p11, p33;

	if (p2x < p4x && p2y < p4y)
		type = 1; // 1┌
	else if (p2x < p4x && p4y < p2y)
		type = 2; // 2 ┐
	else if (p4x < p2x && p2y < p4y)
		type = 3; // 3└
	else if (p4x < p2x && p4y < p2y)
		type = 4; // 4 ┘
	
	if (type == 1) {
		p11 = { p4x, p1y }; p33 = { p3x, p4y };
		p11x = p11.first, p11y = p11.second; 
		p33x = p33.first, p33y = p33.second;
		//p2 -> p1 : y +
		for (int i = p2y; i < p1y; i++) {
			if (i == p2y) { //꼭짓점
				map[p2x][i][0] = -1; map[p2x][i][1] = -2; continue;
			}
			map[p2x][i][0] = 1; map[p2x][i][1] = 3;
		}
		//p1 -> p11 : x +
		for (int i = p1x; i < p11x; i++) {
			if (i == p1x) {
				map[i][p1y][0] = -2; map[i][p1y][1] = -3; continue;
			}
			map[i][p1y][0] = 2; map[i][p1y][1] = 4; 
		}
		//p11 -> p4 : y -
		for (int i = p11y; i > p4y; i--) {
			if (i == p11y) {
				map[p11x][i][0] = -3; map[p11x][i][1] = -4; continue;
			}
			map[p11x][i][0] = 1; map[p11x][i][1] = 3;
		}
		//p4 -> p33 : x +
		for (int i = p4x; i < p33x; i++) {
			if (i == p4x) {
				map[i][p4y][0] = -1; map[i][p4y][1] = -2; continue;
			}
			map[i][p4y][0] = 2; map[i][p4y][1] = 4;
		}
		//p33 -> p3 : y -
		for (int i = p33y; i > p3y; i--) {
			if (i == p33y) {
				map[p33x][i][0] = -3; map[p33x][i][1] = -4; continue;
			}
			map[p33x][i][0] = 1; map[p33x][i][1] = 3;
		}
		//p3 -> p2 : x -
		for (int i = p3x; i > p2x; i--) {
			if (i == p3x) {
				map[i][p3y][0] = -1; map[i][p3y][1] = -4; continue;
			}
			map[i][p3y][0] = 2; map[i][p3y][1] = 4;
		}
	}
	else if (type == 2) {
		p11 = { p1x, p4y }; p33 = { p4x, p3y };
		p11x = p11.first, p11y = p11.second;
		p33x = p33.first, p33y = p33.second;
		//p2 -> p1 : x +
		for (int i = p2x; i < p1x; i++) {
			if (i == p2x) {
				map[i][p2y][0] = -2; map[i][p2y][1] = -3; continue;
			}
			map[i][p2y][0] = 2; map[i][p2y][1] = 4;
		}
		//p1 -> p11 : y -
		for (int i = p1y; i > p11y; i--) {
			if (i == p1y) {
				map[p1x][i][0] = -3; map[p1x][i][1] = -4; continue;
			}
			map[p1x][i][0] = 1; map[p1x][i][1] = 3;
		}
		//p11 -> p4 : x -
		for (int i = p11x; i > p4x; i--) {
			if (i == p11x) {
				map[i][p11y][0] = -1; map[i][p11y][1] = -4; continue;
			}
			map[i][p11y][0] = 2; map[i][p11y][1] = 4;
		}
		//p4 -> p33 : y -
		for (int i = p4y; i > p33y; i--) {
			if (i == p4y) {
				map[p4x][i][0] = -2; map[p4x][i][1] = -3; continue;
			}
			map[p4x][i][0] = 1; map[p4x][i][1] = 3;
		}
		//p33 -> p3 : x -
		for (int i = p33x; i > p3x; i--) {
			if (i == p33x) {
				map[i][p33y][0] = -1; map[i][p33y][1] = -4; continue;
			}
			map[i][p33y][0] = 2; map[i][p33y][1] = 4;
		}
		//p3 -> p2 : y +
		for (int i = p3y; i < p2y; i++) {
			if (i == p3y) {
				map[p3x][i][0] = -1; map[p3x][i][1] = -2; continue;
			}
			map[p3x][i][0] = 1; map[p3x][i][1] = 3;
		}
	}
	else if (type == 3) {
		p11 = { p1x, p4y }; p33 = { p4x, p3y };
		p11x = p11.first, p11y = p11.second;
		p33x = p33.first, p33y = p33.second;
		//p2 -> p1 : x -
		for (int i = p2x; i > p1x; i--) {
			if (i == p2x) {
				map[i][p2y][0] = -1; map[i][p2y][1] = -4; continue;
			}
			map[i][p2y][0] = 2; map[i][p2y][1] = 4;
		}
		//p1 -> p11 : y +
		for (int i = p1y; i < p11y; i++) {
			if (i == p1y) {
				map[p1x][i][0] = -1; map[p1x][i][1] = -2; continue;
			}
			map[p1x][i][0] = 1; map[p1x][i][1] = 3;
		}
		//p11 -> p4 : x +
		for (int i = p11x; i < p4x; i++) {
			if (i == p11x) {
				map[i][p11y][0] = -2; map[i][p11y][1] = -3; continue;
			}
			map[i][p11y][0] = 2; map[i][p11y][1] = 4;
		}
		//p4 -> p33 : y +
		for (int i = p4y; i < p33y; i++) {
			if (i == p4y) {
				map[p4x][i][0] = -1; map[p4x][i][1] = -4; continue;
			}
			map[p4x][i][0] = 1; map[p4x][i][1] = 3;
		}
		//p33 -> p3 : x +
		for (int i = p33x; i < p3x; i++) {
			if (i == p33x) {
				map[i][p33y][0] = -2; map[i][p33y][1] = -3; continue;
			}
			map[i][p33y][0] = 2; map[i][p33y][1] = 4;
		}
		//p3 -> p2 :  y -
		for (int i = p3y; i > p2y; i--) {
			if (i == p3y) {
				map[p3x][i][0] = -3; map[p3x][i][1] = -4; continue;
			}
			map[p3x][i][0] = 1; map[p3x][i][1] = 3;
		}
	}
	else if (type == 4) {
		p11 = { p4x, p1y }; p33 = { p3x, p4y };
		p11x = p11.first, p11y = p11.second;
		p33x = p33.first, p33y = p33.second;
		//p2 -> p1 : y -
		for (int i = p2y; i > p1y; i--) {
			if (i == p2y) {
				map[p2x][i][0] = -3; map[p2x][i][1] = -4; continue;
			}
			map[p2x][i][0] = 1; map[p2x][i][1] = 3;
		}
		//p1 -> p11 : x -
		for (int i = p1x; i > p11x; i--) {
			if (i == p1x) {
				map[i][p1y][0] = -1; map[i][p1y][1] = -4; continue;
			}
			map[i][p1y][0] = 2; map[i][p1y][1] = 4;
		}
		//p11 -> p4 : y +
		for (int i = p11y; i < p4y; i++) {
			if (i == p11y) {
				map[p11x][i][0] = -1; map[p11x][i][1] = -2; continue;
			}
			map[p11x][i][0] = 1; map[p11x][i][1] = 3;
		}
		//p4 -> p33 : x -
		for (int i = p4x; i > p33x; i--) {
			if (i == p4x) {
				map[i][p4y][0] = -3; map[i][p4y][1] = -4; continue;
			}
			map[i][p4y][0] = 2; map[i][p4y][1] = 4;
		}
		//p33 -> p3 : y +
		for (int i = p33y; i < p3y; i++) {
			if (i == p33y) {
				map[p33x][i][0] = -1; map[p33x][i][1] = -2; continue;
			}
			map[p33x][i][0] = 1; map[p33x][i][1] = 3;
		}
		//p3 -> p2 : x +
		for (int i = p3x; i < p2x; i++) {
			if (i == p3x) {
				map[i][p3y][0] = -2; map[i][p3y][1] = -3; continue;
			}
			map[i][p3y][0] = 2; map[i][p3y][1] = 4;
		}
	}
	
}

//모든 입력받는 함수
void input() {
	scanf("%d%d%d%d%d", &x, &y, &end_x, &end_y, &n);
	findMAPSIZE({ x, y }, { end_x, end_y }, { 0, 0 }, { 0, 0 }); //출발,도착좌표도 계산
	
	//입력받음
	for (int i = 0; i < n; i++) { 
		pii p1, p2, p3, p4;
		scanf("%d%d%d%d%d%d%d%d", &p1.first, &p1.second,
			&p2.first, &p2.second, &p3.first, &p3.second,
			&p4.first, &p4.second);
		obstacle obs = { p1, p2, p3, p4 };
		obstacleList.push_back(obs); //장애물 리스트에 추가
		findMAPSIZE(p1, p2, p3, p4); //맵사이즈 결정
	}
	
	makeMAP();

	for (int i = 0; i < obstacleList.size(); i++) //모든 장애물을 설치
		placeObstacle(obstacleList[i].p1, obstacleList[i].p2, 
			obstacleList[i].p3, obstacleList[i].p4);
}

//맵을 생성(초기화)하는 함수
void makeMAP() {
	max_x++; //실제좌표는 0,0 부터시작이므로 +1
	max_y++;
	//map[x좌표][y좌표] => [2] 두가지값(이동가능한 방향)을 가짐
	//초깃값은 모두 0 으로 설정
	map = new int** [max_x];
	for (int i = 0; i < max_x; i++) {
		map[i] = new int* [max_y];
		for (int j = 0; j < max_y; j++) {
			map[i][j] = new int[2];
			map[i][j][0] = 0;
			map[i][j][1] = 0;
		}
	}
	//cost 초기화 -> 최소비용을 출력하기위해 최댓값으로 초기화
	cost = new int* [max_x];
	for (int i = 0; i < max_x; i++) {
		cost[i] = new int[max_y];
		for (int j = 0; j < max_y; j++)
			cost[i][j] = 0x7fffffff;
	}
	//visited 초기화
	visited = new bool* [max_x];
	for (int i = 0; i < max_x; i++) {
		visited[i] = new bool[max_y];
		for (int j = 0; j < max_y; j++)
			visited[i][j] = false;
	}
	
}

//맵의 최대크기를 결정하는 함수
void findMAPSIZE(pii p1, pii p2, pii p3, pii p4) {
	//max_x
	if (max_x < p1.first) max_x = p1.first;
	if (max_x < p2.first) max_x = p2.first;
	if (max_x < p3.first) max_x = p3.first;
	if (max_x < p4.first) max_x = p4.first;
	//max_y
	if (max_y < p1.second) max_y = p1.second;
	if (max_y < p2.second) max_y = p2.second;
	if (max_y < p3.second) max_y = p3.second;
	if (max_y < p4.second) max_y = p4.second;
}

int main(void) {
	input();
	func();

	return 0;
}

