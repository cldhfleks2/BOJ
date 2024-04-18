#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
#define mp std::make_pair 
#define mt std::make_tuple
#define sw std::swap;
#define ts std::to_string
#define pq std::priority_queue
#define dq std::deque
#define pb(x) push_back(x)
#define pf(x) push_front(x)
#define ppb(x) pop_back(x)
#define ppf(x) pop_front(x)
#define b(x) back(x)
#define f(x) front(x)
#define sz(x) ((int)x.size())
#define mem(a) memset((a), 0, sizeof(a)) //0���� �ʱ�ȭ
#define rep(i, n) for(int i = 0; i < n ; i++)
#define rrep(i, r, n) for(int i = r; i < n ; i++)
#define each(x, a) for (auto& x: a)
#define all(x) (x).begin(),(x).end() //sort��� �����̳� ��ü�� ó���ؾ��Ҷ� ���
#define ct continue
#define br break
#define MAX 16
const int IMAX = INT32_MAX; const int IMIN = INT32_MIN;
const long long LMAX = LLONG_MAX; const long long LMIN = LLONG_MIN;
const long double PI = 3.141592653589793238462643383279502884197;
using std::vector; using std::stack; using std::queue; using std::tuple; using std::set; using std::bitset; using std::string; using std::pair; using std::greater;
using std::tie; using std::sort; using std::max_element; using std::min_element; using std::fill;
using std::max; //using std::min; //using std::map;
typedef long long ll; typedef unsigned long long ull;
typedef pair<int, int> pii; typedef pair<double, int> pdi; typedef pair<int, double> pid; typedef pair<double, double> pdd; typedef pair<int, ll> pil;
typedef pair<ll, int> pli; typedef pair<ll, ll> pll; typedef pair<ull, ull> pullull; typedef pair<int, char> pic; typedef pair<char, int> pci;
typedef pair<char, char> pcc; typedef pair<long, char> plc; typedef pair<char, long> pcl; typedef pair<ll, char> pllc; typedef pair<char, ll> pcll;
typedef pair<ull, char> pullc; typedef pair<char, ull> pcull; typedef pair<int, string> pis; typedef pair<string, int> psi; typedef pair<long, string> pls;
typedef pair<string, long> psl; typedef pair<ll, string> plls; typedef pair<string, ll> psll; typedef pair<ull, string> pulls;
typedef pair<string, ull> psull; typedef pair<string, string> pss;
typedef tuple<int, int, int> tiii; typedef tuple<int, int, int, int> tiiii;
typedef tuple<ll, ll, ll> tlll; typedef tuple<ll, ll, ll, ll> tllll;
typedef vector<int> vi; typedef queue<int> qi;
typedef vector<pii> vii; typedef queue<pii> qii;
typedef vector<pll> vll; typedef queue<pll> qll;
typedef vector<tiii> vtiii; typedef queue<tiii> qtiii;
typedef vector<tiiii> vtiiii; typedef queue<tiiii> qtiiii;
typedef vector<tlll> vtlll; typedef queue<tlll> qtlll;
typedef vector<tllll> vtllll; typedef queue<tllll> qtllll;
template <class T> inline T sq(T num) { return num * num; }//�����Լ�
template <class T> inline T GCD(T num1, T num2) { if (num2 == 0) return num1; return GCD(num2, num1 % num2); }
template <class T> inline T LCM(T num1, T num2) { if (num1 == 0 || num2 == 0) return num1 + num2; return num1 * (num2 / GCD(num1, num2)); }
//pii operator - (pii a, pii b) { return pii(a.first - b.first, a.second - b.second); }


int N;
int map[MAX][MAX];
int dp[MAX][1 << 15][10]; //16���� ǥ���� ��Ʈ����ŷ
void init();
void func();

void init() {
    scanf("%d", &N);
    rep(i, N) {
        rep(j, N) {
            scanf("%1d", &map[i][j]);
        }
    }
}

//���� �������� �׸��� �ȶ� ���� ���� �� �� �ִ� ����� �����
//owner: ����׸��� ������� ��ȣ
//buyList: �׸��� �ȸ� ����� ��Ʈ����ŷ����
//buyPRice: ����׸���  �󸶿� �����
int DP(int owner, int buyList, int buyPrice) {
    int& ret = dp[owner][buyList][buyPrice];

    if (buyList == (1 << N) - 1) //��� �������� �׸��� ��ٸ� 
        return ret = 1; //�Լ�����, 1??

    if (ret != 0)
        return ret; //�޸������̼�. ���������� ��������

    ret = 1; //�ּ��� 1��

    rep(buyer, N) { //i: �������
        if (buyList & (1 << buyer)) //�̹� ����ٸ� ����
            continue;

        if (buyer == owner) //�ڱ��ڽ��� ����
            continue;

        if (map[owner][buyer] >= buyPrice) {
            ret = max(ret, DP(buyer, (buyList | 1 << buyer), map[owner][buyer]) + 1); 
        }
    }

    return ret;
}

void func() {
    printf("%d", DP(0, 1, 0));
}

int main(void) {
    init();
    func();


    return 0;
}