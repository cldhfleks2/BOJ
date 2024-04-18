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

ll n;
ll g; //전역변수는 0으로 자동 초기화
void func();

void func() {
    scanf("%lld", &n);
    int mod = n % 7;
    mod == 0 || mod == 2 ? printf("CY") : printf("SK");
}

int main(void) {
    func();


    return 0;
}