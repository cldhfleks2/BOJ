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

ll N, M, H;
deque<ll> tree; 
int size; //트리갯수
ll max;
void init();
void func();

void init() {
    scanf("%lld%lld", &N, &M);
    for (int i = 0; i < N; i++) {
        ll h;
        scanf("%lld", &h);
        tree.push_back(h);
        if (max < h) max = h;
    }
    size = tree.size();
}

void func() {
    //절단기의 높이를 이분탐색하여 찾는다.
    ll left = 0, mid = max / 2, right = max;
    while (left <= right) { 
        //printf("%lld, %lld, %lld\n", left, mid, right);
        ll sum = 0; //절단기높이가 mid일때 모든나무를 자르고난 길이 합
        for (int i = 0; i < size; i++) {
            ll len = tree[i] - mid; //자르고난 길이
            if (len > 0) //길이가 양수면 합산
                sum += len;
        }
        //최소한 M의길이를 확보해야한다
        if (sum >= M) { //자른길이합이 M보다 크면 높이H를 더 늘려보자.
            H = mid; //일단 저장
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
        mid = (left + right) / 2;
    }

    printf("%lld", H);
}

int main(void) {
    init();
    func();


    return 0;
}