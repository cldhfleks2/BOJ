#define _CRT_SECURE_NO_WARNINGS 
#define MAX 100000
#include <bits/stdc++.h>
using std::vector; using std::sort;
//모든 좌표값에 10만을 더하여 0 <= x,y <= 20000 으로 계산
int n, m;
vector<int> list_x[2 * MAX]; //동일한 x좌표만을 나열했을때 각각의 y좌표들
vector<int> list_y[2 * MAX]; //마찬가지
void init() {
    scanf("%d%d", &n, &m);
    for (int i = 0, x, y; i < n; i++) {
        scanf("%d%d", &x, &y);
        list_x[x + MAX].push_back(y + MAX);
        list_y[y + MAX].push_back(x + MAX);
    }
    
    for (int i = 0; i < 2 * MAX; i++) {
        if (list_x[i].size() > 0) sort(list_x[i].begin(), list_x[i].end());
        if (list_y[i].size() > 0) sort(list_y[i].begin(), list_y[i].end());
    }
}

void func() {
    //현재 위치 (0,0)인데, 입력받을때 모든좌표에 100000을 더했으니..
    int x = 0 + MAX, y = 0 + MAX; 
    char c;
    scanf("%c", &c); //줄바꿈문자 제거
    for (int i = 0; i < m; i++) {
        scanf("%c", &c);

        switch (c) {
        case 'R':
            for (int i = 0; i < list_y[y].size(); i++) { //현재 y와 같은 y좌표들을 모두 검색
                int xx = list_y[y][i]; //탐색한 x좌표들
                if (x < xx) { //list는 sort되있으니, 현재 x좌표보다 큰 좌표를 만나면
                    x = xx; //현재 x좌표를 xx로 이동후 종료
                    break;
                }
            }
            break;
        case 'L':
            for (int i = list_y[y].size()-1; i >= 0; i--) { //감소하는방향으로
                int xx = list_y[y][i];
                if (x > xx) { //감소하는 방향이니 작은지 확인
                    x = xx;
                    break;
                }
            }
            break;
        case 'U':
            for (int i = 0; i < list_x[x].size(); i++) { 
                int yy = list_x[x][i]; 
                if (y < yy) { 
                    y = yy; 
                    break;
                }
            }
            break;
        case 'D':
            for (int i = list_x[x].size() - 1 ; i >= 0; i--) {
                int yy = list_x[x][i];
                if (y > yy) {
                    y = yy;
                    break;
                }
            }
            break;
        }
    }

    printf("%d %d\n", x - MAX, y - MAX);
}

int main(void) {
    init();
    func();


    return 0;
}