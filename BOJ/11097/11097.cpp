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
#define sz(x) ((int)x.size()) //�����̳ʿ��� ���
#define ms(a) memset(a, 0, sizeof(a)) //0���� �ʱ�ȭ
#define rep(i, n) for(int i = 0; i < n ; i++)
#define rrep(i, r, n) for(int i = r; i < n ; i++)
#define rrrep(i, r, n) for(ll i = r; i < n ; i++)
#define _rrep(i, r, n) for(int i = r; i >= n; i--)
#define _rrrep(i, r, n) for(ll i = r; i >= n; i--)
#define each(x, a) for (auto& x: a)
#define all(x) x.begin(),x.end() //STL���� ��ü ó���Ҷ� ���
#define range(x, r, n) x.begin() + r, x.begin() + n //STL���� ��������
#define ct continue
#define br break
#define rt return
#define _TYF typedef //�ڵ����̱�
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
_TCE T sq(T num) { rt num* num; }//�����Լ�
_TCE T GCD(T num1, T num2) { if (num2 == 0) rt num1; rt GCD(num2, num1 % num2); }
_TCE T LCM(T num1, T num2) { if (num1 == 0 || num2 == 0) rt num1 + num2; rt num1* (num2 / GCD(num1, num2)); }
//STL ���� �ʱ�ȭ �Լ��� ( ms~~ )
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
//edge[x][y] : x -> y �� �̵����� (�ܹ��⿬�� ������)
//SCCedge[x][y] x��SCC -> y��SCC �� �̵����� (�ܹ��⿬�� ������)
bool edge[MAX][MAX], SCCedge[MAX][MAX]; 
int SCCNum[MAX];
vi SCC[MAX];
vii res;
void init();
void func();

void init() {
	sc("%d", &T);
}

//���α׷� ���� ����
void func() {
	while (T--) {
		sc("%d", &N);
		rrep(i, 1, N + 1) 
			rrep(j, 1, N + 1) 
				sc("%1d", &edge[i][j]);

		//��� �������� �ܹ��� ���������� �־�����
		//������ DFS������� SCC�� �� ���� ���� �� ����
		//�Ʒ��� 1���������ε� ����� SCC�� ���� �� �־��.

		//1. �������� ���ϴ� SCC�� ����
		//SCCNum[x] : ����x�� ���� SCC��ȣ
		//SCCNum[y] : ������ ���� SCC��ȣ
		rrep(x, 1, N + 1) {
			if (SCCNum[x] == 0) { //����x�� ��� SCC���� ������ �ʴ´ٸ�
				SCCNum[x] = SCCcnt++; //����x�� SCC��ȣ�� ������ ����
				SCC[SCCNum[x]].pb(x); //����x�� ���ο�SCC�� �ʱ� ���������� ����
			}
			rrep(y, 1, N + 1) {
				//�� ����x, y�� ���ο��� ���� �����ϸ� �ϳ��� ����Ŭ�̸� �ϳ��� SCC�̴�.
				//����y�� ���� ��� ������ ������ �ʾ����� ����y�� ����x�� ���� SCC�׷��� ���������� �߰��մϴ�.
				if (x != y && !SCCNum[y] && edge[x][y] && edge[y][x]) {
					SCCNum[y] = SCCNum[x]; //����y�� SCC��ȣ�� ������ ����
					SCC[SCCNum[y]].pb(y);  //SCC��ȣ�� ����y�� ���������� ����
				}
			}
		}

		//2. ���� �ٸ� SCC�� ���� ����
		rrep(x, 1, N + 1)
			rrep(y, 1, N + 1) {
				int numX = SCCNum[x]; //����x�� ���� SCC��ȣ
				int numY = SCCNum[y]; //����y�� ���� SCC��ȣ
				//����x ���� y�� �����ְ� �� ������ ���δٸ� SCC�� ���ϸ�
				//����x������ SCC���� ���� y�� ���� SCC�� �̵��������� ����
				if (edge[x][y] && numX != numY)
					SCCedge[numX][numY] = true;
			}

		//3. SCC�� ����� ������ �ߺ��� ����
		//x��SCC -> y��SCC�ΰ��� ��δ�
		//x��SCC -> k��SCC -> y��SCC �� �� �� �ִٸ�
		//�ּ� ��θ� ���� �����ؾ��ϴ°�.
		//���� �����ϸ� SCCedge[numX][numY]�� �Ұ������� �ٲپ��־����
		rrep(numK, 1, SCCcnt + 1) 
			rrep(numX, 1, SCCcnt + 1) 
				rrep(numY, 1, SCCcnt + 1)
					if (SCCedge[numX][numY] && SCCedge[numX][numK] && SCCedge[numK][numY])
						SCCedge[numX][numY] = false;

		//4. SCC���� ���� ����
		//������ ��������� ��SCC�� ���� ù��° ���ҳ��� ������ ����
		rrep(i, 1, SCCcnt) {
			rrep(j, 1, SCCcnt) {
				if (SCCedge[i][j]) {
					res.pb(mp(SCC[i][0], SCC[j][0])); //�� SCC�� �����ϴ� ù��° ������ ���� ������ ����
					resCnt++;
				}
			}
		}

		//5. ��SCC ���� ������ ���� ����
		rrep(k, 1, SCCcnt) {
			if (sz(SCC[k]) >= 2) {
				rrep(i, 1, sz(SCC[k])) {
					int x = SCC[k][i - 1]; //SCC�� ������ ����x
					int y = SCC[k][i]; //SCC�� ������ ����y
					res.pb(mp(x, y)); //�� ���� x, y�� �����(x -> y)�� ����
					resCnt++;
				}
				//SCC�� ������������ SCC�� ó�� ������ �������־�� ����Ŭ�� �ϼ�
				res.pb(mp(SCC[k][sz(SCC[k]) - 1], SCC[k][0])); 
				resCnt++;
			}
		}

		//4. ��� ���
		pr("%d\n", resCnt);
		rep(k, resCnt)
			pr("%d %d\n", res[k].first, res[k].second);

		//�ʱ�ȭ
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