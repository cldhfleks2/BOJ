#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
using std::vector; using std::pair;
int n, m;
vector<pair<int, int>> home, chicken;
vector<int> picked; 
vector<int*> chooseChickenList; //m���� ������ ����Ʈ���� ����
void func();
void pick(int n, vector<int>& picked, int cnt);
int calculateCD(int x1, int y1, int* list);

void func() {
	pick(chicken.size(), picked, m); //ġŲ���� m���������� ����Ʈ���� �����.
	int res = 0x7fffffff;
	for (int i = 0; i < chooseChickenList.size(); i++) { //���õ� m���� ġŲ�� �� ����Ʈ��
		int sum_CD = 0; //m�� �� ġŲ���鿡���� ��� ���� ġŲ�Ÿ��� �ջ�
		for (int j = 0; j < home.size(); j++) { //����������� Ž��
			int CD = calculateCD(home[j].first, //���� ����
								home[j].second, //ġŲ�Ÿ��� ����
						chooseChickenList[i]);
			sum_CD += CD; 
		}
		if (res > sum_CD) res = sum_CD; //������ ġŲ�Ÿ��� �ּڰ��� ���
	}
	printf("%d", res); //���
}

void pick(int n, vector<int>& picked, int cnt) {
	if (cnt == 0) {//�����Ϳ����� ���Ͻ�.
		int* l = new int[picked.size()];
		for (int i = 0; i < picked.size(); i++)
			l[i] = picked[i];
		chooseChickenList.push_back(l); //������ ġŲ��Ͽ� �߰�
		return;
	}
	int smallest = picked.empty() ? 0 : picked.back() + 1;
	for (int i = smallest; i < n; i++) {
		picked.push_back(i); //picked �ְ�
		pick(n, picked, cnt - 1);
		picked.pop_back(); //picked�� ���鼭 ���� ��Ҹ� ����.
	}
}

//�ش� ���� ġŲ�Ÿ��� ���ϴ� �Լ�
int calculateCD(int x1, int y1, int* list) {
	int res=0x7fffffff ,x2, y2;
	for (int i = 0; i < m; i++) { //m���� ġŲ���� Ž��
		x2 = chicken[list[i]].first;
		y2 = chicken[list[i]].second;
		int d = (x2 < x1 ? x1 - x2 : x2 - x1) + 
			(y2 < y1 ? y1 - y2 : y2 - y1);
		if (res > d) res = d; //�ּҰŸ��� ���
	}
	return res;
}

int main(void) {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0, temp; j < n; j++) {
			scanf("%d", &temp);
			if (temp == 1) 
				home.push_back({i, j}); //����ġ ����
			else if (temp == 2) 
				chicken.push_back({ i, j }); //ġŲ����ġ ����
		}
	}

	func();

	return 0;
}