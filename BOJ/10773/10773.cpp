#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
using std::stack; 
int k, sum, size;
stack<int> s;

int main(void) {
	scanf("%d", &k);
	while (k--) {
		int n;
		scanf("%d", &n);
		if (n == 0)
			s.pop();
		else
			s.push(n);
	}
	size = s.size();
	for (int i = 0; i < size; i++) {
		sum += s.top();
		s.pop();
	}

	printf("%d", sum);

	return 0;
}