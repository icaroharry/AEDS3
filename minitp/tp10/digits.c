#include <stdio.h>
#include <stdlib.h>

char digits[100003];
char stack[200003];
int begin, end;
int inc, dec;

void rem_end() {
    end--;
}

void rem_beg() {
    begin++;
}

void insert(char c) {
    stack[end] = c;
    end++;
}

void remove_digits(int n, int d) {
    int i, j, rem = 0;
    char c;
    inc = -1; dec = -1;
    begin = 0; end = 0;
    
    for(i = 0; i < n; i++) {
        c = digits[i];
        //printf("char c%c\n", c);
        if(begin == end) {
            insert(c);
        } else {
            if(c > stack[end - 1] && (inc || inc == -1)) {
                //printf("1\n");
                insert(c);
                inc = 1;
                dec = 0;
            } else if(c > stack[end - 1] && dec == 1) {
                if(rem < d) { 
                    //printf("2\n");
                    while(c > stack[end - 1] && begin != end - 1 && rem < d && c <= stack[begin]) {
                        rem_end();
                        rem++;
                        if(c >= stack[end - 1]) {
                            inc = 1;
                            dec = 0;
                        } else if(c < stack[end - 1]) {
                            inc = 0;
                            dec = 1;                        
                        }
                    }
                    //printf("stack end%c\n", stack[end - 1]);
                }
                insert(c);
            } else if(c < stack[end - 1] && inc == 1) {
                if(rem < d) {
                    //printf("3\n");
                    while(c < stack[end - 1] && begin != end - 1 && rem < d && c >= stack[begin]) {
                        rem_beg();
                        rem++;
                        if(c >= stack[end - 1]) {
                            inc = 1;
                            dec = 0;

                        } else if( c < stack[end - 1]) {
                            inc = 0;
                            dec = 1;                        
                        }
                    }
                    //printf("stack end%c\n", stack[end - 1]);
                }
                insert(c);
                
            } else if(c < stack[end - 1] && (dec || dec == -1)) {
                //printf("4\n");

                insert(c);
                inc = 0;
                dec = 1;
            } else if(c == stack[end - 1]) {
                //printf("5\n");
                insert(c);
            }
        }
        
    }
    if(rem < d) {
        for(j = rem; j < d; j++ ) {
            if(dec) {
                rem_end();
            } else {
                rem_beg();
            }
        }
    }
}

int main() {
    int n, d, i, j;
    char c;

    while(1) {
        
        scanf("%d %d\n", &n, &d);
        if(n == 0 && d == 0) {
            break;
        }

        for(i = 0; i < n; i++)
            scanf("%c", &digits[i]);
        
        
        remove_digits(n, d);
        for(j = begin; j <end; j++) {
            printf("%c", stack[j]);
        }
        printf("\n");

        getchar();
    }
    
    
    return 0;
}