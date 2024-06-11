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
#include <tuple>
#include <unordered_set>
#include <sstream>

using namespace std;

bool dev = false; // not logging

int ln = 1, col = 0; 

bool isFunctionScope = false;

struct Attributes {
    vector<string> code; 

    int args_counter = 0; 

    vector<string> default_value; 

    int ln = 0, col = 0;

    void clear() {
        code.clear();
        default_value.clear();
        ln = 0;
        col = 0;
        args_counter = 0;
    }
};


#define YYSTYPE Attributes

enum Decl { DeclVar=1, DeclConst, DeclLet };

struct Variable {
  int ln, col;
  Decl type;
};

vector<map<string,Variable>> symbols = { map< string, Variable >{} }; 
vector<string> functions;

extern "C" int yylex();
int yyparse();
void yyerror(const char *);

// log functions ---

void logMessage(std::ostream& os) {}

template <typename T, typename... Args>
void logMessage(ostream& os, T first, Args... args) {
    os << first;
    logMessage(os, args...);
}

template <typename... Args>
void log(Args... args) {
    if (dev) {
        logMessage(cout, args...);
        cout << endl;
    }
}

// -------------------

vector<string> concat(vector<string> a, vector<string> b);
vector<string> operator+(vector<string> a, vector<string> b);
vector<string> operator+(vector<string> a, string b);
vector<string> operator+(string a, vector<string> b);
vector<string> resolveAddr(vector<string> code);
string getLabel(string prefix);
void print(vector<string> code);
vector<string> declareVariable(Decl type, Attributes attr);
vector<string> declareVariable(Decl type, string name, int ln, int col);
void verifyAttrib(string name, bool a);
vector<string> vec(string s);
vector<string> declareFunction(Attributes attr);
tuple<string,string,string,string> generateIfLabels();
vector<string> generateDefaultParamsCode(Attributes attr);
string trim(string str, string charsToTrim);
vector<string> getFormattedMdpCode(string mdpCode);


#line 162 "mini_js.tab.c"

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
    EMPTY_BLOCK = 266,             /* EMPTY_BLOCK  */
    IF = 267,                      /* IF  */
    ELSE = 268,                    /* ELSE  */
    FOR = 269,                     /* FOR  */
    WHILE = 270,                   /* WHILE  */
    LET = 271,                     /* LET  */
    CONST = 272,                   /* CONST  */
    VAR = 273,                     /* VAR  */
    ASM = 274,                     /* ASM  */
    ARROW = 275,                   /* ARROW  */
    ARROW_OBJ = 276,               /* ARROW_OBJ  */
    STRING = 277,                  /* STRING  */
    INT = 278,                     /* INT  */
    FLOAT = 279,                   /* FLOAT  */
    ID = 280,                      /* ID  */
    FUNCTION = 281,                /* FUNCTION  */
    RETURN = 282,                  /* RETURN  */
    BOOL = 283,                    /* BOOL  */
    PARENTESIS_ARROW = 284         /* PARENTESIS_ARROW  */
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
  YYSYMBOL_EMPTY_BLOCK = 11,               /* EMPTY_BLOCK  */
  YYSYMBOL_IF = 12,                        /* IF  */
  YYSYMBOL_ELSE = 13,                      /* ELSE  */
  YYSYMBOL_FOR = 14,                       /* FOR  */
  YYSYMBOL_WHILE = 15,                     /* WHILE  */
  YYSYMBOL_LET = 16,                       /* LET  */
  YYSYMBOL_CONST = 17,                     /* CONST  */
  YYSYMBOL_VAR = 18,                       /* VAR  */
  YYSYMBOL_ASM = 19,                       /* ASM  */
  YYSYMBOL_ARROW = 20,                     /* ARROW  */
  YYSYMBOL_ARROW_OBJ = 21,                 /* ARROW_OBJ  */
  YYSYMBOL_STRING = 22,                    /* STRING  */
  YYSYMBOL_INT = 23,                       /* INT  */
  YYSYMBOL_FLOAT = 24,                     /* FLOAT  */
  YYSYMBOL_ID = 25,                        /* ID  */
  YYSYMBOL_FUNCTION = 26,                  /* FUNCTION  */
  YYSYMBOL_RETURN = 27,                    /* RETURN  */
  YYSYMBOL_BOOL = 28,                      /* BOOL  */
  YYSYMBOL_PARENTESIS_ARROW = 29,          /* PARENTESIS_ARROW  */
  YYSYMBOL_30_ = 30,                       /* '='  */
  YYSYMBOL_31_ = 31,                       /* '<'  */
  YYSYMBOL_32_ = 32,                       /* '>'  */
  YYSYMBOL_33_ = 33,                       /* '+'  */
  YYSYMBOL_34_ = 34,                       /* '-'  */
  YYSYMBOL_35_ = 35,                       /* '*'  */
  YYSYMBOL_36_ = 36,                       /* '/'  */
  YYSYMBOL_37_ = 37,                       /* '%'  */
  YYSYMBOL_38_ = 38,                       /* '('  */
  YYSYMBOL_39_ = 39,                       /* '['  */
  YYSYMBOL_40_ = 40,                       /* '{'  */
  YYSYMBOL_41_ = 41,                       /* '.'  */
  YYSYMBOL_42_ = 42,                       /* ';'  */
  YYSYMBOL_43_ = 43,                       /* '}'  */
  YYSYMBOL_44_ = 44,                       /* ')'  */
  YYSYMBOL_45_ = 45,                       /* ','  */
  YYSYMBOL_46_ = 46,                       /* ']'  */
  YYSYMBOL_47_ = 47,                       /* ':'  */
  YYSYMBOL_YYACCEPT = 48,                  /* $accept  */
  YYSYMBOL_S = 49,                         /* S  */
  YYSYMBOL_CMDs = 50,                      /* CMDs  */
  YYSYMBOL_CMD = 51,                       /* CMD  */
  YYSYMBOL_PUSH_SYMBOLS = 52,              /* PUSH_SYMBOLS  */
  YYSYMBOL_CMD_FUNCTION = 53,              /* CMD_FUNCTION  */
  YYSYMBOL_54_1 = 54,                      /* $@1  */
  YYSYMBOL_55_2 = 55,                      /* $@2  */
  YYSYMBOL_56_3 = 56,                      /* $@3  */
  YYSYMBOL_PARAMS_LIST = 57,               /* PARAMS_LIST  */
  YYSYMBOL_PARAMS = 58,                    /* PARAMS  */
  YYSYMBOL_PARAM = 59,                     /* PARAM  */
  YYSYMBOL_CMD_IF = 60,                    /* CMD_IF  */
  YYSYMBOL_CMD_WHILE = 61,                 /* CMD_WHILE  */
  YYSYMBOL_CMD_FOR = 62,                   /* CMD_FOR  */
  YYSYMBOL_PRIM_E = 63,                    /* PRIM_E  */
  YYSYMBOL_DECL_LET = 64,                  /* DECL_LET  */
  YYSYMBOL_LET_IDs = 65,                   /* LET_IDs  */
  YYSYMBOL_LET_ID = 66,                    /* LET_ID  */
  YYSYMBOL_DECL_CONST = 67,                /* DECL_CONST  */
  YYSYMBOL_CONST_IDs = 68,                 /* CONST_IDs  */
  YYSYMBOL_CONST_ID = 69,                  /* CONST_ID  */
  YYSYMBOL_DECL_VAR = 70,                  /* DECL_VAR  */
  YYSYMBOL_VAR_IDs = 71,                   /* VAR_IDs  */
  YYSYMBOL_VAR_ID = 72,                    /* VAR_ID  */
  YYSYMBOL_E = 73,                         /* E  */
  YYSYMBOL_LVALUEPROP = 74,                /* LVALUEPROP  */
  YYSYMBOL_ARGS_LIST = 75,                 /* ARGS_LIST  */
  YYSYMBOL_ARGS = 76,                      /* ARGS  */
  YYSYMBOL_ID_ARROW = 77,                  /* ID_ARROW  */
  YYSYMBOL_ANON_FUNC = 78,                 /* ANON_FUNC  */
  YYSYMBOL_OBJ = 79,                       /* OBJ  */
  YYSYMBOL_OBJ_FIELDS = 80,                /* OBJ_FIELDS  */
  YYSYMBOL_OBJ_FIELD = 81,                 /* OBJ_FIELD  */
  YYSYMBOL_ARRAY = 82,                     /* ARRAY  */
  YYSYMBOL_ARRAY_ARGS = 83,                /* ARRAY_ARGS  */
  YYSYMBOL_ARRAY_ARG = 84                  /* ARRAY_ARG  */
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
#define YYLAST   617

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  37
/* YYNRULES -- Number of rules.  */
#define YYNRULES  104
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  197

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   284


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
       2,     2,     2,     2,     2,     2,     2,    37,     2,     2,
      38,    44,    35,    33,    45,    34,    41,    36,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    47,    42,
      31,    30,    32,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    39,     2,    46,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    40,     2,    43,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   106,   106,   109,   110,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   128,   132,
     133,   136,   131,   149,   150,   153,   162,   173,   180,   188,
     200,   212,   229,   245,   246,   250,   253,   254,   257,   258,
     259,   262,   265,   266,   269,   270,   271,   274,   277,   278,
     281,   282,   283,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   312,   315,   318,
     319,   320,   332,   344,   355,   356,   359,   360,   363,   364,
     367,   372,   379,   382,   396,   397,   400,   401,   404,   405,
     408,   411,   415,   420,   421
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
  "GT_EQ", "LT_EQ", "DIFF", "PLUS_EQ", "PLUS_PLUS", "EMPTY_BLOCK", "IF",
  "ELSE", "FOR", "WHILE", "LET", "CONST", "VAR", "ASM", "ARROW",
  "ARROW_OBJ", "STRING", "INT", "FLOAT", "ID", "FUNCTION", "RETURN",
  "BOOL", "PARENTESIS_ARROW", "'='", "'<'", "'>'", "'+'", "'-'", "'*'",
  "'/'", "'%'", "'('", "'['", "'{'", "'.'", "';'", "'}'", "')'", "','",
  "']'", "':'", "$accept", "S", "CMDs", "CMD", "PUSH_SYMBOLS",
  "CMD_FUNCTION", "$@1", "$@2", "$@3", "PARAMS_LIST", "PARAMS", "PARAM",
  "CMD_IF", "CMD_WHILE", "CMD_FOR", "PRIM_E", "DECL_LET", "LET_IDs",
  "LET_ID", "DECL_CONST", "CONST_IDs", "CONST_ID", "DECL_VAR", "VAR_IDs",
  "VAR_ID", "E", "LVALUEPROP", "ARGS_LIST", "ARGS", "ID_ARROW",
  "ANON_FUNC", "OBJ", "OBJ_FIELDS", "OBJ_FIELD", "ARRAY", "ARRAY_ARGS",
  "ARRAY_ARG", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-136)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-54)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -136,    14,   550,  -136,  -136,   -29,   -15,    -9,    -7,     0,
      37,  -136,  -136,  -136,   124,   -14,   578,  -136,   578,   185,
     385,  -136,  -136,  -136,  -136,  -136,  -136,  -136,   -11,    15,
      30,   271,    19,    32,  -136,  -136,   578,   101,   578,    43,
    -136,    39,    47,  -136,    44,    61,  -136,    48,   578,  -136,
     571,  -136,  -136,  -136,    54,   290,   131,  -136,     6,    69,
      67,    52,  -136,   142,    56,  -136,   328,  -136,    10,  -136,
    -136,  -136,  -136,  -136,   578,   578,   578,   578,    59,   578,
     578,   578,   578,   578,   578,   578,   578,   578,    77,  -136,
     578,   578,   578,  -136,   156,    62,  -136,   328,   196,   571,
      -7,   571,     0,   571,    37,     5,   328,  -136,  -136,    89,
    -136,   571,    71,   -26,  -136,   578,    89,  -136,  -136,   571,
    -136,   418,   365,   365,     5,     5,  -136,   347,   347,   131,
     131,     9,     9,     9,   328,    72,    86,    74,  -136,     5,
     328,   328,   451,   550,   578,   550,   328,  -136,  -136,   328,
    -136,  -136,   328,  -136,  -136,    81,    92,    88,   210,   571,
    -136,    69,   328,  -136,  -136,  -136,  -136,   578,  -136,  -136,
     123,   309,  -136,  -136,   578,    97,   328,  -136,  -136,   328,
     550,   578,    89,   328,  -136,  -136,   250,    94,   484,   550,
     102,  -136,  -136,  -136,   517,  -136,  -136
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       4,     0,     2,     1,    17,     0,     0,     0,     0,     0,
       0,    75,    73,    72,    77,     0,     0,    74,     0,    24,
       0,    18,    16,     3,    11,     8,    10,     9,     0,     0,
       0,     0,    78,     0,    84,    85,     0,     0,     0,    38,
      35,    37,    44,    41,    43,    50,    47,    49,     0,    55,
       0,    92,    19,    18,     0,     0,    70,    94,    77,     0,
       0,    23,    26,     0,     0,    71,   103,   104,     0,   102,
       4,     5,     6,     7,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    89,     0,     0,    15,
       0,     0,     0,     4,     0,     0,    33,    34,     0,     0,
       0,     0,     0,     0,     0,    56,    53,    54,    20,    24,
      12,     0,     0,     0,    97,     0,     0,    79,    80,     0,
     100,     0,    59,    61,    62,    60,    13,    63,    64,    65,
      68,    66,    67,    69,    91,     0,    88,     0,    86,    58,
      57,    81,     0,     0,     0,     0,    39,    40,    36,    45,
      46,    42,    51,    52,    48,     0,    27,     0,    28,     0,
      95,     0,    83,    25,   101,    14,    76,     0,    87,    82,
      29,     0,    31,    18,     0,     0,    98,    99,    96,    90,
       0,     0,    24,    28,     4,    30,     0,     0,     0,     0,
       0,    93,    32,     4,     0,    21,    22
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -136,  -136,   -63,  -135,   -20,  -136,  -136,  -136,  -136,  -104,
    -136,    25,  -136,  -136,  -136,  -136,   115,    55,  -136,  -136,
      57,  -136,  -136,    53,  -136,   -16,  -136,  -136,  -136,  -136,
    -136,   -13,  -136,    -5,  -136,  -136,    41
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,    23,    51,    24,   108,   155,   196,    60,
      61,    62,    25,    26,    27,    95,    28,    40,    41,    29,
      43,    44,    30,    46,    47,    31,    32,   135,   136,    33,
      34,    67,   113,   114,    35,    68,    69
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      55,    70,    56,    63,    66,   157,    64,   121,   170,    36,
     172,    52,   -54,   -54,     3,    48,    49,   160,    39,   161,
      94,    97,    98,    37,    53,    42,   -18,   -18,    90,    38,
     142,    71,   105,   109,   106,   -27,   111,   107,    81,    82,
      83,    84,    85,    86,    87,   185,    88,    86,    87,    91,
      88,   -27,    92,    93,   192,   119,   120,    72,   122,   123,
     124,   125,    45,   127,   128,   129,   130,   131,   132,   133,
     134,   137,    73,    99,   139,   140,   141,   101,   187,    74,
      75,    76,    77,   146,   100,   149,   147,   152,   150,   102,
     153,   103,    53,   104,   112,   158,   115,   116,   107,   162,
     118,   126,   138,    66,   144,    79,    80,    81,    82,    83,
      84,    85,    86,    87,   156,    88,   166,     8,   159,   173,
     168,   188,   174,    11,    12,    13,    14,    54,   171,    17,
     194,   167,   175,    48,    49,    18,   180,   184,   190,    19,
      20,   163,   193,   176,   -18,   -18,   177,    74,    75,    76,
      77,   179,    96,   182,    50,   148,   178,   154,   183,   151,
     164,    74,    75,    76,    77,   186,    83,    84,    85,    86,
      87,     0,    88,    79,    80,    81,    82,    83,    84,    85,
      86,    87,     0,    88,     0,     0,   117,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    57,    88,     0,     0,
     143,    74,    75,    76,    77,     0,     0,    11,    12,    13,
      58,    54,     0,    17,     0,    74,    75,    76,    77,    18,
       0,     0,     0,    19,    20,    59,     0,    79,    80,    81,
      82,    83,    84,    85,    86,    87,     0,    88,     0,     0,
     145,    79,    80,    81,    82,    83,    84,    85,    86,    87,
       0,    88,     0,     0,   -53,    74,    75,    76,    77,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    74,    75,    76,    77,
       0,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      78,    88,     0,     0,   189,    74,    75,    76,    77,     0,
       0,     0,    79,    80,    81,    82,    83,    84,    85,    86,
      87,     0,    88,    89,    74,    75,    76,    77,     0,     0,
       0,    79,    80,    81,    82,    83,    84,    85,    86,    87,
       0,    88,   110,    74,    75,    76,    77,     0,     0,     0,
      79,    80,    81,    82,    83,    84,    85,    86,    87,     0,
      88,   181,    74,    75,    76,    77,     0,     0,     0,    79,
      80,    81,    82,    83,    84,    85,    86,    87,     0,    88,
     -54,   -54,    76,    77,     0,     0,     0,     0,   -54,   -54,
      81,    82,    83,    84,    85,    86,    87,     0,    88,     0,
       0,     0,     0,     0,     0,     0,    57,     0,    81,    82,
      83,    84,    85,    86,    87,     0,    88,    11,    12,    13,
      14,    54,     0,    17,     0,     0,     0,     0,     0,    18,
       0,     0,     0,    19,    20,    59,     0,     0,     0,     4,
       5,    65,     6,     7,     8,     9,    10,     0,     0,     0,
      11,    12,    13,    14,    15,    16,    17,     0,     0,     0,
       0,     0,    18,     0,     0,     0,    19,    20,    21,     0,
      22,   165,     4,     5,     0,     6,     7,     8,     9,    10,
       0,     0,     0,    11,    12,    13,    14,    15,    16,    17,
       0,     0,     0,     0,     0,    18,     0,     0,     0,    19,
      20,    21,     0,    22,   169,     4,     5,     0,     6,     7,
       8,     9,    10,     0,     0,     0,    11,    12,    13,    14,
      15,    16,    17,     0,     0,     0,     0,     0,    18,     0,
       0,     0,    19,    20,    21,     0,    22,   191,     4,     5,
       0,     6,     7,     8,     9,    10,     0,     0,     0,    11,
      12,    13,    14,    15,    16,    17,     0,     0,     0,     0,
       0,    18,     0,     0,     0,    19,    20,    21,     0,    22,
     195,     4,     5,     0,     6,     7,     8,     9,    10,     0,
       0,     0,    11,    12,    13,    14,    15,    16,    17,     0,
       0,     0,    57,     0,    18,     0,     0,     0,    19,    20,
      21,     0,    22,    11,    12,    13,    14,    54,     0,    17,
      11,    12,    13,    14,    54,    18,    17,     0,     0,    19,
      20,    59,    18,     0,     0,     0,    19,    20
};

static const yytype_int16 yycheck[] =
{
      16,    21,    18,    19,    20,   109,    19,    70,   143,    38,
     145,    25,     7,     8,     0,     9,    10,    43,    25,    45,
      36,    37,    38,    38,    38,    25,    20,    21,     9,    38,
      93,    42,    48,    53,    50,    29,    30,    50,    33,    34,
      35,    36,    37,    38,    39,   180,    41,    38,    39,    30,
      41,    45,    20,    21,   189,    45,    46,    42,    74,    75,
      76,    77,    25,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    42,    30,    90,    91,    92,    30,   182,     5,
       6,     7,     8,    99,    45,   101,    99,   103,   101,    45,
     103,    30,    38,    45,    25,   111,    29,    45,   111,   115,
      44,    42,    25,   119,    42,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    25,    41,    44,    16,    47,    38,
      46,   184,    30,    22,    23,    24,    25,    26,   144,    28,
     193,    45,    44,     9,    10,    34,    13,    40,    44,    38,
      39,   116,    40,   159,    20,    21,   159,     5,     6,     7,
       8,   167,    37,   173,    30,   100,   161,   104,   174,   102,
     119,     5,     6,     7,     8,   181,    35,    36,    37,    38,
      39,    -1,    41,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    -1,    41,    -1,    -1,    44,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    11,    41,    -1,    -1,
      44,     5,     6,     7,     8,    -1,    -1,    22,    23,    24,
      25,    26,    -1,    28,    -1,     5,     6,     7,     8,    34,
      -1,    -1,    -1,    38,    39,    40,    -1,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    -1,    41,    -1,    -1,
      44,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      -1,    41,    -1,    -1,    44,     5,     6,     7,     8,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     5,     6,     7,     8,
      -1,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      19,    41,    -1,    -1,    44,     5,     6,     7,     8,    -1,
      -1,    -1,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    -1,    41,    42,     5,     6,     7,     8,    -1,    -1,
      -1,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      -1,    41,    42,     5,     6,     7,     8,    -1,    -1,    -1,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    -1,
      41,    42,     5,     6,     7,     8,    -1,    -1,    -1,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    -1,    41,
       5,     6,     7,     8,    -1,    -1,    -1,    -1,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    -1,    41,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    11,    -1,    33,    34,
      35,    36,    37,    38,    39,    -1,    41,    22,    23,    24,
      25,    26,    -1,    28,    -1,    -1,    -1,    -1,    -1,    34,
      -1,    -1,    -1,    38,    39,    40,    -1,    -1,    -1,    11,
      12,    46,    14,    15,    16,    17,    18,    -1,    -1,    -1,
      22,    23,    24,    25,    26,    27,    28,    -1,    -1,    -1,
      -1,    -1,    34,    -1,    -1,    -1,    38,    39,    40,    -1,
      42,    43,    11,    12,    -1,    14,    15,    16,    17,    18,
      -1,    -1,    -1,    22,    23,    24,    25,    26,    27,    28,
      -1,    -1,    -1,    -1,    -1,    34,    -1,    -1,    -1,    38,
      39,    40,    -1,    42,    43,    11,    12,    -1,    14,    15,
      16,    17,    18,    -1,    -1,    -1,    22,    23,    24,    25,
      26,    27,    28,    -1,    -1,    -1,    -1,    -1,    34,    -1,
      -1,    -1,    38,    39,    40,    -1,    42,    43,    11,    12,
      -1,    14,    15,    16,    17,    18,    -1,    -1,    -1,    22,
      23,    24,    25,    26,    27,    28,    -1,    -1,    -1,    -1,
      -1,    34,    -1,    -1,    -1,    38,    39,    40,    -1,    42,
      43,    11,    12,    -1,    14,    15,    16,    17,    18,    -1,
      -1,    -1,    22,    23,    24,    25,    26,    27,    28,    -1,
      -1,    -1,    11,    -1,    34,    -1,    -1,    -1,    38,    39,
      40,    -1,    42,    22,    23,    24,    25,    26,    -1,    28,
      22,    23,    24,    25,    26,    34,    28,    -1,    -1,    38,
      39,    40,    34,    -1,    -1,    -1,    38,    39
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    49,    50,     0,    11,    12,    14,    15,    16,    17,
      18,    22,    23,    24,    25,    26,    27,    28,    34,    38,
      39,    40,    42,    51,    53,    60,    61,    62,    64,    67,
      70,    73,    74,    77,    78,    82,    38,    38,    38,    25,
      65,    66,    25,    68,    69,    25,    71,    72,     9,    10,
      30,    52,    25,    38,    26,    73,    73,    11,    25,    40,
      57,    58,    59,    73,    79,    46,    73,    79,    83,    84,
      52,    42,    42,    42,     5,     6,     7,     8,    19,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    41,    42,
       9,    30,    20,    21,    73,    63,    64,    73,    73,    30,
      45,    30,    45,    30,    45,    73,    73,    79,    54,    52,
      42,    30,    25,    80,    81,    29,    45,    44,    44,    45,
      46,    50,    73,    73,    73,    73,    42,    73,    73,    73,
      73,    73,    73,    73,    73,    75,    76,    73,    25,    73,
      73,    73,    50,    44,    42,    44,    73,    79,    65,    73,
      79,    68,    73,    79,    71,    55,    25,    57,    73,    47,
      43,    45,    73,    59,    84,    43,    44,    45,    46,    43,
      51,    73,    51,    38,    30,    44,    73,    79,    81,    73,
      13,    42,    52,    73,    40,    51,    73,    57,    50,    44,
      44,    43,    51,    40,    50,    43,    56
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    48,    49,    50,    50,    51,    51,    51,    51,    51,
      51,    51,    51,    51,    51,    51,    51,    51,    52,    54,
      55,    56,    53,    57,    57,    58,    58,    59,    59,    60,
      60,    61,    62,    63,    63,    64,    65,    65,    66,    66,
      66,    67,    68,    68,    69,    69,    69,    70,    71,    71,
      72,    72,    72,    73,    73,    73,    73,    73,    73,    73,
      73,    73,    73,    73,    73,    73,    73,    73,    73,    73,
      73,    73,    73,    73,    73,    73,    73,    73,    73,    73,
      73,    73,    73,    73,    73,    73,    74,    74,    75,    75,
      76,    76,    77,    78,    79,    79,    80,    80,    81,    81,
      82,    83,    83,    84,    84
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     0,     2,     2,     2,     1,     1,
       1,     1,     3,     3,     4,     2,     1,     1,     0,     0,
       0,     0,    12,     1,     0,     3,     1,     1,     3,     5,
       7,     5,     9,     1,     1,     2,     3,     1,     1,     3,
       3,     2,     3,     1,     1,     3,     3,     2,     3,     1,
       1,     3,     3,     3,     3,     2,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       2,     2,     1,     1,     1,     1,     4,     1,     1,     3,
       3,     3,     4,     4,     1,     1,     3,     4,     1,     0,
       3,     1,     2,     8,     1,     3,     3,     1,     3,     3,
       3,     3,     1,     1,     1
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
#line 106 "mini_js.y"
         { print(resolveAddr(yyvsp[0].code  + "." + functions)); }
#line 1511 "mini_js.tab.c"
    break;

  case 3: /* CMDs: CMDs CMD  */
#line 109 "mini_js.y"
                { yyval.code = yyvsp[-1].code + yyvsp[0].code; }
#line 1517 "mini_js.tab.c"
    break;

  case 4: /* CMDs: %empty  */
#line 110 "mini_js.y"
       {yyval.clear();}
#line 1523 "mini_js.tab.c"
    break;

  case 12: /* CMD: RETURN E ';'  */
#line 120 "mini_js.y"
                   { yyval.code = yyvsp[-1].code + "'&retorno'" + "@" + "~"; }
#line 1529 "mini_js.tab.c"
    break;

  case 13: /* CMD: E ASM ';'  */
#line 121 "mini_js.y"
                { yyval.code = yyvsp[-2].code + yyvsp[-1].code + "^"; }
#line 1535 "mini_js.tab.c"
    break;

  case 14: /* CMD: '{' PUSH_SYMBOLS CMDs '}'  */
#line 122 "mini_js.y"
                                { symbols.pop_back(); yyval.code = vec("<{") + yyvsp[-1].code + vec("}>"); }
#line 1541 "mini_js.tab.c"
    break;

  case 15: /* CMD: E ';'  */
#line 123 "mini_js.y"
            { yyval.code = yyvsp[-1].code + "^";}
#line 1547 "mini_js.tab.c"
    break;

  case 16: /* CMD: ';'  */
#line 124 "mini_js.y"
          { yyval.clear(); }
#line 1553 "mini_js.tab.c"
    break;

  case 17: /* CMD: EMPTY_BLOCK  */
#line 125 "mini_js.y"
                  { yyval.clear(); }
#line 1559 "mini_js.tab.c"
    break;

  case 18: /* PUSH_SYMBOLS: %empty  */
#line 128 "mini_js.y"
               { symbols.push_back( map< string, Variable >{} ); }
#line 1565 "mini_js.tab.c"
    break;

  case 19: /* $@1: %empty  */
#line 132 "mini_js.y"
                { declareVariable(DeclVar, yyvsp[0]); }
#line 1571 "mini_js.tab.c"
    break;

  case 20: /* $@2: %empty  */
#line 133 "mini_js.y"
                { isFunctionScope = true; }
#line 1577 "mini_js.tab.c"
    break;

  case 21: /* $@3: %empty  */
#line 136 "mini_js.y"
                { isFunctionScope = false; }
#line 1583 "mini_js.tab.c"
    break;

  case 22: /* CMD_FUNCTION: FUNCTION ID $@1 $@2 '(' PUSH_SYMBOLS PARAMS_LIST ')' '{' CMDs '}' $@3  */
#line 137 "mini_js.y"
                {
                    string lbl_func = getLabel("func_" + yyvsp[-10].code[0]);
                    string def_lbl_func = ":" + lbl_func;
                    // mdc & mdc {} = '&funcao' 21 [=] ^
                    yyval.code =  yyvsp[-10].code + "&" + yyvsp[-10].code + 
                        "{}" + "=" + "'&funcao'" + lbl_func + 
                        "[=]" + "^";
                    functions = functions + def_lbl_func + yyvsp[-5].code + yyvsp[-2].code +
                       "undefined" + "@" + "'&retorno'" + "@"+ "~";
                    symbols.pop_back();
                }
#line 1599 "mini_js.tab.c"
    break;

  case 24: /* PARAMS_LIST: %empty  */
#line 150 "mini_js.y"
              { yyval.clear(); }
#line 1605 "mini_js.tab.c"
    break;

  case 25: /* PARAMS: PARAMS ',' PARAM  */
#line 154 "mini_js.y"
        {
            // declareVariable(DeclLet, $3);
            yyval.code = yyvsp[-2].code + yyvsp[0].code + "&" + yyvsp[0].code + "arguments" + "@" 
                + to_string(yyvsp[-2].args_counter) + "[@]" + "=" + "^";
            if (yyvsp[0].default_value.size() > 0) 
                yyval.code = yyval.code + generateDefaultParamsCode(yyvsp[0]);
            yyval.args_counter = yyvsp[-2].args_counter + yyvsp[0].args_counter;
        }
#line 1618 "mini_js.tab.c"
    break;

  case 26: /* PARAMS: PARAM  */
#line 163 "mini_js.y"
       {    
            // declareVariable(DeclLet, $1);
            yyval.code = yyvsp[0].code + "&" + yyvsp[0].code + "arguments" + "@" 
                + "0" + "[@]" + "=" + "^";
            if (yyvsp[0].default_value.size() > 0) 
                yyval.code = yyval.code + generateDefaultParamsCode(yyvsp[0]);
            yyval.args_counter = yyvsp[0].args_counter;
       }
#line 1631 "mini_js.tab.c"
    break;

  case 27: /* PARAM: ID  */
#line 174 "mini_js.y"
            {
                yyval.code = yyvsp[0].code;
                yyval.default_value.clear();
                yyval.args_counter = 1;
                declareVariable(DeclLet, yyvsp[0]);
            }
#line 1642 "mini_js.tab.c"
    break;

  case 28: /* PARAM: ID '=' E  */
#line 181 "mini_js.y"
            {
                yyval.code = yyvsp[-2].code;
                yyval.default_value = yyvsp[0].code;
                yyval.args_counter = 1;
                declareVariable(DeclLet, yyvsp[-2]);
            }
#line 1653 "mini_js.tab.c"
    break;

  case 29: /* CMD_IF: IF '(' E ')' CMD  */
#line 189 "mini_js.y"
    {
        string lbl_true, lbl_end_if, def_lbl_true, def_lbl_end_if;
        tie(lbl_true, lbl_end_if, def_lbl_true, def_lbl_end_if) = generateIfLabels();
        yyval.code = yyvsp[-2].code + 
                lbl_true + "?" + 
                lbl_end_if + "#" + 
                def_lbl_true + yyvsp[0].code 
                + def_lbl_end_if; 

    }
#line 1668 "mini_js.tab.c"
    break;

  case 30: /* CMD_IF: IF '(' E ')' CMD ELSE CMD  */
#line 201 "mini_js.y"
    { 
        string lbl_true, lbl_end_if, def_lbl_true, def_lbl_end_if;
        tie(lbl_true, lbl_end_if, def_lbl_true, def_lbl_end_if) = generateIfLabels();
        yyval.code = yyvsp[-4].code +                     // Codigo da expressão
                lbl_true + "?" +                // Código do IF
                yyvsp[0].code + lbl_end_if + "#" +    // Código do False
                def_lbl_true + yyvsp[-2].code +        // Código do True
                def_lbl_end_if                  // Fim do IF
                ;
    }
#line 1683 "mini_js.tab.c"
    break;

  case 31: /* CMD_WHILE: WHILE '(' E ')' CMD  */
#line 213 "mini_js.y"
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
#line 1703 "mini_js.tab.c"
    break;

  case 32: /* CMD_FOR: FOR '(' PRIM_E ';' E ';' E ')' CMD  */
#line 230 "mini_js.y"
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
#line 1721 "mini_js.tab.c"
    break;

  case 34: /* PRIM_E: E  */
#line 247 "mini_js.y"
         { yyval.code = yyvsp[0].code + "^"; }
#line 1727 "mini_js.tab.c"
    break;

  case 35: /* DECL_LET: LET LET_IDs  */
#line 250 "mini_js.y"
                       { yyval.code = yyvsp[0].code; }
#line 1733 "mini_js.tab.c"
    break;

  case 36: /* LET_IDs: LET_ID ',' LET_IDs  */
#line 253 "mini_js.y"
                             { yyval.code = yyvsp[-2].code + yyvsp[0].code; }
#line 1739 "mini_js.tab.c"
    break;

  case 38: /* LET_ID: ID  */
#line 257 "mini_js.y"
            { yyval.code = declareVariable(DeclLet, yyvsp[0]); }
#line 1745 "mini_js.tab.c"
    break;

  case 39: /* LET_ID: ID '=' E  */
#line 258 "mini_js.y"
                  {  yyval.code = declareVariable(DeclLet, yyvsp[-2]) + yyvsp[-2].code + yyvsp[0].code + "=" + "^"; }
#line 1751 "mini_js.tab.c"
    break;

  case 40: /* LET_ID: ID '=' OBJ  */
#line 259 "mini_js.y"
                    {  yyval.code = declareVariable(DeclLet, yyvsp[-2]) + yyvsp[-2].code + yyvsp[0].code + "=" + "^"; }
#line 1757 "mini_js.tab.c"
    break;

  case 41: /* DECL_CONST: CONST CONST_IDs  */
#line 262 "mini_js.y"
                             { yyval.code = yyvsp[0].code; }
#line 1763 "mini_js.tab.c"
    break;

  case 42: /* CONST_IDs: CONST_ID ',' CONST_IDs  */
#line 265 "mini_js.y"
                                   { yyval.code = yyvsp[-2].code + yyvsp[0].code; }
#line 1769 "mini_js.tab.c"
    break;

  case 44: /* CONST_ID: ID  */
#line 269 "mini_js.y"
              {  yyval.code = declareVariable(DeclConst, yyvsp[0]); }
#line 1775 "mini_js.tab.c"
    break;

  case 45: /* CONST_ID: ID '=' E  */
#line 270 "mini_js.y"
                  { yyval.code = declareVariable(DeclConst, yyvsp[-2]) + yyvsp[-2].code + yyvsp[0].code + "=" + "^"; }
#line 1781 "mini_js.tab.c"
    break;

  case 46: /* CONST_ID: ID '=' OBJ  */
#line 271 "mini_js.y"
                    {  yyval.code = declareVariable(DeclConst, yyvsp[-2]) + yyvsp[-2].code + yyvsp[0].code + "=" + "^"; }
#line 1787 "mini_js.tab.c"
    break;

  case 47: /* DECL_VAR: VAR VAR_IDs  */
#line 274 "mini_js.y"
                       { yyval.code = yyvsp[0].code; }
#line 1793 "mini_js.tab.c"
    break;

  case 48: /* VAR_IDs: VAR_ID ',' VAR_IDs  */
#line 277 "mini_js.y"
                             { yyval.code = yyvsp[-2].code + yyvsp[0].code; }
#line 1799 "mini_js.tab.c"
    break;

  case 50: /* VAR_ID: ID  */
#line 281 "mini_js.y"
            { yyval.code = declareVariable(DeclVar, yyvsp[0]); }
#line 1805 "mini_js.tab.c"
    break;

  case 51: /* VAR_ID: ID '=' E  */
#line 282 "mini_js.y"
                  { yyval.code = declareVariable(DeclVar, yyvsp[-2]) + yyvsp[-2].code + yyvsp[0].code + "=" + "^"; }
#line 1811 "mini_js.tab.c"
    break;

  case 52: /* VAR_ID: ID '=' OBJ  */
#line 283 "mini_js.y"
                    {  yyval.code = declareVariable(DeclVar, yyvsp[-2]) + yyvsp[-2].code + yyvsp[0].code + "=" + "^"; }
#line 1817 "mini_js.tab.c"
    break;

  case 53: /* E: ID '=' E  */
#line 286 "mini_js.y"
               { verifyAttrib(yyvsp[-2].code[0],true); yyval.code = yyvsp[-2].code + yyvsp[0].code + "="; }
#line 1823 "mini_js.tab.c"
    break;

  case 54: /* E: ID '=' OBJ  */
#line 287 "mini_js.y"
                 { verifyAttrib(yyvsp[-2].code[0],true); yyval.code = yyvsp[-2].code + yyvsp[0].code + "="; }
#line 1829 "mini_js.tab.c"
    break;

  case 55: /* E: ID PLUS_PLUS  */
#line 288 "mini_js.y"
                   { verifyAttrib(yyvsp[-1].code[0], true); yyval.code = yyvsp[-1].code + "@" + yyvsp[-1].code + yyvsp[-1].code + "@" + "1" + "+" + "=" + "^"; }
#line 1835 "mini_js.tab.c"
    break;

  case 56: /* E: ID PLUS_EQ E  */
#line 289 "mini_js.y"
                   { verifyAttrib(yyvsp[-2].code[0], true); yyval.code = yyvsp[-2].code + yyvsp[-2].code + "@" + yyvsp[0].code + "+" + "="; }
#line 1841 "mini_js.tab.c"
    break;

  case 57: /* E: LVALUEPROP '=' E  */
#line 290 "mini_js.y"
                        { verifyAttrib(yyvsp[-2].code[0], true); yyval.code = yyvsp[-2].code + yyvsp[0].code + "[=]"; }
#line 1847 "mini_js.tab.c"
    break;

  case 58: /* E: LVALUEPROP PLUS_EQ E  */
#line 291 "mini_js.y"
                           { verifyAttrib(yyvsp[-2].code[0], true); yyval.code = yyvsp[-2].code + yyvsp[-2].code + "[@]" + yyvsp[0].code + "+" + "[=]"; }
#line 1853 "mini_js.tab.c"
    break;

  case 59: /* E: E EQUAL E  */
#line 292 "mini_js.y"
                { yyval.code = yyvsp[-2].code + yyvsp[0].code + "=="; }
#line 1859 "mini_js.tab.c"
    break;

  case 60: /* E: E DIFF E  */
#line 293 "mini_js.y"
               { yyval.code = yyvsp[-2].code + yyvsp[0].code + "!="; }
#line 1865 "mini_js.tab.c"
    break;

  case 61: /* E: E GT_EQ E  */
#line 294 "mini_js.y"
                { yyval.code = yyvsp[-2].code + yyvsp[0].code + ">="; }
#line 1871 "mini_js.tab.c"
    break;

  case 62: /* E: E LT_EQ E  */
#line 295 "mini_js.y"
                { yyval.code = yyvsp[-2].code + yyvsp[0].code + "<="; }
#line 1877 "mini_js.tab.c"
    break;

  case 63: /* E: E '<' E  */
#line 296 "mini_js.y"
              { yyval.code = yyvsp[-2].code + yyvsp[0].code + "<"; }
#line 1883 "mini_js.tab.c"
    break;

  case 64: /* E: E '>' E  */
#line 297 "mini_js.y"
              { yyval.code = yyvsp[-2].code + yyvsp[0].code + ">"; }
#line 1889 "mini_js.tab.c"
    break;

  case 65: /* E: E '+' E  */
#line 298 "mini_js.y"
              { yyval.code = yyvsp[-2].code + yyvsp[0].code + "+"; }
#line 1895 "mini_js.tab.c"
    break;

  case 66: /* E: E '*' E  */
#line 299 "mini_js.y"
              { yyval.code = yyvsp[-2].code + yyvsp[0].code + "*"; }
#line 1901 "mini_js.tab.c"
    break;

  case 67: /* E: E '/' E  */
#line 300 "mini_js.y"
              { yyval.code = yyvsp[-2].code + yyvsp[0].code + "/"; }
#line 1907 "mini_js.tab.c"
    break;

  case 68: /* E: E '-' E  */
#line 301 "mini_js.y"
              { yyval.code = yyvsp[-2].code + yyvsp[0].code + "-"; }
#line 1913 "mini_js.tab.c"
    break;

  case 69: /* E: E '%' E  */
#line 302 "mini_js.y"
              { yyval.code = yyvsp[-2].code + yyvsp[0].code + "%"; }
#line 1919 "mini_js.tab.c"
    break;

  case 70: /* E: '-' E  */
#line 303 "mini_js.y"
              { yyval.code = "0" + yyvsp[0].code + yyvsp[-1].code; }
#line 1925 "mini_js.tab.c"
    break;

  case 71: /* E: '[' ']'  */
#line 304 "mini_js.y"
              { yyval.code = vec("[]");               }
#line 1931 "mini_js.tab.c"
    break;

  case 76: /* E: E '(' ARGS_LIST ')'  */
#line 309 "mini_js.y"
                            { 
            yyval.code = yyvsp[-1].code + to_string( yyvsp[-1].args_counter ) + yyvsp[-3].code + "$"; 
        }
#line 1939 "mini_js.tab.c"
    break;

  case 77: /* E: ID  */
#line 312 "mini_js.y"
                                { 
            verifyAttrib(yyvsp[0].code[0], false); yyval.code = yyvsp[0].code + "@";         
        }
#line 1947 "mini_js.tab.c"
    break;

  case 78: /* E: LVALUEPROP  */
#line 315 "mini_js.y"
                            { 
            verifyAttrib(yyvsp[0].code[0], false); yyval.code = yyvsp[0].code + "[@]";      
        }
#line 1955 "mini_js.tab.c"
    break;

  case 79: /* E: '(' E ')'  */
#line 318 "mini_js.y"
                            { yyval.code = yyvsp[-1].code; }
#line 1961 "mini_js.tab.c"
    break;

  case 80: /* E: '(' OBJ ')'  */
#line 319 "mini_js.y"
                            { yyval.code = yyvsp[-1].code; }
#line 1967 "mini_js.tab.c"
    break;

  case 81: /* E: ID_ARROW ARROW E  */
#line 320 "mini_js.y"
                            {
            string lbl_func = getLabel("func_" + yyvsp[-2].code[0]);
            string def_lbl_func = ":" + lbl_func;
        
            // x => 2*x; : {} '&funcao' 10 [<=] = ^ . x & x arguments @ 0 [@] = ^ 2 x @ * '&retorno' @ ~
            yyval.code =  vec("{}") + "'&funcao'" + lbl_func + "[<=]";
            functions = functions + def_lbl_func + 
                yyvsp[-2].code + "&" + yyvsp[-2].code + 
                "arguments" + "@" + "0" + "[@]" + "=" + "^" +
                yyvsp[0].code + "'&retorno'" + "@" + "~";
            symbols.pop_back();
        }
#line 1984 "mini_js.tab.c"
    break;

  case 82: /* E: ID_ARROW ARROW_OBJ CMDs '}'  */
#line 332 "mini_js.y"
                                  {
            string lbl_func = getLabel("func_" + yyvsp[-3].code[0]);
            string def_lbl_func = ":" + lbl_func;
        
            // x => 2*x; : {} '&funcao' 10 [<=] = ^ . x & x arguments @ 0 [@] = ^ 2 x @ * '&retorno' @ ~
            yyval.code =  vec("{}") + "'&funcao'" + lbl_func + "[<=]";
            functions = functions + def_lbl_func + 
                yyvsp[-3].code + "&" + yyvsp[-3].code + 
                "arguments" + "@" + "0" + "[@]" + "=" + "^" +
                yyvsp[-1].code + "'&retorno'" + "@" + "~";
            symbols.pop_back();
        }
#line 2001 "mini_js.tab.c"
    break;

  case 83: /* E: '(' PARAMS_LIST PARENTESIS_ARROW E  */
#line 344 "mini_js.y"
                                         { 
            string lbl_func = getLabel("func_" + yyvsp[-3].code[0]);
            string def_lbl_func = ":" + lbl_func;
        
            // x => 2*x; : {} '&funcao' 10 [<=] = ^ . x & x arguments @ 0 [@] = ^ 2 x @ * '&retorno' @ ~
            yyval.code =  vec("{}") + "'&funcao'" + lbl_func + "[<=]";
            functions = functions + def_lbl_func + 
                yyvsp[-3].code + "&" + yyvsp[-2].code + yyvsp[0].code
                + "'&retorno'" + "@" + "~";
            symbols.pop_back();
        }
#line 2017 "mini_js.tab.c"
    break;

  case 86: /* LVALUEPROP: E '.' ID  */
#line 359 "mini_js.y"
                         { yyval.code = yyvsp[-2].code + yyvsp[0].code; }
#line 2023 "mini_js.tab.c"
    break;

  case 87: /* LVALUEPROP: E '[' E ']'  */
#line 360 "mini_js.y"
                            { yyval.code = yyvsp[-3].code + yyvsp[-1].code; }
#line 2029 "mini_js.tab.c"
    break;

  case 89: /* ARGS_LIST: %empty  */
#line 364 "mini_js.y"
             { yyval.clear(); }
#line 2035 "mini_js.tab.c"
    break;

  case 90: /* ARGS: ARGS ',' E  */
#line 368 "mini_js.y"
        { 
            yyval.code = yyvsp[-2].code + yyvsp[0].code;
            yyval.args_counter++; 
        }
#line 2044 "mini_js.tab.c"
    break;

  case 91: /* ARGS: E  */
#line 373 "mini_js.y"
        { 
            yyval.code = yyvsp[0].code;
            yyval.args_counter++; 
        }
#line 2053 "mini_js.tab.c"
    break;

  case 92: /* ID_ARROW: ID PUSH_SYMBOLS  */
#line 379 "mini_js.y"
                           { declareVariable(DeclLet, yyvsp[-1]); }
#line 2059 "mini_js.tab.c"
    break;

  case 93: /* ANON_FUNC: FUNCTION '(' PUSH_SYMBOLS PARAMS_LIST ')' '{' CMDs '}'  */
#line 383 "mini_js.y"
            {
                string lbl_func = getLabel("func_");
                string def_lbl_func = ":" + lbl_func;
                
                yyval.code =  vec("{}") + "'&funcao'" + 
                    lbl_func + "[<=]";
                functions = functions + def_lbl_func + 
                    yyvsp[-4].code + yyvsp[-1].code +
                    "undefined" + "@" + "'&retorno'" + "@"+ "~";
                symbols.pop_back();
            }
#line 2075 "mini_js.tab.c"
    break;

  case 95: /* OBJ: '{' OBJ_FIELDS '}'  */
#line 397 "mini_js.y"
                         { yyval.code = "{}" + yyvsp[-1].code; }
#line 2081 "mini_js.tab.c"
    break;

  case 96: /* OBJ_FIELDS: OBJ_FIELDS ',' OBJ_FIELD  */
#line 400 "mini_js.y"
                                      { yyval.code = yyvsp[-2].code + yyvsp[0].code; }
#line 2087 "mini_js.tab.c"
    break;

  case 98: /* OBJ_FIELD: ID ':' E  */
#line 404 "mini_js.y"
                     { yyval.code = yyvsp[-2].code + yyvsp[0].code + "[<=]"; }
#line 2093 "mini_js.tab.c"
    break;

  case 99: /* OBJ_FIELD: ID ':' OBJ  */
#line 405 "mini_js.y"
                       { yyval.code = yyvsp[-2].code + yyvsp[0].code + "[<=]"; }
#line 2099 "mini_js.tab.c"
    break;

  case 100: /* ARRAY: '[' ARRAY_ARGS ']'  */
#line 408 "mini_js.y"
                           {yyval.code = yyvsp[-1].code; }
#line 2105 "mini_js.tab.c"
    break;

  case 101: /* ARRAY_ARGS: ARRAY_ARGS ',' ARRAY_ARG  */
#line 411 "mini_js.y"
                                      { 
        yyval.code = yyvsp[-2].code + to_string(yyvsp[-2].args_counter) + yyvsp[0].code + "[<=]"; 
        yyval.args_counter++;
    }
#line 2114 "mini_js.tab.c"
    break;

  case 102: /* ARRAY_ARGS: ARRAY_ARG  */
#line 415 "mini_js.y"
                { 
        yyval.code = yyvsp[0].code + to_string(yyvsp[0].args_counter) + "[<=]"; 
        yyval.args_counter++;
    }
#line 2123 "mini_js.tab.c"
    break;


#line 2127 "mini_js.tab.c"

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

#line 429 "mini_js.y"

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
   log("\nDeclarando variável");
    string name = attr.code[0];
    int ln = attr.ln, col = attr.col;
    log("Nome: ", name);
    log("Tipo: ", type);
    log("Linha: ",ln," Coluna: ",col);

    auto& current = symbols.back();

    if(current.count(name) == 0) {
        current[name] = Variable{ln, col, type};
        return vector<string>{name, "&"};
    }
    if(type == DeclVar && current[name].type == DeclVar ) {
        current[name] = Variable{ln, col, type};
        return vector<string>{};
    } 
    cerr << "Erro: a variável '" << name << "' já foi declarada na linha " << current[name].ln << "." << endl;
    exit(1);     
}

vector<string> declareVariable(Decl type, string name, int ln, int col) {
    Attributes attr = {vec(name), 0, {}, ln, col};
    return declareVariable(type, attr);
}

void verifyAttrib(string name, bool a) {
    if (isFunctionScope) return;

    log("\nVerificando atribuição" );
    log("Nome: " , name );

    for (int i = symbols.size() - 1; i >=0; i--){
        auto& curr = symbols[i];
        log(" ==== escopo nivel " , i , " ====" );
        for (const auto& pair : symbols[i]) {
            log("Key: " , pair.first );
            log("Ln: " , pair.second.ln );
            log("Col: " , pair.second.col );
            log("Type: " , pair.second.type );
            log("====================" );
        }
        log("curr.count(name): " , curr.count(name) );
        if(curr.count(name) > 0) {
            if(a && curr[name].type == DeclConst) {
                cerr << "Erro: a variável '" << name << "' não pode ser modificada." << endl;
                exit(1);     
            }
            else return;   
        }
    }
    cerr << "Erro: a variável '" << name << "' não foi declarada." << endl;
    exit(1);
}

vector<string> vec(string s) {
    return vector<string>{s};
}


tuple<string,string,string,string> generateIfLabels(){
    string lbl_true = getLabel( "lbl_true" );
    string lbl_end_if = getLabel( "lbl_end_if" );
    string def_lbl_true = ":" + lbl_true;
    string def_lbl_end_if = ":" + lbl_end_if;
    return make_tuple(lbl_true, lbl_end_if, def_lbl_true, def_lbl_end_if);
}

vector<string> generateDefaultParamsCode(Attributes attr){
    string lbl_true, lbl_end_if, def_lbl_true, def_lbl_end_if;
    tie(lbl_true, lbl_end_if, def_lbl_true, def_lbl_end_if) = generateIfLabels();
    return declareVariable(DeclVar, "df_name", 1, 1) +
        attr.code + "@" + "df_name" + "@" + "==" +
        lbl_true + "?" + lbl_end_if + "#" + 
        def_lbl_true + attr.code + attr.default_value + "=" + "^" +
        def_lbl_end_if;
}

string trim(string str, string charsToTrim) {
    unordered_set<char> removeSet(charsToTrim.begin(), charsToTrim.end());
    string result = "";
    for (char c : str) 
        if (removeSet.find(c) == removeSet.end()) 
            result += c;
        
    return result;
}

vector<string> getFormattedMdpCode(string mdpCode){
	vector<string> formattedMdp;
	string instr = "";
	for(auto c : mdpCode){
		if(c != ' ')
			instr += c;
		else {
			formattedMdp.push_back(instr);
			instr = "";
		}
	}
	formattedMdp.push_back(instr);
	return formattedMdp;
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
