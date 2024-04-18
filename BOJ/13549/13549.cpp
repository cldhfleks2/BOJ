#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
using std::priority_queue; using std::vector; using std::pair; using std::greater;
typedef pair<int, int> ii;
int N, K, res = 0x7fffffff;
bool visited[100001];

void func() {
	priority_queue<ii, vector<ii>, greater<ii>> pq;
	pq.push({ 0, N });
	visited[N] = true;
	while (!pq.empty()) {
		int t = pq.top().first;
		int n = pq.top().second;
		pq.pop();

		if (n == K) {
			res = t;
			break;
		}

		if (2 * n <= 100000 && !visited[2 * n]) {
			visited[2 * n] = true;
			pq.push({ t, 2 * n });
		}

		if (n + 1 <= 100000 && !visited[n + 1]) {
			visited[n + 1] = true;
			pq.push({ t + 1, n + 1 });
		}

		if (0 <= n - 1 && !visited[n - 1]) {
			visited[n - 1] = true;
			pq.push({ t + 1, n - 1 });
		}

	}

	printf("%d", res);
}

int main(void) {
	scanf("%d%d", &N, &K);
	func();

	return 0;
}

