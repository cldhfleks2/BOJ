#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
int person=0, max=0;


int main(int _) {
	scanf("%d", &_);
	for (int i = 0; i < 3; i++) {
		scanf("%d", &_);
		person += _;
		if (max < person) max = person;
		scanf("%d", &_);
		person -= _;
		if (max < person) max = person;
	}
	scanf("%d", &_);

	printf("%d", max);

	return 0;
}