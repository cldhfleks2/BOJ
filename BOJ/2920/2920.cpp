#define _CRT_SECURE_NO_WARNINGS //scanf���� ����
#include <bits/stdc++.h>
using namespace std;

int main(void) {
	int num = 0, size = 8, input, result = 0;
	//result=> 0)mixed  1)ascending  2)descending
	while (size--) {
		scanf("%d", &input);
		if (num == 0) { //ù�Է�
			if (2 <= input && input <= 7) {
				break; //ù�Է½� 1, 8 �ν��۾��ϸ� mixed
			}
			else if(input == 1){ //�������ΰ��
				result = 1; //ascending���� �����ϰڴ�.
			}
			else if (input == 8) {
				result = 2;
			}
			num = input;
			continue;
		}
		if ((result == 1 && num > input) ||
			(result == 2 && num < input)) { //���ΰ���
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