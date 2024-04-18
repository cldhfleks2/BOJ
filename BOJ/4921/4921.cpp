#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
using std::pair;

int cnt = 0; //���° ���̽��ΰ�
//���� ��,����¸� �����γ�Ÿ�� ��
//[0]:�� [1]:��
//0: �ݵ���(1��,2��������)
//1: ���ϻ簢��
//2: ���Ͽ���
//3: ����簢��
//4: �������
int preBlock[2]; //������
//��� preBlock�� 0��, ������ �����ʿ䰡 ����

void input();
pair<int, int> findBlockKey(char b); //���糪������ �¿���� ������ ��ȯ
void setPrevBlock(int left, int right); //���������¸� ����
bool checkBlock(int left, int right); //�������� ������� �¹����� �ִ°� Ȯ��


void input() {
	while (true) {
		char in[10001]; //�Է¹��� ������
		int size = 0; //������ ����

		scanf("%s", &in);
		if (in[0] == '0') //��������
			break;

		for (int i = 0; i < 10001; i++) { //���� ������ �ľ�
			if (in[i] == '\0')
				break;
			size++; 
		}
		cnt++; //���° ���ΰ�.
		bool possible = true;

		if (in[0] == '1' && in[size-1] == '2') { //�������� ó�������� 1���� 2���̾�� ����
			for (int i = 0; i < size; i++) { //�������� ó������ ������ Ž��
				auto keys = findBlockKey(in[i]); //������� �¿� ���¸� ������ ��ȯ
				if (i == 0) {//ùȸ���� ������ ���ø��ϰ� �Ѿ��.
					setPrevBlock(keys.first, keys.second);
				}
				else { //ùȸ���Ŀ��� �������� ������� ���Ͽ� �������� Ȯ��
					//checkBlock: ������ ������ ���� �¹������ִ� �������� Ȯ��
					if (!checkBlock(keys.first, keys.second)) { //false���Ϲ����� �Ұ������� ���
						printf("%d. NOT\n", cnt);
						possible = false; //�Ұ����ϴ�.
						break;
					}
				}
			}
		}
		else { //�������� ó���� ���� �������ΰ�� �ٷ�����
			printf("%d. NOT\n", cnt);
			possible = false;
		}
		//�� �������� �ɷ������������ ������ �������� ���
		if (possible) {
			printf("%d. VALID\n", cnt);
		}
	}


}

//�Է¹��� ��������ȣ������ ���� ��, �� ���¸� ������ ����
std::pair<int, int> findBlockKey(char b) {
	int res1, res2;
	switch (b) {
	case '1':
		res1 = 0; //�ݵ�
		res2 = 3; //����簢��
		break;
	case '2':
		res1 = 3; //����簢��
		res2 = 0; //�ݵ�
		break;
	case '3':
		res1 = 3; //����簢
		res2 = 3; //����簢
		break;
	case '4':
		res1 = 1; //���ϻ簢
		res2 = 1; //���ϻ簢
		break;
	case '5':
		res1 = 1; //���ϻ簢
		res2 = 4; //�������
		break;
	case '6':
		res1 = 4; //�������
		res2 = 1; //���ϻ簢
		break;
	case '7':
		res1 = 4; //�������
		res2 = 4; //�������
		break;
	case '8':
		res1 = 2; //���Ͽ���
		res2 = 2; //���Ͽ���
		break;
	}

	return { res1, res2 };
}

//�������� �缳���ϴ� �Լ�
void setPrevBlock(int left, int right) {
	preBlock[0] = left;
	preBlock[1] = right;
}

//������� �¿���¸� ������ ���޹޾� �����������Ͽ� ������ �������� Ȯ��
//true : ����
//false �� �����ҽ� �Ұ������� ����ϰ� ����
bool checkBlock(int left, int right) { //������ǻ��� left, right
	int preBlockRight = preBlock[1]; //�������� �����ʺκ�
	int nowBlockLeft = left; //������� ���ʺκ�
	
	bool possible = false;
	//�ΰ��� �¹������ִ� ���� �����̴�.
	if ((preBlockRight == 1 && nowBlockLeft == 3) ||
		(preBlockRight == 3 && nowBlockLeft == 1) || 
		(preBlockRight == 2 && nowBlockLeft == 4) || 
		(preBlockRight == 4 && nowBlockLeft == 2))
		possible = true;

	//������ �� ��������·� ����
	setPrevBlock(left, right);

	return possible;
}

int main(void) {
	input();

	return 0;
}