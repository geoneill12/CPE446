#include <stdio.h>

// Define inputs B and C
int B[3][3] = { 4,7,3,
                2,9,5,
                5,9,0   };

int C[3][3] = { 7,1,3,
                7,5,6,
                1,3,1   };

void main(){

    // Add checksum row/column to input matrices
    int B_c[4][3];
    int C_c[3][4];
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){

            B_c[i][j] = B[i][j];
            C_c[i][j] = C[i][j];

        }
    }
    for(int i=0; i<3; i++){

        B_c[3][i] = B_c[0][i]+B_c[1][i]+B_c[2][i];
        C_c[i][3] = C_c[i][0]+C_c[i][1]+C_c[i][2];

    }

    // Multiply matrices
    int A[4][4];
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            A[i][j] = 0;
            for(int k=0; k<3; k++){

                A[i][j] += B_c[i][k]*C_c[k][j];

            }
        }
    }

    // Evaluate checksums
    int ERR = 0;
    for(int i=0; i<4; i++){

        if(A[0][i]+A[1][i]+A[2][i] != A[3][i]){
            ERR = 1;
            break;
        }
        if(A[i][0]+A[i][1]+A[i][2] != A[i][3]){
            ERR = 1;
            break;
        }

    }

    // Print input B
    printf("\nB =\n\n");
    printf("%d    ", B_c[0][0]);
    printf("%d    ", B_c[0][1]);
    printf("%d\n", B_c[0][2]);
    printf("%d    ", B_c[1][0]);
    printf("%d    ", B_c[1][1]);
    printf("%d\n", B_c[1][2]);
    printf("%d    ", B_c[2][0]);
    printf("%d    ", B_c[2][1]);
    printf("%d\n", B_c[2][2]);
    printf("%d    ", B_c[3][0]);
    printf("%d    ", B_c[3][1]);
    printf("%d\n\n", B_c[3][2]);

    // Print input C
    printf("C =\n\n");
    printf("%d    ", C_c[0][0]);
    printf("%d    ", C_c[0][1]);
    printf("%d    ", C_c[0][2]);
    printf("%d\n", C_c[0][3]);
    printf("%d    ", C_c[1][0]);
    printf("%d    ", C_c[1][1]);
    printf("%d    ", C_c[1][2]);
    printf("%d\n", C_c[1][3]);
    printf("%d    ", C_c[2][0]);
    printf("%d    ", C_c[2][1]);
    printf("%d    ", C_c[2][2]);
    printf("%d\n\n", C_c[2][3]);

    // Print result A
    printf("A =\n\n");
    printf("%d    ", A[0][0]);
    printf("%d    ", A[0][1]);
    printf("%d    ", A[0][2]);
    printf("%d\n", A[0][3]);
    printf("%d    ", A[1][0]);
    printf("%d    ", A[1][1]);
    printf("%d    ", A[1][2]);
    printf("%d\n", A[1][3]);
    printf("%d    ", A[2][0]);
    printf("%d    ", A[2][1]);
    printf("%d    ", A[2][2]);
    printf("%d\n", A[2][3]);
    printf("%d    ", A[3][0]);
    printf("%d    ", A[3][1]);
    printf("%d    ", A[3][2]);
    printf("%d\n\n", A[3][3]);

    // Print checksum result
    if(ERR == 1){
        printf("Operation successful!\n\n");
    } else {
        printf("Checksum error!\n\n");
    }

}