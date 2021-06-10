#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int fac(int n)
{
if (n <= 1)

return 1;

else

return n * fac(n - 1);

}

int fact(int n ){
    printf("%d\r\n",fac(n));
}


void add(int* x , int* y, int*z){
    *z = *x + *y;
}

void pr(void)
{
    printf("a\r\n");    
}


void GetIntArray(int64_t* p,int N){
    for(int i = 0;i<N;i++){
        p[i] = i;
    }
}
