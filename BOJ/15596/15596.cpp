#include <bits/stdc++.h>
long long sum(std::vector<int>& a) {
	long long res = 0;
	for (int i = 0; i < a.size(); i++) res += a[i];
	return res;
}