#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
int main(void) {
    int n, *a, *b, *c, *d;
    scanf("%d", &n);
    a = new int[n + 1]; //국어
    b = new int[n + 1]; //영어
    c = new int[n + 1]; //수학
    d = new int[n + 1]; //과학
    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num); //학생번호 받음
        scanf("%d%d%d%d", &a[num], &b[num], &c[num], &d[num]);

    }
    int max = 0;
    int max_num = 0;
    //국어 계산
    for (int i = 1; i <= n; i++) {
        if (a[i] > max) {
            max = a[i];
            max_num = i;
        }
    }
    b[max_num] = -1;
    c[max_num] = -1;
    d[max_num] = -1;
    printf("%d ", max_num);
    max = 0;
    max_num = 0;
    //영어 계산
    for (int i = 1; i <= n; i++) {
        if (b[i] > max) {
            max = b[i];
            max_num = i;
        }
    }
    c[max_num] = -1;
    d[max_num] = -1;
    printf("%d ", max_num);
    max = 0;
    max_num = 0;
    //수학 계산
    for (int i = 1; i <= n; i++) {
        if (c[i] > max) {
            max = c[i];
            max_num = i;
        }
    }
    d[max_num] = -1;
    printf("%d ", max_num);
    max = 0;
    max_num = 0;
    //과학 계산
    for (int i = 1; i <= n; i++) {
        if (d[i] > max) {
            max = d[i];
            max_num = i;
        }
    }
    printf("%d", max_num);

    return 0;
}