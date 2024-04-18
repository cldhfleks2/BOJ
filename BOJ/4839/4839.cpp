#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
using namespace std;

int n;
deque<int> numbers; //ó�� �Է¹��� ���ڵ�
int maxNum = 0; //�Է¹��� ���� �ִ�
deque<int> primeList; //�Ҽ�����Ʈ

void makePrimeList();
void init();
int findPrimeMulti(int num);
void findSOJIN();
void printAll(int num, int* ans, int size);

void init() {
    while (true) {
        scanf("%d", &n);
        if (n == 0)
            break;
        numbers.push_back(n);
        if (maxNum < n) //�ִ��� �̸� ���ص�
            maxNum = n;
    }
    
}

void makePrimeList() { //�������� ���� ��� �Ҽ�(P)�� ã�� �˰���
    primeList.push_back(2); //�̸� �Ҽ� 2 ���
    int prePrime = 2; //���� �ֱ� �߰��� �Ҽ�
    int primeMultiSum = 2; //�Ҽ����� ��
    
    while (true) { //�Ҽ����� ���ʴ�� ���ϸ鼭 int�ִ��� �ѱ��������� �Ҽ����� ã�� �κ�
        //���� �Ҽ��� ã�´�
        int nowPrime = prePrime + 1; //�����Ҽ� ���� ������ �Ҽ��μ��� ã�´�.
        while (true) {
            bool isPrime = true;
            //2~ ��ƮnowPrime ������ ������ �������� �Ҽ����ƴ�
            for (int i = 2; i <= sqrt(nowPrime); i++) {
                if (nowPrime % i == 0) {
                    isPrime = false;
                    break; //�Ҽ����ƴ�
                }
            }
            if (isPrime) { //�Ҽ����� �߰�
                break;
            }
            else { //�Ҽ����ƴϸ� �ݺ�
                nowPrime++; //���� ���ں��� �ݺ�
            }
        }

        if (0 < primeMultiSum * nowPrime &&
            primeMultiSum * nowPrime <= maxNum) { //�Է¹��� ������ �ִ�ũ�⸦ ���� �ʴ� �Ҽ��� �����
            prePrime = nowPrime; //���� �Ҽ� ����
            primeMultiSum *= nowPrime; //�Ҽ����� �� ����
            primeList.push_back(nowPrime); //ã�� �Ҽ��� ����Ʈ�� ���
        }
        else {
            break;
        }
        //������ maxNum = 2147483647�϶� (�Է� �ִ�)
        //2 3 5 7 11 13 17 19 23 �� �ִ�Ҽ���
    }
}

int findPrimeMulti(int num) { //���� �Ҽ��� �ִ밹���� ��������.
    int sum = 1;
    int idx = 0;
    for (int i = 0; i < primeList.size(); i++) {
        if (sum * primeList[i] > num) 
            break;
        idx = i;
        sum *= primeList[i];
    }
    return idx + 1;
}

void findSOJIN() {
    for (int i = 0; i < numbers.size(); i++) {
        int num = numbers[i]; //���� ���� �ʱ갪�� �ԷµȰ�
        int idx = findPrimeMulti(num); //���� �Ҽ� �ִ� ����
        //���ڸ���
        //+1 ������ �����ڸ����� �Ǹ������� 0���ε����� �߰��ϱ�����
        int* ans = new int[idx + 1]; 

        for (int j = idx; j >= 0; j--) { // 
            int sum = 1; //�Ҽ����ǰ� ���
            int k;
            for (k = 0; k < j; k++) {
                sum *= primeList[k];
            }
            //printf("���Ѱ�:%d\n", sum);

            int a = (int)((double)num / (double)sum);

            ans[j] = a; //ã�� �ڸ��� ���
            num -= a * sum; //num ����
        }

        printAll(numbers[i], ans, idx);
    }


}
void printAll(int num, int* ans, int size) {
    printf("%d = ", num); //�Է¹��� ���ڸ� �ٷ� ���

    bool units = true; //�����ڸ����� �����ϴ��� Ȯ���ϴ� ����
    if (ans[0] != 0) { //�����ڸ����� 0�̸� �����������
        printf("%d", ans[0]);
    }
    else { //�����ڸ����� 0�̹Ƿ� ���X
        units = false;
    }

    for (int i = 1; i <= size ; i++) { //���Ұ���
        if (ans[i] == 0)
            continue;
        if (units) { //�����ڸ����� �����Ҷ�
            printf(" + %d", ans[i]);
        }
        else { //�����ڸ����� ���� X
            printf("%d", ans[i]);
            units = true; // i==1 �϶��� ��ȿ��. �״������� ���������� ��µǵ���
        }
        
        for (int j = 1; j <= i; j++) {
            printf("*%d", primeList[j - 1]);
        }
        
    }
    printf("\n");
}

int main() {
    init(); 
    makePrimeList();
    findSOJIN();
}