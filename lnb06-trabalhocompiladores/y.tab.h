
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     INTEIRO = 258,
     IDENT = 259,
     LABEL = 260,
     VAR = 261,
     INTEGER = 262,
     IF = 263,
     THEN = 264,
     ELSE = 265,
     WHILE = 266,
     GOTO = 267,
     DO = 268,
     READ = 269,
     WRITE = 270,
     FUNCTION = 271,
     PROCEDURE = 272,
     PROGRAM = 273,
     _BEGIN = 274,
     END = 275,
     AND = 276,
     OR = 277,
     NOT = 278,
     MAIORIG = 279,
     MENORIG = 280,
     MAIOR = 281,
     MENOR = 282,
     IGUAL = 283,
     ATRIBUICAO = 284,
     MAIS = 285,
     MENOS = 286,
     MULT = 287,
     DIV = 288,
     DIF = 289,
     ABREPAR = 290,
     FECHAPAR = 291,
     ABRECH = 292,
     FECHACH = 293,
     PTOVIRG = 294,
     DOISPTS = 295,
     VIRGULA = 296,
     PONTO = 297,
     LOWER_THEN_ELSE = 298
   };
#endif
/* Tokens.  */
#define INTEIRO 258
#define IDENT 259
#define LABEL 260
#define VAR 261
#define INTEGER 262
#define IF 263
#define THEN 264
#define ELSE 265
#define WHILE 266
#define GOTO 267
#define DO 268
#define READ 269
#define WRITE 270
#define FUNCTION 271
#define PROCEDURE 272
#define PROGRAM 273
#define _BEGIN 274
#define END 275
#define AND 276
#define OR 277
#define NOT 278
#define MAIORIG 279
#define MENORIG 280
#define MAIOR 281
#define MENOR 282
#define IGUAL 283
#define ATRIBUICAO 284
#define MAIS 285
#define MENOS 286
#define MULT 287
#define DIV 288
#define DIF 289
#define ABREPAR 290
#define FECHAPAR 291
#define ABRECH 292
#define FECHACH 293
#define PTOVIRG 294
#define DOISPTS 295
#define VIRGULA 296
#define PONTO 297
#define LOWER_THEN_ELSE 298




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


