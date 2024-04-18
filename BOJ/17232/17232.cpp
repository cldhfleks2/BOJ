#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
using std::vector; using std::stack; using std::queue;
using std::deque; using std::string; using std::pair;
using std::sort;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;
typedef pair<int, char> pic;
typedef pair<char, int> pci;

bool **old, **res;
int N, M, T, K, a, b;

void print();
void func();
void paste();
int around(int x, int y);
void init();

void init() {
    scanf("%d%d%d%d%d%d", &N, &M, &T, &K, &a, &b);
    old = new bool* [N];
    res = new bool* [N];
    for (int x = 0; x < N; x++) {
        old[x] = new bool[M];
        res[x] = new bool[M];
        char c;
        scanf("%c", &c); //�ٹٲ޹��� ����
        for (int y = 0; y < M; y++) {
            scanf("%c", &c);
            if (c == '.')
                res[x][y] = false;
            else
                res[x][y] = true;
        }
    }
}

int around(int x, int y) { //��(x, y) ������ 2K+1�� ���簢�� ĭ���� �������� ����
    int cnt = 0;
    for (int i = x - 1; i >= x - K; i++) {
        for (int j = y - K; j <= y + K; j++) {
            if (i < 0 || i >= N || j < 0 || j >= M) continue;
            if (i == x && j == y) continue;
            if(old[i][j]) cnt++;
        }
    }

    return cnt;
}

void paste() { //res -> old�� �����ϴ� �Լ�
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            old[i][j] = res[i][j];
}

void func() {
    while (T--) {
        paste();
        for (int x = 0; x < N; x++) {
            for (int y = 0; y < M; y++) {
                int cnt = around(x, y);

                if (old[x][y]) { //����ĭ�� ����������
                    if (a <= cnt && cnt <= b) {
                        res[x][y] = true;
                    }
                    else if (cnt < a) {
                        res[x][y] = false;
                    }
                    else if (b < cnt) {
                        res[x][y] = false;
                    }
                }
                else { //����
                    if (a < cnt && cnt <= b) {
                        res[x][y] = true;
                    }
                }

            }
        }
    }

    print();

}

void print() {
    for (int x = 0; x < N; x++) {
        for (int y = 0; y < M; y++) {
            if (res[x][y])
                printf("*");
            else
                printf(".");
        }
        printf("\n");
    }

}

int main(void) {
    init();
    func();


    return 0;
}