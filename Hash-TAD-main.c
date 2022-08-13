/* Compilacao */
/* gcc -o Hash-TAD Hash-TAD-C.c Hash-TAD-main.c -lm */

#include <stdio.h>
#include "Hash-TAD-H.h"
#include <stdlib.h>

#define GET_MS(ini, fim) ((fim.tv_sec * 1000000 + fim.tv_usec) - (ini.tv_sec * 1000000 + ini.tv_usec))
struct timeval inicio, fim;

int main()
{
    CriaHash();
    float media = 0;
    int chaves[10] = {9183686, 4097337, 7081986, 1736712, 7859086, 2204209, 2201715, 138480, 7591640, 8214215};

    for (int i = 0; i < 10; i++)
    {
        gettimeofday(&inicio, NULL);

        BuscaHash(chaves[i], media);

        gettimeofday(&fim, NULL);
        printf("\nTempo de execucao: %ld ms\n\n", GET_MS(inicio, fim));
        if (i > 0)
        {
            media += GET_MS(inicio, fim);
        }
    }
    printf("\nTempo Medio execucao: %f ms\n\n", media / 9);
    return 0;
}