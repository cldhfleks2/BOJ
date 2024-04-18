#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
using std::pair; typedef pair<double, double> pdd;
int t;
struct Point {
    double x;
    double y;
};
struct Square { //사각형
    Point a, b, c, d;
};
struct Line { //선분
    Point top, bottom;
};
Square s;
Line l;

//입력받고 s, l 초기화
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

//두 벡터의 외적이 시계방향, 반시계방향, 직선이면 각각 -1, 1, 0 출력
int ccw(Point p1, Point p2, Point p3) {
    //행렬을 이용한 두 벡터의 외적계산
    int cross_product = (p2.x - p1.x) * (p3.y - p1.y) - (p3.x - p1.x) * (p2.y - p1.y); 

    //외적값에따른 방향 리턴
    if (cross_product < 0) {
        return -1; //반시계방향
    }
    else if (cross_product > 0) {
        return 1; //시계방향
    }
    else {
        return 0; //직선
    }
}

//선분이 교차하면 true 아니면 false 리턴
bool solve() { 
    double lx = l.top.x;
    double ly = l.top.y;
    double lxx = l.bottom.x;
    double lyy = l.bottom.y;

    double sx1 = s.a.x;
    double sy1 = s.a.y;
    double sx3 = s.c.x;
    double sy3 = s.c.y;

    //작
    double sx4 = s.d.x;
    double sy4 = s.d.y;
    //큰
    double sx2 = s.b.x;
    double sy2 = s.b.y;

    //1. 한점이 사각형 내부에 있을때
    if ((sx4 <= lx && lx <= sx2 && sy4 <= ly && ly <= sy2) ||//1-1. top
        (sx4 <= lxx && lxx <= sx2 && sy4 <= lyy && lyy <= sy2)) {//1-2. bottom
        return true;
    }
    //1-2. 두점이 사각형 내부에 있을떄 = 위와 같음

    //2. 모두 사각형 외부에있을떄




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