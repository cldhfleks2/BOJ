#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
std::vector<std::pair<std::string, int>> wordList;

void logic() {
	int t;
	int alpha[26]; //0~25 ���ĺ����
	scanf("%d", &t);
	while (t--) {
		memset(alpha, 0, sizeof(alpha)); //�迭 �ʱ�ȭ
		char input[11]; //ó�� �Է¹��� �ܾ�
		char output[11]; //�ϼ��ȴܾ� (�ִ�ũ��10 + 1 \0)
		memset(input, '\0', sizeof(input)); 
		memset(output, '\0', sizeof(output)); 
		scanf("%s", input); //�ܾ �о��
		int i = 0;
		//�Է¹����ܾ��� ���ĺ� �������� ����ϴ� �κ�
		while (input[i] != '\0') {
//			printf("ī��Ʈ :: %c", input[i]);
			alpha[(int)input[i] - 97]++; //���ĺ� ���������
			i++;
		}

		int k = 0; //output�� ���� �ε���
		//�ܾ �ϼ��ϴ� �κ�
		for (int j = 0; j < 26; j++) {
			if (alpha[j] > 0) {
				while (alpha[j]--) { //��������ŭ���
					output[k] = (char)(j + 97); //�ܾ �ϳ�������
					k++;
				}
			}
		}
		std::string s(output); //�ϼ��� �ܾ�(string ���� ��ȯ)
//		printf("�ܾ� : %s  \n", output); //�˻��

		//����Ʈ�� �߰��ϴºκ�
		int len = wordList.size();
		int j = 0;
		bool check = false;
		while (len--) {
			if (s.compare(wordList[j].first) == 0) { //���ٸ�
				check = true;
				break;
			}
			j++;
		}
		//j�� �ǳ��Ǵ� �ߺ��Ȱ�
		if (check) { //�ܾ �ߺ��Ȱ��
			int num = wordList[j].second; //����Ƚ���ҷ���
			wordList.erase(wordList.begin() + j); //j��° ���Ҹ� �����
			wordList.push_back({ s, num + 1 }); //�������� 1 ������ ���Ҹ� ���� �߰�
//			printf("%d�� => �ߺ�\n", i);
		}
		else { //�ܾ ó����ϵǴ°��
			wordList.push_back({ s, 1 }); //�ܾ��Ʈ�߰�
//			printf("%d�� => ó��\n", i);
		}
	}
}

void print() {
	printf("%d\n", wordList.size());
}

int main(void) {
	logic();
	print();

	return 0;
}