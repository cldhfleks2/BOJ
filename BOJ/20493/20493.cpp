#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>

int main(void) {
	int n, t;
	//준원이초기위치 locX, locY, 이전 시간 preTime
	int locX = 0, locY = 0, preTime = 0; 
	scanf("%d %d\n", &n, &t);
	//n개의 방향을 바꾼 기록을 저장
	//2번째 요소는 0:left 1:right
	std::vector<std::pair<int, int>> list; 

	//입력값을 모두 저장
	for (int i = 0; i < n; i++) {
		int time;
		int dir;
		char flag[7];
		scanf("%d %[^\n]s", &time, &flag); //시간과 방향을 읽음
		scanf("%c", &flag[6]); //줄바꿈문자를 지움
		if (flag[0] == 'r') {
			dir = 0;
		}
		else {
			dir = 1;
		}
		list.push_back({ time, dir });
	}

	//0 : →
	//1 : ↓
	//2 : ←
	//3 : ↑
	int flag = 0; //처음엔 오른쪽으로 전진
	//이전과 다음 입력값을 기준으로 준원이의 위치를 기록
	for (int i = 0; i < list.size(); i++) {
		int time = list[i].first;
		int f = list[i].second;

		int moveGap = time - preTime; //이동할 시간차(=거리)
		

		//현재 바라보는 방향으로 시간차 만큼 이동.
		if (flag == 0) {
			locX += moveGap; 
		}
		else if (flag == 1) {
			locY -= moveGap;
		}
		else if (flag == 2) {
			locX -= moveGap;
		}
		else if (flag == 3) {
			locY += moveGap;
		}

		//다음에 이동할 방향 지정
		if (f == 0) {
			flag++;
		}
		else if (f == 1) {
			flag--;
		}

		//한바퀴를 돈경우
		if (flag == 4) {
			flag = 0;
		}
		else if (flag == -1) {
			flag = 3;
		}

		preTime = time; //이전시간 갱신
	}

	//아직 시간이 남은경우
	if (preTime != t) { 
		//마지막으로 바라보던 방향으로 남은 시간만큼 이동.
		if (flag == 0) {
			locX += t - preTime;
		}
		else if (flag == 1) {
			locY -= t - preTime;
		}
		else if (flag == 2) {
			locX -= t - preTime;
		}
		else if (flag == 3) {
			locY += t - preTime;
		}
	}

	printf("%d %d", locX, locY);

	return 0;
}