#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
int n;
int *parent; //각원소 x에대한 부모노드를 나타내는 배열
void logic();
void init();
bool isConnect(int x, int y);
int getParent(int x);

int getParent(int x) { //원소x의 루트노드를 리턴
    if (parent[x] == x) //
        return x;
    //return find(parent[x]) : 기본형태
    return parent[x] = getParent(parent[x]); //경로압축하며 리턴
}

void buildBridges(int x, int y) { //다리를 연결하는 함수
    //x, y원소의 부모노드 번호를 찾아서 x, y에 대입
    x = getParent(x);
    y = getParent(y);
    if (x == y) //부모노드가 같다 = 같은 집합 = 다리가 연결되있다.
        return; //연결되있다면 중단
    //연결 되있지않으면 연결시킴. (부모노드의 자식노드로 대입시킴)
    parent[y] = x;
}

bool isConnect(int x, int y) { //다리가 연결 되있는가?
    //x, y 원소의 부모노드번호를 찾아서 다시 x, y에 대입 
    x = getParent(x);
    y = getParent(y);
    if (x == y) //서로 부모노드가 같은가? = 같은 집합인가? = 다리로 연결되있다.
        return true; //연결되있음(합연산이 되었음)
    return false; 
}

void init() {
    scanf("%d", &n);
    parent = new int[n + 1];
    for (int i = 0; i <= n; i++) //노드 설정
        parent[i] = i;

    for (int i = 0; i < n - 2; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        buildBridges(x, y);
    }
}

void logic() {
    for (int i = 2; i <= n; i++) {
        if (!isConnect(1, i)) { //연결 되지않은 다리 번호 i를 탐색
            printf("1 %d", i); //1번과 연결하면 모든 다리가 연결된것.(문제 핵심)
            return;  //종료
        }
    }
}

int main(void) {
    init();
    logic();

    return 0;
}