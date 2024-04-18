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
#define ppb(x) pop_back(x)
#define ppf(x) pop_front(x)
#define ph(x) push(x)
#define T() top()
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
#define MAX 5
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
bool operator <= (pii a, pii b) { return a.first <= b.first && a.second <= b.second; }
bool operator >= (pii a, pii b) { return a.first >= b.first && a.second >= b.second; }
bool operator < (pii a, pii b) { if (a == b) return false; return a <= b; }
bool operator > (pii a, pii b) { if (a == b) return false; return a >= b; }


int N;
int map[MAX][MAX];
vii animalList; //������ġ
int dxy[][2] = { {1,0}, {0,-1}, {-1,0}, {0,1} }; //��-��-��-��

void func();
bool isRight(string flagStr);
void print(string s);
void init();

void init() {
    char c;
    sc("%d", &N);
    rep(i, N) {
        sc("%c", &c); //�ٹٲ޹��� ����
        rep(j, N) {
            sc("%c", &c);
            if (c == '.') {
                map[i][j] = 0; //������� 0 
            }
            else {
                map[i][j] = c - 'A' + 1; //�빮�ڸ� ����1~27�� ��ü
                animalList.pb(mp(i, j));
            }
        }
    }
}

void print(string s) {
    pr("yes\n");
    //////////////////// DEBUG ////////////////////
    pr("--------------------------------\n");
    bool D[MAX][MAX];
    ms(D);
    rep(i, len(s)/2) {
        int x = s[i * 2] - '0';
        int y = s[i * 2 + 1] - '0';
        D[x][y] = true;
    }
    rep(i, N + 1) {
        rep(j, N + 1) {
            pr("%2d ", D[i][j]);
        }
        pr("\n");
    }
    pr("--------------------------------\n");
    //////////////////// DEBUG ////////////////////
}

//������� ������ �ùٸ���?
//false : �������� 2���̻�
//true : �������� 0, 1��
bool isRight(string flagStr) {
    pr("%s!!!!!!!!!!!!!!!!!!!!!!\n", tc(flagStr)); //DEBUG
    //���� �����ġ���� �ֺ� 4�������� �̵����� ����
    bool move[MAX][MAX][4] = { true };
    //������ġ
    int fx = flagStr[0], fy = flagStr[1]; 

    //1. ���漱�� �о moveüũ
    rrep(idx, 1, len(flagStr) / 2) {
        //������ġ
        int fxx = flagStr[idx * 2]; 
        int fyy = flagStr[idx * 2 + 1];
        //0:�� 1:�� 2:�� 3:��
        pii p1, p2; //���漱�� ���̿��� �� ĭ�� ��ġ
        mp(fx, fy) < mp(fxx, fyy) ? p2 = mp(fx, fy) : p2 = mp(fxx, fyy);
        p1 = p2;

        //���α��漱 : x��ǥ ������
        if (fx == fxx) { 
            p1.first--; 
            move[p1.first][p1.second][0] = false; //���漱�� ����������
            move[p2.first][p2.second][2] = false;
        }
        //���α��漱 : y��ǥ ������
        if (fy == fyy) { 
            p1.second--; 
            move[p1.first][p1.second][3] = false;
            move[p2.first][p2.second][1] = false;
        }

        fx = fxx; //������ġ ���
        fy = fyy;
    }

    //2. ��� ������ �ִ� ��ġ���� BFS�� ����
    rep(idx, sz(animalList)) {
        bool visited[MAX][MAX] = { false }; //BFS�� ���� �湮üũ�迭
        bool num[27] = { false }; //������ȣ(1~26) üũ
        qii loc; //��ǥ
        qs animal; //������ ����Ʈ(���ݱ��� ��ģ)

        int startX, startY;
        tie(startX, startY) = animalList[idx]; //������ġ�� �������ִ� ��ġ��.
        loc.ph(mp(startX, startY));
        map[startX][startY] != 0 ? animal.ph(ts(map[startX][startY])) : animal.ph(""); //������ ����Ʈ�� �߰�
        visited[startX][startY] = true;

        pr("%d, %d@@@@@@@@@@@@\n", startX, startY);
        while (!loc.empty()) {
            //������ġ x,  y
            int x, y;
            tie(x, y) = loc.F();
            loc.P();
            string s = animal.F();
            animal.P();

            //3. ���� �����ϸ� Ȯ��
            if (x == N - 1 && y == N - 1) {
                pr("%s?????????????\n", tc(s)); //DEBUG

                //���ݱ��� ������ ��������Ʈ(���� ����)�� Ȯ��
                int animalCnt = 0; //���泻�� ������ ����
                rep(i, len(s)) {
                    int number = s[i] - '0';
                    num[number] = true; //1~26�� �ش� �ϴ°Ϳ� üũ
                }

                rrep(i, 1, 27) //üũ�� ���� ���� ���
                    if (num[i])
                        animalCnt++; 

                pr(">> %d\n", animalCnt); //DEBUG
                if (animalCnt >= 2) //���泻�� 2���̻� �� �����ϸ� �ȵȴ�.
                    rt false;
            }

            rep(dir, 4) {
                //������ġ xx, yy
                int xx = x + dxy[dir][0];
                int yy = y + dxy[dir][1];
                //1. �ùٸ� �ε����ΰ�
                if (xx < 0 || yy < 0 || xx == N || yy == N) ct;
                string ss = s + ts(map[xx][yy]);
                printf("%s##############\n", tc(ss));

                //3. ������ġ x,y���� dir�������� �̵��� �Ұ����ϸ� ����
                if (!move[x][y][dir]) ct;

                //2. �湮�߾����� ����
                if (visited[xx][yy]) ct;

                visited[xx][yy] = true;
                loc.ph(mp(xx, yy));
                animal.ph(ss);
            }
        }
    }
    //��� ������ġ���� BFS������
    //�� ���泻�� 2���̻��� ������ �������� ������ true ����
    rt true;
}

//DFS������� flag�� 0,0���� N+1,N+1���� Ž��
void func() {
    bool visited[MAX][MAX] = {false}; //DFS�� ���� �湮üũ�迭
    sii loc;
    ss flagStr;
    loc.ph(mp(0, 0));
    visited[0][0] = true;
    flagStr.ph("00");

    while (!loc.empty()) {
        int x, y;
        tie(x, y) = loc.T();
        loc.P();
        string s = flagStr.T();
        flagStr.P();

        //���漱�� �ϼ��߰�, �ùٸ��ٸ� ����� ����
        if (x == N && y == N && isRight(s)) {
            print(s);
            rt;
        }

        rep(dir, 4) {
            int xx = x + dxy[dir][0];
            int yy = y + dxy[dir][1];

            //1. �ε��� Ȯ��
            if (xx < 0 || yy < 0 || xx == N + 1 || yy == N + 1) ct;

            //2. �湮�߾����� ����
            if (visited[xx][yy]) ct;
            visited[xx][yy] = true;
            string ss = s + ts(xx) + ts(yy);
            loc.ph(mp( xx, yy ));
            flagStr.ph(ss);
        }
    }
    //���漱�� ������ ���ߴٸ� no ���
    pr("no"); 
}



int main(void) {
    init();
    func();

    rt 0;
}