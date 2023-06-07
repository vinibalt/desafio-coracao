#include <stdio.h>
#include <stdlib.h>

struct Professor
{
    int codigo;
    char sexo;
    int horasAula;
    float salarioBruto;
    float salarioLiquido;
    int desconto;
};

// struct Professor professor;
struct Professor professores[5];
// 15 por h/aula


void calcularSalarioF(struct Professor prof){

            if (prof.horasAula <= 70)
            {
                prof.desconto = 7;
                prof.salarioLiquido = prof.salarioBruto * 0.93;

               
            }
            else if (prof.horasAula > 70)
            {
                prof.desconto = 5;
                prof.salarioLiquido = prof.salarioBruto * 0.95;

               
            }
        }

int main()
{
    int i;
    float salF = 0, somaSalF = 0, salM = 0, somaSalM = 0;

    for (i = 0; i < 5; i++)
    {

        printf("\nDIGITE O CODIGO: \n");
        scanf("%d", &professores[i].codigo);

        printf("\nDIGITE O SEXO: \n");
        scanf(" %c", &professores[i].sexo);

        printf("DIGITE A QUANTIDADE DE HORAS AULA: \n");
        scanf("%d", &professores[i].horasAula);

        professores[i].salarioBruto = professores[i].horasAula * 15;
    }

    for (i = 0; i < 5; i++)
    {

        if (professores[i].sexo == 'f' || professores[i].sexo == 'F')
        {
            somaSalF += professores[i].salarioBruto;
            salF++;

          
            if (professores[i].horasAula <= 70)
            {
                professores[i].desconto = 7;
                professores[i].salarioLiquido = professores[i].salarioBruto * 0.93;
            }
            else if (professores[i].horasAula > 70)
            {
                professores[i].desconto = 5;
                professores[i].salarioLiquido = professores[i].salarioBruto * 0.95;
            }
        }
        else if (professores[i].sexo == 'm' || professores[i].sexo == 'M')
        {
            somaSalM += professores[i].salarioBruto;
            salM++;
            if (professores[i].horasAula <= 70)
            {
                professores[i].desconto = 10;
                professores[i].salarioLiquido = professores[i].salarioBruto * 0.90;
            }
            else if (professores[i].horasAula > 70)
            {
                professores[i].desconto = 8;
                professores[i].salarioLiquido = professores[i].salarioBruto * 0.92;
            }
        }
    }

    printf("LISTAGEM PROFESSORES\n\n");
    for (i = 0; i < 5; i++)
    {
        printf("CODIGO: %d          SALARIO BRUTO: %.2lf        DESCONTO: %d     SALARIO LIQUIDO: %.2lf        \n\n\n", professores[i].codigo, professores[i].salarioBruto, professores[i].desconto, professores[i].salarioLiquido);
    }

    printf("MEDIA DOS SALARIOS BRUTOS DOS PROFESSORES DO SEXO MASCULINO: R$%.2lf\n", somaSalM / salM);
    printf("MEDIA DOS SALARIOS BRUTOS DOS PROFESSORES DO SEXO FEMININO: R$%.2lf\n", somaSalF / salF);
}