#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
using std::vector; using std::pair; using std::queue;
/*
������ �丶�� : 1
���� �丶��� : -1
ripeTomato : 1ȸ��, �����丶�� ��ǥ
unripeTomato : 1ȸ��, ������ �丶�� ��ǥ
*/
int n, m, h, ***tomato, unripeTomatoCnt, ***tomatoDays;
int dx[6] = {0, 0, 0, 1, 0, -1 };
int dy[6] = {0, 0, 1, 0, -1, 0 };
int dz[6] = { 1, -1, 0, 0, 0, 0 };
struct Point {
	int x; int y; int z;
};
vector<Point> ripeTomato, unripeTomato;
queue <pair<Point, int>> loc;
void init();
void becomeRipe();

//���� �丶�並 �������� ��� �������丶�並 ������.
//BFS����ϵ�, ��� ���� �丶�� ��ǥ���� days�� +1 �� �÷����� Ž���ϴµ�,
//������ �丶�並 ���������� �ּڰ��� �����ؾ���.
//�� �������丶��, �ϳ��� ��ǥ�� ������ �湮�ؾ��ϹǷ�,
//�湮 check�� �����ʰ� �ߺ��湮��
void becomeRipe() {
	//ó���� ��� �����丶����ǥ�� ���������� ���� ����
	for (int k = 0; k < ripeTomato.size(); k++) {
		int start_x = ripeTomato[k].x;
		int start_y = ripeTomato[k].y;
		int start_z = ripeTomato[k].z;
		loc.push({ Point{start_x, start_y, start_z}, 1 });
	}

	while (!loc.empty()) {
		int x = loc.front().first.x; //������ġ (x, y)
		int y = loc.front().first.y;
		int z = loc.front().first.z;
		int days = loc.front().second;
		loc.pop();

		for (int dir = 0; dir < 6; dir++) { //���� 4����(��,��,��,��)
			int xx = x + dx[dir]; //������ġ (xx, yy)
			int yy = y + dy[dir];
			int zz = z + dz[dir];
			//������ ������ ����
			if (xx < 0 || yy < 0 || zz < 0 || 
				xx == n || yy == m || zz == h) continue;
			//�����丶�䳪 ������� ������ ����
			if (tomato[xx][yy][zz] == -1 || tomato[xx][yy][zz] == 0) continue;
			//�ش���ġ�� �丶�䰡 ������ �ϼ��� �׻� �ּڰ��̾����
			if (tomatoDays[xx][yy][zz] > days) {
				tomatoDays[xx][yy][zz] = days;
				loc.push({ {xx, yy, zz}, days + 1 }); //�ּڰ����� Ž���� �̾��
			}
		}

	}

	int res = 0; //���� �ϼ�
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) 
			for (int k = 0; k < h; k++) {
				if (tomatoDays[i][j][k] == 0x7fffffff) {
					//������ �丶���� �ϼ��� �ʱ갪(0x7fffffff)�̸� ���Ȱ��̹Ƿ�
					//������ ���ǿ����� -1 ���
					if (tomato[i][j][k] == 1) {
						printf("-1");
						return;
					}
				}
				else {
					if (res < tomatoDays[i][j][k]) //�ּڰ��� ã�ư�
						res = tomatoDays[i][j][k];
				}
			}

	printf("%d", res);
}

void init() {
	scanf("%d%d%d", &m, &n, &h);
	tomato = new int**[n];
	tomatoDays = new int**[n];
	for (int i = 0; i < n; i++) {
		tomato[i] = new int* [m];
		tomatoDays[i] = new int* [m];
		for (int j = 0; j < m; j++) {
			tomato[i][j] = new int[h];
			tomatoDays[i][j] = new int[h];
		}
	}

	for (int k = 0; k < h; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0, _; j < m; j++) {
				scanf("%d", &_);
				if (_ == 1) {
					tomato[i][j][k] = -1; //������
					ripeTomato.push_back(Point{ i, j, k });
				}
				else if (_ == 0) {
					tomato[i][j][k] = 1; //��������
					unripeTomato.push_back(Point{ i, j, k });
					unripeTomatoCnt++; //�������丶�䰹����
				}
				else if (_ == -1)
					tomato[i][j][k] = 0; //�����

				tomatoDays[i][j][k] = 0x7fffffff; //�ִ����� �ʱ�ȭ
			}
		}
	}

}

int main(void) {
	init();
	becomeRipe();
	return 0;
}