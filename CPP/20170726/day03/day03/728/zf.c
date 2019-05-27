#include <stdio.h>
int main(){
    char c=0;
    scanf("%c",&c);
    if(c>='a' && c<='z'){
        printf("%c\n",(c-'a')+'A');
    }

    if(c>='A' && c<='Z'){
        printf("%c\n",c-'A'+'a');
    }

    return 0;
}
