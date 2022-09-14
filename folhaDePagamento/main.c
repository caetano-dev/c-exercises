#include <stdio.h>
#include <string.h>
/*PAULO EUSTAQUIO DUARTE PINTO   201210320811 Rua do Catete 231 apto 1002, Catete, CEP 20123-100    01129257869 001 01246 032123-7 120.00*/
struct funcionario{
    char nome[50];
    char matricula[12];
    char endereco[65];
    char cpf[11];
    char cod_banco[3];
    char agencia[5];
    char conta[8];
    int valor_hora;
};

int main(){
    FILE *fp;
    long length;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;
    struct funcionario funcionario1;

    fp = fopen("Funcionarios.txt", "r");
    if (fp == NULL)
    {
        printf("Error!");   
    }
    /*fscanf(fptr, "%s", &funcionario1.nome[50]);*/

    read = getline(&line, &len, fp);
    /*printf("%s", line);*/
    memcpy(funcionario1.nome, line, 50);
    printf("%s", &funcionario1.nome);
    memcpy(funcionario1.matricula, line, 12);
    printf("%s", &funcionario1.matricula);

    /*read = getline(&line, &len, fp);*/
    /*printf("%s", line);*/

    fclose(fp);

    return 0;
}
