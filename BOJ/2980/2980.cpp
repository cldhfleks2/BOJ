#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>

int N, L, ** TL; //TL : �Է¹��� ��ȣ�� 0:��ġ 1:���������ӽð� 2:�ʷϺ����ӽð�
bool* road; //���ΰ� �̵������� ����(���������� �ʷϺ�����)���� ����� ����
int t = 0; //�ð�
int distance = 0;
void init();
void traffic();
void drive();

void init() {
    scanf("%d %d", &N, &L);
    
    road = new bool[L + 1]; // 1~ L����
    //�켱 ��� ���α����� �̵��������� ���
    //�ؿ��� ��ȣ����ġ���� ó���� ���������� ����Ұ���
    road[0] = true; //�˻������ ����
    for (int i = 1; i <= L; i++) 
        road[i] = true; 

    TL = new int* [N];

    for (int i = 0; i < N; i++) {
        TL[i] = new int[3];
        //��ȣ����ġ, ���������ӽð� �ʷϺ����ӽð�
        scanf("%d %d %d", &TL[i][0], &TL[i][1], &TL[i][2]);
    }

    //��ȣ����ġ���� ó���� ������(�̵��Ұ���)���� ���
    for (int i = 0; i < N; i++) 
        road[TL[i][0]] = false;
    
}

//���� �����Ͽ� ���γ��� �����ϸ� �ɸ� �ð��� ����ϴ� �Լ�
void drive() { 
    while (true) {
        t++; //�ð� �帧

        traffic(); //���� 1m �� ��ġ�� ��ȣ����� ���

        if (distance + 1 == L) { //���� 1m�� ���γ��ΰ��(�̰��� ��ȣ���̾���)
            printf("%d", t-1);
            return; //����
        }
        else {
            if (road[distance + 1]) { //���� 1m�� ��ġ�� �̵������� ���¶�� 1m����
                distance++;
            }
        }
        //printf("�ð�: %2d , ��ġ: %2d  >> ", t, distance);
        //for (int i = 0; i < N; i++)
        //   printf("%d��°��ȣ�� ����:%d  ,  ", TL[i][0], road[TL[i][0]]);
        //for (int i = 0; i <= L ; i++)
        //    printf("%d ", road[i]);
        //printf("\n");
    }
}

//�ð������� ��ȣ�� ������ road�� ��������ִ� �Լ�
void traffic() { 
 
    //�ð������� �������� ��ȣ����ġ ���� �̵����� ���¸� ����Ѵ�.
    for (int i = 0, location; i < N; i++) { //��ȣ�� ������ŭ üũ
        location = TL[i][0]; //���� ��ȣ�� ��ġ
        int allLight = TL[i][1] + TL[i][2]; //�����ҽð� + �ʷϺҽð�
        int mod; //�����ȣ���� ���ӵ� �ð�. 

        mod = (t-1) % allLight;
        //���� �������λ��¿��� ������ ���ӽð��� �ى�����
        if (!road[location] && mod == TL[i][1]) {
            //-> �ʷϺҷ� �ٲ�
            road[location] = true; //���λ��¸� �ٲ�
            continue;
        }
        //���� �ʷϺ��λ��¿��� �ʷϺ� ���ӽð��� �ى�����
        if (road[location] && mod == 0) {
            //-> �����ҷ� �ٲ�
            road[location] = false; //���λ��¸� �ٲ�
            continue;
        }
        

    }
        
}

int main() {
    init();
    drive();

    return 0;
}