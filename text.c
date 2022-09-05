#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main (){

    FILE *filePointer;
    int lines;
    int characters;
    int pritable;
    char fileName[18]="";

    scanf("%s", &fileName[18]);
    if (!(filePointer = fopen(fileName[18], "rt"))){
        printf("Erro no arquivo %s\n", &fileName);
        exit(1);
    }

    while(fgets()
    fgets(image.magicNumber, 4, filePointer);
    /*fgets(image.description, 100, filePointer);*/

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
            if(j==0){
                sprintf(hex,"%X", *bitmap);
                printf("%s", hex);
            }
            else{
                sprintf(hex,"%3X", *bitmap);
                printf("%s", hex);
            }
        }
        printf("\n");
    }
}

