#include <stdio.h>
#include <stdlib.h>
#include <string.h>
  
#define STA 0x00
#define LDA 0x01
#define BEQ 0x02
#define NOP 0x03
#define DEC 0x04
#define INC 0x05
#define JMP 0x06
#define HLT 0x07
  
  
int btod(char *bin) {
    unsigned char dec = 0;
    int i;
    for(i = 0; i < 8; i++) { 
        if (bin[i] == '1') dec = dec * 2 + 1; 
        else if (bin[i] == '0') dec *= 2;
    } 
    return dec;
}
  
void printbin(unsigned char n) {
    int k = 0;
    unsigned char x;
    for (k = 7; k >= 0; k--) {
        x = n >> k;
        if (x & 1)
            printf("1");
        else
            printf("0");
    }
    if(!feof(stdin)) {
        printf("\n");
    }
}
  
int main() {
    unsigned char accu, pc;
    char op[9];
    unsigned char instruction, address;
    unsigned char memory[32];
    int i = 0;
    while(scanf("%s", op) != EOF) {
        memory[i] = btod(op);
        i++;
        if(i == 32) {
            i = 0;
            pc = 0x00;
            accu = 0x00;
            instruction = 0x00;
            address = 0x00;
            while(instruction != HLT) {
                instruction = memory[pc];
                instruction >>= 0x05;
                address = memory[pc];
                address &= 0x1F;
                pc++;
                if(pc == 32) {
                    pc = 0;
                }
                switch(instruction) {
                    case STA:
                        memory[address] = accu;
                        break;
                    case LDA:
                        accu = memory[address];
                        break;
                    case BEQ:
                        if(accu == 0x00) {
                            pc = address;
                        }
                        break;
                    case NOP:
                        break;
                    case DEC:
                        accu--;
                        break;
                    case INC:
                        accu++;
                        break;
                    case JMP:
                        pc = address;
                        break;
                    case HLT:
                        printbin(accu);
                        break;
                }
            }
        }
        getchar();
    }
    return 0;
}