#include <string.h>
#include <stdio.h>
#define MAX_LIMIT 1024

int main () {
   char string[MAX_LIMIT];
   fgets(string, MAX_LIMIT, stdin);
   int count = 0;
   const char s[2] = " ";
   char *token;
   token = strtok(string, s);
   while( token != NULL ) {
      count++;
      token = strtok(NULL, s);
   }
   printf("%d", count);
   return(0);
}
