#include <stdio.h>
#include <math.h>

double function(double x)
{
    return 3 * pow(sin(x), 3);
}

double d4_function(double x)
{
    return -10 * sin(x) * cos(x) * cos(x) + 63 * pow(sin(x), 3);
}

double mistakes(double a, double b)
{
    double max = -100000;
    for (double i = a; i < b; i += 0.0001)
    {
        double temp = d4_function(i);
        if (temp > max)
        {
            max = temp;
        }
    }
    double result = d4_function(max) / 135;
    if(result < 0){
        result *= -1;
    }
    return result;
}

double calcInt(double a, double b)
{
    double result = (b - a) / 2;
    result *= function((b + a) / 2 - (b - a) / (2 * sqrt(3))) + function((b + a) / 2 + (b - a) / (2 * sqrt(3)));
    return result;
}

int main()
{
    printf("answer is: %lf\n", calcInt(0, M_PI / 2));
    printf("mistakes is: %lf\n", mistakes(0, M_PI / 2));
    return 0;
}