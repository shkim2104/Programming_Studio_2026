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
        printf("students RC PR\n");
        printf("돼지\n");
        
        printf("====================================\n");
        printf("menu : 1. register boy 2. register women 0. exit >\n");
        scanf("%d" ,&n);
        
        if(n==1){
            ins_studata(n);
        }
        else if(n==2){
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
    printf("result register roomnumber\n");
    printf("======================================\n");

    
    printf("men %d\n" , mc); 

    for(int i =0; i< mc; i++){
        printf("%d. %s [10%d]\n" , i+1 ,mn[i] , mr[i]);
    }

    printf("\n");
    
    printf("women %d\n" , wc);

    for(int i=0; i < wc; i++){
        printf("%d. %s [20%d]\n" , i+1 , wn[i] , wr[i]);
    }

    printf("\n");

    

    printf("reguster all students room\n");

    for(int i =0; i < 5; i++){
        printf("10%d" , i+1);
        for(int j =0; j <mc; j++){
            if(mr[j] ==i){
                printf("%s" , mn[j]);
            }
        }
        printf("\n");
    }

    for(int i = 0; i < 5; i++){
        printf("20%d" , i +1);
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

        printf("%s student register room  10%d\n" , mn[mc] , room);
        mc = mc + 1;
    }    
    
    else if(g ==2){
        scanf("%s" , wn[wc]);
        room = findRoom(wp);
        wr[wc] = room;
        wp[room -1] = wp[room -1] + 1;

        printf("%sstudent reguster room 20%d\n" , wn[wc] , room);

        wc = wc + 1;
    }
}