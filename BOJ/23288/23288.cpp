#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using std::queue; using std::pair;
typedef pair<int, int> pii;
int n, m, k;
int sum = 0; //������. ��°�
int** map;
bool** visited;
int top=1, right=3, bottom=6, left=4, backward=5, toward=2;
queue<pii> q;
int dx[] = {0, 1, 0, -1}; //�ֻ��� ����
int dy[] = {1, 0, -1, 0};

void init();
void reset();
int calculate(int current_x, int current_y);
void play();
void roll(int dir);

//0:�� 1:�� 2:�� 3:��
void roll(int dir) { //�ֻ����� ������ �ٴڸ��� ���ڸ� ������
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
    int dir = 0; //0:�� 1:�� 2:�� 3:��
    int current_x = 0, current_y = 0;
    while (k--) {
        //1. ���� �ֻ��� ��ġ ����
        if (current_x + dx[dir] < 0 || current_y + dy[dir] < 0 ||
            current_x + dx[dir] == n || current_y + dy[dir] == m) //���������� ����ԵǴ� ���
            dir = (dir + 2) % 4; //�ֻ��� ������ �ݴ�� �ٲپ� ����
        current_x += dx[dir];
        current_y += dy[dir];
        roll(dir);

        //2. ����ĭ�� ���� ���
        sum += calculate(current_x, current_y);
        //printf(">> �ֻ����ٴ�%d ��������%d\n", bottom, map[current_x][current_y]);
        if (bottom > map[current_x][current_y])
            dir = (dir + 1) % 4; //�ð����
        if (bottom < map[current_x][current_y])
            dir = (dir - 1) % 4; //�ݽð�

        //printf("  %d\n%d %d %d\n  %d\n  %d\n\n\n", toward, left, top, right, backward, bottom);
    }
    
    printf("%d", sum); //��� ���
}

//������ġ������ ������ ���
//bfs �� ���� ĭ�� ���� ���� ���� ������ ĭ�� ������ Ž��.
int calculate(int current_x, int current_y) {
    int num = map[current_x][current_y]; //����ĭ�� ��
    int count = 0;
    reset(); //�湮�迭 �ʱ�ȭ
    q.push({ current_x, current_y });
    visited[current_x][current_y] = true;
    count++; //ã�� Ƚ��+1
    while (!q.empty()) {
        int x = q.front().first; //ť���� ��ǥ�� ����
        int y = q.front().second;
        q.pop();

        //4���� Ž��
        for (int dir = 0; dir < 4; dir++) {
            int xx = x + dx[dir];
            int yy = y + dy[dir];
            if (xx < 0 || yy < 0 || xx == n || yy == m) //�߸��� �ε��� ����
                continue;
            if (visited[xx][yy]) //�̹� �湮�ߴٸ� ����
                continue;
            if (map[xx][yy] != num) //������ ����ĭ�� �ٸ� ���ڸ� ������ ����
                continue;

            visited[xx][yy] = true; //Ž�� üũ
            count++; //ã�� Ƚ�� +1
            q.push({ xx, yy }); //���� Ž����ġ�� ����. ť�� ����
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