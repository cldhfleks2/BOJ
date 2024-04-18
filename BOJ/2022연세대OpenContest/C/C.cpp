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
	//�Է¹޴ºκ�
	for (int i = 0; i < n; i++) {
		mbti[i] = new char[m];
		scanf("%c", &junk); //�ٹٲ޹��� �����
		for (int j = 0; j < m; j++) {
			scanf("%c", &mbti[i][j]);
		}
	}

	int res = 0;

	//MBTIã�� �κ�
	//���� -> ������  y+
	for (int i = 0; i < n; i++) {//������ġ
		for (int j = 0; j <= m - 4; j++) {//������ġ
			string s = "";
			for (int k = 0; k < 4; k++) {//4�ڸ���ã��
				s += mbti[i][j + k]; //���ڸ� �ϳ������س���
			}
			//�����
			for (int k = 0; k < 16; k++) {
				if (s.compare(group[k]) == 0) { //���ٸ�
					//printf("%s\n", s.c_str());
					res++;
				}
			}
		}
	}
		
	//�� -> �Ʒ�  x+
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

	//������ -> ����  y-
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

	//�Ʒ� -> ��  x-
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

	//�밢��(�»� -> ����)  x+ y+
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

	//�밢��(���� -> �»�)  x- y-
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

	//�밢��(��� -> ����)  x+ y-
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

	//�밢��(���� -> ���)  x- y+
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