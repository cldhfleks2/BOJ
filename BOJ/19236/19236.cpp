#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
using std::pair; using std::stack;
typedef pair<int, int> pii;

int ***map;
int max;
stack<pair<int***, int>> list; //�ʰ� �������

int dx[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[] = { 0, -1, -1, -1, 0, 1, 1, 1 };
/*
0 : ���
1~15 : �����
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
    map[0][0][0] = 0; //0,0�� �� ��ġ
    list.push({map, res});

    while (!list.empty()) {
        int*** map = list.top().first;
        res = list.top().second;
        list.pop();

        if (max < res) max = res; //�ż��� �ִ� ����
        //1. ��� �̵�

        //2. ������̵�
        for (int num = 1; num <= 16; num++) { //1������ ���ʴ�� �̵�
            for (int x = 0; x < 4; x++) {
                for (int y = 0; y < 4; y++) {
                    if (map[x][y][0] == num) { //�̵��� ������ȣ�� ã�����
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


        
        //3. ������ ��ġ �ľ�
        for (int x = 0; x < 4; x++) {
            for (int y = 0; y < 4; y++) {
                if (map[x][y][0] == 0) { //�����ġ���� ����
                    map[x][y][0] = -1; //�� �������ڸ� üũ

                    for (int d = 0; d < 3; d++) {
                        int dir = map[x][y][1];
                        int xx = x + d * dx[dir];
                        int yy = y + d * dy[dir];
                        if (xx < 0 || yy < 0 || xx == 4 || yy == 4) continue; //������ ����� ����
                        if (map[xx][yy][0] == -1) continue; //�� �Ծ ������ �ڸ� ����

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