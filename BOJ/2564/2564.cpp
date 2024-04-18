#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using std::vector; using std::pair;
typedef pair<int, int> pii;
int n, m, r, x, y, location; //location: 0,1,2,3 남서북동 위치
int res; //모든 상점간의 최단거리

vector<pair<pii, int>> shops; //상점의 x, y 위치, location

int dx[] = { 0, -1, 0 , 1 }; //좌상우하 순서
int dy[] = { -1, 0, 1, 0 };

void init() {
	scanf("%d%d%d", &m, &n, &r);
	int _, __;
	while (r--) { //상점위치
		scanf("%d%d", &_, &__);
		if (_ == 1)
			shops.push_back({ { 0, __ }, 2 });
		else if (_ == 2)
			shops.push_back({ { n - 1, __ }, 0 });
		else if (_ == 3)
			shops.push_back({ { __, 0 }, 1 });
		else if (_ == 4)
			shops.push_back({ { __, m - 1 }, 3 });
	}
	scanf("%d%d", &_, &__); //동근이위치
	if (_ == 1) {
		x = 0; y = __; location = 2;
	}
	else if (_ == 2) {
		x = n - 1; y = __; location = 0;
	}
	else if (_ == 3) {
		x = __; y = 0; location = 1;
	}
	else if (_ == 4) {
		x = __; y = m - 1; location = 3;
	}
}

void func() {
	int size = shops.size();
	int dir;
	for (int i = 0; i < size; i++) {
		int xx = shops[i].first.first;
		int yy = shops[i].first.second;
		int shopLocation = shops[i].second;

		dir = location;
		int clockWise = 0, counterClockWise = 0;
		//시계방향으로 가는 거리 계산
		for (int d = 0; d < 4; d++) {
			if (dir == shopLocation) { //샵방향과 현재방향이 일치하면
				if(d == 0) {//처음 동근이위치와 같은 방향이었다면
					if (dir % 2 == 0)
						clockWise += abs(y - yy);
					else
						clockWise += abs(x - xx);
					break;
				}
				if (dir == 0)
					clockWise += m - yy;
				else if (dir == 1)
					clockWise += n - xx;
				else if (dir == 2)
					clockWise += yy;
				else if (dir == 3)
					clockWise += xx;
				break;
			}
			else {
				if (d == 0) { //처음일때
					if (dir == 0)
						clockWise += y;
					else if (dir == 1)
						clockWise += x;
					else if (dir == 2)
						clockWise += m - y;
					else if (dir == 3)
						clockWise += n - x;
				}
				else { //처음X 해당 방향으로 가는 다른방향일때
					if (dir % 2 == 0) //남, 북
						clockWise += m; //가로 전체길이
					else //서, 동
						clockWise += n; //세로 전체길이
				}
			}

			dir = (dir + 1) % 4; //현재위치 에서 시계방향으로 이동
		}
		dir = location; //초기화
		counterClockWise = (2 * n + 2 * m) - clockWise;

		res += clockWise > counterClockWise ? counterClockWise : clockWise; //최단거리저장
	}
	printf("%d", res);
}

int main() {
	init();
	func();


	return 0;
}



