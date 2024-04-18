#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
#include <Windows.h>

int keyboard[27][27] = {0}; //[preKEY][KEY] 이전키에서 현재키까지 이동 비용. 동일위치는 모두 0인 상태
//각각 키사이 거리(최소단위 2)를 모두 기록할것임.

void input(); //입력을 받는 부분
void makeKeyboard(); //키보드의 모든 키값 설정
int findKEY(char c); //문자하나를 고유 키값으로 변환

//모든키값 사이 이동 비용을 계산하는 함수
void makeKeyboard() {
	//1 : 동일층의 모든 키값 
	for (int i = 1; i <= 3; i++) { //1, 2, 3층
		for (int j = 7 * i - 6 ; j <= 7 * i; j++) { //현재 키값 j
			for (int k = j; k <= 7 * i; k++) { //오른쪽방향의 키값 k
				if (j - k != 0) { //동일위치가 아닌것만 기록
					keyboard[j][k] = 2 * abs(k - j); //두키 사이거리(단위 2)기록
				}
			}

			for (int k = j; 7 * i - 6 <= k; k--) { //왼쪽방향 키값 k
				if (j - k != 0) { //동일위치가 아닌것만
					keyboard[j][k] = 2 * abs(k - j); //두키 사이거리(단위 2)기록
				}
			}
		}
	}

	//2 : 한층아래의 모든 키값
	// 1층 :  1~7
	// 2층 :  8~14
	// 3층 : 15~21
	for (int i = 1; i <= 3; i++) { //세개의 층을살핀다
		for (int j = 7 * i - 6; j <= 7 * i; j++) { //1~7  8~14  15~21
			if (i + 1 <= 3) { //유효한 아래층일때만
				//우하단
				for (int k = j + 7; k <= 7 * (i + 1); k++) {
					if (7 * i + 1 <= k && k <= 7 * (i + 1)) //여기는 필요없지만 혹여나 오류방지를 위하여
						keyboard[j][k] = 2 * (k - j - 6); //우하단은 이동비용이 바로밑 1로시작하여 1씩증가. 한층의차이가 7임을 감안
				}
				//좌하단
				for (int k = j + 7 - 1; 7 * (i + 1) - 6 <= k; k--) { //바로밑은제외, 바로밑에서 왼쪽부터 시작하여 줄여나감
					if (7 * i + 1 <= k && k <= 7 * (i + 1)) //!!!!!! k가 층을벗어남을 방지. 중요함!!!!!!!!!!
						keyboard[j][k] = 2 * abs(k - j - 7); //좌하단은 바로밑의 왼쪽키도 비용이 2임을 고려 
				}
			}

			if (i - 1 >= 1) { //유효한 윗층층일때만
				//우상단
				for (int k = j - 7; k <= 7 * (i - 1); k++) {
					if (7 * (i - 1) - 6 <= k && k <= 7 * i)
						keyboard[j][k] = 2 * abs(k - j + 7); //우하단은 이동비용이 바로밑 1로시작하여 1씩증가. 한층의차이가 7임을 감안
				}
				//좌상단
				for (int k = j - 7 - 1; 7 * (i - 1) - 6 <= k; k--) { //바로밑은제외, 바로밑에서 왼쪽부터 시작하여 줄여나감
					if (7 * (i - 1) - 6 <= k && k <= 7 * i) //k가 해당 층을 벗어나면 예외 처리 중요한코드
						keyboard[j][k] = 2 * abs(k - j + 6); //좌하단은 바로밑의 왼쪽키도 비용이 2임을 고려 
				}
			}
			if (8 <= j && j <= 21)
				keyboard[j][j - 7] = 2;
		}
	}

	//검산 - 아래층확인용
	//for (int i = 1; i <= 3; i++) {
	//	for (int j = 7 * i - 6; j <= 7 * i; j++) { //i층
	//		printf("%2d >> ", j);
	//		for (int k = 7 * (i+1) - 6; k <= 7 * (i+1); k++) { //(i+1)층 아래층
	//			if(1 <= i+1 || i+1 <= 3) //유효한것만
	//				printf("%2d ", keyboard[j][k]);
	//		}
	//		printf("\n");
	//	}
	//	printf("\n");
	//}
	
	//검산 - 윗층확인용
	//for (int i = 1; i <= 3; i++) {
	//	for (int j = 7 * i - 6; j <= 7 * i; j++) { //i층
	//		printf("%2d >> ", j);
	//		for (int k = 7 * (i - 1) - 6; k <= 7 * (i - 1); k++) { //(i-1)층 위층
	//			if (1 <= i - 1 || i - 1 <= 3) //유효한것만
	//				printf("%2d ", keyboard[j][k]);
	//		}
	//		printf("\n");
	//	}
	//	printf("\n");
	//}
	
	//3 : 두층아래의 모든 키값
	// 1층 :  1~7
	// 2층 :  8~14
	// 3층 : 15~21
	for (int j = 1; j <= 7; j++) {
		//우하단
		for (int k = j + 14; k <= 21 ; k++) {
			if (15 <= k && k <= 21)
				keyboard[j][k] = 2 * (k - j - 12); //우하단은 이동비용이 바로밑 1로시작하여 1씩증가. 한층의차이가 7임을 감안
		}
		//좌하단
		for (int k = j + 14 - 2; 15 <= k; k--) { //바로밑은제외, 바로밑에서 왼쪽부터 시작하여 줄여나감
			if(15 <= k && k <= 21)
				keyboard[j][k] = 2 * abs(14 - k + j); //좌하단은 바로밑의 왼쪽키도 비용이 2임을 고려 
		}
		if (j != 1) {
			keyboard[j][14 + j - 1] = 4;
		}

	}

	for (int j = 15; j <= 21; j++) {
		//우상단
		for (int k = j - 14; k <= 7; k++) {
			if (1 <= k && k <= 7)
				keyboard[j][k] = 2 * (k - j + 14); //우하단은 이동비용이 바로밑 1로시작하여 1씩증가. 한층의차이가 7임을 감안
		}
		//좌상단
		for (int k = j - 14; 1 <= k; k--) { //바로밑은제외, 바로밑에서 왼쪽부터 시작하여 줄여나감
			if (1 <= k && k <= 7)
				keyboard[j][k] = 2 * (j - k - 12); //좌하단은 바로밑의 왼쪽키도 비용이 2임을 고려 
		}
		if (j != 21)
			keyboard[j][j - 13] = 4;
	}

	//검산 - 아래층확인용
	//for (int j = 1; j <= 7; j++) { //i층
	//	printf("%2d >> ", j);
	//	for (int k = 15; k <= 21; k++) { //층 아래층
	//		printf("%2d ", keyboard[j][k]);
	//	}
	//	printf("\n");
	//}

	//검산 - 윗층확인용
	//for (int j = 15; j <= 21; j++) { //i층
	//	printf("%2d >> ", j);
	//	for (int k = 1; k <= 7; k++) { //(i-1)층 위층
	//		printf("%2d ", keyboard[j][k]);
	//	}
	//	printf("\n");
	//}

	//4 : 기존키에 나머지 5개 키(22 23 24 25 26) 연결
	for (int j = 1; j <= 7; j++) {
		keyboard[j][22] = 2 * (8 - j);
		keyboard[j][23] = 2 * (9 - j);
		keyboard[j][24] = 2 * (10 - j);
		keyboard[j][25] = 2 * (9 - j);
		keyboard[j][26] = 2 * (10 - j);
	}
	for (int j = 8; j <= 14; j++) {
		keyboard[j][22] = 2 * (7 + 8 - j);
		keyboard[j][23] = 2 * (7 + 9 - j);
		keyboard[j][24] = 2 * (7 + 10 - j);
		keyboard[j][25] = 2 * (7 + 8 - j);
		keyboard[j][26] = 2 * (7 + 9 - j);
	}for (int j = 15; j <= 21; j++) {
		keyboard[j][22] = 2 * (7 * 2 + 8 - j);
		keyboard[j][23] = 2 * (7 * 2 + 9 - j);
		keyboard[j][24] = 2 * (7 * 2 + 10 - j);
		keyboard[j][25] = 2 * (7 * 2 + 8 - j);
		keyboard[j][26] = 2 * (7 * 2 + 9 - j);
	}
	keyboard[21][22] = 4; //오류 수정용

	//5 : 22 23 24 25 26 키에 기존키를 연결
	for (int j = 7; j >= 1; j--) {
		keyboard[22][j] = 2 * (8 - j);
		keyboard[23][j] = 2 * (9 - j);
		keyboard[24][j] = 2 * (10 - j);
		keyboard[25][j] = 2 * (9 - j);
		keyboard[26][j] = 2 * (10 - j);
	}
	for (int j = 14; j >= 8; j--) {
		keyboard[22][j] = 2 * (7 + 8 - j);
		keyboard[23][j] = 2 * (7 + 9 - j);
		keyboard[24][j] = 2 * (7 + 10 - j);
		keyboard[25][j] = 2 * (7 + 8 - j);
		keyboard[26][j] = 2 * (7 + 9 - j);
	}
	for (int j = 21; j >= 15; j--) {
		keyboard[22][j] = 2 * (7 * 2 + 8 - j);
		keyboard[23][j] = 2 * (7 * 2 + 9 - j);
		keyboard[24][j] = 2 * (7 * 2 + 10 - j);
		keyboard[25][j] = 2 * (7 * 2 + 8 - j);
		keyboard[26][j] = 2 * (7 * 2 + 9 - j);
	}
	keyboard[22][21] = 4; //오류 수정용

	//6 : 22 23 24 25 26 키값간 연결
	keyboard[22][23] = 2; keyboard[23][22] = 2;
	keyboard[22][24] = 4; keyboard[24][22] = 4;
	keyboard[22][25] = 2; keyboard[25][22] = 2;
	keyboard[22][26] = 4; keyboard[26][22] = 4;
	keyboard[23][24] = 2; keyboard[24][23] = 2;
	keyboard[23][25] = 2; keyboard[25][23] = 2;
	keyboard[23][26] = 2; keyboard[26][23] = 2;
	keyboard[24][25] = 4; keyboard[25][24] = 4;
	keyboard[24][26] = 2; keyboard[26][24] = 2;
	keyboard[25][26] = 2; keyboard[26][25] = 2;
}

//입력받은 문자를 고유숫자인 키값으로 변경하는 함수
int findKEY(char c) {
	int res = -1;
	switch (c) {
	case 'A': res = 8; break; case 'B': res = 19; break;
	case 'C': res = 17; break; case 'D': res = 10; break;
	case 'E': res = 3; break; case 'F': res = 11; break;
	case 'G': res = 12; break; case 'H': res = 13; break;
	case 'I': res = 22; break; case 'J': res = 14; break;
	case 'K': res = 25; break; case 'L': res = 26; break;
	case 'M': res = 21; break; case 'N': res = 20; break;
	case 'O': res = 23; break; case 'P': res = 24; break;
	case 'Q': res = 1; break; case 'R': res = 4; break;
	case 'S': res = 9; break; case 'T': res = 5; break;
	case 'U': res = 7; break; case 'V': res = 18; break;
	case 'W': res = 2; break; case 'X': res = 16; break;
	case 'Y': res = 6; break; case 'Z': res = 15; break;
	}
	return res;
}

//입력을 받고 출력을 하는 함수
void input() {
	int n;
	scanf("%d", &n);
	while (n--) {
		char in[101]; //입력받은 문자
		scanf("%s", &in);
		int size = 0; //입력받은 문자열 크기
		int preKEY = -1;
		int res = 0;
		for (int i = 0; i < 101; i++) {
			if (in[i] == '\0') //끝을 만나면 종료
				break;
			size++;

			int KEY = findKEY(in[i]); //입력받은 문자를 고유 키값으로 변환
			if (i == 0) { //처음에는 손가락이 시작하는 위치로 비용발생X
				preKEY = KEY;
				continue;
			}
			else {
				res += keyboard[preKEY][KEY]; //이전키에서 현재키까지 비용을 추가
				//printf("%2d => %2d 비용:%2d\n", preKEY, KEY, keyboard[preKEY][KEY]); 
				preKEY = KEY; //이전키 갱신
			}
		}
		res += size; //키를 누를때마다 1초가 걸리므로 문자열길이만큼 추가하면 쉽게계산
		printf("%d\n", res);
	}


}

//검산용 출력 함수
void ex_input() {
	while (true) {
		int c;
		scanf("%d", &c);
		printf("======================================================================\n");
		for (int i = 0; i <= 2; i++) {
			if (i == 1)
				printf(" ");
			if (i == 2)
				printf("  ");
			for (int j = 1; j <= 7; j++) {
				if (c == 7 * i + j) {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
					printf("%2d ", keyboard[c][7 * i + j]);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				}
				else {
					printf("%2d ", keyboard[c][7 * i + j]);
				}
			}
			if (i == 0) {
				if (c == 22) {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
					printf("%2d ", keyboard[c][22]);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				}
				else {
					printf("%2d ", keyboard[c][22]);
				}
				if (c == 23) {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
					printf("%2d ", keyboard[c][23]);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				}
				else {
					printf("%2d ", keyboard[c][23]);
				}
				if (c == 24) {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
					printf("%2d ", keyboard[c][24]);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				}
				else {
					printf("%2d ", keyboard[c][24]);
				}
			}
			else if (i == 1) {
				if (c == 25) {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
					printf("%2d ", keyboard[c][25]);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				}
				else {
					printf("%2d ", keyboard[c][25]);
				}
				if (c == 26) {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
					printf("%2d ", keyboard[c][26]);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				}
				else {
					printf("%2d ", keyboard[c][26]);
				}
			}
			printf("\n");
		}
		printf("======================================================================\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	}
}

int main(void) {
	makeKeyboard();
	ex_input(); //검산용
	//input();
	return 0;
}