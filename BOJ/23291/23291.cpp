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
#define MAX 101
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

int N, K;
vii bowl[MAX]; //������, ������ ȸ���ؼ� ���϶� ���� �ε���
int check[MAX][MAX]; //����⸦ �й��Ҷ� ���� �迭

void func();
//void DEBUG(vii(&v)[MAX], int size, string s);
int levitateRotate180Stacking(vii(&v)[MAX], int size);
int unfold(vii(&v)[MAX], int sizeX);
void fishDivide(vii(&v)[MAX], int sizeX);
int levitateRotate90Stacking(vii(&v)[MAX], int size);
void leftAlignment(vii(&v)[MAX], int start, int end);
pii findMAXMIN(vii(&v)[MAX]);
void init();

void init() {
    sc("%d%d", &N, &K);
    rep(i, N) {
        int in;
        sc("%d", &in);
        bowl[i].pb(mp(in, -1));
    }
}

//v�� �ִ� �ּڰ��� ����
pii findMAXMIN(vii (&v)[MAX]) {
    int max = IMIN;
    int min = IMAX;
    rep(i, N) {
        int element = v[i][0].first;
        if (max < element) max = element;
        if (min > element) min = element;
    }

    rt mp(max, min);
}

//������ ���������Ѵ�.
//start ~ end-1 �ε��������� ��� ������ ���� �������� �ű�
//����ũ��� end - start
//�ű��� 0 ~ (end-start)-1 �ε����� ���ĵɰ�
void leftAlignment(vii(&v)[MAX], int start, int end) {
    //1. �������� �ű�
    int left = 0;
    rrep(i, start, end) { //start�ε������� left�� ����
        v[left] = v[i]; //����
        left++;
    }

    //2. ������ �������� ����
    rrep(i, left, end)  //������ �������ִ� ������ ����
        v[i].clear();
}

//���� �׿��� ������ ���ߺξ��Ų�� ȸ���� ������������ �״� �Լ�
//size : ��ü ������ ���� ����
//�ϼ��� ��ü ������ ���� ���̸� ����
int levitateRotate90Stacking(vii (&v)[MAX], int size) {
    int widthSize = size; //��ü ���׵��� ���� ����

    while (1) {
        //1. ���ߺξ� ��ų ���� ���״���(�ּ�2���̻� ���� ���׵�)�� ����
        int right = -1; //���ߺξ��ų ���ε����� ���� �����ʰ�
        int chooseSize;
        rep(i, N) 
            if (v[i].size() >= 2)
                right = i;
            else
                br; //���� ���״��̴� ���ӵ������Ƿ�.. �׿��������� ������ ������ ����
        chooseSize = right + 1;

        //2. ������ ���״��̿� �ε���(second��)�� �ο���
        //���״��̵��� �׿��� �ִ���̸� ���س�����(4������ ����)
        int chooseHeightSize = -1; //90�� �������� ���״��̵��� ���� �ִ� ����.
        rep(i, chooseSize) {
            if (chooseHeightSize < sz(v[i])) chooseHeightSize = sz(v[i]);
            rep(j, sz(v[i]))
                v[i][j].second = j; //�ش翭�� �׾���������� 0, 1, 2, 3..
        }

        //3. ������ ���׵��� ���̰��
        int remainingSize = widthSize - chooseSize;

        //4. ���״��̸� ���� ���� �� ���ٸ� �ߴ�
        if (chooseHeightSize > remainingSize) {
            //��� ������ second���� -1�� �ʱ�ȭ�� �ߴ�
            rep(i, remainingSize) 
                rep(j, sz(v[i]))
                v[i][j].second = -1;
            br; 
        }

        //5. ������ ���׵�(��)�� �ε����� �ο���
        int maxIndex = -1;
        int idx = 0; //���ʺ��� 0, 1, 2, 3..
        rrep(i, right + 1, widthSize) {
            rep(j, sz(v[i])) {
                v[i][j].second = idx; 
            }
            idx++;
        }
        idx = 0;

        //6. ���ߺξ��Ű�� 90�� ȸ���� ������ ������ �������� �ױ�
        //���ߺξ��Ų ���� i
        //v[i][j].second�� idx��, 
        //v[i][j].second�� �������� ���� �ȴ�.
        //right -> 0 �������� �׾ƾ���. 
        _rrep(i, right, 0) {
            rep(j, sz(v[i])) {
                int value = v[i][j].first; //������
                idx = v[i][j].second; //�ε���
                v[chooseSize + idx].pb(mp(value, -1)); //second�� ���� �ʱ�ȭ�� ����
            }
        }

        //7. �̵���Ų�� �������ִ� �ڸ��� ���״��̵��� ����
        //0 ~ right���� ������ ���� ����
        rep(i, right + 1) v[i].clear();

        //8. ��ü ������ ��������
        //right + 1 ~ bottomSize - 1����
        leftAlignment(v, right + 1, widthSize);

        //9. �������� second���� -1�� �ʱ�ȭ
        rep(i, remainingSize)
            rep(j, sz(v[i])) 
                v[i][j].second = -1;

        //10. ��ü������ ���α��̸� �ٽ� ����
        widthSize = remainingSize;
    }

    rt widthSize;
}

//��������� ���װ��� ����� �й�
int dxy[][2] = { {0, 1}, {0, -1}, {-1, 0}, {1, 0} };
void fishDivide(vii (&v)[MAX], int size) {
    int sizeX = size;
    rep(i, MAX)
        ms(check[i]); //��ü �ʱ�ȭ

    //1.�� ���������� �й��ؾ��� �������� check�� ����
    rep(i, sizeX) {
        int sizeY = sz(v[i]);
        rep(j, sizeY) {
            rep(dir, 4) {
                int x = i + dxy[dir][0]; //������ ������ ��ǥ
                int y = j + dxy[dir][1];
                int d; //�� ������ ������ ���̸� 5�γ��� �� 
                int gap; //�����Ѿ��װ��� ������ ���� v[����] - v[����]�� ���������

                //1-1. x,y��ġ�� �߸��� �ε����ų� ������ �������������� ����
                //���� : ���� ������ ���� ��ܿ� ������ ������ ������ ����
                //�Ʒ��� : ���� ������ ���� �ϴ��̸� ������ ������ ����
                //���� : ���� ������ ���� ������ ������ ������ ������ ����, �ٷ� ���ʿ� ������ ���γ��̰� j�̻� �Ǿ�� ����� �й谡��
                //������ : ���� ����(���⸸ ������)
                if (x == -1 || y == -1 || x == sizeX || y == sizeY) ct;
                if ( (dir == 2 || dir == 3) && (j > sz(v[x]) - 1) ) ct; //���� ������ ���̰� ���� ������ ���̺��� ������ ���°�

                gap = v[i][j].first - v[x][y].first; 
                d = gap / 5;
                if (gap > 0) { //�������� ���������� ���������θ� �ű��.
                    check[i][j] -= d; //������ġ���� ����⸦����
                    check[x][y] += d; //������ ���׿� �й�
                }
            }
        }
    }

    //2. ����� �й���� ���� ���׿� ����
    rep(i, sizeX) {
        int sizeY = sz(v[i]);
        rep(j, sizeY) {
            v[i][j].first += check[i][j]; //������ ����� ����� �й谹���� ������ ����
        }
    }
}

//������ ��� �����ϰ� ��ģ��.
//�ϼ��� ������ ���α��� ����
int unfold(vii (&v)[MAX], int sizeX) {
    vii res[MAX];
    int idx = 0; //�ٴڿ� ������ ��ġ �ε���

    //1. res�� ������ ��ģ��.
    rep(i, sizeX) {
        int sizeY = sz(v[i]);
        rep(j, sizeY) {
            res[idx].pb(v[i][j]); //idx��ġ�� �ű�
            idx++;
        }
    }

    //2. ���� �ִ� ��� ������ ����
    rep(i, sizeX)
        v[i].clear();

    //3. ������ ���׵��� res���� v�� �ű�
    rep(i, idx)
        v[i].pb(res[i][0]);

    rt idx;
}

//������ ���� 180�� ȸ���� �װ� �ٽ� ���������� 180ȸ���� �ٽ� ����
//�ϼ��� ��ü ������ ���α��� ����
int levitateRotate180Stacking(vii (&v)[MAX], int size) {
    int widthSize = size;

    //1. ������ �����ؼ� ������ �������� 180�� ȸ���� ����
    int halfSize = widthSize / 2;
    rep(i, halfSize) {
        //i -> (widthSize-i-1)���� �߰�
        v[widthSize - i - 1].pb(v[i][0]);
    }

    //2. �·� ����
    leftAlignment(v, halfSize, widthSize);
    widthSize = halfSize; //��üũ�� �ٽ� ���

    //3. �ٽ� ������ �����ؼ� ������ �������� 180�� ȸ���� ����
    halfSize = widthSize / 2;
    rep(i, halfSize) {
        //���� ���� ���״�����
        //���� ���������� �ű�� �״��� �ٴ� ���������� �ű�
        //i -> (widthSize-i-1)���� �߰�
        v[widthSize - i - 1].pb(v[i][1]); //���� ����
        v[widthSize - i - 1].pb(v[i][0]); //�ٴ� ����
    }

    //4. �·� ����
    leftAlignment(v, halfSize, widthSize);
    widthSize = halfSize;

    rt widthSize;
}

//void DEBUG(vii (&v)[MAX], int size, string s) {
//    printf("%s\n", tc(s));
//    int maxY = 0;
//    rep(i, size)
//        if (maxY < sz(v[i])) maxY = sz(v[i]);
//
//    _rrep(j, maxY-1, 0) {
//        rep(i, size) {
//            int sizeY = sz(v[i]);
//            if(j > sizeY - 1)
//                printf("     ");
//            else
//                printf("%3d  ", v[i][j].first);
//        }
//        printf("\n\n");
//    }
//}

//���α׷��� �߽�
void func() {
    int res = 0; //�������� Ƚ��
    while (1) { //������������
        int widthSize = N;
        int max, min;
        tie(max, min) = findMAXMIN(bowl);
        if (max - min <= K) br;

        //1. �ּڰ��� ���׿� ����� + 1
        rep(i, N)
            if (min == bowl[i][0].first)
                bowl[i][0].first++;

        //2. ������ �׾ƿø�
        //2-1. �������� ���� �ϳ��� �� ������ �������� ����
        int value = bowl[0][0].first; //������ ������
        bowl[1].pb(mp(value, -1)); //�� ������ �������� ����
        bowl[0].clear(); //�Ű����� ������ġ�� ������ ���

        //2-2. �װ��� ������ �·�����
        //�� N-1���� ������ 0���ε������� �����ϵ��� �ű��
        leftAlignment(bowl, 1, widthSize);
        widthSize -= 1;

        //2-3. ������ �������� �ּ�2���̻� �׾��� ���̸� ȸ�����Ѽ� �׾ƿø�
        //N-1���� ����..(���α���)
        widthSize = levitateRotate90Stacking(bowl, widthSize);

        //3. ������ ����
        fishDivide(bowl, widthSize);

        //4. �׿��ִ� ���׵��� �ٴڿ� ���ڷ� ��ģ��.
        widthSize = unfold(bowl, widthSize) ;

        //5. �ι������� ���ݾ� ������ ������ ����
        widthSize = levitateRotate180Stacking(bowl, widthSize);

        //6. �ٽ� ������ ����
        fishDivide(bowl, widthSize);
  
        //7. �ٽ� �׿��ִ� ���׵��� �ٴڿ� ���ڷ� ��ģ��.
        widthSize = unfold(bowl, widthSize);

        res++; //ã�����ϴ� ���� ���� Ƚ��
    }

    pr("%d", res);
}

int main(void) {
    init();
    func();

    rt 0;
}