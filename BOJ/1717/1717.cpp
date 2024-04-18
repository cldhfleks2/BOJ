#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
int n, m;
int parent[1000001];

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

bool isUnion(int x, int y) {
    x = Find(x);
    y = Find(y);
    if (x == y)
        return true;
    return false;
}

void init() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i <= n; i++)
        parent[i] = i;
}

void logic() {
    while (m--) {
        int sign, a, b;
        scanf("%d%d%d", &sign, &a, &b);
        if (sign == 0)
            Union(a, b);
        else {
            if (isUnion(a, b))
                printf("YES\n");
            else
                printf("NO\n");
        }   
    }
}

int main(void) {
    init();
    logic();

    return 0;
}