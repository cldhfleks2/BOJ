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
//using std::map;
////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
////[1] KMP, Knuth Morris Pratt/////////////////////////////////////////////////////////
struct KMP_ALGORITHM {
	//1. �����Լ� : �������̺� �ۼ��ϴ� �Լ�
	//F[i] : �ε���0 ~ �ε���i������ ���λ�� ���̻簡 ��ġ�ϴ� �ִ����
	vector<int> makeFailureTable(string pattern) {
		int lenP = pattern.length();
		vector<int> F(lenP, 0); //FailureTables, M����ũ�⸦������ ��� 0���� �ʱ�ȭ

		F[0] = 0;
		for (int i = 1, j = 0; i < lenP; i++) {
			//Ž���� �����Ѱ��, ���� ���ڿ��� 0���ε������� �ٽ� Ž���ϴ°��� �ƴ϶�
			//���� ���̺��� �̿��� �ռ� ��ġ�ߴ� �κ��� �ǳʶ��� Ž���� �̾��(ȿ����)
			while (j > 0 && pattern[i] != pattern[j])
				j = F[j - 1];
			//Ž���� �����Ѱ�� ���̺��� �ۼ��Ѵ�.(�ε���0 ~ �ε���i ����)
			if (pattern[i] == pattern[j])
				F[i] = ++j;
		}
		return F;
	}
	//2. KMP : �������̺��� ������ ���� ���ڿ��� Ž���Ѵ�.
	vector<int> KMP(string text, string pattern) {
		int lenT = text.length();
		int lenP = pattern.length();
		vector<int> F = makeFailureTable(pattern); //��ó�� : �������̺��� �ۼ�
		vector<int> findStartIndex; //Ž���� �����Ѱ�� ã�� ������ġ

		for (int i = 0, j = 0; i < lenT; i++) {
			//Ž������(���� �ϳ�)
			while (j > 0 && text[i] != pattern[j]) //�����Լ��� ���鶧�� ��������
				j = F[j - 1];
			//Ž������(���� �ϳ�)
			if (text[i] == pattern[j]) { //�����ڿ����� ã�����ϴ� ���ڿ��� ã�����
				if (j == lenP - 1) {
					findStartIndex.push_back((i - lenP) + 1); //ã�� �κй��ڿ��� �����ε����� ����
					j = F[j]; //j = F[lenP - 1]������. => �̾ Ž���� �����ϱ����� �ʿ�
				}
				else
					//F[i] = ++j;
					++j; //�����Լ��ʹٸ���, ���̺��� ������ �ʿ� ����
			}
		}

		return findStartIndex;
	}
};
////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
////[2] Dijstra/////////////////////////////////////////////////////////////////////////
//O(E log N)
//���� ����ġ�� ������, �׷����� Ư�� �� ���� ���� �ּҰŸ� ���Ҷ�
struct Dijstra_ALGORITM {
	vector<pair<int, int>> edge[11111]; //<���������, ����ġ>
	int dijstra(int start, int end, vector<pair<int, int>>(&edge)[11111], int N) {
		vector<int> dist(N + 1, 0x7fffffff);
		priority_queue<pair<int, int>> pq;

		dist[start] = 0;
		pq.push({ -0, start }); //����ġ�� ������(0�� �����)���� ���ĵǵ���

		//�켱���� ť�� �������� �ݺ�
		while (!pq.empty()) {
			int v = pq.top().second;
			int d = -pq.top().first;
			pq.pop();

			if (v == end) return d;

			for (int i = 0; i < edge[v].size(); i++) {
				int dd = edge[v][i].second;
				int vv = edge[v][i].first;

				if (dist[vv] > dist[v] + dd) {
					dist[vv] = dist[v] + dd;
					pq.push({ -dist[vv], vv }); //����ġ, ������ġ ����
				}
			}
		}

		return -1;
	}
};
////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
////[3] Floyd-Warshall//////////////////////////////////////////////////////////////////
//O(N^3)
//��, ���� ����ġ ������, �׷����� ��� ���������� �ּҰŸ����ϱ�
struct Floyd_ALTORITHM {
	int W[1111][1111];
	//1. �ۼ��� 2���� ���̺��� ���޹޴°��
	//2���� ���̺�([i][j])�� �ܹ��� ���� ������ ����. 
	//2���� ���̺��� i == j �ΰ�� 0, �׿ܴ� �����Ѱ��� �����Ѵ�.
	void floyd(int(&W)[1111][1111], int N) {
		//1-1. �÷��̵� ����
		for (int k = 0; k < N; k++) {
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					W[i][j] = min(W[i][j], W[i][k] + W[k][j]);
				}
			}
		}
	}

	//2. ���������� �Է¹޾� 2�������̺��� ����� ���� ���
	void floyd(int N) {
		//2-1. 2�������̺��� i == j �ΰ�� 0, �׿ܴ� �����Ѱ��� �����Ѵ�.
		int W[111][111];
		for (int i = 0; i < 111; i++) {
			for (int j = 0; j < 111; j++) {
				if (i == j)
					W[i][j] = 0;
				else
					W[i][j] = 0x7fffffff;
			}
		}
		//2-2. �ܹ��� ������ �Է� �޾� 2�������̺��� �ϼ��Ѵ�.
		;;;;;;;;
		//2-3. �÷��̵� ����
		for (int k = 0; k < N; k++) {
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					W[i][j] = min(W[i][j], W[i][k] + W[k][j]);
				}
			}
		}
	}
};
////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
////[4] SCC, Strongly Connected Component///////////////////////////////////////////////
struct SCC_ALGORITHM { 
	int idx, P[MAX]; //MAX : ������ �� ����
	vector<int> edge[MAX]; //�ܹ��� ���� ����
	stack<int> S;
	bool visited[MAX]; 
	vector<vector<int>> SCC; //ã�� ��� SCC�Ǳ������� vector<int>�� ����

	////1.DFS ����
	int DFSinSCC(int x) {
		P[x] = ++idx; //������ȣ�� 1���� �����Ҷ�
		S.push(x); 

		int parent = P[x]; //���� SCC�� �θ����� ��ȣ(SCC�������� ���� ���� ��ȣ��)
		for (int i = 0; i < edge[x].size(); i++) {
			int y = edge[x][i]; //x�� ����� �ٸ��� y
			if (P[y] == 0) //����y�� �θ� �������� �ʾ������
				parent = min(parent, DFSinSCC(y)); //���� SCC�� ���ϵ��� DFS����
			else if (!visited[y]) //����y�� �θ𰡼������ְ� SCC�� �������ʾ�����
				parent = min(parent, P[y]); //���� SCC�� ����y�� ���ϵ���
		}

		//DFS��ȯ�ϸ� ���� SCC�� �θ������̶�� SCC�� ���ؾ���.
		if (parent == P[x]) {
			vector<int> scc;
			while (x) {
				int y = S.top();
				S.pop();
				visited[y] = true;
				scc.push_back(y);
				if (y == x) break; //SCC�� �θ�������ȣ�� ������ ����
			}
			SCC.push_back(scc);
		}

		return parent;
	}

	//2. SCC
	void makeSCC(int N) {
		for (int i = 0; i < N; i++)  
			if (P[i] == 0)  DFSinSCC(i);//P[]�� ������������ ��� ������ DFS ����
	}
};
////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
////[5] DSU, Disjoint Set UnionFind/////////////////////////////////////////////////////
//Find�� Union �ΰ��� �ʼ����
struct DSU_ALGORITHM { 
	//MAX : ������ �ִ� ����
	int PARENT[MAX];
	//1. �θ��带 �������� �Լ�
	//���Ҹ� ��ξ����ϸ� �θ� ��ǥ���ҷ� �缳���ϴ��Լ�
	int Find(int x) {
		if (PARENT[x] == x) return x;
		//return Find(parent[x]); //�θ��带 ������
		return PARENT[x] = Find(PARENT[x]); //(��ξ��� ���)�θ� ã��
	}

	//2. �� ���Ҹ� �ϳ��� �������� ��ġ�� �Լ�
	void Union(int x, int y) {
		x = Find(x);
		y = Find(y);
		PARENT[y] = x; //�� ���Ҹ� �ٸ����Ұ� ���� �θ����� ���η� ����
		//PARENT[x] = y : �̷��� �ص� �������.��
	}

	//3. (����)�� ���Ұ� ���� �������� Ȯ���ϴ� �Լ�
	bool isConnect(int x, int y) {
		return Find(x) == Find(y); //�� ������ �θ� ������ �����Ѵ�.
	}

	//4. (����)DSU�Լ�
	void DSU() {
		//�Է����޾� �������� �θ� �������� PARENT�� ���
		;;
		//�� ���Ұ� ���� �����̶��  Union�Լ� ���
		;;
		//�� ���Ұ� ���� �������� Ȯ���Ϸ��� isConnect�Լ� ��� 
		;;
	}
};
////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
////[6] Rabin Karp//////////////////////////////////////////////////////////////////////
//Ž���� �ؽ����� �迭�� �����Ϸ��� % MOD�� �̿��ض�
//�ؽ����� ������ ���ü��ֱ⶧��. �׷��� ���������͵� �����Ѱ��̹Ƿ� Ž������ �����̾���.
struct RabinKarp_ALGORITHM {
	void RabinKarp(string text, string pattern) {
		int lenP = pattern.length();
		int lenT = text.length();
		long long hashP = 0; //���ڿ� pattern�� ��ü �ؽ���
		long long hashT = 0; //���� text���� Ž������ �ؽ���(���� lenP)
		int pow = 1; //�ڸ������� ������ ������
		int spec = 3; //����ڰ� ������ ������ ����. �ƹ����ڳ� �������

		for (int i = 0; i <= lenT - lenP; i++) { //text�� ������ Ž���� �ʿ����
			if (i == 0) { //�ʱ갪
				for (int j = 0; j < lenP; j++) {
					int idx = lenP - j - 1;
					hashT += text[idx] * pow;
					hashP += pattern[idx] * pow;
					if (j < lenP - 1) pow *= spec;
				}
			}
			else { //��ȭ���̿�
				hashT = spec * //���Ϸ��� ������ �ڷ� �и��� �����ؽ����� spec��ŭ ����������/
					(hashT - text[i - 1] * pow) //��ü�ؽ��� - �Ǿ�(����)������ �ؽ���
					+ text[lenP - 1 + i]; //���� Ž���� ���ڿ��� �ؽ���
			}
			if (hashT == hashP) { //�ؽ����� ��ġ�Ѵ� => Ž���� �����������ɼ�������
				bool isFind = true;
				for (int j = 0; j < lenP; j++) {
					if (text[i + j] != pattern[j]) { //Ž���� �����Ѱ��
						isFind = false;
						break;
					}
				}
				if (isFind) {
					//TO-DO : Ž�������� ���ϴ� ������ �ۼ�
				}
			}
		}
	}

};
////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
////[7] LCS, Longest common substring /////////////////////////////////////////////////////
struct LCS_ALGORITHM {
	char str1[1001], str2[1001];

	//���������� ǥ���� str1, str2���� ������ �ִ� Ž�����̸� ���޹޾� 
	//str1[n-1], str2[m-1]������ �ִ� ����κ� ������ ���̸� �����ϴ� �Լ� 
	int LCS(int n, int m) {
		int dp[1001][1001]; //dp 2���� ���̺� �غ�

		//dp���̺� �ʱ�ȭ (�����հ��� �κ����յ鸸 0����)
		for (int i = 0; i < n + 1; i++) dp[i][0] = 0;
		for (int j = 0; j < m + 1; j++) dp[0][j] = 0;
	
		for (int i = 1; i < n + 1; i++)
			for (int j = 1; j < m + 1; j++)
				if (str1[i - 1] == str2[j - 1])
					dp[i][j] = dp[i - 1][j - 1] + 1; //���������� �ִ���� + 1
				else
					dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]); //str1,str2�� ���� ���繮�ڸ� ������ �ִ������ �ִ�

		return dp[n][m]; //ã�� ���� ����
	}
};
////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
////[8] MSIS, Max Sum Increase Subsequence /////////////////////////////////////////////////////
struct MSIS_ALGORITHM {
	int MSIS(vector<int> const& arr) {
		//���Ұ��� �� ���
		if (arr.empty()) return 0;
		
		//DP�� ���ɰ�.
		vector<int> dp(arr.size());

		//�ʱ갪
		dp[0] = arr[0];

		for (int i = 1; i < arr.size(); i++) {
			//j < i�� ��� j������ arr�� �����ϰ��ְ�, 
			//������(dp[j])�� �����ִ���dp[i]���� ũ�� dp[i]�� dp[j]�� ����
			for (int j = 0; j < i; j++) 
				if (arr[j] < arr[i] && dp[j] > dp[i]) dp[i] = dp[j];

			//���� arr[i]�� dp�� ���Խ�Ŵ
			dp[i] += arr[i];
		}

		// ã�� 0~i������ �κм����� �ִ��� �� �ִ� �κм����� ���� ã�Ƽ� ����
		int res = 0;
		for (int x : dp) res = std::max(res, x);
		return res;
	}
};
////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
////[9] BinarySearch  /////////////////////////////////////////////////////
//LowerBound, UpperBound�� ����
struct BinarySearch_ALGORITHM {
	//arr���� ����k�� ��ġ�ε����� ã�Ƽ� �����ϴ� �Լ�
	int BinarySearch(vector<int>& arr, int k) {
		int left = 0, right = arr.size() - 1;
		while (left <= right) {
			int mid = (left + right) / 2;
			if (arr[mid] == k)
				return mid;
			else if (k < arr[mid])
				right = mid - 1;
			else if (arr[mid] < k)
				left = mid;
		}
		return -1; //ã�� ���Ͽ���.
	}

	//1. arr���� k�̻��� ���� ó�������� �ε����� ã�� �Լ�
	//arr���� k�̻��� ���� ó�������� �ε����� ã�� �Լ�
	int LowerBound(vector<int>& arr, int k) {
		int left = 0, right = arr.size() - 1;

		while (left < right) {
			int mid = (left + right) / 2;
			if (k <= arr[mid]) //k�̻��� ���̸�
				right = mid; //���ʺκ��� Ž��
			else               //k�̸��� ���̸�
				left = mid + 1; //�����ʺκ��� Ž��
		}

		return right;
	}

	//2. arr���� k�ʰ��� ���� ó�������� �ε����� ã�� �Լ�
	//arr���� k�ʰ��� ���� ó�������� �ε����� ã�� �Լ�
	int UpperBound(vector<int>& arr, int k) {
		int left = 0, right = arr.size() - 1;

		while (left < right) {
			int mid = (left + right) / 2;
			if (k < arr[mid])
				right = mid;
			else
				left = mid + 1;

		}

		return right;
	}
};
////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
////[10] LIS, Longest Increasing Subsequence /////////////////////////////////////////////////////
struct LIS_ALGORITHM {
	//1. DP�� �̿��� LIS�� ���� �Լ�
	//LIS���̸� ���� �� �ִ�.
	int LISwithDP(vector<int>& arr) {
		if (arr.empty()) return 0;

		vector<int> dp(arr.size());

		for (int i = 0; i < arr.size(); i++) {
			//i���� ���� j������ ��� �����ϴ°����� 
			//�ּ��� �ڱ��ڽ����θ� �̷���� LIS�� ���簡��
			dp[i] = 1; 

			for (int j = 0; j < i; j++) 
				if (arr[j] < arr[i]) 
					dp[i] = max(dp[i], dp[j] + 1);
		}
		
		return dp[arr.size() - 1];
	}

	//�Ʒ��� LIS�� ���� LowerBound�Լ�
	int LowerBound(vector<int>& lis, int k) {
		int L = 0, R = lis.size() - 1;
		while (L < R) {
			int M = (L + R) / 2;
			if (k <= lis[M])
				R = M;
			else
				L = M + 1;
		}
		return R;
	}

	//2. LowerBound�� �̿��Ͽ� LIS�� ���ϴ� �Լ�
	//������� LIS�迭�� ������ �ڼ���, 
	//���� arr�� � ��Ұ� LIS�� �̷������ Ȯ�� ����
	int LISwithBinarySearch(vector<int>& arr) {
		if (arr.empty()) return 0;

		vector<int> lis(arr.size());
		lis.push_back(arr[0]);
		for (int i = 1; i < arr.size(); i++) {
			if (lis.back() < arr[i]) 
				lis.push_back(arr[i]);
			else //lis�� arr[i]�� �� ��������ġ�� LowerBound�� ã�Ƽ�
				//�ش���ġ�� arr[i]�� ����
				lis[LowerBound(lis, arr[i])] = arr[i]; 
		}
		
		return lis.size(); //������� lis �迭�� �����մϴ�.
	}
};
////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
////[11] Trie DataStructure  /////////////////////////////////////////////////////
struct Trie {
	Trie* node[26]; //��带 ��Ÿ���� ������
	bool finish; //�� ��帶�� ���� ��尡 ���ڿ� ������ üũ
				 //���ڿ� ���̶����� �ش� ���ڷ� ������ ���ڿ��� ����������� �ǹ�

	//1. ������ : �ʱ�ȭ. ����, finish=false
	Trie() : node(), finish(false){} 

	//2. ���ڿ��� Trie �ڷᱸ���� ����� �Լ�.
	//Trie�����͸� �̿��� ����� ����
	void insert(char* str) {
		if (*str == '\0') { //2-1. ���ڿ� ���̸� finishüũ�� ����
			finish = true;
			return;
		}
		int cur = *str - 'A'; //'A'~'Z' ���ڸ� ���� 0~25�� ��ȯ
		if (node[cur] == nullptr)   //2-2. node[cur]�� �����ϸ� cur�� �ش��ϴ� ���ڰ�
			node[cur] = new Trie(); //�����ϴ°�. �̹� �����ϸ� ����������
									//Trie���� Ư���� Ʈ�������̴�. �̹� �����ϸ�
									//������� ��带 Ÿ�� ���� �������°�.
		node[cur]->insert(str + 1); //������� ����� insert�� �����Ŵ(���)
	}

	//3. ���ڿ� �˻�1(��Ȯ�� ��ġ�ϴ°� �ִ���)
	//Trie�����͸� �̿��� ����� ����
	bool find(char* str) {
		//3-1. �˻����ڿ� �� + 1 �ε�������������, ��üũ�� �ȵ������� �˻� ����
		if (*str == '\0' && !finish) return false; 
		//3-2. �˻����ڿ� �� + 1 �ε��������԰� ��üũ
		if (*str == '\0' && finish) return true;
		//3-2. �˻����ڿ� ��ü�� �������� �ʴ°��
		int cur = *str - 'A';
		if (node[cur] == nullptr) return false;
		return node[cur]->find(str + 1);
	}

	//4. ���ڿ��˻�2(���ڿ�+a �� �ִ���)
	//Trie�����͸� �̿��� ����� ����
	bool findPrefix(char* str) {
		//4-1. ã����� (3-1 �� 3-2�� ��ģ�����.)
		if (finish) return true;

		//4-2. 4-1�� �ش������ʰ� �˻����߿� ���ڿ� ���� �����Ѱ�� Ž������
		if (*str == '\0') return false;

		//4-3. 4-1�ڵ�� 4-2�ڵ��� ��ġ�� �ٲ۴ٸ�
		//�Ϻ��� ��ġ�ϴ� ���ڿ��� ������� ���� ������.

		//4-4. �˻����ڿ��� ��ġ�ϴ� ���ڿ��� Trie������ ���°��
		int cur = *str - 'A';
		if (node[cur] == nullptr) return false;

		return node[cur]->findPrefix(str + 1);
	}
};
////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
////[12] Kruskal Algorithm  /////////////////////////////////////////////////////
struct Kruskal_ALGORITHM {
	int P[MAX]; //�������� MAX

	//1. (DSU-Find) �θ� ��带 ������
	int getParent(int x) {
		if (P[x] == x) return x; //��Ʈ���� ����
		return P[x] = getParent(P[x]); //��Ʈ��尡 �ƴϸ� ��ξ����ϸ� ��Ʈ��带 �����ϵ��� ��ξ����س���
	}

	//2. (DSU-Union)
	void unionParent(int x, int y) {
		x = getParent(x);
		y = getParent(y);
		//�� ���� ��带 �θ�� ��ħ
		if (x < y)
			P[y] = x;
		else
			P[x] = y;
	}

	//3. �� ��尡 ���� �������� Ȯ��
	bool isSet(int x, int y) {
		return getParent(x) == getParent(y); //������ true �ٸ��� false
		//return P[x] == P[y]; //�̰��� �߸��� ��. getParent�� ������������ ���� �ڱ��ڽ����� �ʱ�ȭ��������
								//�׻� false�� �����ϰԵ�
	}

	//4. ���������� ���� edge�� �̿��� MST ���� ����
	/*
	struct INFO {
		int v1, v2, w; //����� �� ����, ����ġ
		bool operator <(INFO &another){ //sort�Լ��� ����ϱ����� �� ������ ������
			return w < another.w;
		}
	};
	vector<INFO> edge;
	//4-1. �Ʒ�ó�� ���������� ���
	edge.push_back({ 0, 1, 5 });
	edge.push_back({ 0, 2, 2 });
	edge.push_back({ 1, 3, 2 });
	edge.push_back({ 2, 4, 2 });
	...

	//4-2. ���� ����ġ�� �������� ����
	sort(edge.begin(), edge.end());

	//4-3. P[] �ʱ�ȭ : �ڱ��ڽ����� �ʱ�ȭ
	for(int i = 0 ; i < MAX ; i++) P[i] = i; 

	//4-4. MST �����ϴ� �κ�
	int sum = 0; //������ MST�� ����ġ ��
	for(int i = 0 ; i < edge.size() ; i++){ //��� ������ Ž��
		int v1 = edge[i].v1;
		int v2 = edge[i].v2;
		int w = edge[i].w;
		if(!isSet(v1, v2)){ //�� ��尡 ���δٸ� �����϶� : ����Ŭ�� �������� ���� ��츦 �ǹ�
			sum += w;
			unionParent(v1, v2); //�� ��带 �ϳ��� �������� ��ħ
		}
	}

	printf("%d", sum); //������ MST�� ����ġ ��
	*/
};
////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
////[13]  /////////////////////////////////////////////////////
//





