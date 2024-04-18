#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
int n;
bool state, ** computer;

void init() {
	int _;
	scanf("%d%d", &n, &_);
	if (_ == 0)
		state = false;
	else
		state = true;
	computer = new bool *[n];
	for (int i = 0; i < n; i++) {
		computer[i] = new bool[n];
		for (int j = 0; j < n; j++) {
			scanf("%d", &_);
			if (_ == 0)
				computer[i][j] = false;
			else
				computer[i][j] = true;
		}
	}

}

void func() {
	while (1) {
		bool find = false;
		//°¡·ÎÅ½»ö
		for (int i = 0; i < n; i++) {
			int onCnt = 0, offCnt = 0;
			for (int j = 0; j < n; j++) {
				if (computer[i][j])
					onCnt++;
				else
					offCnt++;
			}
			if (state) { //true·Î ¹Ù²ã¾ß ÇÒ¶§
				if (onCnt > offCnt)
					for (int j = 0; j < n; j++)
						if (computer[i][j] != true) {
							computer[i][j] = true;
							find = true;
						}

			}
			else { //false·Î ¹Ù²ã¾ß ÇÒ¶§
				if (offCnt > onCnt)
					for (int j = 0; j < n; j++)
						if (computer[i][j] != false) {
							computer[i][j] = false;
							find = true;
						}
			}		
		}

		//¼¼·ÎÅ½»ö
		for (int i = 0; i < n; i++) {
			int onCnt = 0, offCnt = 0;
			for (int j = 0; j < n; j++) {
				if (computer[j][i])
					onCnt++;
				else
					offCnt++;
			}
			if (state) { //true·Î ¹Ù²ã¾ß ÇÒ¶§
				if (onCnt > offCnt)
					for (int j = 0; j < n; j++)
						if (computer[j][i] != true) {
							computer[j][i] = true;
							find = true;
						}

			}
			else { //false·Î ¹Ù²ã¾ß ÇÒ¶§
				if (offCnt > onCnt)
					for (int j = 0; j < n; j++)
						if (computer[j][i] != false) {
							computer[j][i] = false;
							find = true;
						}
			}
		}
		if (!find) break;
	}
	bool res = true;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (computer[i][j] != state)
				res = false;

	printf("%d", res);
}

int main(void) {
	init();
	func();

	return 0;
}