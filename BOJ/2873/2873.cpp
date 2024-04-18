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
#define MAX 1001
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

int R, C;
int map[MAX][MAX];
bool visited[MAX][MAX];
int dxy[][2] = { {1,0}, {0, 1}, {-1, 0}, {0, -1} };


void init();
void func();

void init() {
    scanf("%d%d", &R, &C);
    rep(i, R)
        rep(j, C)
            scanf("%d", &map[i][j]);
}

void func() {
    if (R % 2) { //세로줄이 홀수일때
        //모든칸을 지나면된다.
        rep(x, R) {
            rep(y, C - 1) {
                if (x % 2)
                    //홀수일떈 왼쪽
                    pr("L");
                else
                    //짝수일땐 오른쪽
                    pr("R");
            }
            if(x != R - 1)
                pr("D");
        }
    }
    else if (C % 2) { //가로줄이 홀수일때
        rep(y, C) {
            rep(x, R - 1) {
                if (y % 2)
                    pr("U");
                else
                    pr("D");
            }
            if (y != C - 1)
                pr("R");
        }
    }
    else { //세로줄이 짝수일때
        //-. 못지나가는 하나의 칸을 찾는다.
        pii blank; //칸의 좌표
        int min = 1000; //칸의 최댓값
        rep(i, R) {
            rep(j, C) {
                if (i % 2 != j % 2) {
                    if (min > map[i][j]) {
                        min = map[i][j];
                        blank = { i, j }; //좌표기록
                    }
                }
            }
        }
        int blank_X, blank_Y;
        tie(blank_X, blank_Y) = mt(blank.first, blank.second);

        //pr(">>>>>>>>>>>%d,%d\n", blank_X, blank_Y); //DEBUG

        //1단계 : 
        //pr("\n1 ====================\n"); //DEBUG
        rep(x, (blank_X/2)*2 ) { //
            rep(y, C - 1) {
                if (x % 2)
                    pr("L");
                else
                    pr("R");
            }
            pr("D");
        }
        //pr("\n2 ====================\n"); //DEBUG
        //2단계 : 구한 칸을포함하는 짝,홀의 2행
        //D R U R  반복
        int X = (blank_X / 2) * 2, Y = 0;
        int end_X = (blank_X / 2) * 2, end_Y = C - 1;
        int dxy[][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, 1} };
        char dchar[] = { 'D', 'R', 'U', 'R'};
        int dir = 0;
        int cnt = 2*(C - 1); //총 이동횟수
        while (cnt--) {
            X += dxy[dir][0];
            Y += dxy[dir][1];
            //못지나가는 칸을 만날때
            if (X == blank_X && Y == blank_Y) {
                //우측으로 한칸이동
                pr("R"); 
                Y++;
                //dir이 일정하므로 방향유지하고 계속 이동
            }
            else {
                pr("%c", dchar[dir]);
                
                dir++;
            }

            dir %= 4;
            //우측아래에 도달하면 종료
            if (X == end_X && Y == end_Y)
                break;
        }
        //pr("\n3 ====================\n"); //DEBUG
        //3단계 : 남은 행
        //      <-------
        //     ↓
        //      ------->
        cnt = R - ((blank_X / 2) + 1) * 2;
        rep(x, cnt) {
            pr("D");
            rep(_, C - 1) {
                if (x % 2)
                    pr("R");
                else
                    pr("L");
            }
        }
    }
}

int main(void) {
    init();
    func();

    rt 0;
}