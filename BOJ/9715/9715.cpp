#include <bits/stdc++.h>
using namespace std;

int** block;

int main(void) {
	int test;
	cin >> test;
	while (test--) {
		int row, col; //��, ��
		cin >> row >> col;
		block = new int*[row];
		int blockCnt = 0;
		int maxFloor = 0; //�ִ��� ����
		for (int i = 0; i < row; i++) { //2�����迭�� ����
			block[i] = new int[col];
			string temp = "";
			cin >> temp; //������� �Է¹����Ƿ� string���� ������ �ϳ��� int�� �ٲܰ�
			for (int j = 0; j < col; j++) {
				int num = temp[j] - '0'; //string���� �ϳ��� char�� int��
				blockCnt += num; //������ī����
				if (maxFloor < num) maxFloor = num;
				block[i][j] = num; //���� ���� ���
			}
		}

		int totalArea = 6 * blockCnt;
		int overlapArea = 0;
		while (maxFloor--) {
			for (int i = 0; i < row; i++) {
				for (int j = 0; j < col; j++) {
					int b = block[i][j];
					//b�� 2�̻� : �����?���κ��� ��ġ�ºκ�����
					if (b >= 2) overlapArea += 2;
					//(i+1)�� 1�̻�, b�� 1�̻� : ����� ��ġ�� �κ�����
					if (i + 1 < row && block[i + 1][j] >= 1 && b >= 1) overlapArea += 2;
					//(j+1)�� 1�̻�, b�� 1�̻� : ������ ��ġ�� �κ�����
					if (j + 1 < col && block[i][j + 1] >= 1 && b >= 1) overlapArea += 2;
				}	
			}

			for (int i = 0; i < row; i++) {//���� �ϳ��� ������ �۾�
				for (int j = 0; j < col; j++) {
					block[i][j] -= 1;
				}
			}
		}
		cout << totalArea - overlapArea << endl;

		delete block; //�޸�����
	}
	return 0;
}
