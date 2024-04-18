#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
using std::string;

string group[16] = { "ISTJ"
, "ISTP"
, "ISFJ"
, "ISFP"
, "INTJ"
, "INTP"
, "INFJ"
, "INFP"
, "ESTJ"
, "ESTP"
, "ESFJ"
, "ESFP"
, "ENTJ"
, "ENTP"
, "ENFJ"
, "ENFP" };

int main(void) {
	int n, m;
	scanf("%d%d", &n, &m);
	if (n < 4 && m < 4) {
		printf("0");
		return 0;
	}
	char** mbti = new char* [n];
	char junk;
	//입력받는부분
	for (int i = 0; i < n; i++) {
		mbti[i] = new char[m];
		scanf("%c", &junk); //줄바꿈문자 지우기
		for (int j = 0; j < m; j++) {
			scanf("%c", &mbti[i][j]);
		}
	}

	int res = 0;

	//MBTI찾는 부분
	//왼쪽 -> 오른쪽  y+
	for (int i = 0; i < n; i++) {//시작위치
		for (int j = 0; j <= m - 4; j++) {//시작위치
			string s = "";
			for (int k = 0; k < 4; k++) {//4자리만찾음
				s += mbti[i][j + k]; //문자를 하나씩더해나감
			}
			//결과비교
			for (int k = 0; k < 16; k++) {
				if (s.compare(group[k]) == 0) { //같다면
					//printf("%s\n", s.c_str());
					res++;
				}
			}
		}
	}
		
	//위 -> 아래  x+
	for (int i = 0; i <= n - 4; i++) {
		for (int j = 0; j < m; j++) {
			string s = "";
			for (int k = 0; k < 4; k++) {
				s += mbti[i + k][j];
			}
			for (int k = 0; k < 16; k++) {
				if (s.compare(group[k]) == 0) { 
					//printf("%s\n", s.c_str());
					res++;
				}
			}
		}
	}

	//오른쪽 -> 왼쪽  y-
	for (int i = 0; i < n; i++) {
		for (int j = m - 1; j - 3 >= 0; j--) {
			string s = "";
			for (int k = 0; k < 4; k++) {
				s += mbti[i][j - k]; 
			}

			for (int k = 0; k < 16; k++) {
				if (s.compare(group[k]) == 0) {
					//printf("%s\n", s.c_str());
					res++;
				}
			}
		}
	}

	//아래 -> 위  x-
	for (int i = n - 1; i - 3 >= 0; i--) {
		for (int j = 0; j < m; j++) {
			string s = "";
			for (int k = 0; k < 4; k++) {
				s += mbti[i - k][j]; 
			}
			
			for (int k = 0; k < 16; k++) {
				if (s.compare(group[k]) == 0) { 
					//printf("%s\n", s.c_str());
					res++;
				}
			}
		}
	}

	//대각선(좌상 -> 우하)  x+ y+
	for (int i = 0; i <= n - 4; i++) {
		for (int j = 0; j <= m - 4; j++) {
			string s = "";
			for (int k = 0; k < 4; k++) {
				s += mbti[i + k][j + k];
			}
			for (int k = 0; k < 16; k++) {
				if (s.compare(group[k]) == 0) {
					//printf("%s\n", s.c_str());
					res++;
				}
			}
		}
	}

	//대각선(우하 -> 좌상)  x- y-
	for (int i = n - 1; i - 3 >= 0; i--) {
		for (int j = m - 1; j - 3 >= 0; j--) {
			string s = "";
			for (int k = 0; k < 4; k++) {
				s += mbti[i - k][j - k];
			}
			for (int k = 0; k < 16; k++) {
				if (s.compare(group[k]) == 0) {
					//printf("%s\n", s.c_str());
					res++;
				}
			}
		}
	}

	//대각선(우상 -> 좌하)  x+ y-
	for (int i = 0; i <= n - 4; i++) {
		for (int j = m - 1; j - 3 >= 0; j--) {
			string s = "";
			for (int k = 0; k < 4; k++) {
				s += mbti[i + k][j - k];
			}
			for (int k = 0; k < 16; k++) {
				if (s.compare(group[k]) == 0) {
					//printf("%s\n", s.c_str());
					res++;
				}
			}
		}
	}

	//대각선(좌하 -> 우상)  x- y+
	for (int i = n - 1; i - 3 >= 0; i--) {
		for (int j = 0; j <= m - 4; j++) {
			string s = "";
			for (int k = 0; k < 4; k++) {
				s += mbti[i - k][j + k];
			}
			for (int k = 0; k < 16; k++) {
				if (s.compare(group[k]) == 0) {
					//printf("%s\n", s.c_str());
					res++;
				}
			}
		}
	}

	printf("%d", res);

	return 0;
}