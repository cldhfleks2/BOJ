#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>

int main(int N) {
	scanf("%d", &N);
	int temp = N, p = 0, r = N % 10, res = 0;
	//10^p <= N < 10^(p+1)
	//p+1�� ���ڸ���
	while (true) { // �� p�� ����
		if (temp < 10)
			break;
		temp /= 10;
		p++;
	}
	//printf("p : %d\n", p); 

	for (int i = p-1; i >= 0; i--) { //�����ܰ� ������
		//�����ܰ�� p-1 ���⼭ +1�ϸ� ���ڸ����̹Ƿ�
		//�����ܰ��� ���ڸ����� p�̾���ϹǷ�
		//���⼱ i+1
		res += 9 * pow(10, i) * (i+1); 
		//printf("res : %d\n", res);
	}

	res += (int)((N - pow(10, p)+1) * (p+1));
	//printf("����res : %d\n", (int)((N - pow(10, p)) * (p + 1)));
	//printf("���� : %d\n", res);

	printf("%d", res);
	return 0;
}

