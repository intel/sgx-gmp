/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

#ifndef YY_YY_CALC_H_INCLUDED
# define YY_YY_CALC_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    EOS = 258,
    BAD = 259,
    HELP = 260,
    HEX = 261,
    DECIMAL = 262,
    QUIT = 263,
    ABS = 264,
    BIN = 265,
    FIB = 266,
    GCD = 267,
    KRON = 268,
    LCM = 269,
    LUCNUM = 270,
    NEXTPRIME = 271,
    POWM = 272,
    ROOT = 273,
    SQRT = 274,
    NUMBER = 275,
    VARIABLE = 276,
    LOR = 277,
    LAND = 278,
    EQ = 279,
    NE = 280,
    LE = 281,
    GE = 282,
    LSHIFT = 283,
    RSHIFT = 284,
    UMINUS = 285
  };
#endif
/* Tokens.  */
#define EOS 258
#define BAD 259
#define HELP 260
#define HEX 261
#define DECIMAL 262
#define QUIT 263
#define ABS 264
#define BIN 265
#define FIB 266
#define GCD 267
#define KRON 268
#define LCM 269
#define LUCNUM 270
#define NEXTPRIME 271
#define POWM 272
#define ROOT 273
#define SQRT 274
#define NUMBER 275
#define VARIABLE 276
#define LOR 277
#define LAND 278
#define EQ 279
#define NE 280
#define LE 281
#define GE 282
#define LSHIFT 283
#define RSHIFT 284
#define UMINUS 285

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 142 "calc.y" /* yacc.c:1909  */

  char  *str;
  int   var;

#line 119 "calc.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_CALC_H_INCLUDED  */
