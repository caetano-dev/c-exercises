#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct image{
    char magicNumber[4];
    char description[100];
    int max;
    int columns;
    int lines;
} image;

void closeFile(FILE *filePointer);
void getHeaders(FILE *filePointer);
unsigned int* readImage(char fileName);
void printImage(unsigned int* bitmap);

int main (){
    char hex[5];
    char fileName[18];
    unsigned int* image = readImage(*fileName);
    printImage(image);
    free(image);
}

unsigned int* readImage(char fileName){
    FILE *filePointer = NULL;
    scanf("%s", &fileName);

    if (!(filePointer = fopen(&fileName, "rt"))){
        printf("Erro: arquivo inexistente\n");
        exit(0);
    }
    getHeaders(filePointer);

    if(fscanf(filePointer,"%d %d",&image.columns, &image.lines)!=2){
      perror("Aquivo corrompido.\n");
   }

    if(fscanf(filePointer,"%d",&image.max)!=1){
        perror("Aquivo corrompido.\n");
    }

    unsigned int *bitmap = malloc(image.columns*image.lines*4);
    unsigned int *iterator = bitmap;

    for (int i = 0; i < image.lines; i++){
        for (int j = 0; j < image.columns; j++, iterator++){
            fscanf(filePointer,"%u",iterator);
        }
    }
    closeFile(filePointer);
    return bitmap;
}

void getHeaders(FILE *filePointer){
    fgets(image.magicNumber, 4, filePointer);
    fgets(image.description, 100, filePointer);
}

void printImage(unsigned int* bitmap){
    for (int i = 0; i < image.lines; i++){
        for (int j = 0; j < image.columns; j++, bitmap++){
            if(j<image.columns-1){
                printf("%3X ", *bitmap);
            }
            else{
                printf("%3X", *bitmap);
            }
        }
        if(i != image.lines-1){
            printf("\n");
        }
    }
}

void closeFile(FILE *filePointer){
    if (fclose (filePointer)==EOF){
        perror("Arquivo não fecha.\n");
        exit(1);
    }
}
