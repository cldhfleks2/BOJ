#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>

int N, L, ** TL; //TL : 입력받은 신호등 0:위치 1:빨간불지속시간 2:초록불지속시간
bool* road; //도로가 이동가능한 상태(빨간불인지 초록불인지)인지 기록할 변수
int t = 0; //시간
int distance = 0;
void init();
void traffic();
void drive();

void init() {
    scanf("%d %d", &N, &L);
    
    road = new bool[L + 1]; // 1~ L까지
    //우선 모든 도로구간이 이동가능함을 기록
    //밑에서 신호등위치마다 처음엔 빨간불임을 기록할것임
    road[0] = true; //검산용으로 넣음
    for (int i = 1; i <= L; i++) 
        road[i] = true; 

    TL = new int* [N];

    for (int i = 0; i < N; i++) {
        TL[i] = new int[3];
        //신호등위치, 빨간불지속시간 초록불지속시간
        scanf("%d %d %d", &TL[i][0], &TL[i][1], &TL[i][2]);
    }

    //신호등위치마다 처음엔 빨간불(이동불가능)임을 기록
    for (int i = 0; i < N; i++) 
        road[TL[i][0]] = false;
    
}

//실제 주행하여 도로끝에 도달하면 걸린 시간을 출력하는 함수
void drive() { 
    while (true) {
        t++; //시간 흐름

        traffic(); //다음 1m 앞 위치의 신호등상태 계산

        if (distance + 1 == L) { //다음 1m가 도로끝인경우(이곳엔 신호등이없다)
            printf("%d", t-1);
            return; //종료
        }
        else {
            if (road[distance + 1]) { //다음 1m의 위치가 이동가능한 상태라면 1m주행
                distance++;
            }
        }
        //printf("시간: %2d , 위치: %2d  >> ", t, distance);
        //for (int i = 0; i < N; i++)
        //   printf("%d번째신호등 상태:%d  ,  ", TL[i][0], road[TL[i][0]]);
        //for (int i = 0; i <= L ; i++)
        //    printf("%d ", road[i]);
        //printf("\n");
    }
}

//시간에따른 신호등 상태즉 road를 변경시켜주는 함수
void traffic() { 
 
    //시간에따른 도로위의 신호등위치 에서 이동가능 상태를 계산한다.
    for (int i = 0, location; i < N; i++) { //신호등 갯수만큼 체크
        location = TL[i][0]; //현재 신호등 위치
        int allLight = TL[i][1] + TL[i][2]; //빨간불시간 + 초록불시간
        int mod; //현재신호에서 지속된 시간. 

        mod = (t-1) % allLight;
        //현재 빨간불인상태에서 빨간불 지속시간이 다됬으면
        if (!road[location] && mod == TL[i][1]) {
            //-> 초록불로 바꿈
            road[location] = true; //도로상태를 바꿈
            continue;
        }
        //현재 초록불인상태에서 초록불 지속시간이 다됬으면
        if (road[location] && mod == 0) {
            //-> 빨간불로 바꿈
            road[location] = false; //도로상태를 바꿈
            continue;
        }
        

    }
        
}

int main() {
    init();
    drive();

    return 0;
}