#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
#define MAX 101
using std::vector; using std::queue; using std::pair; using std::string; using std::sort;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;
typedef pair<int, char> pic;
typedef pair<char, int> pci;

int N;
ll p[MAX];
ll p1_cnt;
ll g = 0;

void init();
void func();

void init() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        ll temp;
        scanf("%lld", &temp);
        p[i] = temp;
        if (temp == 1)  p1_cnt++;
    }
}

void func() {
    //1개짜리 돌무더기가 0보다 크고 짝수개이면
    //그동안 총 G = 0 이면 선공이 패배하는데, 이 원리는
    //중간과정에서 p[i] ^ p[i+1] = 0 이 되는 횟수를 한번 역전시키면 가능함.
    //따라서 가장 기본적이게 g = 0 인상태에서 g = p[1] 로바꾸어
    //밑의 for문에서 g ^ p[1] ==> p[1] ^ p[1] = 0 으로 만들어줌.
    if (p1_cnt > 0 && p1_cnt % 2 == 0) {
        g = p[1];
    }
    //모든 돌더미가 돌1개 일때면 승패가 역전되므로 바꿔주어야한다.
    if (p1_cnt == N) {
        N % 2 ? printf("cubelover") : printf("koosaga");
    }
    else {
        for (int i = 0; i < N; i++)
            g ^= p[i];
        g ? printf("koosaga") : printf("cubelover");
    }
}

int main(void) {
    init();
    func();


    return 0;
}