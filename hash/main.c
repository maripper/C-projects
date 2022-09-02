#include "hash.h"

int main(){
    char st[51];
    p_hash t;
    t = criar_hash();
    scanf("%[^\n]s",st);
    while(strcmp(st,"#")!=0){
        buscar(t,st);
        getchar();
        scanf("%[^\n]s",st);
    }
    destruir_hash(t);
    return 0;
}
