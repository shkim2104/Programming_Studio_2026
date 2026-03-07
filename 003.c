#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char mn[10][20];
int mr[10];
int mc =0;
int mp[5] = {0,0,0,0,0};

char wn[10][20];
int wr[10];
int wc =0;
int wp[5] = {0,0,0,0,0};


int findRoom(int persons[5]);
void printReport(char mn[10][20], int mr[10], int mc, char wn[10][20], int wr[10], int wc);
void ins_studata(int g);

int main(){
    int n;
    system("chcp 65001");
    srand(time(NULL));
    
    while(1){
        printf("====================================\n");
        printf("생활관 호실 배정 프로그램\n");
        printf("====================================\n");
        printf("메뉴  : 1. 남학생 등록  2. 여학생등록 0. 종료 >\n");
        scanf("%d" ,&n);
        
        if(n==1){
            if (mc >= 10) {
                printf("\n오류\n");
                break;
            }
            ins_studata(n);
        }
        else if(n==2){
            if (wc > 10) {
                printf("\n오류\n");
                break;
            }
            ins_studata(n);
        }
        else if(n==0){
            break;
        }

    }

    printReport(mn , mr , mc , wn , wr , wc);

   return 0;
}


int findRoom(int persons[5]){
    int r;
    int n , t;
    n = 1;
    t = 4;

    while(1){
        r = rand() %(t - n + 1) + n; // 방개수를 1 ~ 5개 까지 랜덤으로 배정
        
        if(persons[r] < 2){ // 방에 2명이 다 찼다면 n+1 호로 배
            return r + 1;  
        }
    }
}


void printReport(char mn[10][20], int mr[10], int mc, char wn[10][20], int wr[10], int wc){
    printf("==================================\n");
    printf("생활관 호실 배정 결과는 다음과 같습니다\n");
    printf("======================================\n");

    
    printf("남학생 명단 %d\n\n" , mc); 

    for(int i =0; i< mc; i++){
        printf("%d. %s [10%d]\n" , i+1 ,mn[i] , mr[i]); // 남학생의 방과 호수 이름을출력 남자가 있는 수만큼
    }

    printf("\n");
    
    printf("여학생 명 %d\n" , wc);

    for(int i=0; i < wc;i++){
        printf("%d. %s [20%d]\n" , i+1 , wn[i] , wr[i]); // 남학생과 마찬가지로 출력
    }

    printf("\n");

    

    printf("호실별 배정 명단\n");

    for(int i =0; i < 5; i++){
        printf("10%d호 : " , i+1);
        for(int j =0; j <mc; j++){      //  아래 여학생과 마찬가지로 동일함
            if(mr[j] ==i+1){
                printf("%s " , mn[j]);
            }
        }
        printf("\n");
    }

    for(int i = 0; i < 5; i++){
        printf("20%d호 : " , i+1);
        for(int j =0; j <wc; j++){  // 여학생이 몇호에 있는지  5개 방만큼 배열을 wc만큼 반복하여 출력함 
            if(wr[j] ==i+1){
                printf("%s " , wn[j]);
            }
        }
        printf("\n");
    }
}


void ins_studata(int g){
    int room;
        
    if(g == 1){ 
        printf("학생 이름은? > ");
        scanf("%s" , mn[mc]);           //배열에 이름을 기입함

        room = findRoom(mp);    //방을 지정된 난수로 배정을 받아서 mr 배열에 추가하고
        mr[mc] = room; 
        mp[room -1] = mp[room -1] + 1; 

        printf("%s 학생 10%d호실 배정되었습니다\n" , mn[mc] , room);  
        mc = mc + 1;            // 한명을 추가할때마다 카운트를 더한다
    }    
    
    else if(g ==2){
        printf("학생 이름은? > ");
        scanf("%s" , wn[wc]);
        room = findRoom(wp);            //여학생도 마찬가지로 추가한다
        wr[wc] = room;
        wp[room -1] = wp[room -1] + 1;

        printf("%s학생 20%d호실 배정되었습니다\n" , wn[wc] , room);

        wc = wc + 1;
    }
}