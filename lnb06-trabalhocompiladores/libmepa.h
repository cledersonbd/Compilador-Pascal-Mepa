#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>


#define VARIAVEL 1
#define PROCEDIMENTO 3
#define FUNCAO 4
#define LABGOTO 5
#define VALOR 6
#define REFERENCIA 7


/*====================================================================*/

//Estruturas para a pilha de rótulos

typedef struct no_rot{
	int label;
   struct no_rot *prox;
} tno_rot;

typedef struct pilha_rot{
   tno_rot *topo;
} tpilha_rot;

//Estruturas para a pilha da tabela de símbolos

typedef struct param{
	int desloc[10];		
   char ident[10][10];
   int passagem[10];  
} tparam;

typedef struct no_ts{
   char ident[15];         //identificador do simbolo
	int nivlexico;				//nivel lexico
	int deslocamento;			//deslocamento
	int tipo;					//tipo do simbolo
	int rotulo;					//numero do rotulo para função ou procedimento
	int numparam;				//numero de parametros para função ou procedimento
	tparam parametro;			//parametros para função ou procedimento   
	struct no_ts *prox;
} tno_ts;

typedef struct pilha_ts{
   tno_ts *topo;
} tpilha_ts;

/*====================================================================*/
// Funções da pilha de rótulos

tpilha_rot* criaPilhaRotulo(void);
void incrementaRotulo(tpilha_rot *, int);
int desempilhaRotulo(tpilha_rot *);
void imprimePilhaRotulo(tpilha_rot *);

// Funções da pilha da tabela de símbolos

tpilha_ts* criaPilhaTS(void);
void inicializaEstrutura(tno_ts* );
void novoSimbolo(tpilha_ts *);
void desempilhaSimbolo(tpilha_ts *);
void imprimePilhaTS(tpilha_ts *);
int buscaSimboloTS(tpilha_ts *, int , char* );
int buscaDeslocamentoTS(tpilha_ts *, char* );
int buscaNivLexTS(tpilha_ts *, char * );
int buscaDemem(tpilha_ts *, int);
int buscaNumParam(tpilha_ts *,char *);
int buscaIdentificador(tpilha_ts *,char *);
int buscaPassagem(tpilha_ts *,char *);
int buscaPassagemParam(tpilha_ts *,char *,int );
/*====================================================================*/
