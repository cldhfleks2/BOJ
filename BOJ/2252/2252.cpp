#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
using std::vector; using std::queue; using std::string; using std::pair; using std::to_string;

int N, M;
vector<int> edge[32001];
//vector<string> res;
//
//void BFS(int X) {
//	queue<pair<int ,int>> q;
//	q.push(X);
//	bool visited[32001] = { false, };
//	visited[X] = true;
//	string s = "";
//
//	while (!q.empty()) {
//		int x = q.front();
//		q.pop();
//	}
//
//}
struct Array {
	Array *prev, *next;
	int num;
	bool nextFinish, prevFinish;
	
	Array() : prev(nullptr), next(nullptr), num(0)
		, nextFinish(false), prevFinish(false) {};

	void insert(int num) {

	}

	//number가 있는지 찾는다.
	bool find(int number) {

	}
};

int main(void) {
	scanf("%d%d", &N, &M);
	for (int _ = 0; _ < M; _++) {

		int from, to;
		scanf("%d%d", &from, &to);

	}

	return 0;
}