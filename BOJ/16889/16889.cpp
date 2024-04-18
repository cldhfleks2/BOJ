#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
using std::vector; using std::stack; using std::queue;
using std::deque; using std::string; using std::pair;
using std::sort; using std::max; using std::min;
using std::make_pair; using std::max_element; using std::min_element; using std::bitset;
using std::fill; using std::priority_queue; using std::map; using std::greater;
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

int N;
ll res, g[63];
void init();
void func();

void init() {
    scanf("%d", &N);
    g[0] = 0;
    g[1] = 1;
    g[2] = 1;
    int cnt = 3;
    int j = 2, k = 0;
    for (int i = 3; i < 63; i++) {
        if (k == cnt) {
            k = 0;
            cnt++;
            ++j;
        }
        g[i] = j;
        k++;
    }

    while (N--) {
        int temp;
        scanf("%d", &temp);
        res ^= g[temp];
    }
}

void func() {
    printf("%s", res ? "koosaga" : "cubelover");
}

int main(void) {
    init();
    func();


    return 0;
}