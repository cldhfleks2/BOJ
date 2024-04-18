#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
using std::vector; using std::pair; typedef pair<int, int> pii;
int n, m, **map; //1 : ¶¥ 0: ¹°
vector<pii> land; //¶¥ÀÇ À§Ä¡¸¦ ±â·Ï
int dx1[] = { -1, -1, 0, +1, +1, 0 };
int dx2[] = { -1, -1, 0, +1, +1, 0 };
int dy1[] = { -1, 0, +1, 0, -1, -1 };
int dy2[] = { 0, +1, +1, +1, 0, -1};
int res = 0;

void init() {
    scanf("%d%d", &n, &m);
    map = new int* [n];
    for (int i = 0; i < n; i++) {
        map[i] = new int[m];
        char c;
        scanf("%c", &c);
        for (int j = 0; j < m; j++) {
            
            scanf("%c", &c);
            if (c == '.')
                map[i][j] = 0;
            else if (c == '#') {
                map[i][j] = 1;
                land.push_back({ i, j });
            }
        }
    }

}

void logic() {
    for (int i = 0; i < land.size(); i++) {
        int x = land[i].first;
        int y = land[i].second;

        for (int dir = 0; dir < 6; dir++) {
            int xx;
            int yy;

            if (x % 2 == 0) { //Â¦¼ö Çà
                xx = x + dx1[dir];
                yy = y + dy1[dir]; 
            }
            else { //È¦¼ö Çà
                xx = x + dx2[dir];
                yy = y + dy2[dir]; 
            }


            if (xx < 0 || yy < 0 || xx == n || yy == m)
                continue;
            if (map[xx][yy] == 0) 
                res++;
        }
    }

    printf("%d", res);
}


int main(void) {
    init();
    logic();

    return 0;
}