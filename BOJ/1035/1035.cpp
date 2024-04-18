#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
#define MAX 100001
using std::vector; using std::stack; using std::queue;
using std::deque; using std::string; using std::pair;
using std::sort; using std::max; using std::min; using std::make_pair; using std::max_element; using std::min_element; using std::fill;
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

bool map[5][5]; //true:조각상위치
bool visited[5][5][5];
vector<pii> pieces;
void init();
void func();

void init() {
    for (int i = 0; i < 5; i++) {
        char c;
        scanf("%c", &c); //줄바꿈문자 제거
        for (int j = 0; j < 5; j++) {
            scanf("%c", &c);
            if (c == '*') {
                map[i][j] = true;
                pieces.push_back({ i, j }); //조각위치 저장
            }
            else
                map[i][j] = false;
        }
    }
}

void func() {

}

void reset() {
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            for (int k = 0; k < 5; k++)
                visited[i][j][k] = false;
}

int main(void) {
    init();
    func();


    return 0;
}