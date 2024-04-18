#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
#define MAX 10
using std::vector; using std::stack; using std::queue;
using std::deque; using std::string; using std::pair;
using std::sort; using std::make_pair;
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

int N, M;
int map[MAX][MAX]; //0:빈칸 1:벽 2:빨간공 3:파란공 4:구멍
bool visited[MAX][MAX][MAX][MAX]; //빨간공좌표,파란공좌표
int dx[] = {-1, 0, 1, 0}; //북-동-남-서순
int dy[] = {0, 1, 0, -1};
pii R, B, H;
int res = INT_MAX;
void init();
void func();
pii debug();
void init() {
    scanf("%d%d", &N, &M);
    for (int i = 0; i < N; i++) {
        char c;
        scanf("%c", &c);//줄바꿈문자 제거
        for (int j = 0; j < M; j++) {
            scanf("%c", &c);
            if (c == '#')
                map[i][j] = 1;
            else if (c == '.')
                map[i][j] = 0;
            else if (c == 'R') {
                map[i][j] = 2;
                R = { i, j };
            }
            else if (c == 'B') {
                map[i][j] = 3;
                B = { i, j };
            }
            else {
                map[i][j] = 4;
                H = { i, j };
            }
        }
    }
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            for (int k = 0; k < N; k++)
                for (int l = 0; l < M; l++)
                    visited[i][j][k][l] = false;
}



void func() {
    queue<pair<pii, pii>> q; //빨간공 파란공 위치
    queue<int> trys; //몇번 시도했는가
    q.push({ R, B });
    trys.push(0);
    visited[R.first][R.second][B.first][B.second] = true; //두 공의 시작위치 저장
    while (!q.empty()) {
        int rx = q.front().first.first;
        int ry = q.front().first.second;
        int bx = q.front().second.first;
        int by = q.front().second.second;
        int cnt = trys.front();
        q.pop();
        trys.pop();

        //보드 특징상 맨외곽은 벽으로 막혀있기에 벽체크만하면 out of index오류없음
        for (int dir = 0; dir < 4; dir++) {
            int rxx{ rx }, ryy{ ry }, bxx{ bx }, byy{ by };
            bool R_end{ false }, B_end = { false };
            bool R_hole{ false }, B_hole { false };
            //printf("시작>> - R:%d,%d  B:%d,%d :: ", rxx, ryy, bxx, byy);
            //1. 두 공을 이동 시킨다.
            while (1) {
                bool R_move{ false }, B_move{ false };
                if (!R_end) { //빨간공이 벽을 만나지않은경우 이동
                    rxx += dx[dir]; ryy += dy[dir]; //한칸 이동
                    //벽을 만난경우
                    if (map[rxx][ryy] == 1) {
                        rxx -= dx[dir]; ryy -= dy[dir]; //되돌림
                        R_end = true;
                    }
                    else {
                        R_move = true;
                    }
                }
                //1-1. 빨간 구슬이 구멍에 들어가는가
                if (H == make_pair(rxx, ryy)) R_hole = true;

                if (!B_end) { //빨간공이 벽을 만나지않은경우 이동
                    bxx += dx[dir]; byy += dy[dir];
                    if (map[bxx][byy] == 1) {
                        bxx -= dx[dir]; byy -= dy[dir]; //되돌림
                        B_end = true;
                    }
                    else {
                        B_move = true;
                    }
                }
                //1-2. 파란 구슬이 구멍에 들어가는가
                if (H == make_pair(bxx, byy)) B_hole = true;
                if (make_pair(rxx, ryy) == make_pair(bxx, byy)) {
                    //빨간공이 이동후 겹친경우 - 파란공이 벽에부딪힌 상태에서 빨간공이 이동한것
                    if (R_move) {
                        rxx -= dx[dir]; ryy -= dy[dir]; //되돌림
                        break; //이동 종료
                    }
                    else {
                        bxx -= dx[dir]; byy -= dy[dir];
                        break; //이동 종료
                    }
                }
                if (R_end && B_end) break;
            }

            //2. 빨간공과 파란공이 구멍에 들어간경우 - 탐색종료
            if (R_hole && B_hole) {
                //printf("%d >> dir: % d - 2\n", cnt + 1, dir);
                continue;
            }

            //3. 빨간공만 들어가면 - res값 계산후 탐색종료
            if (R_hole) {
                //printf("%d >> 빨간공들어감\n", cnt + 1);
                if (res > cnt + 1) res = cnt + 1;
                continue;
            }

            //4. 파란공만 들어가면 - 탐색종료
            else if (B_hole) {
                //printf("%d >> dir:%d - 4\n", cnt + 1, dir);
                continue;
            }

            //5. 방문했었는가?
            if (visited[rxx][ryy][bxx][byy]) {
                //printf("%d >> dir:%d - 5 - R:%d,%d  B:%d,%d\n", cnt + 1, dir, rxx, ryy, bxx, byy);
                continue;
            }

            //6. 큐에 정보를 넣고 방문체크, 반복
            //printf("%d >> dir:%d - R:%d,%d  B:%d,%d\n", cnt + 1, dir, rxx, ryy, bxx, byy);
            visited[rxx][ryy][bxx][byy] = true;
            q.push({ {rxx, ryy},{bxx, byy} });
            trys.push(cnt + 1);
        }
    }
    if (res == INT_MAX)
        printf("-1");
    else
        printf("%d", res);

}


int main(void) {
    init();
    func();


    return 0;
}