#include "abb.h"
p_no inicializar(){/*inicializo a arvore*/
    p_no raiz;
    raiz=NULL;
    return raiz;
}

p_no inserir(p_no raiz , char chave[]) {/*insiro o nome do livro "chave" na arvore*/
  p_no novo;
  if (raiz == NULL) {/*se a arvore e vazia ou se chegamos no final da arvore */
    novo = malloc(sizeof(No));/*aloco um no da arvore*/
    novo ->esq = novo ->dir = NULL;/*faco os ponteiros esq e dir apontarem para null*/
    strcpy (novo ->chave, chave);/*atribuo o nome do livro "chave" ao campo chave do novo no*/
    return novo;/*retorno o no*/
  }else if (strcmp(chave,raiz->chave)<=0){/*a arvore nao e vazia e nao chegamos ao final dela e o nome da raiz em que estamos na arvore ? menor ou igual ao que o que estamos querendo colocar*/
    raiz ->esq = inserir(raiz ->esq , chave);/*chamamos a funcao para o filho esquerdo do no em que estamos na arvore*/
  }else{/*nao chegamos ao final dela e o nome da raiz em que estamos na arvore ? maior do que o que estamos querendo colocar*/
    raiz ->dir = inserir(raiz ->dir , chave);/*chamamos a funcao para o filho direito do no em que estamos na arvore*/
  }
  return raiz;
}

p_no remover_rec(p_no raiz , char chave[]) {/*remover nome = variavel "chave", da arvore*/
  p_no t;
  if (raiz == NULL){/*se a arvore esta vazia nao retiro nada*/
    return NULL;/*nada acontece*/
  }
  if (strcmp(chave,raiz->chave)<0){/*se o nome do livro que queremos ? menor em relacao a ordem do que o nome do no em que estamos na arvore*/
    raiz ->esq = remover_rec(raiz ->esq , chave);/*chamo a funcao para o filho esuqerdo do no em que estamos na arvore*/
  }else if (strcmp(chave,raiz->chave)>0){/*se o nome do livro que queremos ? maior em relacao a ordem do que o nome do no em que estamos na arvore*/
    raiz ->dir = remover_rec(raiz ->dir , chave);/*chamo a funcao para o filho direito do no raiz*/
  }else if (raiz ->esq == NULL){/*se o filho esquerdo do no em que estamos ? NUll devolvemos a raiz direita que sera o valor que queremos retirar*/
    t = raiz->dir;
    free(raiz);
    return t;
  }else if (raiz ->dir == NULL){ /*caso seja o filho esuqerdo nao seja null mas o filho direito seja retornamos o filho esquerdo*/
    t = raiz->esq;
    free(raiz);
    return t;
  }else{/*caso achamos na arvore dentro da arvore um valor igual ao que queremos retirar, entao chamamos a funcao remover suscessor*/
    remover_sucessor(raiz);
  }
  return raiz;
}
void remover_sucessor(p_no raiz) {
  p_no t = raiz ->dir;/*? o minimo da subarvore direita*/
  p_no pai = raiz;/*? o pai de t*/
  while (t->esq != NULL) {/*enquanto o filho esuqerdo de t nao e NULL ou seja ate achar o suscessor, que nunca tem filho esquerdo*/
    pai = t;/*transformo t em pai*/
    t = t->esq;/*e transformo o filho esuqerdo de t em t*/
  }
  if (pai ->esq == t){/*se o filho esquerdo ? o suscessor */
    pai ->esq = t->dir;/*tiramos o suscessor da arvore ao fazer seu pai nao apontar mais para ele */
  }else{/*se o filho direito do pai ? o suscessor*/
    pai ->dir= t->dir;/*tiramos o suscessor da arvore ao fazer seu pai nao apontar mais para ele */
  }
  strcpy(raiz ->chave,t->chave);/*removemos o que queriamos, a raiz, ao fazer seu valor ser agora o de seu suscessor*/
  free(t);
}


void comparar_nomes(p_no raiz , char chave[], int tam) {/*funcao que compara um nome dado, variavel chave[] com os nos da arvore*/
  int comp;
  if(raiz != NULL){/*enquanto nao chegamos no fim da arvore*/
    comp = strncmp(chave, raiz->chave, tam);/*comparo apenas a parte do nome do n? da arvore de tamanho tam com o nome que queremos pesquisar, variavel chave*/
    comparar_nomes(raiz ->esq , chave, tam);/*chamo a funcao para o filho esuqerdo para continuar a percorrer a arvore*/
    if(comp==0){/*se o nome do no for igual a string que queremos comparar, imprimo o nome do livro que esta no n?*/
      printf("%s\n",raiz->chave);
    }
    comparar_nomes(raiz ->dir , chave, tam);/*chamo a funcao para o filho direito para continuar a percorrer a arvore*/
  }
}

void destroi(p_no raiz){/*destroi a arvore*/
  if(raiz != NULL){
    destroi(raiz->esq);
    destroi(raiz->dir);
    free(raiz);/*libera o no*/
  }
}
