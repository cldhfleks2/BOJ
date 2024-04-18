#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
#define MAX 1001
using std::vector; using std::stack; using std::queue;
using std::deque; using std::string; using std::pair;
using std::sort; using std::max; using std::min;
using std::make_pair; using std::max_element; using std::min_element;
using std::fill;
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
int p[MAX];
ll g;
int res;
void init();
void func();

void init() {
    scanf("%d", &N);
    for (int i = 0, temp; i < N; i++) {
        scanf("%d", &temp);
        p[i] = temp;
        g ^= temp; //�ʱ� �������� �׷������ ���
    }
}

void func() {
    if (g == 0) { //�ʱ⿡ ��ü������ �׷������ 0 �̸� ����
        printf("0");
    }
    else {
        for (int i = 0; i < N; i++) { //�������� �ϳ� ���� => p[i]            for (int j = 0; j < N; j++)
            g = 0;
            for(int j = 0 ; j < N ; j++)
                if (i != j)
                    g ^= p[j]; //���� ��������(p[i])������ �������� �� �׷������ ����

            for (int j = 0; j < p[i]; j++) { //���� �ϳ��� ����
                ll pp = g;

                if (!(pp ^= j))  res++;
            }
        }
        printf("%d", res);
    }
}

int main(void) {
    init();
    func();


    return 0;
}