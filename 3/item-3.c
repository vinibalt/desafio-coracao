

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Aluno {
    char nome[100];
    int numeroMatricula;
    int telefone;
    char sexo;
    int frequencia;
    float notaA1;
    float notaA2;
    float media;
    char mencao[10];
};

int main() {
    struct Aluno alunos[5];
    int i, alunosAprovados = 0, alunosReprovados = 0, alunosRepFreq = 0;
    float maiorMedia = 0, menorMedia = 10, mediaTurma = 0;
    int indiceMaiorMedia;

    for (i = 0; i < 5; i++) {
        printf("DIGITE O NOME DO ALUNO: ");
        scanf("%s", alunos[i].nome);

        printf("DIGITE O NUMERO DE MATRICULA: ");
        scanf("%d", &alunos[i].numeroMatricula);

        printf("DIGITE O NUMERO DE TELEFONE: ");
        scanf("%d", &alunos[i].telefone);

        printf("DIGITE O SEXO [M] OU [F]: ");
        scanf(" %c", &alunos[i].sexo);

        printf("DIGITE O NUMERO DE AULAS FREQUENTADAS: ");
        scanf("%d", &alunos[i].frequencia);

        printf("NOTA DA A1: ");
        scanf("%f", &alunos[i].notaA1);

        printf("NOTA DA A2: ");
        scanf("%f", &alunos[i].notaA2);

        alunos[i].media = (alunos[i].notaA1 + alunos[i].notaA2) / 2;

        if (alunos[i].media >= 6.0 && alunos[i].frequencia >= 60) {
            strcpy(alunos[i].mencao, "APROVADO");
            alunosAprovados++;
        } else {
            strcpy(alunos[i].mencao, "REPROVADO");
            alunosReprovados++;
        }

        if (alunos[i].frequencia < 60){
            alunosRepFreq++;
        }

        if (alunos[i].media > maiorMedia) {
            maiorMedia = alunos[i].media;
            indiceMaiorMedia = i;
        }

        if (alunos[i].media < menorMedia) {
            menorMedia = alunos[i].media;
        }

        mediaTurma += alunos[i].media;
    }

    mediaTurma /= 5;

    printf("\nRELATÓRIO DOS ALUNOS\n");
    for (i = 0; i < 5; i++) {
        printf("NOME: %s\n", alunos[i].nome);
        printf("MATRICULA: %d\n", alunos[i].numeroMatricula);
        printf("FREQUENCIA: %d aulas\n", alunos[i].frequencia);
        printf("MEDIA FINAL: %.2f\n", alunos[i].media);
        printf("MENCAO: %s\n", alunos[i].mencao);
        printf("\n");
    }

    printf("MAIOR MEDIA FINAL: %.2f (aluno: %s)\n", maiorMedia, alunos[indiceMaiorMedia].nome);
    printf("MENOR MEDIA FINAL: %.2f\n", menorMedia);
    printf("MEDIA DOS ALUNOS: %.2f\n", mediaTurma);
    printf("TOTAL DE ALUNOS APROVADOS: %d\n", alunosAprovados);
    printf("TOTAL DE ALUNOS REPROVADOS: %d\n", alunosReprovados);

    float percentualReprovadosFrequencia = (float)alunosRepFreq / 5 * 100;
    printf("PORCENTAGEM DE ALUNOS REPROVADOS POR FREQUENCIA: %.2f%%\n", percentualReprovadosFrequencia);

    return 0;
}
