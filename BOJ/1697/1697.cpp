#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
using std::queue; using std::pair;
int n, k, size;
bool* visited;

int bfs() {
	queue<pair<int, int>> q;
	q.push({ n, 0 });
	visited[n] = true;

	while (!q.empty()) {
		int x = q.front().first;
		int t = q.front().second;
		q.pop();
		if (x == k) return t;

		if (0 <= x - 1 && !visited[x - 1]) {
			visited[x - 1] = true;
			q.push({ x - 1, t + 1 });
		}
		if (x + 1 <= size - 1 && !visited[x + 1]) {
			visited[x + 1] = true;
			q.push({ x + 1,t + 1 });
		}
		if (2 * x <= size - 1 && !visited[2 * x]) {
			visited[2 * x] = true;
			q.push({ 2 * x, t + 1 });
		}
	}

}

int main(void) {
	scanf("%d%d", &n, &k);
	if (n <= k)//2배로 이동할수있으므로 최대크기는 2k + 1
		size = 2 * k + 1;
	else
		size = 2 * n + 1;
	visited = new bool[size]; 
	for (int i = 0; i < size; i++)
		visited[i] = false;

	printf("%d", bfs());

	return 0;
}
