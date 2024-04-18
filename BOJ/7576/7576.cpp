#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
using std::vector; using std::pair; using std::queue;
typedef pair<int, int> pii;
/*
������ �丶�� : 1
���� �丶��� : -1
days : �丶�䰡 ��� �ʹµ� �ɸ��� ��¥
ripeTomato : 1ȸ��, �����丶�� ��ǥ
unripeTomato : 1ȸ��, ������ �丶�� ��ǥ
changeTomato : BFS�� Ž���� ������ �丶�� ��ǥ
*/
int n, m, ** tomato, unripeTomatoCnt, **tomatoDays;
bool** visited;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
vector<pii> ripeTomato, unripeTomato, changeTomato;
queue <pair<pii, int>> loc;
void init();
void becomeRipe();
void func();

void func() {
	init();
	becomeRipe();
}

//���� �丶�並 �������� ��� �������丶�並 ������.
//BFS����ϵ�, ��� ���� �丶�� ��ǥ���� days�� +1 �� �÷����� Ž���ϴµ�,
//������ �丶�並 ���������� �ּڰ��� �����ؾ���.
//�� �������丶��, �ϳ��� ��ǥ�� ������ �湮�ؾ��ϹǷ�,
//�湮 check�� �����ʰ� �ߺ��湮��
void becomeRipe() { 
	//ó���� ��� �����丶����ǥ�� ���������� ���� ����
	for (int k = 0; k < ripeTomato.size(); k++) { 
		int start_x = ripeTomato[k].first;
		int start_y = ripeTomato[k].second;
		loc.push({ {start_x, start_y}, 1 });
	}

	while (!loc.empty()) {
		int x = loc.front().first.first; //������ġ (x, y)
		int y = loc.front().first.second;
		int days = loc.front().second;
		loc.pop();

		for (int dir = 0; dir < 4; dir++) { //���� 4����(��,��,��,��)
			int xx = x + dx[dir]; //������ġ (xx, yy)
			int yy = y + dy[dir];
			//������ ������ ����
			if (xx < 0 || yy < 0 || xx == n || yy == m) continue; 
			//�����丶�䳪 ������� ������ ����
			if (tomato[xx][yy] == -1 || tomato[xx][yy] == 0) continue;
			//�ش���ġ�� �丶�䰡 ������ �ϼ��� �׻� �ּڰ��̾����
			if (tomatoDays[xx][yy] > days) { 
				tomatoDays[xx][yy] = days;
				loc.push({ {xx, yy}, days + 1 }); //�ּڰ����� Ž���� �̾��
			}
		}

	}

	int res = 0; //���� �ϼ�
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			if (tomatoDays[i][j] == 0x7fffffff) { 
				//������ �丶���� �ϼ��� �ʱ갪(0x7fffffff)�̸� ���Ȱ��̹Ƿ�
				//������ ���ǿ����� -1 ���
				if (tomato[i][j] == 1) { 
					printf("-1");
					return;
				}
			}
			else {
				if (res < tomatoDays[i][j]) //�ּڰ��� ã�ư�
					res = tomatoDays[i][j]; 
			}

		}
	
	printf("%d", res);
}

void init() {
	scanf("%d%d", &m, &n);
	tomato = new int* [n];
	visited = new bool* [n];
	tomatoDays = new int* [n];
	for (int i = 0; i < n; i++) {
		tomato[i] = new int[m];
		visited[i] = new bool[m];
		tomatoDays[i] = new int[m];
		for (int j = 0, _; j < m; j++) {
			scanf("%d", &_);
			if (_ == 1) {
				tomato[i][j] = -1; //������
				ripeTomato.push_back({ i, j });
			}
			else if (_ == 0) {
				tomato[i][j] = 1; //��������
				unripeTomato.push_back({ i, j });
				unripeTomatoCnt++; //�������丶�䰹����
			}
			else if(_ == -1)
				tomato[i][j] = 0; //�����

			tomatoDays[i][j] = 0x7fffffff; //�ִ����� �ʱ�ȭ
		}
	}

}


int main(void) {
	func();
	return 0;
}