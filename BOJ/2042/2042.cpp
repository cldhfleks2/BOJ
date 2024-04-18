#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
using namespace std;

long long makeTree(vector<long long>& a,
	vector<long long>& tree, int node, int start, int end) {
	if (start == end) {
		return tree[node] = a[start];
	}
	else {
		return tree[node] =
			makeTree(a, tree, node * 2, start, (start + end) / 2) +
			makeTree(a, tree, node * 2 + 1, (start + end) / 2 + 1, end);
	}
}

long long sum(vector<long long>& tree, int node,
	int start, int end, int left, int right) {
	if (left > end || right < start) {
		return 0;
	}
	else if (left <= start && end <= right) {
		return tree[node];
	}
	else {
		return
			sum(tree, node * 2, start, (start + end) / 2, left, right) +
			sum(tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right);
	}
}

void update(vector<long long>& tree, int node,
	int start, int end, int index, long long diff) {
	if (index  < start || index > end) return; //포함X 종료
	tree[node] += diff;
	//리프노드가 아닐때만 아래의 과정으로
	// 모든 자식의 구간합을 변경
	if (start != end) {
		update(tree, node * 2, start, (start + end) / 2, index, diff);
		update(tree, node * 2 + 1, (start + end) / 2 + 1, end, index, diff);
	}
}

int main(void) {
	//N : 개수    M : 업데이트횟수   K : 구간합횟수
	int N, M, K;
	scanf("%d %d %d", &N, &M, &K);
	vector<long long> arr(N);
	int tree_height = (int)ceil(log2(N)) + 1;
	vector<long long> tree(pow(2, tree_height));
	for (int i = 0; i < N; i++) {
		scanf("%lld", &arr[i]);
	}
	makeTree(arr, tree, 1, 0, N - 1);
	//N+2 줄부터
	//앞숫자가 1이면 b번원소를 c로
	//앞숫자가 2면 b 부터 c까지 구간합을 출력
	int cnt = M + K;
	while (cnt--) {
		int a, b;
		scanf("%d %d", &a, &b);
		if (a == 1) {
			long long c;
			scanf("%lld", &c);
			long long diff = c - arr[b-1]; //b번째
			arr[b - 1] = c; // 중요
			update(tree, 1, 0, N - 1, b-1, diff); 
		}
		else if (a == 2) {
			int c;
			scanf("%d", &c);
			//n번째이니 인덱스는 -1씩
			printf("%lld\n", sum(tree, 1, 0, N - 1, b-1, c-1));
		}
	}

	return 0;
}