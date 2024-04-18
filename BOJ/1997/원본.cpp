//#define _CRT_SECURE_NO_WARNINGS 
//#include <bits/stdc++.h>
//using std::vector;
//int n, w, b, *** blocks, * lines, ** box, box_h = 0;
//vector<int> heights, res;
//void clear();
//void func();
//bool isRight(int block_num, int start_h);
//void packing(int block_num, int start_h);
//void printAll();
//void debug();
//
//void printAll() {
//	for (int i = 0; i < res.size(); i++)
//		printf("%d ", res[i]);
//}
//
//void clear() { //�ڽ� �ʱ�ȭ
//	for (int i = 0; i < b + 10; i++)
//		for (int j = 0; j < w; j++)
//			box[i][j] = 0;
//}
//
//void func() {
//	box = new int* [b + 10];
//	for (int i = 0; i < b + 10; i++)
//		box[i] = new int[w];
//
//	clear(); //ó�� �ʱ�ȭ
//
//	for (int k = 0; k < n; k++) {
//
//		int start_h; //���� �������ִ� �ּ� ����
//		int current_h = heights[k]; //������� ����
//		int gap = 0;
//
//		for (start_h = box_h + 1; start_h > 0; start_h--) { //pack�� ���� �ִ���� + 1 ���� Ȯ��
//			if (!isRight(k, start_h)) { //�Ұ����ϸ� ��
//				break;
//			}
//			gap++;
//		}
//		if (box_h != 0) //�̹� ���� �׿��ִ���� �� ��ĭ���� ���� �ױ����
//			start_h++;
//		//printf(">> >> >> �߰��� ������ġ%d\n", start_h);
//
//		if (start_h + current_h > b) { //1.�װ��� ���̰� �ڽ��� �ʰ��Ѱ��
//			res.push_back(box_h); //���� �ڽ��ִ� ����(�ε���X) ����� ����
//			clear(); //�ڽ� ����
//			box_h = current_h;  //���� �ڽ��ִ����(�ε���X)�� ��������̷� ����
//			packing(k, 0); //�ڽ��ٴں��� ���� ����
//			//printf(">> %d : 1\n", k);
//		}
//		else if (start_h + current_h == b) { //2.�װ��� ���̰� �ڽ��� ��ġ
//			res.push_back(b); //�ڽ����̸� ����� ����
//			clear(); //�ڽ� ����
//			box_h = 0; //�ڽ� �ִ���� 0���� ����
//			//printf(">> %d : 2\n", k);
//		}
//		else { //3.�������̰� ���� �ڽ����� ������
//			packing(k, start_h); //������ ���� ����
//			box_h = start_h + current_h; //�ڽ� �ִ���� ����
//			//printf(">> %d : 3\n", k);
//		}
//
//		//�������� �ڽ��� �������̳������� ����� ����
//		if (k == n - 1 && box_h != 0)
//			res.push_back(box_h);
//
//		//printf(">> ���� �ڽ� �ִ���� : %d\n", box_h);
//	}
//
//}
//
//void debug(int block_num, int start_h) {
//	int** d = new int* [b + 10];
//	for (int i = 0; i < b + 10; i++)
//		d[i] = new int[w];
//
//	for (int i = 0; i < b + 10; i++)
//		for (int j = 0; j < w; j++)
//			d[i][j] = box[i][j];
//
//	for (int i = start_h; i < start_h + heights[block_num]; i++) {
//		for (int j = 0; j < w; j++) {
//			if (blocks[block_num][i - start_h][j] == 1)
//				if (d[i][j] == 1)
//					d[i][j] = -1;
//				else
//					d[i][j] = -2;
//			else if (d[i][j] == 1)
//				d[i][j] = 1;
//			else
//				d[i][j] = -4;
//		}
//	}
//
//	for (int i = 0; i < b + 10; i++) {
//		for (int j = 0; j < w; j++) {
//			if (d[i][j] == -1)
//				printf("?");
//			else if (d[i][j] == -2)
//				printf("B");
//			else if (d[i][j] == 1)
//				printf("X");
//			else
//				printf(".");
//		}
//		printf("\n");
//	}printf("\n");
//}
//
//bool isRight(int block_num, int start_h) { //���� ������ �ִ��� Ȯ��
//	//debug(block_num, start_h); //��¿뵵
//
//	int h = heights[block_num];
//	for (int i = start_h; i < start_h + h; i++) { //���� �Ȱ�ġ���� Ȯ��
//		for (int j = 0; j < w; j++) {
//			//printf("%2d", box[i][j]);
//			//�ڽ��� ���� ��ġ�� �ȵ�
//			if (box[i][j] == 1 && blocks[block_num][i - start_h][j] == 1) {
//				//printf(">>>>>>>>>>>>>>>> %d %d �浹\n", i, j);
//				return false; //���� �� ����
//			}
//		}
//		//printf("\n");
//	}
//	return true;
//}
//
//void packing(int block_num, int start_h) { //pack�� ���� ����
//	int h = heights[block_num];
//	for (int i = start_h; i < start_h + h; i++) {
//		for (int j = 0; j < w; j++) {
//			if (blocks[block_num][i - start_h][j] == 1) //���κκи�
//				box[i][j] = 1;
//		}
//	}
//}
//
//int main(void) {
//	scanf("%d%d%d", &n, &w, &b);
//	blocks = new int** [n]; //blocks ������
//	for (int k = 0, h; k < n; k++) {
//		scanf("%d", &h);
//		heights.push_back(h);
//		blocks[k] = new int* [h];
//		char c;
//		//���� �Ʒ����ͽ�����, ���� �޸𸮻󿡴� �Ʒ����� ���� ���̹Ƿ�
//		//�Է��� ���Ϲ������� ����.
//		for (int i = h - 1; i >= 0; i--) {
//			blocks[k][i] = new int[w];
//			scanf("%c", &c); //�ٹٲ޹�������
//			for (int j = 0; j < w; j++) {
//				scanf("%c", &c); //���о��
//				if (c == 'X')
//					blocks[k][i][j] = 1; //��
//				else
//					blocks[k][i][j] = 0; //����
//			}
//		}
//
//	}
//	lines = new int[w]; //lines �ʺ񸶴��� ������� ���������� ���
//	for (int i = 0; i < w; i++)
//		lines[i] = 0;
//
//	func();
//	printAll();
//
//	return 0;
//}