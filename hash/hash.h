#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#define MAX 10000

typedef struct No {
    char chave[51];
    struct No *prox;
} No;

typedef No * p_no;

typedef struct{
    p_no vetor[MAX];
} Hash;

typedef Hash * p_hash;

int hash(char *chave);

p_hash criar_hash();

void inserir(p_hash t, char *chave);

void buscar(p_hash t, char *chave);

void destruir_hash(p_hash t);

void destruir_lista(p_no lista);
