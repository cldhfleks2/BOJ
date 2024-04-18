#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
using std::vector; using std::stack; using std::queue;
using std::deque; using std::string; using std::pair;
using std::sort; using std::max; using std::min;
using std::make_pair; using std::max_element; using std::min_element; using std::bitset;
using std::fill; using std::priority_queue; using std::map; using std::greater;
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

int N, M;
vector<int> ways;


void init();
void func();

void init() {
    scanf("%d%d", &N, &M);

    for (int i = 0, temp; i < M; i++) {
        scanf("%d", &temp);
        ways.push_back(temp);
    }
}
/*
p��° ���Ҹ�
�����߰� : cur |= (1 << p)
���һ��� : cur &= ~(1 << p)
������� : cur ^= (1 << p)
*/

void func() {
    int mask = (1 << 22) - 1; //22�� ��Ʈ ����
    int res = -1;
    map<int, int> stoneRecord; //��Ʈ-������ ��
    vector<int> resRecord; //
    for (int i = 0; i <= N; i++) {
        mask <<= 1;
        res += 1;
        //printf("\n0 >> res: %d   i: %d(������,���۵�)   mask: %23s\n", res, i, bitset<22>(mask).to_string().c_str());
        //1.
        for (int k : ways) { //k���� ���� �������� mask�� ���
            if ((mask & (1 << k)) == 0) { //k+1��° ��Ʈ�� 0 �̸�
                mask += 1; //1�߰�
                res -= 1;
                //printf("1 >> >> res: %d   k: %d(������)   mask: %23s\n", res, k, bitset<22>(mask).to_string().c_str());
                break;
            }
        }

        //2. 
        mask &= (1 << 22) - 1;
        //printf("2 >> >> res: %d   mask: %23s\n", res, bitset<22>(mask).to_string().c_str());

        //3. �ֱ⼺�� �߰��ϸ� i�� �ǳʶ��
        //�ð��ʰ��� �����ִ� �κ� -> ���� 4���������� �޸𸮸� ������� ������
        //�����ϸ� �׸�ŭ �� res�� �����ְ�
        if (stoneRecord.count(mask)) {//���� ����ũ(Ű)�� �����ϸ�
            int cycle = i - stoneRecord[mask];
            int cnt = (N - i) / cycle;
            i += cnt * cycle; //�ǳʶ�
            res += cnt * (res - resRecord[stoneRecord[mask]]); //cnt * (��res - ��ω��res)�� ������
            //printf("3 >> >> res: %d(+=%d)   cycle: %d   cnt: %d   i: %d\n", res, cnt * (res - resRecord[stoneRecord[mask]]), cycle, cnt, i);
        }

        //4. ���� ����ũ(Ű)�� ����� �߰� or ����
        stoneRecord[mask] = i;
        resRecord.push_back(res);
       // printf("4 >> >> res: %d   stoneRecord[mask]: %d   r.size(): %d\n", res, stoneRecord[mask], resRecord.size());
    }

    printf("%d", res);
}

int main(void) {
    init();
    func();

    return 0;

}