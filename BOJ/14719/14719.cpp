#define _CRT_SECURE_NO_WARNINGS //scanf���� ����
#include <bits/stdc++.h>
using namespace std;
int H, W, res, *blocks;

void next() { //��� ���� ��ĭ�������� �۾�
	for (int i = 0; i < W; i++) {
		blocks[i]--;
	}
}

int main(void) {
	scanf("%d%d", &H, &W);
	blocks = new int[W];
	int rain = 0;
	for (int i = 0 ; i < W; i++) { //������ ���
		scanf("%d", &blocks[i]);
	}

	//pre, now : ����� üũ�� �� ������(�ε������
	for (int j = 0, pre, now; j < H; j++) { 
		pre = -1; //�ʱ�ȭ
		now = 0;
		for (int i = 0, temp; i < W; i++) {
			if (blocks[i] > 0) { //����� �ִٸ�
				if (pre == -1) { //ó�� ����� �����Ѵٸ�
					pre = i; //��������� ����ϰ� �̾
					continue;
				}
				//�ε���1����
				now = i; //�����հ���
				if (now - pre == 1) { //�α���� �پ��ִٸ�
					pre = now; //���������ġ�� �ٲٰ� �̾
					continue;
				}
				//��������� ���������� �ְ� ��ջ��̰Ÿ��� 2�̻��϶�
				if(pre != -1 && now - pre > 1){ 
					temp = now - pre - 1; //�α�ջ��̿� ���̰��θ�ŭ ����
					res += temp;
					//printf("%d , %d ,   %d\n", j, i, temp);
					pre = now; //��������� ����
				}
			}
		}
		next(); //���� ��ĭ��������.
	}
	printf("%d", res);
}

