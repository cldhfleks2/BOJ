#include <iostream>
#include <stack>
#include <vector>
#include <utility>
using namespace std;

stack<int> s[3]; //기둥을 나타내는 스택

vector< pair<int, int> >result;

void move(int a, int b) {
	int temp = s[a - 1].top();
	s[a - 1].pop();
	if (b != 3) s[b - 1].push(temp);
	result.push_back({ a, b });
}

int main(void) {
	int n, temp;
	cin >> n;
	int moveCnt = 0;
	int currentDisk = n;
	while (n--) {
		cin >> temp;
		s[0].push(temp);
	}
	bool right = true;
	while (currentDisk > 0) {
		int s1 = 0, s2 = 0;
		if (right) { // 1번에서 2번,3번으로 옮긴다.
			while(!s[0].empty()){ // 옮길것이 남아있다면
				int temp = s[0].top();
				if (temp == currentDisk) { // 현재 3번에 가야할원판이면
					move(1, 3);
					currentDisk--;
				}
				else {
					move(1, 2);
				}
			}
			if (s[0].empty()) right = false;
		}
		else { // 2번에서 1번,3번으로 옮긴다.
			while (!s[1].empty()) { 
				int temp = s[1].top();
				if (temp == currentDisk) { 
					move(2, 3);
					currentDisk--;
				}
				else {
					move(2, 1);
				}
			}
			if (s[1].empty()) right = true;
		}
	}
	cout << result.size() << endl;
	for (int i = 0; i < result.size(); i++) 
		cout << result[i].first << " " << result[i].second << endl;


	return 0;
}