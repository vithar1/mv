//euler's method
#include<stdio.h>

double f(double x, double y) {
    if(x + 2*y == 0){
        printf("Error delimeter on zero!!!");
        return 0;
    }
    return 1/(x + 2*y);
}

int main() {
    double prev_x = -1;
    double prev_y = 0;
    for(double i=-1+0.1;i<=1;i+=0.1){
        printf("x = %f; y = %f\n", prev_x, prev_y);
        prev_x = i;
        prev_y += 0.1*f(prev_x, prev_y); 
    }
    printf("x = %f; y = %f\n", prev_x, prev_y);
    return 0;
}