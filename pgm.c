#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (){
    FILE *filePointer;
    char hex[5];

    struct image{
        char magicNumber[4];
        char description[100];
        int max;
        int columns;
        int lines;
    } image;

    char fileName[18];
    scanf("%s", fileName);

    if (!(filePointer = fopen(fileName, "rt"))){
        printf("Erro: arquivo inexistente\n");
        return 0;

    }

    fgets(image.magicNumber, 4, filePointer);
    fgets(image.description, 100, filePointer);

    if(fscanf(filePointer,"%d %d",&image.columns, &image.lines)!=2){
      perror("Aquivo corrompido.\n");
      return -4;
   }

    if(fscanf(filePointer,"%d",&image.max)!=1){
        perror("Aquivo corrompido.\n");
      return -4;
        return -4;
    }

    unsigned int * bitmap = malloc(image.columns*image.lines*4);
    unsigned int *iterator = bitmap;

    for (int i = 0; i < image.lines; i++){
        for (int j = 0; j < image.columns; j++, iterator++){
            fscanf(filePointer,"%u",iterator);
        }
    }

    if (fclose (filePointer)==EOF){
        perror("Arquivo não fecha.\n");
        exit(1);
    };

    for (int i = 0; i < image.lines; i++){
        for (int j = 0; j < image.columns; j++, bitmap++){
            if(j==image.lines){
                sprintf(hex,"%3X", *bitmap);
                printf("%s", hex);
            }
            else{
                sprintf(hex,"%3X ", *bitmap);
                printf("%s", hex);
            }
        }
        printf("\n");
    }
}
