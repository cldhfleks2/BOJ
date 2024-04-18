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

//�켱���� ť���� �ϳ��� ���� �� 
//(=now), now^2 �� (now-1)^4+1 �� ť�� �־��ִ� ������ �׷��� ���� ���� 
int N, res;
ll g;
//ll : Ű
//int : value
map<ll, int> m;
//�켱����ť -> �켱�������������� ����, ���������� �������� �����
//���� ����Ʈ�����¸� ����
//ll : �ڷ���
//vector<ll> : �������� ������ ����ü(�ڷ���). �Ϲ������� vector
//greater : ���� ���� ������ ��������(�������� top����)
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