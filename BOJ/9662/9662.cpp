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
p번째 원소를
원소추가 : cur |= (1 << p)
원소삭제 : cur &= ~(1 << p)
원소토글 : cur ^= (1 << p)
*/

void func() {
    int mask = (1 << 22) - 1; //22개 비트 생성
    int res = -1;
    map<int, int> stoneRecord; //비트-남은돌 쌍
    vector<int> resRecord; //
    for (int i = 0; i <= N; i++) {
        mask <<= 1;
        res += 1;
        //printf("\n0 >> res: %d   i: %d(남은돌,시작돌)   mask: %23s\n", res, i, bitset<22>(mask).to_string().c_str());
        //1.
        for (int k : ways) { //k개의 돌을 가져감을 mask에 기록
            if ((mask & (1 << k)) == 0) { //k+1번째 비트가 0 이면
                mask += 1; //1추가
                res -= 1;
                //printf("1 >> >> res: %d   k: %d(돌갯수)   mask: %23s\n", res, k, bitset<22>(mask).to_string().c_str());
                break;
            }
        }

        //2. 
        mask &= (1 << 22) - 1;
        //printf("2 >> >> res: %d   mask: %23s\n", res, bitset<22>(mask).to_string().c_str());

        //3. 주기성을 발견하면 i를 건너띈다
        //시간초과를 막아주는 부분 -> 밑의 4번과정으로 메모리를 어느정도 쓰긴함
        //존재하면 그만큼 더 res에 더해주고
        if (stoneRecord.count(mask)) {//현재 마스크(키)가 존재하면
            int cycle = i - stoneRecord[mask];
            int cnt = (N - i) / cycle;
            i += cnt * cycle; //건너띔
            res += cnt * (res - resRecord[stoneRecord[mask]]); //cnt * (현res - 기록됬던res)을 더해줌
            //printf("3 >> >> res: %d(+=%d)   cycle: %d   cnt: %d   i: %d\n", res, cnt * (res - resRecord[stoneRecord[mask]]), cycle, cnt, i);
        }

        //4. 현재 마스크(키)의 밸류값 추가 or 수정
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