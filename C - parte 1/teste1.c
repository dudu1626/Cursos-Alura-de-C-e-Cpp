#include <stdio.h>

int main(){

    int a,res;

    printf("Digite um numero:");
    scanf("%d", &a);

    for(int i=0; i<10;i++){

        res = a * (i+1);
        printf("%d x %d = %d\n", a,i+1,res);
    }

    return 0;
}
