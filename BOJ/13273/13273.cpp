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

//index를 숫자로 접근가능하게.
//s[3]
string ones[] = { "", "I", "II", "III", "IV", "V", 
                    "VI", "VII", "VIII", "IX" }; 
//s[2]
string tens[] = { "", "X", "XX", "XXX", "XL", "L",
                     "LX", "LXX", "LXXX", "XC"};
//s[1]
string hundreds[] = { "", "C", "CC", "CCC", "CD", "D",
                        "DC", "DCC", "DCCC", "CM"};
//s[0]
string thousands[] = { "", "M", "MM", "MMM"};

int t;

void init();
void func();
void roma(string s);
void arabia(string s);
void init() {
    scanf("%d", &t);
}

void func() {
    char input[50];
    while (t--) {
        scanf("%s", &input);
        string s(input);
        if (49 <= input[0] && input[0] <= 57) //아라비아 숫자인가
            roma(s);
        else
            arabia(s);
    }
}

//아라비아숫자를 로마숫자로
void roma(string s) {
    string res;
    if (s.size() == 1) { 
        res = res.append(ones[s[0] - '0']);
    }
    else if (s.size() == 2) { 
        res = res.append(tens[s[0] - '0']);
        res = res.append(ones[s[1] - '0']);
    }
    else if (s.size() == 3) { 
        res = res.append(hundreds[s[0] - '0']);
        res = res.append(tens[s[1] - '0']);
        res = res.append(ones[s[2] - '0']);
    }
    else { 
        res = res.append(thousands[s[0] - '0']);
        res = res.append(hundreds[s[1] - '0']);
        res = res.append(tens[s[2] - '0']);
        res = res.append(ones[s[3] - '0']);
    }
    printf("%s\n", res.c_str());
}

//로마숫자를 아라비아 숫자로
void arabia(string s) {
    string res;
    int start = 0;
    bool hundred = false;
    bool ten = false;
    bool one = false;
    for (int i = 3; i >= 1; i--) {
        int size = thousands[i].size(); //비교할 크기
        if (s.find(thousands[i]) == start) {
            res += 48 + i;
            start += size;
            break;
        }
    }
    for (int i = 9; i >= 1; i--) {
        int size = hundreds[i].size();
        if (s.find(hundreds[i]) == start) {
            res += 48 + i;
            start += size;
            hundred = true;
            break;
        }
    }
    //백의자릿수가 0일때, 하지만 맨앞자리에 0이 오지않도록.
    if (!hundred && res.size() != 0) res += '0'; 
    for (int i = 9; i >= 1; i--) {
        int size = tens[i].size();
        if (s.find(tens[i]) == start) {
            res += 48 + i;
            start += size;
            ten = true;
            break;
        }
    }
    if (!ten && res.size() != 0) res += '0';
    for (int i = 9; i >= 1; i--) {
        int size = ones[i].size();
        if (s.find(ones[i]) == start) {
            res += 48 + i;
            start += size;
            one = true;
            break;
        }
    }
    if (!one && res.size() != 0) res += '0';
    printf("%s\n", res.c_str());
}

int main(void) {
    init();
    func();

    return 0;
}