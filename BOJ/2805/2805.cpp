#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
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

ll N, M, H;
deque<ll> tree; 
int size; //Ʈ������
ll max;
void init();
void func();

void init() {
    scanf("%lld%lld", &N, &M);
    for (int i = 0; i < N; i++) {
        ll h;
        scanf("%lld", &h);
        tree.push_back(h);
        if (max < h) max = h;
    }
    size = tree.size();
}

void func() {
    //���ܱ��� ���̸� �̺�Ž���Ͽ� ã�´�.
    ll left = 0, mid = max / 2, right = max;
    while (left <= right) { 
        //printf("%lld, %lld, %lld\n", left, mid, right);
        ll sum = 0; //���ܱ���̰� mid�϶� ��糪���� �ڸ��� ���� ��
        for (int i = 0; i < size; i++) {
            ll len = tree[i] - mid; //�ڸ��� ����
            if (len > 0) //���̰� ����� �ջ�
                sum += len;
        }
        //�ּ��� M�Ǳ��̸� Ȯ���ؾ��Ѵ�
        if (sum >= M) { //�ڸ��������� M���� ũ�� ����H�� �� �÷�����.
            H = mid; //�ϴ� ����
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
        mid = (left + right) / 2;
    }

    printf("%lld", H);
}

int main(void) {
    init();
    func();


    return 0;
}