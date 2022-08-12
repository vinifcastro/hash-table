/* Compilacao */
/* gcc -o Hash-TAD Hash-TAD-C.c Hash-TAD-main.c -lm */

#include <stdio.h>
#include "Hash-TAD-H.h"
#include <stdlib.h>
#include <sys/time.h>

#define GET_MS(ini, fim) ((fim.tv_sec * 1000000 + fim.tv_usec) - (ini.tv_sec * 1000000 + ini.tv_usec))
struct timeval inicio, fim;

int main()
{
    CriaHash();
    printf("Primeira posicao do Vetor %d\n", vetor_hash[0]);
    float media = 0;
    int chaves[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    for (int i = 0; i < 10; i++)
    {
        gettimeofday(&inicio, NULL);

        BuscaHash(chaves[i], media);

        gettimeofday(&fim, NULL);
        printf("\nTempo de execução: %ld ms\n\n", GET_MS(inicio, fim));
        if (i > 0)
        {
            media += GET_MS(inicio, fim);
        }
    }
    printf("\nTempo Medio execução: %f ms\n\n", media / 9);
    return 0;
}