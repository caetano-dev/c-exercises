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
void pegarCampos(struct funcionario *funcionario, char *line);
void imprimirTabela(struct funcionario *funcionario);

int main(){
    FILE *fp;
    long length;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;
    struct funcionario funcionario1;
    struct funcionario funcionario2;
    struct funcionario funcionario3;
    struct funcionario funcionario4;
    struct funcionario funcionario5;
    struct funcionario funcionario6;
    struct funcionario funcionario7;
    struct funcionario funcionario8;
    struct funcionario funcionario9;
    struct funcionario funcionario10;

    fp = fopen("Funcionarios.txt", "r");
    if (fp == NULL)
        printf("Error!");   

        getline(&line, &len, fp);
        pegarCampos(&funcionario1, line);
        getline(&line, &len, fp);
        pegarCampos(&funcionario2, line);
        getline(&line, &len, fp);
        pegarCampos(&funcionario3, line);
        getline(&line, &len, fp);
        pegarCampos(&funcionario4, line);
        getline(&line, &len, fp);
        pegarCampos(&funcionario5, line);
        getline(&line, &len, fp);
        pegarCampos(&funcionario6, line);
        getline(&line, &len, fp);
        pegarCampos(&funcionario7, line);
        getline(&line, &len, fp);
        pegarCampos(&funcionario8, line);
        getline(&line, &len, fp);
        pegarCampos(&funcionario9, line);
        getline(&line, &len, fp);
        pegarCampos(&funcionario10, line);

        imprimirTabela(&funcionario2);
        imprimirTabela(&funcionario3);
        imprimirTabela(&funcionario4);
        imprimirTabela(&funcionario5);
        imprimirTabela(&funcionario6);
        imprimirTabela(&funcionario7);
        imprimirTabela(&funcionario8);
        imprimirTabela(&funcionario9);
        imprimirTabela(&funcionario10);

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
/*void pegarValorHora(struct funcionario *funcionario, char *line){*/
    /*for (int i=153; i<=159; i++){ */
        /*funcionario->conta[i-153] = line[i+7];*/
    /*};*/
    /*funcionario->valor_hora[7] = '\0';*/
/*};*/

void pegarCampos(struct funcionario *funcionario, char *line){
    pegarNome(funcionario, line);
    pegarMatricula(funcionario, line);
    pegarEndereco(funcionario, line);
    pegarCPF(funcionario, line);
    pegarCodigoBanco(funcionario, line);
    pegarAgencia(funcionario, line);
    pegarConta(funcionario, line);
    /*pegarValorHora(&funcionario[i], line);*/
}
void imprimirTabela(struct funcionario *funcionario){
    printf("%s", funcionario->nome);
    printf("|%s", funcionario->matricula);
    printf("|%s", funcionario->endereco);
    printf("|%s", funcionario->cpf);
    printf("|%s", funcionario->cod_banco);
    printf("|%s", funcionario->agencia);
    printf("|%s", funcionario->conta);
    printf("|%d", funcionario->valor_hora);
    printf("\n");
}

