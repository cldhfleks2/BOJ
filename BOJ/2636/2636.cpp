#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
using std::queue; using std::pair;
typedef pair<int, int> pii;
/*
n,m : ��ũ��
cheeze : ġ����ġ �迭 true:ġ��
visited : BFS���� �湮�ߴ��� üũ��
remainsCheeze = ������ܰ迡�� ���� ġ��
�Ŵܰ踶�� BFS 0,0���� Ž��, Ž���ϸ� ġ� ���, Ž�������
clear()����
*/
int n, m, remainsCheeze=0, hour=1;
bool **cheeze, **visited; 
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

void clear();
void init();
int countCheeze();
void DEBUG();
void func();

void func() {
	queue<pii> loc;
	while (remainsCheeze > 0) { //ġ� �Ѱ��� �������
		loc.push({ 0,0 }); //0,0����Ž��
		visited[0][0] = true;

		while (!loc.empty()) {
			int x = loc.front().first; //������ġ (x,y)
			int y = loc.front().second;
			loc.pop();

			//4��������Ž��
			for (int d = 0; d < 4; d++) {
				int xx = x + dx[d]; //������ġ (xx,yy)
				int yy = y + dy[d]; 

				//�ùٸ������� ����
				if (xx < 0 || yy < 0 || xx == n || yy == m)
					continue;

				if (!visited[xx][yy]) {
					visited[xx][yy] = true;

					if (cheeze[xx][yy]) //ġ��ִٸ� ����
						cheeze[xx][yy] = false; 
					else //ġ� ���ٸ� ������ġ���� Ž���� �̾ ����
						loc.push({ xx, yy }); 
				}
			}

		}

		//Ž���� ��� �ʱ�ȭ
		clear();
		//DEBUG(); //����׿�

		if (countCheeze() == 0) //Ž���� ġ� ���°��
			break;
		remainsCheeze = countCheeze();
		hour++;
	}
	printf("%d\n%d", hour, remainsCheeze);
}

void DEBUG() {
	printf("==================================%d �ð���\n", hour);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			printf("%2d", cheeze[i][j]);
		printf("\n");
	}
	printf("=====================================\n");
}

int countCheeze() { 
	int res = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (cheeze[i][j]) res++;
	return res;
}

void init() {
	scanf("%d%d", &n, &m);
	cheeze = new bool* [n];
	visited = new bool* [n];
	for (int i = 0; i < n; i++) {
		cheeze[i] = new bool[m];
		visited[i] = new bool[m];
		for (int j = 0; j < m; j++) {
			scanf("%d", &cheeze[i][j]);
			visited[i][j] = false;
		}
	}
	remainsCheeze = countCheeze(); //����ġ�� �ʱ갪
}

void clear() {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			visited[i][j] = false;
}

int main(void) {
	init();
	func();

	return 0;
}