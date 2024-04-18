#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
int k, tet1[4], tet2[4];

void calculate() {
	bool error = true;
	//밑면을 맞춰줌
	for(int i = 0 ; i < 4 ; i++)
		if (tet1[0] == tet2[i]) {
			error = false;
		}


}

int main(void) {
	scanf("%d", &k);
	while (k--) {
		for (int i = 0; i < 4; i++) //정사면체1 입력
			scanf("%d", &tet1[i]);
		for (int i = 0; i < 4; i++) //정사면체2 입력
			scanf("%d", &tet2[i]);

		calculate();
	}

	return 0;
}