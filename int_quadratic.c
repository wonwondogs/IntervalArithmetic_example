#include <stdio.h>
#include <math.h>
#include <fenv.h>

int main(){
    double a=1;
    double b=1000000000000000;
    double c=100000000000000;

    fesetround(FE_TONEAREST);
    double int_sqrt=b*b-4*a*c;

    fesetround(FE_UPWARD);
    double sqrt_u=sqrt(int_sqrt);
    fesetround(FE_DOWNWARD);
    double sqrt_l=sqrt(int_sqrt);

    fesetround(FE_UPWARD);
    double denom_u= -b + sqrt_u;
    fesetround(FE_DOWNWARD);
    double denom_l= -b + sqrt_l;

    fesetround(FE_TONEAREST);
    double numerator=2*a;
    fesetround(FE_UPWARD);
    double ans_u[4];
    ans_u[0]=denom_l/numerator;
    ans_u[1]=denom_u/numerator;
    fesetround(FE_DOWNWARD);
    double ans_l[4];
    ans_l[0]=denom_l/numerator;
    ans_l[1]=denom_u/numerator;

    double min,max;

    max = ans_u[0];
    for(int i=0; i<2; i++){
        if(max < ans_u[i]){
            max=ans_u[i];
        }
    }

    min = ans_l[0];
    for(int i=0; i<2; i++){
        if(min > ans_l[i]){
            min=ans_l[i];
        }
    }

    printf("ans in [%lf, %lf]\n",min,max);

  }