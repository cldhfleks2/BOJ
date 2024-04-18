
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
#define MAX 100001
const int IMAX = INT32_MAX; const int IMIN = INT32_MIN;
const long long LMAX = LLONG_MAX; const long long LMIN = LLONG_MIN;
const long double PI = 3.141592653589793238462643383279502884197;
_UG std::vector; _UG std::stack; _UG std::queue; _UG std::tuple; _UG std::set; _UG std::list; _UG std::bitset; _UG std::string; _UG std::pair; _UG std::greater;
_UG std::tie; _UG std::sort; _UG std::max_element; _UG std::min_element; _UG std::fill; _UG std::stoi; _UG std::stod; _UG std::stof; _UG std::stol; _UG std::stold; _UG std::stoll; _UG std::stoul; _UG std::stoull;
_UG std::min; //_UG std::map;
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

int T;
int N, M, id;
int P[MAX];
bool visited[MAX];
vi arr[MAX];
si S;
vector<vi> scc;
int group[MAX]; //각각정점이 몇번 SCC에 속하는지 체킹
bool inDegree[MAX]; //각각SCC의 번호마다 다른 SCC에서의 접근이 가능한지 체킹(기본값 false)

void init();
int SCC(int x, int& id, int(&P)[MAX], bool(&visited)[MAX], vi(&arr)[MAX], si& S);
void func();

void init() {
	sc("%d", &T);
}

int SCC(int x, int &id, int (&P)[MAX], bool (&visited)[MAX], 
	vi (&arr)[MAX], si &S) {
	P[x] = ++id;
	S.ph(x);

	int parent = P[x];
	rep(i, sz(arr[x])) {
		int y = arr[x][i];
		if (P[y] == 0)
			parent = min(parent, SCC(y, id, P, visited, arr, S)); //사실상 P[y]를 구하기윟 SCC(y) 호출
		else if (!visited[y])
			parent = min(parent, P[y]); //이미 구해진값P[y] 사용
	}

	if (parent == P[x]) {
		vi list;
		while (x) {
			int y = S.TT();
			S.PP();
			group[y] = sz(scc) + 1; //각 정점이 몇번 SCC에 속해있는지 숫자를매김
			visited[y] = true;
			list.pb(y);
			if (y == x) br;
		}
		scc.pb(list);
	}

	return parent;
}

//프로그램 메인 로직
void func() {
	rep(_, T) {
		sc("%d%d", &N, &M);

		//각 요소들 초기화
		id = 0;
		ms(P);
		ms(visited);
		ms(group);
		ms(inDegree);
		msv(scc); 
		rep(i, N + 1)
			arr[i].cls();

		//연결정보를 입력받음
		rep(__, M) {
			int x, y;
			sc("%d%d", &x, &y);
			arr[x].pb(y); //x->y 연결
		}

		//방문하지 않은 정점을 모두 DFS적용하여 총 SCC그룹갯수인 res를 구함
		rrep(i, 1, N + 1) 
			if (P[i] == 0) SCC(i, id, P, visited, arr, S);

		//그래프의 모든 정점마다 연결된 모든 정점을 탐색하여
		//연결된 두 정점 u -> v가 서로 다른 SCC에 존재하면
		//v번 SCC가 inDegree가 있는 SCC인것이다.
		//따라서 inDegree[v] 를 체크해주자.
		rrep(i, 1, N + 1) {
			rep(j, sz(arr[i])) {
				int y = arr[i][j];
				if (group[i] != group[y])
					//다른 SCC에서 현재 정점이 속한 SCC로 접근이 가능하다. 
					// -> 도미노가 연달아 쓰러짐
					inDegree[group[y]] = true; 
			}
		}

		int res = 0;
		rrep(i, 1, sz(scc) + 1)
			if (!inDegree[i])
				res++; //고립된 SCC만 체크

		pr("%d\n", res);
	}


}

int main(void) {
	init();
	func();

	rt 0;
}