#include "arv_binaria.h"

p_no criar_arvore(int hmax,int h) { /*funcao que le e constroi a arvore com parametros da altura e h que serve para dar a altura de cada no*/
    p_no r;
    if(hmax==h){/*quando chegarmos no ultimo nivel da arvore retorno NULL*/
      return NULL;
    }
    r = malloc(sizeof(No));/*alloco o no da arvore*/
    r->esq = criar_arvore(hmax,h+1);/*chamo a funcao recursiva para criar o no da esquerda do primeiro no e incremento h que e a altura de cad no ou seja do no do filho esuqerdo*/
    r->dir = criar_arvore(hmax,h+1);/*chamo a funcao recursiva para criar o no da direita do primeiro no e incremento h que e a altura de cad no ou seja do no do filho direito*/
    scanf("%s", r->dado);/*input do dado do no*/
    r->alt = h;/*guarda a altura de cada no da arvore*/
    r->indicador = 0;/*indicador para marcar quais nomes estao em ambas as arvores para fim de impressao*/
    return r;/*retorno os nos*/
}
p_no busca(p_no raiz, char nome[]){/*funcao que busca compatibilidade entre nome dado e raiz da arvore*/
  if(raiz!=NULL){/*laco enquanto nao chegarmos ao fim da arvore*/
    if(strcmp(raiz->dado,nome)==0){/*comparacao entre raiz e nome dado*/
      return raiz;/*caso forem iguais eu retorno a raiz*/
    }else{/*caso a raiz nao seja igual ao nome*/
      p_no esq = busca(raiz->esq,nome);/*procuro o nome no filho esuqerdo da raiz*/
      p_no dir;
      if(esq != NULL) return esq;/*se achar no filho esquerdo retorno o filho esquerdo*/
      dir = busca(raiz->dir,nome);/*caso nao ache no filho esquerdo procuro no filho direito*/
      if(dir != NULL) return dir;/*se eu acho no filho direito, retorno o filho direito*/
    }
  }
  return NULL;/*nao achei o nome em nenhum filho*/
}
void pre_ordem(p_no raiz, p_no raiz2) {/*procuro compatibilidade entre os nomes das duas arvores variando a primeira arvore e chamando a funcao busca para cada raiz*/
  if (raiz != NULL) {/*enquanto nao chegarmos ao fim da arvore*/
    p_no raiz3 = busca(raiz2,raiz->dado);/*procuramos se achamos o nome da raiz na outra arvore*/
    if(raiz3!=NULL){/*se acharmos o nome da raiz na outra arvore*/
      printf("%s %d ",raiz3->dado, raiz->alt);/*printo o nome da raiz da primeira arvore e a altura da raiz*/
      raiz3->indicador = 1;/*mudo o indicador da raiz da primeira arvore para fins de impressao*/
      raiz->indicador = 1;/*mudo o indicador da raiz da segunda arvore para fins de impressao*/
    }
    pre_ordem(raiz->esq,raiz2);/*procuro compatibilidade entre os nomes das duas arvores no filho esquerdo*/
    pre_ordem(raiz->dir,raiz2);/*procuro compatibilidade entre os nomes das duas arvores no filho direito*/
  }
}


void imprimir_arvore(p_no raiz){/*imprimir os nomes de uma arvore a partir dos seus indices*/
  if(raiz!=NULL){
    if(raiz->indicador == 1){/*se o indicador da raiz for 1 significa que essa raiz esta nesta arvore e em outra arvore anteriormente analisada*/
      printf("%s %d ",raiz->dado, raiz->alt);/*imprimo o dado da raiz e a altura*/
    }
    imprimir_arvore(raiz->esq);/*continuo chamando a funcao para o filho esuqerdo*/
    imprimir_arvore(raiz->dir);/*e depois para o filho direito*/
  }

}

void destroi(p_no raiz){/*destroi a arvore*/
  if(raiz != NULL){
    destroi(raiz->esq);
    destroi(raiz->dir);
    free(raiz);/*libera o no*/
  }
}
