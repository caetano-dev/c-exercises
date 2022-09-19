#include <stdio.h>
#include <string.h>

struct funcionario{
    char nome[52];
    char matricula[14];
    char endereco[65];
    char cpf[11];
    char cod_banco[3];
    char agencia[5];
    char conta[8];
    int valor_hora;
};

void pegarNome(struct funcionario *funcionario, char *line);
void pegarMatricula(struct funcionario *funcionario, char *line);

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
    printf("%s", line); //PAULO EUSTAQUIO DUARTE PINTO    201210320811 Rua do Catete 231 apto 1002, Catete, CEP 20123-100     01129257869 001 01246 032123-7 120.00
    pegarNome(&funcionario1, line);
    pegarMatricula(&funcionario1, line);

    printf("%s\n", funcionario1.nome);
    printf("%s\n", funcionario1.matricula);

    fclose(fp);

    return 0;
}
void pegarNome(struct funcionario *funcionario, char *line){
    for (int i=0; i<=50; i++){ 
        funcionario->nome[i] = line[i];
    };
    funcionario->nome[51] = '\0';
};

void pegarMatricula(struct funcionario *funcionario, char *line){
    for (int i=50; i<=62; i++){ 
        funcionario->matricula[i-50] = line[i+1];
    };
    funcionario->matricula[13] = '\0';
};
