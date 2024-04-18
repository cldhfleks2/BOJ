#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
using std::vector; using std::stack; using std::queue; using std::deque; using std::tuple; using std::priority_queue;
using std::string; using std::pair; using std::make_tuple; using std::tie;
using std::sort; using std::swap;
using std::make_pair; using std::max_element; using std::min_element; using std::bitset; using std::to_string;
using std::fill; using std::priority_queue; using std::greater; using std::map;
//using std::max; using std::min; 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, int> pdi;
typedef pair<int, double> pid;
typedef pair<double, double> pdd;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;
typedef pair<int, char> pic;
typedef pair<char, int> pci;
typedef pair<string, int> psi;
typedef pair<int, string> pis;
typedef pair<string, string> pss;

int K, N;
vector<ll> prime;
priority_queue<ll, vector<ll>, greater<ll>> pq;
void init();
void func();

void init() {
    scanf("%d%d", &K, &N);
    for (int i = 0; i < K; i++) {
        ll p;
        scanf("%lld", &p);
        prime.push_back(p);
        pq.push(p);
    }
}

void func() {
    ll prev = 0;
    while (N--) {
        while (prev == pq.top())
            pq.pop();

        for (int i = 0; i < prime.size(); i++) {
            ll res = pq.top() * prime[i];
            if (res >= INT32_MAX) break;
            pq.push(res);
            if (pq.top() % prime[i] == 0) break;
        }
        prev = pq.top();
        pq.pop();
    }

    printf("%lld", prev);
}

int main(void) {
    init();
    func();

    return 0;
}