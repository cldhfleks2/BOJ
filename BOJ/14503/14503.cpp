#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
using namespace std;
int N, M, **house;
int r, c, d; //로봇위치,  방향 0)북 1)동 2)남 3)서
/*
0 : 청소하지않은공간
1 : 벽
2 : 청소함
*/
void clean(); //함수원형들
int cd(int dir);
int next(int dir);
void move(int dir);
bool f();

void clean() { //현재 로봇위치를 청소
	if (house[r][c] != 2) {
		house[r][c] = 2; 
	}
}

bool f() { //사방이 전부 막혔는가
	if(next(d) != 0 &&
		next(cd(d)) != 0 &&
		next(cd(cd(d))) != 0 &&
		next(cd(cd(cd(d)))) != 0) {
		return true;
	}
	return false;
}

int cd(int dir) { //방향전환(반시계방향으로-왼쪽)
	dir--;
	if (dir == -1) dir = 3;
	return dir;
}
//dir방향 1칸앞에 무엇이있는가
int next(int dir) { 
	//0) 청소하지않은공간
	//1) 벽(이동불가, 배열범위를벗어난경우도 포함)
	//2) 청소한공간
	int now_r = r, now_c = c;
	if (dir == 0) {
		now_r--; //북
	}
	else if (dir == 1) {
		now_c++; //동
	}
	else if (dir == 2) {
		now_r++; //남
	}
	else if (dir == 3) {
		now_c--; //서
	}
	if (now_r < 0 || now_r == N ||
		now_c < 0 || now_c == M) {
		return 1; //이동불가능한곳은 벽으로생각함
	}
	return house[now_r][now_c]; //상태(0,1,2)를 출력
}

//실제로 dir방향으로 움직이는 함수
void move(int dir) { 
	int now_r = r, now_c = c;
	if (dir == 0) {
		now_r--; //북
	}
	else if (dir == 1) {
		now_c++; //동
	}
	else if (dir == 2) {
		now_r++; //남
	}
	else if (dir == 3) {
		now_c--; //서
	}
	r = now_r; //실제위치 기록
	c = now_c;
}

void robot() {
	while (true) {
		clean(); //현재위치청소

		int dir = cd(d); //왼쪽으로 한번돈다.
		if (next(dir) == 0) {
			//청소하지않은공간이라면
			move(dir);
			d = dir;
			continue;
		}

		if (f()) { //사방이막힌경우
			dir = cd(cd(d)); //두번돌리면 후진방향
			if (next(dir) == 1) {
				//뒤가 벽이었다면 후진불가하니 종료
				return;
			}
			else {
				//후진가능하면
				move(dir); //후진
				continue;
			}
		}
		//벽이나 청소한곳이라면 방향만전환
		d = dir;
	}
}

void printAll() { //청소한 총 면적을 출력
	int res=0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (house[i][j] == 2)
				res++;
	printf("%d", res);
}

int main(void) {
	scanf("%d%d", &N, &M);

	house = new int*[N];
	for (int i = 0; i < N; i++)
		house[i] = new int[M]; //맵생성

	scanf("%d%d%d", &r, &c, &d);
	for(int i = 0 ; i < N ; i++) //맵기록
		for (int j = 0, temp=0; j < M; j++) {
			scanf("%d", &temp);
			house[i][j] = temp;
		}
	robot();

	printAll();
	return 0;
}