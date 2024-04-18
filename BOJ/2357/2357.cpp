#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

//최소, 최대트리를 각각 구현하는 함수
void makeTree(vector<int> &arr, vector<int>& minTree, vector<int>& maxTree, 
	int node, int start, int end) {
	if (start == end) { //리프노드 일때 그대로 저장
		minTree[node] = maxTree[node] = arr[start];
	}
	else {
		makeTree(arr, minTree, maxTree, node * 2, start, (start + end) / 2);
		makeTree(arr, minTree, maxTree, node * 2 + 1, (start + end) / 2 + 1, end);
		//node는 현재 주목하는 노드의 인덱스이며, 그 왼쪽자식 오른쪽자식중
		//최솟값, 최댓값으로 현재노드의 값을 갱신해준다.
		//리프노드의 부모노드부터 쌓아올려지는 방식이다.
		//호출은 top-down임
		minTree[node] = min(minTree[node * 2], minTree[node * 2 + 1]);
		maxTree[node] = max(maxTree[node * 2], maxTree[node * 2 + 1]);
	}
}

//a, b범위에따른 최소, 최댓값을 쌍으로 묶어서 리턴하는 함수
//최솟값, 최댓값쌍을 리턴
//start, end 는 가능한 최대범위
//left, right 는 찾고자하는 구간
pair<int, int> findMinMax(vector<int> &minTree, vector<int> &maxTree, 
	int node, int start, int end, int left, int right) {
	if (left > end || right < start) { //구간이 잘못된경우
		//최솟값으로 최대를, 최댓값으로 최소를 리턴
		return make_pair(INT32_MAX, 0);
	}
	else if (left <= start && end <= right) {
		return make_pair(minTree[node], maxTree[node]);
	}
	else {
		pair<int, int> L, R;
		L = findMinMax(minTree, maxTree, node * 2, start, (start + end) / 2, left, right);
		R = findMinMax(minTree, maxTree, node * 2 + 1, (start + end) / 2 + 1, end, left, right);
		return make_pair(min(L.first, R.first), max(L.second, R.second));
	}
}

int main(void) {
	int N, M;
	scanf("%d%d", &N, &M);
	vector<int> arr(N);
	int h = (int)ceil(log2(N))+1;
	vector<int> minTree(pow(2, h)), maxTree(pow(2, h));
	for (int i = 0, temp; i < N; i++) {
		scanf("%d", &temp);
		arr[i] = temp;
	}
	makeTree(arr, minTree, maxTree, 1, 0, N-1);
	while (M--) {
		int a, b;
		scanf("%d%d", &a, &b);
		pair<int, int> res = findMinMax(minTree, maxTree, 1, 0, N-1, a-1, b-1);
		printf("%d %d\n", res.first, res.second);
	}

	return 0;
}