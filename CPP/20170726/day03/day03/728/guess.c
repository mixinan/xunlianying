#include <stdio.h>
int main(){
    int m;
    int n;

    printf("请输入目标数字：");
    scanf("%d",&m);
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

    while(1){
        printf("请输入一个整数:\n");
        scanf("%d",&n);
        if(n==m){
            printf("恭喜你，答对了！\n");
            break;
        }else if(n<m){
            printf("小了！\n");
        }else if(n>m){
            printf("大了！\n");
        }
    }

    return 0;
}
