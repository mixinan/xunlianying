#include <stdio.h>
int main(){
    int n;
    printf("请输入1-4数字：");
    scanf("%d",&n);
   
    /*
    if(n==1){
        printf("chun\n");
    }else if(n==2){
        printf("xia\n");
    }else if(n==3){
        printf("qiu\n");
    }else if(n==4){
        printf("dong\n");
    }else{
        printf("wrong!\n");
    }
    */

    switch(n){
        case 1:
            printf("chun\n");
        break;
        case 2:
            printf("xia\n");
        break;
        case 3:
            printf("qiu\n");
        break;
        case 4:
            printf("dong\n");
        break;
        default:
            printf("wrong\n");
        break;
    }

    return 0;
}
