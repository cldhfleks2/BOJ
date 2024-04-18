#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
#define MAX 50
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
int map[MAX][MAX];
bool visited[MAX][MAX];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
void init();
void func();
pii bfs(int start_x, int start_y);
void reset();
void init() {
    scanf("%d%d", &N, &M);
    for (int i = 0; i < N; i++) {
        for (int j = 0, temp; j < M; j++) {
            scanf("%d", &temp);
            map[i][j] = temp;
        }
    }
}

void func() {
    pii res = {0, 0};
    for (int x = 0; x < N; x++) {
        for (int y = 0; y < M; y++) {
            if (map[x][y] == 0) continue; //시작위치가 0이면 불가능
            pii values = bfs(x, y);
            if (res.first < values.first) //길이가 더 긴것은 무조건 추가
                res = values;
            else if (res.first == values.first && 
                res.second < values.second) //길이가 같은것이면 숫자합이 큰것으로
                res = values;
        }
    }
    printf("%d", res.second);
}


//x,y에서 출발하는 가장 긴 경로의길이, 숫자합을 구함
pii bfs(int start_x, int start_y) {
    reset();
    queue<pii> pass;
    pass.push({ start_x, start_y });
    visited[start_x][start_y] = true;
    int len = 0;
    int max = 0;
    while (!pass.empty()) {
        len++;
        int size = pass.size();
        while (size--) {
            //현재 길이(len)에서의 숫자 최댓값을 구함
            //반복하다보면 끝방에서의 숫자 최댓값이 max에 담김.
            int x = pass.front().first;
            int y = pass.front().second;
            pass.pop();
            max = map[x][y];
            for (int dir = 0; dir < 4; dir++) {
                int xx = x + dx[dir];
                int yy = y + dy[dir];
                if (xx < 0 || yy < 0 || xx == N || yy == M ||
                    visited[xx][yy] || map[xx][yy] == 0) continue;

                visited[xx][yy] = true;
                if (max < map[xx][yy]) max = map[xx][yy]; //최댓값을 구함
                pass.push({xx, yy});
            }
        }
        
    }
    return { len, map[start_x][start_y] + max };
}

void reset() {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            visited[i][j] = false;
}

int main(void) {
    init();
    func();


    return 0;
}