#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
//�Ź� order����Ʈ�� Ž���ϸ�, �̵��� �ɸ����̵Ǵ°� Ȯ��
//�����ϸ� ���� ������ order�� �߰�, ������ġ x, y, ����dir�� ����
using std::vector; using std::pair;
typedef pair<long, long> pll;
long x, y, dir = 1; //�� ��ġ, ����(1:��  2:��  3:��  4:��//
//������ġ<x1, y1> ���� ����� �Ÿ�<dir, distance>��ŭ �̵��� ���
vector<pair<pll, pll>> order, die; 
long L, N;
long long t=0;
long left=-1, right, up=-1, down; //4���� ��
long dx[5] = {0, 0, 1, 0, -1};
long dy[5] = {0, 1, 0, -1, 0};

bool isRight(long x, long y, long dir, long distance);
void nextDir();
void move(long distance);
void saveOrder(long x, long y, long dir, long distance);
void calculate(long distance);

//���α׷��� ���κκ�
void snakeMOVE() {
	if (N == 0) { //N�� 0 �̴��� �ѹ� �Է¹޾ƾ��ϰ�, ������ �� ������ ���� ���ư���.
		long distance;
		scanf("%ld", &distance);

		printf("%d", right - x);
		return;
	}

	while (N--) {
		long distance; //�̵��ҰŸ�
		scanf("%ld", &distance);

		if (!isRight(x, y, dir, distance)) { //�̵��� �Ұ����ϸ�
			calculate(distance); //�����
			return; //���α׷� ����
		}

		saveOrder(x, y, dir, distance);
		move(distance);
		nextDir();
	}

	//��� �Է��� ������ ���� �ε����� �ʰ� �����ߴٸ�
	long distance; //���� �ٶ󺸴� �������� �̵��� �� �ִ� �Ÿ�(���̳� ��������� �Ÿ�)
	if (dir == 1)
		distance = right - y - 1; //���� �ε����� ��������
	else if (dir == 2)
		distance = down - x - 1;
	else if (dir == 3)
		distance = y - left - 1;
	else if (dir == 4)
		distance = x - up - 1;
	if (!isRight(x, y, dir, distance)) {
		calculate(distance);
	}
	else {
		t += distance + 1; //��������� �̵��� ���� �ŵΰԵ�
		printf("%lld", t);
	}

	return;
}

//���� ����������� �̵��� ���ʵڿ� ����ϴ��� ����ϴ� �Լ�
//�̹� isRight�Լ����� die ���Ϳ� �߰��ÿ�,
//x��ǥ, y��ǥ �Ѵ� �������Ƿ�
//�� �Լ������� x��ǥ, y��ǥ�� �ϳ��� ���ص� ��.
void calculate(long distance) {
	long long min = 0x7fffffffffffffff; //long long �ִ�
	if (die.size() == 0) { //�ʹ����� ������
		//min���� �ʹ����� ����µ� ���� �ɸ��� �ð����� ���
		if (dir == 1)
			min = right - y;
		else if (dir == 2)
			min = down - x;
		else if (dir == 3)
			min = y - left;
		else if (dir == 4)
			min = x - up;
	}
	//���� �̵��ϴٰ� ���� ������ �ε����� �ּ� �Ÿ�(�ð�)�� ���
	for (int i = 0; i < die.size(); i++) { 
		long ox = die[i].first.first;
		long oy = die[i].first.second;
		long odir = die[i].second.first;
		long odis = die[i].second.second;
		long temp = 0;
		if (dir == 1) { 
			if (odir == 1 || odir == 2 || odir == 4) temp = oy - y;
			if (odir == 3) temp = ( oy + dy[odir]*odis ) - y;
		}
		else if (dir == 2) {
			if (odir == 2 || odir == 1 || odir == 3) temp = ox - x;
			if (odir == 4) temp = (ox + dx[odir] * odis) - x;
		}
		else if (dir == 3) {
			if (odir == 3 || odir == 2 || odir == 4) temp = y - oy;
			if (odir == 1) temp = y - (oy + dy[odir] * odis);
		}
		else if (dir == 4) {
			if (odir == 4 || odir == 1 || odir == 3) temp = x - ox;
			if (odir == 2) temp = x - (ox + dx[odir] * odis);
		}

		if (min > temp) {
			min = temp; //�ּҽð� ���
		}
	}

	//����ϴºκ�
	printf("%lld", min + t);
	
}

//���� �̵������� order�� �����ϴ� �Լ�
void saveOrder(long x, long y, long dir, long distance) {
	pll p1 = { x, y }, p2 = { dir, distance };
	order.push_back({ p1, p2 });
}

//�Է¹��� �Ÿ�(�ð�)��ŭ ���� �̵���Ű�� �Լ�
void move(long distance) {
	x += dx[dir] * distance;  //���� ��ġ �̵�
	y += dy[dir] * distance;

	//�̵��� �ð� t ����
	t += distance;
}

//��Ӹ� ������ �Է¹޾� �����ϴ� �Լ�
void nextDir() {
	char d;
	scanf("%c%c", &d, &d);
	if (d == 'L')
		dir--;
	else if (d == 'R')
		dir++;
	if (dir == 0)
		dir = 4;
	if (dir == 5)
		dir = 1;
	scanf("%c", &d); //�ٹٲ޹��� ����
}

//��Ӹ��� �̵����� ���� Ȯ���ϴ� �Լ�
//�Ұ����ϴٸ� die ���Ϳ� �Ұ����� ���� �̵� ����(order[i])�� �߰�
bool isRight(long x, long y, long dir, long distance) { 
	bool res = true; 
	long xx = x + dx[dir] * distance; //���� ��ġ
	long yy = y + dy[dir] * distance;

	//�ʹ����� ������� Ȯ��
	if (yy <= left || right <= yy ||
		xx <= up || down <= xx)
		return false;

	//���� ���� �̵������� �ε������� Ȯ��
	for (int i = 0; i < order.size(); i++) { 
		if (i == order.size() - 1) continue; //�ٷ� ������ ���� ������ ������ ����
		long ox = order[i].first.first;
		long oy = order[i].first.second;
		long odir = order[i].second.first;
		long odis = order[i].second.second;
		if (dir == 1) {
			if (odir == 1 && x == ox) //x�� o��
				if (y <= oy && oy <= yy) { res = false; die.push_back(order[i]);  }
			if (odir == 3 && x == ox) //x�� ��o
				if (y <= oy + dy[odir]*odis && oy + dy[odir] * odis <= yy) { res = false; die.push_back(order[i]);  }
			//y��ǥ�� ���� �����ϴ°�? 
			if (y <= oy && oy <= yy) { //x�� |o
				//x��ǥ�� ���� �����ϴ°�?
				if (odir == 2 && ox <= x && x <= ox + dx[odir] * odis) { res = false; die.push_back(order[i]);  }
				if (odir == 4 && ox + dx[odir] * odis <= x && x <= ox) { res = false; die.push_back(order[i]);  }
			}
		}
		else if (dir == 2) {
			if (odir == 2 && y == oy) //x��
									  //o��
				if (x <= ox && ox <= xx) { res = false; die.push_back(order[i]);  }
			if (odir == 4 && y == oy) //x��
									  //o��
				if (x <= ox + dx[odir]*odis && ox + dx[odir] * odis <= xx) { res = false; die.push_back(order[i]);  }
			//x��ǥ�� ���� �����ϴ°�?
			if (x <= ox && ox <= xx) { //x��
									   //o��
				//y��ǥ�� ���� �����ϴ°�?
				if (odir == 1 && oy <= y && y <= oy + dy[odir] * odis) { res = false; die.push_back(order[i]);  }
				if (odir == 3 && oy + dy[odir] * odis <= y && y <= ox) { res = false; die.push_back(order[i]);  }
			}
		}
		else if (dir == 3) {
			if (odir == 3 && x == ox) //o�� ��x
				if (yy <= oy && oy <= y) { res = false; die.push_back(order[i]);  }
			if (odir == 1 && x == ox) //o�� ��x
				if (yy <= oy + dy[odir] * odis && oy + dy[odir]*odis <= y) { res = false; die.push_back(order[i]);  }
			//y��ǥ�� ���� �����ϴ°�?
			if (yy <= oy && oy <= y) { //o| ��x 
				//x��ǥ�� ���� �����ϴ°�?
				if (odir == 2 && ox <= x && x <= ox + dx[odir] * odis) { res = false; die.push_back(order[i]);  }
				if (odir == 4 && ox + dx[odir] * odis <= x && x <= ox) { res = false; die.push_back(order[i]);  }
			}
		}
		else if (dir == 4) {
			if (odir == 4 && y == oy) //o��
									  //x��
				if (xx <= ox && ox <= x) { res = false; die.push_back(order[i]);  }
			if (odir == 2 && y == oy) //o��
									  //x��
				if (xx <= ox + dx[odir] * odis && ox + dx[odir]*odis <= x) { res = false; die.push_back(order[i]);  }
			//x��ǥ�� ���� �����ϴ°�?
			if (xx <= ox && ox <= x) { //o��
									   //x��
				//y��ǥ�� ���� �����ϴ°�?
				if (odir == 1 && oy <= y && y <= oy + dy[odir] * odis) { res = false; die.push_back(order[i]);  }
				if (odir == 3 && oy + dy[odir] * odis <= y && y <= oy) { res = false; die.push_back(order[i]);  }
			}
		}
	}

	return res;
}

int main(void) {
	scanf("%ld%ld", &L, &N);
	right = 2 * L + 1; 
	down = 2 * L + 1;
	x = L;
	y = L;

	snakeMOVE();

	return 0;
}