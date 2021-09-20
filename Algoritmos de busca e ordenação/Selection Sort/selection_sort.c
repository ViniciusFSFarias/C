#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double ordenar_lista(long int lista[], long int tamanho);

int main()
{
    srand(time(NULL));
    
    //variável tamanho que define o tamanho do vetor. simula input de usuário, pode ser alterada para qualquer valor conveniente.
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
    
    //as funções de clock vão medir o tempo de processamento da função
    inicio = clock();
    
    //o selection sort faz duas verificações no vetor: a primeira (primeiro laço for) caminha por cada elemento do vetor, e a segunda (segundo laço for)
    //vai caminhar por todos os elementos posteriores ao atual para fazer as comparações.
    for(i = 0; i < tamanho; ++i)
    {
        for(j = i + 1; j < tamanho; ++j)
        {
            if(lista[i] > lista[j])
            {
                //valor atual (i) é armazenado em variável de backup, depois o atual é substituido pelo próximo valor que seja menor que ele (j)
                //após isso, a posição (j) é preenchida com o valor de backup, ordenando a lista
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
