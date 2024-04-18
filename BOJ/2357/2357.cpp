#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

//�ּ�, �ִ�Ʈ���� ���� �����ϴ� �Լ�
void makeTree(vector<int> &arr, vector<int>& minTree, vector<int>& maxTree, 
	int node, int start, int end) {
	if (start == end) { //������� �϶� �״�� ����
		minTree[node] = maxTree[node] = arr[start];
	}
	else {
		makeTree(arr, minTree, maxTree, node * 2, start, (start + end) / 2);
		makeTree(arr, minTree, maxTree, node * 2 + 1, (start + end) / 2 + 1, end);
		//node�� ���� �ָ��ϴ� ����� �ε����̸�, �� �����ڽ� �������ڽ���
		//�ּڰ�, �ִ����� �������� ���� �������ش�.
		//��������� �θ������ �׾ƿ÷����� ����̴�.
		//ȣ���� top-down��
		minTree[node] = min(minTree[node * 2], minTree[node * 2 + 1]);
		maxTree[node] = max(maxTree[node * 2], maxTree[node * 2 + 1]);
	}
}

//a, b���������� �ּ�, �ִ��� ������ ��� �����ϴ� �Լ�
//�ּڰ�, �ִ񰪽��� ����
//start, end �� ������ �ִ����
//left, right �� ã�����ϴ� ����
pair<int, int> findMinMax(vector<int> &minTree, vector<int> &maxTree, 
	int node, int start, int end, int left, int right) {
	if (left > end || right < start) { //������ �߸��Ȱ��
		//�ּڰ����� �ִ븦, �ִ����� �ּҸ� ����
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