#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
using std::vector; using std::queue;
//seq : 출력해야하는 수열을 차례대로
//push_num : 스택s에 들어갈 다음수
//top : 스택s의 꼭대기
int n, *seq, push_num=1, top=-1;

vector<int> s; //스택: 벡터로구현함

void func() {
	queue<int> print; //0:-  1:+
	bool error = false;
	int k = 0, num=seq[k];
	while (1) {
		//비어있다면 무조건 원소를 push
		if (top == -1) {
			s.push_back(push_num);
			top++;
			push_num++;
			print.push(1); //출력저장
		}

		//스택에 넣을 최댓값을 넘긴경우
		if (push_num == n + 1) break;

		//원소를 스택의 꼭대기에서 찾았으면 pop
		if (s[top] == num) {
			s.erase(s.begin() + top); //top위치에서 데이터를 삭제
			top--;
			print.push(0); //출력저장
			k++;
			num = seq[k]; //다음에 찾을수
		}
		else { //꼭대기에서 못찾았으면 push
			s.push_back(push_num);
			top++; //꼭대기포인터
			push_num++; //다음저장할수..
			print.push(1); //출력저장
		}

		if (k == n)
			break;

	}

	
	//스택에 남은원소를 전부 pop
	while (top != -1) {
		if (s[top] != num) { //찾고자하는 수가 아니면
			error = true;
			break;
		}
		else { //찾고자한느 수라면
			top--;
			print.push(0); //출력저장
			if (k == n + 1) break;
			k++;
			num = seq[k];
		}
	}
	
	//printf(">>>>>> %d  %d  num %d\n", top, k, num);

	//모든수를 찾지못했거나
	//스택에 수가 남아있으면 오류
	if (k != n || top != -1) {
		error = true;
	}

	//출력하는 부분
	if (error) {
		printf("NO");
		return;
	}
	else {
		while (!print.empty()) {
			if (print.front() == 0)
				printf("-\n");
			else
				printf("+\n");
			print.pop();
		}
	}

}

int main(void) {
	scanf("%d", &n);
	seq = new int[n];
	for (int i = 0; i < n; i++) scanf("%d", &seq[i]);

	func();

	return 0;
}