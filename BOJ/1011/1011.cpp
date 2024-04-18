#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>



int main(void) {
	int t;
	scanf("%d", &t);
	while (t--) {
		int x, y;
		scanf("%d%d", &x, &y);
		//두 지점간의 거리가 중요하니까
		y = y - x; 
		x = 0;
		if (y == 1 || y == 2 || y==3) { //예외사항
			printf("%d", y);
			continue;
		}
		//종료조건 : y - x가 k-1, k , k+1인지
		//두점사이 거리
		int distance = y; 
		int years = 0;
		int step = 0; //최대 이동광년(한번에)
		for (int step2 = 1; ; step2++) { //사용가능한 최대 step을 결정
			if (step2 * (step2 + 1) < distance)
				break;
			step = step2;
		}
		for (int i = 1; ; i++) {
			int sum = i * (i + 1); //앞뒤로 1~i 까지 숫자의합(앞뒤니까 x2)
			int remainingDistance = distance - sum + 1;
			years = i * 2 + 1; //이동한거리 갱신
			if(remainingDistance)

		}
	}
}
