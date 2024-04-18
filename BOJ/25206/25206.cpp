#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
using std::vector; using std::stack; using std::queue;
using std::deque; using std::string; using std::pair;
using std::sort;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;
typedef pair<int, char> pic;
typedef pair<char, int> pci;

string credit_list[] = { "A+", "A0" , "B+" , "B0" ,
                    "C+" , "C0" , "D+", "D0", "F", "P" };
double score_list[] = { 4.5, 4.0, 3.5, 3.0, 2.5,
                        2.0, 1.5, 1.0, 0.0, -1.0 };

void func();

void func() {
    int cnt = 20;
    double sum = 0;
    double credit_sum = 0;
    char subject[51];
    while (cnt--) {
        char _;
        string rank;
        double credit;
        double score;
        scanf("%s%lf%s%c", &subject, &credit, &subject, &_); //줄바꿈문자도 제거
        rank = subject;
        int i = 0;
        for (; i <= 10; i++)
            if (rank.compare(credit_list[i]) == 0)
                break;
        score = score_list[i];
        if (score == -1) continue;
        credit_sum += credit;
        sum += credit * score;
    }

    printf("%.6lf", sum / credit_sum);
}

int main(void) {
    func();

    return 0;
}