#include <stdio.h>

char * dtob(int dec, char bin[6]) {
    int i = 0;
    while(dec!=0){
        printf("%d\n",dec%2 );
        bin[i] = (dec % 2);
        dec = dec / 2;
        i++;
    }
    bin[5] = '\0';
    return bin;
}

int main() {
    int a = 15;
    char bagulho[6];
    char * vtnc = dtob(a, bagulho);
    printf("%s\n", bagulho);
    return 0;
}