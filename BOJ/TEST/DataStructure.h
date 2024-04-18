#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
#define MAX 1 //���ϴ�ũ��
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
////[1] Ʈ���̱��� - �빮�� ���ĺ����θ� �̷���� ���ڿ����� ���տ��� ���ϴ� ���ڿ� Ž��
//					�� ����ȭ�� �ڷᱸ��. �ٸ� �������� ����. 
//���ڿ��� �����ϳ��ϳ��� Ʈ�������� �����Ѱ�. ���ڿ� �˻��� ���� ȿ�����̳� �������� ����
//ã�¹��ڿ��� ���λ�� �����ϰų� �Ϻ���ġ�ϰ� ������ �� ����. (2, 3���Լ� ����)
struct Trie {
	std::map<char, Trie*> node;
	bool finish;

	Trie() : node(), finish(false) {}

	//1. string�� Trie�ڷᱸ���� ����
	void insert(char* str) {
		if (*str == '\0') {
			finish = true;
			return;
		}
		if (node[*str] == nullptr)
			node[*str] = new Trie();

		node[*str]->insert(str + 1);
	}

	//2. ��Ȯ�� ��ġ�ϴ� ���ڿ��� �����ϴ��� Ȯ��
	bool find(char* str) {
		if (*str == '\0' && finish)
			return true;
		if (*str == '\0' && !finish)
			return false;

		if (node[*str] == nullptr) return false;
		return node[*str]->find(str + 1);
	}

	//3. �κй��ڿ��� �����ϴ��� Ȯ��
	//�Ϻ��� ��ġ�ϴ°�� false �κ����θ� �����ؾ���
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
			//////////////////////////////////DFSŽ���ϸ� �� �ڵ� �ۼ�//////////////////////////////////
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





