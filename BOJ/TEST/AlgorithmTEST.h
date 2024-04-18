#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
#define MAX 1//���ϴ�ũ��
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
		vector<int> F(lenP, 0); //lenP��ŭ 0���� �ʱ�ȭ�� ���� ����
		
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
	vector<pair<int, int>> edge[99999]; //edge[v1].push_back({v2, d}):v1��v2�� ����ǰ� ����ġ��d

	//Ž��������ġ, Ž�� ������ġ, ���������2��������, ���������� �ǳ� �޴´�.
	int Dijkstra(int start, int end, vector<pair<int, int>>(&edge)[99999], int cnt) {
		vector<int> dist(cnt + 1, 0x7fffffff); //��� ���������� ����Ұ�, �ʱ갪���� int �ִ�
		priority_queue<pair<int, int>> pq; //�켱����ť�� {-(����ġ), ����}�� �����Ұ�
		pq.push({ -0, start }); //ó�� ������ġ�� �� �ּ� ����ġ�� ����.

		while (!pq.empty()) {
			//�켱����ť���� ���� ���� ������
			int v = pq.top().second;
			int d = pq.top().first;
			pq.pop();

			if (v == end) break; //������ġ ���޽� ����.
			//����v�� ����� ��� �������� Ž��
			for (int i = 0; i < edge[v].size(); i++) { //����v�� ����� ��� �������� Ž��
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
		for (int k = 0; k < N; k++) { //i -> j �ΰ��±濡 ���İ� ����k
			for (int i = 0; i < k; i++)
				for (int j = 0; j < k; j++)
					//i->j    VS    i->k->j �� �ּڰ����� W[i][j]�� ����
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

