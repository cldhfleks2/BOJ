#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
using std::vector;
int N, M, T;
int parent[52]; //1~51
vector<int> partys[51]; //1~M

int res = 0; //������ ��Ƽ��
int* truth;
void goToParty();
void init();
void Union(int x, int y);
int Find(int x);

int Find(int x) {
    if (parent[x] == x)
        return x;
    return parent[x] = Find(parent[x]); //��ξ���
}

void Union(int x, int y) {
    x = Find(x);
    y = Find(y);
    if (x > y)
        parent[y] = x; //��ū �θ��忡 �ڽ����� ����
    else
        parent[x] = y;
}

void init() {
    scanf("%d%d%d", &N, &M, &T);
    for (int i = 1; i <= N; i++) //�ʱ�ȭ
        parent[i] = i;
    parent[51] = 51;
    truth = new int[T];

    for (int i = 0; i < T; i++)
        scanf("%d", &truth[i]);

    if (T == 0) //�Ʒ��� �ڵ尡 �������°��� ����
        return;

    
    for (int i = 0; i < T; i++)
        parent[truth[i]] = 51; //������ ���ϴ� ����� ��� �θ���� 51����

}
//M���� ��Ƽ����� �Է¹ް� �� ��Ƽ�� Union������ ����
void goToParty() { 
    for (int k = 1; k <= M; k++) {
        int num;
        scanf("%d", &num);
        bool canLie = true;

        for (int i = 0; i < num; i++) {
            int human;
            scanf("%d", &human);
            partys[k].push_back(human); //k��° ��Ƽ��Ͽ� ����
        }
        //������ �ƴ»���� ������ ��� ��Ƽ���� ����������
        //�ռ� �Է±����� �ް� �� �� ������ ��� �����ϵ���
        if (T == 0) {
            res++;
            continue;
        }

        for (int i = 0; i < num - 1; i++)
            Union(partys[k][i], partys[k][i + 1]); //��Ƽ �����ڳ��� �տ���
    }
}

//M���� ��Ƽ������ ����� �������� ������ ��츦 ���
void calculate() {
    if (T == 0) {
        printf("%d", M); //��� ��Ƽ���� ������ ����
        return;
    }
    
    for (int k = 1; k <= M; k++) {
        int size = partys[k].size();
        bool canLie = true;
        for (int i = 0; i < size; i++) {
            //k��° ��Ƽ�� i�� �������� �θ��尡 
            //51(������ �ƴ� ����׷��� ��Ʈ����ȣ)�̶��
            if (Find(partys[k][i]) == 51) {
                canLie = false; //�� ��Ƽ���� �����̴� �������� �Ҽ�����
                break;
            }
        }

        if (canLie)
            res++;
    }

    printf("%d", res);
}

int main(void) {
    init();
    goToParty();
    calculate();

    return 0;
}