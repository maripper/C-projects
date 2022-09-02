#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct No {/*struct da arvore*/
    char chave[80];/*esse campo guarda os nomes do livro do n?*/
    struct No *esq, *dir;/*apontadores para a direita e esquerda do n?*/
} No;

typedef No * p_no;/*apontador para a estrutura da arvore*/

p_no inicializar();

p_no inserir(p_no raiz , char chave[]) ;

p_no remover_rec(p_no raiz , char chave[]) ;

void remover_sucessor(p_no raiz);

void comparar_nomes(p_no raiz , char chave[], int tam);

void destroi(p_no raiz);
