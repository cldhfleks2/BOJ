#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
int N;
int arr[6 + 2][2 + 2]; 
int cnt[4];

int main(void) {
    int s = 1;
    int b = 1; 

    scanf("%d", &N);
    for (int i = 0; i < 6; i++) {
        scanf("%d %d", &arr[i][0], &arr[i][1]);
        cnt[arr[i][0]]++;
    }

    for (int i = 0; i < 6; i++) {

        if (cnt[arr[i][0]] == 1) {
            b *= arr[i][1]; 
            continue;
        }

        int n = (i + 1) % 6;
        int nn = (i + 2) % 6;
        if (arr[i][0] == arr[nn][0]) s *= arr[n][1];
    }

    printf("%d", (b - s) * N);

    return 0;
}