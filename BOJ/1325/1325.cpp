#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
using std::vector; using std::pair; using std::queue;
int n, m;
vector<int> edge[10001]; //간선정보
vector<pair<int, int>> res; //컴퓨터번호 : 해킹가능한컴퓨터수
bool* visited;

void printAll() {
	int max = 0;
	for (int i = 0; i < res.size(); i++) {
		if (max <= res[i].second)
			max = res[i].second;
	}

	for (int i = 0; i < res.size(); i++)
		if (res[i].second == max)
			printf("%d ", res[i].first);

}

void func() {
	visited = new bool[n + 1];
	queue<int> q;
	for (int k = 1; k <= n; k++) {
		memset(visited, 0, (n+1)*sizeof(bool)); //방문배열 초기화
		while (!q.empty()) q.pop(); //큐 초기화
		int r = 0; //해킹가능한 컴퓨터수...카운트
		q.push(k);
		visited[k] = true;
		while (!q.empty()) {
			int num = q.front();
			q.pop();
			
			for (int i = 0; i < edge[num].size(); i++) { //k번컴퓨터에연결된 컴퓨터만큼 반복
				int next = edge[num][i];
				if (!visited[next]) {
					visited[next] = true;
					r++;
					q.push(next);
				}
			}
		}

		if (r != 0) 
			res.push_back({ k, r });
		
	}
}

int main(int a, int b) {
	scanf("%d%d", &n, &m);
	while (m--) {
		scanf("%d%d", &a, &b);
		edge[b].push_back(a);
	}

	func();

	printAll();

	return 0;
}