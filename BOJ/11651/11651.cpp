#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
using namespace std;

int compare(pair<int, int>p1, pair<int, int>p2) {
	if (p1.second == p2.second) {
		return p1.first < p2.first;
	}
	else {
		return p1.second < p2.second;
	}
}

int main(int n, int x, int y, char c) {
	scanf("%d", &n);
	vector<pair<int, int>> list;
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &x, &y);
		list.push_back({ x, y });
	}
	sort(list.begin(), list.end(), compare);

	for (int i = 0; i < n; i++)
		printf("%d %d\n", list[i].first, list[i].second);

	return 0;
}