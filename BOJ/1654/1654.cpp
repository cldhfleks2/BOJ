#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
using std::sort;
int k, n, * cable;

void func() {
	//�����Ǳ������� �̺�Ž���ǹ���
	long long start=1, end=cable[k-1], mid=-1, res=0;
	//�̺�Ž��
	while (start <= end) {
		mid = (start + end) / 2;
		long long cnt = 0;
		for (int i = 0; i < k; i++) //��� ������ mid���̷�
			cnt += cable[i] / mid;


		if (cnt >= n) { //���̸� �ø�
			start = mid + 1;
			if (res < mid) res = mid;
		}
		else {
			end = mid - 1;
		}

		
	}

	printf("%d", res);
}

int main(void) {
	scanf("%d%d", &k, &n);
	cable = new int[k];
	//�Է�
	for (int i = 0; i < k; i++) scanf("%d", &cable[i]);

	//����
	sort(cable, cable + k); 

	func();

	return 0;
}