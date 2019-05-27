#include <stdio.h>
int main(){
    int a=3;
    int b;
    
    b= ++a + ++a;

    printf("b= ++a + ++a 的结果是:%d\n",b);

    return 0;
}
