#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
using std::sort; using std::vector;
int n, sum=0, mid;
int group[2] = { 0, 0 }; //�׷� A, �׷� B
vector<int> list, A, B;

void func() {
	int cursor = list.size()-1; //�ΰ��� ������
	while (1) {
		if (group[0] + list[cursor] < mid) { //�߰������� ������� ū������ ����
			group[0] += list[cursor];
			A.push_back(list[cursor]);
			list.erase(list.begin() + cursor); //front�ε��� ������ ����
			cursor--;
		}
		else { //���� �߰����� ������ �ߴ�
			break;
		}
	}

	while (1) {
		if (group[1] + list[cursor] < mid) { //�߰������� ������� ū������ ����
			group[1] += list[cursor];
			B.push_back(list[cursor]);
			list.erase(list.begin() + cursor); //front�ε��� ������ ����
			cursor--;
		}
		else { //���� �߰����� ������ �ߴ�
			break;
		}
	}

	int size = list.size();
	bool turnA = true;
	if ((mid - group[0]) > (mid - group[1]))
		turnA = true; //�߰����� ũ�� ����ġ�� �׷� ���� ä��
	else
		turnA = false;
	for (int i = 0; i < size; i++) {
		if (turnA) { //A�׷쿡 ���� �����϶�
			if (group[0] + list[i] > mid) { //���� �ִµ� �߰������� Ŀ���ٸ�...
				turnA = false; //B�׷� ������ �ٲٰ�
				group[1] += list[i];
				B.push_back(list[i]);
			}
			else {
				group[0] += list[i];
				A.push_back(list[i]);
			}
		}else{
			if (group[1] + list[i] > mid) { //���� �ִµ� �߰������� Ŀ���ٸ�...
				turnA = true; //B�׷� ������ �ٲٰ�
				group[0] += list[i];
				A.push_back(list[i]);
			}
			else {
				group[1] += list[i];
				B.push_back(list[i]);
			}
		}
	}

	if (group[0] < group[1])
		printf("%d %d", group[0], group[1]);
	else
		printf("%d %d", group[1], group[0]);
}

int main(void) {
	scanf("%d", &n);
	for (int i = 0, temp; i < n; i++) {
		scanf("%d", &temp);
		list.push_back(temp);
		sum += temp;
	}
	mid = sum / 2;
	sort(list.begin(), list.end());

	if (n == 1) {
		printf("%d", list[0]);
		return 0;
	}
	
	func();
	return 0;
}