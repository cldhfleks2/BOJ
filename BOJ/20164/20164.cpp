#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
int N, max=0, min=0x7fffffff;

int findOddCnt(char* c, int size) {
	int odd = 0;
	for (int i = 0; i < size; i++)
		if ((c[i] - '0') % 2 != 0) odd++;
	return odd;
}

//최솟값을 구함
void func(int n, int cnt) {
	int size = 1, _ = n, n2, odd = 0; 
	while (_ / 10 != 0) { //자릿수구하기
		size++;
		_ /= 10;
	}
	char c[10];
	sprintf(c, "%d", n); //문자열로 변환
	//1단계 : 각자리 숫자중 홀수 갯수를 저장
	odd += findOddCnt(c, size);

	//2단계 : 한자리면 종료 : 유일한 종료조건.
	//이곳에서 모든 최대 최소 연산이 이루어짐
	if (size == 1) {
		if (max < cnt + odd) max = cnt + odd;
		if (min > cnt + odd) min = cnt + odd;
		return;
	}

	//3단계 : 두자리면
	if (size == 2)
		func((c[0] - '0') + (c[1] - '0'), cnt + odd);

	//4단계 세자리이상이면
	if (size >= 3) {
		for (int i = 1; i < size - 1; i++) {
			for (int j = i + 1; j < size; j++) {
				int s1=0, s2=0, s3=0;
				char c1[10] = {'\0',}, c2[10] = { '\0', }, c3[10] = { '\0', };
				//3등분으로 자름
				for (int k = 0; k < i; k++) { 
					c1[s1] = c[k];
					s1++;
				}
				for (int k = i; k < j; k++) {
					c2[s2] = c[k];
					s2++;
				}
				for (int k = j; k < size; k++) {
					c3[s3] = c[k];
					s3++;
				}
				//정수로 변환
				n2 = atoi(c1) + atoi(c2) + atoi(c3);

				func(n2, cnt + odd);
			}
		}
	}
}

int main(void) {
	scanf("%d", &N);

	func(N, 0);
	printf("%d %d", min, max);

	return 0;
}