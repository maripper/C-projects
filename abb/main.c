#include <stdio.h>
#include <string.h>
#include "abb.h"
int main(){
  p_no livro;
  char op;
  char arg[80];
  int tam;
  livro = inicializar();/*inicializo a arvore*/
  while (scanf(" %c %[^\n]", &op, arg) == 2) {/*enquanto receber um comando e um nome*/
    if(op =='+'){/*se o comando for +*/
      livro = inserir(livro,arg);/*eu insiro o livro de nome arg na arvore livro*/
    }else if(op =='-'){/*retiro um nome de liuvro da arvore livro*/
      livro = remover_rec(livro,arg);
    }else if(op =='$'){/*pesquiso se existem nomes com a pesquisa de stirng arg na arvore*/
      printf("Sugestoes para prefixo \"%s\":\n",arg);
      tam = strlen(arg);/*tamanho da string de pesquisa arg*/
      comparar_nomes(livro,arg,tam);/*funcao de comparacao*/
    }else if(op =='#'){/*fim das operacoes com a arvore*/
	  break;/*acabo de rodar o programa*/
    }
  }
  destroi(livro);
  return 0;
}
