#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
#include <Windows.h>

int keyboard[27][27] = {0}; //[preKEY][KEY] ����Ű���� ����Ű���� �̵� ���. ������ġ�� ��� 0�� ����
//���� Ű���� �Ÿ�(�ּҴ��� 2)�� ��� ����Ұ���.

void input(); //�Է��� �޴� �κ�
void makeKeyboard(); //Ű������ ��� Ű�� ����
int findKEY(char c); //�����ϳ��� ���� Ű������ ��ȯ

//���Ű�� ���� �̵� ����� ����ϴ� �Լ�
void makeKeyboard() {
	//1 : �������� ��� Ű�� 
	for (int i = 1; i <= 3; i++) { //1, 2, 3��
		for (int j = 7 * i - 6 ; j <= 7 * i; j++) { //���� Ű�� j
			for (int k = j; k <= 7 * i; k++) { //�����ʹ����� Ű�� k
				if (j - k != 0) { //������ġ�� �ƴѰ͸� ���
					keyboard[j][k] = 2 * abs(k - j); //��Ű ���̰Ÿ�(���� 2)���
				}
			}

			for (int k = j; 7 * i - 6 <= k; k--) { //���ʹ��� Ű�� k
				if (j - k != 0) { //������ġ�� �ƴѰ͸�
					keyboard[j][k] = 2 * abs(k - j); //��Ű ���̰Ÿ�(���� 2)���
				}
			}
		}
	}

	//2 : �����Ʒ��� ��� Ű��
	// 1�� :  1~7
	// 2�� :  8~14
	// 3�� : 15~21
	for (int i = 1; i <= 3; i++) { //������ �������ɴ�
		for (int j = 7 * i - 6; j <= 7 * i; j++) { //1~7  8~14  15~21
			if (i + 1 <= 3) { //��ȿ�� �Ʒ����϶���
				//���ϴ�
				for (int k = j + 7; k <= 7 * (i + 1); k++) {
					if (7 * i + 1 <= k && k <= 7 * (i + 1)) //����� �ʿ������ Ȥ���� ���������� ���Ͽ�
						keyboard[j][k] = 2 * (k - j - 6); //���ϴ��� �̵������ �ٷι� 1�ν����Ͽ� 1������. ���������̰� 7���� ����
				}
				//���ϴ�
				for (int k = j + 7 - 1; 7 * (i + 1) - 6 <= k; k--) { //�ٷι�������, �ٷιؿ��� ���ʺ��� �����Ͽ� �ٿ�����
					if (7 * i + 1 <= k && k <= 7 * (i + 1)) //!!!!!! k�� ��������� ����. �߿���!!!!!!!!!!
						keyboard[j][k] = 2 * abs(k - j - 7); //���ϴ��� �ٷι��� ����Ű�� ����� 2���� ��� 
				}
			}

			if (i - 1 >= 1) { //��ȿ�� �������϶���
				//����
				for (int k = j - 7; k <= 7 * (i - 1); k++) {
					if (7 * (i - 1) - 6 <= k && k <= 7 * i)
						keyboard[j][k] = 2 * abs(k - j + 7); //���ϴ��� �̵������ �ٷι� 1�ν����Ͽ� 1������. ���������̰� 7���� ����
				}
				//�»��
				for (int k = j - 7 - 1; 7 * (i - 1) - 6 <= k; k--) { //�ٷι�������, �ٷιؿ��� ���ʺ��� �����Ͽ� �ٿ�����
					if (7 * (i - 1) - 6 <= k && k <= 7 * i) //k�� �ش� ���� ����� ���� ó�� �߿����ڵ�
						keyboard[j][k] = 2 * abs(k - j + 6); //���ϴ��� �ٷι��� ����Ű�� ����� 2���� ��� 
				}
			}
			if (8 <= j && j <= 21)
				keyboard[j][j - 7] = 2;
		}
	}

	//�˻� - �Ʒ���Ȯ�ο�
	//for (int i = 1; i <= 3; i++) {
	//	for (int j = 7 * i - 6; j <= 7 * i; j++) { //i��
	//		printf("%2d >> ", j);
	//		for (int k = 7 * (i+1) - 6; k <= 7 * (i+1); k++) { //(i+1)�� �Ʒ���
	//			if(1 <= i+1 || i+1 <= 3) //��ȿ�Ѱ͸�
	//				printf("%2d ", keyboard[j][k]);
	//		}
	//		printf("\n");
	//	}
	//	printf("\n");
	//}
	
	//�˻� - ����Ȯ�ο�
	//for (int i = 1; i <= 3; i++) {
	//	for (int j = 7 * i - 6; j <= 7 * i; j++) { //i��
	//		printf("%2d >> ", j);
	//		for (int k = 7 * (i - 1) - 6; k <= 7 * (i - 1); k++) { //(i-1)�� ����
	//			if (1 <= i - 1 || i - 1 <= 3) //��ȿ�Ѱ͸�
	//				printf("%2d ", keyboard[j][k]);
	//		}
	//		printf("\n");
	//	}
	//	printf("\n");
	//}
	
	//3 : �����Ʒ��� ��� Ű��
	// 1�� :  1~7
	// 2�� :  8~14
	// 3�� : 15~21
	for (int j = 1; j <= 7; j++) {
		//���ϴ�
		for (int k = j + 14; k <= 21 ; k++) {
			if (15 <= k && k <= 21)
				keyboard[j][k] = 2 * (k - j - 12); //���ϴ��� �̵������ �ٷι� 1�ν����Ͽ� 1������. ���������̰� 7���� ����
		}
		//���ϴ�
		for (int k = j + 14 - 2; 15 <= k; k--) { //�ٷι�������, �ٷιؿ��� ���ʺ��� �����Ͽ� �ٿ�����
			if(15 <= k && k <= 21)
				keyboard[j][k] = 2 * abs(14 - k + j); //���ϴ��� �ٷι��� ����Ű�� ����� 2���� ��� 
		}
		if (j != 1) {
			keyboard[j][14 + j - 1] = 4;
		}

	}

	for (int j = 15; j <= 21; j++) {
		//����
		for (int k = j - 14; k <= 7; k++) {
			if (1 <= k && k <= 7)
				keyboard[j][k] = 2 * (k - j + 14); //���ϴ��� �̵������ �ٷι� 1�ν����Ͽ� 1������. ���������̰� 7���� ����
		}
		//�»��
		for (int k = j - 14; 1 <= k; k--) { //�ٷι�������, �ٷιؿ��� ���ʺ��� �����Ͽ� �ٿ�����
			if (1 <= k && k <= 7)
				keyboard[j][k] = 2 * (j - k - 12); //���ϴ��� �ٷι��� ����Ű�� ����� 2���� ��� 
		}
		if (j != 21)
			keyboard[j][j - 13] = 4;
	}

	//�˻� - �Ʒ���Ȯ�ο�
	//for (int j = 1; j <= 7; j++) { //i��
	//	printf("%2d >> ", j);
	//	for (int k = 15; k <= 21; k++) { //�� �Ʒ���
	//		printf("%2d ", keyboard[j][k]);
	//	}
	//	printf("\n");
	//}

	//�˻� - ����Ȯ�ο�
	//for (int j = 15; j <= 21; j++) { //i��
	//	printf("%2d >> ", j);
	//	for (int k = 1; k <= 7; k++) { //(i-1)�� ����
	//		printf("%2d ", keyboard[j][k]);
	//	}
	//	printf("\n");
	//}

	//4 : ����Ű�� ������ 5�� Ű(22 23 24 25 26) ����
	for (int j = 1; j <= 7; j++) {
		keyboard[j][22] = 2 * (8 - j);
		keyboard[j][23] = 2 * (9 - j);
		keyboard[j][24] = 2 * (10 - j);
		keyboard[j][25] = 2 * (9 - j);
		keyboard[j][26] = 2 * (10 - j);
	}
	for (int j = 8; j <= 14; j++) {
		keyboard[j][22] = 2 * (7 + 8 - j);
		keyboard[j][23] = 2 * (7 + 9 - j);
		keyboard[j][24] = 2 * (7 + 10 - j);
		keyboard[j][25] = 2 * (7 + 8 - j);
		keyboard[j][26] = 2 * (7 + 9 - j);
	}for (int j = 15; j <= 21; j++) {
		keyboard[j][22] = 2 * (7 * 2 + 8 - j);
		keyboard[j][23] = 2 * (7 * 2 + 9 - j);
		keyboard[j][24] = 2 * (7 * 2 + 10 - j);
		keyboard[j][25] = 2 * (7 * 2 + 8 - j);
		keyboard[j][26] = 2 * (7 * 2 + 9 - j);
	}
	keyboard[21][22] = 4; //���� ������

	//5 : 22 23 24 25 26 Ű�� ����Ű�� ����
	for (int j = 7; j >= 1; j--) {
		keyboard[22][j] = 2 * (8 - j);
		keyboard[23][j] = 2 * (9 - j);
		keyboard[24][j] = 2 * (10 - j);
		keyboard[25][j] = 2 * (9 - j);
		keyboard[26][j] = 2 * (10 - j);
	}
	for (int j = 14; j >= 8; j--) {
		keyboard[22][j] = 2 * (7 + 8 - j);
		keyboard[23][j] = 2 * (7 + 9 - j);
		keyboard[24][j] = 2 * (7 + 10 - j);
		keyboard[25][j] = 2 * (7 + 8 - j);
		keyboard[26][j] = 2 * (7 + 9 - j);
	}
	for (int j = 21; j >= 15; j--) {
		keyboard[22][j] = 2 * (7 * 2 + 8 - j);
		keyboard[23][j] = 2 * (7 * 2 + 9 - j);
		keyboard[24][j] = 2 * (7 * 2 + 10 - j);
		keyboard[25][j] = 2 * (7 * 2 + 8 - j);
		keyboard[26][j] = 2 * (7 * 2 + 9 - j);
	}
	keyboard[22][21] = 4; //���� ������

	//6 : 22 23 24 25 26 Ű���� ����
	keyboard[22][23] = 2; keyboard[23][22] = 2;
	keyboard[22][24] = 4; keyboard[24][22] = 4;
	keyboard[22][25] = 2; keyboard[25][22] = 2;
	keyboard[22][26] = 4; keyboard[26][22] = 4;
	keyboard[23][24] = 2; keyboard[24][23] = 2;
	keyboard[23][25] = 2; keyboard[25][23] = 2;
	keyboard[23][26] = 2; keyboard[26][23] = 2;
	keyboard[24][25] = 4; keyboard[25][24] = 4;
	keyboard[24][26] = 2; keyboard[26][24] = 2;
	keyboard[25][26] = 2; keyboard[26][25] = 2;
}

//�Է¹��� ���ڸ� ���������� Ű������ �����ϴ� �Լ�
int findKEY(char c) {
	int res = -1;
	switch (c) {
	case 'A': res = 8; break; case 'B': res = 19; break;
	case 'C': res = 17; break; case 'D': res = 10; break;
	case 'E': res = 3; break; case 'F': res = 11; break;
	case 'G': res = 12; break; case 'H': res = 13; break;
	case 'I': res = 22; break; case 'J': res = 14; break;
	case 'K': res = 25; break; case 'L': res = 26; break;
	case 'M': res = 21; break; case 'N': res = 20; break;
	case 'O': res = 23; break; case 'P': res = 24; break;
	case 'Q': res = 1; break; case 'R': res = 4; break;
	case 'S': res = 9; break; case 'T': res = 5; break;
	case 'U': res = 7; break; case 'V': res = 18; break;
	case 'W': res = 2; break; case 'X': res = 16; break;
	case 'Y': res = 6; break; case 'Z': res = 15; break;
	}
	return res;
}

//�Է��� �ް� ����� �ϴ� �Լ�
void input() {
	int n;
	scanf("%d", &n);
	while (n--) {
		char in[101]; //�Է¹��� ����
		scanf("%s", &in);
		int size = 0; //�Է¹��� ���ڿ� ũ��
		int preKEY = -1;
		int res = 0;
		for (int i = 0; i < 101; i++) {
			if (in[i] == '\0') //���� ������ ����
				break;
			size++;

			int KEY = findKEY(in[i]); //�Է¹��� ���ڸ� ���� Ű������ ��ȯ
			if (i == 0) { //ó������ �հ����� �����ϴ� ��ġ�� ���߻�X
				preKEY = KEY;
				continue;
			}
			else {
				res += keyboard[preKEY][KEY]; //����Ű���� ����Ű���� ����� �߰�
				//printf("%2d => %2d ���:%2d\n", preKEY, KEY, keyboard[preKEY][KEY]); 
				preKEY = KEY; //����Ű ����
			}
		}
		res += size; //Ű�� ���������� 1�ʰ� �ɸ��Ƿ� ���ڿ����̸�ŭ �߰��ϸ� ���԰��
		printf("%d\n", res);
	}


}

//�˻�� ��� �Լ�
void ex_input() {
	while (true) {
		int c;
		scanf("%d", &c);
		printf("======================================================================\n");
		for (int i = 0; i <= 2; i++) {
			if (i == 1)
				printf(" ");
			if (i == 2)
				printf("  ");
			for (int j = 1; j <= 7; j++) {
				if (c == 7 * i + j) {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
					printf("%2d ", keyboard[c][7 * i + j]);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				}
				else {
					printf("%2d ", keyboard[c][7 * i + j]);
				}
			}
			if (i == 0) {
				if (c == 22) {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
					printf("%2d ", keyboard[c][22]);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				}
				else {
					printf("%2d ", keyboard[c][22]);
				}
				if (c == 23) {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
					printf("%2d ", keyboard[c][23]);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				}
				else {
					printf("%2d ", keyboard[c][23]);
				}
				if (c == 24) {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
					printf("%2d ", keyboard[c][24]);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				}
				else {
					printf("%2d ", keyboard[c][24]);
				}
			}
			else if (i == 1) {
				if (c == 25) {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
					printf("%2d ", keyboard[c][25]);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				}
				else {
					printf("%2d ", keyboard[c][25]);
				}
				if (c == 26) {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
					printf("%2d ", keyboard[c][26]);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				}
				else {
					printf("%2d ", keyboard[c][26]);
				}
			}
			printf("\n");
		}
		printf("======================================================================\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	}
}

int main(void) {
	makeKeyboard();
	ex_input(); //�˻��
	//input();
	return 0;
}