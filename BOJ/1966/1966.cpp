#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int main(void) {
	int t;
	scanf("%d", &t);
	while (t--) {
		int N, M;
		vector<int> list;
		scanf("%d%d", &N, &M);
		//���Ϳ��ְ� ���� ����� �Ź� ����
		//���ϴ� �����Ͱ� ���ö����� ���� ������
		int frequency[10] = {}; //�󵵼� üũ
		for (int i = 0, temp; i < N; i++) { 
			scanf("%d", &temp);
			list.push_back(temp);
			frequency[temp]++;
		}
		int findIndex = M; //ã�����ϴ� ������ġ
		int currentIndex = 0; //���� ���� ��ġ
		int res = 0; //���Ƚ��
		//printf("&&& ã��:%d  ", findIndex);
		while (true) {
			int currentPriority = list[0]; //���繮���� �߿䵵
			if (currentPriority != 9) { //���繮���� �߿䵵9�� �ƴѰ��
				bool cantPrint = false;
				//ã�¹������� ���� �߿䵵�� �������� �ִ��� Ȯ��
				for (int i = 9; i >= currentPriority + 1 ; i--) {
					if (frequency[i]) {
						cantPrint = true;
						break;
					}
				}
				//ã�¹����� ��ġ���ƴϰ�
				if (cantPrint) { //������ �߿䵵�� ������ �ִ°��
					int temp = list[0];
					//�ǵڷ� �ű�
					list.erase(list.begin() + 0); 
					list.push_back(temp);
					//ã�¹����� ��ġ���ٸ�
					if (currentIndex == findIndex) {
						//ã�� ������ġ ����
						findIndex = list.size() - 1;
						//���� ������ġ ����
						currentIndex = 0;
						continue;
					}
				}//ã�¹����� ��ġ���ƴϰ�
				else { //������ �߿䵵�� ������ ���� ���
					//���
					list.erase(list.begin() + 0); //���� ���� ����
					frequency[currentPriority]--; //���� ���� �󵵼� -1
					res++; //�����
					//ã�¹����� ��ġ���ٸ�
					if (currentIndex == findIndex) break;
				}
			}
			else { //���� ���� �߿䵵�� 9�ΰ�� �ٷ� ��°���
				//ã�¹����� ��ġ�̸�
				if (currentIndex == findIndex) {
					res++;
					break; //��곡
				}
				else {
					//���
					list.erase(list.begin() + 0); //���� ���� ����
					frequency[currentPriority]--; //���� ���� �󵵼� -1
					res++; //�����
				}
			}
			currentIndex++; //���繮����ġ�� ��������
		}
		printf("%d\n", res);
	}
}
