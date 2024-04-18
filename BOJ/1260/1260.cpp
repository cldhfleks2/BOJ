#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
using std::vector; using std::queue; using std::sort;
int N, M, V;
vector<int> edge[1001]; //정점(index)에 대해 간선으로 연결된 다른 정점의 정보를 저장
bool visited[1001];

//재귀적으로 DFS
void DFS(int v) {
	visited[v] = true; //현재정점을 방문
	printf("%d ", v); //방문 => 출력
	for (int i = 0; i < edge[v].size(); i++) {
		int next = edge[v][i]; //현재정점v에연결된 모든 정점들을 순회
		if (!visited[next])
			DFS(next); //재귀적호출
	}
}

//큐를 이용하여 BFS
void BFS(int v) {
	queue<int> q;
	q.push(v); //시작정점
	visited[v] = true; //초기설정
	
	while (!q.empty()) {
		int cursor = q.front();
		q.pop();
		printf("%d ", cursor);
		for (int i = 0; i < edge[cursor].size(); i++) {
			int next = edge[cursor][i];
			if (!visited[next]) {
				visited[next] = true;
				q.push(next);
			}
		}
	}
}

int main(void) {
	scanf("%d%d%d", &N, &M, &V);
	while (M--) {
		int vertex1, vertex2;
		scanf("%d%d", &vertex1, &vertex2);
		edge[vertex1].push_back(vertex2);
		edge[vertex2].push_back(vertex1); //양방향으로 저장
	}

	for (int i = 1; i <= N; i++)
		sort(edge[i].begin(), edge[i].end()); //오름차순정렬

	memset(visited, false, 1001 * sizeof(bool));
	DFS(V); printf("\n");

	memset(visited, false, 1001 * sizeof(bool));
	BFS(V);

	return 0;
}