#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "libUtil.h"

int empilhaRotulo (int x, noRotulo *(*topo)) {
    noRotulo *p; 

    if ( (p = (noRotulo *)malloc(sizeof(noRotulo))) == NULL)
        return;

    p->rotulo = x;
    p->prox = *topo;
    *topo = p;
    return(1);
}

int desempilhaRotulo (noRotulo *(*topo)) {
    static int x;
    noRotulo *temp = *topo;

    if (*topo == NULL)
        return;

    x = (*topo)->rotulo;
    *topo = (*topo)->prox;
    free(temp);
    return(x);
}

int printSimbolos(noTS* topo) {

    puts("\n--------------------------TABELA DE SIMBOLOS--------------------");
    while (topo != NULL) {
        printf("Nome: %s\nN_lexico: %d\nDesloc.: %d\nTipo: %d\nRotulo: %d\nN_Param: %d\nProx: [%p]", topo->nome, topo->n_lexico, topo->desloc, topo->tipo, topo->rotulo, topo->n_param, topo->prox);
        puts("\n----------------------");
        topo= topo->prox;
    }
    puts("\n----------------------FIM DA TABELA DE SIMBOLOS------------------");
}

int buscaSimbolo(noTS *topo, int nlex, char *nomeSimbolo) {

    while ( topo != NULL ) {
        if (topo->n_lexico == nlex && (strcmp(topo->nome, nomeSimbolo) == 0) )
            return 1;
        topo = topo->prox;
    }
    return 0;
}

int buscaNivelLexico(noTS *topo, char *nomeSimbolo) {
   
    while ( topo != NULL ) {
        if (strcmp(topo->nome, nomeSimbolo) == 0)
            return topo->n_lexico;
        topo = topo->prox;
    }
    return -15;
}
 
int buscaDesloc(noTS *topo, char *nomeSimbolo) {

    while ( topo != NULL ) {
        if (strcmp(topo->nome, nomeSimbolo) == 0)
            return topo->desloc;
        topo = topo->prox;
    }
    return -15;
}

int desalocaMem(noTS *topo, int n_lex) {
    int cont = 0;

    while ( topo != NULL ) {
        if (topo->n_lexico == n_lex) {
            cont++;    
        }
        topo = topo->prox;
    }
    return cont;
}

int empilhaSimbolo(noTS **topo, char *nome, int n_lexico, int desloc, int tipo, int rotulo, int n_param) {

    noTS *p;

    p = (noTS*) malloc(sizeof(noTS));

    strcpy(p->nome,nome);
    p->n_lexico = n_lexico;
    p->desloc = desloc;
    p->tipo = tipo;
    p->rotulo = rotulo;
    p->n_param = n_param;

    if (*topo == NULL)
        p->prox = NULL;
    else
        p->prox = *topo;

    *topo = p;

    return 1;    
}





