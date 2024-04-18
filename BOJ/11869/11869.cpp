#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
using std::vector; using std::pair;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;
typedef pair<int, char> pic;
typedef pair<char, int> pci;

int n;
ll res;
void init();
void func();

void init() {
    scanf("%d", &n);

    while (n--) {
        ll p;
        scanf("%llu", &p);
        res ^= p;
    }
}

void func() {
    res ? printf("koosaga") : printf("cubelover");
}

int main(void) {
    init();
    func();

    return 0;
}