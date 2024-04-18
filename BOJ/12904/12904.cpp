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

string S, T;
int S_size;
queue<string> list;
bool find = false;

void init();
void func();
string reverse(string s);
void init() {
    char s[1001], t[1001];
    scanf("%s%s", &s, &t);
    S = s; T = t;
    S_size = S.length();
    list.push(T);
}

void func() {
    while (!list.empty()) {
        string str = list.front();
        int len = str.length();
        list.pop();
        if (len == S_size) {
            if (str.compare(S) == 0) {
                printf("1");
                find = true;
                return;
            }
        }
        else {
            if (str[len - 1] == 'A') { //1. 맨끝이 A라면
                string _ = str.substr(0, len - 1); //끝의 A제거
                list.push(_); //제거후 큐에 넣는다.
            }
            if (str[len - 1] == 'B') { //2. 맨끝이 B라면
                string _ = reverse(str.substr(0, len - 1));
                list.push(_);
            }
        }
    }
    if (!find) printf("0");
}

string reverse(string s) {
    for (int i = 0; i < s.length() / 2; i++) {
        char _ = s[i];
        s[i] = s[s.length() - i - 1];
        s[s.length() - i - 1] = _;
    }

    return s;
}

int main(void) {
    init();
    func();


    return 0;
}