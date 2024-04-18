#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
const int IMAX = INT32_MAX; const int IMIN = INT32_MIN;
const long long LMAX = LLONG_MAX; const long long LMIN = LLONG_MIN;
const long double PI = 3.141592653589793238462643383279502884197;
using std::vector; using std::stack; using std::queue; using std::tuple; 
using std::set; using std::list; using std::bitset; using std::string; 
using std::pair; using std::greater; using std::tie; using std::sort; 
using std::max_element; using std::min_element; using std::fill; using std::stoi; 
using std::stod; using std::stof; using std::stol; using std::stold; using std::stoll; 
using std::stoul; using std::stoull; //using std::max;
//using std::min; 
//using std::map;
////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
////KMP, Knuth-Morris-Pratt/////////////////////////////////////////////////////////////
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
			if (j == lenP - 1)
				findStartIndex.push_back((i - lenP) + 1); //ã�� �κй��ڿ��� �����ε����� ����
			else
				j++; //�����Լ��ʹٸ���, ���̺��� ������ �ʿ� ����
		}
	}

	return findStartIndex;
}
////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////



