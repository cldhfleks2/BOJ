#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
using std::vector; using std::stack; using std::queue; using std::deque; using std::tuple;
using std::string; using std::pair; using std::make_tuple; using std::tie;
using std::sort; using std::swap;
using std::make_pair; using std::max_element; using std::min_element; using std::bitset; using std::to_string;
using std::fill; using std::priority_queue; using std::greater;
//using std::max; using std::min; using std::map;
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


int L;
ll H, M = 1234567891;
void func();
void func() {
    scanf("%d", &L);
    char c;
    scanf("%c", &c);
    
    for (int i = 0; i < L; i++) {
        ll a;
        scanf("%c", &c);
        a = c - 96;
       ll h = a;
       for (int j = 1; j <= i; j++)
           h = (h * 31) % M;
       H = (H + h) % M;
    }

    printf("%lld", H);
}

int main(void) {
    func();


    return 0;
}