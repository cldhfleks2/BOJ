#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>
using std::vector;
typedef long long ll;

struct INFO {
	int v1, v2;
	ll w;
	bool operator < (INFO another) { //sort함수 사용을 위한 비교연산자 재정의
		return w < another.w;
	}
};

int P[10001]; //정점의 부모정점이 무엇인지 기록 
int v, e; //정점갯수, 간선갯수
vector<INFO> edge;

//현재 정점의 루트정점이 누군지 경로압축하며 찾음
int getParent(int x) {
	if (P[x] == x) return P[x];
	//현재 P[x]는 x의 부모정점. 이 부모정점의 부모를 거슬러 올라가 P[x]로 기록
	else return P[x] = getParent(P[x]); 
}

//두 정점을 하나의 집합으로(루트정점이 동일하게)
void unionParent(int x, int y) {
	x = getParent(x);
	y = getParent(y);
	if (x < y) P[y] = x; //더 작은 정점번호로 합침
	else P[x] = y;
}

//두 정점이 같은 집합인지
bool isSet(int x, int y) {
	return getParent(x) == getParent(y); //P[x] == P[y]로 하면 오류!!!
}

void init() {
	scanf("%d%d", &v, &e);
	//P배열 초기화
	for (int i = 1; i <= v; i++)
		P[i] = i;

	//연결정보 기록
	for (int _ = 0, v1, v2; _ < e; _++) {
		ll w;
		scanf("%d%d%lld", &v1, &v2, &w);
		edge.push_back({ v1, v2, w });
	}
}

int main(void) {
	init();

	sort(edge.begin(), edge.end()); //가중치로 오름차순 정렬

	ll sum = 0; //MST 가중치의 합
	for (int i = 0; i < e; i++) { //모든 간선을 확인
		int v1 = edge[i].v1;
		int v2 = edge[i].v2;
		ll w = edge[i].w;
		if (!isSet(v1, v2)) { //두 정점이 다른 집합일때(사이클이 없을때)만 MST로 추가
			sum += w;
			unionParent(v1, v2); //추가한뒤 두 정점을 하나의 집합으로 합침
		}
	}

	printf("%lld", sum);

	return 0;
}