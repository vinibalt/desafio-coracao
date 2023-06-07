

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_ALUNOS 5

struct Aluno {
    char nome[100];
    int matricula;
    int idade;
    char sexo;
    float notaA1;
    float notaA2;
    int frequencia;
};

struct Aluno alunos[MAX_ALUNOS];
int numAlunos = 0;

void cadastrarAluno() {
    if (numAlunos >= MAX_ALUNOS) {
        printf("VOCE CADASTROU O LIMITE MAXIMO DE ALUNOS!\n");
        return;
    }

    struct Aluno novoAluno;

    printf("DIGITE O NOME DO ALUNO: ");
    scanf("%s", novoAluno.nome);

    printf("DIGITE A MATRILCULA: ");
    scanf("%d", &novoAluno.matricula);

    printf("DIGITE A IDADE DO ALUNO: ");
    scanf("%d", &novoAluno.idade);

    printf("DIGITE O SEXO DO ALUNO [M] OU [F]: ");
    scanf(" %c", &novoAluno.sexo);

    printf("NOTA DA A1: ");
    scanf("%f", &novoAluno.notaA1);

    printf("NOTA DA A2: ");
    scanf("%f", &novoAluno.notaA2);

    printf("DIGITE A QUANTIDADE DE AULAS FREQUENTADAS: ");
    scanf("%d", &novoAluno.frequencia);

    alunos[numAlunos] = novoAluno;
    numAlunos++;

    printf("ALUNO CADASTRADO COM SUCESSO!\n");
}

void consultarAlunoPorMatricula() {
    int matricula;
    printf("DIGITE O NUMERO DA MATRICULA DO ALUNO: ");
    scanf("%d", &matricula);

    bool encontrado = false;
    for (int i = 0; i < numAlunos; i++) {
        if (alunos[i].matricula == matricula) {
            printf("DADOS DO ALUNO:\n");
            printf("NOME: %s\n", alunos[i].nome);
            printf("MATRICULA: %d\n", alunos[i].matricula);
            printf("IDADE: %d\n", alunos[i].idade);
            printf("SEXO: %c\n", alunos[i].sexo);
            printf("NOTA DA A1: %.2f\n", alunos[i].notaA1);
            printf("NOTA DA A2: %.2f\n", alunos[i].notaA2);
            printf("FREQUENCIA: %d\n", alunos[i].frequencia);
            encontrado = true;
            break;
        }
    }

    if (!encontrado) {
        printf("ALUNO NAO ENCONTRADO!\n");
    }
}

void consultarAlunoPorNome() {
    char nome[100];
    printf("DIGITE O NOME DO ALUNO: ");
    scanf("%s", nome);

    bool encontrado = false;
    for (int i = 0; i < numAlunos; i++) {
        if (strcmp(alunos[i].nome, nome) == 0) {
            printf("DADOS DO ALUNO:\n");
            printf("NOME %s\n", alunos[i].nome);
            printf("MATRICULA: %d\n", alunos[i].matricula);
            printf("IDADE: %d\n", alunos[i].idade);
            printf("SEXO: %c\n", alunos[i].sexo);
            printf("NOTA DA A1: %.2f\n", alunos[i].notaA1);
            printf("NOTA DA A2: %.2f\n", alunos[i].notaA2);
            printf("FREQUENCIA: %d\n", alunos[i].frequencia);
            encontrado = true;
            break;
        }
    }

    if (!encontrado) {
        printf("ALUNO NAO ENCONTRADO!\n");
    }
}

bool verificarSexo(char sexo) {
    return (sexo == 'M' || sexo == 'F');
}

float calcularMedia(float notaA1, float notaA2) {
    return (notaA1 + notaA2) / 2;
}

bool verificarAprovacao(float media, int frequencia) {
    return (media >= 6.0 && frequencia >= 60);
}

float calcularPercentualReprovados() {
    int numReprovados = 0;
    for (int i = 0; i < numAlunos; i++) {
        if (!verificarAprovacao(calcularMedia(alunos[i].notaA1, alunos[i].notaA2), alunos[i].frequencia)) {
            numReprovados++;
        }
    }

    return (float)numReprovados / numAlunos * 100;
}

void escreverDadosCalculados() {
    float maiorMedia = 0.0;

    for (int i = 0; i < numAlunos; i++) {
        float media = calcularMedia(alunos[i].notaA1, alunos[i].notaA2);
        if (media > maiorMedia) {
            maiorMedia = media;
        }
    }

    float percentualReprovados = calcularPercentualReprovados();

    printf("MAIOR MEDIA: %.2f\n", maiorMedia);
    printf("PORCENTAGEM DE ALUNOS REPROVADOS: %.2f%%\n", percentualReprovados);
}

int main() {
    int opcao;

    do {
        printf("\nMENU PRINCIPAL\n");
        printf("1 - CADASTRAR ALUNO\n");
        printf("2 - CONSULTAR DADOS DE ALUNO\n");
        printf("3 - SAIR\n");
        printf("DIGITE O NUMERO DA OPCAO DESEJADA: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarAluno();
                break;
            case 2: {
                int subOpcao;
                do {
                    printf("\nCONSULTAR DADOS DOS ALUNOS\n");
                    printf("1 - CONSULTAR ALUNO PELO NUMERO DE MATRICULA\n");
                    printf("2 - CONSULTAR ALUNO PELO NOME\n");
                    printf("3 - VOLTAR AO MENU PRINCIPAL\n");
                    printf("DIGITE O NUMERO DA OPCAO DESEJADA: ");
                    scanf("%d", &subOpcao);

                    switch (subOpcao) {
                        case 1:
                            consultarAlunoPorMatricula();
                            break;
                        case 2:
                            consultarAlunoPorNome();
                            break;
                        case 3:
                            break;
                        default:
                            printf("OPCAO INVALIDA!\n");
                            break;
                    }
                } while (subOpcao != 3);
                break;
            }
            case 3:
                break;
            default:
                printf("OPCAO INVALIDA!\n");
                break;
        }
    } while (opcao != 3);

    escreverDadosCalculados();

    return 0;
}
