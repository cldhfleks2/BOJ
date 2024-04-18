#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
//맵크기 n x m 
//map : 검은칸은 -1 흰색칸은 -2값대입
//a : 흰색을 검정으로 칠하는비용
//b : 검정을 흰색으로 칠하는비용
//blackCnt : 모든 검은칸갯수 (ㄷ자에 모든 검은칸이 포함되어야한다.)
int n, m, a, b, **map, blackCnt=0;
void func();
void input();

void func() {
	input();
	int maxSize = n >= m ? m : n; //n과 m중 최솟값
	int res = 0x7fffffff;
	for (int k = 1; 3 * k <= maxSize; k ++) {
		
		//시작위치 x,y(좌상단좌표)를 정함
		int size = 3 * k;
		for (int x = 0; x + size <= n; x++) { //올바른 좌표범위 (0,0)~(n-1,m-1)
			for (int y = 0; y + size <= m; y++) { //ㄷ의 크기는 3k x 3k
				int price = 0; //색을 다시 칠하는 비용
				int lessBlackCnt = blackCnt; //모눈종이의 모든 검은칸의 갯수 - 3k x 3k공간에서 확인된 검은칸의갯수.
											 //즉 남은 검은색갯수
				//1. 3k x 3k칸을 모두 검은색으로 칠하는 비용 계산
				for (int xx = x; xx < x + size; xx++) { //ㄷ내부의 모든 모눈종이를 확인
					for (int yy = y; yy < y + size; yy ++) { //(x,y)~(x+2k,y+2k)확인
						if (map[xx][yy] == -2) { //흰칸을 검은칸으로
							price += a;
						}
						else if (map[xx][yy] == -1) //남은 검은칸의 갯수를 셈
							lessBlackCnt--;
					}
				}
				//2. 3k x 3k이외의 모든 모눈종이칸에있는 검은색을 흰색으로 다시칠해야함
				price += lessBlackCnt * b; 
				
				//3. 흰색칸이어야 하는곳의 비용 계산
				for (int xx = x + k; xx < x + size - k; xx++) {
					for (int yy = y + k; yy < y + size; yy++) {
						if (map[xx][yy] == -2) { //흰칸: 1번에서 필요없는비용을 추가했으니, 다시 빼줌
							price -= a; 
						}
						else if (map[xx][yy] == -1){ //검은칸 : 흰칸으로 칠하는 비용추가
							price += b; 
						}
					}
				}

				//최솟값만 res 에 갱신
				if (res > price)
					res = price; 
			}
		}

	}

	printf("%d", res);
}

void input() {
	scanf("%d%d%d%d", &n, &m, &a, &b);

	map = new int* [n];
	for (int i = 0; i < n; i++) {
		map[i] = new int[m];
		char _;
		scanf("%c", &_); //줄바꿈문자지움
		for (int j = 0; j < m; j++) {
			scanf("%c", &_);
			if (_ == '#') {
				map[i][j] = -1; //검은칸에는 -1
				blackCnt++; //검은칸 갯수를 셈
			}
			else
				map[i][j] = -2; //흰칸에는 -2
		}
	}

}

int main(void) {
	func();

	return 0;
}
