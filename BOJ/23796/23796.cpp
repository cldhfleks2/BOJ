#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
long map[8][8];
char command;

//L D R U 
int dx[] = { 0, -1, 0, 1 };
int dy[] = { 1, 0, -1, 0 };
void init();
void move(int end_x, int end_y, int dir);
void func();
void printAll();


void init() {
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			scanf("%ld", &map[i][j]);

	scanf("%c", &command); 
	scanf("%c", &command);
}
//dir방향으로 (end_x, end_y)까지 1칸씩 밀음
void move(int end_x, int end_y, int dir) { 
	int x = end_x;
	int y = end_y;
	while (1) {
		int xx = x + dx[dir]; //dir방향의 반대방향 수를
		int yy = y + dy[dir];
		if (xx == -1 || yy == -1 || xx == 8 || yy == 8) {
			map[x][y] = 0; //새로운블럭이 생긴곳
			break; //반복종료
		}
		map[x][y] = map[xx][yy]; //dir방향으로 한칸밀음

		x += dx[dir];
		y += dy[dir];

	}
}

void func() {
	int p1, p2, blankCnt, dir;
	if (command == 'L') { //y++
		dir = 0; 
		for (int k = 0; k < 8; k++) {
			p1 = 7; p2 = 6;
			while (0 <= p1) {
				//1. p1이 빈공간이면
				if (map[k][p1] == 0) {
					p1--; //p1은 다음을 탐색
					p2 = p1 - 1; 
				} //2. p1이 숫자라면
				else {
					//2-1. p1기준 'L'방향으로 탐색을 시작
					//숫자발견시 p2가 해당위치를 가리킴
					for (; 0 <= p2; p2--) if (map[k][p2] != 0) break;

					//2-2. p2와 p1이 붙도록 p1이 당겨짐
					if (p2 + 1 != p1) 
						for (p1 = p1 - 1; p2 + 1 <= p1; p1--)
							move(k, p1, dir);
					else
						p1 = p2; //p2, p1을 같게둠

					//현재 p2 == p1인상태
					
					//2-3-1. p2가 0이라면 맨끝에도달했던것
					if (map[k][p2] == 0) {
						move(k, p2, dir); //p1을 맨끝까지 당기고
						
						break; //다음 k를탐색

					} //2-3-2. p2와 p1이 같은 수라면
					else if (map[k][p2] == map[k][p2 + 1]) {
						move(k, p2, dir); 
						map[k][p2] *= map[k][p2]; //p2를 제곱
						p1--; //바뀐 p2의 L방향으로 p1을 변경 => 한타일이 두번이상 바뀌지않음
						p2 = p1 - 1;

					} //2-3-3. p2와 p1이 다른 수라면
					else if (map[k][p2] != map[k][p1]) {
						p2 = p1 - 1;
					}
					

				}
				printf("===========뭔가 부검==============\n");
				//printAll();
			}
			////앞의 빈공간을 지움
			//blankCnt = 7;
			//while (map[k][0] == 0 && blankCnt > 0) {
			//	move(k, 0, dir);
			//	blankCnt--;
			//}

			printf("========%d 번째========================\n", k);
			printAll();
		}



	}
	else if(command == 'D') { //x--
		dir = 1;
		

	}
	else if (command == 'R') { //y--
		dir = 2;
		

	}
	else if(command == 'U') { //x++
		dir = 3;
		

	}

}

void printAll() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++)
			printf("%ld ", map[i][j]);
		printf("\n");
	}
}

int main(void) {
	init();
	func();
	//printAll();

	return 0;
}