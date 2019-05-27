#include <stdio.h>
int main(){
    int n;
    printf("请输入分数:\n");
    scanf("%d",&n);
    if(n>=90){
        printf("优秀！\n");
    }else if(n>=70) {
        printf("良好\n");
    }else if(n>=60){
        printf("jige\n");
    }else{
        printf("不及格！\n");
    }

    return 0;
}
