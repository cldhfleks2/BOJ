#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
using namespace std;

int main(int n, int temp) {
	scanf("%d", &n);

	int numbers[53] = {0}; //��ȣ������ϴ� ����
	int alphabet[53] = {0}; //�򹮱���ϴ� ���� 0:���� 1~26:�빮�� 27~52:�ҹ���

	//��ȣ�� �Է¹޴� �κ�
	for (int i = 0; i < n - 1; i++) {
		scanf("%d", &temp);
		numbers[temp]++; //�ش� ���ڰ����� ī��Ʈ
	}
	//%d ���� %c�� �о�ö� �ٹٲ޹��ڱ��� �о���Ƿ�
	//�ٹٲ޹��ڸ� �̸� �о��ֱ�����
	scanf("%d\n", &temp);
	numbers[temp]++; //�ش� ���ڰ����� ī��Ʈ

	//���Է¹޴� �κ�
	for (int i = 0; i < n; i++) {
		char temp;
		scanf("%c", &temp);
		if (temp == ' ') { //���鹮�ڶ��
			alphabet[0]++;
		}
		else if(65 <= temp && temp <= 90){ //�빮���϶� �ƽ�Ű�ڵ�
			alphabet[temp - 64]++; //1~26���� ����
		}
		else if (97 <= temp && temp <= 122) { //�ҹ���
			alphabet[temp - 70]++; //27~52�� ����
		}
	}
	
	//�򹮰� ��ȣ���� ���ϴ� �κ�
	for (int i = 0; i < 53; i++) {
		if (alphabet[i] != numbers[i]) { //Ʋ���ٸ�
			printf("n");
			return 0;
		}
	}

	//����������� ���� ��ġ�Ѱ�
	printf("y");
	return 0;
}