#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
using std::pair;
int** map;

//흑 또는 백이 이기는 수를 찾아서 리턴
pair<int, int> find(int n) {
	int x = -1, y = -1;
	int cnt = 0; //얼마나 연속되는지 확인
	//   ㅡ 
	for (int i = 0; i < 19; i++) {
		int j;
		for (j = 0; j < 19; j++) {
			if (map[i][j] == n) { //찾고자하는 돌을 찾았으면
				cnt++; //연속된 갯수
			}
			else {
				if (cnt == 5) { //정확히 5개 일때만 승리
					//printf("11\n");
					return { i, j - 5 }; //좌단 위치 리턴 (한번지나치고나서 이므로 j-5)
				} //6개이상 놓인경우였으면 제외
				cnt = 0;
			}
			
		}
		if (cnt == 5) { //정확히 5개 일때만 
			//printf("111\n");
			return { i, j - 5 }; //좌단 위치 리턴
		}
		cnt = 0; //다음열로 가면 초기화
	}

	cnt = 0; //초기화
	//   |
	for (int i = 0; i < 19; i++) {
		int j;
		for (j = 0; j < 19; j++) {
			if (map[j][i] == n) { 
				cnt++; 
			}
			else {
				if (cnt == 5) { 
					//printf("22\n");
					return { j - 5, i }; //상단 위치 리턴 (한번 지나쳤으므로 j-5)
				} 
				cnt = 0;
			}

		}
		if (cnt == 5) { 
			//printf("222\n");
			return { j - 5, i }; //상단 위치 리턴
		}
		cnt = 0; //다음열로 가면 초기화
	}

	cnt = 0;
	//   ＼
	for (int i = 0; i < 19 - 4 ; i++) { //좌상단 x 위치
		for (int j = 0; j < 19 - 4; j++) { //좌상단 y 위치
			cnt = 0; //초기화
			if (i != 0 && j != 0) {
				//현재 i, j 바로직전 좌상단이 같은돌이면 이미 탐색했으므로 제외
				if (map[i - 1][j - 1] == n)
					continue;
			}
			for (int gap = 0; ; gap++) { //5번씩 우하단으로 감
				if (i + gap == 19 || j + gap == 19) //범위 벗어나면 스탑
					break;
				if (map[i + gap][j + gap] != n) { //아닌것을찾으면 스탑
					if (cnt == 5) { //정확히 5개일때만 승리한것
						//printf("33\n");
						return { i, j }; //좌상단위치 리턴
					}
					cnt = 0;
					break;
				}
				cnt++;
			}
			if (cnt == 5) { //정확히 5개일때만 승리한것
				//printf("333\n");
				return { i, j }; //좌상단위치 리턴
			}
		}
	}

	cnt = 0;
	//   /
	for (int i = 0; i < 19 - 4; i++) { 
		for (int j = 0 + 4; j < 19; j++) {
			cnt = 0; 
			if (i != 0 && j != 18) {
				//현재 i, j 바로직전 우상단이 같은돌이면 이미 탐색했으므로 제외
				if (map[i - 1][j + 1] == n)
					continue;
			}
			for (int gap = 0; ; gap++) { 
				if (i + gap == 19 || j - gap == -1) 
					break;
				if (map[i + gap][j - gap] != n) { 
					if (cnt == 5){ 
						//printf("44\n");
						return { i + 4, j - 4 }; //좌하단 위치 
					}
					cnt = 0;
					break;
				}
				cnt++;
			}
			if (cnt == 5) { 
				//printf("444\n");
				return { i + 4, j - 4 }; //좌하단 위치 
			}
		}
	}

	//만약못찾았으면 { -1, -1 } 리턴
	return { x, y };
}

int main(void) {
	map = new int* [19];
	for (int i = 0; i < 19; i++) { //입력받음
		map[i] = new int[19];
		for (int j = 0; j < 19; j++)
			scanf("%d", &map[i][j]);
	}
	pair<int, int> res = find(1);
	if (res.first == -1) { //흑이 지면
		res = find(2);
		if (res.first == -1) { //백이 지면
			printf("0"); //승부결정이 안났음
			return 0;
		}
		else { //백이 이긴경우
			printf("2\n%d %d", res.first + 1, res.second + 1);
			return 0;
		}
	}
	else { //흑이 이긴경우
		printf("1\n%d %d", res.first + 1, res.second + 1);
		return 0;
	}

	return 0;
}