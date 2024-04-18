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
#define MAX 301
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

int T, N, SCCcnt=1, resCnt;
//edge[x][y] : x -> y 로 이동가능 (단방향연결 되있음)
//SCCedge[x][y] x번SCC -> y번SCC 로 이동가능 (단방향연결 되있음)
bool edge[MAX][MAX], SCCedge[MAX][MAX]; 
int SCCNum[MAX];
vi SCC[MAX];
vii res;
void init();
void func();

void init() {
	sc("%d", &T);
}

//프로그램 메인 로직
void func() {
	while (T--) {
		sc("%d", &N);
		rrep(i, 1, N + 1) 
			rrep(j, 1, N + 1) 
				sc("%1d", &edge[i][j]);

		//모든 정점간의 단방향 연결정보가 주어지면
		//기존에 DFS방법말고도 SCC를 더 쉽게 만들 수 있음
		//아래의 1번과정으로도 충분히 SCC를 구할 수 있어요.

		//1. 각정점이 속하는 SCC를 구함
		//SCCNum[x] : 정점x가 속한 SCC번호
		//SCCNum[y] : 정점가 속한 SCC번호
		rrep(x, 1, N + 1) {
			if (SCCNum[x] == 0) { //정점x가 어느 SCC에도 속하지 않는다면
				SCCNum[x] = SCCcnt++; //정점x의 SCC번호를 새로이 지정
				SCC[SCCNum[x]].pb(x); //정점x를 새로운SCC의 초기 구성원으로 넣음
			}
			rrep(y, 1, N + 1) {
				//두 정점x, y가 서로에게 도달 가능하면 하나의 사이클이며 하나의 SCC이다.
				//정점y가 아직 어느 정점에 속하지 않았을때 정점y를 정점x가 속한 SCC그룹의 구성원으로 추가합니다.
				if (x != y && !SCCNum[y] && edge[x][y] && edge[y][x]) {
					SCCNum[y] = SCCNum[x]; //정점y의 SCC번호를 새로이 지정
					SCC[SCCNum[y]].pb(y);  //SCC번호에 정점y를 구성원으로 편입
				}
			}
		}

		//2. 서로 다른 SCC간 간선 연결
		rrep(x, 1, N + 1)
			rrep(y, 1, N + 1) {
				int numX = SCCNum[x]; //정점x가 속한 SCC번호
				int numY = SCCNum[y]; //정점y가 속한 SCC번호
				//정점x 에서 y로 갈수있고 두 정점이 서로다른 SCC에 속하면
				//정점x가속한 SCC에서 정점 y가 속한 SCC로 이동가능함을 저장
				if (edge[x][y] && numX != numY)
					SCCedge[numX][numY] = true;
			}

		//3. SCC간 연결된 간선중 중복을 제거
		//x번SCC -> y번SCC로가는 경로는
		//x번SCC -> k번SCC -> y번SCC 로 갈 수 있다면
		//최소 경로를 위해 제거해야하는것.
		//따라서 가능하면 SCCedge[numX][numY]를 불가능으로 바꾸어주어야함
		rrep(numK, 1, SCCcnt + 1) 
			rrep(numX, 1, SCCcnt + 1) 
				rrep(numY, 1, SCCcnt + 1)
					if (SCCedge[numX][numY] && SCCedge[numX][numK] && SCCedge[numK][numY])
						SCCedge[numX][numY] = false;

		//4. SCC간의 연결 저장
		//순서는 상관없으니 두SCC의 가장 첫번째 원소끼리 연결을 저장
		rrep(i, 1, SCCcnt) {
			rrep(j, 1, SCCcnt) {
				if (SCCedge[i][j]) {
					res.pb(mp(SCC[i][0], SCC[j][0])); //두 SCC를 구성하는 첫번째 정점을 끼리 연결을 저장
					resCnt++;
				}
			}
		}

		//5. 각SCC 내부 정점간 연결 저장
		rrep(k, 1, SCCcnt) {
			if (sz(SCC[k]) >= 2) {
				rrep(i, 1, sz(SCC[k])) {
					int x = SCC[k][i - 1]; //SCC의 구성원 정점x
					int y = SCC[k][i]; //SCC의 구성원 정점y
					res.pb(mp(x, y)); //두 정점 x, y가 연결됨(x -> y)을 저장
					resCnt++;
				}
				//SCC의 마지막정점과 SCC의 처음 정점을 연결해주어야 사이클이 완성
				res.pb(mp(SCC[k][sz(SCC[k]) - 1], SCC[k][0])); 
				resCnt++;
			}
		}

		//4. 결과 출력
		pr("%d\n", resCnt);
		rep(k, resCnt)
			pr("%d %d\n", res[k].first, res[k].second);

		//초기화
		resCnt = 0;
		SCCcnt = 1;
		res.cls();
		rrep(i, 1, N + 1) {
			SCC[i].cls();
			SCCNum[i] = 0;
			rrep(j, 1, N + 1) {
				edge[i][j] = false;
				SCCedge[i][j] = false;
			}
		}
	}
}

int main(void) {
	init();
	func();

	rt 0;
}