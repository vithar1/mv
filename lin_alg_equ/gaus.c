#include<stdio.h>

int h = 4;
int w = 4;
int row_at = 0;
int col_at = 0;
double A[4][4] = {
    { 13, 1, -1,  5},
    { 4 , 9,  2,  1},
    {-6,  2,  14, 2},
    { 1 , 1, -3,  7}
};

double B[4] = {-37, 6, 78, -7};
double X[4] = {0,0,0,0};


void change_rows(int i1, int i2) {
    for(int j=0;j<w;j++){
        double temp = A[i1][j];
        A[i1][j] = A[i2][j];
        A[i2][j] = temp;
    }
    double temp = B[i1];
    B[i1] = B[i2];
    B[i2] = temp;
}


int move_up(){
    for(int j=row_at; j<w; j++){
        for(int i=col_at; i<h; i++){
            if(A[i][j] != 0) {
                change_rows(col_at, i);
                return 1;
            }
        }   
    }
    return 0;
}


void print_matrix(){
    printf("\n");
    for(int i=0;i<h;i++){
        printf("\n");
        for(int j=0;j<w;j++){
            printf("%g, ", A[i][j]);
        }
        printf("||%g", B[i]);
    }
}


void transform_to_stepped(){
    while(move_up()) {
        if(row_at == h-1 ) {
            return;
        }
        double del = A[col_at][row_at];
        for(int j=0; j<w; j++){
            A[col_at][j] /= del;
        }
        B[col_at] /= del;
        for(int i=col_at+1;i<h;i++){
            double mult = A[i][row_at]/A[col_at][row_at];
            for(int j=row_at;j<w;j++){
                A[i][j] -= mult * A[col_at][j];
            }
            B[i] -= mult * B[col_at];
        }
        col_at++;
        row_at++;
    }
}


void take_roots() {
    for(int i = h-1;i>-1;i--){
        double sum = 0;
        for(int j=w-1;j>i;j--){
            sum += A[i][j] * X[j];
        }
        X[i] = (B[i] - sum)/A[i][i];
    }
}


int main() {
    print_matrix();
    transform_to_stepped();
    printf("\n");
    print_matrix();
    take_roots();
    printf("\n\n");
    for(int i=0;i<h;i++){
        printf("x%d = %g\n", i+1, X[i]);
    }
    return 0;
}