#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using std::vector; using std::stack; using std::queue;
using std::deque; using std::string; using std::pair;
using std::sort;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;
typedef pair<int, char> pic;
typedef pair<char, int> pci;

int n;
int g;
vector<int> Fibonacci, res, grundy;
void init();
void makeFibonacci();
void makeGrundy(int start, int from);
vector<int> makeLack_of(vector<int> list);
bool needRebuildingList(vector<int> lack_of, vector<int> list);
vector<int> makeLack_of(vector<int> list);
vector<int> rebuildingList(vector<int> list);
void func();

void init() {
    scanf("%d", &n);
    makeFibonacci();
    vector<int> list;
    int max = 0;
    while (n--) {
        int p;
        scanf("%d", &p);
        if (max < p) max = p;
        list.push_back(p);
    }
    makeGrundy(4, max);
    for (int i = 0; i < list.size(); i++)
        g ^= grundy[list[i]];
}

//300�������� �Ǻ���ġ���� ���Ѵ�.
void makeFibonacci() {
    Fibonacci.push_back(1);
    Fibonacci.push_back(1);
    int idx = 2;
    while (1) {
        int value = Fibonacci[idx - 1] + Fibonacci[idx - 2];
        if (value > 3000000) break;
        Fibonacci.push_back(value);
        idx++;
    }
}

//1~p ���� �׷�������� ���ؼ� res�� ����
void makeGrundy(int start, int from) {
    //0~3������ �⺻��
    grundy.push_back(0); grundy.push_back(1); 
    grundy.push_back(2); grundy.push_back(3);
    int num = start;
    int fib_cnt = 1;
    while (1) {
        if (Fibonacci[fib_cnt] >= num)
            break;
        fib_cnt++;
    }
    vector<int> list;
    vector<int> lack_of;
    while (1) {
        /*
        * num : ���� ����
        * fib_cnt : ���� ���ڿ� ���ų� ���� �Ǻ���ġ������ ����
        * list : ���� ���� num �� num�� ���ų� ���� �Ǻ���ġ����� ���� ���� ����Ʈ
        *       ��, num�� 1���� fib_cnt��ŭ�� �Ǻ���ġ������ ���� ���� ����Ʈ
        * lack_of : �׷���� ���� ã�� �������� ����Ʈ�� ���������ʴ� �������
        *       ���� ����Ʈ.
        *       0�� : �׷����� fib_cnt
        *       1�� : �ٷ��� ���� �׷���
        *       2�� �̻� : lack_of���� ��� ���Ҹ� ���� ���Ұ���� ġȯ�ؾ���.
        *                   lack_of�� ġȯ�Ͽ� �������Ŀ� �ٽ� ����üũ�� ����
        * 
        * ���ϴ� ����
        * 1. fib_cnt���� : ���� �� num�� �Ǻ���ġ������ Ȯ��. �´ٸ� fib_cnt++;
        * 2. list ���� : num�� �Ǻ���ġ�� ��(fib_cnt ��ŭ)�� ���� ���� ������� ����
        * 3. lack_of ���� : list���� ���� ������� ����..
        * 4. lack_of ���� üũ : ����Ʈ���� ���Ұ������Ͽ� ������ ���� ������ ����
        * 5. ������ : list,lack_of�ʱ�ȭ grundy�߰� num++;
        *               num�� 300���ʰ��� �ݺ��� ����
        *
        */
        // 1. fib_cnt ����
        int nextFib = Fibonacci[fib_cnt] + Fibonacci[fib_cnt - 1];
        //�ٷ� Fibonacci[fib_cnt + 1]�� ����, vector�ִ�ũ�⸦ �Ѱ� ���� �� �� ����
        if (nextFib == num) 
            fib_cnt++;

        // 2. list ����
        for (int i = 1; i <= fib_cnt; i++)
            list.push_back(num - Fibonacci[i]);

        // 3. lack_of ����
        lack_of = makeLack_of(list);

        // 4. lack_of ���� üũ
        while (1) {
            if (needRebuildingList(lack_of, list)) { //list�� ġȯ�ؾ� �ϴ°��
                list = rebuildingList(list); //list ġȯ
                lack_of = makeLack_of(list);

            }
            else { //�׷���� ��� ��������
                break;
            }
        }

        // 5. ������
        //printf("%d >> grundy:%d, fib����:%d, nextFib:%d \n", num, grundy[num], fib_cnt, nextFib);
        //printf("\n====================================\n");
        //printf("%d >> %d , %d\n", num, grundy[num], fib_cnt);
        list.clear(); lack_of.clear(); num++;
        if (num > from) break;
    }
}

//list�� ġȯ�ؾ��ϴ��� Ȯ��. lack_of�� ���Ұ����� ��������..
bool needRebuildingList(vector<int> lack_of, vector<int> list) {
    switch (lack_of.size()) {
    case 0:
        grundy.push_back(list.size()); //���տ� ���� �ٷδ������� �׷����
        return false;
    case 1:
        grundy.push_back(lack_of[0]); 
        return false;
    default:
        return true;
    }
}

//list�� ���¿�ҵ�� lack_of�� ����
vector<int> makeLack_of(vector<int> list) {
    sort(list.begin(), list.begin() + list.size()); //����
    int max = list[list.size() - 1]; //list ���� �ִ�ũ���� ����
    vector<int> lack_of;
    for (int k = 0; k <= max; k++) { //����Ʈ���� ���Ұ� ����
        bool find = false;
        for (int i = 0; i < list.size(); i++) { //����Ʈ ��ȸ
            if (k == list[i]) {
                find = true; //ã����
                break;
            }
        }
        if (!find) //��ã����� �ش� ���� k�� lack_of�� �߰�
            lack_of.push_back(k);
    }
    //printf("\nlack_of ���� , ũ��:%d>> ", lack_of.size());
    //for (int i = 0; i < lack_of.size(); i++)
    //    printf("{%d}  ", lack_of[i]);
    //printf("\n");
    return lack_of;
}

//list�� ��� ���Ҹ� ġȯ
vector<int> rebuildingList(vector<int> list) {
    vector<int> newList;
    //���� lack_of�� �����Ҹ� �׷������� ġȯ�Ͽ� ���ο� list�� ����
    //printf("list >> ");
    //for (int i = 0; i < list.size(); i++)
    //    printf("%d  ", list[i]);

    for (int i = 0; i < list.size(); i++) {
        int value = grundy[list[i]];
        bool find = false;
        for (int i = 0; i < newList.size(); i++)
            if (newList[i] == value) find = true;
        if (!find)
            newList.push_back(value); //�ߺ����� ���� ����
    }

    //printf("\nlist ġȯ >> ");
    //for (int i = 0; i < newList.size(); i++)
    //    printf("{%d}  ", newList[i]);
    //printf("\n");
    return newList;
}


void func() {
    g != 0 ? printf("koosaga") : printf("cubelover");

    vector<int> a;

    a.assign(3000, false);
}


int main(void) {
    init();
    func();

    return 0;
}