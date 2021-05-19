#include <stdio.h>
#include <math.h>

double k = 10000;

double function(double x)
{
    return 3 * pow(sin(x), 3);
}

double d4f(double x){
    return -180 * sin(x) * pow(cos(x), 2) + 63* pow(sin(x), 3);
}

double mistakes(double a, double b)
{
    double h = (b-a)/(2*k);
    double max = fabs(d4f(b)); 
    double temp = 0; 
    for(double point = a; point<b; point +=h){
        temp = d4f(point);
        if(fabs(temp) > max){
            max = temp;
        } 
    }
    double mistakes = pow((b-a), 5)/2880;
    return mistakes * max;
}

double calcInt(double a, double b)
{
    double h = (b - a) / (2 * k);
    double integral = function(a) + function(b);
    int flag = 1;
    for (double point = a; point < b; point += h)
    {
        if (flag){
            integral += 2 * function(point);
            flag-=1;
        }else{
            integral += 4 * function(point);
            flag+=1;
        }
    }
    integral *= h / 3;
    return integral;
}

int main()
{
    printf("answer is: %lf\n", calcInt(0, M_PI / 2));
    printf("mistakes is: %lf\n", mistakes(0, M_PI / 2));
    return 0;
}