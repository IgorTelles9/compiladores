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
#line 1 "mini_js.y"

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int ln = 1, col = 0; 

struct Attributes {
    vector<string> code; 

    int ln = 0, col = 0;

    void clear() {
        code.clear();
        ln = 0;
        col = 0;
    }
};

#define YYSTYPE Attributes

enum Decl { DeclVar=1, DeclConst, DeclLet };

struct Variable {
  int ln, col;
  Decl type;
};

map<string,Variable> symbols; 

extern "C" int yylex();
int yyparse();
void yyerror(const char *);

vector<string> concat(vector<string> a, vector<string> b);
vector<string> operator+(vector<string> a, vector<string> b);
vector<string> operator+(vector<string> a, string b);
vector<string> operator+(string a, vector<string> b);
vector<string> resolveAddr(vector<string> code);
string getLabel(string prefix);
void print(vector<string> code);
vector<string> declareVariable(Decl type, Attributes attr);
void verifyAttrib(string name, bool a);
vector<string> vec(string s);


#line 121 "mini_js.tab.c"

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
    AND = 258,                     /* AND  */
    OR = 259,                      /* OR  */
    EQUAL = 260,                   /* EQUAL  */
    GT_EQ = 261,                   /* GT_EQ  */
    LT_EQ = 262,                   /* LT_EQ  */
    DIFF = 263,                    /* DIFF  */
    PLUS_EQ = 264,                 /* PLUS_EQ  */
    PLUS_PLUS = 265,               /* PLUS_PLUS  */
    OBJ = 266,                     /* OBJ  */
    ARRAY = 267,                   /* ARRAY  */
    IF = 268,                      /* IF  */
    ELSE = 269,                    /* ELSE  */
    FOR = 270,                     /* FOR  */
    WHILE = 271,                   /* WHILE  */
    LET = 272,                     /* LET  */
    CONST = 273,                   /* CONST  */
    VAR = 274,                     /* VAR  */
    PRINT = 275,                   /* PRINT  */
    STRING = 276,                  /* STRING  */
    INT = 277,                     /* INT  */
    FLOAT = 278,                   /* FLOAT  */
    ID = 279                       /* ID  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);



/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_AND = 3,                        /* AND  */
  YYSYMBOL_OR = 4,                         /* OR  */
  YYSYMBOL_EQUAL = 5,                      /* EQUAL  */
  YYSYMBOL_GT_EQ = 6,                      /* GT_EQ  */
  YYSYMBOL_LT_EQ = 7,                      /* LT_EQ  */
  YYSYMBOL_DIFF = 8,                       /* DIFF  */
  YYSYMBOL_PLUS_EQ = 9,                    /* PLUS_EQ  */
  YYSYMBOL_PLUS_PLUS = 10,                 /* PLUS_PLUS  */
  YYSYMBOL_OBJ = 11,                       /* OBJ  */
  YYSYMBOL_ARRAY = 12,                     /* ARRAY  */
  YYSYMBOL_IF = 13,                        /* IF  */
  YYSYMBOL_ELSE = 14,                      /* ELSE  */
  YYSYMBOL_FOR = 15,                       /* FOR  */
  YYSYMBOL_WHILE = 16,                     /* WHILE  */
  YYSYMBOL_LET = 17,                       /* LET  */
  YYSYMBOL_CONST = 18,                     /* CONST  */
  YYSYMBOL_VAR = 19,                       /* VAR  */
  YYSYMBOL_PRINT = 20,                     /* PRINT  */
  YYSYMBOL_STRING = 21,                    /* STRING  */
  YYSYMBOL_INT = 22,                       /* INT  */
  YYSYMBOL_FLOAT = 23,                     /* FLOAT  */
  YYSYMBOL_ID = 24,                        /* ID  */
  YYSYMBOL_25_ = 25,                       /* '='  */
  YYSYMBOL_26_ = 26,                       /* '<'  */
  YYSYMBOL_27_ = 27,                       /* '>'  */
  YYSYMBOL_28_ = 28,                       /* '+'  */
  YYSYMBOL_29_ = 29,                       /* '-'  */
  YYSYMBOL_30_ = 30,                       /* '*'  */
  YYSYMBOL_31_ = 31,                       /* '/'  */
  YYSYMBOL_32_ = 32,                       /* '%'  */
  YYSYMBOL_33_ = 33,                       /* '['  */
  YYSYMBOL_34_ = 34,                       /* '.'  */
  YYSYMBOL_35_ = 35,                       /* ';'  */
  YYSYMBOL_36_ = 36,                       /* '{'  */
  YYSYMBOL_37_ = 37,                       /* '}'  */
  YYSYMBOL_38_ = 38,                       /* '('  */
  YYSYMBOL_39_ = 39,                       /* ')'  */
  YYSYMBOL_40_ = 40,                       /* ','  */
  YYSYMBOL_41_ = 41,                       /* ']'  */
  YYSYMBOL_YYACCEPT = 42,                  /* $accept  */
  YYSYMBOL_S = 43,                         /* S  */
  YYSYMBOL_CMDs = 44,                      /* CMDs  */
  YYSYMBOL_CMD = 45,                       /* CMD  */
  YYSYMBOL_CMD_IF = 46,                    /* CMD_IF  */
  YYSYMBOL_CMD_WHILE = 47,                 /* CMD_WHILE  */
  YYSYMBOL_CMD_FOR = 48,                   /* CMD_FOR  */
  YYSYMBOL_PRIM_E = 49,                    /* PRIM_E  */
  YYSYMBOL_DECL_LET = 50,                  /* DECL_LET  */
  YYSYMBOL_LET_IDs = 51,                   /* LET_IDs  */
  YYSYMBOL_LET_ID = 52,                    /* LET_ID  */
  YYSYMBOL_DECL_CONST = 53,                /* DECL_CONST  */
  YYSYMBOL_CONST_IDs = 54,                 /* CONST_IDs  */
  YYSYMBOL_CONST_ID = 55,                  /* CONST_ID  */
  YYSYMBOL_DECL_VAR = 56,                  /* DECL_VAR  */
  YYSYMBOL_VAR_IDs = 57,                   /* VAR_IDs  */
  YYSYMBOL_VAR_ID = 58,                    /* VAR_ID  */
  YYSYMBOL_E = 59,                         /* E  */
  YYSYMBOL_LVALUE = 60,                    /* LVALUE  */
  YYSYMBOL_LVALUEPROP = 61                 /* LVALUEPROP  */
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
typedef yytype_int8 yy_state_t;

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
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   312

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  20
/* YYNRULES -- Number of rules.  */
#define YYNRULES  62
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  116

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   279


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
       2,     2,     2,     2,     2,     2,     2,    32,     2,     2,
      38,    39,    30,    28,    40,    29,    34,    31,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    35,
      26,    25,    27,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    33,     2,    41,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    36,     2,    37,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    64,    64,    67,    68,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    82,    96,   110,   127,   143,   144,
     148,   151,   152,   155,   156,   159,   162,   163,   166,   167,
     170,   173,   174,   177,   178,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     207,   210,   211
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
  "\"end of file\"", "error", "\"invalid token\"", "AND", "OR", "EQUAL",
  "GT_EQ", "LT_EQ", "DIFF", "PLUS_EQ", "PLUS_PLUS", "OBJ", "ARRAY", "IF",
  "ELSE", "FOR", "WHILE", "LET", "CONST", "VAR", "PRINT", "STRING", "INT",
  "FLOAT", "ID", "'='", "'<'", "'>'", "'+'", "'-'", "'*'", "'/'", "'%'",
  "'['", "'.'", "';'", "'{'", "'}'", "'('", "')'", "','", "']'", "$accept",
  "S", "CMDs", "CMD", "CMD_IF", "CMD_WHILE", "CMD_FOR", "PRIM_E",
  "DECL_LET", "LET_IDs", "LET_ID", "DECL_CONST", "CONST_IDs", "CONST_ID",
  "DECL_VAR", "VAR_IDs", "VAR_ID", "E", "LVALUE", "LVALUEPROP", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-94)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -94,     1,   235,   -94,   -94,   -94,   -33,   -29,   -28,   -13,
     -12,   -11,   -94,   -94,   -94,   -94,   274,   -94,   -94,   274,
     -94,   -94,   -94,   -94,   -15,   -10,    -9,   138,    -2,    -7,
     274,   255,   274,    -6,   -94,   -18,    -1,   -94,     4,     2,
     -94,     5,    58,   207,    78,   -94,   -94,   -94,   274,   274,
     274,   274,   274,   274,   274,   274,   274,   274,   274,   274,
       6,   -94,   274,   -94,   274,   274,   274,    92,    -4,   -94,
     169,   108,   274,   -13,   274,   -12,   274,   -11,   -94,   -94,
     169,   169,   169,   169,   183,   183,    58,    58,   199,   199,
     199,    46,   -94,   169,   169,   169,   169,   235,   274,   235,
     169,   -94,   169,   -94,   169,   -94,   -94,    14,   152,   -94,
     235,   274,   -94,   122,   235,   -94
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       4,     0,     2,     1,    53,    52,     0,     0,     0,     0,
       0,     0,    56,    55,    54,    60,     0,    13,     4,     0,
       3,     8,    10,     9,     0,     0,     0,     0,    57,    58,
       0,     0,     0,    23,    20,    22,    28,    25,    27,    33,
      30,    32,    51,     0,     0,     5,     6,     7,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    12,     0,    36,     0,     0,     0,     0,     0,    18,
      19,     0,     0,     0,     0,     0,     0,     0,    11,    59,
      40,    42,    43,    41,    44,    45,    46,    49,    47,    48,
      50,     0,    61,    37,    35,    39,    38,     0,     0,     0,
      24,    21,    29,    26,    34,    31,    62,    14,     0,    16,
       0,     0,    15,     0,     0,    17
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -94,   -94,    11,   -93,   -94,   -94,   -94,   -94,    16,   -14,
     -94,   -94,   -20,   -94,   -94,    -8,   -94,   -16,   -94,   -94
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     1,     2,    20,    21,    22,    23,    68,    24,    34,
      35,    25,    37,    38,    26,    40,    41,    27,    28,    29
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      42,     3,    65,    44,   107,    30,   109,    62,    63,    31,
      32,    33,    36,    39,    67,    70,    71,   112,    66,    72,
      45,   115,    73,    64,    74,    46,    47,    76,   110,    43,
      92,    98,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    75,    77,    93,    69,    94,    95,
      96,    48,    49,    50,    51,   103,   100,     0,   102,   101,
     104,     0,     0,    48,    49,    50,    51,     0,     0,   105,
       0,     0,    52,    53,    54,    55,    56,    57,    58,    59,
      60,     0,   108,    48,    49,    50,    51,   106,    56,    57,
      58,    59,    60,     0,     0,   113,     0,    48,    49,    50,
      51,     0,     0,     0,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    48,    49,    50,    51,    79,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    48,    49,    50,
      51,    97,     0,     0,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    48,    49,    50,    51,    99,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    48,    49,    50,
      51,   114,     0,     0,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,   111,    48,    49,
      50,    51,     0,     0,     0,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    48,    49,    50,    51,     0,    -1,
      -1,    54,    55,    56,    57,    58,    59,    60,     4,     5,
       6,     0,     7,     8,     9,    10,    11,     0,    12,    13,
      14,    15,    59,    60,     0,     0,    16,     0,     0,     0,
       0,     0,    17,    18,    78,    19,     4,     5,     6,     0,
       7,     8,     9,    10,    11,     0,    12,    13,    14,    15,
       0,     0,     0,     0,    16,     0,     4,     5,     0,     0,
      17,    18,     9,    19,     0,     0,    12,    13,    14,    15,
       0,     0,     0,     0,    16,     4,     5,     0,     0,     0,
       0,     0,     0,    19,     0,    12,    13,    14,    15,     0,
       0,     0,     0,    16,     0,     0,     0,     0,     0,     0,
       0,     0,    19
};

static const yytype_int8 yycheck[] =
{
      16,     0,     9,    19,    97,    38,    99,     9,    10,    38,
      38,    24,    24,    24,    30,    31,    32,   110,    25,    25,
      35,   114,    40,    25,    25,    35,    35,    25,    14,    18,
      24,    35,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    40,    40,    62,    31,    64,    65,
      66,     5,     6,     7,     8,    75,    72,    -1,    74,    73,
      76,    -1,    -1,     5,     6,     7,     8,    -1,    -1,    77,
      -1,    -1,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    -1,    98,     5,     6,     7,     8,    41,    30,    31,
      32,    33,    34,    -1,    -1,   111,    -1,     5,     6,     7,
       8,    -1,    -1,    -1,    26,    27,    28,    29,    30,    31,
      32,    33,    34,     5,     6,     7,     8,    39,    26,    27,
      28,    29,    30,    31,    32,    33,    34,     5,     6,     7,
       8,    39,    -1,    -1,    26,    27,    28,    29,    30,    31,
      32,    33,    34,     5,     6,     7,     8,    39,    26,    27,
      28,    29,    30,    31,    32,    33,    34,     5,     6,     7,
       8,    39,    -1,    -1,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,     5,     6,     7,     8,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,     5,     6,
       7,     8,    -1,    -1,    -1,    26,    27,    28,    29,    30,
      31,    32,    33,    34,     5,     6,     7,     8,    -1,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    11,    12,
      13,    -1,    15,    16,    17,    18,    19,    -1,    21,    22,
      23,    24,    33,    34,    -1,    -1,    29,    -1,    -1,    -1,
      -1,    -1,    35,    36,    37,    38,    11,    12,    13,    -1,
      15,    16,    17,    18,    19,    -1,    21,    22,    23,    24,
      -1,    -1,    -1,    -1,    29,    -1,    11,    12,    -1,    -1,
      35,    36,    17,    38,    -1,    -1,    21,    22,    23,    24,
      -1,    -1,    -1,    -1,    29,    11,    12,    -1,    -1,    -1,
      -1,    -1,    -1,    38,    -1,    21,    22,    23,    24,    -1,
      -1,    -1,    -1,    29,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    38
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    43,    44,     0,    11,    12,    13,    15,    16,    17,
      18,    19,    21,    22,    23,    24,    29,    35,    36,    38,
      45,    46,    47,    48,    50,    53,    56,    59,    60,    61,
      38,    38,    38,    24,    51,    52,    24,    54,    55,    24,
      57,    58,    59,    44,    59,    35,    35,    35,     5,     6,
       7,     8,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,     9,    10,    25,     9,    25,    59,    49,    50,
      59,    59,    25,    40,    25,    40,    25,    40,    37,    39,
      59,    59,    59,    59,    59,    59,    59,    59,    59,    59,
      59,    59,    24,    59,    59,    59,    59,    39,    35,    39,
      59,    51,    59,    54,    59,    57,    41,    45,    59,    45,
      14,    35,    45,    59,    39,    45
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    42,    43,    44,    44,    45,    45,    45,    45,    45,
      45,    45,    45,    45,    46,    46,    47,    48,    49,    49,
      50,    51,    51,    52,    52,    53,    54,    54,    55,    55,
      56,    57,    57,    58,    58,    59,    59,    59,    59,    59,
      59,    59,    59,    59,    59,    59,    59,    59,    59,    59,
      59,    59,    59,    59,    59,    59,    59,    59,    59,    59,
      60,    61,    61
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     0,     2,     2,     2,     1,     1,
       1,     3,     2,     1,     5,     7,     5,     9,     1,     1,
       2,     3,     1,     1,     3,     2,     3,     1,     1,     3,
       2,     3,     1,     1,     3,     3,     2,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     2,     1,     1,     1,     1,     1,     1,     1,     3,
       1,     3,     4
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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
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
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
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
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
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
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
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

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

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

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
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
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* S: CMDs  */
#line 64 "mini_js.y"
         { print(resolveAddr(yyvsp[0].code  + ".")); }
#line 1336 "mini_js.tab.c"
    break;

  case 3: /* CMDs: CMDs CMD  */
#line 67 "mini_js.y"
                { yyval.code = yyvsp[-1].code + yyvsp[0].code; }
#line 1342 "mini_js.tab.c"
    break;

  case 4: /* CMDs: %empty  */
#line 68 "mini_js.y"
       {yyval.clear();}
#line 1348 "mini_js.tab.c"
    break;

  case 11: /* CMD: '{' CMDs '}'  */
#line 77 "mini_js.y"
                   { yyval.code = yyvsp[-1].code; }
#line 1354 "mini_js.tab.c"
    break;

  case 12: /* CMD: E ';'  */
#line 78 "mini_js.y"
            { yyval.code = yyvsp[-1].code + "^";}
#line 1360 "mini_js.tab.c"
    break;

  case 13: /* CMD: ';'  */
#line 79 "mini_js.y"
          { yyval.clear(); }
#line 1366 "mini_js.tab.c"
    break;

  case 14: /* CMD_IF: IF '(' E ')' CMD  */
#line 83 "mini_js.y"
    {
        string lbl_true = getLabel( "lbl_true" );
        string lbl_end_if = getLabel( "lbl_end_if" );
        string def_lbl_true = ":" + lbl_true;
        string def_lbl_end_if = ":" + lbl_end_if;
        yyval.code = yyvsp[-2].code + 
                lbl_true + "?" + 
                lbl_end_if + "#" + 
                def_lbl_true + yyvsp[0].code 
                + def_lbl_end_if; 

    }
#line 1383 "mini_js.tab.c"
    break;

  case 15: /* CMD_IF: IF '(' E ')' CMD ELSE CMD  */
#line 97 "mini_js.y"
    { 
        string lbl_true = getLabel( "lbl_true" );
        string lbl_end_if = getLabel( "lbl_end_if" );
        string def_lbl_true = ":" + lbl_true;
        string def_lbl_end_if = ":" + lbl_end_if;
        yyval.code = yyvsp[-4].code +                     // Codigo da expressão
                lbl_true + "?" +                // Código do IF
                yyvsp[0].code + lbl_end_if + "#" +    // Código do False
                def_lbl_true + yyvsp[-2].code +        // Código do True
                def_lbl_end_if                  // Fim do IF
                ;
    }
#line 1400 "mini_js.tab.c"
    break;

  case 16: /* CMD_WHILE: WHILE '(' E ')' CMD  */
#line 111 "mini_js.y"
    {
        string lbl_cond_while = getLabel("lbl_cond_while");
        string def_lbl_cond_while = ":" + lbl_cond_while;
        string lbl_cmd_while = getLabel("lbl_cmd_while");
        string def_lbl_cmd_while = ":" + lbl_cmd_while;
        string lbl_end_while = getLabel("lbl_end_while");
        string def_lbl_end_while = ":" + lbl_end_while;
        
        yyval.code = def_lbl_cond_while 
                + yyvsp[-2].code + lbl_cmd_while + "?" 
                + lbl_end_while + "#" 
                + def_lbl_cmd_while + yyvsp[0].code 
                + lbl_cond_while + "#"
                + def_lbl_end_while;
    }
#line 1420 "mini_js.tab.c"
    break;

  case 17: /* CMD_FOR: FOR '(' PRIM_E ';' E ';' E ')' CMD  */
#line 128 "mini_js.y"
        { string lbl_fim_for = getLabel( "fim_for" );
          string lbl_condicao_for = getLabel( "condicao_for" );
          string lbl_comando_for = getLabel( "comando_for" );
          string definicao_lbl_fim_for = ":" + lbl_fim_for;
          string definicao_lbl_condicao_for = ":" + lbl_condicao_for;
          string definicao_lbl_comando_for = ":" + lbl_comando_for;
          
          yyval.code = yyvsp[-6].code + definicao_lbl_condicao_for +
                 yyvsp[-4].code + lbl_comando_for + "?" + lbl_fim_for + "#" +
                 definicao_lbl_comando_for + yyvsp[0].code + 
                 yyvsp[-2].code + "^" + lbl_condicao_for + "#" +
                 definicao_lbl_fim_for;
        }
#line 1438 "mini_js.tab.c"
    break;

  case 19: /* PRIM_E: E  */
#line 145 "mini_js.y"
         { yyval.code = yyvsp[0].code + "^"; }
#line 1444 "mini_js.tab.c"
    break;

  case 20: /* DECL_LET: LET LET_IDs  */
#line 148 "mini_js.y"
                       { yyval.code = yyvsp[0].code; }
#line 1450 "mini_js.tab.c"
    break;

  case 21: /* LET_IDs: LET_ID ',' LET_IDs  */
#line 151 "mini_js.y"
                             { yyval.code = yyvsp[-2].code + yyvsp[0].code; }
#line 1456 "mini_js.tab.c"
    break;

  case 23: /* LET_ID: ID  */
#line 155 "mini_js.y"
            { yyval.code = declareVariable(DeclLet, yyvsp[0]); }
#line 1462 "mini_js.tab.c"
    break;

  case 24: /* LET_ID: ID '=' E  */
#line 156 "mini_js.y"
                  {  yyval.code = declareVariable(DeclLet, yyvsp[-2]) + yyvsp[-2].code + yyvsp[0].code + "=" + "^"; }
#line 1468 "mini_js.tab.c"
    break;

  case 25: /* DECL_CONST: CONST CONST_IDs  */
#line 159 "mini_js.y"
                             { yyval.code = yyvsp[0].code; }
#line 1474 "mini_js.tab.c"
    break;

  case 26: /* CONST_IDs: CONST_ID ',' CONST_IDs  */
#line 162 "mini_js.y"
                                   { yyval.code = yyvsp[-2].code + yyvsp[0].code; }
#line 1480 "mini_js.tab.c"
    break;

  case 28: /* CONST_ID: ID  */
#line 166 "mini_js.y"
              {  yyval.code = declareVariable(DeclConst, yyvsp[0]); }
#line 1486 "mini_js.tab.c"
    break;

  case 29: /* CONST_ID: ID '=' E  */
#line 167 "mini_js.y"
                  { yyval.code = declareVariable(DeclConst, yyvsp[-2]) + yyvsp[-2].code + yyvsp[0].code + "=" + "^"; }
#line 1492 "mini_js.tab.c"
    break;

  case 30: /* DECL_VAR: VAR VAR_IDs  */
#line 170 "mini_js.y"
                       { yyval.code = yyvsp[0].code; }
#line 1498 "mini_js.tab.c"
    break;

  case 31: /* VAR_IDs: VAR_ID ',' VAR_IDs  */
#line 173 "mini_js.y"
                             { yyval.code = yyvsp[-2].code + yyvsp[0].code; }
#line 1504 "mini_js.tab.c"
    break;

  case 33: /* VAR_ID: ID  */
#line 177 "mini_js.y"
            { yyval.code = declareVariable(DeclVar, yyvsp[-1]); }
#line 1510 "mini_js.tab.c"
    break;

  case 34: /* VAR_ID: ID '=' E  */
#line 178 "mini_js.y"
                  { yyval.code = declareVariable(DeclVar, yyvsp[-2]) + yyvsp[-2].code + yyvsp[0].code + "=" + "^"; }
#line 1516 "mini_js.tab.c"
    break;

  case 35: /* E: LVALUE '=' E  */
#line 181 "mini_js.y"
                 { verifyAttrib(yyvsp[-2].code[0],true); yyval.code = yyvsp[-2].code + yyvsp[0].code + "="; }
#line 1522 "mini_js.tab.c"
    break;

  case 36: /* E: LVALUE PLUS_PLUS  */
#line 182 "mini_js.y"
                       { verifyAttrib(yyvsp[-1].code[0], true); yyval.code = yyvsp[-1].code + "@" + yyvsp[-1].code + yyvsp[-1].code + "@" + "1" + "+" + "=" + "^"; }
#line 1528 "mini_js.tab.c"
    break;

  case 37: /* E: LVALUE PLUS_EQ E  */
#line 183 "mini_js.y"
                       { verifyAttrib(yyvsp[-2].code[0], true); yyval.code = yyvsp[-2].code + yyvsp[-2].code + "@" + yyvsp[0].code + "+" + "="; }
#line 1534 "mini_js.tab.c"
    break;

  case 38: /* E: LVALUEPROP '=' E  */
#line 184 "mini_js.y"
                        { verifyAttrib(yyvsp[-2].code[0], true); yyval.code = yyvsp[-2].code + yyvsp[0].code + "[=]"; }
#line 1540 "mini_js.tab.c"
    break;

  case 39: /* E: LVALUEPROP PLUS_EQ E  */
#line 185 "mini_js.y"
                           { verifyAttrib(yyvsp[-2].code[0], true); yyval.code = yyvsp[-2].code + yyvsp[-2].code + "[@]" + yyvsp[0].code + "+" + "[=]"; }
#line 1546 "mini_js.tab.c"
    break;

  case 40: /* E: E EQUAL E  */
#line 186 "mini_js.y"
                { yyval.code = yyvsp[-2].code + yyvsp[0].code + "=="; }
#line 1552 "mini_js.tab.c"
    break;

  case 41: /* E: E DIFF E  */
#line 187 "mini_js.y"
               { yyval.code = yyvsp[-2].code + yyvsp[0].code + "!="; }
#line 1558 "mini_js.tab.c"
    break;

  case 42: /* E: E GT_EQ E  */
#line 188 "mini_js.y"
                { yyval.code = yyvsp[-2].code + yyvsp[0].code + ">="; }
#line 1564 "mini_js.tab.c"
    break;

  case 43: /* E: E LT_EQ E  */
#line 189 "mini_js.y"
                { yyval.code = yyvsp[-2].code + yyvsp[0].code + "<="; }
#line 1570 "mini_js.tab.c"
    break;

  case 44: /* E: E '<' E  */
#line 190 "mini_js.y"
              { yyval.code = yyvsp[-2].code + yyvsp[0].code + "<"; }
#line 1576 "mini_js.tab.c"
    break;

  case 45: /* E: E '>' E  */
#line 191 "mini_js.y"
              { yyval.code = yyvsp[-2].code + yyvsp[0].code + ">"; }
#line 1582 "mini_js.tab.c"
    break;

  case 46: /* E: E '+' E  */
#line 192 "mini_js.y"
              { yyval.code = yyvsp[-2].code + yyvsp[0].code + "+"; }
#line 1588 "mini_js.tab.c"
    break;

  case 47: /* E: E '*' E  */
#line 193 "mini_js.y"
              { yyval.code = yyvsp[-2].code + yyvsp[0].code + "*"; }
#line 1594 "mini_js.tab.c"
    break;

  case 48: /* E: E '/' E  */
#line 194 "mini_js.y"
              { yyval.code = yyvsp[-2].code + yyvsp[0].code + "/"; }
#line 1600 "mini_js.tab.c"
    break;

  case 49: /* E: E '-' E  */
#line 195 "mini_js.y"
              { yyval.code = yyvsp[-2].code + yyvsp[0].code + "-"; }
#line 1606 "mini_js.tab.c"
    break;

  case 50: /* E: E '%' E  */
#line 196 "mini_js.y"
              { yyval.code = yyvsp[-2].code + yyvsp[0].code + "%"; }
#line 1612 "mini_js.tab.c"
    break;

  case 51: /* E: '-' E  */
#line 197 "mini_js.y"
              {yyval.code = "0" + yyvsp[0].code + yyvsp[-1].code; }
#line 1618 "mini_js.tab.c"
    break;

  case 52: /* E: ARRAY  */
#line 198 "mini_js.y"
              { yyval.code = vec("[]"); }
#line 1624 "mini_js.tab.c"
    break;

  case 53: /* E: OBJ  */
#line 199 "mini_js.y"
              { yyval.code = vec("{}"); }
#line 1630 "mini_js.tab.c"
    break;

  case 57: /* E: LVALUE  */
#line 203 "mini_js.y"
                    { verifyAttrib(yyvsp[0].code[0], false); yyval.code = yyvsp[0].code + "@"; }
#line 1636 "mini_js.tab.c"
    break;

  case 58: /* E: LVALUEPROP  */
#line 204 "mini_js.y"
                    { verifyAttrib(yyvsp[0].code[0], false); yyval.code = yyvsp[0].code + "[@]"; }
#line 1642 "mini_js.tab.c"
    break;

  case 59: /* E: '(' E ')'  */
#line 205 "mini_js.y"
                    { yyval.code = yyvsp[-1].code; }
#line 1648 "mini_js.tab.c"
    break;

  case 61: /* LVALUEPROP: E '.' ID  */
#line 210 "mini_js.y"
                         { yyval.code = yyvsp[-2].code + yyvsp[0].code; }
#line 1654 "mini_js.tab.c"
    break;

  case 62: /* LVALUEPROP: E '[' E ']'  */
#line 211 "mini_js.y"
                            { yyval.code = yyvsp[-3].code + yyvsp[-1].code; }
#line 1660 "mini_js.tab.c"
    break;


#line 1664 "mini_js.tab.c"

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
                      yytoken, &yylval);
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


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 213 "mini_js.y"

#include "lex.yy.c"

vector<string> concat(vector<string> a, vector<string> b) {
    a.insert(a.end(), b.begin(), b.end());
    return a;
}

vector<string> operator+(vector<string> a, vector<string> b) {
    return concat(a, b);
}

vector<string> operator+(vector<string> a, string b) {
    a.push_back(b) ;
    return a;
}

vector<string> operator+(string a, vector<string> b) {
    return vector<string>{a} + b;
}

vector<string> resolveAddr(vector<string> code) {
    map<string,int> label;
    vector<string> saida;
    for(int i = 0; i < code.size(); i++){
        if(code[i][0] == ':')
            label[code[i].substr(1)] = saida.size();
        else
            saida.push_back(code[i]);
    }

    for(int i = 0; i < saida.size(); i++){
        if(label.count( saida[i] ) > 0 )
            saida[i] = to_string(label[saida[i]]);
    }

    return saida;
}

string getLabel(string prefix) {
  static int n = 0;
  return prefix + "_" + to_string(++n) + ":";
}

void print(vector<string> code) {
    for(string s : code)
        cout << s << " ";
    cout << endl;
}

vector<string> declareVariable(Decl type, Attributes attr){ 
    string name = attr.code[0];
    int ln = attr.ln, col = attr.col;
    if(symbols.count(name) == 0) {
        symbols[name] = Variable{ln, col, type};
        return vector<string>{name, "&"};
    }
    if(type == DeclVar && symbols[name].type == DeclVar ) {
        symbols[name] = Variable{ln, col, type};
        return vector<string>{};
    } 
    cerr << "Erro: a variável '" << name << "' ja foi declarada na linha " << symbols[name].ln << "." << endl;
    exit(1);     
}

void verifyAttrib(string name, bool a) {
    if(symbols.count(name) > 0) {
        if(a && symbols[name].type == DeclConst) {
            cerr << "Erro: a variável '" << name << "' não pode ser modificada." << endl;
            exit(1);     
        }
    } else {
        cerr << "Erro: a variável '" << name << "' não foi declarada." << endl;
        exit(1);     
    }
}

vector<string> vec(string s) {
    return vector<string>{s};
}

void yyerror( const char* st ) {
    puts( st ); 
    printf( "Proximo a: %s\n", yytext );
    exit( 1 );
}

int main( int argc, char* argv[] ) {
    yyparse();
    
    return 0;
}
