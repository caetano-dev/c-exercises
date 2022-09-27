#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct
{
    char nome[51];
    char matricula[13];
    char endereco[66];
    char cpf[12];
    char cod_banco[4];
    char agencia[6];
    char conta[9];
    float val_hora;
}funcionario;

typedef struct
{
    char mat[13];
    int hor_trab;
}pagamentos;

funcionario readFuncs(FILE * arq)
{
    funcionario f;
    
    for(int i = 0; i < 50; i++)
    {
        f.nome[i] = getc(arq);
    }
    f.nome[50] = '\0';
    
    getc(arq);
    
    for(int i = 0; i < 12; i++)
    {
        f.matricula[i] = getc(arq);
    }
    
    f.matricula[12] = '\0';
    
    getc(arq);
    
    for(int i = 0; i < 65; i++)
    {
        f.endereco[i] = getc(arq);
    }
    
    getc(arq);
    
    for(int i = 0; i < 11; i++)
    {
        f.cpf[i] = getc(arq);
    }
    f.cpf[11] = '\0';
    
    getc(arq);
    
        for(int i = 0; i < 3; i++)
    {
        f.cod_banco[i] = getc(arq);
    }
    f.cod_banco[3] = '\0';
        
    getc(arq);
    
    fgets(f.agencia, 6, arq);
    
    getc(arq);

    fgets(f.conta, 9, arq);
    getc(arq);
    
    fscanf(arq, "%f", &f.val_hora);
    getc(arq);
   
    
    return f;
}

pagamentos readPay(FILE *pags)
{
    pagamentos p;
    
    for(int i = 0; i < 12; i++)
    {
        p.mat[i] = getc(pags);
    }
    
    p.mat[12] = '\0';
    
    getc(pags);
    
    int payph;
    
    fscanf(pags, "%d", &payph);
    
    p.hor_trab = payph;
    
    getc(pags);
    
    return p;
}

int main()
{
    funcionario funcs[10];
    pagamentos pags[10];
    
    FILE * arquivo;
    if(!(arquivo = fopen("Funcionarios.txt","r")))
    {
        fprintf(stderr,"Erro: arquivo inexistente\n");
        return -1;
    }
    
    FILE * pagaments;
    if(!(pagaments = fopen("Novembro.txt","r")))
    {
        fprintf(stderr,"Erro: arquivo inexistente\n");
        return -1;
    }
    
    for (int x = 0; x < 10; x++)
    {
        funcs[x] = readFuncs(arquivo);
        pags[x] = readPay(pagaments);
    }
    
    fclose(arquivo);
    fclose(pagaments);
    
    for (int g = 0; g < 9; g++)
    {
        for (int i = 0; i < 9; i++)
        {
            if (strcmp(funcs[i].nome, funcs[i+1].nome) > 0)
            {
                funcionario aux = funcs[i];
                funcs[i] = funcs[i+1];
                funcs[i+1] = aux;
            }
        }
    }
    
    for (int g = 0; g < 10; g++)
    {
        for (int i = 0; i < 10; i++)
        {
            if (strcmp(funcs[i].matricula, pags[g].mat) == 0)
            {
                funcs[i].val_hora = funcs[i].val_hora * pags[g].hor_trab;
            }
        }
    }
    
    
    for (int z = 0; z < 10; z++)
    {
    printf("%s|%s|%s|%.5s|%s|%.2f\n", funcs[z].nome, funcs[z].cpf, funcs[z].cod_banco, funcs[z].agencia, funcs[z].conta, funcs[z].val_hora);
    }
    
    return 0;
}
