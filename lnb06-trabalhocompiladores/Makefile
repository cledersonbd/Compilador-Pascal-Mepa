### Makefile compilador ###

lex :   lexarq
	gcc lex.yy.c y.tab.c libmepa.c -o compilador

lexarq : yacc  
	lex -l --header-file=liblex.h lex.l 

yacc: 
	yacc -d -y yacc.y 
	
clear:
	rm -f compilador liblex.h y.tab.h saida.mepa
	
