#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
using std::vector; using std::pair; using std::queue;
typedef pair<int, int> pii; typedef long l;

int n, m, sp, ep, maxLimit = 0;
/*
num1 < num2
[num1] {num2, C}
*/
vector<pii> limits[100001];
vector<int> edge[100001];
bool** visited;


void init() {
	scanf("%d%d", &n, &m);
	visited = new bool*[n + 1];
	for (int i = 0; i < n + 1; i++) {
		visited[i] = new bool[n + 1];
		for (int j = 0; j < n + 1; j++)
			visited[i][j] = false;
	}

	for (int i = 0, _, __, ___; i < n; i++) {
		scanf("%d%d%d", &_, &__, &___);
		limits[_].push_back({__, ___});
		limits[__].push_back({ _, ___ });
		edge[_].push_back(__);
		edge[__].push_back(_);
	}
	scanf("%d%d", &sp, &ep);
}

void func() {
	queue<pii> q;
	q.push({sp, 0x7fffffff});
	
	while (!q.empty()) {
		int cp = q.front().first;
		int cl = q.front().second;
		q.pop();
		if (cp == ep) { //�������� ���޽�
			if (maxLimit < cl) //�ִ񰪸� ���
				maxLimit = cl; 
			continue;
		}

		for (int i = 0; i < edge[cp].size(); i++) {
			int np = edge[cp][i]; //�����湮��
			if (!visited[cp][np]) { //�ߺ����� �ٸ��� �ǳμ�����
				visited[cp][np] = true;
				visited[np][cp] = true;

				int nl=0x7fffffff; //���� �湮�������� �߷�����
				for (int k = 0; k < limits[cp].size(); k++) { 
					//ã�����ϴ� �ٸ��̰�, �߷������� �ּ��ΰ͸� ã��
					if (limits[cp][k].first == np && limits[cp][k].second < nl)
						nl = limits[cp][k].second;
				}
				q.push({ np, cl > nl ? nl : cl });


			}
			
		}
	}
}


int main(void) {
	init();
	func();

	printf("%d", maxLimit);
	
	return 0;
}