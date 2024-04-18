#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
#define MAX 1001
using std::vector; using std::stack; using std::queue;
using std::deque; using std::string; using std::pair;
using std::sort; using std::max; using std::min; using std::make_pair; using std::max_element; using std::min_element; using std::fill;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, int> pdi;
typedef pair<int, double> pid;
typedef pair<double, double> pdd;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;
typedef pair<int, char> pic;
typedef pair<char, int> pci;
typedef pair<string, int> psi;
typedef pair<int, string> pis;
typedef pair<string, string> pss;

int N;
int Grundy[MAX];
bool check[16];
void init();
void func();
void calculateGrundy(int n);
void init() {
    scanf("%d", &N);
    fill(Grundy, Grundy + MAX, 0);
    Grundy[0] = 0;
    Grundy[1] = 0;
    Grundy[2] = 1;
}

void func() {
    for (int i = 3; i <= N; i++) {
        fill(check, check + 16, false);
        int left = 0, right = i - 2;
        while (left <= right) {
            int g = Grundy[left] ^ Grundy[right];
            check[g] = true;
            left++; right--;
        }

        for (int j = 0; j < 16; j++) {
            if (!check[j]) {
                Grundy[i] = j;
                break;
            }
        }
    }

    Grundy[N] ? printf("1") : printf("2");
}


int main(void) {
    init();
    func();


    return 0;
}