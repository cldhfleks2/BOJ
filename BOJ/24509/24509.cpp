#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
int main(void) {
    int n, *a, *b, *c, *d;
    scanf("%d", &n);
    a = new int[n + 1]; //����
    b = new int[n + 1]; //����
    c = new int[n + 1]; //����
    d = new int[n + 1]; //����
    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num); //�л���ȣ ����
        scanf("%d%d%d%d", &a[num], &b[num], &c[num], &d[num]);

    }
    int max = 0;
    int max_num = 0;
    //���� ���
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
    //���� ���
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
    //���� ���
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
    //���� ���
    for (int i = 1; i <= n; i++) {
        if (d[i] > max) {
            max = d[i];
            max_num = i;
        }
    }
    printf("%d", max_num);

    return 0;
}