#define _CRT_SECURE_NO_WARNINGS //scanf오류 없앰
#include <bits/stdc++.h>
using namespace std;

int main(void) {
	int num = 0, size = 8, input, result = 0;
	//result=> 0)mixed  1)ascending  2)descending
	while (size--) {
		scanf("%d", &input);
		if (num == 0) { //첫입력
			if (2 <= input && input <= 7) {
				break; //첫입력시 1, 8 로시작안하면 mixed
			}
			else if(input == 1){ //정상적인경우
				result = 1; //ascending으로 간주하겠다.
			}
			else if (input == 8) {
				result = 2;
			}
			num = input;
			continue;
		}
		if ((result == 1 && num > input) ||
			(result == 2 && num < input)) { //섞인경우들
			result = 0; //mixed
			break;
		}
		
		num = input;
	}
	switch (result) { //result=> 0)mixed  1)ascending  2)descending
	case 0:
		printf("mixed");
		break;
	case 1:
		printf("ascending");
		break;
	case 2:
		printf("descending");
		break;
	}
}