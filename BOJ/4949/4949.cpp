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


stack<bool> brace; //false: () true: []
void func();

void func() {
    while (1) { //�о�ü��ִ� ��ŭ ���پ� �о��
        char C[101];
        scanf("%[^\n]s", &C);
        string s(C);
        if (s.compare(".") == 0 )
            break;
        int len = s.length();
        bool find = true;
        for (int i = 0; i < len; i++) {
            char c = C[i];
            if (c == '(') {
                brace.push(false);
            }
            else if (c == ')') {
                if (brace.empty() || brace.top() != false) {
                    find = false;
                    break;
                }
                brace.pop();
            }
            else if (c == '[') {
                brace.push(true);
            }
            else if (c == ']') {
                if (brace.empty() || brace.top() != true) {
                    find = false;
                    break;
                }
                brace.pop();
            }
        }
        while (!brace.empty()) { //������ ���������� ��Ī�� �ƴѰ�
            find = false;
            brace.pop(); //������ ���
        }
            
        if (find)
            printf("yes\n");
        else
            printf("no\n");

        scanf("%c", &C[0]); //�ٹٲ޹��� ����
    }
}

int main(void) {
    func();


    return 0;
}