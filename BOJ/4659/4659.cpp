#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>

void password(char* c);

void init() {
	while (true) {
		char in[21];
		scanf("%s", &in);
		if ((std::string)in == "end") //��������
			break;
		printf("<%s> ", in); //<���> ���� ���
		password(in); //������ is acceptable or is not acceptable���
	}
}

void password(char* c) {
	char temp[21] = {'\0'}; //ee, oo�������� e, o �θ� �����ϴ� �迭
	int cursor = 0; //�� �迭�������� �ε���
	char pre = NULL; //���� ���ڸ� ����
	bool last = false; //eee, ooo�� �������� Ȯ���ϱ�����
	for (int i = 0; i < 20; i++) { //ee �� oo�� Ȯ��
		if (c[i] == '\0') //���� ������ ����
			break;
		if (pre == c[i]) { //�������ڿ� ���繮�ڰ� �������
			//����3) �������ڰ� ���������� ������ȵ� �׷��� ee, oo�� ���
			if (pre == 'e' || pre == 'o') {
				if (!last) { 
					last = true;
				}
				else { //���� eee , ooo�� ���°���� ����
					printf("is not acceptable.\n");
					return;
				}
			}
			else {
				printf("is not acceptable.\n");
				return;
			}
		}
		else {
			last = false;
			pre = c[i];
			temp[cursor] = c[i];
			cursor++;
		}
	}

	int* check = new int[cursor]; //������ ������ 1 �� 0���� ��ȯ�Ͽ� �����ϴ� �迭
	bool vowel = false; //������ �ϳ��� �������� Ȯ���ϱ�����
	for (int i = 0; i < cursor; i++) {
		if (temp[i] == 97 ||
			temp[i] == 101 ||
			temp[i] == 105 ||
			temp[i] == 111 ||
			temp[i] == 117) {
			vowel = true;
			check[i] = 1; //������ 1
		}
		else {
			check[i] = 0; //������ 0
		}
	}
	if (!vowel) { //����1) ������ �ݵ�� �ϳ��̻� �����ؾ���
		printf("is not acceptable.\n");
		return;
	}
	int preNum = -1; //��������(���� or ����)
	int cnt = 1; //���ӵ� ����
	for (int i = 0; i < cursor; i++) { //����2) ����/������ 3���̻󿬴޾� ������ȵ�
		if (preNum != check[i]) { //������ ������ �����Ƴ��°��
			cnt = 1;
			preNum = check[i];
		}
		else { //���� �� ���� �Ǵ� ������ ������ ���°��
			cnt++;
			if (cnt >= 3) { //���޾� 3�����°��
				printf("is not acceptable.\n");
				return;
			}
		}
	}
	//����������� ��� ������ �����Ѱ�
	printf("is acceptable.\n");
	return;
}

int main(void) {
	init();

	return 0;
}