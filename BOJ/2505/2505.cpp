#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
#define mp std::make_pair 
#define mt std::make_tuple
#define dq std::deque
#define pq std::priority_queue
#define sw std::swap
#define ts(x) std::to_string(x)
#define tc() c_str()
#define sc(x, ...) scanf(x, ##__VA_ARGS__) 
#define pr(x, ...) printf(x, ##__VA_ARGS__) 
#define ins(x) insert(x)
#define pb(x) push_back(x)
#define pf(x) push_front(x)
#define PB() pop_back()
#define PF() pop_front()
#define ph(x) push(x)
#define TT() top()
#define PP() pop()
#define BB() back()
#define FF() front()
#define cls() clear()
#define len(x) x.length()
#define sz(x) ((int)x.size())
#define ms(a) memset(a, 0, sizeof(a)) //0���� �ʱ�ȭ
#define rep(i, n) for(int i = 0; i < n ; i++)
#define rrep(i, r, n) for(int i = r; i < n ; i++)
#define _rrep(i, r, n) for(int i = r; i >= n; i--)
#define each(x, a) for (auto& x: a)
#define all(x) (x).begin(),(x).end() //sort��� �����̳� ��ü�� ó���ؾ��Ҷ� ���
#define range(x, r, n) x.begin() + r, x.begin() + n //STL���� ��������
#define ct continue
#define br break
#define rt return
#define _TYF typedef //�ڵ����̱�
#define _UG using
#define MAX 10001
const int IMAX = INT32_MAX; const int IMIN = INT32_MIN;
const long long LMAX = LLONG_MAX; const long long LMIN = LLONG_MIN;
const long double PI = 3.141592653589793238462643383279502884197;
_UG std::vector; _UG std::stack; _UG std::queue; _UG std::tuple; _UG std::set; _UG std::list; _UG std::bitset; _UG std::string; _UG std::pair; _UG std::greater;
_UG std::tie; _UG std::sort; _UG std::max_element; _UG std::min_element; _UG std::fill;
//_UG std::max; //_UG std::min; //_UG std::map;
_TYF long long ll; _TYF unsigned long long ull;
_TYF pair<int, int> pii; _TYF pair<double, int> pdi; _TYF pair<int, double> pid; _TYF pair<double, double> pdd; _TYF pair<int, ll> pil;
_TYF pair<ll, int> pli; _TYF pair<ll, ll> pll; _TYF pair<ull, ull> pullull; _TYF pair<int, char> pic; _TYF pair<char, int> pci;
_TYF pair<char, char> pcc; _TYF pair<long, char> plc; _TYF pair<char, long> pcl; _TYF pair<ll, char> pllc; _TYF pair<char, ll> pcll;
_TYF pair<ull, char> pullc; _TYF pair<char, ull> pcull; _TYF pair<int, string> pis; _TYF pair<string, int> psi; _TYF pair<long, string> pls;
_TYF pair<string, long> psl; _TYF pair<ll, string> plls; _TYF pair<string, ll> psll; _TYF pair<ull, string> pulls;
_TYF pair<string, ull> psull; _TYF pair<string, string> pss;
_TYF tuple<int, int, int> tiii; _TYF tuple<int, int, int, int> tiiii;
_TYF tuple<ll, ll, ll> tlll; _TYF tuple<ll, ll, ll, ll> tllll;
_TYF vector<string> vs; _TYF queue<string> qs; _TYF stack<string> ss; _TYF dq<string> dqs; _TYF pq<string> pqs; _TYF dq<string> dqs;
_TYF vector<char> vc; _TYF queue<char> qc; _TYF stack<char> sc; _TYF dq<char> dqc; _TYF pq<char> pqc; _TYF dq<char> dqc;
_TYF vector<int> vi; _TYF queue<int> qi; _TYF stack<int> si; _TYF dq<int> dqi; _TYF pq<int> pqi; _TYF dq<int> dqi;
_TYF vector<pii> vii; _TYF queue<pii> qii; _TYF stack<pii> sii; _TYF dq<pii> dqii; _TYF pq<pii> pqii; _TYF dq<pii> dqii;
_TYF vector<tiii> viii; _TYF queue<tiii> qiii; _TYF stack<tiii> siii; _TYF dq<tiii> dqiii; _TYF pq<tiii> pqiii; _TYF dq<tiii> dqiii;
_TYF vector<tiiii> viiii; _TYF queue<tiiii> qiiii; _TYF stack<tiiii> siiii; _TYF dq<tiiii> dqiiii; _TYF pq<tiiii> pqiiii; _TYF dq<tiiii> dqiiii;
_TYF vector<pll> vll; _TYF queue<pll> qll; _TYF stack<ll> sll; _TYF dq<pll> dqll; _TYF pq<pll> pqll; _TYF dq<pll> dqll;
_TYF vector<tlll> vlll; _TYF queue<tlll> qlll; _TYF stack<tlll> slll; _TYF dq<tlll> dqlll; _TYF pq<tlll> pqlll; _TYF dq<tlll> dqlll;
_TYF vector<tllll> vllll; _TYF queue<tllll> qllll; _TYF stack<tllll> sllll; _TYF dq<tllll> dqllll; _TYF pq<tllll> pqllll; _TYF dq<tllll> dqllll;
template <class T> inline T sq(T num) { rt num* num; }//�����Լ�
template <class T> inline T GCD(T num1, T num2) { if (num2 == 0) rt num1; rt GCD(num2, num1 % num2); }
template <class T> inline T LCM(T num1, T num2) { if (num1 == 0 || num2 == 0) rt num1 + num2; rt num1* (num2 / GCD(num1, num2)); }
//STL ���� �ʱ�ȭ �Լ��� ( ms~~ )
template <class T> inline void msq(T& a) { while (!a.empty()) a.PP(); }//queue clear
template <class T> inline void msv(T& a) { a.cls(); }//vector clear
template <class T> inline void msdq(T& a) { a.cls(); }//deque clear
template <class T> inline void msm(T& a) { a.cls(); }//map clear
template <class T> inline void mss(T& a) { while (!a.empty()) a.PP(); }//stack, set clear
template <class T> inline void mspq(T& a) { while (!a.empty()) a.PP(); }//priority_queue clear
//pii operator - (pii a, pii b) { rt pii(a.first - b.first, a.second - b.second); }
//bool operator <= (pii a, pii b) { rt a.first <= b.first && a.second <= b.second; } 
//bool operator >= (pii a, pii b) { rt a.first >= b.first && a.second >= b.second; } 
//bool operator < (pii a, pii b) { if (a == b) return false; rt a <= b; } 
//bool operator > (pii a, pii b) { if (a == b) return false; rt a >= b; }

int N;
vi seq1, seq2;

void init();
void func();

void init() {
    sc("%d", &N);
    rep(i, N) {
        int element;
        sc("%d", &element);
        seq1.pb(element);
        seq2.pb(element);
    }
}

void func() {
    vi start, end;
    int cnt = 0;
    //�տ�������
    while (1) {
        int idx = -2;
        rep(i, N) {
            int cur = seq1[i];
            if (idx == -2 && cur != i + 1) {
                idx = i;
                start.pb(i + 1);
            }
            if (cur == idx + 1) {
                reverse(range(seq1, idx ,i + 1));
                end.pb(i + 1);
            }
        }
        if (idx == -2) br;
        if (cnt >= 3) br;
        cnt++;
    }
    
    if (cnt == 3) {
        start.cls();
        end.cls();
        cnt = 0;
        //�ڿ������� �ٽ�Ž��
        while (1) {
            int idx = -2;
            _rrep(i, N-1, 0) {
                int cur = seq2[i];
                if (idx == -2 && cur != i + 1) {
                    idx = i;
                    end.pb(i + 1);
                }
                if (cur == idx + 1) {
                    reverse(range(seq2, i, idx + 1));
                    start.pb(i + 1);
                }
            }
            if (idx == -2) br;
            if (cnt >= 3) br;
            cnt++;
        }
    }
    if(cnt == 0)
        pr("1 1\n1 1");
    else if (cnt == 1) 
        pr("%d %d\n1 1", start[0], end[0]);
    else if (cnt == 2)
        pr("%d %d\n%d %d", start[0], end[0], start[1], end[1]);

}

int main(void) {
    init();
    func();

    rt 0;
}
