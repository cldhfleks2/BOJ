#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
int N, M, *lamp;
void makeRoad();
void findHeight();

//�̺�Ž������ �ٲ����
void makeRoad() {
	scanf("%d\n%d", &N, &M);
	lamp = new int[M];
	for (int i = 0; i < M; i++) { //���ε��Է¹���
		scanf("%d", &lamp[i]);
	}

	findHeight();
}

void findHeight() {
	int H = 1; //���ε��ǳ���
	while (true) {
		int sangbin = 0; //���� ������� ��ġ
		bool find = false;
		bool end = false; //���ε��ȸ loop�� �������� ����
		//printf("%d >> \n", H);
		for (int i = 0; i < M; i++) { //��� ���ε��� ��ȸ
			//���ε�Һ��� ���ʺ��� sangbin�� ��. ������ sangbin++
			int x = lamp[i]; //���� ���ε���ġ
			//printf("\n%d ���ε�\n", lamp[i]);
			if (end) {
				//printf("  <%d>����", sangbin);
				break;
			}
			// x-H ~ x+H ���� ���� ����
			for (int j = x - H; j <= x + H; j++) {
				//printf("  (%d,%d)", j, sangbin);
				if (j < sangbin) { //����̰� �����±��� ��ŵ(ó����0 �̹Ƿ� �������� ��ŵ)
					//printf("!!  ");
					continue;
				}
				if (j > sangbin) { //����̰��ִ� ��ġ�� �������ʰ� �ǳʶٸ� ��������
					end = true; //loop�� ����
					//printf("  <%d,%d>", j, sangbin);
					//printf("����!\n");
					break; //����
				}
				if (sangbin == N) { //����̰� �������� �����ϸ� ����
					end = true; //loop�� ����
					find = true; //������
					//printf("  <%d,%d>", j, sangbin);
					//printf("���� ��� �ǳ���\n");
					break;
				}
				sangbin++;
			}
		}
		//printf("  ������ġ%d  ", sangbin);
		//���������� Ż��
		if (find) {
			//printf("  <%d>�ܺ�����\n", sangbin);
			break;
		}

		//��� ���ε��� ��ȸ������ ����̰� ���� �� ���ǳ����� 
		//���ε���� + 1 �ϰ� �ݺ�
		if (sangbin <= N) { 
			//printf("  <%d>��پȰǳ���\n", sangbin);
			H++; //���ε���̸� + 1 �ϰ� �ݺ�
			continue; //�ݺ�
		}

	}

	//������º�
	printf("%d\n", H);
	delete lamp;
}

int main(void) {
	while (true) {
		makeRoad();
	}


	return 0;
}