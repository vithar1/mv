#include <stdio.h>
#include <stdlib.h>
  
int number_iter = 3;
int w = 4; 
int h = 4;
double A[4][4] = {
    { 13, 1, -1,  5},
    { 4 , 9,  2,  1},
    {-6,  2,  14, 2},
    { 1 , 1, -3,  7}
};
double B[4] = {-37, 6, 78, -7};
double X[4] = {0,0,0,0};


void print_matrix(){
    printf("\n");
    for(int i=0;i<h;i++){
        printf("\n");
        for(int j=0;j<w;j++){
            printf("%g, ", A[i][j]);
        }
        printf("||%g", B[i]);
    }
    printf("\n");
}


int main(){
    print_matrix();
    for(int iter_count=0;iter_count<number_iter;iter_count++){
        for(int i=0;i<h;i++){
            double x = B[i]; 
            for(int j=0;j<w;j++){
                if (i!=j){
                    x -= A[i][j]*X[j]; 
                }
            }
            x /= A[i][i]; 
            X[i] = x;
        }
    }
    for(int i=0;i<h;i++){
        printf("x%d = %g\n", i+1, X[i]);
    }
}