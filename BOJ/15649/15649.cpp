#include <bits/stdc++.h>
using namespace std;

int n, m, * arr;
bool* visited;
vector<int> seq;

void DFS(int num) {
	if (num == m) { //���ϴ� ����(m)���� Ž���Ѱ��
		for (int i = 0; i < m; i++)
			cout << seq[i] << " "; //Ž�� ������
		cout << '\n';
		return;
	}
	for (int i = 0; i < n; i++) {
		if (visited[i]) //�ߺ��� �����ϹǷ� �湮�� �������
			continue;
		visited[i] = true; //�ߺ��� �����ϹǷ� �湮���� ���
		seq.push_back(arr[i]);
		DFS(num + 1); //DFS�ٽ� �κ� (��������� ����� Ž��(
		seq.pop_back(); //���� Ž���� ���� �ʱ�ȭ
		visited[i] = false; //�ʱ�ȭ
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