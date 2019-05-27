#include <stdio.h>
int main(){
    int n;
    int result;
    printf("请输入一个整数:\n");
    scanf("%d",&n);

    //短路特性：如果大于0，则取本身
    (n>=0) && (result=n);
    //短路特性：如果小于0，则取相反数
    (n<0) && (result=-n);
    printf("%d的绝对值是%d\n",n,result);
    return 0;
}
