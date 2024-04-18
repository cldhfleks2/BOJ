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
ll V[MAX]; //������ ���ΰ�
int parent[MAX]; //�� ������ �θ� ����
vector<int> child[MAX]; //�� ������ �ڽĳ�带 ����
ll edge[MAX]; //�� ������ �θ�� ����� ������ ����ġ��
vector<pii> sad; //���� ������ȣv, ����1���� ������ �Ÿ�
vector<int> tail; //���� ��� ��ȣ��
vector<int> passVertex;
ll res;

void init();
void func();
void findSadVertex();
void init() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
        scanf("%d", &V[i]);

    for (int i = 1; i < N ; i++) { //N-1���ٿ� p1~pN-1�� c1~cN-1�� ����
        int p, c;
        scanf("%lld%lld", &p, &c);
        parent[i+1] = p; //(i+1)������ �θ�� ����p�̴�.
        edge[i + 1] = c; //(i+1)������ �θ���� ������ ����ġ��c
        child[p].push_back(i + 1); //����p�� �ڽĳ��� (i+1)��� �߰�
    }
}

//����v -> ����u�ΰ��� ����� ��� ����ġ���� 
//����u�� ������ ū ��������� ���ϰ�(sad)
//���� Ʈ���� �������� ��ȣ���� ����ã���Լ�(tail)
void findSadVertex() {
    //BFS ���
    bool visited[MAX]{};
    for (int i = 0; i < passVertex.size(); i++) //����������� �������� ��� üũ
        visited[passVertex[i]] = true;

    queue<pil> q; //����v, ���ݱ�������ġ��s
    queue<int> dist; //����1�� ��������v ���� �Ÿ�
    q.push({1, 0});
    dist.push(0);
    visited[1] = true;

    //��� ������ Ž��, ���������� ��� ã��
    while (!q.empty()) {
        int v = q.front().first;
        ll s = q.front().second;
        int d = dist.front();
        q.pop();
        dist.pop();

        if (!child[v].size()){ //���� ���������� �ڽ��̾��ٸ� ��������
            tail.push_back(v);
            continue;
        }

        for (int i = 0; i < child[v].size(); i++) {
            int vv = child[v][i];
            int dd = d + 1;
            if (visited[vv]) continue; //�湮�� ���̸� ����
            ll ss = s + edge[vv]; //�ڽ�����vv�� �θ���v������� ����ġ���� ����

            if (ss > V[vv]) { //���ݱ��� ����ġ���� �ڽ�����vv�� ������ ũ�� ������.
                sad.push_back({ vv, dd });
            }

            visited[vv] = true;
            q.push({ vv, ss }); //�ڽ������� ���ݱ��� ����ġ���� ť���ְ� BFS
            dist.push(dd);
        }
    }

}

void func() {
    
    //for (int i = 0; i < sad.size(); i++)
    //    printf("����%d, �Ÿ�%d\n", sad[i].first, sad[i].second);
    //printf("\n");
    //for (int i = 0; i < tail.size(); i++)
    //    printf("��������%d\n", tail[i]);

    //������ ���������� �ϳ��� �߶󺸰�
    //�߶󳻴°��� : �θ��忡�� �ڽĳ���Ҹ� ������
    //tail������ŭ res++
    //sad,tail�ʱ�ȭ
    //�ٽ� findSadVertex����, ���������� ������������ �� �����ݺ�
    
    findSadVertex();//���������� ���������� ã�´�.

    while (!sad.empty()) {
        //��� ���������� Ž���Ͽ� �θ� ã�� �ڽĿ������ ����
        for (int i = 0; i < tail.size(); i++) {
            int v = tail[i]; //��������
            int pv = parent[v]; //���������� �θ�����
            for (int j = 0; j < child[pv].size(); j++) { //�θ������� �ڽ�����Ž��
                int cv = child[pv][j];
                if (cv == v) { //���� ��������v�� ã����
                    child[pv].erase(child[pv].begin() + j); //���������� �ڽĿ�ҿ��� ����
                    break;
                }
            }

            passVertex.push_back(v); //���� ���������� ������ ������ ������
        }
        res += tail.size();
        sad.clear();
        tail.clear();
        findSadVertex();//�ٽ� ���������� ���������� ã�´�.
    }
    
    printf("%lld", res);
}

int main(void) {
    init();
    func();


    return 0;
}