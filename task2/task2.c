#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double f(double x){
	return exp(2*x)*sin(x) - cos(x);
}

double getHordMiddle(double a, double b){
	double result = a - (f(a)/(f(b)-f(a))) * (b -a);
	return result;	
}

double root(double a, double b){
	if(fabs(b-a)<pow(10, -5)){
		return getHordMiddle(a, b); 
	}
	double c = getHordMiddle(a, b);
	if(f(a)*f(c) < pow(10,-5)){
		return getHordMiddle(a, b); 
	}
	if(f(a)*f(c)<0){
		return root(a, c);
	}else{
		return root(c, b);
	}
}

int main(){
	printf("root1 is: %lf\n", root(-2, -1));
	printf("root2 is: %lf\n", root(0, 1));
	printf("root3 is: %lf\n", root(2, 4));
}
