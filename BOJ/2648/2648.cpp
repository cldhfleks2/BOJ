#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
/*
* 핵심 포인트
* 1. 모든 꼭짓점(방향전환시 생기는점, 두 선분이 교차하는점)
* 2. 하나의 꼭짓점을 기준으로 선정하고, 사각형이 되기위한 나머지 3 꼭짓점이 존재하는지
*	확인 => 있다면 넓이계산 없으면 반복
* 2-1. 위에서 꼭짓점들을 탐색할때 기준점의 x,y 기준으로 x+, x-, y+, y- 의 제각기범위를
*	vertex 에서 탐색하면된다.
* 3. 넓이가 1~ 100까지인 사각형을 찾도록 브루트포스알고리즘을 써도되지만
*	좀더 효율적인 알고리즘을 찾아보았음
*/
using std::pair;
using std::vector;
typedef pair<int, int> p;
//width : <좌측점x1y1 , 우측점x2y2>
//height : <상단점x1y1 , 하단점x2y2>
//width갯수 X height갯수로 각각비교하여
//교차하는경우 꼭짓점으로 기록
vector<pair<p, p>> width, height;
//시작좌표 => 좌표평면을 상하반전 시킨것과 같음.
//map : 지나온 궤적들
int x, y, n; 
int res_x1, res_y1, res_x2, res_y2;
//vertex : 꼭짓점 위치들만
bool vertex[100][100];

void findVertex() { //가로 세로 두선분이 교차시 생기는 꼭짓점들을 파악
	int wn = width.size(), hn = height.size();

	for (int i = 0; i < wn; i++) { //width탐색
		//w_x1, w_y1 가로선분 좌측 좌표
		//w_x2, w_y2 가로선분 우측 좌표
		int w_x1 = width[i].first.first, w_y1 = width[i].first.second;
		int w_x2 = width[i].second.first, w_y2 = width[i].second.second;
		for (int j = 0; j < hn; j++) { //height 탐색
			//h_x1, h_y1 세로선분 상단좌표
			//h_x2, h_y2 세로선분 하단좌표
			int h_x1 = height[j].first.first, h_y1 = height[j].first.second;
			int h_x2 = height[j].second.first, h_y2 = height[j].second.second;
			if ((w_y1 <= h_y1 && h_y1 <= w_y2) &&
				(h_x1 <= w_x1 && w_x1 <= h_x2)) { //두선분이 수직으로 교차한다면
				int xx = w_x1, yy = h_y1; //교차하는 꼭짓점의 좌표
				vertex[xx][yy] = true; //기록
			}
			else { //두선분이 안만나면 제외
				continue;
			}
		}
	}

}

int calculate() {
	int min = 0x7fffffff;
	
	for (int x1 = 0; x1 < 100; x1++) {
		for (int y1 = 0; y1 < 100; y1++) {
			if (vertex[x1][y1]) { //기준점1
				for (int x2 = 0; x2 < 100; x2++) {
					for (int y2 = 0; y2 < 100; y2++) {
						if (x1 == x2 && y1 == y2) continue; //같은 점을잡으면 제외
						if (vertex[x2][y2]) { //기준점2
							//일직선상 이거나 이미 탐색한 기준점이면 제외
							//x1,y1 이 항상 x2,y2 좌표보다 좌상단에 있는것
							if (x1 >= x2) continue;
							if (y1 >= y2) continue;
							//두 기준점으로 만들어지는 사각형의 우상단 꼭짓점확인
							if (!vertex[x1][y2]) continue; //없으면 제외
							//만들어지는 사각형의 좌하단 꼭짓점확인
							if (!vertex[x2][y1]) continue;

							//여기까지오면 찾은것
							int area = (x2 - x1) * (y2 - y1);
							if (min > area) { //최솟값이면 기록
								min = area;
								res_x1 = x1; //좌표기록
								res_y1 = y1; 
								res_x2 = x2;
								res_y2 = y2;
							}
						}

					}
				}
			}
		}
	}

	if (min == 0x7fffffff)
		return 0;
	else
		return min;
}

int main(void) {
	scanf("%d%d%d", &y, &x, &n); //x, y를 행, 열 좌표로 두기위해 바꾸어 대입
	x--; y--; //좌표평면상좌표는 1,1~ 100, 100이지만 실제 행열좌표는 0,0부터 시작하므로
	for (int i = 0; i < 100; i++) //초기화
		for (int j = 0; j < 100; j++)
			vertex[i][j] = false;

	//입력을 받아서 가로줄, 세로줄 그룹에 넣고
	//방향전환했을시 vertext에 꼭짓점으로 기록
	int prevFlag;
	for (int i = 0, temp; i < n; i++) {
		char c, junk;
		int currentFlag = -1;
		int xx=x, yy=y; //로봇이 움직이기전 시작좌표
		scanf("%c", &junk); //줄바꿈문자 지움
		scanf("%c%d", &c, &temp);
		if (c == 'R') { //가로줄 그룹
			currentFlag = 1;
			y += temp;
			width.push_back({ {xx, yy},{x, y} });
		}
		else if (c == 'L') { //가로줄 그룹
			currentFlag = 2;
			y -= temp;
			width.push_back({ {x, y},{xx, yy} });
		}
		else if (c == 'D') { //세로줄 그룹
			//좌표평면상의 down => 행열상 up
			currentFlag = 4;
			x -= temp;
			height.push_back({ {x, y},{xx, yy} });
		}
		else if (c == 'U') { //세로줄 그룹
			//좌표평면상의 down => 행열상 up
			currentFlag = 3;
			x += temp;
			height.push_back({ {xx, yy},{x, y} });
		}

		if (i == 0)
			prevFlag = currentFlag;

		if (prevFlag != currentFlag) //현재 이동이 방향전환했다면
			vertex[xx][yy] = true; //시작좌표 위치가 꼭짓점

		prevFlag = currentFlag;
	}

	findVertex(); 
	if (calculate() == 0) {
		printf("0");
		return 0;
	}
	else {
		printf("%d %d\n%d %d", res_y1 + 1, res_x1 + 1, res_y2 + 1, res_x2 + 1);
		return 0;
	}

}