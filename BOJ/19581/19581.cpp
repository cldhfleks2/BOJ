#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
#define MAX 100001
using std::vector; using std::stack; using std::queue;
using std::deque; using std::string; using std::pair;
using std::sort; using std::max; using std::min;
using std::make_pair; using std::max_element; using std::min_element;
using std::fill;
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
vector<pii> edge[MAX]; //간선 정보, 가중치
bool visited[MAX];
ll weight[MAX]; //정점
void init();
void func();
pil bfs(int n, int remove=0);
void init() {
    scanf("%d", &N);
    for (int i = 0; i < N - 1; i++) {
        int ver1, ver2, value;
        scanf("%d%d%d", &ver1, &ver2, &value);
        edge[ver1].push_back({ ver2, value });
        edge[ver2].push_back({ ver1, value });
    }
}

void func() {
    int a = bfs(1).first; //임의정점으로부터 가장 먼 정점a를 구함
    int b = bfs(a).first; //정점a로 부터 가장 먼 정점b를 구함
    //정점a로부터 가장먼 정점b를 제외한 그다음 정점까지의 거리를 출력
    printf("%lld", max(bfs(a, b).second, bfs(b, a).second));
}

//점 n에서 가장 먼 점의 번호와 두 정점사이 거리를 리턴
//remove:제외할 정점 
pil bfs(int n, int remove) {
    fill(visited, visited + N + 1, false);
    fill(weight, weight + N + 1, 0);
    queue<int> q;
    q.push(n);
    visited[n] = true;
    visited[remove] = true; //제외할정점은 미리 체크
    int max = 0;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int i = 0; i < edge[v].size(); i++) {
            int vv = edge[v][i].first;
            int value = edge[v][i].second;
            //printf("%d >> vv:%d, visited[vv]:%d   weight[vv]:%lld\n", v, vv, visited[vv], weight[vv]);
            if (visited[vv]) continue;
            visited[vv] = true;
            //다음 정점의 거리는 두정점간의 가중치 + 현재정점의 가중치
            weight[vv] = value + weight[v];
            q.push(vv);
            //printf(">>>>>>>>weight[vv]:%lld\n", weight[vv]);
        }
    }

    ll* res = max_element(weight + 1, weight + N + 1);//구한 모든 거리값중 큰값을 참조
    return { res - weight , *res }; 
}

int main(void) {
    init();
    func();


    return 0;
}