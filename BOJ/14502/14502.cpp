#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
using std::vector; using std::pair; using std::queue;
typedef pair<int, int> pii;
/*
map : �ʱ��Է°�
virusMap : ������ ��ġ�� ��3���� ������� ��
visited : BFS���� �ߺ��湮�� �������� �湮üũ�� �迭
virus : ���̷���(��ǥ) ����Ʈ
black : �����(��ǥ) ����Ʈ
loc : BFS���� ����� ť
safetyArea : BFS���� ������ ��������ũ���� �ִ�
*/
int n, m, **map, safetyArea=0;
int** visited;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
vector<pii> virus, blank;
queue<pii> loc;
void init();
int virusSpread();
void clear();
void resetVirusMap(int a, int b, int c);
void replaceMap(int a, int b, int c);
void selectWallLoc(int num, vector<int>& selected, int cnt);
void func();

void func() {
	vector<int> selected;
	int size = blank.size();
	selectWallLoc(size, selected, 3); //������� 3���� �����ϴ� ��츦 ��.

	printf("%d", safetyArea); //�������� �ִ�ũ�� ���
}

void selectWallLoc(int num, vector<int>& selected, int cnt) {
	if (cnt == 0) { //3���� �����ѵڿ�
		//���̷�����������
		replaceMap(selected[0], selected[1], selected[2]);
		//��������� ���̷����� ��Ʈ����
		int res = virusSpread();
		if (safetyArea < res) safetyArea = res; 
		//���̷������� �ʱ�ȭ
		resetVirusMap(selected[0], selected[1], selected[2]);
		return;
	}
	int cursor = selected.empty() ? 0 : selected.back() + 1;
	for (int i = cursor; i < num; i++) {
		selected.push_back(i); //�����Ѹ�Ͽ� ����
		selectWallLoc(num, selected, cnt - 1); //��������� cnt���� ����
		selected.pop_back(); //�����ѿ�Ҹ� ��
	}
}

void replaceMap(int a, int b, int c) { //�����a,b,c�� ��������
	map[blank[a].first][blank[a].second] = 1; 
	map[blank[b].first][blank[b].second] = 1;
	map[blank[c].first][blank[c].second] = 1;
}

void resetVirusMap(int a, int b, int c) {//a,b,c�� �����㹰�� ���������
	map[blank[a].first][blank[a].second] = 0;
	map[blank[b].first][blank[b].second] = 0;
	map[blank[c].first][blank[c].second] = 0;
}

//�湮 �迭 �ʱ�ȭ
void clear() {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			visited[i][j] = false;

}

//���̷����� ��Ʈ���� ���� ��������ũ�⸦ ������
int virusSpread() {
	clear();
	int res = blank.size() - 3; //�������� ũ�� : ����3�����������Ƿ� -3
	//ó�� ���̷�����ġ�� �ѹ��� ť�� �ְ� BFS����
	for (int k = 0; k < virus.size(); k++) {
		int start_x = virus[k].first;
		int start_y = virus[k].second;
		loc.push({ start_x, start_y });
		visited[start_x][start_y] = true;
	}
	//BFS
	while (!loc.empty()) {
		int x = loc.front().first;
		int y = loc.front().second;
		loc.pop();

		for (int dir = 0; dir < 4; dir++) {
			int xx = x + dx[dir];
			int yy = y + dy[dir];

			if (xx < 0 || yy < 0 || xx == n || yy == m) continue; //��������� ����
			if (map[xx][yy] == 1 || map[xx][yy] == 2) continue; //��, ���̷����� ������ ����
			if (!visited[xx][yy]) { //������̰� ó�� �湮�Ѱ��̸� ��������ũ�� -1
				visited[xx][yy] = true;
				res--;
				loc.push({ xx, yy }); //�̾ Ž��
			}
		}
	}

	return res;
}

void init() {
	scanf("%d%d", &n, &m);
	map = new int* [n];
	visited = new int* [n];
	for (int i = 0; i < n; i++) {
		map[i] = new int[m];
		visited[i] = new int[m];
		for (int j = 0; j < m; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 2) //���̷��� ��ġ ���
				virus.push_back({ i, j });
			if (map[i][j] == 0) //����� ��ġ ���
				blank.push_back({ i, j });
		}
	}
}

int main(void) {
	init();
	func();

	return 0;
}