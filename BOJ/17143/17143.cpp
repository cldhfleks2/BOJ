#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
#define MAX 101
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

int R, C, M;
int cycleX, cycleY; //X, Y 방향이 바뀌는 주기
vector<tuple<int, int, int, int, int>> sharkList;
vector<tuple<int, int, int>> map[MAX][MAX];
//0:위  1:오른쪽  2:아래  3:왼쪽
int dxy[][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };

ll res;

void init();
void move();
void hunt(int k);
void func(); 

void init() {
    scanf("%d%d%d", &R, &C, &M);
    int r, c, s, d, z;
    for (int i = 0; i < M; i++) {
        scanf("%d%d%d%d%d", &r, &c, &s, &d, &z);
        r--; c--;
        if (d == 1)
            d = 0;
        else if (d == 3)
            d = 1;
        else if (d == 4)
            d = 3;
        sharkList.push_back(make_tuple(r, c, s, d, z)); //상어위치 기록
    }
    cycleX = R - 1;
    cycleY = C - 1;
}

//k열의 낚시꾼이 사냥을한다.
void hunt(int k) {
    int x = R - 1; //x의 최댓값
    int index = 0;
    int size = 0;
    for (int i = 0; i < sharkList.size(); i++) { //인덱스를 찾는다
        int r, c, s, d, z;
        tie(r, c, s, d, z) = sharkList[i];
        if (c == k && x >= r){ //같은 열이고 x좌표가 최소일때
            x = r; //x 갱신
            size = z; //상어의 크기를 기록
            index = i;
        }
    }
    if (size != 0) {
        sharkList.erase(sharkList.begin() + index); //찾은 상어기록을 삭제
        res += size;
    }
}

//상어가 이동
//0:위  1:오른쪽  2:아래  3:왼쪽
void move() {
    //맵을 비움
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            map[i][j].clear();

    //각 상어의 다음위치 x, y를 결정
    for (int i = 0; i < sharkList.size(); i++) {
        int x, y, s, d, z;
        tie(x, y, s, d, z) = sharkList[i];
        if (d == 0 || d == 2) {
            int cnt = s;
            while (cnt--) { //s만큼 반복
                x += dxy[d][0];
                if (x == R || x == -1) { //방향전환
                    d = (d + 2) % 4;
                    x += 2 * dxy[d][0];
                }
            }
        }
        else if (d == 1 || d == 3) { 
            int cnt = s;
            while (cnt--) { //s만큼 반복
                y += dxy[d][1];
                if (y == C || y == -1) { //방향전환
                    d = (d + 2) % 4;
                    y += 2 * dxy[d][1];
                }
            }
                
        }
        if (!map[x][y].empty()) { //상어가 이미 존재하는 경우
            int ss, dd, zz;
            tie(ss, dd, zz) = map[x][y][0];
            if (zz < z) { //현재상어가 기존에있던 상어를 먹는다.
                //교체
                map[x][y].clear(); 
                map[x][y].push_back(make_tuple(s, d, z)); 
            } //현재상어가 기존에있던 상어에게 먹힘.. 교체할게없음
        }
        else { //상어가없으면 현재상어를 추가
            map[x][y].push_back(make_tuple(s, d, z));
        }
    }
    //map을 탐색해서 최종적인 상어를 sharkList에 기록
    sharkList.clear();
    for(int x = 0 ; x < R ; x++)
        for (int y= 0; y < C; y++)
            if (!map[x][y].empty()) {
                int s, d, z;
                tie(s, d, z) = map[x][y][0];
                sharkList.push_back(make_tuple(x, y, s, d, z));
            }
}

void func() {
    for (int k = 0; k < C; k++) { //낚시꾼이 존재하는 k열
        hunt(k);

        move();
        if (sharkList.size() == 0) { //더이상 상어가 존재하지 않으면 끝
            break;
        }
    }

    printf("%lld", res);
}

int main(void) {
    init();
    func();

    return 0;
}