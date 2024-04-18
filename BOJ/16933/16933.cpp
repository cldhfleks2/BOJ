#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
using std::vector; using std::stack; using std::queue; using std::deque; using std::tuple;
using std::string; using std::pair; using std::make_tuple; using std::tie;
using std::sort; using std::max; using std::min;
using std::make_pair; using std::max_element; using std::min_element; using std::bitset; using std::to_string;
using std::fill; using std::priority_queue; using std::greater;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, int> pdi;
typedef pair<int, double> pid;
typedef pair<double, double> pdd;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;
typedef pair<int, char> pic;
typedef pair<char, int> pci;
typedef pair<string, int> psi;
typedef pair<int, string> pis;
typedef pair<string, string> pss;
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pl;

int a[1001][1001]; // �迭 ����
int wall[1001][1001][12][2];
int dir[4][2] = { {0,1},{0,-1},{-1,0},{1,0} };
int n, m, k;

int main()
{
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%1d", &a[i][j]);
		}
	}

	queue<tuple<int, int, int, int>> q;
	q.push(make_tuple(0, 0, 0, 0));

	wall[0][0][0][0] = 1;

	while (!q.empty())
	{
		int x, y, z, day;
		tie(x, y, z, day) = q.front();
		q.pop();

		if (wall[x][y][z][1 - day] == 0) //����! �������� �ʰ� ������ �ִ� ���(���� �㸸 �ٲ��, �װ͵� Ƚ���� �ľ� �ϹǷ� 1�� ���Ѵ�.)
		{
			wall[x][y][z][1 - day] = wall[x][y][z][day] + 1;
			q.push(make_tuple(x, y, z, 1 - day));
		}

		for (int i = 0; i < 4; i++)
		{
			int xx = x + dir[i][0];
			int yy = y + dir[i][1];
			if (xx >= 0 && xx < n && yy >= 0 && yy < m && 
				a[xx][yy] == 1 && wall[xx][yy][z + 1][1 - day] == 0 && (z + 1) <= k && day == 0) //���� �� ���� ���ε�, ���� ���� �ν� �� �ִ� Ƚ���� ���Ұ�, ���� ���
			{
				wall[xx][yy][z + 1][1 - day] = wall[x][y][z][day] + 1; // ���� �ѹ� �νð� ��
				q.push(make_tuple(xx, yy, z + 1, 1 - day));
			}
			if (xx >= 0 && xx < n && yy >= 0 && yy < m && a[xx][yy] == 0 && wall[xx][yy][z][1 - day] == 0) //���� ������ ���� �ƴϰ� �׳� ���� �ִ� ���ϋ�
			{
				wall[xx][yy][z][1 - day] = wall[x][y][z][day] + 1;
				q.push(make_tuple(xx, yy, z, 1 - day));
			}
		}

	}
	int ans = INT32_MAX;
	for (int i = 0; i <= k; i++) //i<k�� �ƴ϶� i<=k�̴�! �ִ� k�� �ν� �� �����ϱ�, k���� ��� ����ϰ� �������� �����ϴ� ��쵵 �����ؾ� ��!
	{
		for (int j = 0; j < 2; j++)
		{
			if (wall[n - 1][m - 1][i][j] != 0)
			{
				if (ans > wall[n - 1][m - 1][i][j])
					ans = wall[n - 1][m - 1][i][j];
			}
		}
	}
	printf("%d", ans == INT32_MAX ? -1 : ans);

	return 0;
}