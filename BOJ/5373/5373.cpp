#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
#define mp std::make_pair 
#define mt std::make_tuple
#define sw std::swap;
#define dq std::deque
#define pq std::priority_queue
#define ts(x) std::to_string(x)
#define tc(x) x.c_str()
#define sc(x, ...) scanf(x, ##__VA_ARGS__) 
#define pr(x, ...) printf(x, ##__VA_ARGS__) 
#define pb(x) push_back(x)
#define pf(x) push_front(x)
#define PB() pop_back()
#define PF() pop_front()
#define ph(x) push(x)
#define P() pop()
#define B() back()
#define F() front()
#define len(x) x.length()
#define sz(x) ((int)x.size())
#define ms(a) memset(a, 0, sizeof(a)) //0���� �ʱ�ȭ
#define rep(i, n) for(int i = 0; i < n ; i++)
#define rrep(i, r, n) for(int i = r; i < n ; i++)
#define _rrep(i, r, n) for(int i = r; i >= n; i--)
#define each(x, a) for (auto& x: a)
#define all(x) (x).begin(),(x).end() //sort��� �����̳� ��ü�� ó���ؾ��Ҷ� ���
#define ct continue
#define br break
#define rt return
//#define MAX 
const int IMAX = INT32_MAX; const int IMIN = INT32_MIN;
const long long LMAX = LLONG_MAX; const long long LMIN = LLONG_MIN;
const long double PI = 3.141592653589793238462643383279502884197;
using std::vector; using std::stack; using std::queue; using std::tuple; using std::set; using std::list; using std::bitset; using std::string; using std::pair; using std::greater;
using std::tie; using std::sort; using std::max_element; using std::min_element; using std::fill;
//using std::max; //using std::min; //using std::map;
typedef long long ll; typedef unsigned long long ull;
typedef pair<int, int> pii; typedef pair<double, int> pdi; typedef pair<int, double> pid; typedef pair<double, double> pdd; typedef pair<int, ll> pil;
typedef pair<ll, int> pli; typedef pair<ll, ll> pll; typedef pair<ull, ull> pullull; typedef pair<int, char> pic; typedef pair<char, int> pci;
typedef pair<char, char> pcc; typedef pair<long, char> plc; typedef pair<char, long> pcl; typedef pair<ll, char> pllc; typedef pair<char, ll> pcll;
typedef pair<ull, char> pullc; typedef pair<char, ull> pcull; typedef pair<int, string> pis; typedef pair<string, int> psi; typedef pair<long, string> pls;
typedef pair<string, long> psl; typedef pair<ll, string> plls; typedef pair<string, ll> psll; typedef pair<ull, string> pulls;
typedef pair<string, ull> psull; typedef pair<string, string> pss;
typedef tuple<int, int, int> tiii; typedef tuple<int, int, int, int> tiiii;
typedef tuple<ll, ll, ll> tlll; typedef tuple<ll, ll, ll, ll> tllll;
typedef vector<string> vs; typedef queue<string> qs; typedef stack<string> ss; typedef dq<string> dqs; typedef pq<string> pqs;
typedef vector<char> vc; typedef queue<char> qc; typedef stack<char> sc; typedef dq<char> dqc; typedef pq<char> pqc;
typedef vector<int> vi; typedef queue<int> qi; typedef stack<int> si; typedef dq<int> dqi; typedef pq<int> pqi;
typedef vector<pii> vii; typedef queue<pii> qii; typedef stack<pii> sii; typedef dq<pii> dqii; typedef pq<pii> pqii;
typedef vector<tiii> viii; typedef queue<tiii> qiii; typedef stack<tiii> siii; typedef dq<tiii> dqiii; typedef pq<tiii> pqiii;
typedef vector<tiiii> viiii; typedef queue<tiiii> qiiii; typedef stack<tiiii> siiii; typedef dq<tiiii> dqiiii; typedef pq<tiiii> pqiiii;
typedef vector<pll> vll; typedef queue<pll> qll; typedef stack<ll> sll; typedef dq<pll> dqll; typedef pq<pll> pqll;
typedef vector<tlll> vlll; typedef queue<tlll> qlll; typedef stack<tlll> slll; typedef dq<tlll> dqlll; typedef pq<tlll> pqlll;
typedef vector<tllll> vllll; typedef queue<tllll> qllll; typedef stack<tllll> sllll; typedef dq<tllll> dqllll; typedef pq<tllll> pqllll;
template <class T> inline T sq(T num) { rt num* num; }//�����Լ�
template <class T> inline T GCD(T num1, T num2) { if (num2 == 0) rt num1; rt GCD(num2, num1 % num2); }
template <class T> inline T LCM(T num1, T num2) { if (num1 == 0 || num2 == 0) rt num1 + num2; rt num1* (num2 / GCD(num1, num2)); }
//STL ���� �ʱ�ȭ �Լ��� ( ms~~ )
template <class T> inline void msq(T a) { while (!a.empty()) a.pop(); }//queue clear
template <class T> inline void msv(T a) { a.clear(); }//vector clear
template <class T> inline void msdq(T a) { a.clear(); }//deque clear
template <class T> inline void msm(T a) { a.clear(); }//map clear
template <class T> inline void mss(T a) { while (!a.empty()) a.pop(); }//stack, set clear
template <class T> inline void mspq(T a) { while (!a.empty()) a.pop(); }//priority_queue clear
//pii operator - (pii a, pii b) { return pii(a.first - b.first, a.second - b.second); }
//bool operator <= (pii a, pii b) { return a.first <= b.first && a.second <= b.second; } 
//bool operator >= (pii a, pii b) { return a.first >= b.first && a.second >= b.second; } 
//bool operator < (pii a, pii b) { if (a == b) return false; return a <= b; } 
//bool operator > (pii a, pii b) { if (a == b) return false; return a >= b; }

int T;
int cube[6][3][3]; 
char colors[] = { 'w', 'r', 'y', 'o' ,'g' ,'b' };
/*
cube
    555
    555
    555
333 000 111 222
333 000 111 222
333 000 111 222
    444
    444
    444

cube & colors
    bbb
    bbb
    bbb             
ooo www rrr yyy  
ooo www rrr yyy  
ooo www rrr yyy  
    ggg
    ggg
    ggg
*/

void func();
void rotateClockwise(char p, int degree);
void printAll();
void reset();
void DEBUG();

void reset() {
    rep(k, 6)
        rep(i, 3)
            rep(j, 3)
                cube[k][i][j] = k; //�ʱ�ȭ
}

void func() {
    sc("%d", &T);

    //DEBUG
    reset();
    while (T--) {
        //pr("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n"); //DEBUG
        reset();
        int n; //ť�긦 ����Ƚ��
        char _; //�ٹٲ޹��� ����
        sc("%d%c", &n, &_);
        while (n--) {
            char order[4];
            sc("%3c", &order);
            int degree; //�ð�������� ȸ����ų ���� (�ݽð���� ȸ���� 270�� �ð���� ȸ���� ����) 
            order[1] == '+' ? degree = 90 : degree = 270;
            rotateClockwise(order[0], degree); //�Է¹��� ���� degree������ŭ ȸ����Ŵ
            //DEBUG(); //DEBUG
        }
        printAll();
        //pr("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n"); //DEBUG 
    }
}

//��p�� degree������ŭ �ð�������� ȸ����Ų��.
//degree : 90, 180 , 270 ����
//��p�� �������� �����ؼ� copy�� ������
//copy�� ���鿡�� �ð�������� ������
//�������� cube�� copy�� �����Ų��.
void rotateClockwise(char f, int degree) {
    if (degree != 90 && degree != 180 && degree != 270) rt;
    int rotateFace[3][3];
    
    //1. �� ĭ�� ȸ����Ű������ ��ť�� ���� 
    //ȸ���Ҹ��� topFace��, �� ��� ���� 4���� �� 3ĭ���� ������ sideFace�� ����
    //front���� ���� �ٽ� back�� ������ ȸ����Ű�� ���
    dq<int> topFace, sideFace; //�ش���� 8ĭ, �´�� 4���� 3ĭ��(��12ĭ)����
    if (f == 'U') { //����
        topFace.pb(cube[0][0][0]);
        topFace.pb(cube[0][0][1]);
        topFace.pb(cube[0][0][2]);
        topFace.pb(cube[0][1][2]);
        topFace.pb(cube[0][2][2]);
        topFace.pb(cube[0][2][1]);
        topFace.pb(cube[0][2][0]);
        topFace.pb(cube[0][1][0]);
        //R
        sideFace.pb(cube[5][2][0]);
        sideFace.pb(cube[5][2][1]);
        sideFace.pb(cube[5][2][2]);
        //F
        sideFace.pb(cube[1][0][0]);
        sideFace.pb(cube[1][1][0]);
        sideFace.pb(cube[1][2][0]);
        //L
        sideFace.pb(cube[4][0][2]);
        sideFace.pb(cube[4][0][1]);
        sideFace.pb(cube[4][0][0]);
        //B
        sideFace.pb(cube[3][2][2]);
        sideFace.pb(cube[3][1][2]);
        sideFace.pb(cube[3][0][2]);

    }
    else if (f == 'F') { //�ո�
        topFace.pb(cube[1][0][0]);
        topFace.pb(cube[1][0][1]);
        topFace.pb(cube[1][0][2]);
        topFace.pb(cube[1][1][2]);
        topFace.pb(cube[1][2][2]);
        topFace.pb(cube[1][2][1]);
        topFace.pb(cube[1][2][0]);
        topFace.pb(cube[1][1][0]);
        //R
        sideFace.pb(cube[5][2][2]);
        sideFace.pb(cube[5][1][2]);
        sideFace.pb(cube[5][0][2]);
        //D
        sideFace.pb(cube[2][0][0]);
        sideFace.pb(cube[2][1][0]);
        sideFace.pb(cube[2][2][0]);
        //L
        sideFace.pb(cube[4][2][2]);
        sideFace.pb(cube[4][1][2]);
        sideFace.pb(cube[4][0][2]);
        //U
        sideFace.pb(cube[0][2][2]);
        sideFace.pb(cube[0][1][2]);
        sideFace.pb(cube[0][0][2]);
    }
    else if (f == 'D') { //�Ʒ���
        topFace.pb(cube[2][0][0]);
        topFace.pb(cube[2][0][1]);
        topFace.pb(cube[2][0][2]);
        topFace.pb(cube[2][1][2]);
        topFace.pb(cube[2][2][2]);
        topFace.pb(cube[2][2][1]);
        topFace.pb(cube[2][2][0]);
        topFace.pb(cube[2][1][0]);
        //R
        sideFace.pb(cube[5][0][2]);
        sideFace.pb(cube[5][0][1]);
        sideFace.pb(cube[5][0][0]);
        //B
        sideFace.pb(cube[3][0][0]);
        sideFace.pb(cube[3][1][0]);
        sideFace.pb(cube[3][2][0]);
        //L
        sideFace.pb(cube[4][2][0]);
        sideFace.pb(cube[4][2][1]);
        sideFace.pb(cube[4][2][2]);
        //F
        sideFace.pb(cube[1][2][2]);
        sideFace.pb(cube[1][1][2]);
        sideFace.pb(cube[1][0][2]);
    }
    else if (f == 'B') { //�޸�
        topFace.pb(cube[3][0][0]);
        topFace.pb(cube[3][0][1]);
        topFace.pb(cube[3][0][2]);
        topFace.pb(cube[3][1][2]);
        topFace.pb(cube[3][2][2]);
        topFace.pb(cube[3][2][1]);
        topFace.pb(cube[3][2][0]);
        topFace.pb(cube[3][1][0]);
        //R
        sideFace.pb(cube[5][0][0]);
        sideFace.pb(cube[5][1][0]);
        sideFace.pb(cube[5][2][0]);
        //U
        sideFace.pb(cube[0][0][0]);
        sideFace.pb(cube[0][1][0]);
        sideFace.pb(cube[0][2][0]);
        //L
        sideFace.pb(cube[4][0][0]);
        sideFace.pb(cube[4][1][0]);
        sideFace.pb(cube[4][2][0]);
        //D
        sideFace.pb(cube[2][2][2]);
        sideFace.pb(cube[2][1][2]);
        sideFace.pb(cube[2][0][2]);
    }
    else if (f == 'L') { //���ʸ�
        topFace.pb(cube[4][0][0]);
        topFace.pb(cube[4][0][1]);
        topFace.pb(cube[4][0][2]);
        topFace.pb(cube[4][1][2]);
        topFace.pb(cube[4][2][2]);
        topFace.pb(cube[4][2][1]);
        topFace.pb(cube[4][2][0]);
        topFace.pb(cube[4][1][0]);
        //U
        sideFace.pb(cube[0][2][0]);
        sideFace.pb(cube[0][2][1]);
        sideFace.pb(cube[0][2][2]);
        //F
        sideFace.pb(cube[1][2][0]);
        sideFace.pb(cube[1][2][1]);
        sideFace.pb(cube[1][2][2]);
        //D
        sideFace.pb(cube[2][2][0]);
        sideFace.pb(cube[2][2][1]);
        sideFace.pb(cube[2][2][2]);
        //B
        sideFace.pb(cube[3][2][0]);
        sideFace.pb(cube[3][2][1]);
        sideFace.pb(cube[3][2][2]);


    }
    else if (f == 'R') { //�����ʸ�
        topFace.pb(cube[5][0][0]);
        topFace.pb(cube[5][0][1]);
        topFace.pb(cube[5][0][2]);
        topFace.pb(cube[5][1][2]);
        topFace.pb(cube[5][2][2]);
        topFace.pb(cube[5][2][1]);
        topFace.pb(cube[5][2][0]);
        topFace.pb(cube[5][1][0]);
        //D
        sideFace.pb(cube[2][0][2]);
        sideFace.pb(cube[2][0][1]);
        sideFace.pb(cube[2][0][0]);
        //F
        sideFace.pb(cube[1][0][2]);
        sideFace.pb(cube[1][0][1]);
        sideFace.pb(cube[1][0][0]);
        //U
        sideFace.pb(cube[0][0][2]);
        sideFace.pb(cube[0][0][1]);
        sideFace.pb(cube[0][0][0]);
        //B
        sideFace.pb(cube[3][0][2]);
        sideFace.pb(cube[3][0][1]);
        sideFace.pb(cube[3][0][0]);
    }
    int cnt = degree / 90;
    //2. ������� ��ť�� �ð�������� degree/90 �� ȸ����Ų��.
    rep(_, cnt * 3) {
        int color;
        color = sideFace.B(); //�ֺ����� �ð���� 90�� ȸ����Ŵ
        sideFace.PB();
        sideFace.pf(color);
    }
    
    rep(_, cnt * 2) {
        int color;
        color = topFace.B(); //������ �ð���� 90�� ȸ����Ŵ
        topFace.PB();
        topFace.pf(color);
    }
    
    //3. ȸ������� cube�� ���
    if (f == 'U') { //����
        cube[0][0][0] = topFace.F(); topFace.PF();
        cube[0][0][1] = topFace.F(); topFace.PF();
        cube[0][0][2] = topFace.F(); topFace.PF();
        cube[0][1][2] = topFace.F(); topFace.PF();
        cube[0][2][2] = topFace.F(); topFace.PF();
        cube[0][2][1] = topFace.F(); topFace.PF();
        cube[0][2][0] = topFace.F(); topFace.PF();
        cube[0][1][0] = topFace.F(); topFace.PF();

        //R
        cube[5][2][0] = sideFace.F(); sideFace.PF();
        cube[5][2][1] = sideFace.F(); sideFace.PF();
        cube[5][2][2] = sideFace.F(); sideFace.PF();
        //F
        cube[1][0][0] = sideFace.F(); sideFace.PF();
        cube[1][1][0] = sideFace.F(); sideFace.PF();
        cube[1][2][0] = sideFace.F(); sideFace.PF();
        //L
        cube[4][0][2] = sideFace.F(); sideFace.PF();
        cube[4][0][1] = sideFace.F(); sideFace.PF();
        cube[4][0][0] = sideFace.F(); sideFace.PF();
        //B
        cube[3][2][2] = sideFace.F(); sideFace.PF();
        cube[3][1][2] = sideFace.F(); sideFace.PF();
        cube[3][0][2] = sideFace.F(); sideFace.PF();
    }
    else if (f == 'F') { //�ո�
        cube[1][0][0] = topFace.F(); topFace.PF();
        cube[1][0][1] = topFace.F(); topFace.PF();
        cube[1][0][2] = topFace.F(); topFace.PF();
        cube[1][1][2] = topFace.F(); topFace.PF();
        cube[1][2][2] = topFace.F(); topFace.PF();
        cube[1][2][1] = topFace.F(); topFace.PF();
        cube[1][2][0] = topFace.F(); topFace.PF();
        cube[1][1][0] = topFace.F(); topFace.PF();
        //R
        cube[5][2][2] = sideFace.F(); sideFace.PF();
        cube[5][1][2] = sideFace.F(); sideFace.PF();
        cube[5][0][2] = sideFace.F(); sideFace.PF();
        //D
        cube[2][0][0] = sideFace.F(); sideFace.PF();
        cube[2][1][0] = sideFace.F(); sideFace.PF();
        cube[2][2][0] = sideFace.F(); sideFace.PF();
        //L
        cube[4][2][2] = sideFace.F(); sideFace.PF();
        cube[4][1][2] = sideFace.F(); sideFace.PF();
        cube[4][0][2] = sideFace.F(); sideFace.PF();
        //U
        cube[0][2][2] = sideFace.F(); sideFace.PF();
        cube[0][1][2] = sideFace.F(); sideFace.PF();
        cube[0][0][2] = sideFace.F(); sideFace.PF();
    }
    else if (f == 'D') { //�Ʒ���
        cube[2][0][0] = topFace.F(); topFace.PF();
        cube[2][0][1] = topFace.F(); topFace.PF();
        cube[2][0][2] = topFace.F(); topFace.PF();
        cube[2][1][2] = topFace.F(); topFace.PF();
        cube[2][2][2] = topFace.F(); topFace.PF();
        cube[2][2][1] = topFace.F(); topFace.PF();
        cube[2][2][0] = topFace.F(); topFace.PF();
        cube[2][1][0] = topFace.F(); topFace.PF();
        //R
        cube[5][0][2] = sideFace.F(); sideFace.PF();
        cube[5][0][1] = sideFace.F(); sideFace.PF();
        cube[5][0][0] = sideFace.F(); sideFace.PF();
        //B
        cube[3][0][0] = sideFace.F(); sideFace.PF();
        cube[3][1][0] = sideFace.F(); sideFace.PF();
        cube[3][2][0] = sideFace.F(); sideFace.PF();
        //L
        cube[4][2][0] = sideFace.F(); sideFace.PF();
        cube[4][2][1] = sideFace.F(); sideFace.PF();
        cube[4][2][2] = sideFace.F(); sideFace.PF();
        //F
        cube[1][2][2] = sideFace.F(); sideFace.PF();
        cube[1][1][2] = sideFace.F(); sideFace.PF();
        cube[1][0][2] = sideFace.F(); sideFace.PF();
    }
    else if (f == 'B') { //�޸�
        cube[3][0][0] = topFace.F(); topFace.PF();
        cube[3][0][1] = topFace.F(); topFace.PF();
        cube[3][0][2] = topFace.F(); topFace.PF();
        cube[3][1][2] = topFace.F(); topFace.PF();
        cube[3][2][2] = topFace.F(); topFace.PF();
        cube[3][2][1] = topFace.F(); topFace.PF();
        cube[3][2][0] = topFace.F(); topFace.PF();
        cube[3][1][0] = topFace.F(); topFace.PF();
        //R
        cube[5][0][0] = sideFace.F(); sideFace.PF();
        cube[5][1][0] = sideFace.F(); sideFace.PF();
        cube[5][2][0] = sideFace.F(); sideFace.PF();
        //U
        cube[0][0][0] = sideFace.F(); sideFace.PF();
        cube[0][1][0] = sideFace.F(); sideFace.PF();
        cube[0][2][0] = sideFace.F(); sideFace.PF();
        //L
        cube[4][0][0] = sideFace.F(); sideFace.PF();
        cube[4][1][0] = sideFace.F(); sideFace.PF();
        cube[4][2][0] = sideFace.F(); sideFace.PF();
        //D
        cube[2][2][2] = sideFace.F(); sideFace.PF();
        cube[2][1][2] = sideFace.F(); sideFace.PF();
        cube[2][0][2] = sideFace.F(); sideFace.PF();
    }
    else if (f == 'L') { //���ʸ�
        cube[4][0][0] = topFace.F(); topFace.PF();
        cube[4][0][1] = topFace.F(); topFace.PF();
        cube[4][0][2] = topFace.F(); topFace.PF();
        cube[4][1][2] = topFace.F(); topFace.PF();
        cube[4][2][2] = topFace.F(); topFace.PF();
        cube[4][2][1] = topFace.F(); topFace.PF();
        cube[4][2][0] = topFace.F(); topFace.PF();
        cube[4][1][0] = topFace.F(); topFace.PF();
        //U
        cube[0][2][0] = sideFace.F(); sideFace.PF();
        cube[0][2][1] = sideFace.F(); sideFace.PF();
        cube[0][2][2] = sideFace.F(); sideFace.PF();
        //F
        cube[1][2][0] = sideFace.F(); sideFace.PF();
        cube[1][2][1] = sideFace.F(); sideFace.PF();
        cube[1][2][2] = sideFace.F(); sideFace.PF();
        //D
        cube[2][2][0] = sideFace.F(); sideFace.PF();
        cube[2][2][1] = sideFace.F(); sideFace.PF();
        cube[2][2][2] = sideFace.F(); sideFace.PF();
        //B
        cube[3][2][0] = sideFace.F(); sideFace.PF();
        cube[3][2][1] = sideFace.F(); sideFace.PF();
        cube[3][2][2] = sideFace.F(); sideFace.PF();
    }
    else if (f == 'R') { //�����ʸ�
        cube[5][0][0] = topFace.F(); topFace.PF();
        cube[5][0][1] = topFace.F(); topFace.PF();
        cube[5][0][2] = topFace.F(); topFace.PF();
        cube[5][1][2] = topFace.F(); topFace.PF();
        cube[5][2][2] = topFace.F(); topFace.PF();
        cube[5][2][1] = topFace.F(); topFace.PF();
        cube[5][2][0] = topFace.F(); topFace.PF();
        cube[5][1][0] = topFace.F(); topFace.PF();
        //D
        cube[2][0][2] = sideFace.F(); sideFace.PF();
        cube[2][0][1] = sideFace.F(); sideFace.PF();
        cube[2][0][0] = sideFace.F(); sideFace.PF();
        //F
        cube[1][0][2] = sideFace.F(); sideFace.PF();
        cube[1][0][1] = sideFace.F(); sideFace.PF();
        cube[1][0][0] = sideFace.F(); sideFace.PF();
        //U
        cube[0][0][2] = sideFace.F(); sideFace.PF();
        cube[0][0][1] = sideFace.F(); sideFace.PF();
        cube[0][0][0] = sideFace.F(); sideFace.PF();
        //B
        cube[3][0][2] = sideFace.F(); sideFace.PF();
        cube[3][0][1] = sideFace.F(); sideFace.PF();
        cube[3][0][0] = sideFace.F(); sideFace.PF();
    }

    
}

void printAll() {
    pr("%c%c%c\n", colors[cube[0][2][0]], colors[cube[0][1][0]], colors[cube[0][0][0]]);
    pr("%c%c%c\n", colors[cube[0][2][1]], colors[cube[0][1][1]], colors[cube[0][0][1]]);
    pr("%c%c%c\n", colors[cube[0][2][2]], colors[cube[0][1][2]], colors[cube[0][0][2]]);
}

void DEBUG() {
    pr("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");

    pr("    %c%c%c\n", colors[cube[5][0][0]], colors[cube[5][0][1]], colors[cube[5][0][2]]);
    pr("    %c%c%c\n", colors[cube[5][1][0]], colors[cube[5][1][1]], colors[cube[5][1][2]]);
    pr("    %c%c%c\n", colors[cube[5][2][0]], colors[cube[5][2][1]], colors[cube[5][2][2]]);

    pr("%c%c%c ", colors[cube[3][0][0]], colors[cube[3][0][1]], colors[cube[3][0][2]]); 
    pr("%c%c%c ", colors[cube[0][0][0]], colors[cube[0][0][1]], colors[cube[0][0][2]]);
    pr("%c%c%c ", colors[cube[1][0][0]], colors[cube[1][0][1]], colors[cube[1][0][2]]);
    pr("%c%c%c\n", colors[cube[2][0][0]], colors[cube[2][0][1]], colors[cube[2][0][2]]);

    pr("%c%c%c ", colors[cube[3][1][0]], colors[cube[3][1][1]], colors[cube[3][1][2]]);
    pr("%c%c%c ", colors[cube[0][1][0]], colors[cube[0][1][1]], colors[cube[0][1][2]]);
    pr("%c%c%c ", colors[cube[1][1][0]], colors[cube[1][1][1]], colors[cube[1][1][2]]);
    pr("%c%c%c\n", colors[cube[2][1][0]], colors[cube[2][1][1]], colors[cube[2][1][2]]);

    pr("%c%c%c ", colors[cube[3][2][0]], colors[cube[3][2][1]], colors[cube[3][2][2]]);
    pr("%c%c%c ", colors[cube[0][2][0]], colors[cube[0][2][1]], colors[cube[0][2][2]]);
    pr("%c%c%c ", colors[cube[1][2][0]], colors[cube[1][2][1]], colors[cube[1][2][2]]);
    pr("%c%c%c\n", colors[cube[2][2][0]], colors[cube[2][2][1]], colors[cube[2][2][2]]);

    pr("    %c%c%c\n", colors[cube[4][0][0]], colors[cube[4][0][1]], colors[cube[4][0][2]]);
    pr("    %c%c%c\n", colors[cube[4][1][0]], colors[cube[4][1][1]], colors[cube[4][1][2]]);
    pr("    %c%c%c\n", colors[cube[4][2][0]], colors[cube[4][2][1]], colors[cube[4][2][2]]);
    pr("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
}

int main(void) {
    func();

    rt 0;
}