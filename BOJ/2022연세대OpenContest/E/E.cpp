#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
//n, c, e : �Է°�
//cnt: �������л���������
//map: �л����� ��ġ��
int n, c, e, cnt, ** map; 
int dx[4] = { 0, 1, 0, -1 }; //�� �� �� �� ����
int dy[4] = { 1, 0, -1, 0 };

int main(void) {
	scanf("%d%d%d", &n, &c, &e);
	cnt = e; 
	if (c > n * n) { //��ǻ�Ͱ��а� �л����� �ʺ���ũ��
		printf("-1");
		return 0;
	}
	map = new int* [n];
	//�� ����, �ʱ�ȭ
	for (int i = 0; i < n; i++) {
		map[i] = new int[n];
		for (int j = 0; j < n; j++)
			map[i][j] = 0; //����� �� �ٸ�����Ʈ
	}

	//��ǻ�Ͱ��а� �л�(A)�� ��ġ
	int x = 0, y = 0, gap1 = 1, gap2 = 1, cnt_a = 0;
	for (int k = 1; k <= n; k++) cnt_a += k;
	while (c--) {
		map[x][y] = 1; //������ġ�� A�׷��� ��ġ
		cnt_a--;
		if (cnt_a > 0) {
			x -= 1; y += 1; //���ܹ������� ��ġ
			if (x < 0) {
				x = gap1; y = 0;
				gap1++;
			}
		}
		else if (cnt_a == 0) {
			x = 1; y = n - 1;
		}
		else {
			x += 1; y -= 1; //�»�����μ�ġ
			if (y < gap2) {
				gap2++;
				x = gap2;  y = n - 1;
			}
		}
		
	}

	int res = 0;

	//�������л�(B )�� ��ġ
	for (int i = 0; i < n; i++) {
		if (cnt == 0) break;
		for (int j = 0; j < n; j++) { //������ġ i,j Ž��
			if (cnt == 0) break;
			if (map[i][j] == 1) continue; //�̹� ��ǻ�Ͱ��а������̸� ����
			bool isBlank = true; //������ΰ�? => �������л����� ��ġ�� �����Ѱ�?
			for (int k = 0; k < 4; k++) { //������ġ i,j���� �����¿츦 Ž��
				int xx = i + dx[k];
				int yy = j + dy[k];
				if (xx < 0 || y < 0 || n == xx || n == yy) continue; //��ũ�⸦ ����� ����
				if (map[xx][yy] == 1) { //i,j ���� �����¿쿡 ��ǻ�Ͱ��а������� ��ġ��������
					isBlank = false; //������� �ƴ�
					break; //�����¿� Ž������
				}
			}
			if (isBlank) {
				map[i][j] = 2; //������ġ�� �������л��������� ���
				res++;
				cnt--; //�������л��� ī��Ʈ
			}
		}
	}

	if (res < e)
		printf("-1");
	else {
		printf("1\n");
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				printf("%d", map[i][j]);
			}
			printf("\n");
		}
	}

	return 0;
}