#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
using std::vector; using std::stack; using std::queue;
using std::deque; using std::string; using std::pair;
using std::sort;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;
typedef pair<int, char> pic;
typedef pair<char, int> pci;


void func();
void func() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int s, k;
        scanf("%d%d", &s, &k);
        if (k % 2 == 0) { //k가 짝수 일때
            int period = (k + 1); //주기(K+1)
            int mod = s % period; //주기로 나눈 나머지
            if (mod == period - 1) {
                printf("%d\n", k);
            }
            else {
                if (mod % 2 == 0)
                    printf("0\n");
                else
                    //s홀수 
                    printf("1\n");
            }
        }
        else { //k가 홀수 일때
            if (s % 2 == 0)
                printf("0\n"); //이길 수 없음
            else
                printf("1\n");
        }
    }
}

int main(void) {
    func();


    return 0;
}