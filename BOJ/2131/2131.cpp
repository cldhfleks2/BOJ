#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
using std::vector; using std::queue; using std::pair; using std::string;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;
typedef pair<int, char> pic;
typedef pair<char, int> pci;

vector<int> list;

int n, last_dir=0, change_dir=0, res;
void init() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        char _[11];
        scanf("%c", &_[0]); //줄바꿈문자 제거
        scanf("%[^\n]s", &_);

        if (strcmp(_, "Forward") == 0)
            list.push_back(1);
        else if (strcmp(_, "Turn Left") == 0)
            list.push_back(2);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 
        else if (strcmp(_, "Turn Right") == 0)
            list.push_back(3);
        else if(strcmp(_, "Scan") == 0)
            list.push_back(4);
    }
}

void func() {
    for (int i = 0; i < list.size(); i++) {
        int order = list[i];
        
        switch (order) {
        case 1: //Forward
            res += 1;
            if (change_dir%4 == last_dir) { //같은 방향 이동시 한s번에 이동한것으로
                if (i != 0 && list[i - 1] == 1) //바로 직전에도 이동했는지
                    res -= 1;
            }
            else { //다른 방향으로 이동하는경우
                last_dir = change_dir % 4; //last_dir 갱신
                change_dir = change_dir % 4;
            }

        case 2: //Turn Left
            change_dir += 3; //-1 과 같음
            break;

        case 3: //Turn Right
            change_dir += 1;
            break;

        case 4: //SCAN
            res + 1;
            if (change_dir % 4 == last_dir) { //같은 방향 스캔시 작동 안한것으로
                if (i != 0 && list[i - 1] == 4)
                    res -= 1;
            }
            else { //다른 방향으로 이동하는경우
                last_dir = change_dir % 4; //last_dir 갱신
                change_dir = change_dir % 4;
            }
            break;
        }
        //printf(">> %d\n", res);

    }

    printf("%d", res);
}

int main(void) {
    init();
    func();


    return 0;
}