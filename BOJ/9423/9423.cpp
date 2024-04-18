#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
using std::sort; using std::vector;
int n, sum=0, mid;
int group[2] = { 0, 0 }; //그룹 A, 그룹 B
vector<int> list, A, B;

void func() {
	int cursor = list.size()-1; //두개의 포인터
	while (1) {
		if (group[0] + list[cursor] < mid) { //중간값보다 작을경우 큰수부터 더함
			group[0] += list[cursor];
			A.push_back(list[cursor]);
			list.erase(list.begin() + cursor); //front인덱스 데이터 삭제
			cursor--;
		}
		else { //만약 중간값을 넘으면 중단
			break;
		}
	}

	while (1) {
		if (group[1] + list[cursor] < mid) { //중간값보다 작을경우 큰수부터 더함
			group[1] += list[cursor];
			B.push_back(list[cursor]);
			list.erase(list.begin() + cursor); //front인덱스 데이터 삭제
			cursor--;
		}
		else { //만약 중간값을 넘으면 중단
			break;
		}
	}

	int size = list.size();
	bool turnA = true;
	if ((mid - group[0]) > (mid - group[1]))
		turnA = true; //중간값에 크게 못미치는 그룹 먼저 채움
	else
		turnA = false;
	for (int i = 0; i < size; i++) {
		if (turnA) { //A그룹에 넣을 차례일때
			if (group[0] + list[i] > mid) { //만약 넣는데 중간값보다 커진다면...
				turnA = false; //B그룹 턴으로 바꾸고
				group[1] += list[i];
				B.push_back(list[i]);
			}
			else {
				group[0] += list[i];
				A.push_back(list[i]);
			}
		}else{
			if (group[1] + list[i] > mid) { //만약 넣는데 중간값보다 커진다면...
				turnA = true; //B그룹 턴으로 바꾸고
				group[0] += list[i];
				A.push_back(list[i]);
			}
			else {
				group[1] += list[i];
				B.push_back(list[i]);
			}
		}
	}

	if (group[0] < group[1])
		printf("%d %d", group[0], group[1]);
	else
		printf("%d %d", group[1], group[0]);
}

int main(void) {
	scanf("%d", &n);
	for (int i = 0, temp; i < n; i++) {
		scanf("%d", &temp);
		list.push_back(temp);
		sum += temp;
	}
	mid = sum / 2;
	sort(list.begin(), list.end());

	if (n == 1) {
		printf("%d", list[0]);
		return 0;
	}
	
	func();
	return 0;
}