#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
using std::queue; using std::vector; using std::string;
struct state {
	int n;
	string s;
	state(int n, string s) : n(n), s(s){};
};

void BFS(int from, int to) {
	bool visited[10000] = { false, };
	queue<state> q;
	state st(from, "");
	q.push(st);
	visited[from] = true;

	while (!q.empty()) {
		int n = q.front().n;
		string s = q.front().s;

		if (n == to) {
			printf("%s\n", s.c_str());
			return;
		}

		//D
		if (2 * n > 9999 && !visited[n % 10000]) {
			visited[n % 10000] = true;
			state st2(n % 10000, s + 'D');
			q.push(st2);
		}
		else if(2 * n <= 9999 && !visited[2 * n]) {
			visited[2 * n] = true;
			state st2(2 * n, s + 'D');
			q.push(st2);
		}

		//S
		if (n - 1 == 0 && !visited[9999]) {
			visited[9999] = true;
			state st2(9999, s + 'S');
			q.push(st2);
		}
		else if (n - 1 > 0 && !visited[n - 1]) {
			visited[n - 1] = true;
			state st2(n - 1, s + 'S');
			q.push(st2);
		}

		int nn = n;
		int digits[5];
		//L
		while (1) {


		}

		//R
	}

}

int main(void) {
	int t;
	scanf("%d", &t);
	while (t--) {



	}

	return 0;
}

