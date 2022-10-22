#include <stdio.h>

// Input data
int data = 0b1001;
int data_rx = 0b00011001;

void main(){

    printf("\n");

    // Compute parity bits
    int X0 = data & 0x1;
    int X1 = (data >> 1) & 0x1;
    int X2 = (data >> 2) & 0x1;
    int X3 = (data >> 3) & 0x1;
    int P1 = X3 ^ X0 ^ X2;
    int P2 = X3 ^ X0 ^ X1;
    int P4 = X2 ^ X0 ^ X1;
    int data_tx = (P1 << 6) | (P2 << 5) | (X3 << 4) | (P4 << 3) | (X2 << 2) | (X1 << 1) | X0;

    // Print input/encoded data
    printf("Input Data =     0b");
    for(int i=3; i>=0; i--){
        printf("%d", (data >> i) & 0x1);
    }
    printf("\n\nEncoded Data =   0b");
    for(int i=7; i>=0; i--){
        printf("%d", (data_tx >> i) & 0x1);
    }
    printf("\n\n");

    // Decode received data
    int X0_r = data_rx & 0x1;
    int X1_r = (data_rx >> 1) & 0x1;
    int X2_r = (data_rx >> 2) & 0x1;
    int X3_r = (data_rx >> 4) & 0x1;
    int P1_r = (data_rx >> 6) & 0x1;
    int P2_r = (data_rx >> 5) & 0x1;
    int P4_r = (data_rx >> 3) & 0x1;
    int P1_d = X3_r ^ X0_r ^ X2_r;
    int P2_d = X3_r ^ X0_r ^ X1_r;
    int P4_d = X2_r ^ X0_r ^ X1_r;

    // Print received data
    printf("Received Data =  0b");
    for(int i=7; i>=0; i--){
        printf("%d", (data_rx >> i) & 0x1);
    }
    printf("\n\n");

    // Compute check bits
    int C0 = P1_r ^ X3_r ^ X0_r ^ X2_r;
    int C1 = P2_r ^ X3_r ^ X0_r ^ X1_r;
    int C2 = P4_r ^ X2_r ^ X0_r ^ X1_r;
    int CHECK = (C2 << 2) | (C1 << 1) | C0;
    printf("Check bits = 0b");
    for(int i=2; i>=0; i--){
        printf("%d", (CHECK >> i) & 0x1);
    }
    printf("\n\n");

    // Check for errors
    int ERR = 0;
    if(P1_r != P1_d){
        ERR++;
    }
    if(P2_r != P2_d){
        ERR++;
    }
    if(P4_r != P4_d){
        ERR++;
    }
    if(ERR == 0){
        printf("No errors detected.\n\n");
        // Print decoded data
        printf("Decoded Data =   0b");
        printf("%d", (data_rx >> 4) & 0x1);
        printf("%d", (data_rx >> 2) & 0x1);
        printf("%d", (data_rx >> 1) & 0x1);
        printf("%d", data_rx & 0x1);
        printf("\n\n");
    }
    if(ERR == 1){
        printf("1 error detected!\n\n");
        int data_rx_c;
        data_rx_c = data_rx ^ (1 << (7-CHECK));
        // Print corrected data
        printf("Corrected Data = 0b");
        for(int i=7; i>=0; i--){
            printf("%d", (data_rx_c >> i) & 0x1);
        }
        printf("\n\n");
        // Print decoded data
        printf("Decoded Data =   0b");
        printf("%d", (data_rx >> 4) & 0x1);
        printf("%d", (data_rx >> 2) & 0x1);
        printf("%d", (data_rx >> 1) & 0x1);
        printf("%d", data_rx & 0x1);
        printf("\n\n");
    }
    if(ERR == 2){
        printf("2 errors detected!\n\n");
    }

}

// Archived code

/*
void main(){

    int code_type;
    char data_tx[7];
    char data_rx[7];
    int X0, X1, X2, X3;
    int P1, P2, P3;
    int C0, C1, C2;

    printf("\n");
    printf("Enter 0 for a single parity bit code, or 1 for (7,4) hamming code: ");
    scanf("%d", &code_type);
    printf("\n");

    if (code_type == 0){
        printf("Single parity bit code selected.\n\n");
    } else {
        printf("(7,4) hamming code selected.\n\n");
    }

    printf("Enter 7-bit transmitted data: ");
    scanf("%s", data_tx);
    printf("\n");
    printf("Enter 7-bit received data: ");
    scanf("%s", data_rx);
    printf("\n");

}*/