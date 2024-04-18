#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using std::vector; using std::pair;
typedef pair<int, int> pii;
int n, m, r, x, y, location; //location: 0,1,2,3 �����ϵ� ��ġ
int res; //��� �������� �ִܰŸ�

vector<pair<pii, int>> shops; //������ x, y ��ġ, location

int dx[] = { 0, -1, 0 , 1 }; //�»���� ����
int dy[] = { -1, 0, 1, 0 };

void init() {
	scanf("%d%d%d", &m, &n, &r);
	int _, __;
	while (r--) { //������ġ
		scanf("%d%d", &_, &__);
		if (_ == 1)
			shops.push_back({ { 0, __ }, 2 });
		else if (_ == 2)
			shops.push_back({ { n - 1, __ }, 0 });
		else if (_ == 3)
			shops.push_back({ { __, 0 }, 1 });
		else if (_ == 4)
			shops.push_back({ { __, m - 1 }, 3 });
	}
	scanf("%d%d", &_, &__); //��������ġ
	if (_ == 1) {
		x = 0; y = __; location = 2;
	}
	else if (_ == 2) {
		x = n - 1; y = __; location = 0;
	}
	else if (_ == 3) {
		x = __; y = 0; location = 1;
	}
	else if (_ == 4) {
		x = __; y = m - 1; location = 3;
	}
}

void func() {
	int size = shops.size();
	int dir;
	for (int i = 0; i < size; i++) {
		int xx = shops[i].first.first;
		int yy = shops[i].first.second;
		int shopLocation = shops[i].second;

		dir = location;
		int clockWise = 0, counterClockWise = 0;
		//�ð�������� ���� �Ÿ� ���
		for (int d = 0; d < 4; d++) {
			if (dir == shopLocation) { //������� ��������� ��ġ�ϸ�
				if(d == 0) {//ó�� ��������ġ�� ���� �����̾��ٸ�
					if (dir % 2 == 0)
						clockWise += abs(y - yy);
					else
						clockWise += abs(x - xx);
					break;
				}
				if (dir == 0)
					clockWise += m - yy;
				else if (dir == 1)
					clockWise += n - xx;
				else if (dir == 2)
					clockWise += yy;
				else if (dir == 3)
					clockWise += xx;
				break;
			}
			else {
				if (d == 0) { //ó���϶�
					if (dir == 0)
						clockWise += y;
					else if (dir == 1)
						clockWise += x;
					else if (dir == 2)
						clockWise += m - y;
					else if (dir == 3)
						clockWise += n - x;
				}
				else { //ó��X �ش� �������� ���� �ٸ������϶�
					if (dir % 2 == 0) //��, ��
						clockWise += m; //���� ��ü����
					else //��, ��
						clockWise += n; //���� ��ü����
				}
			}

			dir = (dir + 1) % 4; //������ġ ���� �ð�������� �̵�
		}
		dir = location; //�ʱ�ȭ
		counterClockWise = (2 * n + 2 * m) - clockWise;

		res += clockWise > counterClockWise ? counterClockWise : clockWise; //�ִܰŸ�����
	}
	printf("%d", res);
}

int main() {
	init();
	func();


	return 0;
}



