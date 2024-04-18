#define _CRT_SECURE_NO_WARNINGS
#define MAX 10001
#include <stdio.h>
#include <stack>
#include <vector>
#include <algorithm>
using std::min;
using std::vector;
using std::stack;

int n, m, idx, P[MAX];
bool finished[MAX]; //정점x가 SCC에 속하는지
stack<int> S;
vector<int> edge[MAX];
vector<vector<int>> SCC;

//재귀 구조로 SCC를 찾음
int findSCC(int x) {
	P[x] = ++idx; //부모노드 기록
	S.push(x); //스택에 추가(SCC추출할때 쓰임)

	int parent = P[x];
	for (int i = 0; i < edge[x].size(); i++) {
		int y = edge[x][i];
		if (P[y] == 0)
			parent = min(parent, findSCC(y));
		else if (!finished[y])
			parent = min(parent, P[y]);
	}

	//SCC를 추출하는 부분
	if (parent == P[x]) {
		vector<int> scc;
		while (x) {
			int y = S.top();
			S.pop();
			finished[y] = true;
			if (y == x) break;
		}
		SCC.push_back(scc);
	}

	return parent;
}

void init() {
	scanf("%d%d", &n, &m);
	for (int i = 0, a, b; i < m; i++) {
		scanf("%d%d", &a, &b);
		edge[a-1].push_back(b-1);
		edge[b-1].push_back(a-1);
	}
}

int main(void) {
	init();

	for (int i = 0; i < n; i++)
		if (P[i] == 0) findSCC(i);

	printf("%d", SCC.size());

	return 0;
}