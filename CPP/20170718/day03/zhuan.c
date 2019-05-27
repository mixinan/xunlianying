#include <stdio.h>
int main(){
    char ch;
    printf("请输入一个字母:\n");
    scanf("%c",&ch);
    if('A'<=ch && ch<='Z'){
        ch=ch+32;
    }
    printf("结果是%c\n",ch);
    return 0;
}
