#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
using std::queue; using std::vector; using std::pair;

int R, C, map[50][50];
int dxy[][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
bool water_visit[50][50], hed_visit[50][50];
int time = 1;
/*
map�� ����� ��:
1: ��
2: ��
3: ����ġ
4: ������
*/
/*
�ʿ��ִ� ��� ����ġ�� ������� ��ĭ �̵�
1 : ����ġ�� ���� ã��
0 : ����ġ�� ���� ã�� ����
-1 : ����ġ�� �ϴ� ����
*/
int hed_move() {
	int cnt = 0; //����ġ ����
	//��� ����ġ�� ã�Ƽ� ť������
	queue<pair<int, int>> hed;
	for (int i = 0; i < R; i++) 
		for (int j = 0; j < C; j++) 
			if (map[i][j] == 3) {
				hed.push({ i, j });
				cnt++;
			}

	if (cnt == 0) return -1; //����ġ�� �Ѹ����� �ȳ������� ����!

	//ä���� ť�� �ٰŷ� BFS����
	while (!hed.empty()) {
		int x = hed.front().first;
		int y = hed.front().second;
		hed.pop();
		map[x][y] = 0; //�ʿ��� ����ġ�� ����

		for (int d = 0; d < 4; d++) {
			int xx = x + dxy[d][0];
			int yy = y + dxy[d][1];
			//��, ���� ������ ����
			if (xx < 0 || yy < 0 || xx == R || yy == C || hed_visit[xx][yy] || map[xx][yy] == 1 || map[xx][yy] == 2) continue;
			hed_visit[xx][yy] = true;
			if (map[xx][yy] == 4) return 1; //����ġ�� ���� Ż���ϸ� ����
			map[xx][yy] = 3; //����ġ ��ĭ �̵�
		}
		
	}

	return 0; //����ġ�� ���� ���� �߰����� ����
}

//�ʿ� �ִ� ��� ���� ������� ��ĭ �̵�
void water_move() {
	//�湮�迭 �ʱ�ȭ
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			water_visit[i][j] = false;

	//�ʿ��ִ� ��� ���� ť�� ����
	queue<pair<int, int>> q;
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			if (map[i][j] == 2) {
				q.push({ i, j }); //ť�� �ְ�
				water_visit[i][j] = true; //�湮 üũ����
			}

	//ä���� ť�� �ٰŷ� BFS���� 
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int d = 0; d < 4; d++) {
			int xx = x + dxy[d][0];
			int yy = y + dxy[d][1];
			//���� �������δ� �� �� ����.
			if (xx < 0 || yy < 0 || xx == R || yy == C || water_visit[xx][yy] || map[xx][yy] == 1 || map[xx][yy] == 4) continue;
			water_visit[xx][yy] = true;
			map[xx][yy] = 2; //�� ��ĭ �̵�
		}
	}

}

void func() {
	while (1) {
		int res = hed_move();
		if (res == 1) { //����ġ�� ������� Ż���� ���
			printf("%d", time); //�� �ɸ� �ð��� �����ϰ� ���α׷� ����
			return;
		}
		else if (res == -1) { //����ġ�� �� �������
			printf("KAKTUS");
			return;
		}

		water_move(); //���� ��ĭ �̵�

		time++;
	}
}

int main(void) {
	scanf("%d%d", &R, &C);
	for (int i = 0; i < R; i++) {
		char c;
		scanf("%c", &c);//�ٹٲ޹��� ����
		for (int j = 0; j < C; j++) {
			scanf("%c", &c);
			switch (c) {
			case 'X': map[i][j] = 1;
				break;
			case '*' : map[i][j] = 2;
				break;
			case 'S': map[i][j] = 3;
				hed_visit[i][j] = true; //�湮 üũ ���� ���ش�. �ʱ갪
				break;
			case 'D': map[i][j] = 4;
				break;
			default: map[i][j] = 0;
				break;
			}
		}
	}

	func();
	
	return 0;
}