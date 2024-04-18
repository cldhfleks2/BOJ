#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
int N, M;
int parent[201];
int* city;
void travel();
void init();
bool isConnect(int x, int y);
void Union(int x, int y);
int Find(int x);

int Find(int x) {
    if (parent[x] == x)
        return x;
    return parent[x] = Find(parent[x]); //경로압축
}

void Union(int x, int y) {
    x = Find(x);
    y = Find(y);
    parent[x] = y;
}

bool isConnect(int x, int y) {
    x = Find(x);
    y = Find(y);
    if (x == y)
        return true;
    return false;
}

void init() {
    scanf("%d%d", &N, &M);
    for (int i = 0; i <= N; i++)
        parent[i] = i;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            int state;
            scanf("%d", &state);
            if (state == 1)
                Union(i, j);
        }
    }
    city = new int[M];

    for (int i = 0; i < M; i++)
        scanf("%d", &city[i]);
}

void travel() {
    for (int i = 0; i < M - 1; i++) {
        int from = city[i];
        int to = city[i + 1];
        if (!isConnect(from, to)) { //하나라도 연결되지 않으면
            printf("NO");
            return;
        }
    }
    printf("YES"); //전부 연결되있으면
}

int main(void) {
    init();
    travel();


    return 0;
}