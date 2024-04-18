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

//문자열W를 문자열A의 규칙대로 cnt만큼 shift시킨후의 문자열을 리턴
string SHIFT(std::map<char, int> &charToIndex, 
	char(&A)[63], int &lenA, char(&W)[50001], int lenW, int cnt) {
	string res;
	int i = 0;
	rep(i, lenW) {
		char CH = W[i]; //W의 문자하나
		int idx = charToIndex[CH]; //문자에대한 A에서의 위치를 찾음
		char newCH = A[(idx + cnt) % lenA];
		res += newCH;
	}
	//DEBUG
	//pr("[%s]\n", res.tc());

	rt res;
}

//KMP에서 쓰일 실패테이블을 만들어 리턴하는 함수
vi makeFailureTable(string patt) {
	int lenP = patt.length();
	vi F(lenP, 0);

	int j = 0;
	rrep(i, 1, lenP) {
		while (j > 0 && patt[i] != patt[j])
			j = F[j - 1];
		if (patt[i] == patt[j])
			F[i] = ++j;
	}

	rt F;
}

//KMP를이용해 text에서 patt가 반복되는 횟수를 리턴
int KMP(string text, string patt) {
	int lenT = text.length();
	int lenP = patt.length();
	int cnt = 0;
	vi F = makeFailureTable(patt);

	int j = 0;
	rep(i, lenT) {
		while (j > 0 && text[i] != patt[j])
			j = F[j - 1];
		if (text[i] == patt[j]) {
			if (j == lenP - 1) {
				cnt++;
				j = F[j];
			}
			else {
				j++;
			}
		}
	}

	rt cnt;
}

//프로그램 메인 로직
void func() {
	sc("%d", &T);
	while (T--) {
		char A[63], W[50001], S[500001];
		sc("%s%s%s", A, W, S);
		
		int lenA = 0, lenW = 0, lenS = 0;
		rep(i, 63)
			if (A[i] == '\0') br;
			else lenA++;
		rep(i, 50001)
			if (W[i] == '\0') br;
			else lenW++;
		rep(i, 500001)
			if (S[i] == '\0') br;
			else lenS++;
		std::map<char, int> charToIndex;
		rep(i, lenA)
			charToIndex[A[i]] = i; //A의 i번째문자는 i값을 가지도록함

		vi res; //S에서 W shift k가 한번만나타나는 k들을 저장

		rep(k, lenA) {
			string strW = SHIFT(charToIndex, A, lenA, W, lenW, k); //W shiftL k
			string strS(S);
			//KMP돌려서 반복되는 횟수를찾는다.
			int cnt = KMP(strS, strW); //S에 쉬프트시킨W가 몇번나타나냐
			//1번 등장하면
			if (cnt == 1)
				res.pb(k); //현재 쉬프트값k 저장
			//0번, 2번이상은 문제의 조건에 부합한결과 제외.
		}

		if (sz(res) == 0)
			pr("no solution\n");
		else if (sz(res) == 1)
			pr("unique: %d\n", res[0]);
		else {
			pr("ambiguous: ");
			rep(i, sz(res))
				pr("%d ", res[i]);
			pr("\n");
		}
	}
}


int main(void) {
	func();

	rt 0;
}