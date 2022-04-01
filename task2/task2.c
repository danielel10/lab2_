#include <stdlib.h>
#include <stdio.h>
#include <string.h>



char censor(char c) {
    if(c == '!')
        return '*';
    else
        return c;
}

char* map(char *array, int array_length, char (*f) (char)){
    char* mapped_array = (char*)(malloc(array_length*sizeof(char)));
    for (int i = 0; i < array_length; ++i) {
        *(mapped_array + i) = f(*(array + i));
    }
    return mapped_array;
}

char encrypt(char c) {
    if (c >= 41 && c <= 122) {
        c = c + 2;
    }
    return c;
}




int main(int argc, char **argv){
    char arr1[] = {'H','e','y','!'};
    char* arr2 = map(arr1, 4, encrypt);
    printf("%s\n", arr2);
    free(arr2);
}