/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "source.y"

    #define DEBUGGER 1      // 0 - no debugger, 1 - print instructions and variables; 2 - print every instruction executed 3 - also how stack
    
    #include <stdio.h>
    #include <stdlib.h>
    #include "CG.h"
    #include "SM.h"
    #include "flowHeader.h"
    #include "utils.h"
    #include "functionHandler.h"
    #include "VTR.h"
    
    extern FILE* yyin;
    int noErrors = 0;
    int errors;
    int yylex();
    int yyerror(const char *msg);
    extern int lineNo;

    char currentfunction[256];

    enum varType currentType;    

#line 95 "source.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "source.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_T_EQ = 3,                       /* T_EQ  */
  YYSYMBOL_T_LE = 4,                       /* T_LE  */
  YYSYMBOL_T_GE = 5,                       /* T_GE  */
  YYSYMBOL_T_NEQ = 6,                      /* T_NEQ  */
  YYSYMBOL_T_INT_KW = 7,                   /* T_INT_KW  */
  YYSYMBOL_T_FLOAT_KW = 8,                 /* T_FLOAT_KW  */
  YYSYMBOL_T_DOUBLE_KW = 9,                /* T_DOUBLE_KW  */
  YYSYMBOL_T_IF_KW = 10,                   /* T_IF_KW  */
  YYSYMBOL_T_WHILE_KW = 11,                /* T_WHILE_KW  */
  YYSYMBOL_T_ELSE_KW = 12,                 /* T_ELSE_KW  */
  YYSYMBOL_T_VOID_KW = 13,                 /* T_VOID_KW  */
  YYSYMBOL_T_RETURN = 14,                  /* T_RETURN  */
  YYSYMBOL_T_COMM = 15,                    /* T_COMM  */
  YYSYMBOL_T_ERROR = 16,                   /* T_ERROR  */
  YYSYMBOL_T_PRINTF_PARAM = 17,            /* T_PRINTF_PARAM  */
  YYSYMBOL_T_PRINTF_SIMPLE = 18,           /* T_PRINTF_SIMPLE  */
  YYSYMBOL_T_SCANF = 19,                   /* T_SCANF  */
  YYSYMBOL_T_INTEGER_VAL = 20,             /* T_INTEGER_VAL  */
  YYSYMBOL_T_IDENTIFIER = 21,              /* T_IDENTIFIER  */
  YYSYMBOL_T_DOUBLE_VAL = 22,              /* T_DOUBLE_VAL  */
  YYSYMBOL_23_ = 23,                       /* '+'  */
  YYSYMBOL_24_ = 24,                       /* '-'  */
  YYSYMBOL_25_ = 25,                       /* '>'  */
  YYSYMBOL_26_ = 26,                       /* '<'  */
  YYSYMBOL_27_ = 27,                       /* '*'  */
  YYSYMBOL_28_ = 28,                       /* '/'  */
  YYSYMBOL_29_ = 29,                       /* '('  */
  YYSYMBOL_30_ = 30,                       /* ')'  */
  YYSYMBOL_31_ = 31,                       /* '{'  */
  YYSYMBOL_32_ = 32,                       /* '}'  */
  YYSYMBOL_33_ = 33,                       /* ','  */
  YYSYMBOL_34_ = 34,                       /* ';'  */
  YYSYMBOL_35_ = 35,                       /* '='  */
  YYSYMBOL_YYACCEPT = 36,                  /* $accept  */
  YYSYMBOL_program = 37,                   /* program  */
  YYSYMBOL_functions = 38,                 /* functions  */
  YYSYMBOL_function_declaration = 39,      /* function_declaration  */
  YYSYMBOL_40_1 = 40,                      /* $@1  */
  YYSYMBOL_41_2 = 41,                      /* $@2  */
  YYSYMBOL_42_3 = 42,                      /* $@3  */
  YYSYMBOL_43_4 = 43,                      /* $@4  */
  YYSYMBOL_44_5 = 44,                      /* $@5  */
  YYSYMBOL_45_6 = 45,                      /* $@6  */
  YYSYMBOL_parameter_list = 46,            /* parameter_list  */
  YYSYMBOL_parameter_list_tail = 47,       /* parameter_list_tail  */
  YYSYMBOL_midrule_lbs = 48,               /* midrule_lbs  */
  YYSYMBOL_function_call = 49,             /* function_call  */
  YYSYMBOL_argument_list = 50,             /* argument_list  */
  YYSYMBOL_argument_list_tail = 51,        /* argument_list_tail  */
  YYSYMBOL_instructions = 52,              /* instructions  */
  YYSYMBOL_53_7 = 53,                      /* $@7  */
  YYSYMBOL_54_8 = 54,                      /* $@8  */
  YYSYMBOL_55_9 = 55,                      /* $@9  */
  YYSYMBOL_56_10 = 56,                     /* $@10  */
  YYSYMBOL_57_11 = 57,                     /* $@11  */
  YYSYMBOL_58_12 = 58,                     /* $@12  */
  YYSYMBOL_59_13 = 59,                     /* $@13  */
  YYSYMBOL_60_14 = 60,                     /* $@14  */
  YYSYMBOL_61_15 = 61,                     /* $@15  */
  YYSYMBOL_62_16 = 62,                     /* $@16  */
  YYSYMBOL_instruction = 63,               /* instruction  */
  YYSYMBOL_declarations = 64,              /* declarations  */
  YYSYMBOL_declaration = 65,               /* declaration  */
  YYSYMBOL_type = 66,                      /* type  */
  YYSYMBOL_variable_list = 67,             /* variable_list  */
  YYSYMBOL_variable_declaration = 68,      /* variable_declaration  */
  YYSYMBOL_variable_load = 69,             /* variable_load  */
  YYSYMBOL_expression = 70                 /* expression  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  36
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   222

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  36
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  35
/* YYNRULES -- Number of rules.  */
#define YYNRULES  74
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  137

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   277


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      29,    30,    27,    23,    33,    24,     2,    28,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    34,
      26,    35,    25,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    31,     2,    32,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    71,    71,    75,    76,    79,    80,    82,    88,    90,
      82,   101,   107,   109,   101,   122,   123,   126,   127,   131,
     135,   151,   152,   155,   156,   159,   160,   161,   177,   178,
     180,   161,   182,   187,   188,   190,   182,   192,   194,   192,
     198,   199,   200,   201,   202,   203,   204,   221,   314,   416,
     417,   421,   425,   426,   427,   431,   432,   436,   445,   460,
     474,   486,   487,   488,   489,   490,   491,   492,   493,   494,
     495,   496,   497,   498,   499
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "T_EQ", "T_LE", "T_GE",
  "T_NEQ", "T_INT_KW", "T_FLOAT_KW", "T_DOUBLE_KW", "T_IF_KW",
  "T_WHILE_KW", "T_ELSE_KW", "T_VOID_KW", "T_RETURN", "T_COMM", "T_ERROR",
  "T_PRINTF_PARAM", "T_PRINTF_SIMPLE", "T_SCANF", "T_INTEGER_VAL",
  "T_IDENTIFIER", "T_DOUBLE_VAL", "'+'", "'-'", "'>'", "'<'", "'*'", "'/'",
  "'('", "')'", "'{'", "'}'", "','", "';'", "'='", "$accept", "program",
  "functions", "function_declaration", "$@1", "$@2", "$@3", "$@4", "$@5",
  "$@6", "parameter_list", "parameter_list_tail", "midrule_lbs",
  "function_call", "argument_list", "argument_list_tail", "instructions",
  "$@7", "$@8", "$@9", "$@10", "$@11", "$@12", "$@13", "$@14", "$@15",
  "$@16", "instruction", "declarations", "declaration", "type",
  "variable_list", "variable_declaration", "variable_load", "expression", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-32)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-41)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     129,   -32,   -32,   -32,   -28,   -32,   -18,    -3,   -32,   -32,
     -32,   -32,   -32,   -20,   -32,    13,   -32,   -32,   -32,   -14,
     -32,    60,     3,   -32,    -3,    -6,   -32,   -32,    -2,   -32,
      -3,   -32,   194,    -3,    -1,   147,   -32,    52,   147,   -32,
      29,   -21,   -32,   -12,     6,    -3,    27,   166,    -3,    -3,
      -3,    -3,    -3,    -3,    -3,    -3,    -3,    -3,   194,    -3,
      26,   -32,    41,   -32,    28,    -3,    42,    29,   -32,   179,
     -32,   -32,   -22,   -22,   -22,   -22,   -22,   -22,   -22,   -22,
     -32,   -32,    40,    49,   -32,   -32,   194,   -32,   -32,    47,
     -32,    60,   -32,    -3,   -32,   147,    60,   147,    48,    51,
      62,    49,   -32,    54,    56,   -32,    55,    57,   -32,    61,
     -32,   147,   -32,    60,   -32,   -32,    79,    67,   147,    73,
     147,   -32,   -32,    69,    57,    70,    72,   147,   -32,   -32,
     -32,   147,   -32,    74,   -32,   147,   -32
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
      25,    52,    54,    53,     0,    32,     0,     0,    41,     4,
      47,    46,    48,    19,    37,     0,     5,    42,     3,     0,
      44,    49,     0,    45,     0,     0,     7,    62,    60,    61,
       0,    74,    43,     0,     0,    25,     1,     2,    25,    50,
       0,    57,    51,    55,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    59,    21,
       0,     6,     0,    26,    57,     0,     0,     0,    27,     0,
       8,    73,    71,    68,    70,    72,    63,    64,    69,    67,
      65,    66,     0,    23,    38,    11,    58,    12,    56,     0,
      33,    15,    20,     0,    22,    25,    15,    25,     0,     0,
       0,    23,    39,     0,     0,    34,     0,    17,    24,     0,
      28,    25,     9,     0,    16,    13,     0,     0,    25,     0,
      25,    29,    35,     0,    17,     0,     0,    25,    10,    18,
      14,    25,    36,     0,    30,    25,    31
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -32,   -32,   -32,    68,   -32,   -32,   -32,   -32,   -32,   -32,
      11,   -16,   -32,     0,   -32,     8,   -31,   -32,   -32,   -32,
     -32,   -32,   -32,   -32,   -32,   -32,   -32,   -32,    89,   -32,
       2,    45,   -32,   -32,    -8
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    15,    37,    16,    46,    91,   118,    66,    96,   120,
      99,   114,    34,    31,    82,    94,    18,    89,   116,   126,
     135,    25,    98,   111,   127,    35,    95,    19,    20,    21,
      40,    42,    43,    23,    32
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      17,    24,    22,    26,    60,    56,    57,    63,   -11,    48,
      49,    50,    51,    36,    65,    33,    44,    27,    28,    29,
      38,    67,    47,    45,    41,    58,    30,   -19,    59,    52,
      53,    54,    55,    56,    57,    17,    68,    69,    17,    62,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      64,    83,    48,    49,    50,    51,    70,    86,    84,     1,
       2,     3,    85,    65,   102,     6,   104,     1,     2,     3,
      92,    87,    52,    53,    54,    55,    56,    57,    97,   105,
     117,   106,    93,   107,   109,   101,   112,   123,   110,   125,
     113,   121,   115,   100,   124,    17,   132,    17,   100,   122,
     133,   128,   130,   131,   136,    61,   134,   103,   129,   108,
      39,    17,    88,     0,     0,   119,     0,     0,    17,     0,
      17,     0,     0,     0,     0,     0,     0,    17,     0,     0,
       0,    17,     0,     0,     0,    17,     1,     2,     3,     4,
       5,     0,     6,     7,     8,     9,    10,    11,    12,     0,
      13,     0,     0,     0,     1,     2,     3,     4,     5,     0,
      14,     7,     8,   -40,    10,    11,    12,     0,    13,    48,
      49,    50,    51,     0,     0,     0,     0,     0,    14,     0,
       0,   -40,    48,    49,    50,    51,     0,     0,     0,    52,
      53,    54,    55,    56,    57,     0,    71,    48,    49,    50,
      51,     0,    52,    53,    54,    55,    56,    57,     0,    90,
       0,     0,     0,     0,     0,     0,     0,    52,    53,    54,
      55,    56,    57
};

static const yytype_int16 yycheck[] =
{
       0,    29,     0,    21,    35,    27,    28,    38,    29,     3,
       4,     5,     6,     0,    35,    35,    24,    20,    21,    22,
      34,    33,    30,    29,    21,    33,    29,    29,    29,    23,
      24,    25,    26,    27,    28,    35,    30,    45,    38,    37,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      21,    59,     3,     4,     5,     6,    29,    65,    32,     7,
       8,     9,    21,    35,    95,    13,    97,     7,     8,     9,
      30,    29,    23,    24,    25,    26,    27,    28,    31,    31,
     111,    30,    33,    21,    30,    93,    31,   118,    32,   120,
      33,    12,    31,    91,    21,    95,   127,    97,    96,    32,
     131,    32,    32,    31,   135,    37,    32,    96,   124,   101,
      21,   111,    67,    -1,    -1,   113,    -1,    -1,   118,    -1,
     120,    -1,    -1,    -1,    -1,    -1,    -1,   127,    -1,    -1,
      -1,   131,    -1,    -1,    -1,   135,     7,     8,     9,    10,
      11,    -1,    13,    14,    15,    16,    17,    18,    19,    -1,
      21,    -1,    -1,    -1,     7,     8,     9,    10,    11,    -1,
      31,    14,    15,    34,    17,    18,    19,    -1,    21,     3,
       4,     5,     6,    -1,    -1,    -1,    -1,    -1,    31,    -1,
      -1,    34,     3,     4,     5,     6,    -1,    -1,    -1,    23,
      24,    25,    26,    27,    28,    -1,    30,     3,     4,     5,
       6,    -1,    23,    24,    25,    26,    27,    28,    -1,    30,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    23,    24,    25,
      26,    27,    28
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     7,     8,     9,    10,    11,    13,    14,    15,    16,
      17,    18,    19,    21,    31,    37,    39,    49,    52,    63,
      64,    65,    66,    69,    29,    57,    21,    20,    21,    22,
      29,    49,    70,    35,    48,    61,     0,    38,    34,    64,
      66,    21,    67,    68,    70,    29,    40,    70,     3,     4,
       5,     6,    23,    24,    25,    26,    27,    28,    70,    29,
      52,    39,    66,    52,    21,    35,    43,    33,    30,    70,
      29,    30,    70,    70,    70,    70,    70,    70,    70,    70,
      70,    70,    50,    70,    32,    21,    70,    29,    67,    53,
      30,    41,    30,    33,    51,    62,    44,    31,    58,    46,
      66,    70,    52,    46,    52,    31,    30,    21,    51,    30,
      32,    59,    31,    33,    47,    31,    54,    52,    42,    66,
      45,    12,    32,    52,    21,    52,    55,    60,    32,    47,
      32,    31,    52,    52,    32,    56,    52
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    36,    37,    37,    37,    38,    38,    40,    41,    42,
      39,    43,    44,    45,    39,    46,    46,    47,    47,    48,
      49,    50,    50,    51,    51,    52,    52,    53,    54,    55,
      56,    52,    57,    58,    59,    60,    52,    61,    62,    52,
      63,    63,    63,    63,    63,    63,    63,    63,    63,    64,
      64,    65,    66,    66,    66,    67,    67,    68,    68,    69,
      70,    70,    70,    70,    70,    70,    70,    70,    70,    70,
      70,    70,    70,    70,    70
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     1,     1,     0,     2,     0,     0,     0,
      11,     0,     0,     0,    11,     0,     3,     0,     4,     0,
       5,     0,     2,     0,     3,     0,     3,     0,     0,     0,
       0,    16,     0,     0,     0,     0,    12,     0,     0,     6,
       0,     1,     1,     2,     1,     1,     1,     1,     1,     1,
       2,     2,     1,     1,     1,     1,     3,     1,     3,     3,
       1,     1,     1,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)


/* YYLOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

# ifndef YYLOCATION_PRINT

#  if defined YY_LOCATION_PRINT

   /* Temporary convenience wrapper in case some people defined the
      undocumented and private YY_LOCATION_PRINT macros.  */
#   define YYLOCATION_PRINT(File, Loc)  YY_LOCATION_PRINT(File, *(Loc))

#  elif defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
}

#   define YYLOCATION_PRINT  yy_location_print_

    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT(File, Loc)  YYLOCATION_PRINT(File, &(Loc))

#  else

#   define YYLOCATION_PRINT(File, Loc) ((void) 0)
    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT  YYLOCATION_PRINT

#  endif
# endif /* !defined YYLOCATION_PRINT */


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (yylocationp);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  YYLOCATION_PRINT (yyo, yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yykind, yyvaluep, yylocationp);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)],
                       &(yylsp[(yyi + 1) - (yynrhs)]));
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YY_USE (yyvaluep);
  YY_USE (yylocationp);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

    /* The location stack: array, bottom, top.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls = yylsa;
    YYLTYPE *yylsp = yyls;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[3];



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  yylsp[0] = yylloc;
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      yyerror_range[1] = yylloc;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 4: /* program: T_ERROR  */
#line 76 "source.y"
                                             {errors++;}
#line 1376 "source.tab.c"
    break;

  case 7: /* $@1: %empty  */
#line 82 "source.y"
                                                 {
                                                if(strcmp((yyvsp[0].str), "main") == 0) 
                                                    entryPoint = getCurrentIndex(); 
                                                addFunction((yyvsp[0].str), getCurrentIndex())->type = currentType; 
                                                strcpy(currentfunction, (yyvsp[0].str));
                                            }
#line 1387 "source.tab.c"
    break;

  case 8: /* $@2: %empty  */
#line 88 "source.y"
                                            {genCode(INC_SCOPE, "", 0, -1, (yylsp[-3]).first_line);}
#line 1393 "source.tab.c"
    break;

  case 9: /* $@3: %empty  */
#line 90 "source.y"
                                            {
                                                
                                            }
#line 1401 "source.tab.c"
    break;

  case 10: /* function_declaration: T_VOID_KW T_IDENTIFIER $@1 '(' $@2 parameter_list ')' '{' $@3 instructions '}'  */
#line 94 "source.y"
                                            {
                                                
                                                genCode(DEC_SCOPE, "", 0, -1, (yylsp[-10]).first_line);
                                                genCode(RET, "void", 0, 0, (yylsp[-10]).first_line);
                                                if(strcmp(currentfunction, "main")==0)
                                                    genCode(HALT, "", 0, -1, (yylsp[-10]).first_line);
                                            }
#line 1413 "source.tab.c"
    break;

  case 11: /* $@4: %empty  */
#line 101 "source.y"
                                              {
                                                if(strcmp((yyvsp[0].str), "main") == 0) 
                                                    entryPoint = getCurrentIndex(); 
                                                addFunction((yyvsp[0].str), getCurrentIndex())->type = currentType; 
                                                strcpy(currentfunction, (yyvsp[0].str));
                                            }
#line 1424 "source.tab.c"
    break;

  case 12: /* $@5: %empty  */
#line 107 "source.y"
                                            {genCode(INC_SCOPE, "", 0, -1, (yylsp[-3]).first_line);}
#line 1430 "source.tab.c"
    break;

  case 13: /* $@6: %empty  */
#line 109 "source.y"
                                            {
                                                
                                            }
#line 1438 "source.tab.c"
    break;

  case 14: /* function_declaration: type T_IDENTIFIER $@4 '(' $@5 parameter_list ')' '{' $@6 instructions '}'  */
#line 113 "source.y"
                                            {
                                                
                                                genCode(DEC_SCOPE, "", 0, -1, (yylsp[-10]).first_line);
                                                genCode(RET, "", 0, -1, (yylsp[-10]).first_line);
                                                if(strcmp(currentfunction, "main")==0)
                                                    genCode(HALT, "", 0, -1, (yylsp[-10]).first_line);
                                            }
#line 1450 "source.tab.c"
    break;

  case 16: /* parameter_list: type T_IDENTIFIER parameter_list_tail  */
#line 123 "source.y"
                                                    {genCode(DECL, (yyvsp[-1].str), 0, 0, (yylsp[-2]).first_line); genCode(STORE, (yyvsp[-1].str), 0, 0, (yylsp[-2]).first_line); }
#line 1456 "source.tab.c"
    break;

  case 18: /* parameter_list_tail: ',' type T_IDENTIFIER parameter_list_tail  */
#line 127 "source.y"
                                                {genCode(DECL, (yyvsp[-1].str), 0, 0, (yylsp[-3]).first_line); genCode(STORE, (yyvsp[-1].str), 0, 0, (yylsp[-3]).first_line); }
#line 1462 "source.tab.c"
    break;

  case 19: /* midrule_lbs: %empty  */
#line 131 "source.y"
                                                { (yyval.lbVal) = (struct lbs*) newLbRec(); (yyval.lbVal)->forGoto = reserveLoc(); }
#line 1468 "source.tab.c"
    break;

  case 20: /* function_call: T_IDENTIFIER midrule_lbs '(' argument_list ')'  */
#line 137 "source.y"
                                                {
                                                    functionRecord* ptr = getFunction((yyvsp[-4].str));
                                                    if(ptr == NULL)
                                                    {
                                                        printf("Line %d: Function \"%s\" not found\n", (yylsp[-4]).first_line, (yyvsp[-4].str));
                                                        errors++;
                                                        break;
                                                    }
                                                    genCode(GOTO, "", getFunction((yyvsp[-4].str))->functionIndex, 1, (yylsp[-4]).first_line);
                                                    backPatch((yyvsp[-3].lbVal)->forGoto, DATA, "", getCurrentIndex(), 1, (yylsp[-4]).first_line);
                                                }
#line 1484 "source.tab.c"
    break;

  case 27: /* $@7: %empty  */
#line 161 "source.y"
                                            {
                                                (yyvsp[-3].lbVal) = (struct lbs*) newLbRec();
                                                (yyvsp[-3].lbVal)->forJmpFalse = reserveLoc();
                                                
                                                // if($3 != 0)
                                                // {
                                                //     currentIfCondition[ifCount++] = 1;
                                                //     shouldExecute = 1;
                                                // }
                                                // else
                                                // {
                                                //     currentIfCondition[ifCount++] = 0;
                                                //     shouldExecute = 0;
                                                // }
                                            }
#line 1504 "source.tab.c"
    break;

  case 28: /* $@8: %empty  */
#line 177 "source.y"
                                            {  }
#line 1510 "source.tab.c"
    break;

  case 29: /* $@9: %empty  */
#line 178 "source.y"
                                            {(yyvsp[-9].lbVal)->forGoto = reserveLoc();backPatch((yyvsp[-9].lbVal)->forJmpFalse, JMP_FALSE, "", getCurrentIndex(), 1, (yylsp[-9]).first_line); }
#line 1516 "source.tab.c"
    break;

  case 30: /* $@10: %empty  */
#line 180 "source.y"
                                            { backPatch((yyvsp[-13].lbVal)->forGoto, GOTO, "", getCurrentIndex(), 1, (yylsp[-13]).first_line);}
#line 1522 "source.tab.c"
    break;

  case 32: /* $@11: %empty  */
#line 182 "source.y"
                                            {
                                                (yyvsp[0].lbVal) = (struct lbs*) newLbRec();
                                                (yyvsp[0].lbVal)->forGoto = getCurrentIndex();
                                            }
#line 1531 "source.tab.c"
    break;

  case 33: /* $@12: %empty  */
#line 187 "source.y"
                                            {(yyvsp[-4].lbVal)->forJmpFalse = reserveLoc();}
#line 1537 "source.tab.c"
    break;

  case 34: /* $@13: %empty  */
#line 188 "source.y"
                                            {genCode(INC_SCOPE, "", 0, -1, (yylsp[-6]).first_line);}
#line 1543 "source.tab.c"
    break;

  case 35: /* $@14: %empty  */
#line 190 "source.y"
                                            {genCode(DEC_SCOPE, "", 0, -1, (yylsp[-9]).first_line); genCode(GOTO, "", (yyvsp[-9].lbVal)->forGoto, 1, (yylsp[-9]).first_line); backPatch((yyvsp[-9].lbVal)->forJmpFalse, JMP_FALSE, "", getCurrentIndex(), 1, (yylsp[-9]).first_line);}
#line 1549 "source.tab.c"
    break;

  case 37: /* $@15: %empty  */
#line 192 "source.y"
                                            {genCode(INC_SCOPE, "", 0, -1, (yylsp[0]).first_line);}
#line 1555 "source.tab.c"
    break;

  case 38: /* $@16: %empty  */
#line 194 "source.y"
                                            {genCode(DEC_SCOPE, "", 0, -1, (yylsp[-3]).first_line);}
#line 1561 "source.tab.c"
    break;

  case 46: /* instruction: T_PRINTF_SIMPLE  */
#line 204 "source.y"
                                            {
                                                genCode(PRINTF, (yyvsp[0].str), 0, 3, (yylsp[0]).first_line);
                                                // if(errors > 0 || shouldExecute == 0) break;
                                                // char buffer[1024] = "";
                                                // strcpy(buffer, $1 + strlen("printf(\"")); // eliminare printf(" de la inceput
                                                // buffer[strlen(buffer) - 2] = '\0'; //eliminare ") de la final
                                                // for(int i = 0; i < strlen(buffer); i++) // afisare manuala pentru ca \n sa mearga
                                                // {
                                                //     if(buffer[i] == '\\')
                                                //     {
                                                //         handleBackSlashForBuffer(buffer[i+1]);
                                                //         i++;
                                                //         continue;
                                                //     }
                                                //     printf("%c", buffer[i]);
                                                // }
                                            }
#line 1583 "source.tab.c"
    break;

  case 47: /* instruction: T_PRINTF_PARAM  */
#line 221 "source.y"
                                            {
                                                genCode(PRINTF, (yyvsp[0].str), 1, 2, (yylsp[0]).first_line);
                                                // if(errors > 0 || shouldExecute == 0) break;
                                                // char buffer[1024];
                                                // char varName[1024] = "";
                                                // strcpy(buffer, $1 + strlen("printf(\""));  // eliminare printf(" de la inceput
                                                // char* p = strchr(buffer, '\"');
                                                // p+=2;                           //eliminare ",
                                                // int formatSize = strlen(buffer) - strlen(p) - 2;     //-2 pentru ca am facut p += 2
                                                // for(int i = 0; i < formatSize && buffer[i] != '\"' && errors == 0; i++)
                                                // {
                                                //     if(buffer[i] == '%')
                                                //     {
                                                //         varRecord* ptr = NULL;
                                                //         while(p[0] == ' ') p++;
                                                //         i++;
                                                //         int j = 0;
                                                //         strcpy(varName, "");
                                                //         switch(buffer[i])
                                                //         {
                                                //             case 'd':
                                                //                 while(p[0] != ',' && p[0] != ')')
                                                //                 {
                                                //                     varName[j++] = p[0];
                                                //                     p++;
                                                //                 }

                                                //                 ptr = getVar(varName);
                                                //                 if(ptr == 0)
                                                //                 {
                                                //                     printf("line %d: Identifier %s not declared.\n", @1.first_line, varName); 
                                                //                     errors++;
                                                //                     break;
                                                //                 }
                                                //                 printf("%d",(int)getVar(varName)->value);
                                                //             break;
                                                //             case 'f':
                                                //                 while(p[0] != ',' && p[0] != ')')
                                                //                 {
                                                //                     varName[j++] = p[0];
                                                //                     p++;
                                                //                 }
                                                //                 ptr = getVar(varName);
                                                //                 if(ptr == 0)
                                                //                 {
                                                //                     printf("line %d: Identifier %s not declared.\n", @1.first_line, varName); 
                                                //                     errors++;
                                                //                     break;
                                                //                 }
                                                //                 printf("%f", (float)getVar(varName)->value);
                                                //                 break;
                                                //             case 'l':
                                                //                 i++;
                                                //                 if(buffer[i] != 'f')
                                                //                 {
                                                //                     errors++;
                                                //                     printf("line %d: Symbol not recognized by %% \n", @1.first_line);
                                                //                     break;
                                                //                 }
                                                //                 while(p[0] != ',' && p[0] != ')')
                                                //                 {
                                                //                     varName[j++] = p[0];
                                                //                     p++;
                                                //                 }
                                                //                 ptr = getVar(varName);
                                                //                 if(ptr == 0)
                                                //                 {
                                                //                     printf("line %d: Identifier %s not declared.\n", @1.first_line, varName); 
                                                //                     errors++;
                                                //                     break;
                                                //                 }
                                                //                 printf("%lf", getVar(varName)->value);
                                                //                 break;
                                                //             default:
                                                //             printf("line %d: Symbol not recognized by %% \n", @1.first_line);
                                                //             errors++;
                                                //             break;
                                                //         }


                                                //         p++;
                                                //         continue;

                                                //     }
                                                //     if(buffer[i] == '\\')
                                                //     {
                                                //         i++;
                                                //         handleBackSlashForBuffer(buffer[i]);
                                                //         continue;
                                                //     }
                                                //     printf("%c", buffer[i]);
                                                // }
                                            }
#line 1681 "source.tab.c"
    break;

  case 48: /* instruction: T_SCANF  */
#line 314 "source.y"
                                            {
                                                genCode(SCANF, (yyvsp[0].str), 0, 0, (yylsp[0]).first_line);
                                                // if(errors > 0 || shouldExecute == 0) break;
                                                // char buffer[1024];
                                                // double val=0;
                                                // char varName[1024] = "";
                                                // strcpy(buffer, $1 + strlen("scanf(\""));  // eliminare scnaf(" de la inceput
                                                // char* p = strchr(buffer, '\"');
                                                // p+=2;                           //eliminare ",
                                                // int formatSize = strlen(buffer) - strlen(p) - 2;     //-2 pentru ca am facut p += 2
                                                // for(int i = 0; i < formatSize && buffer[i] != '\"' && errors == 0; i++)
                                                // {
                                                //     if(buffer[i] == '%')
                                                //     {
                                                //         while(p[0] == ' ') p++;
                                                //         i++;
                                                //         int j = 0;
                                                //         strcpy(varName, "");
                                                //         if(p[0] != '&')
                                                //         {
                                                //             errors++;
                                                //             printf("line %d: & not used, could not read value\n", @1.first_line);
                                                //         }
                                                //         p++;
                                                //         varRecord* ptr = NULL;
                                                //         switch(buffer[i])
                                                //         {
                                                //             case 'd':
                                                //                 while(p[0] != ',' && p[0] != ')')
                                                //                 {
                                                //                     varName[j++] = p[0];
                                                //                     p++;
                                                //                 }
                                                //                 scanf("%lf", &val);
                                                //                 ptr = getVar(varName);
                                                //                 if(ptr == 0)
                                                //                 {
                                                //                     printf("line %d: Identifier %s not declared.\n", @1.first_line, varName); 
                                                //                     errors++;
                                                //                     break;
                                                //                 }
                                                //                 ptr->value = (int)val;
                                                //             break;
                                                //             case 'f':
                                                //                 while(p[0] != ',' && p[0] != ')')
                                                //                 {
                                                //                     varName[j++] = p[0];
                                                //                     p++;
                                                //                 }
                                                //                 scanf("%lf", &val);
                                                //                 ptr = getVar(varName);
                                                //                 if(ptr == 0)
                                                //                 {
                                                //                     printf("line %d: Identifier %s not declared.\n", @1.first_line, varName); 
                                                //                     errors++;
                                                //                     break;
                                                //                 }
                                                //                 ptr->value = (float)val;
                                                //                 break;
                                                //             case 'l':
                                                //                 i++;
                                                //                 if(buffer[i] != 'f')
                                                //                 {
                                                //                     errors++;
                                                //                     printf("line %d: Symbol not recognized by %% \n", @1.first_line);
                                                //                     break;
                                                //                 }
                                                //                 while(p[0] != ',' && p[0] != ')')
                                                //                 {
                                                //                     varName[j++] = p[0];
                                                //                     p++;
                                                //                 }
                                                //                 scanf("%lf", &val);
                                                //                 ptr = getVar(varName);
                                                //                 if(ptr == 0)
                                                //                 {
                                                //                     printf("line %d: Identifier %s not declared.\n", @1.first_line, varName); 
                                                //                     errors++;
                                                //                     break;
                                                //                 }
                                                //                 ptr->value = (double)val;
                                                //                 break;
                                                //             default:
                                                //             printf("line %d: Symbol not recognized by %% \n", @1.first_line);
                                                //             errors++;
                                                //             break;
                                                //         }
                                                //         p++;
                                                //         continue;
                                                //     } else if (buffer[0] == ' ') {continue;}
                                                //     else
                                                //     {
                                                //         errors++;
                                                //         printf("line %d: Character not recognized by scnaf, please only use %%\n", @1.first_line);
                                                //     }
                                                // }
                                                
                                            }
#line 1784 "source.tab.c"
    break;

  case 52: /* type: T_INT_KW  */
#line 425 "source.y"
                                            { currentType = t_integer; }
#line 1790 "source.tab.c"
    break;

  case 53: /* type: T_DOUBLE_KW  */
#line 426 "source.y"
                                            { currentType = t_double; }
#line 1796 "source.tab.c"
    break;

  case 54: /* type: T_FLOAT_KW  */
#line 427 "source.y"
                                            { currentType = t_float; }
#line 1802 "source.tab.c"
    break;

  case 57: /* variable_declaration: T_IDENTIFIER  */
#line 436 "source.y"
                                            { 
                                                genCode(DECL, (yyvsp[0].str), currentType, 2, (yylsp[0]).first_line);
                                                // varRecord* ptr = addVar($1, currentType);  
                                                // if(ptr == NULL) 
                                                // {
                                                //     printf("line %d: Previous declaration of variable %s\n", @1.first_line, $1); 
                                                //     errors++;
                                                // }
                                            }
#line 1816 "source.tab.c"
    break;

  case 58: /* variable_declaration: T_IDENTIFIER '=' expression  */
#line 445 "source.y"
                                         {
                                            genCode(DECL, (yyvsp[-2].str), currentType, 2, (yylsp[-2]).first_line);
                                            genCode(STORE, (yyvsp[-2].str), 0, 0, (yylsp[-2]).first_line);
                                            // varRecord* ptr = addVar($1, currentType);
                                            // if(ptr == NULL) 
                                            // {
                                            //     printf("line %d: Previous declaration of variable %s\n", @1.first_line, $1); 
                                            //     errors++;
                                            //     break;
                                            // }
                                            // ptr->value = $3;
                                        }
#line 1833 "source.tab.c"
    break;

  case 59: /* variable_load: T_IDENTIFIER '=' expression  */
#line 460 "source.y"
                                        {
                                            genCode(STORE, (yyvsp[-2].str), 0, 0, (yylsp[-2]).first_line);
                                            // if (shouldExecute == 0) break; 
                                            // varRecord* ptr = getVar($1);
                                            // if(ptr == NULL)
                                            // {
                                            //     printf("Line %d: Identifier %s not declared.\n", @1.first_line, $1);
                                            //     errors++;
                                            //     break;
                                            // }
                                            // ptr->value = $3;
                                        }
#line 1850 "source.tab.c"
    break;

  case 60: /* expression: T_IDENTIFIER  */
#line 474 "source.y"
                                        {
                                            genCode(DATA, (yyvsp[0].str), 0, 0, (yylsp[0]).first_line);
                                            // if (shouldExecute == 0) break;  
                                            // varRecord* ptr = getVar($1);
                                            // if(ptr == NULL)
                                            // {
                                            //     printf("Line %d: Idendifier %s not declared.\n", @1.first_line, $1);
                                            //     errors++;
                                            //     break;
                                            // }
                                            // $$ = ptr->value;
                                        }
#line 1867 "source.tab.c"
    break;

  case 61: /* expression: T_DOUBLE_VAL  */
#line 486 "source.y"
                                            {genCode(DATA, "", (yyvsp[0].dval), 1, (yylsp[0]).first_line);}
#line 1873 "source.tab.c"
    break;

  case 62: /* expression: T_INTEGER_VAL  */
#line 487 "source.y"
                                            {genCode(DATA, "", (double)(yyvsp[0].intval), 1, (yylsp[0]).first_line);}
#line 1879 "source.tab.c"
    break;

  case 63: /* expression: expression '+' expression  */
#line 488 "source.y"
                                            {genCode(ADD, "", 0, -1, (yylsp[-2]).first_line);  (yyval.dval) = (yyvsp[-2].dval) + (yyvsp[0].dval);}
#line 1885 "source.tab.c"
    break;

  case 64: /* expression: expression '-' expression  */
#line 489 "source.y"
                                            {genCode(SUB, "", 0, -1, (yylsp[-2]).first_line); (yyval.dval) = (yyvsp[-2].dval) - (yyvsp[0].dval);}
#line 1891 "source.tab.c"
    break;

  case 65: /* expression: expression '*' expression  */
#line 490 "source.y"
                                            {genCode(MUL, "", 0, -1, (yylsp[-2]).first_line);  (yyval.dval) = (yyvsp[-2].dval) * (yyvsp[0].dval);}
#line 1897 "source.tab.c"
    break;

  case 66: /* expression: expression '/' expression  */
#line 491 "source.y"
                                            {genCode(DIV, "", 0, -1, (yylsp[-2]).first_line);}
#line 1903 "source.tab.c"
    break;

  case 67: /* expression: expression '<' expression  */
#line 492 "source.y"
                                            {genCode(LT, "", 0, -1, (yylsp[-2]).first_line); (yyval.dval) = (yyvsp[-2].dval) < (yyvsp[0].dval);}
#line 1909 "source.tab.c"
    break;

  case 68: /* expression: expression T_LE expression  */
#line 493 "source.y"
                                            {genCode(LE, "", 0, -1, (yylsp[-2]).first_line); (yyval.dval) = (yyvsp[-2].dval) <= (yyvsp[0].dval);}
#line 1915 "source.tab.c"
    break;

  case 69: /* expression: expression '>' expression  */
#line 494 "source.y"
                                            {genCode(GT, "", 0, -1, (yylsp[-2]).first_line); (yyval.dval) = (yyvsp[-2].dval) > (yyvsp[0].dval);}
#line 1921 "source.tab.c"
    break;

  case 70: /* expression: expression T_GE expression  */
#line 495 "source.y"
                                            {genCode(GE, "", 0, -1, (yylsp[-2]).first_line); (yyval.dval) = (yyvsp[-2].dval) >= (yyvsp[0].dval);}
#line 1927 "source.tab.c"
    break;

  case 71: /* expression: expression T_EQ expression  */
#line 496 "source.y"
                                            {genCode(EQ, "", 0, -1, (yylsp[-2]).first_line); (yyval.dval) = (yyvsp[-2].dval) == (yyvsp[0].dval);}
#line 1933 "source.tab.c"
    break;

  case 72: /* expression: expression T_NEQ expression  */
#line 497 "source.y"
                                            {genCode(NEQ, "", 0, -1, (yylsp[-2]).first_line); (yyval.dval) = (yyvsp[-2].dval) != (yyvsp[0].dval);}
#line 1939 "source.tab.c"
    break;

  case 73: /* expression: '(' expression ')'  */
#line 498 "source.y"
                                            {if (shouldExecute == 0) break; (yyval.dval) = (yyvsp[-1].dval);}
#line 1945 "source.tab.c"
    break;

  case 74: /* expression: function_call  */
#line 499 "source.y"
                                            {
                                                
                                            }
#line 1953 "source.tab.c"
    break;


#line 1957 "source.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  yyerror_range[1] = yylloc;
  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, &yylloc);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  ++yylsp;
  YYLLOC_DEFAULT (*yylsp, yyerror_range, 2);

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 504 "source.y"


/**********************************
            MAIN FUNCTION
**********************************/

int main(int argc, char** argv)
{   
    if (argc == 2) {
        yyin = fopen(argv[1], "r");
        if (!yyin) {
            perror("Error opening file");
            return 1;
        }
    }
    yyparse();
    printf("Parsing ended.\n");
    if(DEBUGGER)
    {
        printAllInstructions();
    }
    printf("-------------------STARTING CODE SEQUENCE--------------------\n\n");
    if(errors > 0)
    {
        printf("Code can not execute, detected %d errors.\n", errors);
    }
    else
        fetchExecuteCycle();
    printf("\n\n------------------CODE ENDED-------------------\n");
    if(DEBUGGER)
    {
        //printf("IfCount= %d\n", ifCount);
        printAllVars();
    }
    return 0;
}

int yyerror(const char *msg)
{
    printf("Line %d: Error: %s\n",lineNo, msg);
    errors++;
    return 1;
}
