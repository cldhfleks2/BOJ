#include <bits/stdc++.h>
using namespace std;

int n, m, * arr;
bool* visited;
vector<int> seq;

void DFS(int num) {
	if (num == m) { //원하는 깊이(m)까지 탐색한경우
		for (int i = 0; i < m; i++)
			cout << seq[i] << " "; //탐색 결과출력
		cout << '\n';
		return;
	}
	for (int i = 0; i < n; i++) {
		if (visited[i]) //중복을 제외하므로 방문시 실행안함
			continue;
		visited[i] = true; //중복을 제외하므로 방문함을 기록
		seq.push_back(arr[i]);
		DFS(num + 1); //DFS핵심 부분 (현재방향대로 깊숙히 탐색(
		seq.pop_back(); //다음 탐색을 위한 초기화
		visited[i] = false; //초기화
	}
}

int main(void) {
	cin >> n >> m;
	visited = new bool[n];
	arr = new int[n];
	for (int i = 0; i < n; i++) {
		arr[i] = i + 1;
		visited[i] = false;
	}
	DFS(0);

	return 0;
}