#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
using std::pair;
int** map;

//�� �Ǵ� ���� �̱�� ���� ã�Ƽ� ����
pair<int, int> find(int n) {
	int x = -1, y = -1;
	int cnt = 0; //�󸶳� ���ӵǴ��� Ȯ��
	//   �� 
	for (int i = 0; i < 19; i++) {
		int j;
		for (j = 0; j < 19; j++) {
			if (map[i][j] == n) { //ã�����ϴ� ���� ã������
				cnt++; //���ӵ� ����
			}
			else {
				if (cnt == 5) { //��Ȯ�� 5�� �϶��� �¸�
					//printf("11\n");
					return { i, j - 5 }; //�´� ��ġ ���� (�ѹ�����ġ���� �̹Ƿ� j-5)
				} //6���̻� ���ΰ�쿴���� ����
				cnt = 0;
			}
			
		}
		if (cnt == 5) { //��Ȯ�� 5�� �϶��� 
			//printf("111\n");
			return { i, j - 5 }; //�´� ��ġ ����
		}
		cnt = 0; //�������� ���� �ʱ�ȭ
	}

	cnt = 0; //�ʱ�ȭ
	//   |
	for (int i = 0; i < 19; i++) {
		int j;
		for (j = 0; j < 19; j++) {
			if (map[j][i] == n) { 
				cnt++; 
			}
			else {
				if (cnt == 5) { 
					//printf("22\n");
					return { j - 5, i }; //��� ��ġ ���� (�ѹ� ���������Ƿ� j-5)
				} 
				cnt = 0;
			}

		}
		if (cnt == 5) { 
			//printf("222\n");
			return { j - 5, i }; //��� ��ġ ����
		}
		cnt = 0; //�������� ���� �ʱ�ȭ
	}

	cnt = 0;
	//   ��
	for (int i = 0; i < 19 - 4 ; i++) { //�»�� x ��ġ
		for (int j = 0; j < 19 - 4; j++) { //�»�� y ��ġ
			cnt = 0; //�ʱ�ȭ
			if (i != 0 && j != 0) {
				//���� i, j �ٷ����� �»���� �������̸� �̹� Ž�������Ƿ� ����
				if (map[i - 1][j - 1] == n)
					continue;
			}
			for (int gap = 0; ; gap++) { //5���� ���ϴ����� ��
				if (i + gap == 19 || j + gap == 19) //���� ����� ��ž
					break;
				if (map[i + gap][j + gap] != n) { //�ƴѰ���ã���� ��ž
					if (cnt == 5) { //��Ȯ�� 5���϶��� �¸��Ѱ�
						//printf("33\n");
						return { i, j }; //�»����ġ ����
					}
					cnt = 0;
					break;
				}
				cnt++;
			}
			if (cnt == 5) { //��Ȯ�� 5���϶��� �¸��Ѱ�
				//printf("333\n");
				return { i, j }; //�»����ġ ����
			}
		}
	}

	cnt = 0;
	//   /
	for (int i = 0; i < 19 - 4; i++) { 
		for (int j = 0 + 4; j < 19; j++) {
			cnt = 0; 
			if (i != 0 && j != 18) {
				//���� i, j �ٷ����� ������ �������̸� �̹� Ž�������Ƿ� ����
				if (map[i - 1][j + 1] == n)
					continue;
			}
			for (int gap = 0; ; gap++) { 
				if (i + gap == 19 || j - gap == -1) 
					break;
				if (map[i + gap][j - gap] != n) { 
					if (cnt == 5){ 
						//printf("44\n");
						return { i + 4, j - 4 }; //���ϴ� ��ġ 
					}
					cnt = 0;
					break;
				}
				cnt++;
			}
			if (cnt == 5) { 
				//printf("444\n");
				return { i + 4, j - 4 }; //���ϴ� ��ġ 
			}
		}
	}

	//�����ã������ { -1, -1 } ����
	return { x, y };
}

int main(void) {
	map = new int* [19];
	for (int i = 0; i < 19; i++) { //�Է¹���
		map[i] = new int[19];
		for (int j = 0; j < 19; j++)
			scanf("%d", &map[i][j]);
	}
	pair<int, int> res = find(1);
	if (res.first == -1) { //���� ����
		res = find(2);
		if (res.first == -1) { //���� ����
			printf("0"); //�ºΰ����� �ȳ���
			return 0;
		}
		else { //���� �̱���
			printf("2\n%d %d", res.first + 1, res.second + 1);
			return 0;
		}
	}
	else { //���� �̱���
		printf("1\n%d %d", res.first + 1, res.second + 1);
		return 0;
	}

	return 0;
}