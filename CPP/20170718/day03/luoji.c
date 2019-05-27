#include <stdio.h>
int main(){
    int a=5,b=8,c=20;
    printf("a>b %d\n",a>b);
    printf("a<c %d\n",a<c);
    printf("a>b && a<c %d\n",a>b && a<c);
    printf("a>b || a<c %d\n",a>b || a<c);
    printf("!(a>b) %d\n",!(a>b));
    printf("!(a<c) %d\n",!(a<c));
    return 0;
}
