//runga kutta method 
#include<stdio.h>

double f(double x, double y) {
    if(x + 2*y == 0){
        printf("Error delimeter on zero!!!");
        return 0;
    }
    return 1/(x + 2*y);
}

void calc_k(double *k_1, double *k_2, double *k_3, double *k_4, double x, double y, double h) {
    *k_1 = f(x,y);
    *k_2 = f(x+h/2, y+(h/2)* (*k_1));
    *k_3 = f(x+h/2, y+(h/2)* (*k_2));
    *k_4 = f(x+h, y+h* (*k_3));
}

int main() {
    double prev_x = -1;
    double prev_y = 0;
    double k_1, k_2, k_3, k_4;
    double k;
    for(double i=-1+0.1;i<=1;i+=0.1){
        printf("x = %f; y = %f\n", prev_x, prev_y);
        calc_k(&k_1, &k_2, &k_3, &k_4, prev_x, prev_y, 0.1);
        k = (k_1 + 2 * k_2 + 2 * k_3 + k_4)/6;
        prev_x = i;
        prev_y += 0.1*k; 
    }
    printf("x = %f; y = %f\n", prev_x, prev_y);
    return 0;
}
