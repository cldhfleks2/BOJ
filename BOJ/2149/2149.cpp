#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>

int main(void) {
	int keyLength = 0, secretLength = -1, period = 0;
	//input : ó���Է¹���Ű
	//key : Ű�� ũ�⿡�°� �����Ҵ�Ǿ� ����� Ű
	//originKey : key�� ���纻
	char input[11], *key, *originKey; 
	scanf("%[^\n]s", &input);
	for (int i = 0; i <= 10; i++) //m��ũ�⸦ ����
		if (input[i] == '\0')
			break;
		else
			keyLength++;
	key = new char[keyLength];
	originKey = new char[keyLength];

	for (int i = 0; i < keyLength; i++) {
		originKey[i] = input[i];
		key[i] = input[i];
	}

	char secret[101];
	char c;
	scanf("%c", &c);
	//�Է°��� �޴� �κ�
	while (scanf("%c", &c) != EOF) {
		secret[secretLength+1] = c;
		secretLength++;
		if (secretLength > 0 && c == '\n')
			break;
	}
	period = secretLength / keyLength;

	std::sort(key, key + keyLength); //Ű�� ����

	//��ȣ�����´� �࿭ �����͸� ����Ʈ�� ���
	std::vector<std::pair <char, char*>> list;
	for (int i = 0; i < keyLength; i++) {
		char* s = new char[period]; //�ֱ⸸ŭ�� �迭 ����
		for (int j = 0; j < period; j++) {
			s[j] = secret[period * i + j];
		}
		list.push_back({ key[i], s });
	}
	std::vector<std::pair<char, char*>> res;

	//��ȣ������ ������ �����͸� ��ȯ�ϴ� �κ�
	for (int i = 0; i < keyLength; i++) {
		for (int j = 0; j < list.size(); j++) {
			if (originKey[i] == list[j].first) {
				res.push_back({ originKey[i], list[j].second });
				list.erase(list.begin() + j); //����Ʈ���� �ش���ġ�� ����
				key[j] = NULL;
				break;
			}

		}
	}

	//���� ����ϴ� �κ�
	for (int i = 0; i < period; i++) {
		for (int j = 0; j < keyLength; j++) {
			printf("%c", res[j].second[i]);
		}
	}

	return 0;
}