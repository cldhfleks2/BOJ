#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>

int comp(std::pair<int, std::string> a, std::pair<int, std::string> b) {
	return a.first < b.first;
}

int main(int n) {
	scanf("%d", &n);
	std::vector<std::pair<int, std::string>> list;
	//입력받는 부분
	for (int i = 0; i < n; i++) {
		int age;
		char name[102];
		scanf("%d %[^\n]s", &age, &name);
		list.push_back({ age, name });
		scanf("%c", &name[101]); //줄바꿈문자 지우기(안쓰는 101번인덱스에)
	}

	std::stable_sort(list.begin(), list.end(), comp);

	for (int i = 0; i < n; i++) {
		printf("%d %s\n", list[i].first, list[i].second.c_str());
	}


	return 0;
}