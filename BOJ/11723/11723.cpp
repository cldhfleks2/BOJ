#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
bool s[21], size=0;
void clear();
void all();

void func() {
	int t, x;
	char _[7];
	scanf("%d", &t);
	while (t--) {
		scanf("%s", &_);

		if (!strcmp(_, "add")) {
			scanf("%d", &x);
			s[x] = true;
		}
		else if (!strcmp(_, "remove")) {
			scanf("%d", &x);
			s[x] = false;
		}
		else if (!strcmp(_, "check")) {
			scanf("%d", &x);
			s[x] ? printf("1\n") : printf("0\n");
		}
		else if (!strcmp(_, "toggle")) {
			scanf("%d", &x);
			s[x] = !s[x];
		}
		else if (!strcmp(_, "all")) {
			all();
		}
		else if (!strcmp(_, "empty")) {
			clear();
		}

	}


}
void clear() {
	for (int i = 1; i <= 20; i++)
		s[i] = false;
}

void all() {
	for (int i = 1; i <= 20; i++)
		s[i] = true;
}
int main(void) {
	func();

	return 0;
}