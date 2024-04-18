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
#define emp() empty()
#define len(x) x.length()
#define sz(x) ((int)x.size()) //컨테이너에서 사용
#define ms(a) memset(a, 0, sizeof(a)) //0으로 초기화
#define rep(i, n) for(int i = 0; i < n ; i++)
#define rrep(i, r, n) for(int i = r; i < n ; i++)
#define rrrep(i, r, n) for(ll i = r; i < n ; i++)
#define _rrep(i, r, n) for(int i = r; i >= n; i--)
#define _rrrep(i, r, n) for(ll i = r; i >= n; i--)
#define each(x, a) for (auto& x: a)
#define all(x) x.begin(),x.end() //STL에서 전체 처리할때 사용
#define range(x, r, n) x.begin() + r, x.begin() + n //STL에서 구간설정
#define ct continue
#define br break
#define rt return
#define _TYF typedef //코드줄이기
#define _UG using
#define _TCE template <class T> inline
//#define MAX 
const int IMAX = INT32_MAX; const int IMIN = INT32_MIN;
const long long LMAX = LLONG_MAX; const long long LMIN = LLONG_MIN;
const long double PI = 3.141592653589793238462643383279502884197;
_UG std::vector; _UG std::stack; _UG std::queue; _UG std::tuple; _UG std::set; _UG std::list; _UG std::bitset; _UG std::string; _UG std::pair; _UG std::greater;
_UG std::tie; _UG std::sort; _UG std::max_element; _UG std::min_element; _UG std::fill; _UG std::stoi; _UG std::stod; _UG std::stof; _UG std::stol; _UG std::stold; _UG std::stoll; _UG std::stoul; _UG std::stoull; _UG std::to_string;
//_UG std::max; //_UG std::min; //_UG std::map;
_TYF long long ll;// _TYF unsigned long long ull; // 입출력오류날때가있음.
_TYF pair<int, int> pii; _TYF pair<double, int> pdi; _TYF pair<int, double> pid; _TYF pair<double, double> pdd; _TYF pair<int, ll> pil;
_TYF pair<ll, int> pli; _TYF pair<ll, ll> pll; _TYF pair<int, char> pic; _TYF pair<char, int> pci;
_TYF pair<char, char> pcc; _TYF pair<long, char> plc; _TYF pair<char, long> pcl; _TYF pair<ll, char> pllc; _TYF pair<char, ll> pcll;
_TYF pair<int, string> pis; _TYF pair<string, int> psi; _TYF pair<long, string> pls;
_TYF pair<string, long> psl; _TYF pair<ll, string> plls; _TYF pair<string, ll> psll;
_TYF pair<string, string> pss;
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
_TCE T sq(T num) { rt num* num; }//제곱함수
_TCE T GCD(T num1, T num2) { if (num2 == 0) rt num1; rt GCD(num2, num1 % num2); }
_TCE T LCM(T num1, T num2) { if (num1 == 0 || num2 == 0) rt num1 + num2; rt num1* (num2 / GCD(num1, num2)); }
//STL 전용 초기화 함수들 ( ms~~ )
_TCE void msq(T& a) { while (!a.empty()) a.PP(); }//queue clear
_TCE void msv(T& a) { a.cls(); }//vector clear
_TCE void msdq(T& a) { a.cls(); }//deque clear
_TCE void msm(T& a) { a.cls(); }//map clear
_TCE void mss(T& a) { while (!a.empty()) a.PP(); }//stack, set clear
_TCE void mspq(T& a) { while (!a.empty()) a.PP(); }//priority_queue clear
//pii operator - (pii a, pii b) { rt pii(a.first - b.first, a.second - b.second); }
//bool operator <= (pii a, pii b) { rt a.first <= b.first && a.second <= b.second; } 
//bool operator >= (pii a, pii b) { rt a.first >= b.first && a.second >= b.second; } 
//bool operator < (pii a, pii b) { if (a == b) return false; rt a <= b; } 
//bool operator > (pii a, pii b) { if (a == b) return false; rt a >= b; }

int N, M;
int map[1000][1000];
bool moveLocCheck[1000][1000];
vi moveLocArea({ 0 }); //각각 -1, -2, -3영역의 크기. 갯수
int areaNum = -1;
bool visited[1000][1000];
int dxy[][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
void init() {
	sc("%d%d", &N, &M);
	rep(i, N)
		rep(j, M) {
		sc("%1d", &map[i][j]);
		if (map[i][j] == 0) moveLocCheck[i][j] = true;
	}
}

//빈공간중 하나를 입력받아
//그 빈공간과 연결된 다른 빈공간들을 하나의 areaNum으로 묶고,
//연결된 공간의 크기를 moveLocArea에 저장하는 함수
void findMoveLocArea(int X, int Y) {
	qii q;
	q.ph(mp(X, Y));
	moveLocCheck[X][Y] = false;
	map[X][Y] = areaNum;
	int moveCnt = 1;

	while (!q.emp()) {
		int x, y;
		tie(x, y) = q.FF();
		q.PP();

		rep(dir, 4) {
			int xx = x + dxy[dir][0];
			int yy = y + dxy[dir][1];
			if (xx < 0 || yy < 0 || xx == N || yy == M //구간을 벗어나거나
				|| !moveLocCheck[xx][yy]) ct; //탐색했으면 제외

			q.ph(mp(xx, yy));
			moveLocCheck[xx][yy] = false; //탐색체크
			map[xx][yy] = areaNum;
			moveCnt++;
		}
	}

	moveLocArea.pb(moveCnt); //현재영역의 크기를 기록
	areaNum--;
}

//한번 BFS를 돌려서
//모든 벽에서 주변 4방향의 빈공간무리값(moveLocArea)을 더하는 함수
//결과로 벽이있는 위치의 map[x][y]값이 갱신될것이다.
void bfs() {
	qii q;
	rep(i, N) rep(j, M) visited[i][j] = false;

	q.ph(mp(0, 0));
	visited[0][0] = true;
	while (!q.emp()) {
		int x, y;
		tie(x, y) = q.FF();
		q.PP();

		int aroundSum = 0;
		std::set<int> moveLocAreaNum;
		rep(dir, 4) {
			int xx = x + dxy[dir][0];
			int yy = y + dxy[dir][1];
			if (xx < 0 || yy < 0 || xx == N || yy == M) ct;

			if (map[x][y] > 0 //현재벽위치고
				&& map[xx][yy] < 0 //다음위치가 빈공간(음수로체크했었음)이며
				&& !moveLocAreaNum.count(map[xx][yy])) { //이미 확인한 빈공간이아니라면
				moveLocAreaNum.ins(map[xx][yy]); //확인한 공간임을 체크
				aroundSum += moveLocArea[-map[xx][yy]]; //벽주변 영역크기를 더함
			}

			if (visited[xx][yy]) ct;
			visited[xx][yy] = true;

			q.push(mp(xx, yy));
		}
		map[x][y] += aroundSum; //현재가벽이면 주변영역크기를 더함(벽이아니었으면 값은 0)
	}
}

//프로그램 메인 로직
void func() {
	rep(X, N)
		rep(Y, M)
		if (moveLocCheck[X][Y]) //체크된 빈공간을 찾아서
			findMoveLocArea(X, Y); //moveLocArea에 크기를 저장한뒤 체크해제하는 bfs함수

	bfs();

	rep(i, N) {
		rep(j, M) {
			map[i][j] > 0 ? //빈공간일경우 -1, -2, -3...등으로 빈공간무리를 표시함
				pr("%d", map[i][j] % 10) : pr("0"); //따라서 양수면 벽이있던위치임.
		}
		pr("\n");
	}
}

int main(void) {
	init();
	func();

	rt 0;
}