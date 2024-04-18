#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
using std::vector; using std::queue; using std::sort;
int N, M, V;
vector<int> edge[1001]; //����(index)�� ���� �������� ����� �ٸ� ������ ������ ����
bool visited[1001];

//��������� DFS
void DFS(int v) {
	visited[v] = true; //���������� �湮
	printf("%d ", v); //�湮 => ���
	for (int i = 0; i < edge[v].size(); i++) {
		int next = edge[v][i]; //��������v������� ��� �������� ��ȸ
		if (!visited[next])
			DFS(next); //�����ȣ��
	}
}

//ť�� �̿��Ͽ� BFS
void BFS(int v) {
	queue<int> q;
	q.push(v); //��������
	visited[v] = true; //�ʱ⼳��
	
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
		edge[vertex2].push_back(vertex1); //��������� ����
	}

	for (int i = 1; i <= N; i++)
		sort(edge[i].begin(), edge[i].end()); //������������

	memset(visited, false, 1001 * sizeof(bool));
	DFS(V); printf("\n");

	memset(visited, false, 1001 * sizeof(bool));
	BFS(V);

	return 0;
}