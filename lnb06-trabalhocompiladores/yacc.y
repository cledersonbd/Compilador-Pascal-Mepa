%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "liblex.h"
#include "libmepa.h"

extern char retorno[100];
extern int linha;

//pilhas
tpilha_rot *rotulo;
tpilha_ts *ts;

int yydebug=1;

//variaveis compilador
int nivlex=0;
int desloc=0;
int num=0;
int numvar=0;
int numpar=0;
int numpass=0;
int aux[10];
int cont=0;
int rotulocorrente=0;
char recebe[30];
char relacao[10];
char nomerotina[30];
int i;

//variaveis de controle
int decvar=0;
int decif=0;
int decloop=0;
int decproc=0;
int decfunc=0;
int declabel=0;
int decparam=0;
int passvalor=0;
int passreferencia=0;
int temsubrot=0;
int chpr=0; 
int parsubrotina=0;
int leitura=0;
int escrita=0;
int atribuicao=0;

//Funcao de erro
void yyerror(const char *str){
	printf("Erro: %s - linha: %d \n",str,linha);
	exit(1);
}

int yywrap(){
	return 1;
}


main(int argc, char **argv)
{
	if(argc!=2)
	{
		printf("USO: ./compilador arquivo.pas\n");
		exit(2);
	}
	yyin=fopen(argv[1],"r");
	yyout=fopen("saida.mepa","w");
	rotulo=criaPilhaRotulo();
	ts=criaPilhaTS();
	yyparse();
}

%}

%token INTEIRO	IDENT	LABEL	VAR INTEGER
%token IF	THEN	ELSE	WHILE	GOTO	DO
%token READ WRITE	FUNCTION	PROCEDURE
%token PROGRAM	_BEGIN	END
%token AND	OR	NOT	MAIORIG	MENORIG
%token MAIOR	MENOR	IGUAL	ATRIBUICAO 
%token MAIS	MENOS	MULT	DIV	DIF
%token ABREPAR	FECHAPAR	ABRECH	FECHACH
%token PTOVIRG	DOISPTS	VIRGULA	PONTO

%left MAIS MENOS
%left MULT DIV

%nonassoc LOWER_THEN_ELSE
%nonassoc ELSE

%start programa

%%

programa: PROGRAM identificador 
	{ fprintf(yyout,"INPP\n"); } 
	ABREPAR listaidentificadores FECHAPAR PTOVIRG bloco PONTO 
	{
		fprintf(yyout,"DMEM %d\n", buscaDemem(ts,nivlex));
		fprintf(yyout,"PARA\n");
	} ;

listaidentificadores: identificador
	| listaidentificadores VIRGULA identificador 
	;

bloco: p_declaracaorotulos 
	{
		decproc=0; 
		decvar=1; 
		decfunc=0; 
		parsubrotina=0;
	} 
	p_declaracaovariaveis 
	{
		decvar=0;
		fprintf(yyout,"DSVS R%d\n",rotulocorrente);
		incrementaRotulo(rotulo,rotulocorrente); 
		rotulocorrente++; 
	} 
	p_declaracaosubrotinas comandocomposto 
	;

p_declaracaorotulos: 
	| LABEL listanumeros PTOVIRG
	;

listanumeros: numero 
	{ fprintf(yyout,"%s",retorno);	}
	| listanumeros VIRGULA numero 
	;

p_declaracaovariaveis: 
	| VAR declaracaovariaveis PTOVIRG 
	{
		fprintf(yyout,"AMEM %d\n", numvar); 
		numvar=0; 
	}
	| declaracaovariaveis PTOVIRG 
	{
		fprintf(yyout,"AMEM %d\n", numvar); 
		numvar=0; 
	}
	;

declaracaovariaveis:  listaidentificadores  DOISPTS tipo 
	| declaracaovariaveis PTOVIRG listaidentificadores DOISPTS tipo 
	;

tipo: INTEGER 
	;

p_declaracaosubrotinas: 
	| listadeclaracaosubrotinas PTOVIRG 
	;

listadeclaracaosubrotinas: listadeclaracaosubrotinas PTOVIRG declaracaosubrotinas
	| declaracaosubrotinas
	;

declaracaosubrotinas: declaracaoproc 
	| declaracaofuncao
	;

declaracaoproc: PROCEDURE 
	{
		decproc=1; 
		decvar=0; 
		decfunc=0; 
		parsubrotina=0;
	}
	identificador 
	{
		strcpy(nomerotina,retorno);
		decproc=0; 
		decvar=0; 
		decfunc=0; 
		parsubrotina=0;
	} 
	parametrosformais PTOVIRG 
	bloco 
	{
		fprintf(yyout,"DMEM %d\n", buscaDemem(ts,nivlex));
		fprintf(yyout,"RTPR %d,%d\n", nivlex, buscaNumParam(ts,nomerotina));
		nivlex--;
	} ;

declaracaofuncao: FUNCTION 
	{
		decproc=0; 
		decvar=0; 
		decfunc=1; 
		parsubrotina=0;
	} 
	identificador 
	{ strcpy(nomerotina,retorno); } 
	parametrosformais DOISPTS tipo
	{
		numpar++;
		ts->topo->parametro.desloc[numpar-1]=-3-numpar;
		strcpy(ts->topo->parametro.ident[numpar-1],nomerotina);
		ts->topo->parametro.passagem[numpar-1]=VALOR;
		ts->topo->numparam=numpar;
	}
	PTOVIRG bloco 
	{
		fprintf(yyout,"DMEM %d\n", buscaDemem(ts,nivlex));
		fprintf(yyout,"RTPR %d,%d\n", nivlex, (buscaNumParam(ts,nomerotina)-1));
		nivlex--;
	} ;
	
parametrosformais: 
	| ABREPAR 
	{
		decproc=0; 
		decvar=0; 
		decfunc=0; 
		parsubrotina=1;
	} 
	s_parametrosformais 
	{
		decproc=0; 
		decvar=0; 
		decfunc=0; 
		parsubrotina=0; 
		for(i=ts->topo->numparam-1;i>=0;i--)
		{
			aux[i]=ts->topo->parametro.desloc[cont];
			cont++;
		}
		for(i=0;i<ts->topo->numparam;i++)
			ts->topo->parametro.desloc[i]=aux[i];
	}
	FECHAPAR
	;

s_parametrosformais: VAR 
	{ passreferencia=1; } 
	listaidentificadores 
	{ passreferencia=0; } 
	DOISPTS tipo
	| 	{passvalor=1;}
	listaidentificadores 
	{ passvalor=0; } 
	DOISPTS tipo
	| s_parametrosformais PTOVIRG VAR 
	{ passreferencia=1; } 
	listaidentificadores 
	{ passreferencia=0; } 
	DOISPTS tipo
	| s_parametrosformais PTOVIRG 
	{ passvalor=1; } 
	listaidentificadores 
	{ passvalor=1; } 
	DOISPTS tipo
	;

comandocomposto: _BEGIN END
	| _BEGIN 
	{
		if ((decloop==0)&&(decif==0))
		{
			num=desempilhaRotulo(rotulo);
			fprintf(yyout,"R%d: NADA\n",num); 
		}
	}
	listacomandos END
	;

listacomandos: comando
	| listacomandos PTOVIRG comando 
	;

comando: numero DOISPTS comandosemrotulo
	| comandosemrotulo
	;

comandosemrotulo: atribuicao 
	| chamadaprocedimento
	| desvio
	| read	
	| write
	| comandocomposto
	| comandocondicional
	| comandorepetitivo
	;

atribuicao: variavel 
	{
		atribuicao=1; 
		strcpy(recebe,retorno);
        printf("Copiei %s\n", retorno);
        printf("Copiei %s\n", yytext);
	} 
	ATRIBUICAO expressao 
	{ 
		if (buscaPassagem(ts,recebe)==VALOR)
			 fprintf(yyout,"ARMZ %d,%d\n", buscaNivLexTS(ts,recebe),buscaDeslocamentoTS(ts,recebe)); 
		else if (buscaPassagem(ts,recebe)==REFERENCIA)
			 fprintf(yyout,"ARMI %d,%d\n", buscaNivLexTS(ts,recebe),buscaDeslocamentoTS(ts,recebe)); 
		atribuicao=0;
	};

chamadaprocedimento: identificador 
	{	
		strcpy(nomerotina,retorno);
		fprintf(yyout,"CHPR R%d,%d\n", buscaIdentificador(ts,nomerotina),nivlex);
	}
	| identificador 
	{	
		chpr=1;
		strcpy(nomerotina,retorno);
	}
	ABREPAR listaexpressoes 
	{ 
		fprintf(yyout,"CHPR R%d,%d\n", buscaIdentificador(ts,nomerotina),nivlex);
		chpr=0;
		numpass=0;
	}
	FECHAPAR 
	;

read: { leitura=1; } 
	READ ABREPAR listaexpressoes FECHAPAR 
	{ leitura=0; }
	;

write: { escrita=1; } 
	WRITE ABREPAR listaexpressoes FECHAPAR 
	{ escrita=0; }
	;

desvio: GOTO numero
	;

comandocondicional: IF 
	{ decif=1; } 
	expressao 
	{
		fprintf(yyout,"DSVF R%d\n",rotulocorrente); 
		incrementaRotulo(rotulo,rotulocorrente);
		rotulocorrente++;
	}
	THEN comandosemrotulo condicaoelse 
	{
		fprintf(yyout,"R%d: NADA\n", desempilhaRotulo(rotulo));
		decif=0;
	} ;

condicaoelse: ELSE 
	{
		fprintf(yyout,"DSVS R%d\n", rotulocorrente);
		fprintf(yyout,"R%d: NADA\n", desempilhaRotulo(rotulo));
		incrementaRotulo(rotulo,rotulocorrente);
		rotulocorrente++;		
	}
	comandosemrotulo 
	| %prec LOWER_THEN_ELSE ;

comandorepetitivo: WHILE 
	{
		decloop=1;
		incrementaRotulo(rotulo,rotulocorrente);
		fprintf(yyout,"R%d: NADA\n", rotulocorrente);
		rotulocorrente++;
	}
	expressao
	{ fprintf(yyout,"DSVF R%d\n",rotulocorrente); }
	DO comandosemrotulo
	{
		fprintf(yyout,"DSVS R%d\n", desempilhaRotulo(rotulo));
		incrementaRotulo(rotulo,rotulocorrente);
		fprintf(yyout,"R%d: NADA\n", desempilhaRotulo(rotulo));
		rotulocorrente++;
		decloop=0;
	} ;

listaexpressoes: expressao 
	| listaexpressoes VIRGULA expressao
	;

expressao: expressaosimples 
	|  expressaosimples relacao expressaosimples { fprintf(yyout,"%s",relacao); }
	;

expressaosimples: termo 
	| MAIS termo
	| MENOS termo 
	| termo listaexpressoessimples
	| MAIS termo listaexpressoessimples
	| MENOS termo listaexpressoessimples
	;

listaexpressoessimples: MAIS  termo  {fprintf(yyout,"SOMA\n");}
	| MENOS  termo {fprintf(yyout,"SUBT\n");}
	| OR  termo {fprintf(yyout,"DISJ\n");}
	| listaexpressoessimples MAIS termo {fprintf(yyout,"SOMA\n");}
	| listaexpressoessimples MENOS termo  {fprintf(yyout,"SUBT\n");}
	| listaexpressoessimples OR termo {fprintf(yyout,"DISJ\n");}
	;

termo: fator 
	|fator listatermos
	;

listatermos: MULT fator {fprintf(yyout,"MULT\n");}
	| DIV fator {fprintf(yyout,"DIVI\n");}
	| AND fator {fprintf(yyout,"CONJ\n");} 
	| listatermos MULT fator {fprintf(yyout,"MULT\n");}
	| listatermos DIV fator {fprintf(yyout,"DIVI\n");} 
	| listatermos AND fator {fprintf(yyout,"CONJ\n");} 
	;

fator: variavel
	{
		if ((escrita==0)&&(leitura==0)&&(buscaPassagem(ts,retorno)==VALOR)&&(chpr==0))
			fprintf(yyout,"CRVL %d,%d\n", buscaNivLexTS(ts,retorno),buscaDeslocamentoTS(ts, retorno)); 
 		else if((escrita==0)&&(leitura==0)&&(buscaPassagem(ts,retorno)==REFERENCIA)&&(chpr==0))
			fprintf(yyout,"CRVI %d,%d\n", buscaNivLexTS(ts,retorno),buscaDeslocamentoTS(ts, retorno)); 
		if (chpr==1)
		{
			if ((buscaPassagem(ts,retorno)==REFERENCIA)&&(buscaPassagemParam(ts,nomerotina,numpass)==VALOR))
				fprintf(yyout,"CRVI %d,%d\n", buscaNivLexTS(ts,retorno),buscaDeslocamentoTS(ts, retorno));	
			if ((buscaPassagem(ts,retorno)==VALOR)&&(buscaPassagemParam(ts,nomerotina,numpass)==VALOR))
				fprintf(yyout,"CRVL %d,%d\n", buscaNivLexTS(ts,retorno),buscaDeslocamentoTS(ts, retorno));	
			if ((buscaPassagem(ts,retorno)==VALOR)&&(buscaPassagemParam(ts,nomerotina,numpass)==REFERENCIA))
				fprintf(yyout,"CREN %d,%d\n", buscaNivLexTS(ts,retorno),buscaDeslocamentoTS(ts, retorno));	
			if ((buscaPassagem(ts,retorno)==REFERENCIA)&&(buscaPassagemParam(ts,nomerotina,numpass)==REFERENCIA))
				fprintf(yyout,"CRVL %d,%d\n", buscaNivLexTS(ts,retorno),buscaDeslocamentoTS(ts, retorno));	
			numpass++;
		}
	}
	| numero 
	{
 		if ((escrita==0)&&(leitura==0))
			fprintf(yyout,"CRCT %d\n", num);
	}
	| chamadafuncao
	| ABREPAR expressao FECHAPAR
	| NOT fator  
	{ fprintf(yyout,"NEGA\n"); }
	;

relacao: IGUAL {strcpy(relacao,"CMIG\n");}
	| DIF {strcpy(relacao,"CMDG\n");}
	| MENORIG {strcpy(relacao,"CMEG\n");}
	| MAIORIG {strcpy(relacao,"CMAG\n");}
	| MENOR {strcpy(relacao,"CMME\n");}
	| MAIOR {strcpy(relacao,"CMMA\n");}
	;

variavel: identificador 
	;

chamadafuncao: identificador 
	{
		strcpy(nomerotina,retorno);
		chpr=1;
	}
	ABREPAR listaexpressoes 
	{	
		fprintf(yyout,"CHPR R%d,%d\n", buscaIdentificador(ts,nomerotina),nivlex);
		chpr=0;
		numpass=0;
	}
	FECHAPAR
	;

numero: INTEIRO 
	{ 
		num=atoi(retorno);
		if (declabel==1 && buscaSimboloTS(ts,nivlex,retorno)==1)
		{
			novoSimbolo(ts);
			strcpy(ts->topo->ident,retorno);
			incrementaRotulo(rotulo, rotulocorrente);
			rotulocorrente++;
			ts->topo->tipo=LABGOTO;
			ts->topo->rotulo=rotulo->topo->label;
			ts->topo->nivlexico=nivlex;
		}
	} ;

identificador: IDENT  
	{	
		if (decvar==1 && buscaSimboloTS(ts,nivlex,retorno)==1)
		{	
			novoSimbolo(ts);
			strcpy(ts->topo->ident,retorno);
			ts->topo->nivlexico=nivlex;
			ts->topo->deslocamento=numvar;
			ts->topo->tipo=VARIAVEL;
			numvar++;
		}
		if ((leitura==1) && (buscaPassagem(ts,retorno)==VALOR))
			fprintf(yyout,"LEIT\nARMZ %d,%d\n", buscaNivLexTS(ts,retorno), buscaDeslocamentoTS(ts,retorno));
		else if ((leitura==1) && (buscaPassagem(ts,retorno)==REFERENCIA))
			fprintf(yyout,"LEIT\nARMI %d,%d\n", buscaNivLexTS(ts,retorno), buscaDeslocamentoTS(ts,retorno));
		if ((escrita==1) && (buscaPassagem(ts,retorno)==VALOR))
			fprintf(yyout,"CRVL %d,%d\nIMPR\n", buscaNivLexTS(ts,retorno),buscaDeslocamentoTS(ts,retorno));
		else if(escrita==1 && (buscaPassagem(ts,retorno)==REFERENCIA))
			fprintf(yyout,"CRVI %d,%d\nIMPR\n", buscaNivLexTS(ts,retorno),buscaDeslocamentoTS(ts, retorno));	
		if (decproc==1 && buscaSimboloTS(ts,nivlex,retorno)==1)
		{	
			fprintf(yyout,"R%d: NADA\n",rotulocorrente);
			incrementaRotulo(rotulo,rotulocorrente);
			nivlex++;
			fprintf(yyout,"ENPR %d\n", nivlex);
			novoSimbolo(ts);
			strcpy(ts->topo->ident,retorno);
			ts->topo->nivlexico=nivlex;
			ts->topo->rotulo=rotulocorrente;
			ts->topo->tipo=PROCEDIMENTO;
			rotulocorrente++;
			numpar=desempilhaRotulo(rotulo);
			numpar=0;
		}
		if (decfunc==1 && buscaSimboloTS(ts,nivlex,retorno)==1)
		{	
			fprintf(yyout,"R%d: NADA\n",rotulocorrente);
			incrementaRotulo(rotulo,rotulocorrente);
			nivlex++;
			fprintf(yyout,"ENPR %d\n", nivlex);
			novoSimbolo(ts);
			strcpy(ts->topo->ident,retorno);
			ts->topo->nivlexico=nivlex;
			ts->topo->rotulo=rotulocorrente;
			ts->topo->tipo=FUNCAO;
			rotulocorrente++;
			numpar=desempilhaRotulo(rotulo);
			numpar=0;
		}
		if ((parsubrotina==1)&&(passvalor==1))
		{
			numpar++;
			ts->topo->parametro.desloc[numpar-1]=-3-numpar;
			strcpy(ts->topo->parametro.ident[numpar-1],retorno);
			ts->topo->numparam=numpar;
			ts->topo->parametro.passagem[numpar-1]=VALOR;			
		}
		if ((parsubrotina==1)&&(passreferencia==1))
		{
			numpar++;
			ts->topo->parametro.desloc[numpar-1]=-3-numpar;
			strcpy(ts->topo->parametro.ident[numpar-1],retorno);
			ts->topo->numparam=numpar;
			ts->topo->parametro.passagem[numpar-1]=REFERENCIA;			
		}
	} ;
