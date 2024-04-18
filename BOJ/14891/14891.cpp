#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
using namespace std;
deque<int> gear[4];
int K = 0;
vector<pair<int, int>> rot; //ȸ����Ų�����
bool gaps[3] = { false, };	//3������ ���� ���ư��°�?
int cnt = 0;

void gear_r(int gearNum, int r);
int gear_p(int gearNum, bool right);
void cw(int gearNum);
void ccw(int gearNum);
void rotate(int n, int r);
void machine();
void printAll();

void cw(int gearNum) { //�ð�������� ȸ��
	int temp = gear[gearNum].back();
	gear[gearNum].pop_back();
	gear[gearNum].push_front(temp);
}

void ccw(int gearNum) { //�ݽð�������� ȸ��
	int temp = gear[gearNum].front();
	gear[gearNum].pop_front();
	gear[gearNum].push_back(temp);
}

//����� ������, ����(�´�� �κ�)�� ����Ѵ�.
int gear_p(int gearNum, bool right) { 
	int res = 0;
	if (right) { //������ ���������
		//3��° �� 2���ε�����
		res = gear[gearNum][2];
	}else{ //���������� ���
		//7��°, �� 6���ε�����
		res = gear[gearNum][6];
	}
	return res;
}

void rotate(int n, int r) { //n���� r�������� ����
	for (int i = 0; i < 3; i++) //�ʱ�ȭ
		gaps[i] = false;
	//�� �������� ȸ���� �Ͼ�°�
	if (gear_p(0, true) != gear_p(1, false)) gaps[0] = true;
	if (gear_p(1, true) != gear_p(2, false)) gaps[1] = true;
	if (gear_p(2, true) != gear_p(3, false)) gaps[2] = true;

	//n������ �����µ��� ��ȭ
	if (n == 1) {
		if (gaps[0] == true &&
			gaps[1] == true &&
			gaps[2] == true) {
			gear_r(2, r * -1);
			gear_r(3, r);
			gear_r(4, r * -1);
		}
		else if (gaps[0] == true &&
			gaps[1] == true &&
			gaps[2] == false) {
			gear_r(2, r * -1);
			gear_r(3, r);
		}
		else if (gaps[0] == true &&
			gaps[1] == false &&
			gaps[2] == true) {
			gear_r(2, r * -1);
		}
		else if (gaps[0] == false &&
			gaps[1] == true &&
			gaps[2] == true) {
			//pass
		}
		else if (gaps[0] == false &&
			gaps[1] == false &&
			gaps[2] == true) {
			//pass
		}
		else if (gaps[0] == true &&
			gaps[1] == false &&
			gaps[2] == false) {
			gear_r(2, r * -1);
		}
		else if (gaps[0] == false &&
			gaps[1] == true &&
			gaps[2] == false) {
			//pass
		}
		else if (gaps[0] == false &&
			gaps[1] == false &&
			gaps[2] == false) {
			//pass
		}
		gear_r(1, r);
	}
	else if (n == 2) {
		if (gaps[0] == true &&
			gaps[1] == true &&
			gaps[2] == true) {
			gear_r(1, r * -1);
			gear_r(3, r * -1);
			gear_r(4, r);
		}
		else if (gaps[0] == true &&
			gaps[1] == true &&
			gaps[2] == false) {
			gear_r(1, r * -1);
			gear_r(3, r * -1);
		}
		else if (gaps[0] == true &&
			gaps[1] == false &&
			gaps[2] == true) {
			gear_r(1, r * -1);
		}
		else if (gaps[0] == false &&
			gaps[1] == true &&
			gaps[2] == true) {
			gear_r(3, r * -1);
			gear_r(4, r);
		}
		else if (gaps[0] == false &&
			gaps[1] == false &&
			gaps[2] == true) {
			//pass
		}
		else if (gaps[0] == true &&
			gaps[1] == false &&
			gaps[2] == false) {
			gear_r(1, r * -1);
		}
		else if (gaps[0] == false &&
			gaps[1] == true &&
			gaps[2] == false) {
			gear_r(3, r * -1);
		}
		else if (gaps[0] == false &&
			gaps[1] == false &&
			gaps[2] == false) {
			//pass
		}
		gear_r(2, r);
	}
	else if (n == 3) {
		if (gaps[0] == true &&
			gaps[1] == true &&
			gaps[2] == true) {
			gear_r(1, r);
			gear_r(2, r * -1);
			gear_r(4, r * -1);
		}
		else if (gaps[0] == true &&
			gaps[1] == true &&
			gaps[2] == false) {
			gear_r(1, r);
			gear_r(2, r * -1);
		}
		else if (gaps[0] == true &&
			gaps[1] == false &&
			gaps[2] == true) {
			gear_r(4, r * -1);
		}
		else if (gaps[0] == false &&
			gaps[1] == true &&
			gaps[2] == true) {
			gear_r(2, r * -1);
			gear_r(4, r * -1);
		}
		else if (gaps[0] == false &&
			gaps[1] == false &&
			gaps[2] == true) {
			gear_r(4, r * -1);
		}
		else if (gaps[0] == true &&
			gaps[1] == false &&
			gaps[2] == false) {
			//pass
		}
		else if (gaps[0] == false &&
			gaps[1] == true &&
			gaps[2] == false) {
			gear_r(2, r * -1);
		}
		else if (gaps[0] == false &&
			gaps[1] == false &&
			gaps[2] == false) {
			//pass
		}
		gear_r(3, r);
	}
	else if (n == 4) {
		if (gaps[0] == true &&
			gaps[1] == true &&
			gaps[2] == true) {
			gear_r(1, r * -1);
			gear_r(2, r);
			gear_r(3, r * -1);
		}
		else if (gaps[0] == true &&
			gaps[1] == true &&
			gaps[2] == false) {
			//pass
		}
		else if (gaps[0] == true &&
			gaps[1] == false &&
			gaps[2] == true) {
			gear_r(3, r * -1);
		}
		else if (gaps[0] == false &&
			gaps[1] == true &&
			gaps[2] == true) {
			gear_r(2, r);
			gear_r(3, r * -1);
		}
		else if (gaps[0] == false &&
			gaps[1] == false &&
			gaps[2] == true) {
			gear_r(3, r * -1);
		}
		else if (gaps[0] == true &&
			gaps[1] == false &&
			gaps[2] == false) {
			//pass
		}
		else if (gaps[0] == false &&
			gaps[1] == true &&
			gaps[2] == false) {
			//pass
		}
		else if (gaps[0] == false &&
			gaps[1] == false &&
			gaps[2] == false) {
			//pass
		}
		gear_r(4, r);
	}
}

void gear_r(int gearNum, int r) {
	int num = gearNum - 1;
	if (num < 0 || num > 3) //�������� �߸��Ȱ��
		return;

	//�� �ش�������ε���
	if (r == 1) {
		//�ð����
		cw(num);
	}
	else if (r == -1) {
		//�ݽð����
		ccw(num);
	}
}

void machine() { //ȸ����Ų ������ ��� ����
	for (int i = 0; i < K; i++) {
		//i��° ���(ȸ����Ų���, ����)�� ����
		int n = rot[i].first;
		int r = rot[i].second;
		rotate(n, r);
	}
}

void printAll() {
	cnt++;
	int res = 0;
	res += 1 * gear[0].front();
	res += 2 * gear[1].front();
	res += 4 * gear[2].front();
	res += 8 * gear[3].front();
	
	printf("%d\n", res);
}

int main(void) {
	int temp=0, temp2=0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 8; j++) { //������ ����
			scanf("%1d", &temp);
			gear[i].push_back(temp); //�Ųٷγ־�� ó�����Ұ� front����
		}
	}
	scanf("%d", &K);
	for (int i = 0; i < K; i++) { //ȸ����Ų������ ����
		scanf("%d%d", &temp, &temp2);
		//ȸ����Ų����ȣ, ���� 
		rot.push_back({ temp, temp2 });
	}
	machine();
	printAll();

	return 0;
}