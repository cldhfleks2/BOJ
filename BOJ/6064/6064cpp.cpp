#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
int GCD(int a, int b) {
	int temp;
	while (b != 0) {
		temp = a % b;
		a = b;
		b = temp;
	}
	return a;
}

int main(void) {
	int t = 0;
	scanf("%d", &t);
	while (t--) {
		int M, N, x, y;
		scanf("%d%d%d%d", &M, &N, &x, &y);
		if (M > N) { // M <= N인 상황을 만들어줌
			int temp = M;
			M = N;
			N = temp;
			//x, y도 교환
			temp = x;
			x = y;
			y = temp;
		}

		int res = -1; //결괏값
		//x(M)고정, y를 반복하는것과같음.
		int step_MN = N - M; //M, N 간의 차이
		int step_xy = 0; //x, y 간의 차이
		//x가 y보다 주기가짧으므로, 평균적으로 y가 더 작을확률이높음
		//그래서 정함
		if (x >= y)
			step_xy = x - y;
		else
			step_xy = N - (y - x);

		int temp_x = y + step_xy; //temp_x는 x랑 같은지 비교할때만 쓰임.
		if (temp_x > N - 1) { //temp_x가 M을넘은 몫을가질때
			while(temp_x - (N - 1)) //계산식상 N-1 과 비교하게됨
				temp_x -= N - 1; //비교가능하게 맞춰만주는것
		}
		int LCM = M * N / GCD(M, N); //최소공배수

		if (temp_x == x) { //가능한 달력이라면 아래코드를진행
			if (step_xy > M) { //종말이후 날짜라면 -1 출력
				res = -1;
				continue;
			}

			res = (step_xy / step_MN) * M; //M계산
			int temp_y = y + step_xy;
			if(temp_y > N)
				temp_y %= N;
					
			res += temp_y; //N계산
		}
		//불가능하다면 res = -1 자동 출력

		printf("정답%d\n", res);
	}




	return 0;
}