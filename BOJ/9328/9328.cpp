//#define _CRT_SECURE_NO_WARNINGS 
//#include <bits/stdc++.h>
//#define mp std::make_pair 
//#define mt std::make_tuple
//#define dq std::deque
//#define pq std::priority_queue
//#define sw std::swap
//#define ts(x) std::to_string(x)
//#define tc() c_str()
//#define sc(x, ...) scanf(x, ##__VA_ARGS__) 
//#define pr(x, ...) printf(x, ##__VA_ARGS__) 
//#define ins(x) insert(x)
//#define pb(x) push_back(x)
//#define pf(x) push_front(x)
//#define PB() pop_back()
//#define PF() pop_front()
//#define ph(x) push(x)
//#define TT() top()
//#define PP() pop()
//#define BB() back()
//#define FF() front()
//#define cls() clear()
//#define emp() empty()
//#define len(x) x.length()
//#define sz(x) ((int)x.size()) //�����̳ʿ��� ���
//#define ms(a) memset(a, 0, sizeof(a)) //0���� �ʱ�ȭ
//#define rep(i, n) for(int i = 0; i < n ; i++)
//#define rrep(i, r, n) for(int i = r; i < n ; i++)
//#define rrrep(i, r, n) for(ll i = r; i < n ; i++)
//#define _rrep(i, r, n) for(int i = r; i >= n; i--)
//#define _rrrep(i, r, n) for(ll i = r; i >= n; i--)
//#define each(x, a) for (auto& x: a)
//#define all(x) x.begin(),x.end() //STL���� ��ü ó���Ҷ� ���
//#define range(x, r, n) x.begin() + r, x.begin() + n //STL���� ��������
//#define ct continue
//#define br break
//#define rt return
//#define _TYF typedef //�ڵ����̱�
//#define _UG using
//#define _TCE template <class T> inline
////#define MAX 
//const int IMAX = INT32_MAX; const int IMIN = INT32_MIN;
//const long long LMAX = LLONG_MAX; const long long LMIN = LLONG_MIN;
//const long double PI = 3.141592653589793238462643383279502884197;
//_UG std::vector; _UG std::stack; _UG std::queue; _UG std::tuple; _UG std::set; _UG std::list; _UG std::bitset; _UG std::string; _UG std::pair; _UG std::greater;
//_UG std::tie; _UG std::sort; _UG std::max_element; _UG std::min_element; _UG std::fill; _UG std::stoi; _UG std::stod; _UG std::stof; _UG std::stol; _UG std::stold; _UG std::stoll; _UG std::stoul; _UG std::stoull;
////_UG std::max; //_UG std::min; //_UG std::map;
//_TYF long long ll; _TYF unsigned long long ull;
//_TYF pair<int, int> pii; _TYF pair<double, int> pdi; _TYF pair<int, double> pid; _TYF pair<double, double> pdd; _TYF pair<int, ll> pil;
//_TYF pair<ll, int> pli; _TYF pair<ll, ll> pll; _TYF pair<ull, ull> pullull; _TYF pair<int, char> pic; _TYF pair<char, int> pci;
//_TYF pair<char, char> pcc; _TYF pair<long, char> plc; _TYF pair<char, long> pcl; _TYF pair<ll, char> pllc; _TYF pair<char, ll> pcll;
//_TYF pair<ull, char> pullc; _TYF pair<char, ull> pcull; _TYF pair<int, string> pis; _TYF pair<string, int> psi; _TYF pair<long, string> pls;
//_TYF pair<string, long> psl; _TYF pair<ll, string> plls; _TYF pair<string, ll> psll; _TYF pair<ull, string> pulls;
//_TYF pair<string, ull> psull; _TYF pair<string, string> pss;
//_TYF tuple<int, int, int> tiii; _TYF tuple<int, int, int, int> tiiii;
//_TYF tuple<ll, ll, ll> tlll; _TYF tuple<ll, ll, ll, ll> tllll;
//_TYF vector<string> vs; _TYF queue<string> qs; _TYF stack<string> ss; _TYF dq<string> dqs; _TYF pq<string> pqs; _TYF dq<string> dqs;
//_TYF vector<char> vc; _TYF queue<char> qc; _TYF stack<char> sc; _TYF dq<char> dqc; _TYF pq<char> pqc; _TYF dq<char> dqc;
//_TYF vector<int> vi; _TYF queue<int> qi; _TYF stack<int> si; _TYF dq<int> dqi; _TYF pq<int> pqi; _TYF dq<int> dqi;
//_TYF vector<pii> vii; _TYF queue<pii> qii; _TYF stack<pii> sii; _TYF dq<pii> dqii; _TYF pq<pii> pqii; _TYF dq<pii> dqii;
//_TYF vector<tiii> viii; _TYF queue<tiii> qiii; _TYF stack<tiii> siii; _TYF dq<tiii> dqiii; _TYF pq<tiii> pqiii; _TYF dq<tiii> dqiii;
//_TYF vector<tiiii> viiii; _TYF queue<tiiii> qiiii; _TYF stack<tiiii> siiii; _TYF dq<tiiii> dqiiii; _TYF pq<tiiii> pqiiii; _TYF dq<tiiii> dqiiii;
//_TYF vector<pll> vll; _TYF queue<pll> qll; _TYF stack<ll> sll; _TYF dq<pll> dqll; _TYF pq<pll> pqll; _TYF dq<pll> dqll;
//_TYF vector<tlll> vlll; _TYF queue<tlll> qlll; _TYF stack<tlll> slll; _TYF dq<tlll> dqlll; _TYF pq<tlll> pqlll; _TYF dq<tlll> dqlll;
//_TYF vector<tllll> vllll; _TYF queue<tllll> qllll; _TYF stack<tllll> sllll; _TYF dq<tllll> dqllll; _TYF pq<tllll> pqllll; _TYF dq<tllll> dqllll;
//_TCE T sq(T num) { rt num* num; }//�����Լ�
//_TCE T GCD(T num1, T num2) { if (num2 == 0) rt num1; rt GCD(num2, num1 % num2); }
//_TCE T LCM(T num1, T num2) { if (num1 == 0 || num2 == 0) rt num1 + num2; rt num1* (num2 / GCD(num1, num2)); }
////STL ���� �ʱ�ȭ �Լ��� ( ms~~ )
//_TCE void msq(T& a) { while (!a.empty()) a.PP(); }//queue clear
//_TCE void msv(T& a) { a.cls(); }//vector clear
//_TCE void msdq(T& a) { a.cls(); }//deque clear
//_TCE void msm(T& a) { a.cls(); }//map clear
//_TCE void mss(T& a) { while (!a.empty()) a.PP(); }//stack, set clear
//_TCE void mspq(T& a) { while (!a.empty()) a.PP(); }//priority_queue clear
////pii operator - (pii a, pii b) { rt pii(a.first - b.first, a.second - b.second); }
////bool operator <= (pii a, pii b) { rt a.first <= b.first && a.second <= b.second; } 
////bool operator >= (pii a, pii b) { rt a.first >= b.first && a.second >= b.second; } 
////bool operator < (pii a, pii b) { if (a == b) return false; rt a <= b; } 
////bool operator > (pii a, pii b) { if (a == b) return false; rt a >= b; }
//
//int T;
//int h, w;
//string keys;
//vii door[27]; //�빮�ڿ� �ش��ϴ� �� ���� ��ġ
//int map[100][100]; //-1 ~ -26:�ҹ���, 0:�����, 1 ~ 26:�빮��, 100:��, 1000:����
//bool visited[100][100];
//
////DEBUG
//int DEBUG[100][100]; 
//
//int dxy[][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
//void func();
//
////X, Y���� Ž���� �����ؼ� ��ĥ �� �ִ� ������ �ִ� ����
//int bfs(int X, int Y) {
//	//1.������ġ X, Y�� ���� ������
//	//1-1. ������ġ�� ���̸� Ž���Ұ�
//	if (map[X][Y] == 100) rt 0; 
//
//	//1-2. ������ġ�� ���������� ���谡 �־�� Ž������
//	if (1 <= map[X][Y] && map[X][Y] <= 26) { 
//		bool existKey = false;
//		rep(i, len(keys))
//			if (keys[i] - 'a' + 1 == map[X][Y]) existKey = true;
//		if (!existKey) rt 0; //���谡������ Ž���Ұ�
//	}
//	qiii loc; //������ġ ã���������� ���
//	qs key; //������ġ���� �����ִ� ���� ������
//	loc.ph(mt(X, Y, 0)); //�����ǥ
//	key.ph(keys); //���� ���� ����
//
//	//1-3. ������ġ�� ���谡������ �ݰ����
//	if (-26 <= map[X][Y] && map[X][Y] <= -1) { 
//		//key�� �߰��� �ߺ��˻�
//		bool exist = false;
//		char keyChar = -map[X][Y] + 96;
//		rep(i, len(keys)) //
//			if (keys[i] == keyChar) exist = true;
//		//key�� �߰�
//		if (!exist) {
//			string K = key.FF(); //key���� ������.
//			key.PP(); //key���� ����
//			K.pb(keyChar); //�������� �����ֿ�Ű�� ���ϰ�
//			key.ph(K); //key�� ���Ӱ� ����
//		}
//	}
//
//	//1-4. ������ġ�� ������ �ִٸ� ��ġ�� ����
//	if (map[X][Y] == 1000) {
//		int x, y, c;
//		tie(x, y, c) = loc.FF();
//		loc.PP();
//		loc.ph(mt(x, y, c + 1));
//	}
//
//	int res = 0; //��ĥ �� �ִ� ������ �ִ�
//	rep(i, h)
//		rep(j, w)
//			visited[i][j] = false; //�湮�迭 �ʱ�ȭ
//	visited[X][Y] = true; //������ġ �湮üũ
//
//	//2. BFSŽ��
//	while (!loc.emp()) {
//		int x, y, c;
//		tie(x, y, c) = loc.FF();
//		string k = key.FF();
//		loc.PP();
//		key.PP();
//
//		//pr("(%d, %d)\n", x, y); //DEBUG
//		//0. ��ĥ �� �ִ� ������ �ִ� ���
//		res < c ? res = c : res; 
//
//		//map[][] ::  -1 ~ -26:�ҹ���, 0:�����, 1 ~ 26:�빮��, 100:��, 1000:����
//		//���� ��ġ�ΰ����� �����¿�������� Ž���� ����
//		rep(dir, 4) { 
//			int xx = x + dxy[dir][0];
//			int yy = y + dxy[dir][1];
//			int cc = c;
//			string kk = k;
//
//			//1. ������ ����� ����
//			if (xx < 0 || yy < 0 || xx == h || yy == w) { 
//				//pr("1 >> (%d, %d)\n", xx, yy); //DEBUG
//				ct; 
//			}
//
//			//2. �湮������ ����
//			if (visited[xx][yy]) {
//				//pr("2 >> (%d, %d)\n", xx, yy); //DEBUG
//				ct;
//			}
//			visited[xx][yy] = true; 
//
//			//3. ���̸� ����
//			if (map[xx][yy] == 100) {
//				//pr("3 >> (%d, %d)\n", xx, yy); //DEBUG
//				ct;
//			}
//
//			//4.���� ã�� ���
//			bool end = false;
//			if (1 <= map[xx][yy] && map[xx][yy] <= 26) { 
//				bool existKey = false;
//				//pr("4 >> (%d, %d)\n", xx, yy); //DEBUG
//				//pr("%s ::", kk.tc()); //DEBUG
//				rep(i, len(kk)) {
//					//pr("%d ", kk[i] - 'a' + 1); //DEBUG
//					if (kk[i] - 'a' + 1 == map[xx][yy]) existKey = true; //�����´� ���踦 �����������
//				}
//				//pr("\n"); //DEBUG
//				if (!existKey) end = true;
//			} 
//			//4-1. �����´� ���踦 ������ ���� ������ ����
//			if (end) {
//				//pr("4-1 >> (%d, %d)\n", xx, yy); //DEBUG
//				ct;
//			}
//
//			//5.���踦 ã�����
//			if (-26 <= map[xx][yy] && map[xx][yy] <= -1) { 
//				//pr("5 >>\n");//DEBUG
//				//5-1. ���ο� �������� Ȯ�� : ����� �ߺ����� KK�� ��ϵǾ���Ѵ�.
//				bool exist = false;
//				int doorNum = -map[xx][yy]; //���迡 �ش��ϴ� ����ȣ
//				char keyChar = doorNum + 96; //���踦 �ҹ��ڷ� ġȯ
//				rep(i, len(kk))
//					if (kk[i] == keyChar) exist = true;
//
//				//5-2. ���ο� ���踦 �ֿ���
//				if (!exist) {
//					kk.pb(keyChar); //�ߺ����� kk�� ã�� ����(�ҹ���) ���
//					 
//					//�ֿ�迡 �´� ���� ��ǥ�� ��� ť�� ����
//					//���踦������ �ٽ� ���ư��� �´� ����ǥ�� �̵��Ͽ� Ž���� �����ϴ� ����
//					//���⼭ �����̵��ϵ� ť�� ����ǥ�� �ٷ� ��Ƶ��Ǵ� ������
//					//1. ���� ���� ���� �ѷ��׿��ִٸ� �������� �����ִ°����� 
//					//	 �̵����Ŀ� �ֺ������� Ž���� �Ұ���(�����δ� �̵��Ұ�)�ϹǷ� ���⼭ ������.
//					//2. �ֺ��̸�� �̵������� ���̾��ٸ� �� ������ ���� �̵��ϵ���ϵ�
//					//	 ����� ���� ������ �湮üũvisited�� �Ǿ��ٸ� ��Ž�������Ѵ�.
//					//�̷� ������� �����̵��ϵ� ť�� ��ġ�� ��Ƶ� ���� ��������.
//					rep(i, sz(door[doorNum])) {
//						int doorX, doorY; //����� ���� �ִ� ���� ��ġ�� ������
//						tie(doorX, doorY) = door[doorNum][i]; 
//						if (visited[doorX][doorY]) ct;
//						visited[doorX][doorY] = true; //�̹� �湮�ߴٸ�����(����� �������� ���� �� �ִ�.)
//						
//						loc.ph(mt(doorX, doorY, cc)); //�� ��ǥ
//						key.ph(kk);
//					}
//					//���ο� ���踦 �ֿ�ڿ��� ����Ž���� �̾������ϴ� ���⼭ continue�� ���� �ʴ´�.
//					//�� ����� �����ִ� ��繮�� ��ǥ�� {xx, yy} ��� ť�� ��ƾ���.
//				}
//			}
//
//			//6. ������ ã��
//			if (map[xx][yy] == 1000) cc++; 
//
//			//7. �����¿� �̵������� ��ġ�� ť�� ��Ƽ� Ž���� �̾ ����
//			loc.ph(mt(xx, yy, cc));
//			key.ph(kk);
//		}
//	}
//
//	//DEBUG////////////
//	DEBUG[X][Y] = res; 
//	pr("���� >> %d, %d\n", X, Y);
//	///////////////////
//
//	rt res;
//}
//
//void DD() {
//	pr("MAP==================================\n");
//	rep(i, h) {
//		rep(j, w) {
//			pr("%4d ", map[i][j]);
//		}
//		if(i != h - 1) pr("\n\n\n\n");
//	}
//	pr("\n=====================================\n");
//}
//
//void func() {
//	sc("%d", &T);
//	while (T--) {
//		//�Է�
//		sc("%d%d", &h, &w);
//		char c;
//		sc("%c", &c); //�ٹٲ޹��� ����
//		rep(i, h) {
//			rep(j, w) {
//				sc("%c", &c);
//				if (c == '*')
//					map[i][j] = 100; //��
//				else if (c == '.')
//					map[i][j] = 0; //�����
//				else if(c == '$') 
//					map[i][j] = 1000; //����
//				else if (97 <= c && c <= 122) 
//					map[i][j] = - (c - 'a' + 1); //���� : -1 ~ -26
//				else if (65 <= c && c <= 90) { 
//					int num = c - 'A' + 1; //�� : 1 ~ 26
//					map[i][j] = num; 
//					door[num].pb(mp(i, j)); //�� ��ġ ���
//				}
//
//			}
//			sc("%c", &c); //�ٹٲ޹��� ����
//		}
//
//		//DEBUG///////////////////////////////
//		DD(); //�Է¹��� ���� ���캸��
//		//////////////////////////////////////
//
//		keys.cls(); //ó���־����� Ű �ʱ�ȭ
//		char k[27] = {'\0'}; //����������� ����
//		sc("%[^\n]s", k);
//		if(k[0] != '0') //ó���־����� Ű�� ��������..
//			keys = k;
//
//		//������ ������ ��� �����ڸ��κ��� bfs�����Ͽ� ���� �ִ밹���� ã��
//		int max = 0;
//		rep(j, w) {
//			int cnt = bfs(0, j); //����Ž��
//			max < cnt ? max = cnt : max; //�ִ��̸� ����
//
//			if (h - 1 == 0) ct; //�ð�ȿ����
//			cnt = bfs(h - 1, j); //�Ʒ��� Ž��
//			max < cnt ? max = cnt : max;
//		}
//		rrep(i, 1, h - 1) {
//			int cnt = bfs(i, 0); //���ʺ�Ž��
//			max < cnt ? max = cnt : max;
//
//			if (w - 1 == 0) ct;
//			cnt = bfs(i, w - 1); //������Ž��
//			max < cnt ? max = cnt : max;
//		}
//		
//		//DEBUG////////////////////////////////////////
//		rep(i, h)
//			rep(j, w)
//				DEBUG[i][j] = 0; //DEBUG �ʱ�ȭ
//		pr("DEBUG================================\n");
//		rep(i, h) {
//			rep(j, w) {
//				pr("%2d ", DEBUG[i][j]);
//			}
//			if(i != h-1) pr("\n\n");
//		}
//		pr("\n=====================================\n");
//		//////////////////////////////////////////////
//
//		pr("%d\n", max); //��ĥ �� �ִ� ������ �ִ� ���
//	}
//
//
//}
//
//int main(void) {
//	func();
//
//	rt 0;
//}