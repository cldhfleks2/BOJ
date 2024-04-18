#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>

int main(void) {
	int n, t;
	//�ؿ����ʱ���ġ locX, locY, ���� �ð� preTime
	int locX = 0, locY = 0, preTime = 0; 
	scanf("%d %d\n", &n, &t);
	//n���� ������ �ٲ� ����� ����
	//2��° ��Ҵ� 0:left 1:right
	std::vector<std::pair<int, int>> list; 

	//�Է°��� ��� ����
	for (int i = 0; i < n; i++) {
		int time;
		int dir;
		char flag[7];
		scanf("%d %[^\n]s", &time, &flag); //�ð��� ������ ����
		scanf("%c", &flag[6]); //�ٹٲ޹��ڸ� ����
		if (flag[0] == 'r') {
			dir = 0;
		}
		else {
			dir = 1;
		}
		list.push_back({ time, dir });
	}

	//0 : ��
	//1 : ��
	//2 : ��
	//3 : ��
	int flag = 0; //ó���� ���������� ����
	//������ ���� �Է°��� �������� �ؿ����� ��ġ�� ���
	for (int i = 0; i < list.size(); i++) {
		int time = list[i].first;
		int f = list[i].second;

		int moveGap = time - preTime; //�̵��� �ð���(=�Ÿ�)
		

		//���� �ٶ󺸴� �������� �ð��� ��ŭ �̵�.
		if (flag == 0) {
			locX += moveGap; 
		}
		else if (flag == 1) {
			locY -= moveGap;
		}
		else if (flag == 2) {
			locX -= moveGap;
		}
		else if (flag == 3) {
			locY += moveGap;
		}

		//������ �̵��� ���� ����
		if (f == 0) {
			flag++;
		}
		else if (f == 1) {
			flag--;
		}

		//�ѹ����� �����
		if (flag == 4) {
			flag = 0;
		}
		else if (flag == -1) {
			flag = 3;
		}

		preTime = time; //�����ð� ����
	}

	//���� �ð��� �������
	if (preTime != t) { 
		//���������� �ٶ󺸴� �������� ���� �ð���ŭ �̵�.
		if (flag == 0) {
			locX += t - preTime;
		}
		else if (flag == 1) {
			locY -= t - preTime;
		}
		else if (flag == 2) {
			locX -= t - preTime;
		}
		else if (flag == 3) {
			locY += t - preTime;
		}
	}

	printf("%d %d", locX, locY);

	return 0;
}