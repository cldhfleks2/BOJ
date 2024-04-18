#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
#define MAX 500*500 + 1
using std::vector; using std::stack; using std::queue; using std::deque; using std::tuple;
using std::string; using std::pair; using std::make_tuple; using std::tie;
using std::sort; using std::swap;
using std::make_pair; using std::max_element; using std::min_element; using std::bitset; using std::to_string;
using std::fill; using std::priority_queue; using std::greater;
//using std::max; using std::min; using std::map;
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


ll N, M, B, size, H, min_T=LLONG_MAX;
int map[MAX];
void init();
void func();

void init() {
    scanf("%lld%lld%lld", &N, &M, &B);
    size = N * M;
    for (int i = 0; i < size; i++)
        scanf("%d", &map[i]);

    sort(map, map + size, greater<>()); //�������� ����
}

void func() {
    int res = 0;
    for (int k = 0; k <= 256; k++) { //��� ���ǳ��̸� k������ ������.
        ll b = B; //��밡���� ����
        ll t = 0; //���� �� �ð�
        bool possible = true;

        //1.���� ��´� - ��2��
        int cur = 0;
        while (map[cur] >= k && cur < size) { //k������ ���ų� Ŭ��������
            int gap = map[cur] - k; //��ƾ��� ����
            t += gap * 2; //��ĭ��µ� 2�� �ҿ�
            b += gap; //������ �κ��丮�� ����
            cur++;
        }

        //2.���� �״´� - ��1��
        while (cur < size) { //������ �� ��� ��ȸ
            int gap = k - map[cur]; //�׾ƾ��� ����
            b -= gap; //�κ��丮�� �� ���
            if (b < 0) { //�κ��丮�� ���� �����ϸ� Ž������
                printf("%lld %lld", min_T, H);
                return;
            }
            t += gap; //��ĭ�״µ� 1�� �ҿ�
            cur++;
        }

        //���ݲ� �ּҽð��Ǵ� �����ѽð��̸� ���̸� ����
        if (min_T >= t) {
            H = k; 
            min_T = t;
        }
    }

    printf("%lld %lld", min_T, H);
}

int main(void) {
    init();
    func();

    return 0;
}