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
    char valor_hora[7];
};

void pegarNome(struct funcionario *funcionario, char *line);
void pegarMatricula(struct funcionario *funcionario, char *line);
void pegarEndereco(struct funcionario *funcionario, char *line);
void pegarCPF(struct funcionario *funcionario, char *line);
void pegarCodigoBanco(struct funcionario *funcionario, char *line);
void pegarAgencia(struct funcionario *funcionario, char *line);
void pegarConta(struct funcionario *funcionario, char *line);
void pegarValorHora(struct funcionario *funcionario, char *line);
void pegarCampos(struct funcionario *funcionario, char *line);
void imprimirTabela(struct funcionario *funcionario);

int main(){
    FILE *fp;
    long length;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;
    struct funcionario arrayFuncionario[10];

    fp = fopen("Funcionarios.txt", "r");
    if (fp == NULL)
        printf("Error!");   

    for (int i=0; i<=9;i++){
        getline(&line, &len, fp);
        pegarCampos(&arrayFuncionario[i], line);
}
    fclose(fp);
    for (int i=0; i<=9;i++){
        imprimirTabela(&arrayFuncionario[i]);
    }

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
    funcionario->cod_banco[4] = '\0';
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
void pegarValorHora(struct funcionario *funcionario, char *line){
    for (int i=154; i!=159; i++){
        funcionario->valor_hora[i-154] = line[i+7];
    };
    funcionario->valor_hora[6] = '\0';
};

void pegarCampos(struct funcionario *funcionario, char *line){
    pegarNome(funcionario, line);
    pegarMatricula(funcionario, line);
    pegarEndereco(funcionario, line);
    pegarCPF(funcionario, line);
    pegarCodigoBanco(funcionario, line);
    pegarAgencia(funcionario, line);
    pegarConta(funcionario, line);
    pegarValorHora(funcionario, line);
};
void imprimirTabela(struct funcionario *funcionario){
    printf("%s", funcionario->nome);
    printf("|%s", funcionario->matricula);
    printf("|%s", funcionario->endereco);
    printf("|%s", funcionario->cpf);
    printf("|%s", funcionario->cod_banco);
    printf("|%s", funcionario->agencia);
    printf("|%s", funcionario->conta);
    printf("|%s", funcionario->valor_hora);
    printf("\n");
};
