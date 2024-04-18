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

int n;
ll grundy = 0;
void init();
void func();
void init() {
    scanf("%d", &n);
    while (n--) {
        ll p;
        scanf("%llu", &p);
        p % 2 == 0 ? grundy ^= p / 2 - 1 : grundy ^= p / 2 + 1;
    }
}

void func() {
    grundy != 0 ? printf("koosaga") : printf("cubelover");
}

int main(void) {
    init();
    func();


    return 0;
}