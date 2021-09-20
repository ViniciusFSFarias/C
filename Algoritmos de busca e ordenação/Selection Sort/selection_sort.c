#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double ordenar_lista(long int lista[], long int tamanho);

int main()
{
    srand(time(NULL));

    long int tamanho = 100000;
    long int lista[tamanho];
    int i;
    int j;
    double tempo_total;
    double tempo_de_execucao;

    //printf("A lista desordenada eh: \n");
    for(i = 0; i < tamanho; ++i)
    {
        lista[i] = rand() % 100 + 1;
        //printf(" [ %d ] ", lista[i]);
    }

    printf("\nA lista ordenada eh:\n");
    tempo_total = ordenar_lista(lista, tamanho);

    printf("\n\nO tempo total de execucao eh: %lf ms", tempo_total);

    return 0;
}

double ordenar_lista(long int lista[], long int tamanho)
{
    int i;
    int j;
    int armazena_valor;
    
    clock_t inicio;
    clock_t fim;
    double tempo_de_execucao;

    inicio = clock();
    for(i = 0; i < tamanho; ++i)
    {
        for(j = i + 1; j < tamanho; ++j)
        {
            if(lista[i] > lista[j])
            {
                armazena_valor = lista[i];
                lista[i] = lista[j];
                lista[j] = armazena_valor;
            }
        }

       printf("[ %d ]", lista[i]);
    }
    fim = clock();

    tempo_de_execucao = ((double)(fim - inicio)/CLOCKS_PER_SEC)*1000;

    return tempo_de_execucao;
}