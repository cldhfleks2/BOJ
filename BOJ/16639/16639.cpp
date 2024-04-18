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
vector<string> Log;
ll max = INT32_MIN; //����� �ִ�

void func();
void picked(vector<int>& n, vector<int>& o, vector<int>& index, vector<pair<vector<int>, vector<int>>>& list);
void debug(int n, vector<int>& a, vector<int>& b, ll r);
string makeLog(vector<int>& a, vector<int>& b);
bool exist(string s);
ll polynomialCalculate(vector<int>& NUM, vector<int>& OP);
ll calculate(vector<int>& n, vector<int>& o, vector<int>& opIndex, vector<pair<vector<int>, vector<int>>>& list);
int monomialCalculate(int left, int right, int OP);
void init();

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
ll calculate(vector<int>& n, vector<int>& o, vector<int>& opIndex,
    vector<pair<vector<int>, vector<int>>>& list) {
    vector<int> NUM, OP;
    //1-1. ��ȣ���� ������ ���� ���
    //left, right : ��ȣ�� �� ����. �����ȣ�� �������� ��,�� �� ����
    bool prevBrace = false;
    //��ü �����ȣ Ž��
    for (int i = 0; i < o.size(); i++) {
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
            int left{ n[i] }, right{ n[i + 1] }; //�� ����
            NUM.push_back(monomialCalculate(left, right, o[i])); //��ȣ�� ����ؼ� NUM�� �߰�
            prevBrace = true;
        }
        else { //��ȣ�� �����ȣ ���
            if (prevBrace) { //�ٷ������� ��ȣ�� ��� �߾��ٸ�
                //NUM�� num[i]�����߰�X,  OP�� �����ȣ�߰�O
                OP.push_back(o[i]);
                prevBrace = false; //üũ ����
            }
            else {
                //NUM�� num[i]�����߰�O,  OP�� �����ȣ�߰�O
                NUM.push_back(n[i]);
                OP.push_back(o[i]);
            }
        }

        //�������ε����̰� ��ȣ�� �ƴϸ� ������ ���ڸ� NUM�� �߰��������
        if (i == o.size() - 1 && !findIndex)
            NUM.push_back(n[o.size()]);
    }
    //debug(22, NUM, OP, polynomialCalculate(NUM, OP));

    //������ ��������� �ִ� �����̸� ����
    string s = makeLog(NUM, OP);
    if (exist(s))
        return INT32_MIN;
    else { //�ƴϸ� ���
        Log.push_back(s);
        //������� NUM�� OP������ ���̽��� �̾ ��ȣ�� �߰��غ���.
        if (OP.size() != 1)
            list.push_back({ NUM, OP });
    }
    
    //2. ��ȣ�� Ǭ ������ ����ؼ� ����
    ll res = polynomialCalculate(NUM, OP);

    return res;
}

bool exist(string s) {
    for (int i = 0; i < Log.size(); i++)
        if (s.compare(Log[i]) == 0)
            return true;
    return false;
}

//��ü ������ ����Ͽ� ����
//���ϱ⸦ ��������Ѵ�.
ll polynomialCalculate(vector<int>& NUM, vector<int>& OP) {
    //vector<int> A, B;
    //����
    //for (int i = 0; i < NUM.size(); i++) A.push_back(NUM[i]);
    //for (int i = 0; i < OP.size(); i++) B.push_back(OP[i]);
    ////1-2.
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

    //ll res = A[0];
    //for (int i = 1; i < A.size(); i++)
    //    res = monomialCalculate(res, A[i], B[i - 1]);
    //return res;

    ll res = NUM[0];
    for (int i = 1; i < NUM.size(); i++)
        res = monomialCalculate(res, NUM[i], OP[i - 1]);
    return res;
}

string makeLog(vector<int>& a, vector<int>& b) {
    string s;
    for (int i = 0; i < a.size(); i++)
        s += a[i] + " ";
    for (int i = 0; i < b.size(); i++)
        s += b[i] + " ";

    return s;
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
void picked(vector<int> &n, vector<int> &o, vector<int>& index, 
    vector<pair<vector<int>, vector<int>>> &list) {
    if (n.size() == 1 || o.size() == 0) return; //��ȣ�� ������ĥ�� ��������

    //1. 2���̻� �����ȣ�� pick�Ҷ� �� �����ȣ�� ���� �����ϸ� �ȵ�.
    bool pass = false;
    if (index.size() >= 2) {
        //������ �ΰ��� �����ȣ�� ���� �������� Ȯ��
        for (int i = 0; i < index.size(); i++) {
            int prevIndex = index[i];
            for (int j = i + 1; j < index.size(); j++) {
                int nextIndex = index[j];
                if (nextIndex - prevIndex == 1) { //���� �����ϴٸ�
                    pass = true;
                    break;
                }
            }
        }
    }
    if (pass) return; //���� ������ �����ȣ�� ����ϴ� ���� ����

    //2. ������� ���� ���۷����͸�ŭ ����� ���
    if (!index.empty()) {
        ll res = calculate(n, o, index, list);
        if (max < res) max = res;
    }

    //if (!index.empty()) { //��ȣ�� �߰������ʰ� ����ϴ°��� �Ʒ� func()���� �̸� �صξ���
    //    ll res = calculate(n, o, index, list);
    //    if (max < res) max = res;
    //}
    //3. OP�� �����ȣ�� ���� �����ϴ� ����Ǽ��� ��� ������� ����
    int smallest = index.empty() ? 0 : index.back() + 1; //index���� �ε����� �ٷ� ���� �ε���
    for (int i = smallest; i < op.size(); i++) {
        index.push_back(i);
        picked(n, o, index, list);
        index.pop_back();
    }
}

void func() {
    //�ϳ��� �����ȣ�� pick�ϴ°��� ��ȣ�� ����°�.
    //�ٸ�, ���� ������ �����ȣ�� �����Ѵٸ� ��ȣ�� ������ ������ ����.
    //���� ������������ �����ȣ�� pick �ؾ��Ѵ�.
    //pick �ѵ� ���� ��츶���� �ִ��� ���غ���.
    vector<pair<vector<int>, vector<int>>> list;
    list.push_back({ num, op });

    int de = -1;
    while (!list.empty()) {
        de++;
        //printf("%d========================\n", de);
        vector<int> index, n, o;
        n = list.back().first;
        o = list.back().second;
        list.pop_back();
        //��ȣ�� �߰����� ����ä�� ���
        ll res = polynomialCalculate(n, o);
        if (max < res) max = res;
        string s = makeLog(n, o);
        Log.push_back(s);
        //if (!exist(s)) { 
        //    ll res = polynomialCalculate(n, o); 
        //    if (max < res) max = res;
        //    Log.push_back(s);
        //}
        //else {
        //    continue;
        //}

        //��ȣ�� �߰��ؼ� ���
        picked(n, o, index, list);
    }

    printf("%lld", max); //���� �ִ�
}

int main(void) {
    init();
    func();

    return 0;
}