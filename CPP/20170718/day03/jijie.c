#include <stdio.h>
int main(){
    int n;
    printf("请输入数字:\n");
    scanf("%d",&n);
   /*
    if(n==1){
        printf("spring\n");
    }else if(n==2){
        printf("summer\n");
    }else if(n==3){
        printf("autumn\n");
    }else if(n==4){
        printf("winter\n");
    }else{
        printf("wrong!\n");
    }
    */

    switch(n){
        case 1:
            printf("春天！\n");
        break;
        case 2:
            printf("xia天！\n");
        break;
        case 3:
            printf("qiu天！\n");
        break;
        case 4:
            printf("dong天！\n");
        break;
        default:
            printf("wrong!\n");
        break;
    
    }
    return 0;
}
