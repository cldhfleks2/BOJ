#define _CRT_SECURE_NO_WARNINGS //scanf오류 없앰
#include <bits/stdc++.h>
using namespace std;


int main(void) {
	double x1, y1, x2, y2, x3, y3;
	scanf("%lf%lf%lf%lf%lf%lf", &x1, &y1, &x2, &y2, &x3, &y3);
	//두직선의  기울기가 같으면 한직선상이므로 -1출력

	if ((abs(y2 - y1) / abs(x2 - x1)) == (abs(y3 - y2) / abs(x3 - x2))) {
		printf("-1.0");
	}
	else {
		double lines[3];
		lines[0] = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)); //2 ,1
		lines[1] = sqrt((x3 - x1) * (x3 - x1) + (y3 - y1) * (y3 - y1)); //3, 1
		lines[2] = sqrt((x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2)); //3, 2
		double perimeters[] = { lines[0] * 2 + lines[1] * 2,
								lines[1] * 2 + lines[2] * 2,
								lines[2] * 2 + lines[0] * 2 };
		double maxPerimeter = 0.0, minPerimeter = 0.0;
		maxPerimeter = max(perimeters[0], max(perimeters[1], perimeters[2]));
		minPerimeter = min(perimeters[0], min(perimeters[1], perimeters[2]));
		printf("%.16f", maxPerimeter - minPerimeter);
	}
}
