#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
using std::pair; typedef pair<double, double> pdd;
int t;
struct Point {
    double x;
    double y;
};
struct Square { //�簢��
    Point a, b, c, d;
};
struct Line { //����
    Point top, bottom;
};
Square s;
Line l;

//�Է¹ް� s, l �ʱ�ȭ
void input() {
    double x, y, xx, yy, x1, y1, x2, y2;
    scanf("%lf%lf%lf%lf%lf%lf%lf%lf", &x, &y, &xx, &yy, &x1, &y1, &x2, &y2);
    if (y > yy) {
        l.top.x = x; l.top.y = y;
        l.bottom.x = xx; l.bottom.y = yy;
    }
    else {
        l.top.x = xx; l.top.y = yy;
        l.bottom.x = x; l.bottom.y = y;
    }

    if (x1 < x2 && y1 < y2) { //type1
        s.a.x = x1; s.a.y = y2;
        s.b.x = x2; s.b.y = y2;
        s.c.x = x2; s.c.y = y1;
        s.d.x = x1; s.d.y = y1;
    }
    else if (x1 > x2 && y1 > y2) { //type1
        s.a.x = x2; s.a.y = y1;
        s.b.x = x1; s.b.y = y1;
        s.c.x = x1; s.c.y = y2; 
        s.d.x = x2; s.d.y = y2;
    }
    else if (x1 < x2 && y1 > y2) { //type2
        s.a.x = x1; s.a.y = y1;
        s.b.x = x2; s.b.y = y1;
        s.c.x = x2; s.c.y = y2;
        s.d.x = x1; s.d.y = y2;
    }
    else { //type2
        s.a.x = x2; s.a.y = y2;
        s.b.x = x1; s.b.y = y2;
        s.c.x = x1; s.c.y = y1;
        s.d.x = x2; s.d.y = y1;
    }
}

//�� ������ ������ �ð����, �ݽð����, �����̸� ���� -1, 1, 0 ���
int ccw(Point p1, Point p2, Point p3) {
    //����� �̿��� �� ������ �������
    int cross_product = (p2.x - p1.x) * (p3.y - p1.y) - (p3.x - p1.x) * (p2.y - p1.y); 

    //������������ ���� ����
    if (cross_product < 0) {
        return -1; //�ݽð����
    }
    else if (cross_product > 0) {
        return 1; //�ð����
    }
    else {
        return 0; //����
    }
}

//������ �����ϸ� true �ƴϸ� false ����
bool solve() { 
    double lx = l.top.x;
    double ly = l.top.y;
    double lxx = l.bottom.x;
    double lyy = l.bottom.y;

    double sx1 = s.a.x;
    double sy1 = s.a.y;
    double sx3 = s.c.x;
    double sy3 = s.c.y;

    //��
    double sx4 = s.d.x;
    double sy4 = s.d.y;
    //ū
    double sx2 = s.b.x;
    double sy2 = s.b.y;

    //1. ������ �簢�� ���ο� ������
    if ((sx4 <= lx && lx <= sx2 && sy4 <= ly && ly <= sy2) ||//1-1. top
        (sx4 <= lxx && lxx <= sx2 && sy4 <= lyy && lyy <= sy2)) {//1-2. bottom
        return true;
    }
    //1-2. ������ �簢�� ���ο� ������ = ���� ����

    //2. ��� �簢�� �ܺο�������




    return false;
}

int main(void) {
    scanf("%d", &t);
    while (t--) {
        input();
        if (solve())
            printf("T\n");
        else
            printf("F\n");
    }

    return 0;
}