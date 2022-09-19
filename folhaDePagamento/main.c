#include <stdio.h>
#include <string.h>

struct funcionario{
    char nome[52];//50 char
    char matricula[14];//12 char
    char endereco[67];//65 char
    char cpf[13];//11 char
    char cod_banco[5];//3 char
    char agencia[7];//5 char
    char conta[10];//8 char
    int valor_hora;
};

void pegarNome(struct funcionario *funcionario, char *line);
void pegarMatricula(struct funcionario *funcionario, char *line);
void pegarEndereco(struct funcionario *funcionario, char *line);
void pegarCPF(struct funcionario *funcionario, char *line);
void pegarCodigoBanco(struct funcionario *funcionario, char *line);
void pegarAgencia(struct funcionario *funcionario, char *line);
void pegarConta(struct funcionario *funcionario, char *line);

int main(){
    FILE *fp;
    long length;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;
    struct funcionario funcionario1;

    fp = fopen("Funcionarios.txt", "r");
    if (fp == NULL)
        printf("Error!");   

    for (int i=0; i<=3; i++){ 

        read = getline(&line, &len, fp);
        printf("%s", line); //PAULO EUSTAQUIO DUARTE PINTO    201210320811 Rua do Catete 231 apto 1002, Catete, CEP 20123-100     01129257869 001 01246 032123-7 120.00


        pegarNome(&funcionario1, line);
        pegarMatricula(&funcionario1, line);
        pegarEndereco(&funcionario1, line);
        pegarCPF(&funcionario1, line);
        pegarCodigoBanco(&funcionario1, line);
        pegarAgencia(&funcionario1, line);
        pegarConta(&funcionario1, line);

        printf("%s\n", funcionario1.nome);
        printf("%s\n", funcionario1.matricula);
        printf("%s\n", funcionario1.endereco);
        printf("%s\n", funcionario1.cpf);
        printf("%s\n", funcionario1.cod_banco);
        printf("%s\n", funcionario1.agencia);
        printf("%s\n", funcionario1.conta);
        printf("\n");
    };
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
void pegarEndereco(struct funcionario *funcionario, char *line){
    for (int i=62; i<=127; i++){ 
        funcionario->endereco[i-62] = line[i+2];
    };
    funcionario->endereco[66] = '\0';
};
void pegarCPF(struct funcionario *funcionario, char *line){
    for (int i=127; i<=138; i++){ 
        funcionario->cpf[i-127] = line[i+3];
    };
    funcionario->cpf[12] = '\0';
};
void pegarCodigoBanco(struct funcionario *funcionario, char *line){
    for (int i=138; i<=141; i++){ 
        funcionario->cod_banco[i-138] = line[i+4];
    };
    funcionario->cod_banco[13] = '\0';
};
void pegarAgencia(struct funcionario *funcionario, char *line){
    for (int i=141; i<=146; i++){ 
        funcionario->agencia[i-141] = line[i+5];
    };
    funcionario->agencia[6] = '\0';
};
void pegarConta(struct funcionario *funcionario, char *line){
    for (int i=146; i<=153; i++){ 
        funcionario->conta[i-146] = line[i+6];
    };
    funcionario->conta[9] = '\0';
};
