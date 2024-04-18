
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
#define MAX 500001 
const int IMAX = INT32_MAX; const int IMIN = INT32_MIN;
const long long LMAX = LLONG_MAX; const long long LMIN = LLONG_MIN;
const long double PI = 3.141592653589793238462643383279502884197;
_UG std::vector; _UG std::stack; _UG std::queue; _UG std::tuple; _UG std::set; _UG std::list; _UG std::bitset; _UG std::string; _UG std::pair; _UG std::greater;
_UG std::tie; _UG std::sort; _UG std::max_element; _UG std::min_element; _UG std::fill; _UG std::stoi; _UG std::stod; _UG std::stof; _UG std::stol; _UG std::stold; _UG std::stoll; _UG std::stoul; _UG std::stoull;
_UG std::min; _UG std::max;
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

//////////////입력, DFS에서 사용될 요소/////////////////////
int N, M; //정점갯수, 간선갯수
vi road[MAX]; //교차로간의 연결된 다른 교차로를 기록 (단방향 간선)
int money[MAX]; //정점(교차로)의 ATM기가 갖는 현금
int S, P; //출발위치 정점번호, 레스토랑 총갯수 P
int idx, p[MAX]; //정점에매겨질 번호, 정점마다 자신의 부모를 저장하는 배열
si s; //DFS에서 SCC만듦에 사용될 스택
////////////////////////////////////////////////////////////
/////////////SCC그룹마다에 사용될 요소//////////////////////
int SCCcnt = 1; //SCC그룹에 매겨질 번호. 1부터 시작한다.
bool restaurant[MAX]; //정점(교차로)에 레스토랑이 있는가 <= 입력받는 값
int group[MAX]; //정점(교차로)이 어느 SCC그룹에 속하는가 SCCcnt값으로.
int SCCmoney[MAX]; //SCC그룹마다 내부 정점들이 가진 현금총합
bool SCChasRestaurant[MAX]; //SCC그룹이 레스토랑을 포함하고있는가
int SCCstartNum; //SCC그룹중 현금합계를 시작할 번호
vector<int> SCCedge[MAX];  //SCC에서 연결된. 다음으로 이동가능한 다음SCC번호를 저장 <= BFS에서 사용
int SCCmoneySumMAX[MAX]; //해당하는 SCC그룹도착지라 칠때 거쳐온 모든경로들간의 현금총합 중 최댓값을 저장 <= BFS로 갱신해나갈것
int res; //출력할 값 (최댓값)
////////////////////////////////////////////////////////////
void init();
int DFS(int x);
void bfs();
void func();

void init() {
	sc("%d%d", &N, &M);
	rep(_, M) { //도로 상황 
		int s, e;
		sc("%d%d", &s, &e);
		road[s].pb(e);
	}
	rrep(i, 1, N+1) { //각 교차로의 ATM이 가지는 금액
		int m;
		sc("%d", &m);
		money[i] = m;
	}
	sc("%d%d", &S, &P); //시작위치, 레스토랑 총갯수 
	rep(_, P) {
		int r;
		sc("%d", &r);
		restaurant[r] = true;
	}
}

int DFS(int x) {
	p[x] = ++idx;
	s.ph(x);

	int parent = p[x];
	rep(i, sz(road[x])) {
		int y = road[x][i];
		if (p[y] == 0) //아직 탐색하지 않은 정점이 있으면
			parent = min(parent, DFS(y));
		else if (!group[y]) //탐색은 했으나 SCC그룹에 속하지 않은 정점이있으면(사이클도는중)
			parent = min(parent, p[y]);
	}

	if (parent == p[x]) {
		while (x) {
			int y = s.TT();
			s.PP();
			group[y] = SCCcnt; //현재 정점에대해 SCC그룹번호를 매긴다. (1부터 매겨짐)
			SCCmoney[SCCcnt] += money[y]; //SCC그룹내의 현금 총합 갱신
			if (restaurant[y]) //현재 정점에 레스토랑이 존재하면
				SCChasRestaurant[SCCcnt] = true;  //속하는 SCC그룹에 레스토랑이 존재한다고 표기함
			if (S == y) //현재 정점이 시작정점이면
				SCCstartNum = SCCcnt; //속하는 SCC그룹으로부터 BFS탐색을 시작해줘용 ~

			if (y == x) br;
		}
		SCCcnt++;
	}

	rt parent;
}


void bfs() {
	qi q;
	q.ph(SCCstartNum); //SCCstartNum : DFS에서구한 시작할 SCC그룹번호
	SCCmoneySumMAX[SCCstartNum] = SCCmoney[SCCstartNum]; //해당하는 SCC그룹이
	while (!q.emp()) {
		int sccCurNum = q.FF();
		q.PP();
		//현재 SCC번호에 레스토랑이 존재하면 최댓값을갱신함
		if (SCChasRestaurant[sccCurNum])
			res = max(res, SCCmoneySumMAX[sccCurNum]);
		//현재 SCC그룹에 속하는 구성원(각 정점들)을 다음 정점으로하여
		//다음 정점인 sccNextNum이 속하는 다른 SCC그룹의 현금총합이 최댓값으로 갱신될 수 있는지 확인
		//무조건 sccCurNum이 속하는 SCC그룹과 sccNextNum이 속하는 SCC그룹은 다르다.!!! <= func()에서정의했기때문
		//SCCmoneySumMAX : SCC그룹내의 현금총합
		rep(i, sz(SCCedge[sccCurNum])) {
			int sccNextNum = SCCedge[sccCurNum][i];
			//최댓값이 갱신될때만 SCCmoneySumMAX를 갱신
			if (SCCmoneySumMAX[sccNextNum] < SCCmoneySumMAX[sccCurNum] + SCCmoney[sccNextNum]) {
				SCCmoneySumMAX[sccNextNum] = SCCmoneySumMAX[sccCurNum] + SCCmoney[sccNextNum];
				//갱신한다면 최댓값이 가능한루트이므로 다음에 탐색할 요소로 간주하여 큐에 넣습니다.
				q.ph(sccNextNum);
			}
		}
	}
}


//프로그램 메인 로직
void func() {
	//DFS를 이용해 SCC를 만드는 알고리즘
	rrep(i, 1, N + 1) 
		if (p[i] == 0) DFS(i); 

	//서로다른 SCC간에 단방향그래프(사이클이없는)를 SCCedge을 통해 구현
	rrep(x, 1, N + 1) {
		rep(i, sz(road[x])) {
			int y = road[x][i];
			//서로 연결된 두정점 x, y가 x - > y 일때
			//두 정점이 서로다른 SCC에 속한경우
			//x가속하는 SCC그룹이 y가속하는 SCC그룹으로의 연결을 가짐을 저장한다.
			if (group[x] != group[y]) 
				SCCedge[group[x]].pb(group[y]);
		}
	}

	//저장된 SCCedge을 이용해 BFS를 진행한다.
	bfs();
	pr("%d", res);
}

int main(void) {
	init();
	func();

	rt 0;
}