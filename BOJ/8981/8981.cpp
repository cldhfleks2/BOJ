#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
int n, *x, *y;
void init();
void func();

void func() {
	printf("%d\n", n);
	//�ʱ갪
	x[0] = y[0];
	int cur = 0;
	for (int i = 1; i < n; i++) {
		int value = x[cur];
		cur = (cur + value) % n; //�������ŭ Ŀ���̵�
		while (x[cur] != -1) cur = (cur + 1) % n; //�̹� �ٸ����������� +1�� �̵�
		x[cur] = y[i]; //���� ��°��� �ش���ġ�� ����
	}

	for (int i = 0; i < n; i++) printf("%d ", x[i]);

}

void init() {
	scanf("%d", &n);
	x = new int[n];
	y = new int[n];
	for (int i = 0; i < n; i++) {
		scanf("%d", &y[i]);
		x[i] = -1;
	}
}

int main(void) {
	init();
	func();
	
	return 0;
}