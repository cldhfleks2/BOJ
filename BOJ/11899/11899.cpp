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

stack<int> bracket; //1, -1

void func() {
    char S[51];
    scanf("%[^\n]s", &S);

    for (int i = 0; i < 51; i++) {
        char c = S[i];
        if (c == '\0') break;

        if (c == '(') // 1
            bracket.push(1);
        else if (c == ')') { // -1
            if (!bracket.empty() && bracket.top() == 1) //-1 Ãß°¡
                bracket.pop();
            else
                bracket.push(-1);
        }
    }

    printf("%d", bracket.size());
}

int main(void) {
    func();

    return 0;
}