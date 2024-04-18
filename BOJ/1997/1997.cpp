#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
using std::vector;
int n, w, b, ***blocks, **box, box_h=0;
vector<int> heights, res; 
void clear();
void func();
bool isRight(int block_num, int start_h);
void packing(int block_num, int start_h);
void printAll();

//�������
void printAll() {
	for (int i = 0; i < res.size(); i++)
		printf("%d ", res[i]);
}

//�ڽ� �ʱ�ȭ
void clear() { 
	for (int i = 0; i < b + 10; i++)
		for (int j = 0; j < w; j++)
			box[i][j] = 0;
}

void func() {
	box = new int* [b + 10]; 
	for (int i = 0; i < b + 10; i++)
		box[i] = new int[w];

	clear(); //ó�� �ʱ�ȭ
	
	for (int k = 0; k < n; k++) {
		int start_h; //���� �������ִ� �ּ� ����
		int current_h = heights[k]; //������� ����

		for (start_h = box_h +1; start_h > 0; start_h--) { //pack�� ���� �ִ���� + 1 ���� Ȯ��
			if (!isRight(k, start_h)) { //�Ұ����ϸ� ��
				break;
			}
		}
		if(box_h != 0) //�̹� ���� �׿��ִ���� �� ��ĭ���� ���� �ױ����
			start_h++; 

		if (start_h + current_h > b) { //1.�װ��� ���̰� �ڽ��� �ʰ��Ѱ��
			res.push_back(box_h); //���� �ڽ��ִ� ����(�ε���X) ����� ����
			clear(); //�ڽ� ����
			box_h = current_h;  //���� �ڽ��ִ����(�ε���X)�� ��������̷� ����
			packing(k, 0); //�ڽ��ٴں��� ���� ����
		}
		else if (start_h + current_h == b) { //2.�װ��� ���̰� �ڽ��� ��ġ
			res.push_back(b); //�ڽ����̸� ����� ����
			clear(); //�ڽ� ����
			box_h = 0; //�ڽ� �ִ���� 0���� ����
		}
		else { //3.�������̰� ���� �ڽ����� ������
			packing(k, start_h); //������ ���� ����
			box_h = start_h + current_h; //�ڽ� �ִ���� ����
		}

		//�������� �ڽ��� �������̳������� ����� ����
		if (k == n - 1 && box_h != 0)  
			res.push_back(box_h);
	}

}

//���� ������ �ִ��� Ȯ��
bool isRight(int block_num, int start_h) { 
	int h = heights[block_num];
	for (int i = start_h; i < start_h + h; i++) { //���� �Ȱ�ġ���� Ȯ��
		for (int j = 0; j < w; j++) {
			//�ڽ��� ���� ��ġ�� �ȵ�
			if (box[i][j] == 1 && blocks[block_num][i - start_h][j] == 1)
				return false; //���� �� ����
		}
	}
	return true;
}

//�ڽ��� ���� ����
void packing(int block_num, int start_h) { 
	int h = heights[block_num];
	for (int i = start_h; i < start_h + h; i++) { 
		for (int j = 0; j < w; j++) {
			if(blocks[block_num][i - start_h][j] == 1) //���κκи�
				box[i][j] = 1;
		}
	}
}

int main(void) {
	scanf("%d%d%d", &n, &w, &b);
	blocks = new int** [n]; //blocks ������
	for (int k = 0, h; k < n; k++) {
		scanf("%d", &h);
		heights.push_back(h);
		blocks[k] = new int* [h];
		char c;
		//���� �Ʒ����ͽ�����, ���� �޸𸮻󿡴� �Ʒ����� ���� ���̹Ƿ�
		//�Է��� ���Ϲ������� ����.
		for (int i = h - 1; i >= 0; i--) { 
			blocks[k][i] = new int[w];
			scanf("%c", &c); //�ٹٲ޹�������
			for (int j = 0; j < w; j++) {
				scanf("%c", &c); //���о��
				if (c == 'X')
					blocks[k][i][j] = 1; //��
				else
					blocks[k][i][j] = 0; //����
			}
		}

	}
	func();
	printAll();

	return 0;
}