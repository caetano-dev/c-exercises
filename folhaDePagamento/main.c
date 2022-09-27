#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct funcionario pegarValores(FILE *funcionariosPtr);
struct valores pegarPagamento(FILE *valoresPtr);

struct funcionario {
    char nome[51];
    char matricula[13];
    char endereco[66];
    char cpf[12];
    char codigoBancario[4];
    char agencia[6];
    char conta[9];
    float valorHora;
};

struct valores {
    char matricula[13];
    int horasTrabalhadas;
};

void imprimir(struct funcionario arrayFuncionarios[10]);

int main() {
    FILE *funcionariosPtr;
    FILE *valoresPtr;
    if(!(funcionariosPtr = fopen("Funcionarios.txt","r")) || !(valoresPtr = fopen("Novembro.txt","r")))
        printf("o arquivo não existe!");
    struct funcionario arrayFuncionarios[10];
    struct valores valores[10];
    for (int i = 0; i < 10; i++) {
        arrayFuncionarios[i] = pegarValores(funcionariosPtr);
        valores[i] = pegarPagamento(valoresPtr);
    }
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (strcmp(arrayFuncionarios[j].nome, arrayFuncionarios[j+1].nome) > 0) {
                struct funcionario a;
                a = arrayFuncionarios[j];
                arrayFuncionarios[j] = arrayFuncionarios[j+1];
                arrayFuncionarios[j+1] = a;
            }
        }
    }
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (strcmp(arrayFuncionarios[j].matricula, valores[i].matricula) == 0)
                arrayFuncionarios[j].valorHora = arrayFuncionarios[j].valorHora * valores[i].horasTrabalhadas;

        }
    }
    imprimir(arrayFuncionarios);
    fclose(funcionariosPtr);
    fclose(valoresPtr);
    return 0;
}
struct funcionario pegarValores(FILE *funcionariosPtr) {

    struct funcionario funcionarios;
    for(int i = 0; i < 50; i++) {
        funcionarios.nome[i] = getc(funcionariosPtr);
    }
    funcionarios.nome[50] = '\0';
    getc(funcionariosPtr);
    for(int i = 0; i < 12; i++)
        funcionarios.matricula[i] = getc(funcionariosPtr);

    funcionarios.matricula[12] = '\0';
    getc(funcionariosPtr);

    for(int i = 0; i < 65; i++)
        funcionarios.endereco[i] = getc(funcionariosPtr);

    getc(funcionariosPtr);

    for(int i = 0; i < 11; i++)
        funcionarios.cpf[i] = getc(funcionariosPtr);

    funcionarios.cpf[11] = '\0';
    getc(funcionariosPtr);

    for(int i = 0; i < 3; i++)
        funcionarios.codigoBancario[i] = getc(funcionariosPtr);

    funcionarios.codigoBancario[3] = '\0';
    getc(funcionariosPtr);
    fgets(funcionarios.agencia, 6, funcionariosPtr);
    getc(funcionariosPtr);
    fgets(funcionarios.conta, 9, funcionariosPtr);
    getc(funcionariosPtr);
    fscanf(funcionariosPtr, "%f", &funcionarios.valorHora);
    getc(funcionariosPtr);

    return funcionarios;
}

struct valores pegarPagamento(FILE *valoresPtr) {

    struct valores valores;
    for(int i = 0; i < 12; i++)
        valores.matricula[i] = getc(valoresPtr);

    valores.matricula[12] = '\0';
    getc(valoresPtr);
    int pagamentoPorHora;

    fscanf(valoresPtr, "%d", &pagamentoPorHora);
    valores.horasTrabalhadas = pagamentoPorHora;
    getc(valoresPtr);

    return valores;
}

void imprimir(struct funcionario arrayFuncionarios[10]){
    for (int i = 0; i < 10; i++)
        printf("%s|%s|%s|%.5s|%s|%.2f\n", arrayFuncionarios[i].nome, arrayFuncionarios[i].cpf, arrayFuncionarios[i].codigoBancario, arrayFuncionarios[i].agencia, arrayFuncionarios[i].conta, arrayFuncionarios[i].valorHora);
}
