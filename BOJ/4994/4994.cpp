#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
using std::vector; using std::stack; using std::queue;
using std::deque; using std::string; using std::pair;
using std::sort;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;
typedef pair<int, char> pic;
typedef pair<char, int> pci;
typedef pair<string, int> psi;
typedef pair<int, string> pis;
typedef pair<string, string> pss;

int N = 200;
void func() {
    queue<ll> q;
    scanf("%d", &N);
    while (N) {
        q.push(1);
        while (!q.empty()) {
            ll num = q.front();
            //printf(">>>> %lld mod %d = %d\n", num, N, num % N);
            if (num % N == 0) {
                printf("%lld\n", num);
                break;
            }
            else {
                q.push(num * 10);
                q.push(num * 10 + 1);
                q.pop();
            }

        }
        while (!q.empty()) q.pop();
        scanf("%d", &N); //다음 수를 받아들임.
    }
}

int main(void) {
    func();

    return 0;
}