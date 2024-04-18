#include <bits/stdc++.h>
using namespace std;

int n, *queen, result;

bool promisingCheck(int row) {//�ش� ��, ���� ���� ������ �ִ°�
	for (int i = 0; i < row; i++) { //�Է¹��������Ž��
		if ((queen[i] == queen[row]) || //������ġ�� ��ġ�ų� �밢���ΰ�� �Ұ�����
			//������ġ�� ��ĥ���� �����ϱ� ������. ���̾ȵ���
			(row - i == (abs(queen[row] - queen[i])))) {
			return false;
		}
	}
	return true;
}

void n_queen(int row) {
	if (row == n) { //n����� ���� ��� ���ҵ��� ����Ǽ� +1
		result++;
		return;
	}
	else {
		for (int col = 0; col < n; col++) {
			//���������ϰ� ���� �ϳ����ٲٸ鼭 �����ϸ� 
			//�� ���� Ž�����ϴ� DFS�� �����ѳ�忩�߸� Ž�����ϴ�
			//��Ʈ��ŷ�̵ǰڴ�.
			queen[row] = col; //row�� col���� ���� ���´�.
			if (promisingCheck(row)) //������ġ�� ���� ��ġ�� �˸´ٸ� ���� ���� �˻��Ѵ�.
				n_queen(row + 1); //�̰� ����ȵǸ� Ž���������, ����Ǽ��� ī��Ʈ�����ʴ´�.
		}
	}
}

int main(void) {
	cin >> n;
	queen = new int[n];

	n_queen(0);
	cout << result;

	return 0;
}