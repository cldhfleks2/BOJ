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
typedef pair<string, int> psi;
typedef pair<int, string> pis;
typedef pair<string, string> pss;

int R, C;
char** map;
bool alphabet[26];
int res = 0;
int dx[] = {0, 1, 0, -1};
int dy[] = { 1, 0, -1, 0 };

void init();
void func();
void dfs(int x, int y, int cnt);
void init() {
    scanf("%d%d", &R, &C);
    map = new char* [R];
    for (int i = 0; i < R; i++) {
        char c;
        scanf("%c", &c); //ÁÙ¹Ù²Þ¹®ÀÚ Á¦°Å
        map[i] = new char[C];
        for (int j = 0; j < C; j++) {
            scanf("%c", &c);
            map[i][j] = c;
        }
    }
}

void func() {
    alphabet[map[0][0] - 'A'] = true;
    dfs(0, 0, 1);
    printf("%d", res);
}

void dfs(int x, int y, int cnt) {
    if (cnt > res) res = cnt;

    for (int d = 0; d < 4; d++) {
        int xx = x + dx[d];
        int yy = y + dy[d];
        if (xx < 0 || yy < 0 || xx == R || yy == C || alphabet[map[xx][yy] - 'A']) continue;
        alphabet[map[xx][yy] - 'A'] = true; //Å½»öÀü Ã¼Å©
        dfs(xx, yy, cnt + 1); //Å½»ö
        alphabet[map[xx][yy] - 'A'] = false; //Å½»öÈÄ Ã¼Å© ÇØÁ¦
    }
}

int main(void) {
    init();
    func();


    return 0;
}