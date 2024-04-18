#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
using std::vector; using std::pair; using std::queue;
typedef pair<int, int> pii;
/*
iceberg : 매시간마다 빙산높이를 저장
icebergList : 매시간마다 생존한 빙산좌표들
meltAmount : 매시간마다 빙하가 녹는양을 저장
visited : finished 함수에서 BFS로 사용하기위한 방문체크 배열
loc : finished 함수에서 빙산이 한덩어리인지 찾기위해
	  BFS를 사용하기위한 큐
hour : 현재시간, 출력값
dx, dy : 방향벡터
*/
int n, m, ** iceberg, ** meltAmount, hour = 0;
bool** visited;
vector<pii> icebergList;
queue<pii> loc;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
bool findMeltAmount();
bool isOnePiece();
void melting();
void func();

void func() {
	while (1) {
		if (!findMeltAmount()) { //빙산이존재하지않으면 0출력, 종료
			printf("0");
			return;
		}

		if (!isOnePiece()) { //빙산이 둘이상으로 분리된경우 지난시간출력, 종료
			printf("%d", hour);
			return;
		}

		melting(); //빙산을 녹인다.
		hour++; 
	}
}

//실제로 빙산을 녹인다.
void melting() {
	for (int k = 0; k < icebergList.size(); k++) {
		int x = icebergList[k].first;
		int y = icebergList[k].second;
		iceberg[x][y] -= meltAmount[x][y];
		if (iceberg[x][y] < 0) iceberg[x][y] = 0; //0이하로 떨어지지않음
	}
}

//빙산위치중 하나에서 시작해서 BFS로 한덩어리로 이루어졌는지 확인하는 함수
//두덩어리 이상으로 분리된경우 false 리턴
bool isOnePiece() {
	int icebergCnt = icebergList.size();
	int init_x = icebergList[0].first;
	int init_y = icebergList[0].second;
	loc.push({ init_x, init_y }); //BFS 시작위치
	visited[init_x][init_y] = true; //방문체크
	icebergCnt--; //빙산갯수카운트

	while (!loc.empty()) {
		int x = loc.front().first; //현재위치
		int y = loc.front().second;
		loc.pop();

		for (int d = 0; d < 4; d++) {
			int xx = x + dx[d]; //다음위치
			int yy = y + dy[d];

			//맵을벗어난경우 제외
			if (xx < 0 || yy < 0 || xx == n || yy == m) continue;
			
			//방문한적없고, 빙산이 존재하는곳이면 이동
			if (!visited[xx][yy] && iceberg[xx][yy] > 0) {
				visited[xx][yy] = true; //방문체크
				loc.push({ xx, yy }); //다음위치를 큐에넣어서 탐색을이어감
				icebergCnt--;
			}
		}
	}

	if (icebergCnt > 0)  //모든 빙산이 이어져있지않은경우
		return false;
	else
		return true;
}

//현재빙산이 녹는 속도를 계산
//빙산이없으면 false리턴
bool findMeltAmount() { 
	icebergList.clear(); 
	for (int i = 0; i < n; i++)
		for(int j = 0 ; j < m ; j++)
			if (iceberg[i][j] != 0)
				icebergList.push_back({ i, j }); //빙산위치를 기록

	if (icebergList.size() == 0) return false;

	//초기화 1
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			meltAmount[i][j] = 0;
	//초기화 2
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			visited[i][j] = false;

	//빙산마다 녹는속도를 계산
	for (int k = 0; k < icebergList.size(); k++) {
		int x = icebergList[k].first;
		int y = icebergList[k].second;
		
		int amount = 0;
		for (int d = 0; d < 4; d++) {
			int xx = x + dx[d];
			int yy = y + dy[d];

			if (xx < 0 || yy < 0 || xx == n || yy == m) continue;
			if (iceberg[xx][yy] == 0) amount++; //4방향중 바다가있는곳
		}
		meltAmount[x][y] = amount;
	}
	return true;
}

int main(void) {
	scanf("%d%d", &n, &m);
	iceberg = new int* [n];
	meltAmount = new int* [n];
	visited = new bool* [n];
	for (int i = 0; i < n; i++) {
		iceberg[i] = new int[m];
		meltAmount[i] = new int[m];
		visited[i] = new bool[m];
		for (int j = 0; j < m; j++) {
			scanf("%d", &iceberg[i][j]);
		}
	}

	func();

	return 0;
}
