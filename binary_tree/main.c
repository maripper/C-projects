#include "arv_binaria.h"
int main(){
  p_no r1,r2;
  int h1,h2;
  scanf("%d %d",&h1,&h2);/*leio a altura das duas arvores*/
  r1 = criar_arvore(h1,0);/*crio a arvore 1 com altura h1 e comecando do no de altura zero*/
  r2 = criar_arvore(h2,0);/*crio a arvore 2 com altura h2 e comecando do no de altura zero*/
  pre_ordem(r1,r2);/*chamo a funcao que busca compatibilidade de nomes nas duas arvores*/
  printf("\n");
  imprimir_arvore(r2);/*imprimo os nomes iguais entre as duas arvores e seus graus de consanguinidade(altura na arvore)*/
  printf("\n");
  destroi(r1);
  destroi(r2);
  return 0;
}
