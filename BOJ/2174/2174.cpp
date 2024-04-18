#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
int a, b, n, m, **map, **robots; 
int dx[5] = {0, 1, 0, -1, 0}; //E:1  S:2  W:3  N:4 (�ð����)
int dy[5] = {0, 0, 1, 0, -1};

void playGame() {
	int r, cnt; //�κ���ȣr �ݺ�Ƚ��cnt
	char order; //��ɾ�
	bool END_GAME = false;
	while (m--) {
		scanf("%d%c%c%d", &r, &order, &order, &cnt);
		int y, x, dir; //x, y��ǥ, �������dir
		for(int i = 0 ; i < b; i++)
			for(int j = 0 ; j < a ; j++)
				if (robots[i][j] == r) { //�κ���ġ�� ã��
					y = i; x = j; dir = map[i][j];
				}
		if (END_GAME)
			continue;

		if (order == 'L') { //�ݽð���� ��
			while (cnt--) {
				dir--;
				if (dir == 0)
					dir = 4;
			}
			map[y][x] = dir; //�缳��
		}
		else if (order == 'R') { //�ð���� ��
			while (cnt--) {
				dir++;
				if (dir == 5)
					dir = 1;
			}
			map[y][x] = dir;
		}
		else if (order == 'F') { //����
			int yy = y, xx = x; //������ġ
			while (cnt--) {
				//�κ���ġ ����1
				robots[yy][xx] = 0;
				map[yy][xx] = 0;
				yy += dy[dir]; xx += dx[dir];  //������ġ ���
				//�����ε����°��
				if (yy <= -1 || b <= yy || xx <= -1 || a <= xx) {
					printf("Robot %d crashes into the wall", r);
					END_GAME = true;
					break;
				}
				//�κ��� �浹�ϴ°��
				if (!END_GAME && robots[yy][xx] != 0) {
					printf("Robot %d crashes into robot %d", r, robots[yy][xx]);
					END_GAME = true;
					break;
				}
				//�κ���ġ ����2
				robots[yy][xx] = r;
				map[yy][xx] = dir;

			}
		}

	}

	if (!END_GAME) printf("OK");
}

int main(char c) {
	scanf("%d%d%d%d", &a, &b, &n, &m);
	map = new int* [b];
	robots = new int* [b];
	for (int i = 0; i < b; i++) {
		map[i] = new int[a];
		robots[i] = new int[a];
		for (int j = 0; j < a; j++) {
			map[i][j] = 0; //�ʱ�ȭ
			robots[i][j] = 0;
		}
	}

	for (int i = 0, x, y; i < n; i++) {
		scanf("%d%d%c%c", &x, &y, &c, &c); //%c%c:�����а� ����������
		if (c == 'E') {
			map[b - y][x - 1] = 1; //�Է���ǥ�� ���
		}
		else if (c == 'S') {
			map[b - y][x - 1] = 2;
		}
		else if (c == 'W') {
			map[b - y][x - 1] = 3;
		}
		else if (c == 'N') {
			map[b - y][x - 1] = 4;
		}
		robots[b - y][x - 1] = i + 1; //�κ���ȣ���
	}

	playGame();

	return 0;
}