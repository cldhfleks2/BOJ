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
int map[MAX][MAX]; //0:��ĭ 1:�� 2:������ 3:�Ķ��� 4:����
bool visited[MAX][MAX][MAX][MAX]; //��������ǥ,�Ķ�����ǥ
int dx[] = { -1, 0, 1, 0 }; //��-��-��-����
int dy[] = { 0, 1, 0, -1 };
char dpath[] = { 'U', 'R', 'D', 'L' };

pii R, B, H;
int res_value = INT_MAX;
string res_path;
void init();
void func();
void init() {
    scanf("%d%d", &N, &M);
    for (int i = 0; i < N; i++) {
        char c;
        scanf("%c", &c);//�ٹٲ޹��� ����
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
    queue<pair<pii, pii>> q; //������ �Ķ��� ��ġ
    queue<int> trys; //��� �õ��ߴ°�
    queue<string> path; //���ݱ��� �̵�����
    q.push({ R, B });
    trys.push(0);
    path.push("");
    visited[R.first][R.second][B.first][B.second] = true; //�� ���� ������ġ ����
    while (!q.empty()) {
        int rx = q.front().first.first;
        int ry = q.front().first.second;
        int bx = q.front().second.first;
        int by = q.front().second.second;
        int cnt = trys.front();
        string p = path.front();
        q.pop();
        trys.pop();
        path.pop();

        //���� Ư¡�� �ǿܰ��� ������ �����ֱ⿡ ��üũ���ϸ� out of index��������
        for (int dir = 0; dir < 4; dir++) {
            int rxx{ rx }, ryy{ ry }, bxx{ bx }, byy{ by };
            string pp = p + dpath[dir];
            bool R_end{ false }, B_end = { false };
            bool R_hole{ false }, B_hole{ false };
            //1. �� ���� �̵� ��Ų��.
            while (1) {
                bool R_move{ false }, B_move{ false };
                if (!R_end) { //�������� ���� ������������� �̵�
                    rxx += dx[dir]; ryy += dy[dir]; //��ĭ �̵�
                    //���� �������
                    if (map[rxx][ryy] == 1) {
                        rxx -= dx[dir]; ryy -= dy[dir]; //�ǵ���
                        R_end = true;
                    }
                    else {
                        R_move = true;
                    }
                }
                //1-1. ���� ������ ���ۿ� ���°�
                if (H == make_pair(rxx, ryy)) R_hole = true;

                if (!B_end) { //�������� ���� ������������� �̵�
                    bxx += dx[dir]; byy += dy[dir];
                    if (map[bxx][byy] == 1) {
                        bxx -= dx[dir]; byy -= dy[dir]; //�ǵ���
                        B_end = true;
                    }
                    else {
                        B_move = true;
                    }
                }
                //1-2. �Ķ� ������ ���ۿ� ���°�
                if (H == make_pair(bxx, byy)) B_hole = true;
                if (make_pair(rxx, ryy) == make_pair(bxx, byy)) {
                    //�������� �̵��� ��ģ��� - �Ķ����� �����ε��� ���¿��� �������� �̵��Ѱ�
                    if (R_move) {
                        rxx -= dx[dir]; ryy -= dy[dir]; //�ǵ���
                        break; //�̵� ����
                    }
                    else {
                        bxx -= dx[dir]; byy -= dy[dir];
                        break; //�̵� ����
                    }
                }
                if (R_end && B_end) break;
            }

            //2. �������� �Ķ����� ���ۿ� ����� - Ž������
            if (R_hole && B_hole) {
                continue;
            }

            //3. �������� ���� - Ž������, res�� �ּڰ��̸� ���� ���� �̵���� ��� 
            if (R_hole) {
                if (res_value > cnt + 1) {
                    res_value = cnt + 1; //�ּڰ� ����
                    res_path = pp; //�̵� ��� ����
                }
                continue;
            }

            //4. �Ķ����� ���� - Ž������
            else if (B_hole) {
                continue;
            }

            //5. �湮�߾��°�?
            if (visited[rxx][ryy][bxx][byy]) {
                continue;
            }

            //6. ť�� ������ �ְ� �湮üũ, �ݺ�
            visited[rxx][ryy][bxx][byy] = true;
            q.push({ {rxx, ryy},{bxx, byy} });
            trys.push(cnt + 1);
            path.push(pp);
        }
    }
    if (res_value > 10 || res_value == INT32_MAX)
        printf("-1");
    else {
        printf("%d\n%s", res_value, res_path.c_str());
    }

}


int main(void) {
    init();
    func();


    return 0;
}