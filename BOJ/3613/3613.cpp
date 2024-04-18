#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>

char input[101]; //�Է� ���� ����
std::vector<std::string> res; //�ܾ���� ����Ұ���
void translate(bool isJava);
void logic();
void init();

void init() {
	scanf("%s", &input);
}

void logic() {
	bool isJava = false;
	char buffer[101] = {};
	int cursor = 0;
	int endIndex = 0;

	for (int i = 0; i <= 100; i++) { 
		char c = input[i];
		if (endIndex == 0 && c == '\0')
			endIndex = i - 1;

		//ù���ڰ� �빮�ڳ� �������̸� ����
		if (i == 0 && 65 <= c && c <= 90) { 
			printf("Error!");
			return;
		}
		if (i == 0 && c == '_') {
			printf("Error!");
			return;
		}
		//�׿ܿ� �빮�ڰ� ���̸� �ڹٷ� �ν�. ���� ������ �Ʒ��� üũ
		if (65 <= c && c <= 90) {
			isJava = true;
			break;
		}
	}

	if (input[endIndex] == '_') { //���������ڰ� '_'�ΰ��
		printf("Error!");
		return;
	}

	bool isHyphen = false;
	for (int i = 0; i <= 100; i++) {
		char c = input[i];
		if (c == '_') { //'_' �� ���°��
			if (!isHyphen) { //���ӵ����ʾ����� üũ
				isHyphen = true;
			}
			else { //���ӵǰ� '_' �� ������ ����
				printf("Error!");
				return;
			}
			//'_' ������ �빮�ڰ� ���°��
			if (65 <= input[i + 1] && input[i + 1] <= 90) {
				printf("Error!");
				return;
			}
			continue;
		}
		//'_'�� ���� �������
		if (isHyphen) //������ '_'�� ���°�� üũ����
			isHyphen = false;
	}

	if (isJava) { //java
		for (int i = 0; i <= 100; i++) { //���� Ȯ�ο�
			char c = input[i];
			if (c == '_') {
				printf("Error!");
				return;
			}
		}

		for (int i = 0; i <= 100; i++) { //JAVA�ܾ �ڸ��� �κ�
			char c = input[i];
			if (65 <= c && c <= 90) { //�빮�ڸ� ���ο�ܾ�
				std::string s(buffer);
				res.push_back(s); //�������� �ܾ ����ϰ�
				for (int j = 0; j <= 100; j++)
					buffer[j] = NULL;
				cursor = 0;
				buffer[0] = (char)((int)c + 32); //�ҹ��ڷιٲپ ���ۿ����
				cursor++;
			}
			else { //�ҹ��ڸ� �ܾ �ȳ�����
				buffer[cursor] = c; //���ۿ����(�ҹ����� ����)
				cursor++;
			}
		}
		std::string s(buffer);
		res.push_back(s); 

	}
	else { //C++
		for (int i = 0; i <= 100; i++) { //���� Ȯ�ο�
			char c = input[i];
			if (65 <= c && c <= 90) {
				printf("Error!");
				return;
			}
		}

		for (int i = 0; i <= 100; i++) { //C++ �ܾ �ڸ��ºκ�
			char c = input[i];
			
			if (c == '_') {
				std::string s(buffer);
				res.push_back(s); //�������� �ܾ ����ϰ�
				for (int j = 0; j <= 100; j++)
					buffer[j] = NULL;
				cursor = 0;
			}
			else {
				buffer[cursor] = c;
				cursor++;
			}

		}
		std::string s(buffer);
		res.push_back(s);

	}

	translate(isJava);
}

void translate(bool isJava) { //�ܾ���� �ٸ����� �ٲ��ִ� �κ�
	std::string ans;

	if (isJava) { //JAVA
		for (int i = 0; i < res.size(); i++) {
			ans.append(res[i]);
			if (i != res.size() - 1) {
				ans.append("_");
			}
		}
	}
	else { //C++
		for (int i = 0; i < res.size(); i++) {
			if (i == 0) {
				ans.append(res[i]);
			}else{
				ans += (char)((int)res[i][0] - 32); //ù���� �빮�ڷ�
				for (int j = 1; j < res[i].length(); j++) {
					ans += res[i][j]; //�������� �ҹ��� �״��
				}
			}
		}
	}
	printf("%s", ans.c_str());
}

int main(void) {
	init();
	logic();

	return 0;
}