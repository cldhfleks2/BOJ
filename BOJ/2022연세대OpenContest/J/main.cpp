#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
using namespace std;

//1 <= v[i] <= 1e9
//1 <= v.size() <= 1e6
//�ð����ѿ�, ���� ����� ���� �Լ��� �ۼ��϶�.
vector<long long> calc(const vector<long long>& v, int N) {
    vector<long long> ans(N);
    ans[0] = 1;
    

    for (int x = 1; x < N; x++) { // N-1�� ��ȯ (x����)
        long long m = 1000000000000000000; // (1e18)
        for (int y = x-1; y >= 0; y--) { // 0 <= y <= x-1
            //�ּڰ��� ã�� ����
            m = min(m, v[y + 1]);
            m = min(m, v[y]);
            ans[x] = ans[x] + ans[y] * m;
            ans[x] = ans[x] % 1000000007; // (1e9 + 7)
        }
    }

    return ans;
}

int main() {
	int N;
	scanf("%d", &N);

	vector<long long> arr(N);
	for (int i = 0; i < N; i++)
		scanf("%lld", &arr[i]);

	vector<long long> ans = calc(arr, N);
	for (long long& it : ans)
		printf("%lld\n", it);

	return 0;
}
