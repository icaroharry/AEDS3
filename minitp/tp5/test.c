#include <stdio.h>
#include <stdlib.h>

int btod(char *bin) {
    int dec = 0;
    int i;
    for(i = 0; i < 8; i++) { 
        if (bin[i] == '1') dec = dec * 2 + 1; 
        else if (bin[i] == '0') dec *= 2;
    } 
    return dec;
}
  
void printbin(int n) {
    int k = 0;
    int x;
    int l = 0;
    char a[8];
    for (k = 7; k >= 0; k--) {
        x = n >> k;
        if (x & 1)
            a[l] = '1';
        else
            a[l] = '0';
        l++;
    }
    a[8] = '\0';
    printf("%d\n", btod(a));
}

int main() {
    int i;
    unsigned char a;
    a = 255;
    printf("%d\n", a);
    a++;
    printf("%d\n", a);
    return 0;
}