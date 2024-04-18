#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
using std::pair; using std::stack;
typedef pair<int, int> pii;

int ***map;
int max;
stack<pair<int***, int>> list; //맵과 물고기합

int dx[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[] = { 0, -1, -1, -1, 0, 1, 1, 1 };
/*
0 : 상어
1~15 : 물고기
*/
void init() {
    map = new int** [4];
    for (int i = 0; i < 4; i++) {
        map[i] = new int* [4];
        for (int j = 0; j < 4; j++) {
            map[i][j] = new int[2];
            int num, dir;
            scanf("%d%d", &num, &dir);
            map[i][j][0] = num;
            map[i][j][1] = dir - 1;
        }
    }


}

void logic() {
    int res = map[0][0][0];
    map[0][0][0] = 0; //0,0에 상어를 배치
    list.push({map, res});

    while (!list.empty()) {
        int*** map = list.top().first;
        res = list.top().second;
        list.pop();

        if (max < res) max = res; //매순간 최댓값 갱신
        //1. 상어 이동

        //2. 물고기이동
        for (int num = 1; num <= 16; num++) { //1번부터 차례대로 이동
            for (int x = 0; x < 4; x++) {
                for (int y = 0; y < 4; y++) {
                    if (map[x][y][0] == num) { //이동할 물고기번호를 찾은경우
                        int dir = map[x][y][1];
                        int cnt = 1;
                        while (true) {
                            if (cnt == 8) break;
                            int xx = x + dx[dir];
                            int yy = y + dy[dir];
                            if (xx < 0 || yy < 0 || xx == 4 || yy == 4) {
                                dir = (dir + 1) % 8;
                                cnt++;
                                continue;
                            }
                            else if (map[xx][yy][0] == 0) {
                                dir = (dir + 1) % 8;
                                cnt++;
                                continue;
                            }
                            int change_num = map[xx][yy][0];
                            int change_dir = map[xx][yy][1];

                            map[xx][yy][0] = num;
                            map[xx][yy][1] = dir;
                            map[x][y][0] = change_num;
                            map[x][y][1] = change_dir;


                        }
                    }
                }
            }
        }


        
        //3. 상어다음 위치 파악
        for (int x = 0; x < 4; x++) {
            for (int y = 0; y < 4; y++) {
                if (map[x][y][0] == 0) { //상어위치에서 시작
                    map[x][y][0] = -1; //상어가 지나간자리 체크

                    for (int d = 0; d < 3; d++) {
                        int dir = map[x][y][1];
                        int xx = x + d * dx[dir];
                        int yy = y + d * dy[dir];
                        if (xx < 0 || yy < 0 || xx == 4 || yy == 4) continue; //공간을 벗어나면 제외
                        if (map[xx][yy][0] == -1) continue; //상어가 먹어서 지나간 자리 제외

                        map[xx][yy][0]
                    }

                    return;
                }
            }
        }

    }

}


int main(void) {
    init();
    
    logic();

    return 0;
}