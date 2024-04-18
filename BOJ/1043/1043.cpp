#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
using std::vector;
int N, M, T;
int parent[52]; //1~51
vector<int> partys[51]; //1~M

int res = 0; //가능한 파티수
int* truth;
void goToParty();
void init();
void Union(int x, int y);
int Find(int x);

int Find(int x) {
    if (parent[x] == x)
        return x;
    return parent[x] = Find(parent[x]); //경로압축
}

void Union(int x, int y) {
    x = Find(x);
    y = Find(y);
    if (x > y)
        parent[y] = x; //더큰 부모노드에 자식으로 삽입
    else
        parent[x] = y;
}

void init() {
    scanf("%d%d%d", &N, &M, &T);
    for (int i = 1; i <= N; i++) //초기화
        parent[i] = i;
    parent[51] = 51;
    truth = new int[T];

    for (int i = 0; i < T; i++)
        scanf("%d", &truth[i]);

    if (T == 0) //아래의 코드가 오류나는것을 방지
        return;

    
    for (int i = 0; i < T; i++)
        parent[truth[i]] = 51; //진실을 말하는 사람은 모두 부모노드로 51지목

}
//M개의 파티목록을 입력받고 각 파티별 Union연산을 실행
void goToParty() { 
    for (int k = 1; k <= M; k++) {
        int num;
        scanf("%d", &num);
        bool canLie = true;

        for (int i = 0; i < num; i++) {
            int human;
            scanf("%d", &human);
            partys[k].push_back(human); //k번째 파티목록에 저장
        }
        //진실을 아는사람이 없으면 모든 파티에서 거짓말가능
        //앞서 입력까지만 받고 그 뒤 과정은 모두 생략하도록
        if (T == 0) {
            res++;
            continue;
        }

        for (int i = 0; i < num - 1; i++)
            Union(partys[k][i], partys[k][i + 1]); //파티 참여자끼리 합연산
    }
}

//M개의 파티구성원 목록중 거짓말이 가능한 경우를 계산
void calculate() {
    if (T == 0) {
        printf("%d", M); //모든 파티에서 거짓말 가능
        return;
    }
    
    for (int k = 1; k <= M; k++) {
        int size = partys[k].size();
        bool canLie = true;
        for (int i = 0; i < size; i++) {
            //k번째 파티의 i번 참가자의 부모노드가 
            //51(진실을 아는 사람그룹의 루트노드번호)이라면
            if (Find(partys[k][i]) == 51) {
                canLie = false; //이 파티에서 지민이는 거짓말을 할수없음
                break;
            }
        }

        if (canLie)
            res++;
    }

    printf("%d", res);
}

int main(void) {
    init();
    goToParty();
    calculate();

    return 0;
}