//#define _CRT_SECURE_NO_WARNINGS
//#include <bits/stdc++.h>
//using namespace std;
//string _country[4]; //4�������� �����
//	/*
//	* ratiro[X][Y][W/D/L]
//	* X�� Y�� �º��Ҷ� W, D, L �� �� Ȯ��(double)����
//	*/
//double _ratio[4][4][3] = {};
//void init() { //�Է°��� ����
//	for (int i = 0; i < 4; i++) {
//		char temp[11];
//		scanf("%s", &temp);
//		string name(temp);
//		_country[i] = name;
//	}
//
//	for (int i = 0; i < 6; i++) { //�·� �迭�� ���
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
//	for (int c = 0; c < 4; c++) { //������� �� 4���� ������ ���
//		/*
//		* W
//		* D/2
//		* (1-L)
//		*/
//		double totalsum_W = 0;
//		for (int i = 0; i < 4; i++) { //c�� ������ ������� 1��1 ����� �̱�Ȯ����
//			if (c == i) continue;
//			//W, (1-L)�� ū���� �̱� Ȯ��
//			//�� 4���� ����� ���� ���ڴٴ°�
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
//		//////////////////////������� �¸���Ȯ��(���º���Ȯ�� ����)���Ϸ�/////////////////
//		//���º��� Ȯ���� �������.
//		double sum_D = 0.0;
//		for (int i = 0; i < 4; i++) { //��� ���º�Ȯ�����ϰ�
//			if (c == i) continue;
//			sum_D += _ratio[c][i][1];
//		}
//		sum_D /= 2; //�������� ������
//		totalsum_W += sum_D; //�̰��� �ռ����� �¸���Ȯ������ ����.
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