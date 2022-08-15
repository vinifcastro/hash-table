/* Compilacao */
/* gcc -o Hash-TAD Hash-TAD-C.c Hash-TAD-main.c -lm */

#include "Hash-TAD-H.h"

#define GET_MS(ini, fim) ((fim.tv_sec * 1000000 + fim.tv_usec) - (ini.tv_sec * 1000000 + ini.tv_usec))
struct timeval inicio, fim;

int main()
{
    CriaHash();
    float media = 0;
    int chaves[10] = {40009, 80018, 0, 2, 120027, 7878107, 4222497, 5748520, 8282987, 160036};

    for (int i = 0; i < 10; i++)
    {
        printf("\n------------------------------------------------------------\n");
        gettimeofday(&inicio, NULL);

        BuscaHash(chaves[i], media);

        gettimeofday(&fim, NULL);
        printf("\nTempo de execucao: %ld ms\n\n", GET_MS(inicio, fim));
        if (i > 0)
        {
            media += GET_MS(inicio, fim);
        }
    }

    for(int z=0; z <TAM;z++) liberahashtable(&(tabelahash[z].inicio));

    printf("\nTempo Medio execucao: %f ms\n\n", media / 9);

    return 0;
}