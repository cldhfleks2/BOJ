#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
#define MAX 1//원하는크기
const int IMAX = INT32_MAX; const int IMIN = INT32_MIN;
const long long LMAX = LLONG_MAX; const long long LMIN = LLONG_MIN;
const long double PI = 3.141592653589793238462643383279502884197;
using std::vector; using std::stack; using std::queue; using std::tuple; using std::set;
using std::list; using std::bitset; using std::string; using std::priority_queue;
using std::pair; using std::greater; using std::tie; using std::sort;
using std::max_element; using std::min_element; using std::fill; using std::stoi;
using std::stod; using std::stof; using std::stol; using std::stold; using std::stoll;
using std::stoul; using std::stoull; using std::max;
using std::min;
///////////////////////////////////////////////////////////
//1. KMP
struct KMPAlgorithm {
	vector<int> makeFailureTable(string P) {
		int lenP = P.length();
		vector<int> F(lenP, 0); //lenP만큼 0으로 초기화된 벡터 생성
		
		for (int i = 1, j = 0; i < lenP; i++) {
			while (j > 0 && P[i] != P[j])
				j = F[i - 1];

			if (P[i] == P[j])
				F[i] = ++j;
		}

		return F;
	}

	vector<int> KMP(string T, string P) {
		int lenT = T.length();
		int lenP = P.length();
		vector<int> F = makeFailureTable(P);
		vector<int> res;
		for (int i = 0, j = 0; i < lenP; i++) {
			while (j > 0 && T[i] != P[j])
				j = F[i - 1];
			if (T[i] == P[j]) {
				if (j == lenP - 1)
					res.push_back(i - lenP + 1);
				else
					++j;
			}
		}

		return res;
	}

};
////////////////////////////////////////////////////////////////////
//2. Dijkstra
struct DijkstraAlgorithm{
	vector<pair<int, int>> edge[99999]; //edge[v1].push_back({v2, d}):v1과v2가 연결되고 가중치는d

	//탐색시작위치, 탐색 종료위치, 연결관계정2차원벡터, 정점갯수를 건네 받는다.
	int Dijkstra(int start, int end, vector<pair<int, int>>(&edge)[99999], int cnt) {
		vector<int> dist(cnt + 1, 0x7fffffff); //모든 정점에대해 기록할것, 초깃값으로 int 최댓값
		priority_queue<pair<int, int>> pq; //우선순위큐에 {-(가중치), 정점}로 저장할것
		pq.push({ -0, start }); //처음 시작위치와 그 최소 가중치를 저장.

		while (!pq.empty()) {
			//우선순위큐에서 정점 정보 꺼내기
			int v = pq.top().second;
			int d = pq.top().first;
			pq.pop();

			if (v == end) break; //종료위치 도달시 종료.
			//정점v와 연결된 모든 정점들을 탐색
			for (int i = 0; i < edge[v].size(); i++) { //정점v와 연결된 모든 정점들을 탐색
				int vv = edge[v][i].first;
				int dd = edge[v][i].second;
				
				if (dist[vv] > dist[v] + dd) {
					dist[vv] = dist[v] + dd;
					pq.push({ -dd, vv });
				}
			}
		}
		return -1;
	}


};
////////////////////////////////////////////////////////////////////
//3. Floyd-Warshall
struct FloydAlgorithm {
	int W[999][999];

	void floyd(int N) {
		for (int k = 0; k < N; k++) { //i -> j 로가는길에 거쳐갈 정점k
			for (int i = 0; i < k; i++)
				for (int j = 0; j < k; j++)
					//i->j    VS    i->k->j 중 최솟값으로 W[i][j]를 갱신
					W[i][j] = std::min(W[i][j], W[i][k] + W[k][j]);
		}
	}

};

////////////////////////////////////////////////////////////////////
//4.

////////////////////////////////////////////////////////////////////
//5.

////////////////////////////////////////////////////////////////////
//6.

////////////////////////////////////////////////////////////////////
//7.

////////////////////////////////////////////////////////////////////
//8.

////////////////////////////////////////////////////////////////////
//9.

////////////////////////////////////////////////////////////////////
//10.

////////////////////////////////////////////////////////////////////
//11.

