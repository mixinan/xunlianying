#include <stdio.h>
int main(){
    int n;
    int m;

    for(m=1; m<=9; m++){
        for(n=1; n<=m; n++){
            printf("%d*%d=%d\t",n,m,n*m);
        }
        printf("\n");
    }

    return 0;
}
