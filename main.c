#include<stdio.h>
#include<math.h>

double k = 100000   ;

double function(double x){
    return 3*pow(sin(x), 3); 
}

double mistakes(double a, double b){
    double ksi = (b-a)/k;
    double mistakes = -9*(pow(sin(ksi),2) - 2*pow(cos(ksi),2))*sin(ksi);
    mistakes /= 12;
    mistakes *= pow((b-a),3);
    return mistakes;
}

double calcInt(double a, double b){
    double sum = 0;
    double step = (b-a)/k;
    for(double i = a+step;i<b-step; i+=step){
        sum += function(i);
    }
    sum += (function(a)+function(b))/2;
    return sum*step;
}

int main(){
    printf("answer is: %lf\n", calcInt(0, M_PI/2));
    printf("mistakes is: %lf\n", mistakes(0, M_PI/2));
    return 0;
}