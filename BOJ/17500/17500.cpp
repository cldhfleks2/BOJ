#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
#define mp std::make_pair 
#define mt std::make_tuple
#define sw std::swap;
#define dq std::deque
#define pq std::priority_queue
#define ts(x) std::to_string(x)
#define tc(x) x.c_str()
#define sc(x, ...) scanf(x, ##__VA_ARGS__) 
#define pr(x, ...) printf(x, ##__VA_ARGS__) 
#define pb(x) push_back(x)
#define pf(x) push_front(x)
#define ppb(x) pop_back(x)
#define ppf(x) pop_front(x)
#define ph(x) push(x)
#define T() top()
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
#define MAX 5
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
bool operator <= (pii a, pii b) { return a.first <= b.first && a.second <= b.second; }
bool operator >= (pii a, pii b) { return a.first >= b.first && a.second >= b.second; }
bool operator < (pii a, pii b) { if (a == b) return false; return a <= b; }
bool operator > (pii a, pii b) { if (a == b) return false; return a >= b; }


int N;
int map[MAX][MAX];
vii animalList; //동물위치
int dxy[][2] = { {1,0}, {0,-1}, {-1,0}, {0,1} }; //하-좌-상-우

void func();
bool isRight(string flagStr);
void print(string s);
void init();

void init() {
    char c;
    sc("%d", &N);
    rep(i, N) {
        sc("%c", &c); //줄바꿈문자 제거
        rep(j, N) {
            sc("%c", &c);
            if (c == '.') {
                map[i][j] = 0; //빈공간은 0 
            }
            else {
                map[i][j] = c - 'A' + 1; //대문자를 숫자1~27로 대체
                animalList.pb(mp(i, j));
            }
        }
    }
}

void print(string s) {
    pr("yes\n");
    //////////////////// DEBUG ////////////////////
    pr("--------------------------------\n");
    bool D[MAX][MAX];
    ms(D);
    rep(i, len(s)/2) {
        int x = s[i * 2] - '0';
        int y = s[i * 2 + 1] - '0';
        D[x][y] = true;
    }
    rep(i, N + 1) {
        rep(j, N + 1) {
            pr("%2d ", D[i][j]);
        }
        pr("\n");
    }
    pr("--------------------------------\n");
    //////////////////// DEBUG ////////////////////
}

//만들어진 국경이 올바른가?
//false : 동물종이 2종이상
//true : 동물종이 0, 1개
bool isRight(string flagStr) {
    pr("%s!!!!!!!!!!!!!!!!!!!!!!\n", tc(flagStr)); //DEBUG
    //맵의 모든위치에서 주변 4방향으로 이동가능 여부
    bool move[MAX][MAX][4] = { true };
    //이전위치
    int fx = flagStr[0], fy = flagStr[1]; 

    //1. 국경선을 읽어서 move체크
    rrep(idx, 1, len(flagStr) / 2) {
        //현재위치
        int fxx = flagStr[idx * 2]; 
        int fyy = flagStr[idx * 2 + 1];
        //0:하 1:좌 2:상 3:우
        pii p1, p2; //국경선을 사이에둔 두 칸의 위치
        mp(fx, fy) < mp(fxx, fyy) ? p2 = mp(fx, fy) : p2 = mp(fxx, fyy);
        p1 = p2;

        //가로국경선 : x좌표 일정함
        if (fx == fxx) { 
            p1.first--; 
            move[p1.first][p1.second][0] = false; //국경선을 지날수없다
            move[p2.first][p2.second][2] = false;
        }
        //세로국경선 : y좌표 일정함
        if (fy == fyy) { 
            p1.second--; 
            move[p1.first][p1.second][3] = false;
            move[p2.first][p2.second][1] = false;
        }

        fx = fxx; //이전위치 기록
        fy = fyy;
    }

    //2. 모든 동물이 있는 위치에서 BFS를 진행
    rep(idx, sz(animalList)) {
        bool visited[MAX][MAX] = { false }; //BFS에 쓰일 방문체크배열
        bool num[27] = { false }; //동물번호(1~26) 체크
        qii loc; //좌표
        qs animal; //동물종 리스트(지금까지 거친)

        int startX, startY;
        tie(startX, startY) = animalList[idx]; //시작위치를 동물이있던 위치로.
        loc.ph(mp(startX, startY));
        map[startX][startY] != 0 ? animal.ph(ts(map[startX][startY])) : animal.ph(""); //동물을 리스트에 추가
        visited[startX][startY] = true;

        pr("%d, %d@@@@@@@@@@@@\n", startX, startY);
        while (!loc.empty()) {
            //현재위치 x,  y
            int x, y;
            tie(x, y) = loc.F();
            loc.P();
            string s = animal.F();
            animal.P();

            //3. 끝에 도달하면 확인
            if (x == N - 1 && y == N - 1) {
                pr("%s?????????????\n", tc(s)); //DEBUG

                //지금까지 지나온 동물리스트(국경 내의)를 확인
                int animalCnt = 0; //국경내의 동물종 갯수
                rep(i, len(s)) {
                    int number = s[i] - '0';
                    num[number] = true; //1~26중 해당 하는것에 체크
                }

                rrep(i, 1, 27) //체크된 동물 종수 계산
                    if (num[i])
                        animalCnt++; 

                pr(">> %d\n", animalCnt); //DEBUG
                if (animalCnt >= 2) //국경내에 2종이상 이 공존하면 안된다.
                    rt false;
            }

            rep(dir, 4) {
                //다음위치 xx, yy
                int xx = x + dxy[dir][0];
                int yy = y + dxy[dir][1];
                //1. 올바른 인덱스인가
                if (xx < 0 || yy < 0 || xx == N || yy == N) ct;
                string ss = s + ts(map[xx][yy]);
                printf("%s##############\n", tc(ss));

                //3. 현재위치 x,y에서 dir방향으로 이동이 불가능하면 제외
                if (!move[x][y][dir]) ct;

                //2. 방문했었으면 제외
                if (visited[xx][yy]) ct;

                visited[xx][yy] = true;
                loc.ph(mp(xx, yy));
                animal.ph(ss);
            }
        }
    }
    //모든 동물위치에서 BFS진행결과
    //한 국경내에 2종이상의 동물이 존재하지 않으면 true 리턴
    rt true;
}

//DFS방법으로 flag의 0,0에서 N+1,N+1까지 탐색
void func() {
    bool visited[MAX][MAX] = {false}; //DFS에 쓰일 방문체크배열
    sii loc;
    ss flagStr;
    loc.ph(mp(0, 0));
    visited[0][0] = true;
    flagStr.ph("00");

    while (!loc.empty()) {
        int x, y;
        tie(x, y) = loc.T();
        loc.P();
        string s = flagStr.T();
        flagStr.P();

        //국경선을 완성했고, 올바르다면 출력후 종료
        if (x == N && y == N && isRight(s)) {
            print(s);
            rt;
        }

        rep(dir, 4) {
            int xx = x + dxy[dir][0];
            int yy = y + dxy[dir][1];

            //1. 인덱스 확인
            if (xx < 0 || yy < 0 || xx == N + 1 || yy == N + 1) ct;

            //2. 방문했었으면 제외
            if (visited[xx][yy]) ct;
            visited[xx][yy] = true;
            string ss = s + ts(xx) + ts(yy);
            loc.ph(mp( xx, yy ));
            flagStr.ph(ss);
        }
    }
    //국경선을 만들지 못했다면 no 출력
    pr("no"); 
}



int main(void) {
    init();
    func();

    rt 0;
}