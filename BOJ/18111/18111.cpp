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

    sort(map, map + size, greater<>()); //내림차순 정렬
}

void func() {
    int res = 0;
    for (int k = 0; k <= 256; k++) { //모든 블럭의높이를 k층으로 만들어본다.
        ll b = B; //사용가능한 블럭수
        ll t = 0; //사용될 총 시간
        bool possible = true;

        //1.블럭을 깎는다 - 각2초
        int cur = 0;
        while (map[cur] >= k && cur < size) { //k층보다 같거나 클때까지만
            int gap = map[cur] - k; //깎아야할 갯수
            t += gap * 2; //한칸깎는데 2초 소요
            b += gap; //깎은블럭 인벤토리에 저장
            cur++;
        }

        //2.블럭을 쌓는다 - 각1초
        while (cur < size) { //나머지 블럭 모두 순회
            int gap = k - map[cur]; //쌓아야할 갯수
            b -= gap; //인벤토리의 블럭 사용
            if (b < 0) { //인벤토리의 블럭이 부족하면 탐색종료
                printf("%lld %lld", min_T, H);
                return;
            }
            t += gap; //한칸쌓는데 1초 소요
            cur++;
        }

        //지금껏 최소시간또는 동일한시간이면 높이를 저장
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