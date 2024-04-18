#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
using std::vector; using std::stack; using std::queue; using std::deque; using std::tuple;
using std::string; using std::pair; using std::make_tuple; using std::tie;
using std::sort; using std::swap;
using std::make_pair; using std::max_element; using std::min_element; using std::bitset; using std::to_string;
using std::fill; using std::priority_queue; using std::greater;
//using std::max; using std::min; using std::map;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, int> pdi;
typedef pair<int, double> pid;
typedef pair<double, double> pdd;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;
typedef pair<int, char> pic;
typedef pair<char, int> pci;
typedef pair<string, int> psi;
typedef pair<int, string> pis;
typedef pair<string, string> pss;

int N;
vector<int> num; //0~9
vector<int> op; //1:+  2:-  3:*
ll max = INT32_MIN; //����� �ִ�
void init();
int monomialCalculate(int left, int right, int OP);
ll calculate(vector<int>& index);
ll polynomialCalculate(vector<int>& newNUM, vector<int>& newOP);
void debug(int n, vector<int>& a, vector<int>& b, ll r); //��Ȯ�ο�
void picked(vector<int>& index);
void func();
void init() {
    scanf("%d", &N);
    char o;
    scanf("%c", &o); //�ٹٲ޹��� ����
    for (int i = 0; i < N; i++) {
        char o;
        scanf("%c", &o);
        if (i % 2) //��ȣ
            if (o == '+')
                op.push_back(1);
            else if (o == '-')
                op.push_back(2);
            else
                op.push_back(3);
        else //����
            num.push_back(o - '0');
    }
}

//�� ���ڸ� OP�����ȣ(���ڷ� ��ü)�� ����Ѱ� ����
int monomialCalculate(int left, int right, int OP) {
    if (OP == 1) //+
        return left + right;
    else if (OP == 2) //-
        return left - right;
    else if (OP == 3) //*
        return left * right;
}

//��ȣ�� Ǯ�� ��ü���� �����帧�� ����
ll calculate(vector<int>& opIndex) {
    vector<int> NUM, OP;
    //1-1. ��ȣ���� ������ ���� ���
    //left, right : ��ȣ�� �� ����. �����ȣ�� �������� ��,�� �� ����
    bool prevBrace = false;
    //��ü �����ȣ Ž��
    for (int i = 0; i < op.size(); i++) {
        bool findIndex = false;
        //�� �� ������ �����ȣ�� Ž��
        for (int j = 0; j < opIndex.size(); j++) {
            if (i == opIndex[j]) { //��ȣ�� �����ȣ����.
                findIndex = true;
                break;
            }
        }

        //��ȣ�� �����ȣ ���
        if (findIndex) {
            //NUM�� ��ȣ���� ����Ѽ����߰�,  OP�� �����ȣ�߰�X
            int left{ num[i] }, right{ num[i + 1] }; //�� ����
            //printf("1>> left:%d right:%d\n", left, right);
            NUM.push_back(monomialCalculate(left, right, op[i])); //��ȣ�� ����ؼ� NUM�� �߰�
            prevBrace = true;
        }
        else { //��ȣ�� �����ȣ ���
            if (prevBrace) { //�ٷ������� ��ȣ�� ��� �߾��ٸ�
                //NUM�� num[i]�����߰�X,  OP�� �����ȣ�߰�O
                OP.push_back(op[i]);
                prevBrace = false; //üũ ����
            }
            else {
                //NUM�� num[i]�����߰�O,  OP�� �����ȣ�߰�O
                NUM.push_back(num[i]);
                OP.push_back(op[i]);
            }
        }

        //�������ε����̰� ��ȣ�� �ƴϸ� ������ ���ڸ� NUM�� �߰��������
        if (i == op.size() - 1 && !findIndex)
            NUM.push_back(num[op.size()]);
    }
    //debug(22, NUM, OP, polynomialCalculate(NUM, OP));

    //2. ��ȣ�� Ǭ ������ ����ؼ� ����
    ll res = polynomialCalculate(NUM, OP);

    return res;
}

//��ü ������ ����Ͽ� ����
//���ϱ⸦ ��������Ѵ�.
ll polynomialCalculate(vector<int>& NUM, vector<int>& OP) {
    vector<int> A, B;
    //����
    for (int i = 0; i < NUM.size(); i++) A.push_back(NUM[i]);
    for (int i = 0; i < OP.size(); i++) B.push_back(OP[i]);
    //1-2.
    //while (1) { //���ϱ� ��ȣ�� �߰����� ���Ҷ� ���� �ݺ�
    //    bool findMultiple = false;
    //    for (int i = 0; i < B.size(); i++) {
    //        //1-3.
    //        if (B[i] == 3) {
    //            findMultiple = true;
    //            int left{ A[i] }, right{ A[i + 1] };
    //            //printf("3>> left:%d right:%d\n", left, right);
    //            //1-4.
    //            //left��ġ�� left,right���� ����� ������
    //            //right����(A[i + 1])�� ����
    //            //B[i] �� ����
    //            A[i] = monomialCalculate(left, right, 3); //���ϱ� �������
    //            A.erase(A.begin() + i + 1); //right���� ����
    //            B.erase(B.begin() + i); //�������ȣ ����
    //        }
    //    }
    //    //1-5.
    //    if (!findMultiple)
    //        break;
    //}

    ll res = A[0];
    for (int i = 1; i < A.size(); i++)
        res = monomialCalculate(res, A[i], B[i - 1]);
    return res;
}

//�� ������ ������ ��� - Ȯ�ο�
void debug(int n, vector<int>& a, vector<int>& b, ll r) {
    printf("%d>> ", n);
    bool A = true, B = true;
    int idxA = 0, idxB = 0;
    int lenA = a.size(), lenB = b.size();

    while (1) {
        if (A)
            printf("%d ", a[idxA]);
        if (B)
            if (b[idxB] == 1)
                printf("+ ");
            else if (b[idxB] == 2)
                printf("- ");
            else if (b[idxB] == 3)
                printf("* ");
        idxA++;
        idxB++;
        if (idxA == lenA) A = false;
        if (idxB == lenB) B = false;
        if (!A && !B) break;
    }

    printf("= %lld\n", r);
}

//��ȣ�� �߰��ؼ� ������ ����غ���.
//���� ���������ʵ��� �����ȣ�� ����(��ȣ�� �߰��ϴ°�)�ϴ� ��� ����Ǽ�����
//���� ��츶���� ������� �ִ��� max�� ����
void picked(vector<int>& opIndex) {
    //1. 2���̻� �����ȣ�� pick�Ҷ� �� �����ȣ�� ���� �����ϸ� �ȵ�.
    bool pass = false;
    if (opIndex.size() >= 2) {
        //������ �ΰ��� �����ȣ�� ���� �������� Ȯ��
        for (int i = 0; i < opIndex.size(); i++) {
            int prevIndex = opIndex[i];
            for (int j = i + 1; j < opIndex.size(); j++) {
                int nextIndex = opIndex[j];
                if (nextIndex - prevIndex == 1) { //���� �����ϴٸ�
                    pass = true;
                    break;
                }
            }
        }
    }
    if (pass) return; //���� ������ �����ȣ�� ����ϴ� ���� ����

    //2. ������� ���� ���۷����͸�ŭ ����� ���
    if (!opIndex.empty()) { //��ȣ�� �߰������ʰ� ����ϴ°��� �Ʒ� func()���� �̸� �صξ���
        ll res = calculate(opIndex);
        if (max < res) max = res;
    }

    //3. OP�� �����ȣ�� ���� �����ϴ� ����Ǽ��� ��� ������� ����
    int smallest = opIndex.empty() ? 0 : opIndex.back() + 1; //index���� �ε����� �ٷ� ���� �ε���
    for (int i = smallest; i < op.size(); i++) {
        opIndex.push_back(i);
        picked(opIndex);
        opIndex.pop_back();
    }
}

void func() {
    //�ϳ��� �����ȣ�� pick�ϴ°��� ��ȣ�� ����°�.
    //�ٸ�, ���� ������ �����ȣ�� �����Ѵٸ� ��ȣ�� ������ ������ ����.
    //���� ������������ �����ȣ�� pick �ؾ��Ѵ�.
    //pick �ѵ� ���� ��츶���� �ִ��� ���غ���.
    vector<int> opIndex;
    ll res = polynomialCalculate(num, op); //��ȣ�� �߰������ʰ� ����ϴ°��
    if (max < res) max = res;

    picked(opIndex); //��ȣ�� �߰��ؼ� ����ϴ� ���

    printf("%lld", max); //���� �ִ�
}

int main(void) {
    init();
    func();

    return 0;
}