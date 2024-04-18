#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
#define MOD 1000000007
#define BOUND 1000000000000
#define MININT -2147483647
#define MAXINT 2147483647
using std::vector; using std::stack; using std::queue;
using std::deque; using std::string; using std::pair;
using std::sort; using std::max; using std::min;
using std::make_pair; using std::max_element; using std::min_element;
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

//우선순위 큐에서 하나씩 꺼낸 후 
//(=now), now^2 과 (now-1)^4+1 을 큐에 넣어주는 식으로 그런디 값을 구함 
int N, res;
ll g;
//ll : 키
//int : value
map<ll, int> m;
//우선순위큐 -> 우선순위높은순으로 나옴, 내부적으로 힙구조를 만들어
//완전 이진트리형태를 유지
//ll : 자료형
//vector<ll> : 힙구조를 구현할 구현체(자료형). 일반적으로 vector
//greater : 가장 작은 값부터 나오도록(낮은값이 top유지)
priority_queue<ll, vector<ll>, greater<ll>> pq;

int findGrundy(ll p) {
    double root4, root2;
    bool FLAG = false;
    vector<int> v = { 1,1,1,1,1 };
    root4 = sqrt(sqrt(p)); //x^1/4
    root2 = sqrt(p); //x^1/2
    for (auto it = m.begin(); it != m.end(); it++) {
        if (FLAG) {
            if (it->first > root2) break;
            v[it->second] = 0;
        }
        else if (it->first >= root4) {
            FLAG = true;
            if (it->first - 1 > root4) it--;
            v[it->second] = 0;
        }
    }
    for (int i = 0; i < 5; i++) 
        if (v[i]) return i;
    return 5;
}

int getGrundy(ll p) {
    auto it = m.upper_bound(p);
    it--;
    return it->second;
}

int main(void) {
    m[0] = 0;
    m[4] = 1;
    pq.push(4);
    ll cur, next;
    while (!pq.empty()) {
        cur = pq.top();
        if (cur != 4) m[cur] = findGrundy(cur);
        if (cur <= 1000000) pq.push(cur * cur);
        if (cur <= 1001) {
            cur--;
            pq.push(cur * cur * cur * cur + 1);
        }
        pq.pop();
    }

    ll p;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%lld", &p);
        g = g ^ getGrundy(p);
    }
    printf("%s", g ? "koosaga" : "cubelover");

    return 0;
}