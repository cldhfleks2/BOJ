#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
using std::vector; using std::queue;
//seq : ����ؾ��ϴ� ������ ���ʴ��
//push_num : ����s�� �� ������
//top : ����s�� �����
int n, *seq, push_num=1, top=-1;

vector<int> s; //����: ���ͷα�����

void func() {
	queue<int> print; //0:-  1:+
	bool error = false;
	int k = 0, num=seq[k];
	while (1) {
		//����ִٸ� ������ ���Ҹ� push
		if (top == -1) {
			s.push_back(push_num);
			top++;
			push_num++;
			print.push(1); //�������
		}

		//���ÿ� ���� �ִ��� �ѱ���
		if (push_num == n + 1) break;

		//���Ҹ� ������ ����⿡�� ã������ pop
		if (s[top] == num) {
			s.erase(s.begin() + top); //top��ġ���� �����͸� ����
			top--;
			print.push(0); //�������
			k++;
			num = seq[k]; //������ ã����
		}
		else { //����⿡�� ��ã������ push
			s.push_back(push_num);
			top++; //�����������
			push_num++; //���������Ҽ�..
			print.push(1); //�������
		}

		if (k == n)
			break;

	}

	
	//���ÿ� �������Ҹ� ���� pop
	while (top != -1) {
		if (s[top] != num) { //ã�����ϴ� ���� �ƴϸ�
			error = true;
			break;
		}
		else { //ã�����Ѵ� �����
			top--;
			print.push(0); //�������
			if (k == n + 1) break;
			k++;
			num = seq[k];
		}
	}
	
	//printf(">>>>>> %d  %d  num %d\n", top, k, num);

	//������ ã�����߰ų�
	//���ÿ� ���� ���������� ����
	if (k != n || top != -1) {
		error = true;
	}

	//����ϴ� �κ�
	if (error) {
		printf("NO");
		return;
	}
	else {
		while (!print.empty()) {
			if (print.front() == 0)
				printf("-\n");
			else
				printf("+\n");
			print.pop();
		}
	}

}

int main(void) {
	scanf("%d", &n);
	seq = new int[n];
	for (int i = 0; i < n; i++) scanf("%d", &seq[i]);

	func();

	return 0;
}