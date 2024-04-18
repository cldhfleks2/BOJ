#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
using std::vector; using std::stack; using std::queue; using std::deque; using std::tuple;
using std::string; using std::pair; using std::make_tuple; using std::tie;
using std::sort; using std::swap;
using std::make_pair; using std::max_element; using std::min_element; using std::bitset; using std::to_string;
using std::fill; using std::priority_queue; using std::greater;
//using std::max; using std::min; using std::map;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, int> pdi;
typedef pair<int, double> pid;
typedef pair<double, double> pdd;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;
typedef pair<int, char> pic;
typedef pair<char, int> pci;
typedef pair<string, int> psi;
typedef pair<int, string> pis;
typedef pair<string, string> pss;

int N;
vector<int> num; //0~9
vector<int> op; //1:+  2:-  3:*
vector<string> Log;
ll max = INT32_MIN; //출력할 최댓값

void func();
void picked(vector<int>& n, vector<int>& o, vector<int>& index, vector<pair<vector<int>, vector<int>>>& list);
void debug(int n, vector<int>& a, vector<int>& b, ll r);
string makeLog(vector<int>& a, vector<int>& b);
bool exist(string s);
ll polynomialCalculate(vector<int>& NUM, vector<int>& OP);
ll calculate(vector<int>& n, vector<int>& o, vector<int>& opIndex, vector<pair<vector<int>, vector<int>>>& list);
int monomialCalculate(int left, int right, int OP);
void init();

void init() {
    scanf("%d", &N);
    char o;
    scanf("%c", &o); //줄바꿈문자 제거
    for (int i = 0; i < N; i++) {
        char o;
        scanf("%c", &o);
        if (i % 2) //기호
            if (o == '+')
                op.push_back(1);
            else if (o == '-')
                op.push_back(2);
            else
                op.push_back(3);
        else //숫자
            num.push_back(o - '0');
    }
}

//두 숫자를 OP연산기호(숫자로 대체)로 계산한값 리턴
int monomialCalculate(int left, int right, int OP) {
    if (OP == 1) //+
        return left + right;
    else if (OP == 2) //-
        return left - right;
    else if (OP == 3) //*
        return left * right;
}

//괄호를 풀고 전체적인 연산흐름을 맡음
ll calculate(vector<int>& n, vector<int>& o, vector<int>& opIndex,
    vector<pair<vector<int>, vector<int>>>& list) {
    vector<int> NUM, OP;
    //1-1. 괄호안의 수식을 먼저 계산
    //left, right : 괄호안 두 숫자. 연산기호를 기준으로 좌,우 두 숫자
    bool prevBrace = false;
    //전체 연산기호 탐색
    for (int i = 0; i < o.size(); i++) {
        bool findIndex = false;
        //그 중 선택한 연산기호를 탐색
        for (int j = 0; j < opIndex.size(); j++) {
            if (i == opIndex[j]) { //괄호안 연산기호였다.
                findIndex = true;
                break;
            }
        }

        //괄호안 연산기호 라면
        if (findIndex) {
            //NUM에 괄호안을 계산한숫자추가,  OP에 연산기호추가X
            int left{ n[i] }, right{ n[i + 1] }; //두 숫자
            NUM.push_back(monomialCalculate(left, right, o[i])); //괄호를 계산해서 NUM에 추가
            prevBrace = true;
        }
        else { //괄호밖 연산기호 라면
            if (prevBrace) { //바로직전에 괄호를 계산 했었다면
                //NUM에 num[i]숫자추가X,  OP에 연산기호추가O
                OP.push_back(o[i]);
                prevBrace = false; //체크 해제
            }
            else {
                //NUM에 num[i]숫자추가O,  OP에 연산기호추가O
                NUM.push_back(n[i]);
                OP.push_back(o[i]);
            }
        }

        //마지막인덱스이고 괄호가 아니면 마지막 숫자를 NUM에 추가해줘야함
        if (i == o.size() - 1 && !findIndex)
            NUM.push_back(n[o.size()]);
    }
    //debug(22, NUM, OP, polynomialCalculate(NUM, OP));

    //이전에 만들어진적 있는 수식이면 제외
    string s = makeLog(NUM, OP);
    if (exist(s))
        return INT32_MIN;
    else { //아니면 기록
        Log.push_back(s);
        //만들어진 NUM과 OP수식을 베이스로 이어서 괄호를 추가해보자.
        if (OP.size() != 1)
            list.push_back({ NUM, OP });
    }
    
    //2. 괄호를 푼 수식을 계산해서 리턴
    ll res = polynomialCalculate(NUM, OP);

    return res;
}

bool exist(string s) {
    for (int i = 0; i < Log.size(); i++)
        if (s.compare(Log[i]) == 0)
            return true;
    return false;
}

//전체 수식을 계산하여 리턴
//곱하기를 먼저계산한다.
ll polynomialCalculate(vector<int>& NUM, vector<int>& OP) {
    //vector<int> A, B;
    //복사
    //for (int i = 0; i < NUM.size(); i++) A.push_back(NUM[i]);
    //for (int i = 0; i < OP.size(); i++) B.push_back(OP[i]);
    ////1-2.
    //while (1) { //곱하기 기호를 발견하지 못할때 까지 반복
    //    bool findMultiple = false;
    //    for (int i = 0; i < B.size(); i++) {
    //        //1-3.
    //        if (B[i] == 3) {
    //            findMultiple = true;
    //            int left{ A[i] }, right{ A[i + 1] };
    //            //printf("3>> left:%d right:%d\n", left, right);
    //            //1-4.
    //            //left위치에 left,right곱한 결과를 덮어씌우고
    //            //right원소(A[i + 1])를 삭제
    //            //B[i] 도 삭제
    //            A[i] = monomialCalculate(left, right, 3); //곱하기 연산실행
    //            A.erase(A.begin() + i + 1); //right숫자 삭제
    //            B.erase(B.begin() + i); //곱연산기호 삭제
    //        }
    //    }
    //    //1-5.
    //    if (!findMultiple)
    //        break;
    //}

    //ll res = A[0];
    //for (int i = 1; i < A.size(); i++)
    //    res = monomialCalculate(res, A[i], B[i - 1]);
    //return res;

    ll res = NUM[0];
    for (int i = 1; i < NUM.size(); i++)
        res = monomialCalculate(res, NUM[i], OP[i - 1]);
    return res;
}

string makeLog(vector<int>& a, vector<int>& b) {
    string s;
    for (int i = 0; i < a.size(); i++)
        s += a[i] + " ";
    for (int i = 0; i < b.size(); i++)
        s += b[i] + " ";

    return s;
}

//두 벡터의 내용을 출력 - 확인용
void debug(int n, vector<int>& a, vector<int>& b, ll r) {
    printf("%d>> ", n);
    bool A = true, B = true;
    int idxA = 0, idxB = 0;
    int lenA = a.size(), lenB = b.size();

    while (1) {
        if (A)
            printf("%d ", a[idxA]);
        if (B)
            if (b[idxB] == 1)
                printf("+ ");
            else if (b[idxB] == 2)
                printf("- ");
            else if (b[idxB] == 3)
                printf("* ");
        idxA++;
        idxB++;
        if (idxA == lenA) A = false;
        if (idxB == lenB) B = false;
        if (!A && !B) break;
    }

    printf("= %lld\n", r);
}

//괄호를 추가해서 수식을 계산해본다.
//서로 인접하지않도록 연산기호를 선택(괄호를 추가하는것)하는 모든 경우의수에서
//각각 경우마다의 계산결과의 최댓값을 max로 갱신
void picked(vector<int> &n, vector<int> &o, vector<int>& index, 
    vector<pair<vector<int>, vector<int>>> &list) {
    if (n.size() == 1 || o.size() == 0) return; //괄호를 여럿겹칠때 종료조건

    //1. 2개이상 연산기호를 pick할때 각 연산기호가 서로 인접하면 안됨.
    bool pass = false;
    if (index.size() >= 2) {
        //선택한 두개의 연산기호가 서로 인접한지 확인
        for (int i = 0; i < index.size(); i++) {
            int prevIndex = index[i];
            for (int j = i + 1; j < index.size(); j++) {
                int nextIndex = index[j];
                if (nextIndex - prevIndex == 1) { //서로 인접하다면
                    pass = true;
                    break;
                }
            }
        }
    }
    if (pass) return; //서로 인접한 연산기호를 사용하는 경우는 제외

    //2. 현재까지 담은 오퍼레이터만큼 결과를 계산
    if (!index.empty()) {
        ll res = calculate(n, o, index, list);
        if (max < res) max = res;
    }

    //if (!index.empty()) { //괄호를 추가하지않고 계산하는경우는 아래 func()에서 미리 해두었음
    //    ll res = calculate(n, o, index, list);
    //    if (max < res) max = res;
    //}
    //3. OP의 연산기호를 여럿 선택하는 경우의수를 재귀 방법으로 구현
    int smallest = index.empty() ? 0 : index.back() + 1; //index에들어간 인덱스의 바로 다음 인덱스
    for (int i = smallest; i < op.size(); i++) {
        index.push_back(i);
        picked(n, o, index, list);
        index.pop_back();
    }
}

void func() {
    //하나의 연산기호를 pick하는것이 괄호를 만드는것.
    //다만, 서로 인접한 연산기호를 선택한다면 괄호를 여러개 만들지 못함.
    //서로 인접하지않은 연산기호를 pick 해야한다.
    //pick 한뒤 각각 경우마다의 최댓값을 구해본다.
    vector<pair<vector<int>, vector<int>>> list;
    list.push_back({ num, op });

    int de = -1;
    while (!list.empty()) {
        de++;
        //printf("%d========================\n", de);
        vector<int> index, n, o;
        n = list.back().first;
        o = list.back().second;
        list.pop_back();
        //괄호를 추가하지 않은채로 계산
        ll res = polynomialCalculate(n, o);
        if (max < res) max = res;
        string s = makeLog(n, o);
        Log.push_back(s);
        //if (!exist(s)) { 
        //    ll res = polynomialCalculate(n, o); 
        //    if (max < res) max = res;
        //    Log.push_back(s);
        //}
        //else {
        //    continue;
        //}

        //괄호를 추가해서 계산
        picked(n, o, index, list);
    }

    printf("%lld", max); //구한 최댓값
}

int main(void) {
    init();
    func();

    return 0;
}