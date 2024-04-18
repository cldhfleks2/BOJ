#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
using namespace std;
deque<int> gear[4];
int K = 0;
vector<pair<int, int>> rot; //회전시킨방법들
bool gaps[3] = { false, };	//3구간이 각각 돌아가는가?
int cnt = 0;

void gear_r(int gearNum, int r);
int gear_p(int gearNum, bool right);
void cw(int gearNum);
void ccw(int gearNum);
void rotate(int n, int r);
void machine();
void printAll();

void cw(int gearNum) { //시계방향으로 회전
	int temp = gear[gearNum].back();
	gear[gearNum].pop_back();
	gear[gearNum].push_front(temp);
}

void ccw(int gearNum) { //반시계방향으로 회전
	int temp = gear[gearNum].front();
	gear[gearNum].pop_front();
	gear[gearNum].push_back(temp);
}

//기어의 오른쪽, 왼쪽(맞닿는 부분)을 출력한다.
int gear_p(int gearNum, bool right) { 
	int res = 0;
	if (right) { //오른쪽 정보를출력
		//3번째 즉 2번인덱스값
		res = gear[gearNum][2];
	}else{ //왼쪽정보를 출력
		//7번째, 즉 6번인덱스값
		res = gear[gearNum][6];
	}
	return res;
}

void rotate(int n, int r) { //n번기어를 r방향으로 돌림
	for (int i = 0; i < 3; i++) //초기화
		gaps[i] = false;
	//세 구간에서 회전이 일어나는가
	if (gear_p(0, true) != gear_p(1, false)) gaps[0] = true;
	if (gear_p(1, true) != gear_p(2, false)) gaps[1] = true;
	if (gear_p(2, true) != gear_p(3, false)) gaps[2] = true;

	//n에따라 기어상태들을 변화
	if (n == 1) {
		if (gaps[0] == true &&
			gaps[1] == true &&
			gaps[2] == true) {
			gear_r(2, r * -1);
			gear_r(3, r);
			gear_r(4, r * -1);
		}
		else if (gaps[0] == true &&
			gaps[1] == true &&
			gaps[2] == false) {
			gear_r(2, r * -1);
			gear_r(3, r);
		}
		else if (gaps[0] == true &&
			gaps[1] == false &&
			gaps[2] == true) {
			gear_r(2, r * -1);
		}
		else if (gaps[0] == false &&
			gaps[1] == true &&
			gaps[2] == true) {
			//pass
		}
		else if (gaps[0] == false &&
			gaps[1] == false &&
			gaps[2] == true) {
			//pass
		}
		else if (gaps[0] == true &&
			gaps[1] == false &&
			gaps[2] == false) {
			gear_r(2, r * -1);
		}
		else if (gaps[0] == false &&
			gaps[1] == true &&
			gaps[2] == false) {
			//pass
		}
		else if (gaps[0] == false &&
			gaps[1] == false &&
			gaps[2] == false) {
			//pass
		}
		gear_r(1, r);
	}
	else if (n == 2) {
		if (gaps[0] == true &&
			gaps[1] == true &&
			gaps[2] == true) {
			gear_r(1, r * -1);
			gear_r(3, r * -1);
			gear_r(4, r);
		}
		else if (gaps[0] == true &&
			gaps[1] == true &&
			gaps[2] == false) {
			gear_r(1, r * -1);
			gear_r(3, r * -1);
		}
		else if (gaps[0] == true &&
			gaps[1] == false &&
			gaps[2] == true) {
			gear_r(1, r * -1);
		}
		else if (gaps[0] == false &&
			gaps[1] == true &&
			gaps[2] == true) {
			gear_r(3, r * -1);
			gear_r(4, r);
		}
		else if (gaps[0] == false &&
			gaps[1] == false &&
			gaps[2] == true) {
			//pass
		}
		else if (gaps[0] == true &&
			gaps[1] == false &&
			gaps[2] == false) {
			gear_r(1, r * -1);
		}
		else if (gaps[0] == false &&
			gaps[1] == true &&
			gaps[2] == false) {
			gear_r(3, r * -1);
		}
		else if (gaps[0] == false &&
			gaps[1] == false &&
			gaps[2] == false) {
			//pass
		}
		gear_r(2, r);
	}
	else if (n == 3) {
		if (gaps[0] == true &&
			gaps[1] == true &&
			gaps[2] == true) {
			gear_r(1, r);
			gear_r(2, r * -1);
			gear_r(4, r * -1);
		}
		else if (gaps[0] == true &&
			gaps[1] == true &&
			gaps[2] == false) {
			gear_r(1, r);
			gear_r(2, r * -1);
		}
		else if (gaps[0] == true &&
			gaps[1] == false &&
			gaps[2] == true) {
			gear_r(4, r * -1);
		}
		else if (gaps[0] == false &&
			gaps[1] == true &&
			gaps[2] == true) {
			gear_r(2, r * -1);
			gear_r(4, r * -1);
		}
		else if (gaps[0] == false &&
			gaps[1] == false &&
			gaps[2] == true) {
			gear_r(4, r * -1);
		}
		else if (gaps[0] == true &&
			gaps[1] == false &&
			gaps[2] == false) {
			//pass
		}
		else if (gaps[0] == false &&
			gaps[1] == true &&
			gaps[2] == false) {
			gear_r(2, r * -1);
		}
		else if (gaps[0] == false &&
			gaps[1] == false &&
			gaps[2] == false) {
			//pass
		}
		gear_r(3, r);
	}
	else if (n == 4) {
		if (gaps[0] == true &&
			gaps[1] == true &&
			gaps[2] == true) {
			gear_r(1, r * -1);
			gear_r(2, r);
			gear_r(3, r * -1);
		}
		else if (gaps[0] == true &&
			gaps[1] == true &&
			gaps[2] == false) {
			//pass
		}
		else if (gaps[0] == true &&
			gaps[1] == false &&
			gaps[2] == true) {
			gear_r(3, r * -1);
		}
		else if (gaps[0] == false &&
			gaps[1] == true &&
			gaps[2] == true) {
			gear_r(2, r);
			gear_r(3, r * -1);
		}
		else if (gaps[0] == false &&
			gaps[1] == false &&
			gaps[2] == true) {
			gear_r(3, r * -1);
		}
		else if (gaps[0] == true &&
			gaps[1] == false &&
			gaps[2] == false) {
			//pass
		}
		else if (gaps[0] == false &&
			gaps[1] == true &&
			gaps[2] == false) {
			//pass
		}
		else if (gaps[0] == false &&
			gaps[1] == false &&
			gaps[2] == false) {
			//pass
		}
		gear_r(4, r);
	}
}

void gear_r(int gearNum, int r) {
	int num = gearNum - 1;
	if (num < 0 || num > 3) //기어범위가 잘못된경우
		return;

	//기어를 해당방향으로돌림
	if (r == 1) {
		//시계방향
		cw(num);
	}
	else if (r == -1) {
		//반시계방향
		ccw(num);
	}
}

void machine() { //회전시킨 정보를 모두 실행
	for (int i = 0; i < K; i++) {
		//i번째 요소(회전시킨기어, 방향)를 꺼냄
		int n = rot[i].first;
		int r = rot[i].second;
		rotate(n, r);
	}
}

void printAll() {
	cnt++;
	int res = 0;
	res += 1 * gear[0].front();
	res += 2 * gear[1].front();
	res += 4 * gear[2].front();
	res += 8 * gear[3].front();
	
	printf("%d\n", res);
}

int main(void) {
	int temp=0, temp2=0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 8; j++) { //기어상태 저장
			scanf("%1d", &temp);
			gear[i].push_back(temp); //거꾸로넣어야 처음원소가 front가됨
		}
	}
	scanf("%d", &K);
	for (int i = 0; i < K; i++) { //회전시킨정보를 저장
		scanf("%d%d", &temp, &temp2);
		//회전시킨기어번호, 방향 
		rot.push_back({ temp, temp2 });
	}
	machine();
	printAll();

	return 0;
}