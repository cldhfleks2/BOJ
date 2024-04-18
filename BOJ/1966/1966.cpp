#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int main(void) {
	int t;
	scanf("%d", &t);
	while (t--) {
		int N, M;
		vector<int> list;
		scanf("%d%d", &N, &M);
		//벡터에넣고 벡터 사이즈를 매번 갱신
		//원하는 데이터가 나올때까지 전부 구현함
		int frequency[10] = {}; //빈도수 체크
		for (int i = 0, temp; i < N; i++) { 
			scanf("%d", &temp);
			list.push_back(temp);
			frequency[temp]++;
		}
		int findIndex = M; //찾고자하는 문서위치
		int currentIndex = 0; //현재 문서 위치
		int res = 0; //출력횟수
		//printf("&&& 찾문:%d  ", findIndex);
		while (true) {
			int currentPriority = list[0]; //현재문서의 중요도
			if (currentPriority != 9) { //현재문서가 중요도9가 아닌경우
				bool cantPrint = false;
				//찾는문서보다 높은 중요도의 문서들이 있는지 확인
				for (int i = 9; i >= currentPriority + 1 ; i--) {
					if (frequency[i]) {
						cantPrint = true;
						break;
					}
				}
				//찾는문서의 위치가아니고
				if (cantPrint) { //더높은 중요도의 문서가 있는경우
					int temp = list[0];
					//맨뒤로 옮김
					list.erase(list.begin() + 0); 
					list.push_back(temp);
					//찾는문서의 위치였다면
					if (currentIndex == findIndex) {
						//찾는 문서위치 갱신
						findIndex = list.size() - 1;
						//현재 문서위치 갱신
						currentIndex = 0;
						continue;
					}
				}//찾는문서의 위치가아니고
				else { //더높은 중요도의 문서가 없는 경우
					//출력
					list.erase(list.begin() + 0); //현재 문서 삭제
					frequency[currentPriority]--; //현재 문서 빈도수 -1
					res++; //출력함
					//찾는문서의 위치였다면
					if (currentIndex == findIndex) break;
				}
			}
			else { //현재 문서 중요도가 9인경우 바로 출력가능
				//찾는문서의 위치이면
				if (currentIndex == findIndex) {
					res++;
					break; //계산끝
				}
				else {
					//출력
					list.erase(list.begin() + 0); //현재 문서 삭제
					frequency[currentPriority]--; //현재 문서 빈도수 -1
					res++; //출력함
				}
			}
			currentIndex++; //현재문서위치를 다음으로
		}
		printf("%d\n", res);
	}
}
