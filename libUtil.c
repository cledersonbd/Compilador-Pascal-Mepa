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
    short int i;

    while (topo != NULL) {
        printf("Nome: %s |N_lexico: %d |Desloc.: %d |Tipo: %d |Rotulo: %d |N_Param: %d |Prox: [%p]", topo->nome, topo->n_lexico, topo->desloc, topo->tipo, topo->rotulo, topo->n_param, topo->prox);
        if (topo->tipo == FUNCAO || topo->tipo == PROCEDIMENTO) {
            printf("\n>>>>> ");
            for (i=0; i < topo->n_param; i++)
                printf("NomeParam: %s |Desloc: %d |tipoPass: %d\n", topo->parametros->nome[i], topo->parametros->desloc[i], topo->parametros->tipoPass[i]);
        }

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

int buscaTipoParam(noTS *topo, char *nomeSimbolo) {
    while ( topo != NULL ) {
        if ( strcmp(topo->nome, nomeSimbolo) == 0) {
            return topo->tipo;
        }
        topo = topo->prox;
    }
    return -15;
}

char buscaNumParamRotina(noTS *topo, char *nomeRotina) {
    while ( topo != NULL) {
        if ( strcmp(topo->nome, nomeRotina) == 0)
            return topo->n_param;
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
    if (tipo == FUNCAO || tipo == PROCEDIMENTO)
        p->parametros = (noParam*) malloc(sizeof(noParam));
    else
        p->parametros = NULL;

    if (*topo == NULL)
        p->prox = NULL;
    else
        p->prox = *topo;

    *topo = p;

    return 1;    
}





