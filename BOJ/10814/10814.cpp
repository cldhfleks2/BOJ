#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>

int comp(std::pair<int, std::string> a, std::pair<int, std::string> b) {
	return a.first < b.first;
}

int main(int n) {
	scanf("%d", &n);
	std::vector<std::pair<int, std::string>> list;
	//�Է¹޴� �κ�
	for (int i = 0; i < n; i++) {
		int age;
		char name[102];
		scanf("%d %[^\n]s", &age, &name);
		list.push_back({ age, name });
		scanf("%c", &name[101]); //�ٹٲ޹��� �����(�Ⱦ��� 101���ε�����)
	}

	std::stable_sort(list.begin(), list.end(), comp);

	for (int i = 0; i < n; i++) {
		printf("%d %s\n", list[i].first, list[i].second.c_str());
	}


	return 0;
}