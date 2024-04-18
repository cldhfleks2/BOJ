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
    int idx, max; //0 ~ flag���Ǵ� �ε����� 0~idx������ ��
};

//�������� ������ ���� ���Լ� ����
bool compare(const int &a, const int &b) {
    if (a > b)
        return true;
    else
        return false;
}

//�ִ� max�� min�� ���������� �ٿ�����, ���Ŀ��� n�� ���Ҵٸ�
//min ���ط� ���̴� ������ �ѵڿ�
//vector works�� ���� ����.
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
    printf("���� >>  ");

    printf("%lld", solution(n, works));

    return 0;
}