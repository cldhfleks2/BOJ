#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
using std::sort; using std::vector; using std::pair; using std::floor;
int n, *num, max=-4000, min=4000, mid, range, mode, freq=0;
double avg, sum = 0;
vector<pair<int, int>>list;
vector<int> mode_list; //�ֺ� ����Ʈ(���� �󵵼��� ���� �����ϼ�����)

int main(void) {
	scanf("%d", &n);
	num = new int[n];
	for (int i = 0; i < n; i++) {
		scanf("%d", &num[i]);
		sum += num[i];
		if (min > num[i]) min = num[i];
		if (max < num[i]) max = num[i];
	}

	sort(num, num + n);
	avg = sum / (double)n;
	mid = num[n / 2];
	range = max - min;
	int preNum=0x7fffffff, cursor=-1;
	for (int i = 0; i < n; i++) { //���ĵ��ִ� ������Ž��
		if (preNum != num[i]) { //������ �ٸ� �����ϰ��
			list.push_back({ num[i], 1 });
			cursor++;
			preNum = num[i];
		}
		else { //��������
			int x = list[cursor].first;
			int cnt = list[cursor].second;
			list.erase(list.begin() + cursor);
			list.push_back({ x, cnt + 1 });
		}
	}

	for (int i = 0, m, f; i < list.size(); i++) { //�ֺ��� ã��
		m = list[i].first; //��
		f = list[i].second; //�󵵼�
		if (freq == f) {
			mode_list.push_back(m);
		}else if (freq < f) {
			mode = m;
			freq = f;
			mode_list.clear();
			mode_list.push_back(m);
		}
	}

	if (mode_list.size() == 1) {
		mode = mode_list[0];
	}
	else {
		sort(mode_list.begin(), mode_list.end());
		mode = mode_list[1];
	}

	printf("%d\n%d\n%d\n%d", (int)floor(avg + 0.5), mid, mode, range);

	return 0;
}