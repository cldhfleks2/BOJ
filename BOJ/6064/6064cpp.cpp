#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
int GCD(int a, int b) {
	int temp;
	while (b != 0) {
		temp = a % b;
		a = b;
		b = temp;
	}
	return a;
}

int main(void) {
	int t = 0;
	scanf("%d", &t);
	while (t--) {
		int M, N, x, y;
		scanf("%d%d%d%d", &M, &N, &x, &y);
		if (M > N) { // M <= N�� ��Ȳ�� �������
			int temp = M;
			M = N;
			N = temp;
			//x, y�� ��ȯ
			temp = x;
			x = y;
			y = temp;
		}

		int res = -1; //�ᱣ��
		//x(M)����, y�� �ݺ��ϴ°Ͱ�����.
		int step_MN = N - M; //M, N ���� ����
		int step_xy = 0; //x, y ���� ����
		//x�� y���� �ֱⰡª���Ƿ�, ��������� y�� �� ����Ȯ���̳���
		//�׷��� ����
		if (x >= y)
			step_xy = x - y;
		else
			step_xy = N - (y - x);

		int temp_x = y + step_xy; //temp_x�� x�� ������ ���Ҷ��� ����.
		if (temp_x > N - 1) { //temp_x�� M������ ����������
			while(temp_x - (N - 1)) //���Ļ� N-1 �� ���ϰԵ�
				temp_x -= N - 1; //�񱳰����ϰ� ���縸�ִ°�
		}
		int LCM = M * N / GCD(M, N); //�ּҰ����

		if (temp_x == x) { //������ �޷��̶�� �Ʒ��ڵ带����
			if (step_xy > M) { //�������� ��¥��� -1 ���
				res = -1;
				continue;
			}

			res = (step_xy / step_MN) * M; //M���
			int temp_y = y + step_xy;
			if(temp_y > N)
				temp_y %= N;
					
			res += temp_y; //N���
		}
		//�Ұ����ϴٸ� res = -1 �ڵ� ���

		printf("����%d\n", res);
	}




	return 0;
}