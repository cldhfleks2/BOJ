#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
/*
* �ٽ� ����Ʈ
* 1. ��� ������(������ȯ�� �������, �� ������ �����ϴ���)
* 2. �ϳ��� �������� �������� �����ϰ�, �簢���� �Ǳ����� ������ 3 �������� �����ϴ���
*	Ȯ�� => �ִٸ� ���̰�� ������ �ݺ�
* 2-1. ������ ���������� Ž���Ҷ� �������� x,y �������� x+, x-, y+, y- �� �����������
*	vertex ���� Ž���ϸ�ȴ�.
* 3. ���̰� 1~ 100������ �簢���� ã���� ���Ʈ�����˰����� �ᵵ������
*	���� ȿ������ �˰����� ã�ƺ�����
*/
using std::pair;
using std::vector;
typedef pair<int, int> p;
//width : <������x1y1 , ������x2y2>
//height : <�����x1y1 , �ϴ���x2y2>
//width���� X height������ �������Ͽ�
//�����ϴ°�� ���������� ���
vector<pair<p, p>> width, height;
//������ǥ => ��ǥ����� ���Ϲ��� ��Ų�Ͱ� ����.
//map : ������ ������
int x, y, n; 
int res_x1, res_y1, res_x2, res_y2;
//vertex : ������ ��ġ�鸸
bool vertex[100][100];

void findVertex() { //���� ���� �μ����� ������ ����� ���������� �ľ�
	int wn = width.size(), hn = height.size();

	for (int i = 0; i < wn; i++) { //widthŽ��
		//w_x1, w_y1 ���μ��� ���� ��ǥ
		//w_x2, w_y2 ���μ��� ���� ��ǥ
		int w_x1 = width[i].first.first, w_y1 = width[i].first.second;
		int w_x2 = width[i].second.first, w_y2 = width[i].second.second;
		for (int j = 0; j < hn; j++) { //height Ž��
			//h_x1, h_y1 ���μ��� �����ǥ
			//h_x2, h_y2 ���μ��� �ϴ���ǥ
			int h_x1 = height[j].first.first, h_y1 = height[j].first.second;
			int h_x2 = height[j].second.first, h_y2 = height[j].second.second;
			if ((w_y1 <= h_y1 && h_y1 <= w_y2) &&
				(h_x1 <= w_x1 && w_x1 <= h_x2)) { //�μ����� �������� �����Ѵٸ�
				int xx = w_x1, yy = h_y1; //�����ϴ� �������� ��ǥ
				vertex[xx][yy] = true; //���
			}
			else { //�μ����� �ȸ����� ����
				continue;
			}
		}
	}

}

int calculate() {
	int min = 0x7fffffff;
	
	for (int x1 = 0; x1 < 100; x1++) {
		for (int y1 = 0; y1 < 100; y1++) {
			if (vertex[x1][y1]) { //������1
				for (int x2 = 0; x2 < 100; x2++) {
					for (int y2 = 0; y2 < 100; y2++) {
						if (x1 == x2 && y1 == y2) continue; //���� ���������� ����
						if (vertex[x2][y2]) { //������2
							//�������� �̰ų� �̹� Ž���� �������̸� ����
							//x1,y1 �� �׻� x2,y2 ��ǥ���� �»�ܿ� �ִ°�
							if (x1 >= x2) continue;
							if (y1 >= y2) continue;
							//�� ���������� ��������� �簢���� ���� ������Ȯ��
							if (!vertex[x1][y2]) continue; //������ ����
							//��������� �簢���� ���ϴ� ������Ȯ��
							if (!vertex[x2][y1]) continue;

							//����������� ã����
							int area = (x2 - x1) * (y2 - y1);
							if (min > area) { //�ּڰ��̸� ���
								min = area;
								res_x1 = x1; //��ǥ���
								res_y1 = y1; 
								res_x2 = x2;
								res_y2 = y2;
							}
						}

					}
				}
			}
		}
	}

	if (min == 0x7fffffff)
		return 0;
	else
		return min;
}

int main(void) {
	scanf("%d%d%d", &y, &x, &n); //x, y�� ��, �� ��ǥ�� �α����� �ٲپ� ����
	x--; y--; //��ǥ������ǥ�� 1,1~ 100, 100������ ���� �࿭��ǥ�� 0,0���� �����ϹǷ�
	for (int i = 0; i < 100; i++) //�ʱ�ȭ
		for (int j = 0; j < 100; j++)
			vertex[i][j] = false;

	//�Է��� �޾Ƽ� ������, ������ �׷쿡 �ְ�
	//������ȯ������ vertext�� ���������� ���
	int prevFlag;
	for (int i = 0, temp; i < n; i++) {
		char c, junk;
		int currentFlag = -1;
		int xx=x, yy=y; //�κ��� �����̱��� ������ǥ
		scanf("%c", &junk); //�ٹٲ޹��� ����
		scanf("%c%d", &c, &temp);
		if (c == 'R') { //������ �׷�
			currentFlag = 1;
			y += temp;
			width.push_back({ {xx, yy},{x, y} });
		}
		else if (c == 'L') { //������ �׷�
			currentFlag = 2;
			y -= temp;
			width.push_back({ {x, y},{xx, yy} });
		}
		else if (c == 'D') { //������ �׷�
			//��ǥ������ down => �࿭�� up
			currentFlag = 4;
			x -= temp;
			height.push_back({ {x, y},{xx, yy} });
		}
		else if (c == 'U') { //������ �׷�
			//��ǥ������ down => �࿭�� up
			currentFlag = 3;
			x += temp;
			height.push_back({ {xx, yy},{x, y} });
		}

		if (i == 0)
			prevFlag = currentFlag;

		if (prevFlag != currentFlag) //���� �̵��� ������ȯ�ߴٸ�
			vertex[xx][yy] = true; //������ǥ ��ġ�� ������

		prevFlag = currentFlag;
	}

	findVertex(); 
	if (calculate() == 0) {
		printf("0");
		return 0;
	}
	else {
		printf("%d %d\n%d %d", res_y1 + 1, res_x1 + 1, res_y2 + 1, res_x2 + 1);
		return 0;
	}

}