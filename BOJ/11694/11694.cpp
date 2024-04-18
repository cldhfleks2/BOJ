#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
#define MAX 101
using std::vector; using std::queue; using std::pair; using std::string; using std::sort;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;
typedef pair<int, char> pic;
typedef pair<char, int> pci;

int N;
ll p[MAX];
ll p1_cnt;
ll g = 0;

void init();
void func();

void init() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        ll temp;
        scanf("%lld", &temp);
        p[i] = temp;
        if (temp == 1)  p1_cnt++;
    }
}

void func() {
    //1��¥�� �������Ⱑ 0���� ũ�� ¦�����̸�
    //�׵��� �� G = 0 �̸� ������ �й��ϴµ�, �� ������
    //�߰��������� p[i] ^ p[i+1] = 0 �� �Ǵ� Ƚ���� �ѹ� ������Ű�� ������.
    //���� ���� �⺻���̰� g = 0 �λ��¿��� g = p[1] �ιٲپ�
    //���� for������ g ^ p[1] ==> p[1] ^ p[1] = 0 ���� �������.
    if (p1_cnt > 0 && p1_cnt % 2 == 0) {
        g = p[1];
    }
    //��� �����̰� ��1�� �϶��� ���а� �����ǹǷ� �ٲ��־���Ѵ�.
    if (p1_cnt == N) {
        N % 2 ? printf("cubelover") : printf("koosaga");
    }
    else {
        for (int i = 0; i < N; i++)
            g ^= p[i];
        g ? printf("koosaga") : printf("cubelover");
    }
}

int main(void) {
    init();
    func();


    return 0;
}