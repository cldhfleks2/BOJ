#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
using std::vector;
using std::pair;
vector<pair<int, int>> queen, knight, pawn;
int n, m, qn, kn, pn, **map; //map: �Է¹��� ü���� ��ġ ���
bool** res; //�����Ѱ����� check

int printAll() {
	int cnt = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (res[i][j])
				cnt++;
	return cnt;
}

void make_map() {
	//�� ����� �ʱ�ȭ
	map = new int* [n];
	res = new bool* [n];
	for (int i = 0; i < n; i++) {
		map[i] = new int[m];
		res[i] = new bool[m];
		for (int j = 0; j < m; j++) {
			map[i][j] = 0; // ó���� ��� ��������� ���
			res[i][j] = true; //ó���� ��� �����Ѱ����� ���
		}
	}

	//queen��ġ => 1 ���
	for (int i = 0; i < qn; i++) {
		int x = queen[i].first, y = queen[i].second;
		map[x][y] = 1;
		res[x][y] = false;
	}
	//knight��ġ => 2 ���
	for (int i = 0; i < kn; i++) {
		int x = knight[i].first, y = knight[i].second;
		map[x][y] = 2;
		res[x][y] = false;
	}
	//pawn��ġ => 3 ���
	for (int i = 0; i < pn; i++) {
		int x = pawn[i].first, y = pawn[i].second;
		map[x][y] = 3;
		res[x][y] = false;
	}
}

void queen_check() { //��ֹ� ��� O
	for (int k = 0; k < qn; k++) { //��������ŭ�ݺ�
		int x = queen[k].first, y = queen[k].second; //�������� ��ǥ
		
		//�� Ž��
		for (int i = y - 1; i >= 0; i--) {
			if (map[x][i] != 0) //��ֹ������� ��ž
				break;
			res[x][i] = false; //���� �̵������ϹǷ� ��������������
		}
		//�� Ž��
		for (int i = y + 1; i < m; i++) {
			if (map[x][i] != 0) 
				break;
			res[x][i] = false; 
		}
		//�� Ž��
		for (int i = x - 1; i >= 0; i--) {
			if (map[i][y] != 0)
				break;
			res[i][y] = false;
		}
		//�� Ž��
		for (int i = x + 1; i < n; i++) {
			if (map[i][y] != 0)
				break;
			res[i][y] = false;
		}
		
		//�� Ž��
		for (int gap = 1; ; gap++) {
			if (x - gap <= -1 || y - gap <= -1) //������ ������ ��ž
				break;
			if (map[x - gap][y - gap] != 0) //�ٸ� ü������ ���ΰ�� ��ž
				break;
			res[x - gap][y - gap] = false;
		}
		//�� Ž��
		for (int gap = 1; ; gap++) {
			if (x + gap >= n || y + gap >= m) 
				break;
			if (map[x + gap][y + gap] != 0) 
				break;
			res[x + gap][y + gap] = false;
		}
		//�� Ž��
		for (int gap = 1; ; gap++) {
			if (x - gap < 0 || y + gap >= m) 
				break;
			if (map[x - gap][y + gap] != 0) 
				break;
			res[x - gap][y + gap] = false;
		}
		//�� Ž��
		for (int gap = 1; ; gap++) {
			if (x + gap >= n || y - gap < 0) 
				break;
			if (map[x + gap][y - gap] != 0) 
				break;
			res[x + gap][y - gap] = false;
		}
	}
}

void knight_check() { //��ֹ� ��� X
	for (int k = 0; k < kn; k++) {
		int x = knight[k].first, y = knight[k].second;
		//��� 
		if (x - 1 >= 0 && y - 2 >= 0)
			res[x - 1][y - 2] = false;
		//��� 
		if (x - 2 >= 0 && y - 1 >= 0)
			res[x - 2][y - 1] = false;
		//�֡� 
		if (x - 2 >= 0 && y + 1 < m)
			res[x - 2][y + 1] = false;
		//�֡� 
		if (x - 1 >= 0 && y + 2 < m)
			res[x - 1][y + 2] = false;
		//�١�
		if (x + 1 < n && y + 2 < m)
			res[x + 1][y + 2] = false;
		//�١�
		if (x + 2 < n && y + 1 < m)
			res[x + 2][y + 1] = false;
		//���
		if (x + 2 < n && y - 1 < m)
			res[x + 2][y - 1] = false;
		//���
		if (x + 1 < n && y - 2 < m)
			res[x + 1][y - 2] = false;
	}
}

int main(void) {
	scanf("%d %d", &n, &m); 
	scanf("%d", &qn); //���Է�
	for (int i = 0, x, y; i < qn; i++) {
		scanf("%d %d", &x, &y);
		queen.push_back({ x-1, y-1 }); //�ε����� ����ϱ����� -1��
	}
	scanf("%d", &kn); //����Ʈ�Է�
	for (int i = 0, x, y; i < kn; i++) {
		scanf("%d %d", &x, &y);
		knight.push_back({ x-1, y-1 });
	}
	scanf("%d", &pn); //���Է�
	for (int i = 0, x, y; i < pn; i++) {
		scanf("%d %d", &x, &y);
		pawn.push_back({ x-1, y-1 });
	}

	make_map();
	queen_check();
	knight_check();

	printf("%d", printAll()); //���

	return 0;
}