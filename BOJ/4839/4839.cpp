#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
using namespace std;

int n;
deque<int> numbers; //처음 입력받은 숫자들
int maxNum = 0; //입력받은 수중 최댓값
deque<int> primeList; //소수리스트

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
        if (maxNum < n) //최댓값을 미리 구해둠
            maxNum = n;
    }
    
}

void makePrimeList() { //소진법에 사용될 모든 소수(P)를 찾는 알고리즘
    primeList.push_back(2); //미리 소수 2 등록
    int prePrime = 2; //가장 최근 발견한 소수
    int primeMultiSum = 2; //소수들의 곱
    
    while (true) { //소수끼리 차례대로 곱하면서 int최댓값을 넘기전까지의 소수만을 찾는 부분
        //다음 소수를 찾는다
        int nowPrime = prePrime + 1; //이전소수 다음 수부터 소수인수를 찾는다.
        while (true) {
            bool isPrime = true;
            //2~ 루트nowPrime 까지로 나누어 떨어지면 소수가아님
            for (int i = 2; i <= sqrt(nowPrime); i++) {
                if (nowPrime % i == 0) {
                    isPrime = false;
                    break; //소수가아님
                }
            }
            if (isPrime) { //소수임을 발견
                break;
            }
            else { //소수가아니면 반복
                nowPrime++; //다음 숫자부터 반복
            }
        }

        if (0 < primeMultiSum * nowPrime &&
            primeMultiSum * nowPrime <= maxNum) { //입력받은 숫자의 최대크기를 넘지 않는 소수만 기록함
            prePrime = nowPrime; //이전 소수 갱신
            primeMultiSum *= nowPrime; //소수들의 곱 갱신
            primeList.push_back(nowPrime); //찾은 소수를 리스트에 기록
        }
        else {
            break;
        }
        //실험결과 maxNum = 2147483647일때 (입력 최댓값)
        //2 3 5 7 11 13 17 19 23 이 최대소수임
    }
}

int findPrimeMulti(int num) { //사용될 소수의 최대갯수를 리턴해줌.
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
        int num = numbers[i]; //비교할 숫자 초깃값은 입력된값
        int idx = findPrimeMulti(num); //사용될 소수 최대 갯수
        //각자릿수
        //+1 이유는 일의자릿수는 맨마지막에 0번인덱스로 추가하기위함
        int* ans = new int[idx + 1]; 

        for (int j = idx; j >= 0; j--) { // 
            int sum = 1; //소수들의곱 계산
            int k;
            for (k = 0; k < j; k++) {
                sum *= primeList[k];
            }
            //printf("곱한값:%d\n", sum);

            int a = (int)((double)num / (double)sum);

            ans[j] = a; //찾은 자릿수 기록
            num -= a * sum; //num 갱신
        }

        printAll(numbers[i], ans, idx);
    }


}
void printAll(int num, int* ans, int size) {
    printf("%d = ", num); //입력받은 숫자를 바로 출력

    bool units = true; //일의자릿수가 존재하는지 확인하는 변수
    if (ans[0] != 0) { //일의자릿수가 0이면 출력하지않음
        printf("%d", ans[0]);
    }
    else { //일의자릿수가 0이므로 출력X
        units = false;
    }

    for (int i = 1; i <= size ; i++) { //곱할갯수
        if (ans[i] == 0)
            continue;
        if (units) { //일의자릿수가 존재할때
            printf(" + %d", ans[i]);
        }
        else { //일의자릿수가 존재 X
            printf("%d", ans[i]);
            units = true; // i==1 일때만 유효함. 그다음부턴 정상적으로 출력되도록
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