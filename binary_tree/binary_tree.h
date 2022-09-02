#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct No {
  char dado[21];
  int alt;
  int indicador;
  struct No *esq, *dir; /* *pai */
} No;

typedef No * p_no;

p_no criar_arvore(int hmax,int h);

p_no busca(p_no raiz, char nome[]);

void pre_ordem(p_no raiz, p_no raiz2);

void imprimir_arvore(p_no raiz);

void destroi(p_no raiz);
