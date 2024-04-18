#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
#define MAX 1001
using std::vector; using std::stack; using std::queue;
using std::deque; using std::string; using std::pair;
using std::sort; using std::max; using std::min;
using std::make_pair; using std::max_element; using std::min_element;
using std::fill;
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
int p[MAX];
ll g;
int res;
void init();
void func();

void init() {
    scanf("%d", &N);
    for (int i = 0, temp; i < N; i++) {
        scanf("%d", &temp);
        p[i] = temp;
        g ^= temp; //초기 모든게임의 그런디수를 계산
    }
}

void func() {
    if (g == 0) { //초기에 전체게임의 그런디수가 0 이면 필패
        printf("0");
    }
    else {
        for (int i = 0; i < N; i++) { //돌무더기 하나 선택 => p[i]            for (int j = 0; j < N; j++)
            g = 0;
            for(int j = 0 ; j < N ; j++)
                if (i != j)
                    g ^= p[j]; //현재 돌무더기(p[i])제외한 나머지의 총 그런디수를 구함

            for (int j = 0; j < p[i]; j++) { //돌을 하나씩 빼봄
                ll pp = g;

                if (!(pp ^= j))  res++;
            }
        }
        printf("%d", res);
    }
}

int main(void) {
    init();
    func();


    return 0;
}