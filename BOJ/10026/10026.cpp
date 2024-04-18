#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
using std::pair; using std::queue;
typedef pair<int, int> pii;
int n, R=0, G=0, B=0, RG=0;
char** picture, **check;
bool** visited;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
queue<pii> loc;

void func();
void init();
void clear();
bool checkColor(char c1, char c2, char**& check);
pii findColor(char c1, char c2, char**& check);
void pastePicture();

void func() {
	pastePicture();
	while (checkColor('R', 'R', check)) R++;
	while (checkColor('G', 'G', check)) G++;
	while (checkColor('B', 'B', check)) B++;
	pastePicture();
	while (checkColor('R', 'G', check)) RG++;
	printf("%d %d", R + G + B, RG + B);
}

void clear() {
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) visited[i][j] = false;
}

void pastePicture() {
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) check[i][j] = picture[i][j];
}

//해당 색상을 하나 찾아서 BFS를 진행하여 같은 색상만 지워간다.
//만약 해당 색상이 남아있지않으면 false 리턴
bool checkColor(char c1, char c2, char**&check) {
	clear();
	pii p = findColor(c1, c2, check);
	int start_x = p.first;
	int start_y = p.second;
	if (start_x == -1 && start_y == -1) return false;
	loc.push({ start_x, start_y });
	check[start_x][start_y] = 'X';
	visited[start_x][start_y] = true;

	while (!loc.empty()) {
		int x = loc.front().first;
		int y = loc.front().second;
		loc.pop();

		for (int dir = 0; dir < 4; dir++) {
			int xx = x + dx[dir];
			int yy = y + dy[dir];

			if (xx < 0 || yy < 0 || xx == n || yy == n) continue; //올바르지않은범위이면 제외
			if (check[xx][yy] != c1 && check[xx][yy] != c2) continue; //다른색이면 제외
			if (!visited[xx][yy]) {
				visited[xx][yy] = true;
				check[xx][yy] = 'X'; //찾았음을 체크

				loc.push({ xx, yy });
			}
		}
	}
	return true;
}

pii findColor(char c1, char c2, char**&check) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (check[i][j] == c1 || check[i][j] == c2)
				return { i, j };
	return { -1, -1 };
}

void init() {
	scanf("%d", &n);
	picture = new char* [n];
	visited = new bool* [n];
	check = new char* [n];
	for (int i = 0; i < n; i++) {
		picture[i] = new char[n];
		visited[i] = new bool[n] ;
		check[i] = new char[n];
		char _;
		scanf("%c", &_);
		for (int j = 0; j < n; j++) {
			scanf("%c", &picture[i][j]);
		}
	}
}

int main() {
	init();
	func();

	return 0;
}