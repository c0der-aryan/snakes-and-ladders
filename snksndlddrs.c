#include <stdio.h>
#include <time.h>
#include <stdlib.h>
typedef struct lists_of_snakes_and_ladder {
    int start;
    int end;
}lst;
int dice();
void turn(int plyr,int *ptr);
int wins(int plyr,int posn);
int main(){
    int posn1 = 0 ;
    int posn2 = 0 ;
    int *ptr1;
    int *ptr2;
    int name;
    printf("-----------------------------------\n");
    printf("PRESS '1' to roll dice for player 1 \nPRESS '2' to roll dice for playes 2 \n");
    printf("-----------------------------------\n");
    while (1){
        printf("HERE : ");
        scanf("%d",&name);
        if (name==1){
            turn(name , &posn1);
            if (wins(1,posn1)==10){
                break;
            }
        } else if (name==2){
            turn(name , &posn2);
            if (wins(2,posn2)==10){
                break;
            }
           
        }
    }
}
int dice(){ // ROLL THE DICE 
    int dig;
    srand(time(0));
    dig=(rand() % 6) + 1 ; // TO GENERATE A RANDOM NUMBER BETWEEN 1 - 6
    return dig;
}
void turn(int plyr,int *ptr){
    lst lddrs[3],snks[3];
    lddrs[0].start=9;
    lddrs[0].end=33;
    lddrs[1].start=13;
    lddrs[1].end=24;
    lddrs[2].start=17;
    lddrs[2].end=30;
    
    snks[0].start=35;
    snks[0].end=2;
    snks[1].start=32;
    snks[1].end=28;
    snks[2].start=29;
    snks[2].end=18;
    
    int numb=dice();
    printf("The dice rolled : %d\n",numb);
    *ptr+=numb;
    for (int i=0 ; i<3;i++){
        if (*ptr==lddrs[i].start){
            printf("ladder from %d to ",*ptr);
            *ptr=lddrs[i].end;
            printf("%d\n ",*ptr);
            
        } else if (*ptr==snks[i].start){
            printf("snake from %d to ",*ptr);
            *ptr=snks[i].end;
            printf("%d\n",*ptr);
        }
    }
    printf("The postion of player %d is : %d \n",plyr , *ptr);
    
}
int wins(int plyr, int posn){
    if (posn>36){
        printf("PLAYER %D WINSS!!!\n",plyr);
        return 10;
    } else {
        return 0;
    }
}
