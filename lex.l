%{
#include "y.tab.h"
#include <stdio.h>
// Variavel para contar o num de linhas
int num_linha = 1;
char matched[100];

%}

A [aA]
B [bB]
C [cC]
D [dD]
E [eE]
F [fF]
G [gG]
H [hH]
I [iI]
J [jJ]
K [kK]
L [lL]
M [mM]
N [nN]
O [oO]
P [pP]
Q [qQ]
R [rR]
S [sS]
T [tT]
U [uU]
V [vV]
W [wW]
X [xX]
Y [yY]
Z [zZ]
PALAVRA [a-zA-Z][a-zA-Z0-9]*
INTEIRO [0-9]+
REAL [0-9]+[.][0-9]+

%%
{INTEIRO} 					{ /*printf("INTEIRO: %s ", yytext); */strcpy(matched, yytext); return INTEIRO; }
{REAL} 						{ /*printf("REAL: %s ", yytext); */strcpy(matched, yytext); return REAL; }
{I}{N}{T}{E}{G}{E}{R}		{ /*printf("INTEGER ");	*/return INTEGER; 	}
{L}{A}{B}{E}{L}             { /*printf("LABEL "); 	*/return LABEL;		}
{V}{A}{R}                   { /*printf("VAR "); 		*/return VAR;			}
{I}{F}                      { /*printf("IF "); 		*/return IF;			}
{T}{H}{E}{N}                { /*printf("THEN ");	 	*/return THEN;		}
{E}{L}{S}{E}                { /*printf("ELSE "); 	 */   return ELSE; 		}
{W}{H}{I}{L}{E}             { /*printf("WHILE "); 	*/return WHILE;		}
{G}{O}{T}{O}	            {/* printf("GOTO ");	 	*/return GOTO; 		}
{D}{O}                      {/* printf("DO "); 		*/return DO;			}
{R}{E}{A}{D}                { /*printf("READ "); 	*/return READ; 		    }
{W}{R}{I}{T}{E}             { /*printf("WRITE "); 	*/return WRITE; 		}
{P}{R}{O}{G}{R}{A}{M}       { /*printf("PROGRAMA "); */return PROGRAMA;	    }
{B}{E}{G}{I}{N}             { /*printf("BEGIN ");	*/return BEGIN_;		    }
{E}{N}{D}	                { /*printf("END "); 	*/	return END;			}
{F}{U}{N}{C}{T}{I}{O}{N}    { /*printf("FUNCTION "); */return FUNCTION;     }
{P}{R}{O}{C}{E}{D}{U}{R}{E} { /*printf("PROCEDURE ");  */return PROCEDURE;  }
{A}{N}{D}                   { /*printf("AND "); */return AND ;}
{O}{R}                      { /*printf("OR "); */return OR; }
{N}{O}{T}                   { /*printf("NOT "); */return NOT; }
\:\=                        { /*printf("ATRIBUICAO "); */return ATRIBUICAO;}
\+                          { /*printf("MAIS "); */return MAIS; }
\-                          { /*printf("MENOS "); */return MENOS; }
\*                          { /*printf("MULT ");		*/return MULT; }
{D}{I}{V}					{ /*printf("DIV "); 		*/return DIV; 		}
\<>                         { /*printf("DIFF ");		*/return DIFF; }
\>\=                        { /*printf("MAIORIGUAL "); */return MAIORIGUAL; }
\<\=                        { /*printf("MENORIGUAL "); */return MENORIGUAL; }
\>                          { /*printf("MAIOR ");		*/return MAIOR; }
\<                          { /*printf("MENOR "); 		*/return MENOR; }
\=                          { /*printf("IGUAL "); 		*/return IGUAL; }
\(                          { /*printf("ABREPARENTESE "); */return ABREPARENTESE; }
\)                          { /*printf("FECHAPARENTESE "); */return FECHAPARENTESE; }
\{                          { /*printf("ABRECHAVE "); */return ABRECHAVE; }
\}                          { /*printf("FECHACHAVE "); */return FECHACHAVE; }
\;                          { /*printf("PTOVIRGULA "); */return PTOVIRGULA; }
\:                          { /*printf("DOISPTOS ");	*/		return DOISPTOS; }
\,                          { /*printf("VIRGULA "); */return VIRGULA; }
\.                          { /*printf("PTO "); */return PTO;}
\n							{ /*num_linha++; */printf("\n"); }
{PALAVRA}                   { /*printf("IDENTIFICADOR: %s ", yytext);*/ strcpy(matched, yytext); return IDENTIFICADOR;}
[ \t\n]+
%%

