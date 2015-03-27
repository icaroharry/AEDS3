#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int find_tag(char* text, char* tag, char* new_value) {
    int size_of_text = strlen(text);
    int size_of_tag = strlen(tag) - 1;
    int size_of_new_value = strlen(new_value) -1;
    char *aux_word = malloc(12 * sizeof(char));
    if(new_value[size_of_new_value] == '\n') {
        new_value[size_of_new_value] = '\0';
    }
    if(tag[size_of_tag] == '\n') {
        tag[size_of_tag] = '\0';
    }

    int bigger_size = 0, size = 0, print = 0;
    int i, j, k, l;
    for(i = 0; i < size_of_text; i++) {
        if(tolower(text[i]) != tolower(tag[0])) {
            printf("%c", text[i]);
        } else {
            print = 0;
            for (j = 0; j < size_of_tag; j++) {
                size = 0;
                k = 0;
                while(tolower(text[i + k]) == tolower(tag[j + k]) && (i+k) < size_of_text && (j + k) < size_of_tag) {
                    aux_word[k] = text[i+k];
                    size++;
                    k++;
                }
                aux_word[k] = '\0';
                if(size == size_of_tag) {
                    int ok = -1;
                    for(l = i; l >= 0; l--) {
                        if(text[l] == 62) {
                            if(print == 0) {
                                printf("%s", aux_word);
                                print = 1;
                            }
                            ok = -1;
                            break;
                        }
                        if(text[l] == 60) {
                            ok = 1;
                            break;
                        }
                    }
                    for(l = i; l < size_of_text; l++) {
                        
                        if(text[l] == 60) {
                            if(print == 0) {
                                printf("%s", aux_word);
                                print = 1;
                            }
                            ok = -1;
                            break;
                        }
                        if(text[l] == 62) {
                            if(ok != -1) {
                                printf("%s", new_value);
                                print = 1;
                                ok = -1;
                                break;
                            }
                        }
                    }
                    if(print == 0) {
                        printf("%s", aux_word);
                        print = 1;
                    }
                    i += size_of_tag - 1;
                } else {
                    if (print==0) {
                        printf("%c", text[i]);
                        print = 1;
                    }
                    size = 0;
                    k = 0;
                }
            }
        }
    }
    //printf("\n");
    free(aux_word);
}

int main() {
    char *original_tag = malloc(12 * sizeof(char));
    char *new_value = malloc(10 * sizeof(char));
    char *text = malloc(62 * sizeof(char));

    while(!feof(stdin)) {
        fgets(original_tag, 12, stdin);
        if(feof(stdin)) {
            break;
        } else {    
            fgets(new_value, 1002, stdin);
            if(feof(stdin)) {
                break;
            } else {    
                fgets(text, 52, stdin);
                find_tag(text, original_tag, new_value);
            }
        }
    }

    free(original_tag);
    free(new_value);
    free(text);
    return 0;
}