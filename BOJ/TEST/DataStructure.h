#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
#define MAX 1 //원하는크기
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
////[1] 트라이구조 - 대문자 알파벳으로만 이루어진 문자열들의 집합에서 원하는 문자열 탐색
//					에 최적화된 자료구조. 다만 공간낭비가 심함. 
//문자열을 문자하나하나의 트리구조로 구현한것. 문자열 검색에 아주 효율적이나 공간낭비가 심함
//찾는문자열이 접두사로 존재하거나 완벽일치하게 존재할 수 있음. (2, 3번함수 참고)
struct Trie {
	std::map<char, Trie*> node;
	bool finish;

	Trie() : node(), finish(false) {}

	//1. string을 Trie자료구조로 편입
	void insert(char* str) {
		if (*str == '\0') {
			finish = true;
			return;
		}
		if (node[*str] == nullptr)
			node[*str] = new Trie();

		node[*str]->insert(str + 1);
	}

	//2. 정확히 일치하는 문자열이 존재하는지 확인
	bool find(char* str) {
		if (*str == '\0' && finish)
			return true;
		if (*str == '\0' && !finish)
			return false;

		if (node[*str] == nullptr) return false;
		return node[*str]->find(str + 1);
	}

	//3. 부분문자열이 존재하는지 확인
	//완벽히 일치하는경우 false 부분으로만 존재해야함
	bool findPrefix(char* str) {
		if (*str == '\0')
			return false;
		if (finish)
			return true;

		if (node[*str] == nullptr)
			return false;
		return node[*str]->findPrefix(str + 1);
	}

	//4. DFS in Trie
	void DFS(int depth) {
		for (int c = 0; c < 128; c++) {
			if (node[c] == nullptr) continue;
			////////////////////////////////////////////////////////////////////////////////////////////
			//////////////////////////////////DFS탐색하며 쓸 코드 작성//////////////////////////////////
			////////////////////////////////////////////////////////////////////////////////////////////
			node[c]->DFS(depth + 1);
		}
	}

	//5. BFS in Trie
	//???
};
////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
////
//





