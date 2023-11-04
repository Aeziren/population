#include <cs50.h>
#include <stdio.h>
#include <math.h>

int get_pop_ini();
int get_pop_final();

int main(void)      // programa principal
{
    int populacao_i = get_pop_ini();
    int populacao_f = get_pop_final(populacao_i);
    if (populacao_i == populacao_f)
    {
        printf("Years: 0\n");    
        return 0;
    }
    int anos = 0;
    float nascidos = 0;
    float falecidos = 0;
    while (populacao_i < populacao_f)    // logica
    {
        nascidos = populacao_i / 3;
        falecidos = populacao_i / 4;
        populacao_i = populacao_i + (nascidos - falecidos);
        anos++;
    }
    printf("Years: %i\n", anos);  // saida do resultado
}

int get_pop_ini(void) // funcao para pegar populacao inicial
{
    int pop_i;
    do
    {
        pop_i = get_int("População inicial: ");
    }
    while (pop_i < 9);
    return pop_i;
}

int get_pop_final(pop_i) // funcao para pegar populacao final
{
    int pop_f;
    do
    {
        pop_f = get_int("População final: ");
    }
    while (pop_f < pop_i);
    return pop_f;
}