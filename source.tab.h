/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_SOURCE_TAB_H_INCLUDED
# define YY_YY_SOURCE_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    T_EQ = 258,                    /* T_EQ  */
    T_LE = 259,                    /* T_LE  */
    T_GE = 260,                    /* T_GE  */
    T_NEQ = 261,                   /* T_NEQ  */
    T_INT_KW = 262,                /* T_INT_KW  */
    T_FLOAT_KW = 263,              /* T_FLOAT_KW  */
    T_DOUBLE_KW = 264,             /* T_DOUBLE_KW  */
    T_INT_CAST = 265,              /* T_INT_CAST  */
    T_FLOAT_CAST = 266,            /* T_FLOAT_CAST  */
    T_DOUBLE_CAST = 267,           /* T_DOUBLE_CAST  */
    T_IF_KW = 268,                 /* T_IF_KW  */
    T_WHILE_KW = 269,              /* T_WHILE_KW  */
    T_ELSE_KW = 270,               /* T_ELSE_KW  */
    T_VOID_KW = 271,               /* T_VOID_KW  */
    T_RETURN = 272,                /* T_RETURN  */
    T_COMM = 273,                  /* T_COMM  */
    T_ERROR = 274,                 /* T_ERROR  */
    T_PRINTF_PARAM = 275,          /* T_PRINTF_PARAM  */
    T_PRINTF_SIMPLE = 276,         /* T_PRINTF_SIMPLE  */
    T_SCANF = 277,                 /* T_SCANF  */
    T_INTEGER_VAL = 278,           /* T_INTEGER_VAL  */
    T_IDENTIFIER = 279,            /* T_IDENTIFIER  */
    T_DOUBLE_VAL = 280,            /* T_DOUBLE_VAL  */
    T_FLOAT_VAL = 281              /* T_FLOAT_VAL  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 30 "source.y"
int intval; char *str; double dval; struct lbs *lbVal; float fval;

#line 93 "source.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;

int yyparse (void);


#endif /* !YY_YY_SOURCE_TAB_H_INCLUDED  */
