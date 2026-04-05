#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    int matricula;
    char nome[50];
    float salario;
    int data_nascimento; // formato YYYYMMDD
    int contratado; // 1 para contratado, 0 para demitido
    char cargo[50];
    int data_contratacao; // formato YYYYMMDD
    int data_demissao; // formato YYYYMMDD
    char motivo_demissao[100];
    _Bool ativo; // true para ativo, false para inativo
} Funcionario;

int main() {
    Funcionario f1;
    f1.id = 1;
    f1.matricula = 12345;
    strcpy(f1.nome, "João Silva");
    f1.salario = 3500.00;
    f1.data_nascimento = 19900101;
    f1.contratado = 1;
    strcpy(f1.cargo, "Analista de Sistemas");
    f1.data_contratacao = 20200101;
    f1.data_demissao = 0;
    strcpy(f1.motivo_demissao, "");
    f1.ativo = 1;

    printf("\n");
    f1.contratado = 1;
    strcpy(f1.cargo, "Analista de Sistemas");
    printf("ID: %d\n", f1.id);
    printf("Matrícula: %d\n", f1.matricula);
    printf("Nome: %s\n", f1.nome);
    printf("Salário: %.2f\n", f1.salario);
    printf("Data de Nascimento: %d\n", f1.data_nascimento);
    printf("Contratado: %s\n", f1.contratado ? "Sim" : "Não");
    printf("Cargo: %s\n", f1.cargo);
    printf("Ativo: %s\n", f1.ativo ? "Sim" : "Não");


    Funcionario f2;
    f2.id = 2;
    f2.matricula = 54321;
    strcpy(f2.nome, "Maria Santos");
    f2.salario = 4000.00;
    f2.data_nascimento = 19850515;
    f2.contratado = 1;
    strcpy(f2.cargo, "Gerente de Projetos");
    f2.data_contratacao = 20200101;
    f2.data_demissao = 0;
    strcpy(f2.motivo_demissao, "");
    f2.ativo = 1;

    printf("\n");
    f2.contratado = 2;
    strcpy(f2.cargo, "Gerente de Projetos");
    printf("ID: %d\n", f2.id);
    printf("Matrícula: %d\n", f2.matricula);
    printf("Nome: %s\n", f2.nome);
    printf("Salário: %.2f\n", f2.salario);
    printf("Data de Nascimento: %d\n", f2.data_nascimento);
    printf("Contratado: %s\n", f2.contratado ? "Sim" : "Não");
    printf("Cargo: %s\n", f2.cargo);
    printf("Ativo: %s\n", f2.ativo ? "Sim" : "Não");

    return 0;
}