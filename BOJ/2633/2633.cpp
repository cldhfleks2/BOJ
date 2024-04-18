#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
using std::vector; using std::pair; using std::queue;
typedef pair<int, int> pii;
int x, y, end_x, end_y, n, ***map, **cost;
int max_x = 0, max_y = 0;
bool** visited;
struct obstacle {
	pii p1; pii p2; pii p3; pii p4;
};
int dx[5] = { 0, 0, 1, 0, -1 }; //X, ��, ��, ��, ��
int dy[5] = { 0, 1, 0, -1, 0 }; //X, ��, ��, ��, �� 

vector<obstacle> obstacleList;



void DEBUG1();
void DEBUG2();
void placeObstacle(pii p1, pii p2, pii p3, pii p4);
void input();
void makeMAP();
void findMAPSIZE(pii p1, pii p2, pii p3, pii p4);

//�κ� �̵��ϴ� �Լ�
void func() {
	
	//<<x, y>, <dir, res>> 
	//dir:�������� res:����Ƚ��
	//������������ map[][][0]�� map[][][1] �� ���� -1 ~ -4
	queue<pair<pii, pii>> move; 
	move.push({ { x,y }, {0, 0} }); 
	cost[x][y] = 0;
	
	while (!move.empty()) {
		int xx = move.front().first.first;
		int yy = move.front().first.second;
		int dir = move.front().second.first;
		int res = move.front().second.second;
		//�������� ����
		move.pop(); 

		//��������
		// if (xx == end_x && yy == end_y) continue;

		//���� ��ġ�� ť�� �ִ´�.
		if (map[xx][yy][0] <= 0 && map[xx][yy][1] <= 0) { //������� ��ֹ��������� ��ġ�Ѱ��
			for (int i = 1; i <= 4; i++) { //���ư� ����
				int next_x = xx + dx[i];
				int next_y = yy + dy[i];
				int next_dir = i; 
				//���� ����� ����
				if (next_x <= 0 || next_y <= 0 || max_x <= next_x || max_y <= next_y) continue;
				// ������ܿ� ��������� ���� ������ �ٸ��ٸ� ��Ƚ�� +1
				int next_res = res;
				if (dir != 0 && dir != next_dir)
					next_res += 1;
				if (cost[next_x][next_y] >= next_res) { //�ּҺ���̸� ����
					cost[next_x][next_y] = next_res;
					//ť�� �߰�
					move.push({ {next_x, next_y}, {next_dir, next_res} });
					//printf(">> �� %d,%d %d:%d\n", next_x, next_y, next_dir, next_res);
				}

			}
		}
		else { //��ֹ������� �����̴°��
			for (int k = 0; k <= 1; k++) { //������ �ι������� Ž���� �̾��
				int next_dir = map[xx][yy][k];
				int next_x = xx + dx[next_dir];
				int next_y = yy + dy[next_dir];
				
				//���� ����� ����
				if (next_x <= 0 || next_y <= 0 || max_x <= next_x || max_y <= next_y) continue;
				int next_res = res;
				if (dir != next_dir) next_res += 1;
				if (cost[next_x][next_y] >= next_res) {
					cost[next_x][next_y] = next_res;
					move.push({ {next_x, next_y}, {next_dir, next_res} });
					//printf(">> �� %d,%d %d:%d\n", next_x, next_y, next_dir, next_res);
				}
			}

		}


	}
	//�ּڰ� ���
	printf("%d", cost[end_x][end_y]); 

	//DEBUG1();
}

//�ʻ��¸� ����ϴ� �Լ�
void DEBUG1() { //��¿�
	printf(">>>>>>>>>>>>�� \n");
	for (int i = 0; i < max_x; i++) {
		for (int j = 0; j < max_y; j++) {
			if (i == x && j == y) {
				printf("O");
				continue;
			}
			if (i == end_x && j == end_y) {
				printf("X");
				continue;
			}
			if (map[i][j][0] == 0 && map[i][j][1] == 0) {
				printf(".");
			}
			else if (map[i][j][0] == -1 && map[i][j][1] == -2) {
				printf("��");
			}
			else if (map[i][j][0] == -2 && map[i][j][1] == -3) {
				printf("��");
			}
			else if (map[i][j][0] == -3 && map[i][j][1] == -4) {
				printf("��");
			}
			else if (map[i][j][0] == -1 && map[i][j][1] == -4) {
				printf("��");
			}
			else if (map[i][j][0] == 1 && map[i][j][1] == 3) {
				printf("��");
			}
			else if (map[i][j][0] == 2 && map[i][j][1] == 4) {
				printf("��");
			}
		}
		printf("\n");
	}

	printf(">>>>>>>>>>>>cost \n");
	for (int i = 0; i < max_x; i++) {
		for (int j = 0; j < max_y; j++)
			if (i == 0 || j == 0)
				printf("  X");
			else if (i == end_x && j == end_y)
				printf(" !%d", cost[i][j]);
			else if (i == x && j == y)
				printf(" !%d", cost[i][j]);
			else
				printf("%3d", cost[i][j]);
		printf("\n");
	}
}

//�ʿ� ��ֹ��� ��ġ�ϴ� �Լ�
void placeObstacle(pii p1, pii p2, pii p3, pii p4) {
	int type = -1; 
	int p1x = p1.first, p1y = p1.second;
	int p2x = p2.first, p2y = p2.second;
	int p3x = p3.first, p3y = p3.second;
	int p4x = p4.first, p4y = p4.second;
	int p11x, p11y, p33x, p33y;
	pii p11, p33;

	if (p2x < p4x && p2y < p4y)
		type = 1; // 1��
	else if (p2x < p4x && p4y < p2y)
		type = 2; // 2 ��
	else if (p4x < p2x && p2y < p4y)
		type = 3; // 3��
	else if (p4x < p2x && p4y < p2y)
		type = 4; // 4 ��
	
	if (type == 1) {
		p11 = { p4x, p1y }; p33 = { p3x, p4y };
		p11x = p11.first, p11y = p11.second; 
		p33x = p33.first, p33y = p33.second;
		//p2 -> p1 : y +
		for (int i = p2y; i < p1y; i++) {
			if (i == p2y) { //������
				map[p2x][i][0] = -1; map[p2x][i][1] = -2; continue;
			}
			map[p2x][i][0] = 1; map[p2x][i][1] = 3;
		}
		//p1 -> p11 : x +
		for (int i = p1x; i < p11x; i++) {
			if (i == p1x) {
				map[i][p1y][0] = -2; map[i][p1y][1] = -3; continue;
			}
			map[i][p1y][0] = 2; map[i][p1y][1] = 4; 
		}
		//p11 -> p4 : y -
		for (int i = p11y; i > p4y; i--) {
			if (i == p11y) {
				map[p11x][i][0] = -3; map[p11x][i][1] = -4; continue;
			}
			map[p11x][i][0] = 1; map[p11x][i][1] = 3;
		}
		//p4 -> p33 : x +
		for (int i = p4x; i < p33x; i++) {
			if (i == p4x) {
				map[i][p4y][0] = -1; map[i][p4y][1] = -2; continue;
			}
			map[i][p4y][0] = 2; map[i][p4y][1] = 4;
		}
		//p33 -> p3 : y -
		for (int i = p33y; i > p3y; i--) {
			if (i == p33y) {
				map[p33x][i][0] = -3; map[p33x][i][1] = -4; continue;
			}
			map[p33x][i][0] = 1; map[p33x][i][1] = 3;
		}
		//p3 -> p2 : x -
		for (int i = p3x; i > p2x; i--) {
			if (i == p3x) {
				map[i][p3y][0] = -1; map[i][p3y][1] = -4; continue;
			}
			map[i][p3y][0] = 2; map[i][p3y][1] = 4;
		}
	}
	else if (type == 2) {
		p11 = { p1x, p4y }; p33 = { p4x, p3y };
		p11x = p11.first, p11y = p11.second;
		p33x = p33.first, p33y = p33.second;
		//p2 -> p1 : x +
		for (int i = p2x; i < p1x; i++) {
			if (i == p2x) {
				map[i][p2y][0] = -2; map[i][p2y][1] = -3; continue;
			}
			map[i][p2y][0] = 2; map[i][p2y][1] = 4;
		}
		//p1 -> p11 : y -
		for (int i = p1y; i > p11y; i--) {
			if (i == p1y) {
				map[p1x][i][0] = -3; map[p1x][i][1] = -4; continue;
			}
			map[p1x][i][0] = 1; map[p1x][i][1] = 3;
		}
		//p11 -> p4 : x -
		for (int i = p11x; i > p4x; i--) {
			if (i == p11x) {
				map[i][p11y][0] = -1; map[i][p11y][1] = -4; continue;
			}
			map[i][p11y][0] = 2; map[i][p11y][1] = 4;
		}
		//p4 -> p33 : y -
		for (int i = p4y; i > p33y; i--) {
			if (i == p4y) {
				map[p4x][i][0] = -2; map[p4x][i][1] = -3; continue;
			}
			map[p4x][i][0] = 1; map[p4x][i][1] = 3;
		}
		//p33 -> p3 : x -
		for (int i = p33x; i > p3x; i--) {
			if (i == p33x) {
				map[i][p33y][0] = -1; map[i][p33y][1] = -4; continue;
			}
			map[i][p33y][0] = 2; map[i][p33y][1] = 4;
		}
		//p3 -> p2 : y +
		for (int i = p3y; i < p2y; i++) {
			if (i == p3y) {
				map[p3x][i][0] = -1; map[p3x][i][1] = -2; continue;
			}
			map[p3x][i][0] = 1; map[p3x][i][1] = 3;
		}
	}
	else if (type == 3) {
		p11 = { p1x, p4y }; p33 = { p4x, p3y };
		p11x = p11.first, p11y = p11.second;
		p33x = p33.first, p33y = p33.second;
		//p2 -> p1 : x -
		for (int i = p2x; i > p1x; i--) {
			if (i == p2x) {
				map[i][p2y][0] = -1; map[i][p2y][1] = -4; continue;
			}
			map[i][p2y][0] = 2; map[i][p2y][1] = 4;
		}
		//p1 -> p11 : y +
		for (int i = p1y; i < p11y; i++) {
			if (i == p1y) {
				map[p1x][i][0] = -1; map[p1x][i][1] = -2; continue;
			}
			map[p1x][i][0] = 1; map[p1x][i][1] = 3;
		}
		//p11 -> p4 : x +
		for (int i = p11x; i < p4x; i++) {
			if (i == p11x) {
				map[i][p11y][0] = -2; map[i][p11y][1] = -3; continue;
			}
			map[i][p11y][0] = 2; map[i][p11y][1] = 4;
		}
		//p4 -> p33 : y +
		for (int i = p4y; i < p33y; i++) {
			if (i == p4y) {
				map[p4x][i][0] = -1; map[p4x][i][1] = -4; continue;
			}
			map[p4x][i][0] = 1; map[p4x][i][1] = 3;
		}
		//p33 -> p3 : x +
		for (int i = p33x; i < p3x; i++) {
			if (i == p33x) {
				map[i][p33y][0] = -2; map[i][p33y][1] = -3; continue;
			}
			map[i][p33y][0] = 2; map[i][p33y][1] = 4;
		}
		//p3 -> p2 :  y -
		for (int i = p3y; i > p2y; i--) {
			if (i == p3y) {
				map[p3x][i][0] = -3; map[p3x][i][1] = -4; continue;
			}
			map[p3x][i][0] = 1; map[p3x][i][1] = 3;
		}
	}
	else if (type == 4) {
		p11 = { p4x, p1y }; p33 = { p3x, p4y };
		p11x = p11.first, p11y = p11.second;
		p33x = p33.first, p33y = p33.second;
		//p2 -> p1 : y -
		for (int i = p2y; i > p1y; i--) {
			if (i == p2y) {
				map[p2x][i][0] = -3; map[p2x][i][1] = -4; continue;
			}
			map[p2x][i][0] = 1; map[p2x][i][1] = 3;
		}
		//p1 -> p11 : x -
		for (int i = p1x; i > p11x; i--) {
			if (i == p1x) {
				map[i][p1y][0] = -1; map[i][p1y][1] = -4; continue;
			}
			map[i][p1y][0] = 2; map[i][p1y][1] = 4;
		}
		//p11 -> p4 : y +
		for (int i = p11y; i < p4y; i++) {
			if (i == p11y) {
				map[p11x][i][0] = -1; map[p11x][i][1] = -2; continue;
			}
			map[p11x][i][0] = 1; map[p11x][i][1] = 3;
		}
		//p4 -> p33 : x -
		for (int i = p4x; i > p33x; i--) {
			if (i == p4x) {
				map[i][p4y][0] = -3; map[i][p4y][1] = -4; continue;
			}
			map[i][p4y][0] = 2; map[i][p4y][1] = 4;
		}
		//p33 -> p3 : y +
		for (int i = p33y; i < p3y; i++) {
			if (i == p33y) {
				map[p33x][i][0] = -1; map[p33x][i][1] = -2; continue;
			}
			map[p33x][i][0] = 1; map[p33x][i][1] = 3;
		}
		//p3 -> p2 : x +
		for (int i = p3x; i < p2x; i++) {
			if (i == p3x) {
				map[i][p3y][0] = -2; map[i][p3y][1] = -3; continue;
			}
			map[i][p3y][0] = 2; map[i][p3y][1] = 4;
		}
	}
	
}

//��� �Է¹޴� �Լ�
void input() {
	scanf("%d%d%d%d%d", &x, &y, &end_x, &end_y, &n);
	findMAPSIZE({ x, y }, { end_x, end_y }, { 0, 0 }, { 0, 0 }); //���,������ǥ�� ���
	
	//�Է¹���
	for (int i = 0; i < n; i++) { 
		pii p1, p2, p3, p4;
		scanf("%d%d%d%d%d%d%d%d", &p1.first, &p1.second,
			&p2.first, &p2.second, &p3.first, &p3.second,
			&p4.first, &p4.second);
		obstacle obs = { p1, p2, p3, p4 };
		obstacleList.push_back(obs); //��ֹ� ����Ʈ�� �߰�
		findMAPSIZE(p1, p2, p3, p4); //�ʻ����� ����
	}
	
	makeMAP();

	for (int i = 0; i < obstacleList.size(); i++) //��� ��ֹ��� ��ġ
		placeObstacle(obstacleList[i].p1, obstacleList[i].p2, 
			obstacleList[i].p3, obstacleList[i].p4);
}

//���� ����(�ʱ�ȭ)�ϴ� �Լ�
void makeMAP() {
	max_x++; //������ǥ�� 0,0 ���ͽ����̹Ƿ� +1
	max_y++;
	//map[x��ǥ][y��ǥ] => [2] �ΰ�����(�̵������� ����)�� ����
	//�ʱ갪�� ��� 0 ���� ����
	map = new int** [max_x];
	for (int i = 0; i < max_x; i++) {
		map[i] = new int* [max_y];
		for (int j = 0; j < max_y; j++) {
			map[i][j] = new int[2];
			map[i][j][0] = 0;
			map[i][j][1] = 0;
		}
	}
	//cost �ʱ�ȭ -> �ּҺ���� ����ϱ����� �ִ����� �ʱ�ȭ
	cost = new int* [max_x];
	for (int i = 0; i < max_x; i++) {
		cost[i] = new int[max_y];
		for (int j = 0; j < max_y; j++)
			cost[i][j] = 0x7fffffff;
	}
	//visited �ʱ�ȭ
	visited = new bool* [max_x];
	for (int i = 0; i < max_x; i++) {
		visited[i] = new bool[max_y];
		for (int j = 0; j < max_y; j++)
			visited[i][j] = false;
	}
	
}

//���� �ִ�ũ�⸦ �����ϴ� �Լ�
void findMAPSIZE(pii p1, pii p2, pii p3, pii p4) {
	//max_x
	if (max_x < p1.first) max_x = p1.first;
	if (max_x < p2.first) max_x = p2.first;
	if (max_x < p3.first) max_x = p3.first;
	if (max_x < p4.first) max_x = p4.first;
	//max_y
	if (max_y < p1.second) max_y = p1.second;
	if (max_y < p2.second) max_y = p2.second;
	if (max_y < p3.second) max_y = p3.second;
	if (max_y < p4.second) max_y = p4.second;
}

int main(void) {
	input();
	func();

	return 0;
}

