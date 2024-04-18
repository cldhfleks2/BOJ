#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>

//map
//빈공간 : 0
//아래방향 좀비 : 2
//위방향 좀비 : 3
//x : 아리의 행 인덱스 y : 아리의 열 인덱스
//moveMap : 좀비가 이동할때 잠시 기록하는 버퍼 역할
int n, x=0, y=0, **map, **moveMap, cnt=0; 
//button : 스위치 위치 기록 light : 불빛이 비추는 곳 기록
bool **button, **light; 
char c[51]; //아리가 움직일 명령

//아리가 좀비랑 마주치면 true리턴
bool action() { //해당위치에서의 행동을 실행
	//1. 형광등확인
	//현재위치에 스위치가있다면
	if (button[x][y]) {
		light[x][y] = true; //현재위치를 밝힘
		//유효한범위의 불을 밝힘
		if (y >= 1) light[x][y - 1] = true;
		if (x >= 1 && y >= 1) light[x - 1][y - 1] = true;
		if (x >= 1) light[x - 1][y] = true;
		if (x >= 1 && y <= n - 2) light[x - 1][y + 1] = true;
		if (y <= n - 2) light[x][y + 1] = true;
		if (x <= n - 2 && y <= n - 2) light[x + 1][y + 1] = true;
		if (x <= n - 2) light[x + 1][y] = true;
		if (x <= n - 2 && y >= 1) light[x + 1][y - 1] = true;

		button[x][y] = false; //현재 스위치 삭제
	}
	
	//2. 현재위치 좀비확인 
	//불이 꺼져있던경우에 좀비랑 마주쳤다면
	if (!light[x][y] && (map[x][y] == 2 || map[x][y] == 3)) { 
		printf("Aaaaaah!");
		return true;
	}

	//3-1. 좀비 이동 (1)
	//moveMap에 복사
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 2) { //아래방향 좀비일때
				if (i + 1 <= n - 1) { //유효한가?
					moveMap[i + 1][j] = 2; //좀비 이동
				}
				else { //벽에닿은경우 (유효하지않은경우)
					moveMap[i][j] = 3; //180도 방향전환
				}
			}
			else if (map[i][j] == 3) { //위방향 좀비일때
				if (i - 1 >= 0) {
					moveMap[i - 1][j] = 3; 
				}
				else { 
					moveMap[i][j] = 2;
				}
			}
		}
	}
	//3-2. 좀비이동 (2)
	//기존 map에서 좀비위치들만 전부 삭제
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (map[i][j] == 2 || map[i][j] == 3)
				map[i][j] = 0;

	//3-3. 좀비이동 (3)
	//복사한 moveMap에서 map으로 복사, moveMap 초기화
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (moveMap[i][j] == 2 || moveMap[i][j] == 3) {
				map[i][j] = moveMap[i][j]; //복사
				moveMap[i][j] = 0; //초기화
			}

	//4. 좀비이동후 다시 아리가 잡혔는지 확인 
	if (!light[x][y] && (map[x][y] == 2 || map[x][y] == 3)) {
		printf("Aaaaaah!");
		return true;
	}
	
	return false;
}

//아리가 좀비랑 마주쳤다면 true리턴
bool playGame() {
	//아래 1   왼쪽 2   위 3   오른쪽 4
	int view_dir = 1; 
	for (int i = 0; i < cnt; i++) {
		char order = c[i];
		if (order == 'F') {
			if (view_dir == 1) {
				if (x + 1 < n) //이동가능한경우만
					x++;
			}
			else if (view_dir == 2) {
				if (y - 1 > -1) 
					y--;
			}
			else if (view_dir == 3) {
				if (x - 1 > -1) 
					x--;
			}
			else if (view_dir == 4) {
				if (y + 1 < n) 
					y++;
			}
		}
		else if (order == 'L') { //왼쪽으로 방향을 튼다
			view_dir--;
			if (view_dir == 0)
				view_dir = 4;
		}
		else if (order == 'R') { //오른쪽으로 방향을 튼다
			view_dir++;
			if (view_dir == 5)
				view_dir = 1;
		}

		//행동을 함
		if (action()) //만약 기절했다면 게임종료
			return true;
	}

	return false;
}

int main(void) {
	scanf("%d%s", &n, &c);
	map = new int* [n]; //맵
	moveMap = new int* [n];
	light = new bool* [n]; //형광등맵
	button = new bool* [n]; //스위치 위치 기록
	for (int i = 0; i < n; i++) {
		map[i] = new int[n];
		moveMap[i] = new int[n];
		light[i] = new bool[n];
		button[i] = new bool[n];
		char temp[16];
		scanf("%s", &temp);
		for (int j = 0; j < n; j++) {
			moveMap[i][j] = 0;
			light[i][j] = false;
			button[i][j] = false;
			if (temp[j] == 'O') { //빈공간
				map[i][j] = 0;
			}
			else if (temp[j] == 'S') { //형광등
				button[i][j] = true;;
			}
			else if (temp[j] == 'Z') { //좀비
				map[i][j] = 2; //처음엔 모두 아래를 보고있다.
			}
		}
	}

	//명령어의 총갯수를 셈
	for (int i = 0; i < 51; i++) 
		if (c[i] == '\0')
			break;
		else
			cnt++;

	if (!playGame()) //아리가 좀비를피해 살아남았다면 false리턴
		printf("Phew...");


	return 0;
}