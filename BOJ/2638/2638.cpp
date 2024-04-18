#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
using std::queue; using std::pair;
typedef pair<int, int> pii;
int n, m, **map, **check, res=0, cheeze=0;
bool** visited;

int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };

void init() {
    scanf("%d%d", &n, &m);
    map = new int* [n];
    check = new int* [n];
    visited = new bool* [n];
    for (int i = 0; i < n; i++) {
        map[i] = new int[m];
        check[i] = new int[m];
        visited[i] = new bool[m];
        for (int j = 0, temp; j < m; j++) {
            scanf("%d", &temp); 
            map[i][j] = temp;
            if (temp == 1) //ġ�� ���� ī��Ʈ
                cheeze++;
        }
    }
    
}

void reset() {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            check[i][j] = 0;
            visited[i][j] = false;
        }
}

void logic() {
    queue<pii> points;
    while (cheeze > 0) {
        reset();

        points.push({ 0, 0 });
        visited[0][0] = true;

        //bfs �̿�
        while (!points.empty()) {
            int x = points.front().first; //���� ��ġ
            int y = points.front().second;
            points.pop();

            for (int dir = 0; dir < 4; dir++) { //������ġ 
                int xx = x + dx[dir];
                int yy = y + dy[dir];

                if (xx < 0 || yy < 0 || xx == n || yy == m) continue; //�����̸� ����� ����
                if (visited[xx][yy]) continue; //�ߺ��湮 ����

                if (map[xx][yy] == 1) { //ġ��߽߰�
                    check[xx][yy]++;
                }
                else if(map[xx][yy] == 0){ //������Ͻ�
                    visited[xx][yy] = true;
                    points.push({ xx, yy }); //Ž���� �̾��
                }

            }

        }

        for(int x = 0 ; x < n ; x++)
            for(int y = 0 ; y < m ; y++)
                if (check[x][y] >= 2) {
                    cheeze--;
                    map[x][y] = 0;
                }

        res++;

    }

    printf("%d", res);
}

int main(void) {
    init();

    logic();

    return 0;
}