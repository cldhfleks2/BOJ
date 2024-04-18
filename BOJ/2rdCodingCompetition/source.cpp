#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using std::vector;
using std::min;
using std::sort;
using std::queue;

struct INFO {
    int idx, max; //0 ~ flag가되는 인덱스와 0~idx까지의 값
};

//내림차순 정렬을 위한 비교함수 정의
bool compare(const int &a, const int &b) {
    if (a > b)
        return true;
    else
        return false;
}

//최댓값 max를 min과 같을때까지 줄여보고, 그후에도 n이 남았다면
//min 이해로 줄이는 과정을 한뒤에
//vector works를 새로 구함.
long long solution(int n, vector<int> works) {
    long long answer = 0;
    vector<int> res;

    while (n--) {
        int max = 0;
        int idx = 0;
        for (int i = 0; i < works.size(); i++)
            if (max < works[i]) {
                max = works[i];
                idx = i;
            }
        works[idx]--;
    }

    for (int i = 0; i < works.size(); i++)
        if (works[i] <= 0)
            return 0;
        else
            answer += works[i] * works[i];
    return answer;
}

int main(void) {
    int n = 3;
    vector<int> works = {1, 1};
    printf("정답 >>  ");

    printf("%lld", solution(n, works));

    return 0;
}