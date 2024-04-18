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
//#define sz(x) ((int)x.size()) //컨테이너에서 사용
//#define ms(a) memset(a, 0, sizeof(a)) //0으로 초기화
//#define rep(i, n) for(int i = 0; i < n ; i++)
//#define rrep(i, r, n) for(int i = r; i < n ; i++)
//#define rrrep(i, r, n) for(ll i = r; i < n ; i++)
//#define _rrep(i, r, n) for(int i = r; i >= n; i--)
//#define _rrrep(i, r, n) for(ll i = r; i >= n; i--)
//#define each(x, a) for (auto& x: a)
//#define all(x) x.begin(),x.end() //STL에서 전체 처리할때 사용
//#define range(x, r, n) x.begin() + r, x.begin() + n //STL에서 구간설정
//#define ct continue
//#define br break
//#define rt return
//#define _TYF typedef //코드줄이기
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
//_TCE T sq(T num) { rt num* num; }//제곱함수
//_TCE T GCD(T num1, T num2) { if (num2 == 0) rt num1; rt GCD(num2, num1 % num2); }
//_TCE T LCM(T num1, T num2) { if (num1 == 0 || num2 == 0) rt num1 + num2; rt num1* (num2 / GCD(num1, num2)); }
////STL 전용 초기화 함수들 ( ms~~ )
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
//vii door[27]; //대문자에 해당하는 각 문의 위치
//int map[100][100]; //-1 ~ -26:소문자, 0:빈공간, 1 ~ 26:대문자, 100:벽, 1000:문서
//bool visited[100][100];
//
////DEBUG
//int DEBUG[100][100]; 
//
//int dxy[][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
//void func();
//
////X, Y에서 탐색을 진행해서 훔칠 수 있는 문서의 최댓값 리턴
//int bfs(int X, int Y) {
//	//1.시작위치 X, Y에 대한 설정들
//	//1-1. 시작위치가 벽이면 탐색불가
//	if (map[X][Y] == 100) rt 0; 
//
//	//1-2. 시작위치에 문이있으면 열쇠가 있어야 탐색가능
//	if (1 <= map[X][Y] && map[X][Y] <= 26) { 
//		bool existKey = false;
//		rep(i, len(keys))
//			if (keys[i] - 'a' + 1 == map[X][Y]) existKey = true;
//		if (!existKey) rt 0; //열쇠가없으면 탐색불가
//	}
//	qiii loc; //현재위치 찾은문서갯수 기록
//	qs key; //현재위치에서 갖고있는 열쇠 종류들
//	loc.ph(mt(X, Y, 0)); //출발좌표
//	key.ph(keys); //시작 열쇠 저장
//
//	//1-3. 시작위치에 열쇠가있으면 줍고시작
//	if (-26 <= map[X][Y] && map[X][Y] <= -1) { 
//		//key에 추가전 중복검사
//		bool exist = false;
//		char keyChar = -map[X][Y] + 96;
//		rep(i, len(keys)) //
//			if (keys[i] == keyChar) exist = true;
//		//key에 추가
//		if (!exist) {
//			string K = key.FF(); //key에서 꺼낸다.
//			key.PP(); //key에서 제거
//			K.pb(keyChar); //꺼낸값에 새로주운키를 더하고
//			key.ph(K); //key에 새롭게 저장
//		}
//	}
//
//	//1-4. 시작위치에 문서가 있다면 훔치고 시작
//	if (map[X][Y] == 1000) {
//		int x, y, c;
//		tie(x, y, c) = loc.FF();
//		loc.PP();
//		loc.ph(mt(x, y, c + 1));
//	}
//
//	int res = 0; //훔칠 수 있는 문서의 최댓값
//	rep(i, h)
//		rep(j, w)
//			visited[i][j] = false; //방문배열 초기화
//	visited[X][Y] = true; //시작위치 방문체크
//
//	//2. BFS탐색
//	while (!loc.emp()) {
//		int x, y, c;
//		tie(x, y, c) = loc.FF();
//		string k = key.FF();
//		loc.PP();
//		key.PP();
//
//		//pr("(%d, %d)\n", x, y); //DEBUG
//		//0. 훔칠 수 있는 문서의 최댓값 기록
//		res < c ? res = c : res; 
//
//		//map[][] ::  -1 ~ -26:소문자, 0:빈공간, 1 ~ 26:대문자, 100:벽, 1000:문서
//		//다음 위치로가능한 상하좌우방향으로 탐색을 진행
//		rep(dir, 4) { 
//			int xx = x + dxy[dir][0];
//			int yy = y + dxy[dir][1];
//			int cc = c;
//			string kk = k;
//
//			//1. 범위를 벗어나면 제외
//			if (xx < 0 || yy < 0 || xx == h || yy == w) { 
//				//pr("1 >> (%d, %d)\n", xx, yy); //DEBUG
//				ct; 
//			}
//
//			//2. 방문했으면 제외
//			if (visited[xx][yy]) {
//				//pr("2 >> (%d, %d)\n", xx, yy); //DEBUG
//				ct;
//			}
//			visited[xx][yy] = true; 
//
//			//3. 벽이면 제외
//			if (map[xx][yy] == 100) {
//				//pr("3 >> (%d, %d)\n", xx, yy); //DEBUG
//				ct;
//			}
//
//			//4.문을 찾은 경우
//			bool end = false;
//			if (1 <= map[xx][yy] && map[xx][yy] <= 26) { 
//				bool existKey = false;
//				//pr("4 >> (%d, %d)\n", xx, yy); //DEBUG
//				//pr("%s ::", kk.tc()); //DEBUG
//				rep(i, len(kk)) {
//					//pr("%d ", kk[i] - 'a' + 1); //DEBUG
//					if (kk[i] - 'a' + 1 == map[xx][yy]) existKey = true; //문에맞는 열쇠를 보유했을경우
//				}
//				//pr("\n"); //DEBUG
//				if (!existKey) end = true;
//			} 
//			//4-1. 문에맞는 열쇠를 가지고 있지 않으면 제외
//			if (end) {
//				//pr("4-1 >> (%d, %d)\n", xx, yy); //DEBUG
//				ct;
//			}
//
//			//5.열쇠를 찾은경우
//			if (-26 <= map[xx][yy] && map[xx][yy] <= -1) { 
//				//pr("5 >>\n");//DEBUG
//				//5-1. 새로운 열쇠인지 확인 : 열쇠는 중복없이 KK에 기록되어야한다.
//				bool exist = false;
//				int doorNum = -map[xx][yy]; //열쇠에 해당하는 문번호
//				char keyChar = doorNum + 96; //열쇠를 소문자로 치환
//				rep(i, len(kk))
//					if (kk[i] == keyChar) exist = true;
//
//				//5-2. 새로운 열쇠를 주운경우
//				if (!exist) {
//					kk.pb(keyChar); //중복없이 kk에 찾은 열쇠(소문자) 기록
//					 
//					//주운열쇠에 맞는 문의 좌표를 모두 큐에 담음
//					//열쇠를가지고 다시 돌아가서 맞는 문좌표로 이동하여 탐색을 진행하는 원리
//					//여기서 순간이동하듯 큐에 문좌표를 바로 담아도되는 이유는
//					//1. 만약 문이 벽에 둘러쌓여있다면 어찌저찌 문이있는곳으로 
//					//	 이동한후에 주변으로의 탐색이 불가능(벽으로는 이동불가)하므로 여기서 끝난다.
//					//2. 주변이모두 이동가능한 곳이었다면 그 문으로 굳이 이동하든안하든
//					//	 결과는 같고 이전에 방문체크visited가 되었다면 재탐색을안한다.
//					//이런 이유들로 순간이동하듯 큐에 위치를 담아도 논리상 문제없음.
//					rep(i, sz(door[doorNum])) {
//						int doorX, doorY; //열쇠로 열수 있는 문의 위치를 가져옴
//						tie(doorX, doorY) = door[doorNum][i]; 
//						if (visited[doorX][doorY]) ct;
//						visited[doorX][doorY] = true; //이미 방문했다면제외(열쇠는 복수개가 있을 수 있다.)
//						
//						loc.ph(mt(doorX, doorY, cc)); //문 좌표
//						key.ph(kk);
//					}
//					//새로운 열쇠를 주운뒤에도 다음탐색은 이어져야하니 여기서 continue를 하지 않는다.
//					//즉 열쇠로 열수있는 모든문의 좌표와 {xx, yy} 모두 큐에 담아야함.
//				}
//			}
//
//			//6. 문서를 찾음
//			if (map[xx][yy] == 1000) cc++; 
//
//			//7. 상하좌우 이동가능한 위치면 큐에 담아서 탐색을 이어서 진행
//			loc.ph(mt(xx, yy, cc));
//			key.ph(kk);
//		}
//	}
//
//	//DEBUG////////////
//	DEBUG[X][Y] = res; 
//	pr("가능 >> %d, %d\n", X, Y);
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
//		//입력
//		sc("%d%d", &h, &w);
//		char c;
//		sc("%c", &c); //줄바꿈문자 제거
//		rep(i, h) {
//			rep(j, w) {
//				sc("%c", &c);
//				if (c == '*')
//					map[i][j] = 100; //벽
//				else if (c == '.')
//					map[i][j] = 0; //빈공간
//				else if(c == '$') 
//					map[i][j] = 1000; //문서
//				else if (97 <= c && c <= 122) 
//					map[i][j] = - (c - 'a' + 1); //열쇠 : -1 ~ -26
//				else if (65 <= c && c <= 90) { 
//					int num = c - 'A' + 1; //문 : 1 ~ 26
//					map[i][j] = num; 
//					door[num].pb(mp(i, j)); //문 위치 기록
//				}
//
//			}
//			sc("%c", &c); //줄바꿈문자 제거
//		}
//
//		//DEBUG///////////////////////////////
//		DD(); //입력받은 맵을 살펴보자
//		//////////////////////////////////////
//
//		keys.cls(); //처음주어지는 키 초기화
//		char k[27] = {'\0'}; //만약오류나면 제거
//		sc("%[^\n]s", k);
//		if(k[0] != '0') //처음주어지는 키가 있을때만..
//			keys = k;
//
//		//지도의 가능한 모든 가장자리로부터 bfs진행하여 문서 최대갯수를 찾음
//		int max = 0;
//		rep(j, w) {
//			int cnt = bfs(0, j); //윗벽탐색
//			max < cnt ? max = cnt : max; //최댓값이면 갱신
//
//			if (h - 1 == 0) ct; //시간효율성
//			cnt = bfs(h - 1, j); //아랫벽 탐색
//			max < cnt ? max = cnt : max;
//		}
//		rrep(i, 1, h - 1) {
//			int cnt = bfs(i, 0); //왼쪽벽탐색
//			max < cnt ? max = cnt : max;
//
//			if (w - 1 == 0) ct;
//			cnt = bfs(i, w - 1); //오른벽탐색
//			max < cnt ? max = cnt : max;
//		}
//		
//		//DEBUG////////////////////////////////////////
//		rep(i, h)
//			rep(j, w)
//				DEBUG[i][j] = 0; //DEBUG 초기화
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
//		pr("%d\n", max); //훔칠 수 있는 문서의 최댓값 출력
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