#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>
using std::vector;
typedef long long ll;

struct INFO {
	int v1, v2;
	ll w;
	bool operator < (INFO another) { //sort�Լ� ����� ���� �񱳿����� ������
		return w < another.w;
	}
};

int P[10001]; //������ �θ������� �������� ��� 
int v, e; //��������, ��������
vector<INFO> edge;

//���� ������ ��Ʈ������ ������ ��ξ����ϸ� ã��
int getParent(int x) {
	if (P[x] == x) return P[x];
	//���� P[x]�� x�� �θ�����. �� �θ������� �θ� �Ž��� �ö� P[x]�� ���
	else return P[x] = getParent(P[x]); 
}

//�� ������ �ϳ��� ��������(��Ʈ������ �����ϰ�)
void unionParent(int x, int y) {
	x = getParent(x);
	y = getParent(y);
	if (x < y) P[y] = x; //�� ���� ������ȣ�� ��ħ
	else P[x] = y;
}

//�� ������ ���� ��������
bool isSet(int x, int y) {
	return getParent(x) == getParent(y); //P[x] == P[y]�� �ϸ� ����!!!
}

void init() {
	scanf("%d%d", &v, &e);
	//P�迭 �ʱ�ȭ
	for (int i = 1; i <= v; i++)
		P[i] = i;

	//�������� ���
	for (int _ = 0, v1, v2; _ < e; _++) {
		ll w;
		scanf("%d%d%lld", &v1, &v2, &w);
		edge.push_back({ v1, v2, w });
	}
}

int main(void) {
	init();

	sort(edge.begin(), edge.end()); //����ġ�� �������� ����

	ll sum = 0; //MST ����ġ�� ��
	for (int i = 0; i < e; i++) { //��� ������ Ȯ��
		int v1 = edge[i].v1;
		int v2 = edge[i].v2;
		ll w = edge[i].w;
		if (!isSet(v1, v2)) { //�� ������ �ٸ� �����϶�(����Ŭ�� ������)�� MST�� �߰�
			sum += w;
			unionParent(v1, v2); //�߰��ѵ� �� ������ �ϳ��� �������� ��ħ
		}
	}

	printf("%lld", sum);

	return 0;
}