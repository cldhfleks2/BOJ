#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
//매번 order리스트를 탐색하며, 이동에 걸림돌이되는가 확인
//가능하면 현재 정보를 order에 추가, 현재위치 x, y, 방향dir을 갱신
using std::vector; using std::pair;
typedef pair<long, long> pll;
long x, y, dir = 1; //뱀 위치, 방향(1:우  2:하  3:좌  4:상//
//시작위치<x1, y1> 에서 방향과 거리<dir, distance>만큼 이동을 기록
vector<pair<pll, pll>> order, die; 
long L, N;
long long t=0;
long left=-1, right, up=-1, down; //4방향 벽
long dx[5] = {0, 0, 1, 0, -1};
long dy[5] = {0, 1, 0, -1, 0};

bool isRight(long x, long y, long dir, long distance);
void nextDir();
void move(long distance);
void saveOrder(long x, long y, long dir, long distance);
void calculate(long distance);

//프로그램의 메인부분
void snakeMOVE() {
	if (N == 0) { //N이 0 이더라도 한번 입력받아야하고, 오른쪽 벽 끝까지 뱀이 나아간다.
		long distance;
		scanf("%ld", &distance);

		printf("%d", right - x);
		return;
	}

	while (N--) {
		long distance; //이동할거리
		scanf("%ld", &distance);

		if (!isRight(x, y, dir, distance)) { //이동이 불가능하면
			calculate(distance); //출력후
			return; //프로그램 종료
		}

		saveOrder(x, y, dir, distance);
		move(distance);
		nextDir();
	}

	//모든 입력을 받은후 에도 부딪히지 않고 생존했다면
	long distance; //현재 바라보는 방향으로 이동할 수 있는 거리(벽이나 몸통까지의 거리)
	if (dir == 1)
		distance = right - y - 1; //벽에 부딪히기 전까지감
	else if (dir == 2)
		distance = down - x - 1;
	else if (dir == 3)
		distance = y - left - 1;
	else if (dir == 4)
		distance = x - up - 1;
	if (!isRight(x, y, dir, distance)) {
		calculate(distance);
	}
	else {
		t += distance + 1; //현재방향대로 이동후 숨을 거두게됨
		printf("%lld", t);
	}

	return;
}

//뱀이 현재방향으로 이동시 몇초뒤에 사망하는지 출력하는 함수
//이미 isRight함수에서 die 벡터에 추가시에,
//x좌표, y좌표 둘다 비교했으므로
//이 함수에서는 x좌표, y좌표중 하나만 비교해도 됨.
void calculate(long distance) {
	long long min = 0x7fffffffffffffff; //long long 최댓값
	if (die.size() == 0) { //맵밖으로 벗어난경우
		//min값을 맵밖으로 벗어나는데 까지 걸리는 시간으로 계산
		if (dir == 1)
			min = right - y;
		else if (dir == 2)
			min = down - x;
		else if (dir == 3)
			min = y - left;
		else if (dir == 4)
			min = x - up;
	}
	//뱀이 이동하다가 기존 궤적에 부딪히는 최소 거리(시간)을 계산
	for (int i = 0; i < die.size(); i++) { 
		long ox = die[i].first.first;
		long oy = die[i].first.second;
		long odir = die[i].second.first;
		long odis = die[i].second.second;
		long temp = 0;
		if (dir == 1) { 
			if (odir == 1 || odir == 2 || odir == 4) temp = oy - y;
			if (odir == 3) temp = ( oy + dy[odir]*odis ) - y;
		}
		else if (dir == 2) {
			if (odir == 2 || odir == 1 || odir == 3) temp = ox - x;
			if (odir == 4) temp = (ox + dx[odir] * odis) - x;
		}
		else if (dir == 3) {
			if (odir == 3 || odir == 2 || odir == 4) temp = y - oy;
			if (odir == 1) temp = y - (oy + dy[odir] * odis);
		}
		else if (dir == 4) {
			if (odir == 4 || odir == 1 || odir == 3) temp = x - ox;
			if (odir == 2) temp = x - (ox + dx[odir] * odis);
		}

		if (min > temp) {
			min = temp; //최소시간 계산
		}
	}

	//출력하는부분
	printf("%lld", min + t);
	
}

//뱀의 이동궤적을 order에 저장하는 함수
void saveOrder(long x, long y, long dir, long distance) {
	pll p1 = { x, y }, p2 = { dir, distance };
	order.push_back({ p1, p2 });
}

//입력받은 거리(시간)만큼 뱀을 이동시키는 함수
void move(long distance) {
	x += dx[dir] * distance;  //현재 위치 이동
	y += dy[dir] * distance;

	//이동후 시간 t 증가
	t += distance;
}

//뱀머리 방향을 입력받아 설정하는 함수
void nextDir() {
	char d;
	scanf("%c%c", &d, &d);
	if (d == 'L')
		dir--;
	else if (d == 'R')
		dir++;
	if (dir == 0)
		dir = 4;
	if (dir == 5)
		dir = 1;
	scanf("%c", &d); //줄바꿈문자 지움
}

//뱀머리가 이동가능 한지 확인하는 함수
//불가능하다면 die 벡터에 불가능한 뱀의 이동 궤적(order[i])을 추가
bool isRight(long x, long y, long dir, long distance) { 
	bool res = true; 
	long xx = x + dx[dir] * distance; //다음 위치
	long yy = y + dy[dir] * distance;

	//맵밖으로 벗어나는지 확인
	if (yy <= left || right <= yy ||
		xx <= up || down <= xx)
		return false;

	//기존 뱀의 이동궤적과 부딪히는지 확인
	for (int i = 0; i < order.size(); i++) { 
		if (i == order.size() - 1) continue; //바로 직전의 뱀이 움직인 궤적은 제외
		long ox = order[i].first.first;
		long oy = order[i].first.second;
		long odir = order[i].second.first;
		long odis = order[i].second.second;
		if (dir == 1) {
			if (odir == 1 && x == ox) //x→ o→
				if (y <= oy && oy <= yy) { res = false; die.push_back(order[i]);  }
			if (odir == 3 && x == ox) //x→ ←o
				if (y <= oy + dy[odir]*odis && oy + dy[odir] * odis <= yy) { res = false; die.push_back(order[i]);  }
			//y좌표가 서로 교차하는가? 
			if (y <= oy && oy <= yy) { //x→ |o
				//x좌표가 서로 교차하는가?
				if (odir == 2 && ox <= x && x <= ox + dx[odir] * odis) { res = false; die.push_back(order[i]);  }
				if (odir == 4 && ox + dx[odir] * odis <= x && x <= ox) { res = false; die.push_back(order[i]);  }
			}
		}
		else if (dir == 2) {
			if (odir == 2 && y == oy) //x↓
									  //o↓
				if (x <= ox && ox <= xx) { res = false; die.push_back(order[i]);  }
			if (odir == 4 && y == oy) //x↓
									  //o↑
				if (x <= ox + dx[odir]*odis && ox + dx[odir] * odis <= xx) { res = false; die.push_back(order[i]);  }
			//x좌표가 서로 교차하는가?
			if (x <= ox && ox <= xx) { //x↓
									   //oㅡ
				//y좌표가 서로 교차하는가?
				if (odir == 1 && oy <= y && y <= oy + dy[odir] * odis) { res = false; die.push_back(order[i]);  }
				if (odir == 3 && oy + dy[odir] * odis <= y && y <= ox) { res = false; die.push_back(order[i]);  }
			}
		}
		else if (dir == 3) {
			if (odir == 3 && x == ox) //o← ←x
				if (yy <= oy && oy <= y) { res = false; die.push_back(order[i]);  }
			if (odir == 1 && x == ox) //o→ ←x
				if (yy <= oy + dy[odir] * odis && oy + dy[odir]*odis <= y) { res = false; die.push_back(order[i]);  }
			//y좌표가 서로 교차하는가?
			if (yy <= oy && oy <= y) { //o| ←x 
				//x좌표가 서로 교차하는가?
				if (odir == 2 && ox <= x && x <= ox + dx[odir] * odis) { res = false; die.push_back(order[i]);  }
				if (odir == 4 && ox + dx[odir] * odis <= x && x <= ox) { res = false; die.push_back(order[i]);  }
			}
		}
		else if (dir == 4) {
			if (odir == 4 && y == oy) //o↑
									  //x↑
				if (xx <= ox && ox <= x) { res = false; die.push_back(order[i]);  }
			if (odir == 2 && y == oy) //o↓
									  //x↑
				if (xx <= ox + dx[odir] * odis && ox + dx[odir]*odis <= x) { res = false; die.push_back(order[i]);  }
			//x좌표가 서로 교차하는가?
			if (xx <= ox && ox <= x) { //oㅡ
									   //x↑
				//y좌표가 서로 교차하는가?
				if (odir == 1 && oy <= y && y <= oy + dy[odir] * odis) { res = false; die.push_back(order[i]);  }
				if (odir == 3 && oy + dy[odir] * odis <= y && y <= oy) { res = false; die.push_back(order[i]);  }
			}
		}
	}

	return res;
}

int main(void) {
	scanf("%ld%ld", &L, &N);
	right = 2 * L + 1; 
	down = 2 * L + 1;
	x = L;
	y = L;

	snakeMOVE();

	return 0;
}