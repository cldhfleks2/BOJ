#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>

int main(int n, int m) {
	scanf("%d", &n);
	long long* a = new long long[n];
	long long max = 0;
	for (int i = 0; i < n; i++){
		scanf("%lld", &a[i]);
		if (max < a[i]) //�ִ��� ã��
			max = a[i];
	}
	std::sort(a, a + n);

	scanf("%d", &m);
	while (m--) {
		long long num;
		scanf("%lld", &num);
		bool find = false;
		int start = 0, mid = n / 2, end = n - 1;
		//�̺�Ž��
		while (end >= start) {
			//�߾Ӱ��� ��ġ�ϸ� Ž������
			if (a[mid] == num) {
				printf("1\n");
				find = true;
				break;
			}
			//�߾Ӱ� ������ Ž�������� ��������
			else if (a[mid] > num)
				end = mid - 1;
			//�߾Ӱ����� ũ�� Ž�������� ��������
			else if (a[mid] < num)
				start = mid + 1;

			mid = (start + end) / 2;
		}
		if(!find)
			printf("0\n");
	}

	return 0;
}