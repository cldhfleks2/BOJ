#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
int k, tet1[4], tet2[4];

void calculate() {
	bool error = true;
	//�ظ��� ������
	for(int i = 0 ; i < 4 ; i++)
		if (tet1[0] == tet2[i]) {
			error = false;
		}


}

int main(void) {
	scanf("%d", &k);
	while (k--) {
		for (int i = 0; i < 4; i++) //�����ü1 �Է�
			scanf("%d", &tet1[i]);
		for (int i = 0; i < 4; i++) //�����ü2 �Է�
			scanf("%d", &tet2[i]);

		calculate();
	}

	return 0;
}