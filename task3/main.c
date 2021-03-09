#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double f(double x){
    return exp(2*x)*sin(x) - cos(x);
}

double df(double x){
    return 2*exp(2*x)*sin(x) + exp(2*x)*cos(x)+sin(x);
}

double d2f(double x){
    return 4*exp(2*x)*sin(x) + exp(2*x)*cos(x)+2*exp(2*x)*cos(x)-exp(2*x)*sin(x)+cos(x);
}

double getRoot(double x){
   double x_next = x - f(x)/df(x); 
   if(fabs(x_next - x)<pow(10,-5)){
        return x_next; 
   }
   return getRoot(x_next);
}

int main(){
    printf("root1: %lf\n",getRoot(-1));
    printf("root2: %lf\n",getRoot(1));
    printf("root3: %lf\n",getRoot(3));
    return 0;
}
