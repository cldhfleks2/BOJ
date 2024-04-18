#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
using std::vector; using std::stack; using std::queue; using std::deque; using std::tuple;
using std::string; using std::pair; using std::make_tuple; using std::tie;
using std::sort;
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

typedef struct Line {
    pll p1, p2;
}L;

L line1, line2;
void init();
void func();
ll ccw(pll p1, pll p2, pll p3);
void init() {
    int x1, y1, x2, y2, x3, y3, x4, y4;
    scanf("%d%d%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4);
    line1.p1 = { x1, y1 };
    line1.p2 = { x2, y2 };
    line2.p1 = { x3, y3 };
    line2.p2 = { x4, y4 };
}

void func() {
    //각각 선분에대해 다른 선분에대한 외적이 모두 0이거나 음수이면 두 선분이 교차하는것
    //x1(a)ㅡx2(b) 선분에서 x3(c)ㅡx4(d)선분에대한 두 방향값의 곱
    ll ab = ccw(line1.p1, line1.p2, line2.p1) * ccw(line1.p1, line1.p2, line2.p2);
    //x3(c)ㅡx4(d) 선분에서 x1(a)ㅡx2(b)선분에대한 두 방향값의 곱
    ll cd = ccw(line2.p1, line2.p2, line1.p1) * ccw(line2.p1, line2.p2, line1.p2);
    if (ab <= 0 && cd <= 0)
        printf("1");
    else
        printf("0");
}

//외적값을 계산해서 방향을 정수로 리턴
//1:반시계방향  0:평행  -1:시계방향
ll ccw(pll p1, pll p2, pll p3) {
    ll op = (p1.first * p2.second + p2.first * p3.second + p3.first * p1.second)
        - (p1.second * p2.first + p2.second * p3.first + p3.second * p1.first);
    if (op < 0)
        return 1;
    else if (op == 0)
        return 0;
    else
        return -1;

}

int main(void) {
    init();
    func();


    return 0;
}