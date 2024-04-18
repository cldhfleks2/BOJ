#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
using std::vector; using std::queue; using std::pair;
int dxy[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
/*
X Y : ��� ��ǥ(�ǽð�)
S : ���ũ��
E : �� ���� ����ⰹ��
cnt : ũ�Ⱑ1~6 �� ������� ������ ���
ũ�⺰ ����ⰹ���� ī��Ʈ�س��� >> cnt

1. ������ũ�⺸�� ���� ����Ⱑ ������ ���α׷�����
2. ����ʿ���find
	> ���� �Ұ����ϸ� BFS�ϸ� ���� �ð��� �������ʰ� ���α׷� ����
3. BFS���࿡ ���� �ð��� ����
*/ 
int N, map[20][20], X, Y, S = 2, E, cnt[7];

void init() {
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		for (int j = 0, in; j < N; j++) {
			scanf("%d", &in);
			if (in == 9) { //�����ġ�� �ʿ� �����������
				X = i; Y = j;
				continue;
			}
			map[i][j] = in; //����� ��ġ�� �ʿ� ���
			if(1 <= in || in <= 6) {
				cnt[in]++; //����� ũ�⺰ ������ ��
			}
		}
	}
}

/*
BFS�����ϸ� ����⸦ ����������
�Ұ����ϴٸ� -1�� ����
�����ϴٸ� BFS�� ���� �ð��� ����
*/
struct loc{ //������� ��ġ, Ž���� ���� �ð��� ����ϴ� �����̳�
	int x, y, t; 
};
bool comp(const loc& l1, const loc& l2) { //loc�� x���۰� y�� �����ͼ����� ���ĵȴ�.
	if (l1.x < l2.x)
		return true;
	else if (l1.x == l2.x)
		return l1.y < l2.y;
	else
		return false;
}

int find() {
	 queue<loc> q;
	 q.push({ X, Y, 0});
	 bool visited[20][20] = { false, };
	 visited[X][Y] = true;

	 int max = 0x7fffffff; //BFS�ϸ� ã�� ������� �ִ� �Ÿ�
	 vector<loc> list;

	 while (!q.empty()) {
		 int cx = q.front().x;
		 int cy = q.front().y;
		 int ct = q.front().t;
		 q.pop();
		 if (max < ct) continue;

		 if (0 < map[cx][cy] && map[cx][cy] < S) {  //ũ�Ⱑ ���� ����⸦ ã�� ���
			 max = ct; //ã�� ������� �ִ�Ÿ��� ����
			 list.push_back({ cx, cy, ct }); //���
		 }

		 for (int dir = 0; dir < 4; dir++) {
			 int nx = cx + dxy[dir][0];
			 int ny = cy + dxy[dir][1];
			 int nt = ct + 1;

			 if (nx < 0 || ny < 0 || nx == N || ny == N || visited[nx][ny]) continue;
			 if (map[nx][ny] > S) continue; //���ũ�⺸�� ū ������ ������ �� ����.
			 visited[nx][ny] = true;

			 q.push({ nx, ny, nt});
		 }
	 }

	 if (list.size() == 0)	return -1; //�Ұ��� -1����

	 std::sort(list.begin(), list.end(), comp); //x��ǥ, y��ǥ������ �������� ���� ������ ����
	 int x = list[0].x;
	 int y = list[0].y;
	 int t = list[0].t;
	 map[x][y] = 0; //����⸦ �Դ´�.
	 cnt[map[x][y]]--; //������ ����� ���� -1
	 X = x; //��� ��ġ �̵� 
	 Y = y;
	 E++;
	 if (E == S) { //�� ũ�⸸ŭ ����⸦ ������ ũ��+1
		 S++;
		 E = 0;
	 }

	 return t; //�ɸ� �ð��� ����

}

//���α׷� ����
void logic() {
	int res = 0;
	while (1) {
		int end = false;
		for(int i = 1 ; i < S ; i++) 
			if (cnt[i]) { 
				end = true;
				break;
			}

		//�� �������ִ� ����Ⱑ ������ ���α׷�����
		if (!end) break;
		int time = find(); //�� ����⸦ ã�´�.
		if (time == -1) break; //����⸦ ��ã������ ���α׷�����

		res += time; //�ɸ� �ð��� ���
	}

	printf("%d", res);
}

int main(void) {
	init();
	logic();

	return 0;
}