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

int N, M;
int res = 1;
bool **map, ***visited;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
void init();
void func();
void bfs();
void init() {
    scanf("%d%d", &N, &M);
    visited = new bool** [N];
    map = new bool* [N];
    for (int i = 0; i < N; i++) {
        visited[i] = new bool*[M];
        map[i] = new bool[M];
        char c;
        scanf("%c", &c); //줄바꿈문자 제거
        for (int j = 0; j < M; j++) {
            scanf("%c", &c);
            c == '1' ? map[i][j] = true : map[i][j] = false;
            visited[i][j] = new bool[2];
            visited[i][j][0] = false;
            visited[i][j][1] = false;
        }
    }
}

void func() {
    bfs();
    printf("%d", res);
}

void bfs() {
    visited[0][0][0] = true;
    queue<pair<pii, pii>> pass; //<위치>, <지나온갯수,벽뚫은 횟수>
    pass.push({ {0, 0}, {res, 0} });
    while (!pass.empty()) {
        int x = pass.front().first.first;
        int y = pass.front().first.second;
        int cnt = pass.front().second.first;
        int crash = pass.front().second.second;
        pass.pop();

        if (x == N - 1 && y == M - 1) { //도착한경우
            res = cnt;
            return;
        }

        for (int dir = 0; dir < 4; dir++) {
            int xx = x + dx[dir];
            int yy = y + dy[dir];
            if (xx < 0 || yy < 0 || xx == N || yy == M) continue;

            //현재 벽위치에 있는경우
            //벽뚫은 1회만 허용
            if (map[xx][yy] == 1) { 
                if (crash >= 1) continue;
                visited[xx][yy][crash + 1] = true;
                pass.push({ {xx, yy}, {cnt + 1, crash + 1 } });
            }
            else {
                if (visited[xx][yy][crash]) continue;
                visited[xx][yy][crash] = true;
                pass.push({ {xx, yy}, {cnt + 1, crash} });
            }
            
        }
    }
    res = -1;
}

int main(void) {
    init();
    func();


    return 0;
}