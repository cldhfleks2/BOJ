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
			if (j == lenP - 1)
				findStartIndex.push_back((i - lenP) + 1); //찾은 부분문자열의 시작인덱스를 저장
			else
				j++; //실패함수와다르게, 테이블을 수정할 필요 없음
		}
	}

	return findStartIndex;
}
////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////



