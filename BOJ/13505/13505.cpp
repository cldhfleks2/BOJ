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
//#define MAX 
const int IMAX = INT32_MAX; const int IMIN = INT32_MIN;
const long long LMAX = LLONG_MAX; const long long LMIN = LLONG_MIN;
const long double PI = 3.141592653589793238462643383279502884197;
_UG std::vector; _UG std::stack; _UG std::queue; _UG std::tuple; _UG std::set; _UG std::list; _UG std::bitset; _UG std::string; _UG std::pair; _UG std::greater;
_UG std::tie; _UG std::sort; _UG std::max_element; _UG std::min_element; _UG std::fill; _UG std::stoi; _UG std::stod; _UG std::stof; _UG std::stol; _UG std::stold; _UG std::stoll; _UG std::stoul; _UG std::stoull; _UG std::to_string;
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

int N;
vi number; //�Է¹��� ������
int binary[31]; //10������������� 30���� ��Ʈ�� ���尡��. 31��°��Ʈ�� �ǳ��� ��Ÿ����

struct BinaryTrie {
private:
	BinaryTrie* node[2];

public:
	BinaryTrie() : node() {}

	//2������ binaryArr�迭�� Trie������ ����
	void insert(int *binary) {
		if (*binary == -1) rt;

		if (node[*binary] == nullptr)
			node[*binary] = new BinaryTrie();

		node[*binary]->insert(binary + 1);
	}

	//Trie�������� �ϳ��� 2������ ������
	//�ش� 2������ XOR����� �ִ��� �Ǵ� �ٸ� 2������ ã�� �Լ�
	//������ 2������ �� ��Ʈ���� ������Ų��Ʈ�� ������ ã�� ������ ������Ʈ�� Ž��
	//�� 0, 1��Ʈ�� ��� �����ϴ� ���� ������ ��Ʈ(XOR����� 1�Ǵ�)�� ����
	void search(int *binary) {
		if (*binary == -1) rt;

		int bit = *binary; //���� ��Ʈ

		//XOR���� ũ���� 2���� �ǳ���Ʈ���� Ž���Ҷ� XOR���� �ִ밡 �ɷ���
		//���ڸ� ��Ʈ���� ������Ų ��Ʈ�� ã����� (���δٸ���Ʈ�� XOR��� 1, ������ 0)
		//�츮�� 2������ �������� �־����� binary�� 0���ε������� Ž���ϴ°� �ǳ���Ʈ���� Ž���ϴ°�
		//������ XOR�� �ִ밡�Ǵ� ��带 ������ ���󰡸�
		//Trie������ ���Ե� 2������ �ϳ��� ���ϰԵ�.
	
		//1���� : ������Ų ��Ʈ�� ������ ���� (XOR ��� 1, �ִ���)
		if (node[bit ^ 1] != nullptr) { 
			*binary = bit ^ (bit ^ 1); //������Ʈ�� ������Ų ��Ʈ�� ������ XOR�� ����� 1
			node[bit ^ 1]->search(binary + 1); //ã�� ��Ʈ�� ��带 ���� Ž��
			
		}//2���� : ������Ų ��Ʈ�� ������ ���� ��Ʈ�� ����(XOR��� 0)
		else { 
			*binary = bit ^ bit; //������Ʈ�� ������Ʈ�� ������ XOR�� ����� 0
			 node[bit]->search(binary + 1); //ã�� ��Ʈ�� ����..
		}
	}
};

//���α׷� ���� ����
void func() {
	BinaryTrie bt;
	sc("%d", &N);
	binary[30] = -1;

	rep(_, N) { //������ �Է¹޾� 2������ Trie������ ����
		int n;
		sc("%d", &n);
		number.pb(n);
		_rrep(i, 29, 0) { //2������ ��ȯ�ϵ� �������� Trie������ ����
			n & 1 ? binary[i] = 1 : binary[i] = 0;
			n >>= 1;
		}
		//�Է¹��� ������ 2�����ιٲپ� Trie������ ����
		bt.insert(binary);
	}

	int maxXOR = 0; //XOR�ִ�
	rep(k, sz(number)) {
		int n = number[k];
		//������ 2������ ��ȯ�ؼ� binary�� ����
		_rrep(i, 29, 0) {
			n & 1 ? binary[i] = 1 : binary[i] = 0;
			n >>= 1;
		}
		//binary�� XOR����� �ִ밡�Ǵ� 2������ ã�Ƽ� �ٽ� binary�� �����
		bt.search(binary); 

		int decimal = 0; //��ȯ�� ����
		int digit = 1; //���ڸ��� Ȯ���ϱ����� ��Ʈ
		_rrep(i, 29, 0) {
			if (binary[i]) decimal |= digit; //�� �ڸ������� ������ ��ȯ
			digit <<= 1; //���� �ڸ����� Ž��
		}

		maxXOR = std::max(maxXOR, decimal);
	}
	pr("%d", maxXOR);
}


int main(void) {
	func();

	rt 0;
}