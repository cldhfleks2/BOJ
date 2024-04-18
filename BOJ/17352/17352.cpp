#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
int n;
int *parent; //������ x������ �θ��带 ��Ÿ���� �迭
void logic();
void init();
bool isConnect(int x, int y);
int getParent(int x);

int getParent(int x) { //����x�� ��Ʈ��带 ����
    if (parent[x] == x) //
        return x;
    //return find(parent[x]) : �⺻����
    return parent[x] = getParent(parent[x]); //��ξ����ϸ� ����
}

void buildBridges(int x, int y) { //�ٸ��� �����ϴ� �Լ�
    //x, y������ �θ��� ��ȣ�� ã�Ƽ� x, y�� ����
    x = getParent(x);
    y = getParent(y);
    if (x == y) //�θ��尡 ���� = ���� ���� = �ٸ��� ������ִ�.
        return; //������ִٸ� �ߴ�
    //���� ������������ �����Ŵ. (�θ����� �ڽĳ��� ���Խ�Ŵ)
    parent[y] = x;
}

bool isConnect(int x, int y) { //�ٸ��� ���� ���ִ°�?
    //x, y ������ �θ����ȣ�� ã�Ƽ� �ٽ� x, y�� ���� 
    x = getParent(x);
    y = getParent(y);
    if (x == y) //���� �θ��尡 ������? = ���� �����ΰ�? = �ٸ��� ������ִ�.
        return true; //���������(�տ����� �Ǿ���)
    return false; 
}

void init() {
    scanf("%d", &n);
    parent = new int[n + 1];
    for (int i = 0; i <= n; i++) //��� ����
        parent[i] = i;

    for (int i = 0; i < n - 2; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        buildBridges(x, y);
    }
}

void logic() {
    for (int i = 2; i <= n; i++) {
        if (!isConnect(1, i)) { //���� �������� �ٸ� ��ȣ i�� Ž��
            printf("1 %d", i); //1���� �����ϸ� ��� �ٸ��� ����Ȱ�.(���� �ٽ�)
            return;  //����
        }
    }
}

int main(void) {
    init();
    logic();

    return 0;
}