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
}
  
int main() {
    unsigned char accu = 0, pc = 0;
    char op[9];
    unsigned char instruction, address;
    unsigned char memory[32];
    int i = 0;
    while(scanf("%s", op) != EOF) {
        memory[i] = btod(op);
        i++;
        if(i == 32) {
            pc = 0;
            i = 0;
            accu = 0;
            instruction = 0;
            address = 0;
            while(instruction != HLT && pc < 32) {
                instruction = memory[pc];
                instruction >>= 5;
                address = memory[pc];
                address &= 0x1F;
                pc++;
                switch(instruction) {
                    case STA:
                        memory[address] = accu;
                        break;
                    case LDA:
                        accu = memory[address];
                        break;
                    case BEQ:
                        if(accu == 0) {
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
}