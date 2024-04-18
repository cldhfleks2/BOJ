#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
#define MAX 100001
using std::vector; using std::stack; using std::queue; using std::deque; using std::tuple;
using std::string; using std::pair; using std::make_tuple; using std::tie;
using std::sort;
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

int N;
ll V[MAX]; //정점에 쓰인값
int parent[MAX]; //각 정점의 부모를 저장
vector<int> child[MAX]; //각 정점의 자식노드를 저장
ll edge[MAX]; //각 정점의 부모와 연결된 간선의 가중치값
vector<pii> sad; //슬픈 정점번호v, 정점1과의 떨어진 거리
vector<int> tail; //말단 노드 번호들
vector<int> passVertex;
ll res;

void init();
void func();
void findSadVertex();
void init() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
        scanf("%d", &V[i]);

    for (int i = 1; i < N ; i++) { //N-1개줄에 p1~pN-1과 c1~cN-1을 받음
        int p, c;
        scanf("%lld%lld", &p, &c);
        parent[i+1] = p; //(i+1)정점의 부모는 정점p이다.
        edge[i + 1] = c; //(i+1)정점과 부모사이 간선의 가중치값c
        child[p].push_back(i + 1); //정점p의 자식노드로 (i+1)노드 추가
    }
}

//정점v -> 정점u로가는 경로의 모든 가중치합이 
//정점u의 값보다 큰 모든정점을 구하고(sad)
//현재 트리의 말단정점 번호들을 전부찾는함수(tail)
void findSadVertex() {
    //BFS 사용
    bool visited[MAX]{};
    for (int i = 0; i < passVertex.size(); i++) //사용하지않을 정점들을 모두 체크
        visited[passVertex[i]] = true;

    queue<pil> q; //정점v, 지금까지가중치합s
    queue<int> dist; //정점1과 현재정점v 간의 거리
    q.push({1, 0});
    dist.push(0);
    visited[1] = true;

    //모든 정점를 탐색, 슬픈정점을 모두 찾음
    while (!q.empty()) {
        int v = q.front().first;
        ll s = q.front().second;
        int d = dist.front();
        q.pop();
        dist.pop();

        if (!child[v].size()){ //만약 현재정점이 자식이없다면 말단정점
            tail.push_back(v);
            continue;
        }

        for (int i = 0; i < child[v].size(); i++) {
            int vv = child[v][i];
            int dd = d + 1;
            if (visited[vv]) continue; //방문한 점이면 제외
            ll ss = s + edge[vv]; //자식정점vv와 부모인v가연결된 가중치합을 더함

            if (ss > V[vv]) { //지금까지 가중치합이 자식정점vv의 값보다 크면 슬프다.
                sad.push_back({ vv, dd });
            }

            visited[vv] = true;
            q.push({ vv, ss }); //자식정점과 지금까지 가중치합을 큐에넣고 BFS
            dist.push(dd);
        }
    }

}

void func() {
    
    //for (int i = 0; i < sad.size(); i++)
    //    printf("정점%d, 거리%d\n", sad[i].first, sad[i].second);
    //printf("\n");
    //for (int i = 0; i < tail.size(); i++)
    //    printf("말단정점%d\n", tail[i]);

    //구해진 말단정점을 하나씩 잘라보고
    //잘라내는과정 : 부모노드에서 자식노드요소를 제거함
    //tail갯수만큼 res++
    //sad,tail초기화
    //다시 findSadVertex실행, 슬픈정점이 아직도있으면 위 과정반복
    
    findSadVertex();//슬픈정점과 말단정점을 찾는다.

    while (!sad.empty()) {
        //모든 말단정점을 탐색하여 부모를 찾아 자식요소임을 제거
        for (int i = 0; i < tail.size(); i++) {
            int v = tail[i]; //말단정점
            int pv = parent[v]; //말단정점의 부모정점
            for (int j = 0; j < child[pv].size(); j++) { //부모정점의 자식정점탐색
                int cv = child[pv][j];
                if (cv == v) { //현재 말단정점v를 찾으면
                    child[pv].erase(child[pv].begin() + j); //말단정점을 자식요소에서 제거
                    break;
                }
            }

            passVertex.push_back(v); //현재 말단정점은 앞으로 사용되지 않을것
        }
        res += tail.size();
        sad.clear();
        tail.clear();
        findSadVertex();//다시 슬픈정점과 말단정점을 찾는다.
    }
    
    printf("%lld", res);
}

int main(void) {
    init();
    func();


    return 0;
}