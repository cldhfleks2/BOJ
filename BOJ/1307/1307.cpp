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

int N, map[MAX][MAX];
void init();
void func();
void printAll();
void odd(int(&MAP)[MAX][MAX], int n);
void even(int(&MAP)[MAX][MAX]);
void DEBUG();

void init() {
	sc("%d", &N);
}

void odd(int (&MAP)[MAX][MAX], int n) {
	int x, y; //���� ���� ��ġ
	rrep(i, 1, n * n + 1) {
		if (i == 1) { //1. ���簢�� �� �Ʒ��� ����� ����1 ���
			MAP[n - 1][n / 2] = 1;
			x = n - 1;
			y = n / 2;
			ct;
		}

		//�������� ������ �Ʒ�ĭ�� �ʹ��ΰ�?
		if (x + 1 >= n || y + 1 >= n) { //2. �� ���϶�
			//2-1. ����(��)���� �̵��Ͽ� ��ϵ��� ���� ��ĭ�� ���� ���ڸ� ���
			if (x + 1 < n) {
				rep(j, n) {
					if (MAP[x + 1][j] == 0) {
						MAP[x + 1][j] = i;
						x = x + 1;
						y = j;
						br;
					}
				}
			}
			else if (y + 1 < n) { //2-2. ����(��)���� �̵��Ͽ� ��ϵ��� ���� ��ĭ�� ���ڸ� ���
				rep(j, n) {
					if (MAP[j][y + 1] == 0) {
						MAP[j][y + 1] = i;
						x = j;
						y = y + 1;
						br;
					}
				}
			}
			else { //2-3. ����, �������� �̵��Ұ����ϸ� ���������� ��ĭ�� �������ڸ� ���
				MAP[x - 1][y] = i;
				x = x - 1;
				y = y;
			}

		}
		else { //�� ���϶�
			if (MAP[x + 1][y + 1] == 0) { //3. ������ �Ʒ�ĭ�� ��������� �������ڸ� ���
				MAP[x + 1][y + 1] = i;
				x = x + 1;
				y = y + 1;
			}
			else { //4. ������ �Ʒ�ĭ�� ä�����ִ� ��� ���������� ��ĭ�� �������ڸ� ���
				MAP[x - 1][y] = i;
				x = x - 1;
				y = y;
			}
		}
	}

}
void even(int (&MAP)[MAX][MAX]) {
	if (N % 4 == 0) { //4�ǹ���϶�
		bool cross[MAX + 1][MAX + 1] = { false };
		int k = N / 4;
		rep(i, N) {
			rep(j, N) {
				if ((0 <= i && i <= k - 1 && 0 <= j && j <= k - 1)
					|| (0 <= i && i <= k - 1 && 3 * k <= j)
					|| (3 * k <= i && 0 <= j && j <= k - 1)
					|| (3 * k <= i && 3 * k <= j))
					cross[i][j] = true;
				if (k <= i && i <= 3 * k - 1 && k <= j && j <= 3 * k - 1)
					cross[i][j] = true;
			}
		}
		bool num[MAX * MAX + 2] = { false };
		rep(i, N) {
			rep(j, N) {
				if (cross[i][j]) {
					MAP[i][j] = N * i + j + 1;
					num[N * i + j + 1] = true;
				}
			}
		}
		int n;
		rrep(i, 1, MAX * MAX + 2) { //�����Ҽ��� ã��
			n = i;
			if (!num[i])
				br;
		}

		_rrep(i, N - 1, 0) {
			_rrep(j, N - 1, 0) {
				if (!cross[i][j]) { //�밢���� �ƴѰ�
					MAP[i][j] = n;
					num[n] = true;
					rrep(i, n + 1, MAX * MAX + 2) { //���� k���� ã��
						n++;
						if (!num[i])
							br;
					}
				}
			}
		}
	}
	else { //�׿� ¦��(4�ǹ�� + 2)
		int sub[MAX][MAX] = {0};
		int k = N / 2;
		odd(sub, k);
		
		int kk = k / 2;
		//�⺻ ����
		rrep(i, k, N) { //C
			rep(j, k) {
				map[i][j] = 3;
			}
		}
		rep(i, k) { //B
			rrep(j, k, N) {
				if (N - kk < j)
					map[i][j] = 1;
				else
					map[i][j] = 2;
			}
		}
		rrep(i, k, N) { //D
			rrep(j, k, N) {
				if (N - kk < j)
					map[i][j] = 2;
				else
					map[i][j] = 1;
			}
		}
		printAll();
		
		rep(i, kk) {
			rep(j, kk) {
				map[i][j] = 3;
				map[i + k][j] = 0;
			}
		}

		rrep(j, 1, kk + 1) { //����� �ٲ�
			map[kk][j] = 3;
			map[3 * kk + 1][j] = 0;
		}

		rrep(i,k - kk, k) {
			rep(j, kk) {
				map[i][j] = 3;
				map[i + k][j] = 0;
			}
		}

		//���õ� �������� size*size/4�� ���� ����
		rep(i, N)
			rep(j, N)
				map[i][j] *= (N * N) / 4;

		//printAll();
		
		//�̸����� N/2 * N/2 �������� ��  4���ҿ� ����
		rep(i, k) {
			rep(j, k) {
				map[i][j] += sub[i][j]; //A
				map[i][j + k] += sub[i][j]; //C
				map[i + k][j + k] += sub[i][j]; //B
				map[i + k][j] += sub[i][j]; //D
			}
		}
	}
}

void func() {
	if (N % 2 != 0) //Ȧ���϶�
		odd(map, N);
	else //¦���϶�
		even(map);

	printAll();
}

void printAll() {
	rep(i, N) {
		rep(j, N)
			pr("%d ", map[i][j]);
		pr("\n");
	}

	//DEBUG(); //DEBUG
}

void DEBUG() {
	pr("1!!!!!!!!!!!!!\n");
	rep(i, N) {
		int sum = 0;
		rep(j, N)
			sum += map[i][j];
		pr("%d\n", sum);
	}
	pr("2!!!!!!!!!!!!!\n");
	rep(i, N) {
		int sum = 0;
		rep(j, N)
			sum += map[j][i];
		pr("%d\n", sum);
	}


	pr("3!!!!!!!!!!!!!\n");
	int sum = 0;
	rep(i, N) {
		
		sum += map[i][i];
		
	}
	pr("%d\n", sum);
	pr("4!!!!!!!!!!!!!\n");
	sum = 0;
	rep(i, N) {
		sum += map[i][N - i - 1];
	}
	pr("%d\n\n\n", sum);
	bool num[MAX * MAX * 2] = {false};
	 rep(i, N)
		 rep(j, N)
			if (num[map[i][j]]) { //�̹� üũ��µ�??
				pr("ERROR >> %d,%d\n", i, j);
			}
			else {
				num[map[i][j]] = true;
			}
	 rrep(i, 1, N* N + 1)
		 if (!num[i])
			 pr("CANT FIND NUM: %d\n", i);
}

int main(void) {
	init();
	func();

	rt 0;
}