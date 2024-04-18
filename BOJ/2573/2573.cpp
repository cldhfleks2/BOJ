#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
using std::vector; using std::pair; using std::queue;
typedef pair<int, int> pii;
/*
iceberg : �Žð����� ������̸� ����
icebergList : �Žð����� ������ ������ǥ��
meltAmount : �Žð����� ���ϰ� ��¾��� ����
visited : finished �Լ����� BFS�� ����ϱ����� �湮üũ �迭
loc : finished �Լ����� ������ �ѵ������ ã������
	  BFS�� ����ϱ����� ť
hour : ����ð�, ��°�
dx, dy : ���⺤��
*/
int n, m, ** iceberg, ** meltAmount, hour = 0;
bool** visited;
vector<pii> icebergList;
queue<pii> loc;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
bool findMeltAmount();
bool isOnePiece();
void melting();
void func();

void func() {
	while (1) {
		if (!findMeltAmount()) { //�������������������� 0���, ����
			printf("0");
			return;
		}

		if (!isOnePiece()) { //������ ���̻����� �и��Ȱ�� �����ð����, ����
			printf("%d", hour);
			return;
		}

		melting(); //������ ���δ�.
		hour++; 
	}
}

//������ ������ ���δ�.
void melting() {
	for (int k = 0; k < icebergList.size(); k++) {
		int x = icebergList[k].first;
		int y = icebergList[k].second;
		iceberg[x][y] -= meltAmount[x][y];
		if (iceberg[x][y] < 0) iceberg[x][y] = 0; //0���Ϸ� ������������
	}
}

//������ġ�� �ϳ����� �����ؼ� BFS�� �ѵ���� �̷�������� Ȯ���ϴ� �Լ�
//�ε�� �̻����� �и��Ȱ�� false ����
bool isOnePiece() {
	int icebergCnt = icebergList.size();
	int init_x = icebergList[0].first;
	int init_y = icebergList[0].second;
	loc.push({ init_x, init_y }); //BFS ������ġ
	visited[init_x][init_y] = true; //�湮üũ
	icebergCnt--; //���갹��ī��Ʈ

	while (!loc.empty()) {
		int x = loc.front().first; //������ġ
		int y = loc.front().second;
		loc.pop();

		for (int d = 0; d < 4; d++) {
			int xx = x + dx[d]; //������ġ
			int yy = y + dy[d];

			//���������� ����
			if (xx < 0 || yy < 0 || xx == n || yy == m) continue;
			
			//�湮��������, ������ �����ϴ°��̸� �̵�
			if (!visited[xx][yy] && iceberg[xx][yy] > 0) {
				visited[xx][yy] = true; //�湮üũ
				loc.push({ xx, yy }); //������ġ�� ť���־ Ž�����̾
				icebergCnt--;
			}
		}
	}

	if (icebergCnt > 0)  //��� ������ �̾��������������
		return false;
	else
		return true;
}

//��������� ��� �ӵ��� ���
//�����̾����� false����
bool findMeltAmount() { 
	icebergList.clear(); 
	for (int i = 0; i < n; i++)
		for(int j = 0 ; j < m ; j++)
			if (iceberg[i][j] != 0)
				icebergList.push_back({ i, j }); //������ġ�� ���

	if (icebergList.size() == 0) return false;

	//�ʱ�ȭ 1
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			meltAmount[i][j] = 0;
	//�ʱ�ȭ 2
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			visited[i][j] = false;

	//���긶�� ��¼ӵ��� ���
	for (int k = 0; k < icebergList.size(); k++) {
		int x = icebergList[k].first;
		int y = icebergList[k].second;
		
		int amount = 0;
		for (int d = 0; d < 4; d++) {
			int xx = x + dx[d];
			int yy = y + dy[d];

			if (xx < 0 || yy < 0 || xx == n || yy == m) continue;
			if (iceberg[xx][yy] == 0) amount++; //4������ �ٴٰ��ִ°�
		}
		meltAmount[x][y] = amount;
	}
	return true;
}

int main(void) {
	scanf("%d%d", &n, &m);
	iceberg = new int* [n];
	meltAmount = new int* [n];
	visited = new bool* [n];
	for (int i = 0; i < n; i++) {
		iceberg[i] = new int[m];
		meltAmount[i] = new int[m];
		visited[i] = new bool[m];
		for (int j = 0; j < m; j++) {
			scanf("%d", &iceberg[i][j]);
		}
	}

	func();

	return 0;
}
