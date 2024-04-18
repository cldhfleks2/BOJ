#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
using std::vector; using std::pair;
int n, m;
vector<pair<int, int>> home, chicken;
vector<int> picked; 
vector<int*> chooseChickenList; //m개를 선택한 리스트들을 담음
void func();
void pick(int n, vector<int>& picked, int cnt);
int calculateCD(int x1, int y1, int* list);

void func() {
	pick(chicken.size(), picked, m); //치킨집중 m개를선택한 리스트쌍을 만든다.
	int res = 0x7fffffff;
	for (int i = 0; i < chooseChickenList.size(); i++) { //선택된 m개의 치킨집 의 리스트를
		int sum_CD = 0; //m개 고른 치킨집들에대한 모든 집의 치킨거리를 합산
		for (int j = 0; j < home.size(); j++) { //모든집에대해 탐색
			int CD = calculateCD(home[j].first, //현재 집의
								home[j].second, //치킨거리를 구함
						chooseChickenList[i]);
			sum_CD += CD; 
		}
		if (res > sum_CD) res = sum_CD; //도시의 치킨거리의 최솟값만 기록
	}
	printf("%d", res); //출력
}

void pick(int n, vector<int>& picked, int cnt) {
	if (cnt == 0) {//뽑힌것에대해 뭘하실.
		int* l = new int[picked.size()];
		for (int i = 0; i < picked.size(); i++)
			l[i] = picked[i];
		chooseChickenList.push_back(l); //선탟한 치킨목록에 추가
		return;
	}
	int smallest = picked.empty() ? 0 : picked.back() + 1;
	for (int i = smallest; i < n; i++) {
		picked.push_back(i); //picked 넣고
		pick(n, picked, cnt - 1);
		picked.pop_back(); //picked를 빼면서 다음 요소를 참조.
	}
}

//해당 집의 치킨거리를 구하는 함수
int calculateCD(int x1, int y1, int* list) {
	int res=0x7fffffff ,x2, y2;
	for (int i = 0; i < m; i++) { //m개의 치킨집을 탐색
		x2 = chicken[list[i]].first;
		y2 = chicken[list[i]].second;
		int d = (x2 < x1 ? x1 - x2 : x2 - x1) + 
			(y2 < y1 ? y1 - y2 : y2 - y1);
		if (res > d) res = d; //최소거리만 기록
	}
	return res;
}

int main(void) {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0, temp; j < n; j++) {
			scanf("%d", &temp);
			if (temp == 1) 
				home.push_back({i, j}); //집위치 저장
			else if (temp == 2) 
				chicken.push_back({ i, j }); //치킨집위치 저장
		}
	}

	func();

	return 0;
}