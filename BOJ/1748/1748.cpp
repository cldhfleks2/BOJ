#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>

int main(int N) {
	scanf("%d", &N);
	int temp = N, p = 0, r = N % 10, res = 0;
	//10^p <= N < 10^(p+1)
	//p+1은 총자릿수
	while (true) { // 의 p를 구함
		if (temp < 10)
			break;
		temp /= 10;
		p++;
	}
	//printf("p : %d\n", p); 

	for (int i = p-1; i >= 0; i--) { //이전단계 수의합
		//이전단계는 p-1 여기서 +1하면 총자릿수이므로
		//이전단계의 총자릿수는 p이어야하므로
		//여기선 i+1
		res += 9 * pow(10, i) * (i+1); 
		//printf("res : %d\n", res);
	}

	res += (int)((N - pow(10, p)+1) * (p+1));
	//printf("구한res : %d\n", (int)((N - pow(10, p)) * (p + 1)));
	//printf("정답 : %d\n", res);

	printf("%d", res);
	return 0;
}

