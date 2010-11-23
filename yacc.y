%{
#include <stdio.h>

#include "liblex.h"
#include "libUtil.h"

extern int num_linha;
extern char matched[100];

int yylex(void);

//  Estrutura de pilha que mantem os rotulos
noRotulo *topoRotulo;

// Estrutura de pilha para a tabela de simbolos
noTS * topoTS;


int nivel_lex;
int desloc;

short int dec_vars = 0;    
short int dec_proc = 0;    
short int dec_func = 0;     
short int comando_read = 0;
short int comando_write = 0;
short int atrib = 0;
short int dec_params_subrotina = 0;
short int par_referencia = 0;

char relacao[10];
char lesq[100];
int rotulo_atual = 0;
int n_var = 0;              // Numero da variavel

void yyerror(const char *s) {
	printf("Erro - %s\n linha %d\n", s, num_linha);
	exit(EXIT_FAILURE);
}

int yywrap() {
    printf("Compilado\n");
	return 1;
}

main(int argc, char **argv) {
	yyin=fopen(argv[1], "r");
	yyout=fopen(argv[2], "w");

    empilhaRotulo(0, &topoRotulo);
	yyparse();
}

%}

%token INTEIRO	REAL	IDENTIFICADOR	LABEL	VAR INTEGER
%token IF	THEN	ELSE	WHILE	GOTO	DO
%token READ WRITE	FUNCTION	PROCEDURE
%token PROGRAMA	BEGIN_	END
%token AND	OR	NOT	MAIORIGUAL	MENORIGUAL
%token MAIOR	MENOR	IGUAL	ATRIBUICAO 
%token MAIS	MENOS	MULT	DIV	DIFF
%token ABREPARENTESE	FECHAPARENTESE	ABRECHAVE	FECHACHAVE
%token PTOVIRGULA	DOISPTOS	VIRGULA	PTO

%left MAIS MENOS
%left MULT DIV

%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE

%start programa

%%

programa: PROGRAMA identificador	
			{ 
			  	fprintf(yyout, "INPP\n");
			}
		  	ABREPARENTESE conj_identificadores FECHAPARENTESE PTOVIRGULA bloco PTO 
			{
				fprintf(yyout, "DMEM X\n");
				fprintf(yyout, "PARA\n");
			}
			;

conj_identificadores: identificador
						| conj_identificadores VIRGULA identificador
						;

bloco: bloco_dec_rotulos 
        {   dec_vars=1; }
		bloco_dec_vars 
        {
            dec_vars=0;
            fprintf(yyout, "AMEM %d,%d\n", nivel_lex, n_var);
            n_var = 0;
            fprintf(yyout, "DSVS L%d\n", rotulo_atual);
            empilhaRotulo(rotulo_atual, &topoRotulo);
            rotulo_atual++;
        }
        bloco_dec_subrotinas
		bloco_comandos
		;

bloco_dec_rotulos: 
	| LABEL conj_numeros PTOVIRGULA
					;

conj_numeros: numero_inteiro
	{ fprintf(yyout, "%s", matched); }
	| conj_numeros VIRGULA numero_inteiro
	;

bloco_dec_vars: 
	| VAR conj_dec_vars PTOVIRGULA
				| conj_dec_vars PTOVIRGULA 
				;

conj_dec_vars: conj_identificadores DOISPTOS tipo
				| conj_dec_vars PTOVIRGULA conj_identificadores DOISPTOS tipo
				;

tipo: INTEGER
	| REAL
	;

bloco_dec_subrotinas: 
	| conj_dec_subrotinas PTOVIRGULA
	;

conj_dec_subrotinas: conj_dec_subrotinas PTOVIRGULA dec_subrotinas
	| dec_subrotinas
	;

dec_subrotinas: dec_procedimento
	| dec_funcao
	;

dec_procedimento: PROCEDURE { dec_proc = 1; }
                    identificador 
					{ dec_proc = 0; }
                    params PTOVIRGULA 
                    bloco
					{
						fprintf(yyout, "DMEM %d\n",0);
						fprintf(yyout, "RtPR %d,%d\n", nivel_lex, 0);
						nivel_lex--;
					}
	;

dec_funcao: FUNCTION 
			{ dec_func = 1; }
		 	identificador 
			{ dec_func = 0; }
			params DOISPTOS tipo PTOVIRGULA bloco
	;

params: 
	| ABREPARENTESE 
        {   dec_params_subrotina = 1;   }
        parametros 
        {   dec_params_subrotina = 0;   }
        FECHAPARENTESE
	;

parametros: VAR 
            {   par_referencia = 1; }
            conj_identificadores 
            {   par_referencia = 0; }
            DOISPTOS tipo
	| conj_identificadores DOISPTOS tipo
	| parametros PTOVIRGULA VAR 
            {   par_referencia = 1; }
            conj_identificadores 
            {   par_referencia = 0; }
            DOISPTOS tipo
	| parametros PTOVIRGULA conj_identificadores DOISPTOS tipo
	; 

bloco_comandos: BEGIN_ END
	| BEGIN_ 
                { fprintf(yyout, "L%d NADA\n", desempilhaRotulo(&topoRotulo)); 
                }
                conj_comandos END
				;

conj_comandos: comando 
				| conj_comandos PTOVIRGULA comando
				;

comando: numero_inteiro DOISPTOS comando_sem_rotulo
	| comando_sem_rotulo
	;

comando_sem_rotulo: atribuicao
	| ch_procedimento
	| desvio
	| read
	| write
	| bloco_comandos
	| comando_condicional
	| comando_repetitivo
;

atribuicao: variavel 
            {   atrib = 1; 
                strcpy(lesq, matched);
            }
            ATRIBUICAO expressao
            {   fprintf(yyout, "ARMZ %d,%d\n", buscaNivelLexico(topoTS, lesq), buscaDesloc(topoTS, lesq));
                atrib = 0	;
            }
;

ch_procedimento: identificador 
	| identificador ABREPARENTESE conj_expressoes FECHAPARENTESE 
	;

read: { comando_read = 1; }
        READ ABREPARENTESE conj_expressoes FECHAPARENTESE 
        { comando_read = 0; }
	;

write: { comando_write = 1; } 
        WRITE ABREPARENTESE conj_expressoes FECHAPARENTESE 
        { comando_write = 0; } 
	;

desvio: GOTO numero_inteiro
		{
			fprintf(yyout, "DSVS %d\n", atoi(matched));
		}
	;

comando_condicional: IF expressao THEN comando_sem_rotulo cond_else
;

cond_else:	ELSE comando_sem_rotulo
			| %prec LOWER_THAN_ELSE	;

comando_repetitivo: WHILE expressao DO comando_sem_rotulo
	;

conj_expressoes: expressao
	| conj_expressoes VIRGULA expressao
	;

expressao: expressao_simples
	| expressao_simples relacao expressao_simples
            {   fprintf(yyout, "%s", relacao); }
			;

expressao_simples: termo
	| MAIS termo
	| MENOS termo
	| termo conj_expr_simples
	| MAIS termo conj_expr_simples
	| MENOS termo conj_expr_simples
	;

conj_expr_simples: MAIS termo
	| MENOS termo
	| OR termo
	| conj_expr_simples MAIS termo
	| conj_expr_simples MENOS termo
	| conj_expr_simples OR termo
	;

termo: fator
	| fator conj_termos
	;

conj_termos: MULT fator
	| DIV fator
	| AND fator
	| conj_termos MULT fator
	| conj_termos DIV fator
	| conj_termos AND fator
	;

fator: variavel
	| numero_inteiro
	{
		if ( !comando_read && ! comando_write)
			fprintf(yyout, "CRCT %d\n", atoi(matched));
	}
	| numero_real
	{
		if ( !comando_read && ! comando_write)
			fprintf(yyout, "CRCT %f\n", atof(matched));
	}
	| ch_funcao
	| ABREPARENTESE expressao FECHAPARENTESE
	| NOT fator { fprintf(yyout, "NEGA\n"); }
	;

relacao: IGUAL           { strcpy(relacao, "CMIG\n"); }
	| DIFF          { strcpy(relacao, "CMDG\n"); }
	| MENOR         { strcpy(relacao, "CMME\n"); }
	| MENORIGUAL    { strcpy(relacao, "CMEG\n"); }
	| MAIORIGUAL    { strcpy(relacao, "CMAG\n"); }
	| MAIOR         { strcpy(relacao, "CMMA\n"); }
	;

variavel: identificador;

ch_funcao: identificador ABREPARENTESE conj_expressoes FECHAPARENTESE 
	;

numero_inteiro: INTEIRO
	;

numero_real:	REAL
		;

identificador: IDENTIFICADOR
                {
                    if (dec_vars) {
                        if (!buscaSimbolo(topoTS, nivel_lex, matched)) {
                            empilhaSimbolo(&topoTS, matched, nivel_lex, n_var, VARIAVEL, topoRotulo->rotulo, -1);
                            n_var++;
                        }
                        else {
                            printf("\nErro: %d	| Variavel ja declarada: %s\n", num_linha, matched);
							exit(EXIT_FAILURE);
						}
                    }
                    else if (comando_read == 1) {
						if (!buscaSimbolo(topoTS, nivel_lex, matched)) {
							printf("\nErro| Linha %d | Variavel nao declarada: %s\n", num_linha, matched);
							exit(EXIT_FAILURE);
						}
						else
                        	fprintf(yyout, "LEIT\nARMZ %d,%d\n", buscaNivelLexico(topoTS,matched), buscaDesloc(topoTS, yytext));
                    }
                    else if (dec_proc && !buscaSimbolo(topoTS, nivel_lex, matched)) {
                        fprintf(yyout, "L%d: NADA\n", rotulo_atual);
                        empilhaRotulo(rotulo_atual, &topoRotulo);
                        nivel_lex++;
                        fprintf(yyout,"ENPR %d\n", nivel_lex);
                        empilhaSimbolo(&topoTS, matched, nivel_lex, -1, PROCEDIMENTO, rotulo_atual, -1);
                        rotulo_atual++;
                    }
                    else if (dec_func && !buscaSimbolo(topoTS, nivel_lex, matched)) {
                        fprintf(yyout, "L%d: NADA\n", rotulo_atual);
                        empilhaRotulo(rotulo_atual, &topoRotulo);
                        nivel_lex++;
                        fprintf(yyout,"ENPR %d\n", nivel_lex);
                        empilhaSimbolo(&topoTS, matched, nivel_lex, -1, FUNCAO, rotulo_atual, -1);
                        rotulo_atual++;
                    }
                }
	;


