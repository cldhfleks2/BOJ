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


int mod[] = { 0, 1, 0, 1, 2, 3, 2 };
void init();
void init() {
    int n;
    scanf("%d", &n);
    n %= 7;
    mod[n] ? printf("SK") : printf("CY");
}

int main(void) {
    init();

    return 0;
}