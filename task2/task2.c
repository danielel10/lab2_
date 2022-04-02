#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct fun_desc {
    char *name;
    char (*fun)(char);
};


char* map(char *array, int array_length, char (*f) (char)){
    char* mapped_array = (char*)(malloc(array_length*sizeof(char)));
    for (int i = 0; i < array_length; ++i) {
        *(mapped_array + i) = f(*(array + i));
    }
    return mapped_array;
}

char censor(char c) {
    if(c == '!')
        return '*';
    else
        return c;
}

char encrypt(char c) {
    if (c >= 41 && c <= 122) {
        c = c + 2;
    }
    return c;
}

char decrypt(char c) {
    if (c >= 41 && c <= 122) {
        c = c - 2;
    }
    return c;
}

char dprt(char c) {
    printf("%d\n",c);
    return c;
}

char cprt(char c) {
    if (c >= 41 && c <= 122)
        printf("%c\n", c);
    else
        printf("%c\n", '*');
    return c;
}

char my_get(char c) {
    c = (fgetc(stdin));
    if(c == '\n')
        c = '\0';
    return c;
}

char quit(char c) {
    if(c == 'q')
       exit(0);
    return c;
}

struct fun_desc menu[] = { { "Censor", censor }, { "Encrypt", encrypt }, { "Decrypt", decrypt },{ "Print dec", dprt },{ "Print string", cprt },{ "Get string", my_get },{ "Quit", quit }, { NULL, NULL }  };


int main(int argc, char **argv){
    int c;
    char carry[5] = {'\0','\0','\0','\0','\0'};
    while (1 != 0) {
        printf("please choose a function:\n");
        for (int i = 0; i < 7; ++i) {
            printf("%d) %s\n",i,menu[i].name);
        }
        printf("option: ");
        c = (fgetc(stdin)) - 48;
        fgetc(stdin);
        if (c < 0 || c > 6) {
            printf("Not within bounds");
            free(carry);
            return 0;
        }
        printf("Within bounds\n");
        char* carry = map(carry, 5, menu[c].fun);
        printf("DONE\n");

    }


}