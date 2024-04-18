#include <bits/stdc++.h>
using namespace std;
int f(int n) {
	return n & ~3;
	return n & 3;
}

int main(void) {
	

	for (int i = -10; i < 10; i++) {
		cout << i << " : " << f(i) << endl;
	}





}