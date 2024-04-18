#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
long map[8][8];
char command;

//L D R U 
int dx[] = { 0, -1, 0, 1 };
int dy[] = { 1, 0, -1, 0 };
void init();
void move(int end_x, int end_y, int dir);
void func();
void printAll();


void init() {
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			scanf("%ld", &map[i][j]);

	scanf("%c", &command); 
	scanf("%c", &command);
}
//dir�������� (end_x, end_y)���� 1ĭ�� ����
void move(int end_x, int end_y, int dir) { 
	int x = end_x;
	int y = end_y;
	while (1) {
		int xx = x + dx[dir]; //dir������ �ݴ���� ����
		int yy = y + dy[dir];
		if (xx == -1 || yy == -1 || xx == 8 || yy == 8) {
			map[x][y] = 0; //���ο���� �����
			break; //�ݺ�����
		}
		map[x][y] = map[xx][yy]; //dir�������� ��ĭ����

		x += dx[dir];
		y += dy[dir];

	}
}

void func() {
	int p1, p2, blankCnt, dir;
	if (command == 'L') { //y++
		dir = 0; 
		for (int k = 0; k < 8; k++) {
			p1 = 7; p2 = 6;
			while (0 <= p1) {
				//1. p1�� ������̸�
				if (map[k][p1] == 0) {
					p1--; //p1�� ������ Ž��
					p2 = p1 - 1; 
				} //2. p1�� ���ڶ��
				else {
					//2-1. p1���� 'L'�������� Ž���� ����
					//���ڹ߽߰� p2�� �ش���ġ�� ����Ŵ
					for (; 0 <= p2; p2--) if (map[k][p2] != 0) break;

					//2-2. p2�� p1�� �ٵ��� p1�� �����
					if (p2 + 1 != p1) 
						for (p1 = p1 - 1; p2 + 1 <= p1; p1--)
							move(k, p1, dir);
					else
						p1 = p2; //p2, p1�� ���Ե�

					//���� p2 == p1�λ���
					
					//2-3-1. p2�� 0�̶�� �ǳ��������ߴ���
					if (map[k][p2] == 0) {
						move(k, p2, dir); //p1�� �ǳ����� ����
						
						break; //���� k��Ž��

					} //2-3-2. p2�� p1�� ���� �����
					else if (map[k][p2] == map[k][p2 + 1]) {
						move(k, p2, dir); 
						map[k][p2] *= map[k][p2]; //p2�� ����
						p1--; //�ٲ� p2�� L�������� p1�� ���� => ��Ÿ���� �ι��̻� �ٲ�������
						p2 = p1 - 1;

					} //2-3-3. p2�� p1�� �ٸ� �����
					else if (map[k][p2] != map[k][p1]) {
						p2 = p1 - 1;
					}
					

				}
				printf("===========���� �ΰ�==============\n");
				//printAll();
			}
			////���� ������� ����
			//blankCnt = 7;
			//while (map[k][0] == 0 && blankCnt > 0) {
			//	move(k, 0, dir);
			//	blankCnt--;
			//}

			printf("========%d ��°========================\n", k);
			printAll();
		}



	}
	else if(command == 'D') { //x--
		dir = 1;
		

	}
	else if (command == 'R') { //y--
		dir = 2;
		

	}
	else if(command == 'U') { //x++
		dir = 3;
		

	}

}

void printAll() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++)
			printf("%ld ", map[i][j]);
		printf("\n");
	}
}

int main(void) {
	init();
	func();
	//printAll();

	return 0;
}