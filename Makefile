
main: yacc lex libUtil.c libUtil.h 
	gcc lex.yy.c y.tab.c libUtil.c -o miniPascalCompiler

lex: lex.l
	flex -l --header-file=liblex.h lex.l

yacc: yacc.y
	yacc -d -y yacc.y

clean:
	rm -rf lex.yy.c liblex.h y.tab.c y.tab.h miniPascalCompiler
