#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
struct ant {
    char alpha;
    bool dir;
};
int n1, n2; //���̱׷� ��
int t; //T��
ant* group1, *group2, *list;
void print();
void logic();
void init();

void init() {
    scanf("%d%d", &n1, &n2);
    group1 = new ant[n1];
    group2 = new ant[n2];
    list = new ant[n1 + n2];
    char _;
    scanf("%c", &_); //�ٹٲ޹��� ����

    for (int i = 0; i < n1; i++) { //���̱׷�1  �Ʒ����� : true
        scanf("%c", &_);
        group1[i].alpha = _;
        group1[i].dir = true;
    }

    scanf("%c", &_); //�ٹٲ޹��� ����

    for (int i = 0; i < n2; i++) { //���̱׷�2  ������ : false
        scanf("%c", &_);
        group2[i].alpha = _;
        group2[i].dir = false;
    }
    int cur = 0;
    for (int i = n1 - 1; i >= 0; i--, cur++) {
        list[cur] = group1[i];
    }
    for (int i = 0; i < n2; i++, cur++) {
        list[cur] = group2[i];
    }


    scanf("%d", &t);
}

void logic() {
    int count = n1 + n2;
    ant _;
    while (t--) {
        for (int cur = 0; cur < count - 1; cur++) {
            //���� ���İ��� �������� ���ֺ��°��
            if (list[cur].dir == true && list[cur + 1].dir == false) {
                _ = list[cur];
                list[cur] = list[cur + 1];
                list[cur + 1] = _;
                cur += 1;
            }
        }
    }
}

void print() {
    for (int i = 0; i < n1 + n2; i++)
        printf("%c", list[i].alpha);
}

int main(void) {
    init();
    logic();
    print();

    return 0;
}