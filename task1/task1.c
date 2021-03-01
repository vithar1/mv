#include <stdio.h>
#include <math.h>
#include<stdio.h>

double function(double x){
    return exp(2*x)*sin(x) - cos(x);
}

double getRootForInterval(double a, double b){
    if(fabs(b -a) < pow(10,-5)){
	   return a+(b - a)/2;
    }
	if(function(a)*function(a+(b-a)/2)<0){
	    return getRootForInterval(a, a+(b-a)/2);
    }else{
        return getRootForInterval(a+(b-a)/2, b);
    }
}

int main(){
    printf("First root: %lf\n", getRootForInterval(-2, -1));
	printf("Second root: %lf\n", getRootForInterval(0, 1));
	printf("Trid root: %lf\n", getRootForInterval(2, 4));
	return 0;
}
