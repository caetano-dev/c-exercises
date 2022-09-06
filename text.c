#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int main (){
    FILE *filePointer;

    int numberOfLines=0;
    int numberOfCharacters=0;
    int numberOfPrintable=0;

    char character;
    char fileName[18];

    scanf("%s", fileName);

    if (!(filePointer = fopen(fileName, "r"))){
        printf("Erro no arquivo %s\n", fileName);
        return 0;
    }

    for (character = getc(filePointer); character != EOF; character = getc(filePointer)){
        if (character == '\n'){
            numberOfLines++;
        }
        if (isprint(character)){
            numberOfPrintable++;
        }
        numberOfCharacters++;
    }

    fclose(filePointer);

    printf("%d\n", numberOfCharacters);
    printf("%d\n", numberOfPrintable);
    printf("%d\n", numberOfLines);

    return 0;
}
