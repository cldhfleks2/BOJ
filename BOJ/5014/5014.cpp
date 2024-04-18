#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <vector>
using std::priority_queue; using std::vector;  using std::pair;
typedef pair<int, int> ii;

template<typename T>
struct greater {
	bool operator() (T a, T b) {
		return a.first > b.first;
	}
};

int F, S, G, U, D;
bool visit[1000001];


int main(void) {
	scanf("%d%d%d%d%d", &F, &S, &G, &U, &D);

	priority_queue<ii, vector<ii>, greater<ii>> pq;
	pq.push({ 0, S });
	visit[S] = true;
	while (!pq.empty()) {
		int c = pq.top().first;
		int s = pq.top().second;
		pq.pop();

		if (s == G) {
			printf("%d", c);
			return 0;
		}

		if (1 <= s - D && !visit[s - D]) {
			visit[s - D] = true;
			pq.push({ c + 1, s - D });
		}

		if (s + U <= F && !visit[s + U]) {
			visit[s + U] = true;
			pq.push({ c + 1, s + U });
		}
	}

	printf("use the stairs");

	return 0;
}