#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
int n, m;


int main(void) {
	for (int i = 0; i < 3; i++) {
		n = 0; m = 0;
		for (int k = 0, _; k < 4; k++) {
			scanf("%d", &_);
			if (_ == 0) 
				n++;
			else
				m++;
		}
		if (n == 1) printf("A\n");
		if(n == 2) printf("B\n");
		if(n == 3)printf("C\n");
		if(n == 4) printf("D\n");
		if(n == 0)printf("E\n");
	}


}