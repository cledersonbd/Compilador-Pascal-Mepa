#include "libmepa.h"

/*===========================================================================*/
/*                    FUNÇÕES DA PILHA DE RÓTULO                             */                        
/*===========================================================================*/

tpilha_rot* criaPilhaRotulo (void)
{
   tpilha_rot* p = (tpilha_rot*) malloc(sizeof(tpilha_rot));
   p->topo = NULL;
   return p;
}

void incrementaRotulo (tpilha_rot *p, int num)
{	
	tno_rot *n;

	if (p->topo == NULL) 
	{
		n = (tno_rot*) malloc(sizeof(tno_rot));
		n->label = num;
		n->prox=NULL;
		p->topo=n;
	} else {
		n = (tno_rot*) malloc(sizeof(tno_rot));
		n->label=num;
		n->prox=p->topo;
		p->topo=n;
	}
}

int desempilhaRotulo(tpilha_rot *p)
{
   tno_rot *a;
	int rotulo;
   if (p->topo!=NULL)
   {
      a=p->topo;
      p->topo=p->topo->prox;
		rotulo=a->label;
      free(a);
   }
   else 
   {
      printf("\nPilha vazia!\n");
      exit(0);
   }
	return(rotulo);
}

void imprimePilhaRotulo(tpilha_rot *p)
{
   tno_rot *a;
   a=p->topo;
   while (a!=NULL)
   {
      printf("Nó %d\n", a->label);
      a=a->prox;
   } 
}

/*===========================================================================*/
/*                 FUNÇÕES DA PILHA DA TABELA DE SIMBOLOS                    */                        
/*===========================================================================*/

tpilha_ts* criaPilhaTS(void)
{
   tpilha_ts* p = (tpilha_ts*) malloc(sizeof(tpilha_ts));
   p->topo = NULL;
   return p;
}

void inicializaEstrutura(tno_ts* n)
{
	n->nivlexico=-1;
	n->deslocamento=-1;
	n->tipo=-1;
	n->rotulo=-1;
	n->numparam=-1;
}

void novoSimbolo(tpilha_ts *p)
{
	if (p->topo == NULL)
	{
		tno_ts* n = (tno_ts*) malloc(sizeof(tno_ts));
		n->prox=NULL;
		p->topo=n;
		inicializaEstrutura(n);
	} else {
		tno_ts* n = (tno_ts*) malloc(sizeof(tno_ts));
		n->prox=p->topo;
		p->topo=n;
		inicializaEstrutura(n);
	}
}

void desempilhaSimbolo(tpilha_ts *p)
{
   tno_ts *a;
   if (p->topo!=NULL)
   {
      a=p->topo;
      p->topo=p->topo->prox;
      free(a);
   }
   else 
   {
      printf("\nPilha vazia!\n");
      exit(0);
   }
}

void imprimePilhaTS(tpilha_ts *p)
{
   tno_ts *a;
	int i;
   a=p->topo;
   while (a!=NULL)
   {
      printf("\nId: %s\t", a->ident);
		printf("Niv. lexico: %d\t", a->nivlexico);
		printf("Desloc: %d\t", a->deslocamento);
		printf("Tipo: %d\t", a->tipo);
		printf("Rótulo: %d\t", a->rotulo);
		printf("Num param: %d", a->numparam);
		if ((a->tipo==PROCEDIMENTO)||(a->tipo==FUNCAO))
		{
			for (i=0;i<a->numparam;i++)
			{
				printf("\n\tPassagem: %d\t", a->parametro.passagem[i]);
				printf("Ident: %s\t", a->parametro.ident[i]);
				printf("Desloc: %d\n", a->parametro.desloc[i]);
			}
		}
      a=a->prox;
   } 
	printf("\n");
}

int buscaSimboloTS(tpilha_ts *p, int nivlex, char *simbolo)
{
	tno_ts *a;
   a=p->topo;
   while (a!=NULL)
   {
		if ((a->nivlexico==nivlex) && !(strcmp(a->ident,simbolo)))
			return(0);
		a=a->prox;
	}
	return(1);
}
	
int buscaDeslocamentoTS(tpilha_ts *p, char *simbolo)
{
	tno_ts *a;
	int i;
   a=p->topo;
   while (a!=NULL)
   {
		if ((!strcmp(a->ident,simbolo))&&(a->tipo!=FUNCAO))
			return(a->deslocamento);
		if ((a->tipo==PROCEDIMENTO)||(a->tipo==FUNCAO))
			for(i=0;i<a->numparam;i++)
				if (!strcmp(a->parametro.ident[i],simbolo))
					return(a->parametro.desloc[i]);
		a=a->prox;
	}
	printf("Erro: Símbolo %s não encontrado na tabela de símbolos.\n", simbolo);
	exit(1);
}
	
int buscaNivLexTS(tpilha_ts *p, char *simbolo)
{
	tno_ts *a;
	int i;
   a=p->topo;
   while (a!=NULL)
   {
		if (!strcmp(a->ident,simbolo))
			return(a->nivlexico);
		if ((a->tipo==PROCEDIMENTO)||(a->tipo==FUNCAO))
			for(i=0;i<a->numparam;i++)
				if (!strcmp(a->parametro.ident[i],simbolo))
					return(a->nivlexico);
		a=a->prox;
	}
	printf("Erro: Símbolo %s não encontrado na tabela de símbolos.\n", simbolo);
	exit(1);
}

int buscaDemem(tpilha_ts *p, int nl)
{
	tno_ts *a;
	int cont=0;
	int conttotal=0;
	int i;
	
	a=p->topo;
	while (a!=NULL)
   {
		if ((a->nivlexico==nl) && (a->tipo==VARIAVEL))
			cont++;
		if ((a->nivlexico==nl) && ((a->tipo==FUNCAO)||(a->tipo==PROCEDIMENTO)))
			a->numparam=0;
		a=a->prox;
	}
	for (i=0;i<cont;i++)
		desempilhaSimbolo(p);
	return(cont);
}

int buscaNumParam(tpilha_ts *p, char *simbolo)
{
	tno_ts *a;
   a=p->topo;
   while (a!=NULL)
   {
		if (!strcmp(a->ident,simbolo))
			return(a->numparam);
		a=a->prox;
	}
}

int buscaIdentificador(tpilha_ts *p,char *simbolo)
{
	tno_ts *a;
   a=p->topo;
   while (a!=NULL)
   {
		if (!strcmp(a->ident,simbolo))
			return(a->rotulo);
		a=a->prox;
	}
	printf("Erro: Símbolo %s não encontrado na tabela de símbolos.\n", simbolo);
	exit(1);
}

int buscaPassagem(tpilha_ts *p,char *simbolo)
{
	tno_ts *a;
	int i;
   a=p->topo;
   while (a!=NULL)
   {
		if ((a->tipo==PROCEDIMENTO)||(a->tipo==FUNCAO))
			for(i=0;i<a->numparam;i++)
				if (!strcmp(a->parametro.ident[i],simbolo))
					return(a->parametro.passagem[i]);
		a=a->prox;
	}
	return(VALOR);
}

int buscaPassagemParam(tpilha_ts *p,char *rotina,int num)
{
	tno_ts *a;
	int i;
   a=p->topo;
   while (a!=NULL)
   {
		if (!strcmp(a->ident,rotina) && ((a->tipo==PROCEDIMENTO)||(a->tipo==FUNCAO)))
			return(a->parametro.passagem[num]);
		a=a->prox;
	}
}
