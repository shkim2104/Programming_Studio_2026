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

    while(1){
        r = rand() %5;  
        if(persons[r] < 2){
            return r + 1;  
        }
    }
}


void printReport(char mn[10][20], int mr[10], int mc, char wn[10][20], int wr[10], int wc){
    printf("==================================\n");
    printf("생활관 호실 배정 결과는 다음과 같습니다\n");
    printf("======================================\n");

    
    printf("남학생 명단 %d\n" , mc); 

    for(int i =0; i< mc; i++){
        printf("%d. %s [10%d]\n" , i+1 ,mn[i] , mr[i]);
    }

    printf("\n");
    
    printf("여학생 명 %d\n" , wc);

    for(int i=0; i < wc; i++){
        printf("%d. %s [20%d]\n" , i+1 , wn[i] , wr[i]);
    }

    printf("\n");

    

    printf("호실별 배정 명단\n");

    for(int i =0; i < 5; i++){
        printf("10%d" , i);
        for(int j =0; j <mc; j++){
            if(mr[j] ==i){
                printf("%s" , mn[j]);
            }
        }
        printf("\n");
    }

    for(int i = 0; i < 5; i++){
        printf("20%d" , i);
        for(int j =0; j <wc; j++){
            if(wr[j] ==i){
                printf("%s" , wn[j]);
            }
        }
        printf("\n");
    }
}


void ins_studata(int g){
    int room;

    
    if(g == 1){ 
        scanf("%s" , mn[mc]);

        room = findRoom(mp);
        mr[mc] = room; 
        mp[room -1] = mp[room -1] + 1; 

        printf("%s 학생   10%d호실 배정되었습니다\n" , mn[mc] , room);
        mc = mc + 1;
    }    
    
    else if(g ==2){
        scanf("%s" , wn[wc]);
        room = findRoom(wp);
        wr[wc] = room;
        wp[room -1] = wp[room -1] + 1;

        printf("%s학생 20%d호실 배정되었습니다\n" , wn[wc] , room);

        wc = wc + 1;
    }
}