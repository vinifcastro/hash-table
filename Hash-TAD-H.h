#include <string.h>

#ifndef _TIMES_H
#define _TIMES_H

#ifdef __linux__
    #include <sys/times.h>
#elif _WIN32
	#include <sys/timeb.h>
	#include <sys/types.h>
	#include <winsock2.h>
	#include <windows.h>
	int gettimeofday(struct timeval* t,void* timezone);
	#define sleep(sleeptime) Sleep(1000*(sleeptime)) 
	#define __need_clock_t
	#include <time.h>
	struct tms
	  {
		clock_t tms_utime;        
		clock_t tms_stime;          

		clock_t tms_cutime;         
		clock_t tms_cstime;         
	  };
	clock_t times (struct tms *__buffer);
	typedef long long suseconds_t ;
#endif
#endif

int CriaHash();
int BuscaHash(int chave, float media);

#define TAM 40000
#define PRIME 40009


typedef struct No{
    int id;
    char name[20];
	struct No * prox;
} No;

typedef struct Lista{
    No * inicio;
} Lista;

Lista tabelahash[TAM];

void inserirno(Lista * lista, int a, char * b);

void liberahashtable(No**No);