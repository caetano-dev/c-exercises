#include <stdio.h>
#define MAX_LIMIT 1024

int main () {
   enum estado{ dentroDaPalavra = 0, foraDaPalavra = 1};
   char caractere;
   int i, estado, numeroDeCaracteres = 0;
   int count = 1;

   while((caractere = getchar()) != '\n' && numeroDeCaracteres <= MAX_LIMIT){
      numeroDeCaracteres++;
      switch(caractere){
         case '.':
         case ';':
         case ':':
         case ',':
         case ' ':
            if (estado != foraDaPalavra){
               estado = foraDaPalavra;}
            break;
         default:
            if (estado != dentroDaPalavra){
               estado = dentroDaPalavra;
               count++;
            }
            break;
      }
   }
   printf("%d", count);
   return(0);
}
