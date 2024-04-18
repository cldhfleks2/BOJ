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
vector<pii> edge[MAX]; //���� ����, ����ġ
bool visited[MAX];
ll weight[MAX]; //����
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
    int a = bfs(1).first; //�����������κ��� ���� �� ����a�� ����
    int b = bfs(a).first; //����a�� ���� ���� �� ����b�� ����
    //����a�κ��� ����� ����b�� ������ �״��� ���������� �Ÿ��� ���
    printf("%lld", max(bfs(a, b).second, bfs(b, a).second));
}

//�� n���� ���� �� ���� ��ȣ�� �� �������� �Ÿ��� ����
//remove:������ ���� 
pil bfs(int n, int remove) {
    fill(visited, visited + N + 1, false);
    fill(weight, weight + N + 1, 0);
    queue<int> q;
    q.push(n);
    visited[n] = true;
    visited[remove] = true; //������������ �̸� üũ
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
            //���� ������ �Ÿ��� ���������� ����ġ + ���������� ����ġ
            weight[vv] = value + weight[v];
            q.push(vv);
            //printf(">>>>>>>>weight[vv]:%lld\n", weight[vv]);
        }
    }

    ll* res = max_element(weight + 1, weight + N + 1);//���� ��� �Ÿ����� ū���� ����
    return { res - weight , *res }; 
}

int main(void) {
    init();
    func();


    return 0;
}