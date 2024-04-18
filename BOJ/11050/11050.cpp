#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>

int fact(int n) {
    if (n == 0)
        return 1;
    return n * fact(n - 1);
}

int main(int n, int k) {
    scanf("%d %d", &n, &k);

    printf("%d", fact(n) / (fact(k) * fact(n - k)));
}