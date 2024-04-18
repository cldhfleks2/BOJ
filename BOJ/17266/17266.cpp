#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
int N, M, *lamp;
void makeRoad();
void findHeight();

//이분탐색으로 바꿔야함
void makeRoad() {
	scanf("%d\n%d", &N, &M);
	lamp = new int[M];
	for (int i = 0; i < M; i++) { //가로등입력받음
		scanf("%d", &lamp[i]);
	}

	findHeight();
}

void findHeight() {
	int H = 1; //가로등의높이
	while (true) {
		int sangbin = 0; //현재 상빈이의 위치
		bool find = false;
		bool end = false; //가로등순회 loop를 끝내는지 결정
		//printf("%d >> \n", H);
		for (int i = 0; i < M; i++) { //모든 가로등을 순회
			//가로등불빛의 왼쪽부터 sangbin랑 비교. 같으면 sangbin++
			int x = lamp[i]; //현재 가로등위치
			//printf("\n%d 가로등\n", lamp[i]);
			if (end) {
				//printf("  <%d>종료", sangbin);
				break;
			}
			// x-H ~ x+H 까지 빛을 비춤
			for (int j = x - H; j <= x + H; j++) {
				//printf("  (%d,%d)", j, sangbin);
				if (j < sangbin) { //상빈이가 지나온길은 스킵(처음은0 이므로 음수또한 스킵)
					//printf("!!  ");
					continue;
				}
				if (j > sangbin) { //상빈이가있는 위치를 비추지않고 건너뛰면 못지나감
					end = true; //loop를 종료
					//printf("  <%d,%d>", j, sangbin);
					//printf("실패!\n");
					break; //종료
				}
				if (sangbin == N) { //상빈이가 목적지에 도달하면 종료
					end = true; //loop를 종료
					find = true; //성공함
					//printf("  <%d,%d>", j, sangbin);
					//printf("길을 모두 건넛음\n");
					break;
				}
				sangbin++;
			}
		}
		//printf("  현재위치%d  ", sangbin);
		//성공했으면 탈출
		if (find) {
			//printf("  <%d>외부종료\n", sangbin);
			break;
		}

		//모든 가로등을 순회했으나 상빈이가 길을 다 못건넜으면 
		//가로등높이 + 1 하고 반복
		if (sangbin <= N) { 
			//printf("  <%d>길다안건넜음\n", sangbin);
			H++; //가로등높이를 + 1 하고 반복
			continue; //반복
		}

	}

	//정답출력부
	printf("%d\n", H);
	delete lamp;
}

int main(void) {
	while (true) {
		makeRoad();
	}


	return 0;
}