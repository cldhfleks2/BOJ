#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using std::vector; using std::stack; using std::queue;
using std::deque; using std::string; using std::pair;
using std::sort;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;
typedef pair<int, char> pic;
typedef pair<char, int> pci;

int n;
int g;
vector<int> Fibonacci, res, grundy;
void init();
void makeFibonacci();
void makeGrundy(int start, int from);
vector<int> makeLack_of(vector<int> list);
bool needRebuildingList(vector<int> lack_of, vector<int> list);
vector<int> makeLack_of(vector<int> list);
vector<int> rebuildingList(vector<int> list);
void func();

void init() {
    scanf("%d", &n);
    makeFibonacci();
    vector<int> list;
    int max = 0;
    while (n--) {
        int p;
        scanf("%d", &p);
        if (max < p) max = p;
        list.push_back(p);
    }
    makeGrundy(4, max);
    for (int i = 0; i < list.size(); i++)
        g ^= grundy[list[i]];
}

//300만까지의 피보나치수를 구한다.
void makeFibonacci() {
    Fibonacci.push_back(1);
    Fibonacci.push_back(1);
    int idx = 2;
    while (1) {
        int value = Fibonacci[idx - 1] + Fibonacci[idx - 2];
        if (value > 3000000) break;
        Fibonacci.push_back(value);
        idx++;
    }
}

//1~p 까지 그런디수값을 구해서 res에 넣음
void makeGrundy(int start, int from) {
    //0~3까지는 기본값
    grundy.push_back(0); grundy.push_back(1); 
    grundy.push_back(2); grundy.push_back(3);
    int num = start;
    int fib_cnt = 1;
    while (1) {
        if (Fibonacci[fib_cnt] >= num)
            break;
        fib_cnt++;
    }
    vector<int> list;
    vector<int> lack_of;
    while (1) {
        /*
        * num : 현재 숫자
        * fib_cnt : 현재 숫자와 같거나 작은 피보나치수들의 갯수
        * list : 현재 숫자 num 을 num과 같거나 작은 피보나치수들로 빼서 만든 리스트
        *       즉, num에 1부터 fib_cnt만큼의 피보나치수들을 빼서 만든 리스트
        * lack_of : 그런디수 값을 찾는 과정에서 리스트에 존재하지않는 정수들로
        *       만든 리스트.
        *       0개 : 그런디값은 fib_cnt
        *       1개 : 바로이 값이 그런디값
        *       2개 이상 : lack_of내의 모든 원소를 기존 원소값들로 치환해야함.
        *                   lack_of를 치환하여 갱신한후에 다시 갯수체크를 진행
        * 
        * 구하는 순서
        * 1. fib_cnt갱신 : 현재 수 num이 피보나치수인지 확인. 맞다면 fib_cnt++;
        * 2. list 생성 : num에 피보나치수 들(fib_cnt 만큼)을 뺀후 남은 정수들로 생성
        * 3. lack_of 생성 : list에서 없는 정수들로 생성..
        * 4. lack_of 갯수 체크 : 리스트내의 원소갯수비교하여 위에서 만든 설명대로 진행
        * 5. 마무리 : list,lack_of초기화 grundy추가 num++;
        *               num이 300만초과시 반복문 종료
        *
        */
        // 1. fib_cnt 갱신
        int nextFib = Fibonacci[fib_cnt] + Fibonacci[fib_cnt - 1];
        //바로 Fibonacci[fib_cnt + 1]을 사용시, vector최대크기를 넘겨 오류 날 수 있음
        if (nextFib == num) 
            fib_cnt++;

        // 2. list 생성
        for (int i = 1; i <= fib_cnt; i++)
            list.push_back(num - Fibonacci[i]);

        // 3. lack_of 생성
        lack_of = makeLack_of(list);

        // 4. lack_of 갯수 체크
        while (1) {
            if (needRebuildingList(lack_of, list)) { //list를 치환해야 하는경우
                list = rebuildingList(list); //list 치환
                lack_of = makeLack_of(list);

            }
            else { //그런디수 계산 끝난상태
                break;
            }
        }

        // 5. 마무리
        //printf("%d >> grundy:%d, fib갯수:%d, nextFib:%d \n", num, grundy[num], fib_cnt, nextFib);
        //printf("\n====================================\n");
        //printf("%d >> %d , %d\n", num, grundy[num], fib_cnt);
        list.clear(); lack_of.clear(); num++;
        if (num > from) break;
    }
}

//list를 치환해야하는지 확인. lack_of의 원소갯수를 기준으로..
bool needRebuildingList(vector<int> lack_of, vector<int> list) {
    switch (lack_of.size()) {
    case 0:
        grundy.push_back(list.size()); //집합에 없는 바로다음수가 그런디수
        return false;
    case 1:
        grundy.push_back(lack_of[0]); 
        return false;
    default:
        return true;
    }
}

//list에 없는요소들로 lack_of를 만듦
vector<int> makeLack_of(vector<int> list) {
    sort(list.begin(), list.begin() + list.size()); //정렬
    int max = list[list.size() - 1]; //list 내의 최대크기의 원소
    vector<int> lack_of;
    for (int k = 0; k <= max; k++) { //리스트내의 원소값 범위
        bool find = false;
        for (int i = 0; i < list.size(); i++) { //리스트 순회
            if (k == list[i]) {
                find = true; //찾았음
                break;
            }
        }
        if (!find) //못찾은경우 해당 숫자 k를 lack_of에 추가
            lack_of.push_back(k);
    }
    //printf("\nlack_of 생성 , 크기:%d>> ", lack_of.size());
    //for (int i = 0; i < lack_of.size(); i++)
    //    printf("{%d}  ", lack_of[i]);
    //printf("\n");
    return lack_of;
}

//list의 모든 원소를 치환
vector<int> rebuildingList(vector<int> list) {
    vector<int> newList;
    //현재 lack_of의 모든원소를 그런디값으로 치환하여 새로운 list를 만듬
    //printf("list >> ");
    //for (int i = 0; i < list.size(); i++)
    //    printf("%d  ", list[i]);

    for (int i = 0; i < list.size(); i++) {
        int value = grundy[list[i]];
        bool find = false;
        for (int i = 0; i < newList.size(); i++)
            if (newList[i] == value) find = true;
        if (!find)
            newList.push_back(value); //중복값은 넣지 않음
    }

    //printf("\nlist 치환 >> ");
    //for (int i = 0; i < newList.size(); i++)
    //    printf("{%d}  ", newList[i]);
    //printf("\n");
    return newList;
}


void func() {
    g != 0 ? printf("koosaga") : printf("cubelover");

    vector<int> a;

    a.assign(3000, false);
}


int main(void) {
    init();
    func();

    return 0;
}