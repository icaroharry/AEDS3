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
    int dec = 0;
    int i;
    for(i = 0; i < 8; i++) { 
        if (bin[i] == '1') dec = dec * 2 + 1; 
        else if (bin[i] == '0') dec *= 2;
    } 
    return dec;
}

int main() {
    unsigned int accu = 0, pc = 0;
    char op[9];
    unsigned int instruction, adress;
    unsigned int memory[32] = { 0 };

    while(scanf("%8s\n", op) != EOF) {
        instruction = btod(op);
        instruction >>= 5;
        adress = btod(op);
        adress &= 0x1F;
        pc++;
        switch(instruction) {
            case STA:
                memory[adress] = accu;
                break;
            case LDA:
                accu = memory[adress];
                break;
            case BEQ:
                if(accu == 0) {
                    pc = adress;
                }
                break;
            case NOP:
                break;
            case DEC:
                if(accu > 0)
                    accu--;
                break;
            case INC:
                if(accu < 256)
                    accu++;
                break;
            case JMP:
                pc = adress;
                //pc++;
                break;
            case HLT:
                pc = 0;
                //accu = 0;
                break; 
        }

        printf("%d %d\n", instruction, adress);
        //scanf("%8s", op);
    }
        printf("accu%d\n", accu);
}