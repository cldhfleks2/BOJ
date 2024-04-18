//#define _CRT_SECURE_NO_WARNINGS
//#include <bits/stdc++.h>
//using namespace std;
//string _country[4]; //4개국가가 저장됨
//	/*
//	* ratiro[X][Y][W/D/L]
//	* X와 Y가 승부할때 W, D, L 이 될 확률(double)저장
//	*/
//double _ratio[4][4][3] = {};
//void init() { //입력값을 저장
//	for (int i = 0; i < 4; i++) {
//		char temp[11];
//		scanf("%s", &temp);
//		string name(temp);
//		_country[i] = name;
//	}
//
//	for (int i = 0; i < 6; i++) { //승률 배열에 기록
//		char temp[11];
//		scanf("%s", &temp);
//		string temp2(temp);
//		int x = 0, y = 0;
//		for (int i = 0; i < 4; i++)
//			if (temp2 == _country[i])
//				x = i;
//		char temp3[11];
//		scanf("%s", &temp3);
//		string temp4(temp3);
//		for (int i = 0; i < 4; i++)
//			if (temp4 == _country[i])
//				y = i;
//		double W = 0.0, D = 0.0, L = 0.0;
//		scanf("%lf%lf%lf", &W, &D, &L);
//		_ratio[x][y][0] = W;
//		_ratio[x][y][1] = D;
//		_ratio[x][y][2] = L;
//		_ratio[y][x][0] = 1 - W - D;
//		_ratio[y][x][1] = D;
//		_ratio[y][x][2] = 1 - L - D;
//	}
//}
//void printAll() {
//	for (int c = 0; c < 4; c++) { //순서대로 총 4개의 국가를 출력
//		/*
//		* W
//		* D/2
//		* (1-L)
//		*/
//		double totalsum_W = 0;
//		for (int i = 0; i < 4; i++) { //c를 제외한 국가들과 1ㄷ1 결과중 이길확률만
//			if (c == i) continue;
//			//W, (1-L)중 큰것이 이길 확률
//			//총 4가지 경우의 수를 보겠다는것
//			double sum_W = 0; 
//			if (sum_W < _ratio[c][i][0]) { //W
//				sum_W = _ratio[c][i][0];
//				//printf(" W%.3lf", sum_W);
//			}
//			
//			if (sum_W < 1.0 - _ratio[c][i][2]) { //(1-L)
//				sum_W = 1.0 - _ratio[c][i][2];
//				//printf(" (1-L)%.3lf", sum_W);
//			}
//			totalsum_W += _ratio[c][i][0];
//			printf("  (%d,%.3lf)  ", i, _ratio[c][i][0]);
//		}
//		//////////////////////여기까지 승리할확률(무승부할확률 포함)계산완료/////////////////
//		//무승부할 확률을 빼줘야함.
//		double sum_D = 0.0;
//		for (int i = 0; i < 4; i++) { //모든 무승부확률더하고
//			if (c == i) continue;
//			sum_D += _ratio[c][i][1];
//		}
//		sum_D /= 2; //절반으로 나누고
//		totalsum_W += sum_D; //이것을 앞서구한 승리할확률에서 뺀다.
//
//		totalsum_W /= 3.0;
//		printf("=>%.3lf\n", totalsum_W);
//	}
//}
//
//int main(void) {
//	init();
//	printAll();
//
//
//	return 0;
//}