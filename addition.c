#include <stdio.h>
#include <math.h>
#include <fenv.h>

int main(){
    double a=1.0/10.0; //0.1
    double b=11.0/10.0; //1.1

    double c=a+b;

    printf("%lf\n",c);
}
