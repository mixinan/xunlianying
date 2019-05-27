#include <stdio.h>
int main(){
    int score;
    printf("请输入你的分数:\n");
    scanf("%d",&score);
    if(score>100 || score<0){
        printf("输入有误！\n");
    }else if(score==100){
        printf("牛！\n");
    }else if(score>=90){
        printf("优秀！\n");
    }else if(score>=60){
        printf("良好!\n");
    }else{
        printf("不及格！\n");
    }
    return 0;
}
