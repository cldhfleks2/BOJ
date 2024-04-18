#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
#define MAX 100001
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
int dp[MAX];


void init();
void func();

void init() {
    scanf("%d", &N);
    fill(dp, dp + MAX, -1);
    dp[0] = -1;
    dp[1] = -1;
    dp[2] = -1;
}

int find(int n) {
    if (dp[n] != -1) return dp[n];
    int left = n / 2;
    int right
}

void func() {

}



int main(void) {
    init();
    func();


    return 0;
}