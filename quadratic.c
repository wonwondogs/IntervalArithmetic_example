#include <stdio.h>
#include <math.h>

int main(){
    double a=1;
    double b=1000000000000000;
    double c=100000000000000;

    double x1=(-b+sqrt(b*b-4*a*c))/(2*a);
    printf("%.16f\n",x1);

    double x2=(2*c)/(-b-sqrt(b*b-4*a*c));

    printf("%.16f\n",x2);    
}