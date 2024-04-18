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
#define ms(a) memset(a, 0, sizeof(a)) //0으로 초기화
#define rep(i, n) for(int i = 0; i < n ; i++)
#define rrep(i, r, n) for(int i = r; i < n ; i++)
#define _rrep(i, r, n) for(int i = r; i >= n; i--)
#define each(x, a) for (auto& x: a)
#define all(x) (x).begin(),(x).end() //sort등에서 컨테이너 전체를 처리해야할때 사용
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
template <class T> inline T sq(T num) { rt num* num; }//제곱함수
template <class T> inline T GCD(T num1, T num2) { if (num2 == 0) rt num1; rt GCD(num2, num1 % num2); }
template <class T> inline T LCM(T num1, T num2) { if (num1 == 0 || num2 == 0) rt num1 + num2; rt num1* (num2 / GCD(num1, num2)); }
//STL 전용 초기화 함수들 ( ms~~ )
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
vii bowl[MAX]; //물고기수, 어항을 회전해서 쌓일때 쓰일 인덱스
int check[MAX][MAX]; //물고기를 분배할때 쓰일 배열

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

//v의 최댓값 최솟값을 리턴
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

//어항을 왼쪽정렬한다.
//start ~ end-1 인덱스까지의 모든 어항을 전부 좌측으로 옮김
//실제크기는 end - start
//옮긴후 0 ~ (end-start)-1 인덱스로 정렬될것
void leftAlignment(vii(&v)[MAX], int start, int end) {
    //1. 좌측으로 옮김
    int left = 0;
    rrep(i, start, end) { //start인덱스부터 left에 쌓음
        v[left] = v[i]; //복사
        left++;
    }

    //2. 우측에 남은것을 지움
    rrep(i, left, end)  //우측에 기존에있던 어항을 지움
        v[i].clear();
}

//좌측 쌓여진 어항을 공중부양시킨뒤 회전후 우측어항위에 쌓는 함수
//size : 전체 어항의 가로 길이
//완성뒤 전체 어항의 가로 길이를 리턴
int levitateRotate90Stacking(vii (&v)[MAX], int size) {
    int widthSize = size; //전체 어항들의 가로 길이

    while (1) {
        //1. 공중부양 시킬 좌측 어항더미(최소2개이상 쌓인 어항들)를 선택
        int right = -1; //공중부양시킬 열인덱스중 가장 오른쪽것
        int chooseSize;
        rep(i, N) 
            if (v[i].size() >= 2)
                right = i;
            else
                br; //좌측 어항더미는 연속되있으므로.. 쌓여지지않은 어항을 만나면 종료
        chooseSize = right + 1;

        //2. 선택한 어항더미에 인덱스(second값)를 부여함
        //어항더미들의 쌓여진 최대높이를 구해놔야함(4번에서 쓰임)
        int chooseHeightSize = -1; //90도 돌렸을때 어항더미들의 가로 최대 길이.
        rep(i, chooseSize) {
            if (chooseHeightSize < sz(v[i])) chooseHeightSize = sz(v[i]);
            rep(j, sz(v[i]))
                v[i][j].second = j; //해당열의 쌓아진순서대로 0, 1, 2, 3..
        }

        //3. 나머지 어항들의 길이계산
        int remainingSize = widthSize - chooseSize;

        //4. 어항더미를 위에 쌓을 수 없다면 중단
        if (chooseHeightSize > remainingSize) {
            //모든 어항의 second값을 -1로 초기화후 중단
            rep(i, remainingSize) 
                rep(j, sz(v[i]))
                v[i][j].second = -1;
            br; 
        }

        //5. 나머지 어항들(열)에 인덱스를 부여함
        int maxIndex = -1;
        int idx = 0; //왼쪽부터 0, 1, 2, 3..
        rrep(i, right + 1, widthSize) {
            rep(j, sz(v[i])) {
                v[i][j].second = idx; 
            }
            idx++;
        }
        idx = 0;

        //6. 공중부양시키고 90도 회전한 어항을 나머지 어항위에 쌓기
        //공중부양시킨 더미 i
        //v[i][j].second를 idx로, 
        //v[i][j].second이 같은곳에 쌓음 된다.
        //right -> 0 역순으로 쌓아야함. 
        _rrep(i, right, 0) {
            rep(j, sz(v[i])) {
                int value = v[i][j].first; //물고기수
                idx = v[i][j].second; //인덱스
                v[chooseSize + idx].pb(mp(value, -1)); //second는 이제 초기화할 값임
            }
        }

        //7. 이동시킨후 기존에있던 자리의 어항더미들을 삭제
        //0 ~ right까지 어항을 전부 삭제
        rep(i, right + 1) v[i].clear();

        //8. 전체 어항을 좌측정렬
        //right + 1 ~ bottomSize - 1까지
        leftAlignment(v, right + 1, widthSize);

        //9. 모든어항의 second값을 -1로 초기화
        rep(i, remainingSize)
            rep(j, sz(v[i])) 
                v[i][j].second = -1;

        //10. 전체어항의 가로길이를 다시 구함
        widthSize = remainingSize;
    }

    rt widthSize;
}

//모든인접한 어항간의 물고기 분배
int dxy[][2] = { {0, 1}, {0, -1}, {-1, 0}, {1, 0} };
void fishDivide(vii (&v)[MAX], int size) {
    int sizeX = size;
    rep(i, MAX)
        ms(check[i]); //전체 초기화

    //1.두 인접어항의 분배해야할 물고기수를 check에 저장
    rep(i, sizeX) {
        int sizeY = sz(v[i]);
        rep(j, sizeY) {
            rep(dir, 4) {
                int x = i + dxy[dir][0]; //인접한 어항의 좌표
                int y = j + dxy[dir][1];
                int d; //두 어항의 물고기수 차이를 5로나눈 몫 
                int gap; //인접한어항과의 물고기수 차이 v[현재] - v[인접]이 양수여야함

                //1-1. x,y위치가 잘못된 인덱스거나 어항이 존재하지않으면 제외
                //위쪽 : 현재 어항이 가장 상단에 있으면 인접한 어항이 없음
                //아래쪽 : 현재 어항이 가장 하단이면 인접한 어항이 없음
                //왼쪽 : 현재 어항이 가장 좌측에 있으면 인접한 어항이 없음, 바로 왼쪽에 어항이 쌓인높이가 j이상 되어야 물고기 분배가능
                //오른쪽 : 위와 동일(방향만 오른쪽)
                if (x == -1 || y == -1 || x == sizeX || y == sizeY) ct;
                if ( (dir == 2 || dir == 3) && (j > sz(v[x]) - 1) ) ct; //옆의 어항의 높이가 현재 어항의 높이보다 낮으면 없는것

                gap = v[i][j].first - v[x][y].first; 
                d = gap / 5;
                if (gap > 0) { //물고기수가 더많은데서 더적은데로만 옮긴다.
                    check[i][j] -= d; //현재위치에서 물고기를빼서
                    check[x][y] += d; //인접한 어항에 분배
                }
            }
        }
    }

    //2. 계산한 분배수를 실제 어항에 적용
    rep(i, sizeX) {
        int sizeY = sz(v[i]);
        rep(j, sizeY) {
            v[i][j].first += check[i][j]; //위에서 계산한 물고기 분배갯수를 실제로 적용
        }
    }
}

//어항을 모두 평평하게 펼친다.
//완성후 어항의 가로길이 리턴
int unfold(vii (&v)[MAX], int sizeX) {
    vii res[MAX];
    int idx = 0; //바닥에 놓여질 위치 인덱스

    //1. res에 어항을 펼친다.
    rep(i, sizeX) {
        int sizeY = sz(v[i]);
        rep(j, sizeY) {
            res[idx].pb(v[i][j]); //idx위치로 옮김
            idx++;
        }
    }

    //2. 원래 있던 모든 어항을 없앰
    rep(i, sizeX)
        v[i].clear();

    //3. 펼쳐진 어항들을 res에서 v로 옮김
    rep(i, idx)
        v[i].pb(res[i][0]);

    rt idx;
}

//절반을 떼서 180도 회전후 쌓고 다시 절반을떼서 180회전후 다시 쌓음
//완성뒤 전체 어항의 가로길이 리턴
int levitateRotate180Stacking(vii (&v)[MAX], int size) {
    int widthSize = size;

    //1. 절반을 선택해서 나머지 절반위에 180도 회전후 쌓음
    int halfSize = widthSize / 2;
    rep(i, halfSize) {
        //i -> (widthSize-i-1)열에 추가
        v[widthSize - i - 1].pb(v[i][0]);
    }

    //2. 좌로 정렬
    leftAlignment(v, halfSize, widthSize);
    widthSize = halfSize; //전체크기 다시 계산

    //3. 다시 절반을 선택해서 나머지 절반위에 180도 회전후 쌓음
    halfSize = widthSize / 2;
    rep(i, halfSize) {
        //좌측 절반 어항더미중
        //맨위 어항한줄을 옮기고 그다음 바닥 어항한줄을 옮김
        //i -> (widthSize-i-1)열에 추가
        v[widthSize - i - 1].pb(v[i][1]); //맨위 어항
        v[widthSize - i - 1].pb(v[i][0]); //바닥 어항
    }

    //4. 좌로 정렬
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

//프로그램의 중심
void func() {
    int res = 0; //어항정리 횟수
    while (1) { //어항정리하자
        int widthSize = N;
        int max, min;
        tie(max, min) = findMAXMIN(bowl);
        if (max - min <= K) br;

        //1. 최솟값인 어항에 물고기 + 1
        rep(i, N)
            if (min == bowl[i][0].first)
                bowl[i][0].first++;

        //2. 어항을 쌓아올림
        //2-1. 가장좌측 어항 하나를 그 오른쪽 어항위에 쌓음
        int value = bowl[0][0].first; //어항의 물고기수
        bowl[1].pb(mp(value, -1)); //그 오른쪽 어항위에 쌓음
        bowl[0].clear(); //옮겼으니 기존위치의 어항을 비움

        //2-2. 쌓고난뒤 어항을 좌로정렬
        //총 N-1개의 어항을 0번인덱스부터 시작하도록 옮길것
        leftAlignment(bowl, 1, widthSize);
        widthSize -= 1;

        //2-3. 어항을 좌측부터 최소2개이상 쌓아진 더미를 회전시켜서 쌓아올림
        //N-1개의 어항..(가로길이)
        widthSize = levitateRotate90Stacking(bowl, widthSize);

        //3. 물고기수 조절
        fishDivide(bowl, widthSize);

        //4. 쌓여있는 어항들을 바닥에 일자로 펼친다.
        widthSize = unfold(bowl, widthSize) ;

        //5. 두번에걸쳐 절반씩 좌측에 우측에 쌓음
        widthSize = levitateRotate180Stacking(bowl, widthSize);

        //6. 다시 물고기수 조절
        fishDivide(bowl, widthSize);
  
        //7. 다시 쌓여있는 어항들을 바닥에 일자로 펼친다.
        widthSize = unfold(bowl, widthSize);

        res++; //찾고자하는 어항 정리 횟수
    }

    pr("%d", res);
}

int main(void) {
    init();
    func();

    rt 0;
}