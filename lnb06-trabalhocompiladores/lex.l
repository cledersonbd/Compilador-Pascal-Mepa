%{
#include <stdio.h>
#include <string.h>
#include "y.tab.h"
void yyerror(char *);
int linha;
char retorno[100];

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

%%
{INTEIRO}                   { strcpy(retorno,yytext); return(INTEIRO); }
{I}{N}{T}{E}{G}{E}{R}		 { return(INTEGER); }
{L}{A}{B}{E}{L}             { return(LABEL); }
{V}{A}{R}                   { return(VAR); }
{I}{F}                      { return(IF); }
{T}{H}{E}{N}                { return(THEN); }
{E}{L}{S}{E}                { return(ELSE); }
{W}{H}{I}{L}{E}             { return(WHILE); }
{G}{O}{T}{O}	             { return(GOTO); }
{D}{O}                      { return(DO); }
{R}{E}{A}{D}                { return(READ); }
{W}{R}{I}{T}{E}             { return(WRITE); }
{P}{R}{O}{G}{R}{A}{M}       { return(PROGRAM); }
{B}{E}{G}{I}{N}             { return(_BEGIN); }
{E}{N}{D}	                { return(END); }
{F}{U}{N}{C}{T}{I}{O}{N}    { return(FUNCTION); }
{P}{R}{O}{C}{E}{D}{U}{R}{E} { return(PROCEDURE); }
{A}{N}{D}                   { return(AND); }
{O}{R}                      { return(OR); }
{N}{O}{T}                   { return(NOT); }
\:\=                        { return(ATRIBUICAO); } 
\+                          { return(MAIS); }
\-                          { return(MENOS); }
\*                          { return(MULT); }
{D}{I}{V}                   { return(DIV); }
\<>                         { return(DIF); }
\>\=                        { return(MAIORIG); }
\<\=                        { return(MENORIG); }
\>                          { return(MAIOR); }
\<                          { return(MENOR); }
\=                          { return(IGUAL); }
\(                          { return(ABREPAR); }
\)                          { return(FECHAPAR); }
\{			   					 { return(ABRECH); }
\}			   					 { return(FECHACH); }
\;			   					 { return(PTOVIRG); }
\:			   					 { return(DOISPTS); }
\,									 { return(VIRGULA); }
\.									 { return(PONTO); }
\n			    					 linha++;
{PALAVRA}                   { strcpy(retorno,yytext); return(IDENT); }
[ \t\n]+
%%