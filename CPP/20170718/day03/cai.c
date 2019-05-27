#include <stdio.h>
int main(){
    int n=9;
    while(1){
        int input;
        printf("input number:\n");
        scanf("%d",&input);
        if(input != n){
            printf("不对!\n");
        }else{
            printf("very good!\n");
            break;
        }
        
    
    }
    
}
