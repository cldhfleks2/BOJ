#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>

int* consumer;
std::vector<int> check;

int main(void) {
	int n;
	scanf("%d", &n);
	consumer = new int[n];
	for (int i = 0; i < n; i++) { //�Է¹޴� �κ�
		scanf("%d", &consumer[i]);
	}

	//�������� �뷮�� �ִ��� Ȯ�� �ϴ� �κ�
	for (int i = 0; i < n; i++) {
		int num = consumer[i];
		bool find = false;
		for (int j = 0; j < check.size(); j++) {
			if (check[j] == num) { //������ �߰��ߴ°�
				find = true;
				break;
			}
		}
		if (!find) //������ �߰������ʾҴٸ� check�� ���
			check.push_back(num);
	}
	if (check.size() == 1) {
		printf("%d", n);
		return 0;
	}

	int maxLength = 1; //�ִ�� ���ӵǾ� �ټ��ִ� ����. �������� ���ϰ����ϴ� ��
	for (int i = 0; i < check.size(); i++) {
		int del_cap = check[i]; //������ �뷮

		int preNum = -1;
		int length = 0;
		for (int j = 0; j < n; j++) {
			if (consumer[j] == del_cap) { //������ �뷮�� �߽߰�
				if (j == n - 1) //�� ���������̶��
					if (length != 0 && maxLength < length + 1)
						maxLength = length + 1; //�������� ����Ͽ� + 1
				continue;
			}
			if (preNum != consumer[j]) {
				preNum = consumer[j];
				if (length != 0 && maxLength < length + 1)
					maxLength = length + 1;
				length = 0;
			}
			else {
				length++;
			}
		}
		if (length > 0) {
			if (maxLength < length + 1)
				maxLength = length + 1;
			
		}

	}

	printf("%d", maxLength);

	return 0;
}