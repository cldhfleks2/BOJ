
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

//////////////�Է�, DFS���� ���� ���/////////////////////
int N, M; //��������, ��������
vi road[MAX]; //�����ΰ��� ����� �ٸ� �����θ� ��� (�ܹ��� ����)
int money[MAX]; //����(������)�� ATM�Ⱑ ���� ����
int S, P; //�����ġ ������ȣ, ������� �Ѱ��� P
int idx, p[MAX]; //�������Ű��� ��ȣ, �������� �ڽ��� �θ� �����ϴ� �迭
si s; //DFS���� SCC���꿡 ���� ����
////////////////////////////////////////////////////////////
/////////////SCC�׷츶�ٿ� ���� ���//////////////////////
int SCCcnt = 1; //SCC�׷쿡 �Ű��� ��ȣ. 1���� �����Ѵ�.
bool restaurant[MAX]; //����(������)�� ��������� �ִ°� <= �Է¹޴� ��
int group[MAX]; //����(������)�� ��� SCC�׷쿡 ���ϴ°� SCCcnt������.
int SCCmoney[MAX]; //SCC�׷츶�� ���� �������� ���� ��������
bool SCChasRestaurant[MAX]; //SCC�׷��� ��������� �����ϰ��ִ°�
int SCCstartNum; //SCC�׷��� �����հ踦 ������ ��ȣ
vector<int> SCCedge[MAX];  //SCC���� �����. �������� �̵������� ����SCC��ȣ�� ���� <= BFS���� ���
int SCCmoneySumMAX[MAX]; //�ش��ϴ� SCC�׷쵵������ ĥ�� ���Ŀ� ����ε鰣�� �������� �� �ִ��� ���� <= BFS�� �����س�����
int res; //����� �� (�ִ�)
////////////////////////////////////////////////////////////
void init();
int DFS(int x);
void bfs();
void func();

void init() {
	sc("%d%d", &N, &M);
	rep(_, M) { //���� ��Ȳ 
		int s, e;
		sc("%d%d", &s, &e);
		road[s].pb(e);
	}
	rrep(i, 1, N+1) { //�� �������� ATM�� ������ �ݾ�
		int m;
		sc("%d", &m);
		money[i] = m;
	}
	sc("%d%d", &S, &P); //������ġ, ������� �Ѱ��� 
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
		if (p[y] == 0) //���� Ž������ ���� ������ ������
			parent = min(parent, DFS(y));
		else if (!group[y]) //Ž���� ������ SCC�׷쿡 ������ ���� ������������(����Ŭ������)
			parent = min(parent, p[y]);
	}

	if (parent == p[x]) {
		while (x) {
			int y = s.TT();
			s.PP();
			group[y] = SCCcnt; //���� ���������� SCC�׷��ȣ�� �ű��. (1���� �Ű���)
			SCCmoney[SCCcnt] += money[y]; //SCC�׷쳻�� ���� ���� ����
			if (restaurant[y]) //���� ������ ��������� �����ϸ�
				SCChasRestaurant[SCCcnt] = true;  //���ϴ� SCC�׷쿡 ��������� �����Ѵٰ� ǥ����
			if (S == y) //���� ������ ���������̸�
				SCCstartNum = SCCcnt; //���ϴ� SCC�׷����κ��� BFSŽ���� ��������� ~

			if (y == x) br;
		}
		SCCcnt++;
	}

	rt parent;
}


void bfs() {
	qi q;
	q.ph(SCCstartNum); //SCCstartNum : DFS�������� ������ SCC�׷��ȣ
	SCCmoneySumMAX[SCCstartNum] = SCCmoney[SCCstartNum]; //�ش��ϴ� SCC�׷���
	while (!q.emp()) {
		int sccCurNum = q.FF();
		q.PP();
		//���� SCC��ȣ�� ��������� �����ϸ� �ִ���������
		if (SCChasRestaurant[sccCurNum])
			res = max(res, SCCmoneySumMAX[sccCurNum]);
		//���� SCC�׷쿡 ���ϴ� ������(�� ������)�� ���� ���������Ͽ�
		//���� ������ sccNextNum�� ���ϴ� �ٸ� SCC�׷��� ���������� �ִ����� ���ŵ� �� �ִ��� Ȯ��
		//������ sccCurNum�� ���ϴ� SCC�׷�� sccNextNum�� ���ϴ� SCC�׷��� �ٸ���.!!! <= func()���������߱⶧��
		//SCCmoneySumMAX : SCC�׷쳻�� ��������
		rep(i, sz(SCCedge[sccCurNum])) {
			int sccNextNum = SCCedge[sccCurNum][i];
			//�ִ��� ���ŵɶ��� SCCmoneySumMAX�� ����
			if (SCCmoneySumMAX[sccNextNum] < SCCmoneySumMAX[sccCurNum] + SCCmoney[sccNextNum]) {
				SCCmoneySumMAX[sccNextNum] = SCCmoneySumMAX[sccCurNum] + SCCmoney[sccNextNum];
				//�����Ѵٸ� �ִ��� �����ѷ�Ʈ�̹Ƿ� ������ Ž���� ��ҷ� �����Ͽ� ť�� �ֽ��ϴ�.
				q.ph(sccNextNum);
			}
		}
	}
}


//���α׷� ���� ����
void func() {
	//DFS�� �̿��� SCC�� ����� �˰���
	rrep(i, 1, N + 1) 
		if (p[i] == 0) DFS(i); 

	//���δٸ� SCC���� �ܹ���׷���(����Ŭ�̾���)�� SCCedge�� ���� ����
	rrep(x, 1, N + 1) {
		rep(i, sz(road[x])) {
			int y = road[x][i];
			//���� ����� ������ x, y�� x - > y �϶�
			//�� ������ ���δٸ� SCC�� ���Ѱ��
			//x�����ϴ� SCC�׷��� y�����ϴ� SCC�׷������� ������ ������ �����Ѵ�.
			if (group[x] != group[y]) 
				SCCedge[group[x]].pb(group[y]);
		}
	}

	//����� SCCedge�� �̿��� BFS�� �����Ѵ�.
	bfs();
	pr("%d", res);
}

int main(void) {
	init();
	func();

	rt 0;
}