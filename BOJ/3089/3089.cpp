#define _CRT_SECURE_NO_WARNINGS 
#define MAX 100000
#include <bits/stdc++.h>
using std::vector; using std::sort;
//��� ��ǥ���� 10���� ���Ͽ� 0 <= x,y <= 20000 ���� ���
int n, m;
vector<int> list_x[2 * MAX]; //������ x��ǥ���� ���������� ������ y��ǥ��
vector<int> list_y[2 * MAX]; //��������
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
    //���� ��ġ (0,0)�ε�, �Է¹����� �����ǥ�� 100000�� ��������..
    int x = 0 + MAX, y = 0 + MAX; 
    char c;
    scanf("%c", &c); //�ٹٲ޹��� ����
    for (int i = 0; i < m; i++) {
        scanf("%c", &c);

        switch (c) {
        case 'R':
            for (int i = 0; i < list_y[y].size(); i++) { //���� y�� ���� y��ǥ���� ��� �˻�
                int xx = list_y[y][i]; //Ž���� x��ǥ��
                if (x < xx) { //list�� sort��������, ���� x��ǥ���� ū ��ǥ�� ������
                    x = xx; //���� x��ǥ�� xx�� �̵��� ����
                    break;
                }
            }
            break;
        case 'L':
            for (int i = list_y[y].size()-1; i >= 0; i--) { //�����ϴ¹�������
                int xx = list_y[y][i];
                if (x > xx) { //�����ϴ� �����̴� ������ Ȯ��
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