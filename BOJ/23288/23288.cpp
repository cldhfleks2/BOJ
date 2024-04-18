#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using std::queue; using std::pair;
typedef pair<int, int> pii;
int n, m, k;
int sum = 0; //총점수. 출력값
int** map;
bool** visited;
int top=1, right=3, bottom=6, left=4, backward=5, toward=2;
queue<pii> q;
int dx[] = {0, 1, 0, -1}; //주사위 방향
int dy[] = {1, 0, -1, 0};

void init();
void reset();
int calculate(int current_x, int current_y);
void play();
void roll(int dir);

//0:동 1:남 2:서 3:북
void roll(int dir) { //주사위를 굴리고 바닥면의 숫자를 리턴함
    int _;
    switch (dir) {
    case 0:
        _ = left;
        left = bottom;
        bottom = right;
        right = top;
        top = _;
        break;
    case 1:
        _ = toward;
        toward = bottom;
        bottom = backward;
        backward = top;
        top = _;
        break;
    case 2:
        _ = top;
        top = right;
        right = bottom;
        bottom = left;
        left = _;
        break;
    case 3:
        _ = top;
        top = backward;
        backward = bottom;
        bottom = toward;
        toward = _;
        break;
    }
}

void play() {
    int dir = 0; //0:동 1:남 2:서 3:북
    int current_x = 0, current_y = 0;
    while (k--) {
        //1. 현재 주사위 위치 갱신
        if (current_x + dx[dir] < 0 || current_y + dy[dir] < 0 ||
            current_x + dx[dir] == n || current_y + dy[dir] == m) //지도밖으로 벗어나게되는 경우
            dir = (dir + 2) % 4; //주사위 방향을 반대로 바꾸어 진행
        current_x += dx[dir];
        current_y += dy[dir];
        roll(dir);

        //2. 도착칸의 점수 계산
        sum += calculate(current_x, current_y);
        //printf(">> 주사위바닥%d 지도숫자%d\n", bottom, map[current_x][current_y]);
        if (bottom > map[current_x][current_y])
            dir = (dir + 1) % 4; //시계방향
        if (bottom < map[current_x][current_y])
            dir = (dir - 1) % 4; //반시계

        //printf("  %d\n%d %d %d\n  %d\n  %d\n\n\n", toward, left, top, right, backward, bottom);
    }
    
    printf("%d", sum); //결과 출력
}

//현재위치에서의 총합을 계산
//bfs 로 현재 칸의 수와 같은 값을 가지는 칸의 갯수를 탐색.
int calculate(int current_x, int current_y) {
    int num = map[current_x][current_y]; //현재칸의 값
    int count = 0;
    reset(); //방문배열 초기화
    q.push({ current_x, current_y });
    visited[current_x][current_y] = true;
    count++; //찾은 횟수+1
    while (!q.empty()) {
        int x = q.front().first; //큐에서 좌표를 꺼냄
        int y = q.front().second;
        q.pop();

        //4방향 탐색
        for (int dir = 0; dir < 4; dir++) {
            int xx = x + dx[dir];
            int yy = y + dy[dir];
            if (xx < 0 || yy < 0 || xx == n || yy == m) //잘못된 인덱스 제외
                continue;
            if (visited[xx][yy]) //이미 방문했다면 제외
                continue;
            if (map[xx][yy] != num) //지도의 현재칸과 다른 숫자를 가지면 제외
                continue;

            visited[xx][yy] = true; //탐색 체크
            count++; //찾은 횟수 +1
            q.push({ xx, yy }); //다음 탐색위치로 지정. 큐에 넣음
        }
    }
    return num * count; 
}

void reset() {
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++)
            visited[i][j] = false;
}

void init() {
    scanf("%d%d%d", &n, &m, &k);
    map = new int* [n];
    visited = new bool* [n];
    for (int i = 0; i < n; i++) {
        map[i] = new int[m];
        visited[i] = new bool[m];
        for (int j = 0; j < m; j++) {
            scanf("%d", &map[i][j]);
        }
    }
}

int main(void) {
    init();
    play();

    return 0;
}