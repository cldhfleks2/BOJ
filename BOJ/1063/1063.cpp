#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>

void printAll(int a, int b) {
	int x = 8 - a;
	char y = b + 65;
	printf("%c%d \n", y, x);
}

int main(void) {
	int kingX, kingY, stoneX, stoneY, n;
	char init_kingY, init_kingX, init_stoneY, init_stoneX;
	scanf("%c%c %c%c %d\n", &init_kingY, &init_kingX, &init_stoneY, &init_stoneX, &n);
	kingX = 7 - (init_kingX - 49);
	kingY = init_kingY - 65;
	stoneX = 7 - (init_stoneX - 49);
	stoneY = init_stoneY - 65;
	char c[3], temp;

	while (n--) {
		scanf("%[^\n]s", &c); //��ɾ �о����.
		scanf("%c", &temp); //�ٹٲ޹��� ����
		//������ ����� ����
		int flag = 0;
		//���οŰ��� ŷ, ����ġ
		int kX=kingX, kY=kingY, sX=stoneX, sY=stoneY; 
		//ŷ�� �����̰� ������ ����flag�� ���
		if (c[0] == 'R' && c[1] == '\0') {
			flag = 1;
			kY++;
		}
		else if (c[0] == 'L' && c[1] == '\0') {
			flag = 2;
			kY--;
		}
		else if (c[0] == 'B' && c[1] == '\0') {
			flag = 3;
			kX++;
		}
		else if (c[0] == 'T' && c[1] == '\0') {
			flag = 4;
			kX--;
		}
		else if (c[0] == 'R' && c[1] == 'T') {
			flag = 5;
			kX--;
			kY++;
		}
		else if (c[0] == 'L' && c[1] == 'T') {
			flag = 6;
			kX--;
			kY--;
		}
		else if (c[0] == 'R' && c[1] == 'B') {
			flag = 7;
			kX++;
			kY++;
		}
		else if (c[0] == 'L' && c[1] == 'B') {
			flag = 8;
			kX++;
			kY--;
		}

		//���� ŷ�̰��ƴٸ� ���� ������
		if (sX == kX && sY == kY) {
			switch (flag) {
			case 1:
				sY++;
				break;
			case 2:
				sY--;
				break;
			case 3:
				sX++;
				break;
			case 4:
				sX--;
				break;
			case 5:
				sX--;
				sY++;
				break;
			case 6:
				sX--;
				sY--;
				break;
			case 7:
				sX++;
				sY++;
				break;
			case 8:
				sX++;
				sY--;
				break;
			}
		}

		//���Ǵ� ŷ�� ü���ǹ����� �������� Ȯ��
		if (sX == -1 || sX == 8 ||
			sY == -1 || sY == 8 ||
			kX == -1 || kX == 8 ||
			kY == -1 || kY == 8) {
		}
		else {
			kingX = kX;
			kingY = kY;
			stoneX = sX;
			stoneY = sY;
		}

	}
	printAll(kingX, kingY);
	printAll(stoneX, stoneY);

	return 0;
}