#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
#define MAX 31
using std::vector; using std::stack; using std::queue; using std::deque; using std::tuple;
using std::string; using std::pair; using std::make_tuple; using std::tie;
using std::sort; using std::max; using std::min;
using std::make_pair; using std::max_element; using std::min_element; using std::bitset; using std::to_string;
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
    dp[0] = 1;
    dp[2] = 3;
    for (int i = 0; i < N / 2; i++)
        dp[i * 2 + 1] = 0; //È¦¼ö¸é ¸ðµÎ 0
}

void func() {
    if (N % 2 == 1) {
        printf("0");
        return;
    }
    for (int i = 4; i <= N; i += 2) {
        int sum = 0;
        for (int j = 2; i - j >= 0; j += 2) {
            if (j == 2)
                sum += dp[i - j] * dp[2];
            else
                sum += dp[i - j] * 2;
        }
        dp[i] = sum;
    }

    printf("%d", dp[N]);
}

int main(void) {
    init();
    func();


    return 0;
}