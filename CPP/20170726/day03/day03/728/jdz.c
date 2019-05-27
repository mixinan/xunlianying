#include <stdio.h>
int main(){
    int n;
    printf("请输入一个整数：\n");
    scanf("%d",&n);
    if(n>=0){
        printf("%d\n",n);
    }else{
        printf("%d\n",-n);
    }
    return 0;
}
