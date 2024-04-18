#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
//��ũ�� n x m 
//map : ����ĭ�� -1 ���ĭ�� -2������
//a : ����� �������� ĥ�ϴº��
//b : ������ ������� ĥ�ϴº��
//blackCnt : ��� ����ĭ���� (���ڿ� ��� ����ĭ�� ���ԵǾ���Ѵ�.)
int n, m, a, b, **map, blackCnt=0;
void func();
void input();

void func() {
	input();
	int maxSize = n >= m ? m : n; //n�� m�� �ּڰ�
	int res = 0x7fffffff;
	for (int k = 1; 3 * k <= maxSize; k ++) {
		
		//������ġ x,y(�»����ǥ)�� ����
		int size = 3 * k;
		for (int x = 0; x + size <= n; x++) { //�ùٸ� ��ǥ���� (0,0)~(n-1,m-1)
			for (int y = 0; y + size <= m; y++) { //���� ũ��� 3k x 3k
				int price = 0; //���� �ٽ� ĥ�ϴ� ���
				int lessBlackCnt = blackCnt; //�������� ��� ����ĭ�� ���� - 3k x 3k�������� Ȯ�ε� ����ĭ�ǰ���.
											 //�� ���� ����������
				//1. 3k x 3kĭ�� ��� ���������� ĥ�ϴ� ��� ���
				for (int xx = x; xx < x + size; xx++) { //�������� ��� �����̸� Ȯ��
					for (int yy = y; yy < y + size; yy ++) { //(x,y)~(x+2k,y+2k)Ȯ��
						if (map[xx][yy] == -2) { //��ĭ�� ����ĭ����
							price += a;
						}
						else if (map[xx][yy] == -1) //���� ����ĭ�� ������ ��
							lessBlackCnt--;
					}
				}
				//2. 3k x 3k�̿��� ��� ������ĭ���ִ� �������� ������� �ٽ�ĥ�ؾ���
				price += lessBlackCnt * b; 
				
				//3. ���ĭ�̾�� �ϴ°��� ��� ���
				for (int xx = x + k; xx < x + size - k; xx++) {
					for (int yy = y + k; yy < y + size; yy++) {
						if (map[xx][yy] == -2) { //��ĭ: 1������ �ʿ���º���� �߰�������, �ٽ� ����
							price -= a; 
						}
						else if (map[xx][yy] == -1){ //����ĭ : ��ĭ���� ĥ�ϴ� ����߰�
							price += b; 
						}
					}
				}

				//�ּڰ��� res �� ����
				if (res > price)
					res = price; 
			}
		}

	}

	printf("%d", res);
}

void input() {
	scanf("%d%d%d%d", &n, &m, &a, &b);

	map = new int* [n];
	for (int i = 0; i < n; i++) {
		map[i] = new int[m];
		char _;
		scanf("%c", &_); //�ٹٲ޹�������
		for (int j = 0; j < m; j++) {
			scanf("%c", &_);
			if (_ == '#') {
				map[i][j] = -1; //����ĭ���� -1
				blackCnt++; //����ĭ ������ ��
			}
			else
				map[i][j] = -2; //��ĭ���� -2
		}
	}

}

int main(void) {
	func();

	return 0;
}
