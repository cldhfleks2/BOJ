#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
#define mp std::make_pair 
#define mt std::make_tuple
#define dq std::deque
#define pq std::priority_queue
#define sw std::swap
#define ts(x) std::to_string(x)
#define tc(x) x.c_str()
#define sc(x, ...) scanf(x, ##__VA_ARGS__) 
#define pr(x, ...) printf(x, ##__VA_ARGS__) 
#define pb(x) push_back(x)
#define pf(x) push_front(x)
#define PB() pop_back()
#define PF() pop_front()
#define ph(x) push(x)
#define P() pop()
#define B() back()
#define F() front()
#define len(x) x.length()
#define sz(x) ((int)x.size())
#define ms(a) memset(a, 0, sizeof(a)) //0으로 초기화
#define rep(i, n) for(int i = 0; i < n ; i++)
#define rrep(i, r, n) for(int i = r; i < n ; i++)
#define _rrep(i, r, n) for(int i = r; i >= n; i--)
#define each(x, a) for (auto& x: a)
#define all(x) (x).begin(),(x).end() //sort등에서 컨테이너 전체를 처리해야할때 사용
#define ct continue
#define br break
#define rt return
//#define MAX 
const int IMAX = INT32_MAX; const int IMIN = INT32_MIN;
const long long LMAX = LLONG_MAX; const long long LMIN = LLONG_MIN;
const long double PI = 3.141592653589793238462643383279502884197;
using std::vector; using std::stack; using std::queue; using std::tuple; using std::set; using std::list; using std::bitset; using std::string; using std::pair; using std::greater;
using std::tie; using std::sort; using std::max_element; using std::min_element; using std::fill;
//using std::max; //using std::min; //using std::map;
typedef long long ll; typedef unsigned long long ull;
typedef pair<int, int> pii; typedef pair<double, int> pdi; typedef pair<int, double> pid; typedef pair<double, double> pdd; typedef pair<int, ll> pil;
typedef pair<ll, int> pli; typedef pair<ll, ll> pll; typedef pair<ull, ull> pullull; typedef pair<int, char> pic; typedef pair<char, int> pci;
typedef pair<char, char> pcc; typedef pair<long, char> plc; typedef pair<char, long> pcl; typedef pair<ll, char> pllc; typedef pair<char, ll> pcll;
typedef pair<ull, char> pullc; typedef pair<char, ull> pcull; typedef pair<int, string> pis; typedef pair<string, int> psi; typedef pair<long, string> pls;
typedef pair<string, long> psl; typedef pair<ll, string> plls; typedef pair<string, ll> psll; typedef pair<ull, string> pulls;
typedef pair<string, ull> psull; typedef pair<string, string> pss;
typedef tuple<int, int, int> tiii; typedef tuple<int, int, int, int> tiiii;
typedef tuple<ll, ll, ll> tlll; typedef tuple<ll, ll, ll, ll> tllll;
typedef vector<string> vs; typedef queue<string> qs; typedef stack<string> ss; typedef dq<string> dqs; typedef pq<string> pqs;
typedef vector<char> vc; typedef queue<char> qc; typedef stack<char> sc; typedef dq<char> dqc; typedef pq<char> pqc;
typedef vector<int> vi; typedef queue<int> qi; typedef stack<int> si; typedef dq<int> dqi; typedef pq<int> pqi;
typedef vector<pii> vii; typedef queue<pii> qii; typedef stack<pii> sii; typedef dq<pii> dqii; typedef pq<pii> pqii;
typedef vector<tiii> viii; typedef queue<tiii> qiii; typedef stack<tiii> siii; typedef dq<tiii> dqiii; typedef pq<tiii> pqiii;
typedef vector<tiiii> viiii; typedef queue<tiiii> qiiii; typedef stack<tiiii> siiii; typedef dq<tiiii> dqiiii; typedef pq<tiiii> pqiiii;
typedef vector<pll> vll; typedef queue<pll> qll; typedef stack<ll> sll; typedef dq<pll> dqll; typedef pq<pll> pqll;
typedef vector<tlll> vlll; typedef queue<tlll> qlll; typedef stack<tlll> slll; typedef dq<tlll> dqlll; typedef pq<tlll> pqlll;
typedef vector<tllll> vllll; typedef queue<tllll> qllll; typedef stack<tllll> sllll; typedef dq<tllll> dqllll; typedef pq<tllll> pqllll;
template <class T> inline T sq(T num) { rt num* num; }//제곱함수
template <class T> inline T GCD(T num1, T num2) { if (num2 == 0) rt num1; rt GCD(num2, num1 % num2); }
template <class T> inline T LCM(T num1, T num2) { if (num1 == 0 || num2 == 0) rt num1 + num2; rt num1* (num2 / GCD(num1, num2)); }
//STL 전용 초기화 함수들 ( ms~~ )
template <class T> inline void msq(T a) { while (!a.empty()) a.pop(); }//queue clear
template <class T> inline void msv(T a) { a.clear(); }//vector clear
template <class T> inline void msdq(T a) { a.clear(); }//deque clear
template <class T> inline void msm(T a) { a.clear(); }//map clear
template <class T> inline void mss(T a) { while (!a.empty()) a.pop(); }//stack, set clear
template <class T> inline void mspq(T a) { while (!a.empty()) a.pop(); }//priority_queue clear
//pii operator - (pii a, pii b) { return pii(a.first - b.first, a.second - b.second); }
//bool operator <= (pii a, pii b) { return a.first <= b.first && a.second <= b.second; } 
//bool operator >= (pii a, pii b) { return a.first >= b.first && a.second >= b.second; } 
//bool operator < (pii a, pii b) { if (a == b) return false; return a <= b; } 
//bool operator > (pii a, pii b) { if (a == b) return false; return a >= b; }

bool B[5][5];
void init();
void func();

//{빙고줄, 빙고줄에 포함되는 칸수}계산
pii checkingBingo() {
    set<pii> list;
    int LineCnt = 0;
    bool crossIncrease = false;
    bool crossDecrease = false;
    rep(i, 5) {
        //가로
        bool horizontal = true;
        bool vertical = true;
        rep(j, 5)
            if (!B[i][j]) horizontal = false;
        //세로
        rep(j, 5)
            if (!B[j][i]) vertical = false;

        if (horizontal) {
            rep(j, 5)
                list.insert({ i, j });
            LineCnt++;
        }
        if (vertical) {
            rep(j, 5)
                list.insert({ j, i });
            LineCnt++;
        }
        if (!B[i][i]) crossIncrease = false;
        if (!B[i][5 - i]) crossDecrease = false;
    }
    {}
    if (crossIncrease) {
        list.insert({ 0, 0 });
        list.insert({ 1, 1 });
        list.insert({ 2, 2 });
        list.insert({ 3, 3 });
        list.insert({ 4, 4 });
        LineCnt++;
    }
    if (crossDecrease) {
        list.insert({ 4, 0 });
        list.insert({ 3, 1 });
        list.insert({ 2, 2 });
        list.insert({ 1, 3 });
        list.insert({ 0, 4 });
        LineCnt++;
    }

    rt { LineCnt++, list.size()};
}

//초기화하는 함수
void init() {
    rep(i, 5)
        rep(j, 5)
            B[i][j] = false; //초기화
}

//결과를 출력한다.
void printAll() {
    rep(i, 5) {
        rep(j, 5)
            if (B[i][j])
                pr("#");
            else
                pr(".");
        pr("\n");
    }
}

//전체 칠해진 칸의 갯수를 계산
int findCnt() {
    int res = 0;
    rep(i, 5)
        rep(j, 5)
            if (B[i][j]) res++;
    rt res;
}

//빙고를 체크해보는 함수
//특정칸 x, y를 무조건 칠해보고 체크해본다.
void checkBingo(int x, int y) {
    B[x][y] = true;
    int cnt = findCnt();
    while (1) {
        bool check; //하나라도 체크하면?
        if (!B[0][3] && B[3][3]) B[0][3] = true;
        if (!B[3][3] && B[0][3]) {
            B[0][3] = true;
            B[3][3] = true;
        }
        if (!B[1][0] && !B[3][0]) B[1][0] = true;
        if (!B[3][0] && !B[1][0]) B[3][0] = true;
        if (!B[4][0] && B[4][4]) B[4][0] = true;
        if (!B[0][0] && !(B[4][0] && B[3][1] && B[2][2] && B[1][3] && B[0][4])) B[0][0];
        if (!B[0][2] && B[0][0] && B[1][1] && B[2][2] && B[3][3] && B[4][4]) B[0][2] = true;
        //if(!B[1][1])
        if (!B[1][3] && cnt <= 17) B[1][3] = true;
        if (!B[1][4] && checkingBingo().second % 2 == 0) B[1][4] = true;
        if (!B[2][1] && (findCnt() - checkingBingo().second) >= 5) B[2][1] = true;
        if(!B[2][2] ||  ) 




        int CNT = findCnt();
        if (cnt == CNT) break; //달라진게없으면
    }

}

void func() {
    rep(x, 5) {
        rep(y, 5) {
            //절대 처음으로 칠해질 수 없는 칸들
            if (x == 0 && y == 1) continue; 
            if (x == 1 && y == 1) continue; 
            if (x == 2 && y == 2) continue;


            pr(">>>>>>>>>>> 빙고 결과 %d줄, %d칸\n", checkingBingo().first, checkingBingo().second);
            init();
        }
    }
}

int main(void) {
    init();
    func();

    rt 0;
}