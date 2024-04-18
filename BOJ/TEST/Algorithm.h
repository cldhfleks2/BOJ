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
//using std::map;
////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
////[1] KMP, Knuth Morris Pratt/////////////////////////////////////////////////////////
struct KMP_ALGORITHM {
	//1. 실패함수 : 실패테이블 작성하는 함수
	//F[i] : 인덱스0 ~ 인덱스i까지의 접두사와 접미사가 일치하는 최대길이
	vector<int> makeFailureTable(string pattern) {
		int lenP = pattern.length();
		vector<int> F(lenP, 0); //FailureTables, M개의크기를가지며 모두 0으로 초기화

		F[0] = 0;
		for (int i = 1, j = 0; i < lenP; i++) {
			//탐색에 실패한경우, 비교할 문자열의 0번인덱스부터 다시 탐색하는것이 아니라
			//실패 테이블을 이용해 앞서 일치했던 부분은 건너띈후 탐색을 이어나감(효율적)
			while (j > 0 && pattern[i] != pattern[j])
				j = F[j - 1];
			//탐색에 성공한경우 테이블을 작성한다.(인덱스0 ~ 인덱스i 까지)
			if (pattern[i] == pattern[j])
				F[i] = ++j;
		}
		return F;
	}
	//2. KMP : 실패테이블을 가지고 실제 문자열을 탐색한다.
	vector<int> KMP(string text, string pattern) {
		int lenT = text.length();
		int lenP = pattern.length();
		vector<int> F = makeFailureTable(pattern); //전처리 : 실패테이블을 작성
		vector<int> findStartIndex; //탐색에 성공한경우 찾은 시작위치

		for (int i = 0, j = 0; i < lenT; i++) {
			//탐색성공(문자 하나)
			while (j > 0 && text[i] != pattern[j]) //실패함수를 만들때랑 같은조건
				j = F[j - 1];
			//탐색실패(문자 하나)
			if (text[i] == pattern[j]) { //본문자열에서 찾고자하는 문자열을 찾은경우
				if (j == lenP - 1) {
					findStartIndex.push_back((i - lenP) + 1); //찾은 부분문자열의 시작인덱스를 저장
					j = F[j]; //j = F[lenP - 1]과같음. => 이어서 탐색을 진행하기위해 필요
				}
				else
					//F[i] = ++j;
					++j; //실패함수와다르게, 테이블을 수정할 필요 없음
			}
		}

		return findStartIndex;
	}
};
////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
////[2] Dijstra/////////////////////////////////////////////////////////////////////////
//O(E log N)
//양의 가중치만 가질때, 그래프내 특정 두 정점 간의 최소거리 구할때
struct Dijstra_ALGORITM {
	vector<pair<int, int>> edge[11111]; //<연결된정점, 가중치>
	int dijstra(int start, int end, vector<pair<int, int>>(&edge)[11111], int N) {
		vector<int> dist(N + 1, 0x7fffffff);
		priority_queue<pair<int, int>> pq;

		dist[start] = 0;
		pq.push({ -0, start }); //가중치가 작은순(0에 가까운)으로 정렬되도록

		//우선순위 큐가 빌때까지 반복
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
					pq.push({ -dist[vv], vv }); //가중치, 정점위치 저장
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
//양, 음의 가중치 가질때, 그래프내 모든 두정점간의 최소거리구하기
struct Floyd_ALTORITHM {
	int W[1111][1111];
	//1. 작성된 2차원 테이블을 전달받는경우
	//2차원 테이블([i][j])은 단방향 연결 정보를 가짐. 
	//2차원 테이블은 i == j 인경우 0, 그외는 무한한값을 저장한다.
	void floyd(int(&W)[1111][1111], int N) {
		//1-1. 플로이드 적용
		for (int k = 0; k < N; k++) {
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					W[i][j] = min(W[i][j], W[i][k] + W[k][j]);
				}
			}
		}
	}

	//2. 연결정보를 입력받아 2차원테이블을 만들어 쓰는 경우
	void floyd(int N) {
		//2-1. 2차원테이블에서 i == j 인경우 0, 그외는 무한한값을 저장한다.
		int W[111][111];
		for (int i = 0; i < 111; i++) {
			for (int j = 0; j < 111; j++) {
				if (i == j)
					W[i][j] = 0;
				else
					W[i][j] = 0x7fffffff;
			}
		}
		//2-2. 단방향 정보를 입력 받아 2차원테이블을 완성한다.
		;;;;;;;;
		//2-3. 플로이드 적용
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
	int idx, P[MAX]; //MAX : 정점의 총 갯수
	vector<int> edge[MAX]; //단방향 연결 간선
	stack<int> S;
	bool visited[MAX]; 
	vector<vector<int>> SCC; //찾은 모든 SCC의구성원을 vector<int>로 저장

	////1.DFS 수행
	int DFSinSCC(int x) {
		P[x] = ++idx; //정점번호가 1부터 시작할때
		S.push(x); 

		int parent = P[x]; //현재 SCC의 부모정점 번호(SCC구성원중 가장 낮은 번호로)
		for (int i = 0; i < edge[x].size(); i++) {
			int y = edge[x][i]; //x와 연결된 다른점 y
			if (P[y] == 0) //정점y의 부모가 설정되지 않았을경우
				parent = min(parent, DFSinSCC(y)); //현재 SCC에 속하도록 DFS수행
			else if (!visited[y]) //정점y의 부모가설정되있고 SCC에 속하지않았으면
				parent = min(parent, P[y]); //현재 SCC에 정점y가 속하도록
		}

		//DFS순환하며 현재 SCC의 부모정점이라면 SCC를 구해야함.
		if (parent == P[x]) {
			vector<int> scc;
			while (x) {
				int y = S.top();
				S.pop();
				visited[y] = true;
				scc.push_back(y);
				if (y == x) break; //SCC의 부모정점번호를 꺼내면 종료
			}
			SCC.push_back(scc);
		}

		return parent;
	}

	//2. SCC
	void makeSCC(int N) {
		for (int i = 0; i < N; i++)  
			if (P[i] == 0)  DFSinSCC(i);//P[]가 결정되지않은 모든 정점을 DFS 수행
	}
};
////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
////[5] DSU, Disjoint Set UnionFind/////////////////////////////////////////////////////
//Find와 Union 두가지 필수요소
struct DSU_ALGORITHM { 
	//MAX : 정점의 최대 갯수
	int PARENT[MAX];
	//1. 부모노드를 가져오는 함수
	//원소를 경로압축하며 부모를 대표원소로 재설정하는함수
	int Find(int x) {
		if (PARENT[x] == x) return x;
		//return Find(parent[x]); //부모노드를 가져옴
		return PARENT[x] = Find(PARENT[x]); //(경로압축 사용)부모를 찾음
	}

	//2. 두 원소를 하나의 집합으로 합치는 함수
	void Union(int x, int y) {
		x = Find(x);
		y = Find(y);
		PARENT[y] = x; //한 원소를 다른원소가 속한 부모집합 내부로 편입
		//PARENT[x] = y : 이렇게 해도 상관없다.ㄴ
	}

	//3. (예제)두 원소가 같은 집합인지 확인하는 함수
	bool isConnect(int x, int y) {
		return Find(x) == Find(y); //두 원소의 부모가 같은지 리턴한다.
	}

	//4. (예제)DSU함수
	void DSU() {
		//입력을받아 각원소의 부모가 누구인지 PARENT에 기록
		;;
		//두 원소가 같은 집합이라면  Union함수 사용
		;;
		//두 원소가 같은 집합인지 확인하려면 isConnect함수 사용 
		;;
	}
};
////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
////[6] Rabin Karp//////////////////////////////////////////////////////////////////////
//탐색한 해쉬값을 배열에 저장하려면 % MOD를 이용해라
//해쉬값이 음수가 나올수있기때문. 그러나 음수가나와도 고유한값이므로 탐색에는 지장이없다.
struct RabinKarp_ALGORITHM {
	void RabinKarp(string text, string pattern) {
		int lenP = pattern.length();
		int lenT = text.length();
		long long hashP = 0; //문자열 pattern의 전체 해쉬값
		long long hashT = 0; //현재 text에서 탐색중인 해쉬값(길이 lenP)
		int pow = 1; //자릿수마다 곱해질 제곱수
		int spec = 3; //사용자가 지정할 제곱할 숫자. 아무숫자나 상관없음

		for (int i = 0; i <= lenT - lenP; i++) { //text의 끝까지 탐색할 필요없음
			if (i == 0) { //초깃값
				for (int j = 0; j < lenP; j++) {
					int idx = lenP - j - 1;
					hashT += text[idx] * pow;
					hashP += pattern[idx] * pow;
					if (j < lenP - 1) pow *= spec;
				}
			}
			else { //점화식이용
				hashT = spec * //비교하려는 단위가 뒤로 밀리며 이전해쉬값은 spec만큼 곱해져야함/
					(hashT - text[i - 1] * pow) //전체해쉬값 - 맨앞(좌측)문자의 해쉬값
					+ text[lenP - 1 + i]; //새로 탐색된 문자열의 해쉬값
			}
			if (hashT == hashP) { //해쉬값이 일치한다 => 탐색에 성공했을가능성이있음
				bool isFind = true;
				for (int j = 0; j < lenP; j++) {
					if (text[i + j] != pattern[j]) { //탐색에 실패한경우
						isFind = false;
						break;
					}
				}
				if (isFind) {
					//TO-DO : 탐색성공시 원하는 로직을 작성
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

	//전역변수로 표현된 str1, str2에서 각각의 최대 탐색길이를 전달받아 
	//str1[n-1], str2[m-1]까지의 최대 공통부분 수열의 길이를 리턴하는 함수 
	int LCS(int n, int m) {
		int dp[1001][1001]; //dp 2차원 테이블 준비

		//dp테이블 초기화 (공집합과의 부분집합들만 0으로)
		for (int i = 0; i < n + 1; i++) dp[i][0] = 0;
		for (int j = 0; j < m + 1; j++) dp[0][j] = 0;
	
		for (int i = 1; i < n + 1; i++)
			for (int j = 1; j < m + 1; j++)
				if (str1[i - 1] == str2[j - 1])
					dp[i][j] = dp[i - 1][j - 1] + 1; //이전까지의 최대길이 + 1
				else
					dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]); //str1,str2의 각각 현재문자를 제외한 최대길이중 최댓값

		return dp[n][m]; //찾은 길이 리턴
	}
};
////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
////[8] MSIS, Max Sum Increase Subsequence /////////////////////////////////////////////////////
struct MSIS_ALGORITHM {
	int MSIS(vector<int> const& arr) {
		//계산불가능 한 경우
		if (arr.empty()) return 0;
		
		//DP로 계산될것.
		vector<int> dp(arr.size());

		//초깃값
		dp[0] = arr[0];

		for (int i = 1; i < arr.size(); i++) {
			//j < i인 모든 j에대해 arr이 증가하고있고, 
			//이전합(dp[j])이 현재최대합dp[i]보다 크면 dp[i]를 dp[j]로 변경
			for (int j = 0; j < i; j++) 
				if (arr[j] < arr[i] && dp[j] > dp[i]) dp[i] = dp[j];

			//현재 arr[i]를 dp에 포함시킴
			dp[i] += arr[i];
		}

		// 찾은 0~i까지의 부분수열의 최대합 중 최대 부분수열의 합을 찾아서 리턴
		int res = 0;
		for (int x : dp) res = std::max(res, x);
		return res;
	}
};
////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
////[9] BinarySearch  /////////////////////////////////////////////////////
//LowerBound, UpperBound도 포함
struct BinarySearch_ALGORITHM {
	//arr에서 원소k의 위치인덱스를 찾아서 리턴하는 함수
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
		return -1; //찾지 못하였음.
	}

	//1. arr에서 k이상인 값이 처음나오는 인덱스를 찾는 함수
	//arr에서 k이상인 값이 처음나오는 인덱스를 찾는 함수
	int LowerBound(vector<int>& arr, int k) {
		int left = 0, right = arr.size() - 1;

		while (left < right) {
			int mid = (left + right) / 2;
			if (k <= arr[mid]) //k이상인 값이면
				right = mid; //왼쪽부분을 탐색
			else               //k미만인 값이면
				left = mid + 1; //오른쪽부분을 탐색
		}

		return right;
	}

	//2. arr에서 k초과인 값이 처음나오는 인덱스를 찾는 함수
	//arr에서 k초과인 값이 처음나오는 인덱스를 찾는 함수
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
	//1. DP를 이용해 LIS를 구한 함수
	//LIS길이만 구할 수 있다.
	int LISwithDP(vector<int>& arr) {
		if (arr.empty()) return 0;

		vector<int> dp(arr.size());

		for (int i = 0; i < arr.size(); i++) {
			//i보다 작은 j에대해 모두 감소하는관계라면 
			//최소한 자기자신으로만 이루어진 LIS가 존재가능
			dp[i] = 1; 

			for (int j = 0; j < i; j++) 
				if (arr[j] < arr[i]) 
					dp[i] = max(dp[i], dp[j] + 1);
		}
		
		return dp[arr.size() - 1];
	}

	//아래의 LIS에 사용될 LowerBound함수
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

	//2. LowerBound를 이용하여 LIS를 구하는 함수
	//만들어진 LIS배열은 순서가 뒤섞인, 
	//그저 arr의 어떤 요소가 LIS를 이루는지만 확인 가능
	int LISwithBinarySearch(vector<int>& arr) {
		if (arr.empty()) return 0;

		vector<int> lis(arr.size());
		lis.push_back(arr[0]);
		for (int i = 1; i < arr.size(); i++) {
			if (lis.back() < arr[i]) 
				lis.push_back(arr[i]);
			else //lis에 arr[i]가 들어갈 적절한위치를 LowerBound로 찾아서
				//해당위치에 arr[i]를 저장
				lis[LowerBound(lis, arr[i])] = arr[i]; 
		}
		
		return lis.size(); //만들어진 lis 배열을 리턴합니다.
	}
};
////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
////[11] Trie DataStructure  /////////////////////////////////////////////////////
struct Trie {
	Trie* node[26]; //노드를 나타내는 포인터
	bool finish; //각 노드마다 현재 노드가 문자열 끝인지 체크
				 //문자열 끝이란것은 해당 문자로 끝나는 문자열이 저장되있음을 의미

	//1. 생성자 : 초기화. 빈노드, finish=false
	Trie() : node(), finish(false){} 

	//2. 문자열을 Trie 자료구조로 만드는 함수.
	//Trie포인터를 이용한 재귀적 구조
	void insert(char* str) {
		if (*str == '\0') { //2-1. 문자열 끝이면 finish체크후 종료
			finish = true;
			return;
		}
		int cur = *str - 'A'; //'A'~'Z' 문자를 정수 0~25로 변환
		if (node[cur] == nullptr)   //2-2. node[cur]이 존재하면 cur에 해당하는 문자가
			node[cur] = new Trie(); //존재하는것. 이미 존재하면 만들지않음
									//Trie구조 특성상 트리구조이니. 이미 존재하면
									//만들어진 노드를 타고 깊이 내려가는것.
		node[cur]->insert(str + 1); //만들어진 노드의 insert를 실행시킴(재귀)
	}

	//3. 문자열 검색1(정확히 일치하는게 있는지)
	//Trie포인터를 이용한 재귀적 구조
	bool find(char* str) {
		//3-1. 검색문자열 끝 + 1 인덱스까지왔으나, 끝체크가 안되있으면 검색 실패
		if (*str == '\0' && !finish) return false; 
		//3-2. 검색문자열 끝 + 1 인덱스까지왔고 끝체크
		if (*str == '\0' && finish) return true;
		//3-2. 검색문자열 자체가 존재하지 않는경우
		int cur = *str - 'A';
		if (node[cur] == nullptr) return false;
		return node[cur]->find(str + 1);
	}

	//4. 문자열검색2(문자열+a 가 있는지)
	//Trie포인터를 이용한 재귀적 구조
	bool findPrefix(char* str) {
		//4-1. 찾은경우 (3-1 과 3-2를 합친경우임.)
		if (finish) return true;

		//4-2. 4-1에 해당하지않고 검색도중에 문자열 끝에 도달한경우 탐색실패
		if (*str == '\0') return false;

		//4-3. 4-1코드와 4-2코드의 위치를 바꾼다면
		//완벽히 일치하는 문자열은 결과에서 제외 가능함.

		//4-4. 검색문자열과 일치하는 문자열이 Trie구조에 없는경우
		int cur = *str - 'A';
		if (node[cur] == nullptr) return false;

		return node[cur]->findPrefix(str + 1);
	}
};
////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
////[12] Kruskal Algorithm  /////////////////////////////////////////////////////
struct Kruskal_ALGORITHM {
	int P[MAX]; //정점갯수 MAX

	//1. (DSU-Find) 부모 노드를 가져옴
	int getParent(int x) {
		if (P[x] == x) return x; //루트노드면 리턴
		return P[x] = getParent(P[x]); //루트노드가 아니면 경로압축하며 루트노드를 리턴하도록 경로압축해나감
	}

	//2. (DSU-Union)
	void unionParent(int x, int y) {
		x = getParent(x);
		y = getParent(y);
		//더 작은 노드를 부모로 합침
		if (x < y)
			P[y] = x;
		else
			P[x] = y;
	}

	//3. 두 노드가 같은 집합인지 확인
	bool isSet(int x, int y) {
		return getParent(x) == getParent(y); //같으면 true 다르면 false
		//return P[x] == P[y]; //이것은 잘못된 예. getParent를 실행하지않은 노드는 자기자신으로 초기화되있으니
								//항상 false를 리턴하게됨
	}

	//4. 연결정보를 담은 edge를 이용한 MST 생성 예제
	/*
	struct INFO {
		int v1, v2, w; //연결된 두 정점, 가중치
		bool operator <(INFO &another){ //sort함수를 사용하기위한 비교 연산자 재정의
			return w < another.w;
		}
	};
	vector<INFO> edge;
	//4-1. 아래처럼 연결정보를 기록
	edge.push_back({ 0, 1, 5 });
	edge.push_back({ 0, 2, 2 });
	edge.push_back({ 1, 3, 2 });
	edge.push_back({ 2, 4, 2 });
	...

	//4-2. 간선 가중치로 오름차순 정렬
	sort(edge.begin(), edge.end());

	//4-3. P[] 초기화 : 자기자신으로 초기화
	for(int i = 0 ; i < MAX ; i++) P[i] = i; 

	//4-4. MST 생성하는 부분
	int sum = 0; //생성한 MST의 가중치 합
	for(int i = 0 ; i < edge.size() ; i++){ //모든 간선을 탐색
		int v1 = edge[i].v1;
		int v2 = edge[i].v2;
		int w = edge[i].w;
		if(!isSet(v1, v2)){ //두 노드가 서로다른 집합일때 : 사이클을 형성하지 않은 경우를 의미
			sum += w;
			unionParent(v1, v2); //두 노드를 하나의 집합으로 함침
		}
	}

	printf("%d", sum); //생성된 MST의 가중치 합
	*/
};
////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
////[13]  /////////////////////////////////////////////////////
//





