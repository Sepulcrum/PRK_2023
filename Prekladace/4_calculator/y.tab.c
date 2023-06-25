/* original parser id follows */
/* yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93" */
/* (use YYMAJOR/YYMINOR for ifdefs dependent on parser version) */

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20170709

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)
#define YYENOMEM       (-2)
#define YYEOF          0
#define YYPREFIX "yy"

#define YYPURE 0

#line 2 "ll.y"
/*
PetrLang=fce;
expr=term, expr1;
expr1="+",term,expr1 |;
term=factor, term1;
term1="*", factor, term1 |;
factor="(", expr , ")",mod,binNum | number;
mod = "%";
number=hexaNum | intNum | binNum | octNum;
hexaNum="h", hexaDigit, {hexaDigit};
intNum="0" | nonZeroDigits, {digits};
binNum="b", binDigit, {binDigit};
octNum = "o", octaDigit, {octaDigit};
octaDigit= "1"|"2"|"3"|"4"|"5"|"6"|"7"|"0";
hexaDigit="1"|"2"|"3"|"4"|"5"|"6"|"7"|"8"|"9"|"0"|"A"|"B"|"C"|"D"|"E"|"F";
nonZeroDigits="1"|"2"|"3"|"4"|"5"|"6"|"7"|"8"|"9";
digits="1"|"2"|"3"|"4"|"5"|"6"|"7"|"8"|"9"|"0";
binDigit="0"|"1";
fce=fceName, "(", expr, ")";
fceName="IND";
*/

#include <stdio.h>
/*#include "prk-stack.h"*/
/*#include "prints.h"*/

int yylex();
void yyerror(const char *s);
extern int yylineno;

int ind(int x, int bin);
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#line 35 "ll.y"
typedef union {
  int int_value;
  int integer;
  char* str_value;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 66 "y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define L_BR 257
#define R_BR 258
#define PLUS 259
#define MPY 260
#define MOD 261
#define HEX_NUM 262
#define INT_NUM 263
#define BIN_NUM 264
#define OCT_NUM 265
#define LINE_END 266
#define FCE_IND 267
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    0,    1,    2,    2,    3,    4,    4,    5,    5,
    6,    6,    6,    6,    7,
};
static const YYINT yylen[] = {                            2,
    3,    2,    2,    3,    0,    2,    3,    0,    3,    1,
    1,    1,    1,    1,    6,
};
static const YYINT yydefred[] = {                         0,
    0,    0,    0,    0,    0,    2,    0,   11,   12,   13,
   14,    0,    0,    0,   10,    1,    0,    0,    0,    3,
    0,    6,    9,    0,    0,    0,   15,    4,    7,
};
static const YYINT yydgoto[] = {                          2,
   12,   20,   13,   22,   14,   15,    3,
};
static const YYINT yysindex[] = {                      -266,
 -255, -266, -263, -257, -262,    0, -257,    0,    0,    0,
    0, -248, -244, -243,    0,    0, -242, -246, -257,    0,
 -257,    0,    0, -239, -244, -243,    0,    0,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0, -247, -249,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0, -247, -249,    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
   13,   -4,    3,   -3,    4,    0,   22,
};
#define YYTABLESIZE 25
static const YYINT yytable[] = {                          7,
    1,    4,    6,   16,    8,    9,   10,   11,    8,    8,
    5,    8,   18,    5,   19,   23,   21,   24,   27,   17,
   28,   25,   29,    5,   26,
};
static const YYINT yycheck[] = {                        257,
  267,  257,  266,  266,  262,  263,  264,  265,  258,  259,
  258,  261,  261,  261,  259,  258,  260,  264,  258,    7,
   25,   19,   26,    2,   21,
};
#define YYFINAL 2
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 267
#define YYUNDFTOKEN 277
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"L_BR","R_BR","PLUS","MPY","MOD",
"HEX_NUM","INT_NUM","BIN_NUM","OCT_NUM","LINE_END","FCE_IND",0,0,0,0,0,0,0,0,0,
"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : PetrLang",
"PetrLang : PetrLang fceInd LINE_END",
"PetrLang : fceInd LINE_END",
"expr : term expr1",
"expr1 : PLUS term expr1",
"expr1 :",
"term : factor term1",
"term1 : MPY factor term1",
"term1 :",
"factor : L_BR expr R_BR",
"factor : number",
"number : HEX_NUM",
"number : INT_NUM",
"number : BIN_NUM",
"number : OCT_NUM",
"fceInd : FCE_IND L_BR expr MOD BIN_NUM R_BR",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#define YYINITSTACKSIZE 200

typedef struct {
    unsigned stacksize;
    YYINT    *s_base;
    YYINT    *s_mark;
    YYINT    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 153 "ll.y"

void yyerror(const char *s) {
    printf("%s\n", s);
}

void main() {
    // yydebug = 1;
    //printf("Entering the main");
    yyparse();
}
int ind(int x, int bin){
	int count = x%bin;
	return count;
}
void printInd(int a)
{
	char str[10];
	sprintf(str, "%d", a);
        printf("Result number is: ");
	printf(str);
	printf("\n");
    for (int i = 0; i < sizeof(str); ++i)
    {
      if(str[i]=='0'){
        printf("Kumar ");
      }
      else if(str[i]=='1'){
        printf("Ashwin ");
      }
      else if(str[i]=='2'){
        printf("Suren ");
      }
      else if(str[i]=='3'){
        printf("Nithin ");
      }
      else if(str[i]=='4'){
        printf("Yuva ");
      }
      else if(str[i]=='5'){
        printf("Jamal ");
      }
      else if(str[i]=='6'){
        printf("Rudrakša ");
      }
      else if(str[i]=='7'){
        printf("Akhila ");
      }
      else if(str[i]=='8'){
        printf("Rádha ");
      }
      else if(str[i]=='9'){
        printf("Nara ");
      }
      else{
       printf("No more Ind found");
	printf("\n");
	break;
      }
    }
}
#line 287 "y.tab.c"

#if YYDEBUG
#include <stdio.h>	/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    YYINT *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return YYENOMEM;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (YYINT *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return YYENOMEM;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return YYENOMEM;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yym = 0;
    yyn = 0;
    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        yychar = YYLEX;
        if (yychar < 0) yychar = YYEOF;
#if YYDEBUG
        if (yydebug)
        {
            if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if (((yyn = yysindex[yystate]) != 0) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if (((yyn = yyrindex[yystate]) != 0) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag != 0) goto yyinrecovery;

    YYERROR_CALL("syntax error");

    goto yyerrlab; /* redundant goto avoids 'unused label' warning */
yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if (((yyn = yysindex[*yystack.s_mark]) != 0) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == YYEOF) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym > 0)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);

    switch (yyn)
    {
case 1:
#line 58 "ll.y"
	{
			/*printf("Syntax OK, Rule1\n");*/
			/*printf("Klasický tvar: %d\n", $2);*/
			printInd(yystack.l_mark[-1].integer);
			printf("\n");
    }
break;
case 2:
#line 70 "ll.y"
	{
			printf("Syntax OK, RULE IND\n");
			printInd(yystack.l_mark[-1].integer);
	}
break;
case 3:
#line 83 "ll.y"
	{
			/*printf("Rule5\n");*/
			yyval.integer = yystack.l_mark[-1].integer + yystack.l_mark[0].integer;
		}
break;
case 4:
#line 89 "ll.y"
	{
			/*printf("Rule6\n");*/
			yyval.integer = yystack.l_mark[-1].integer + yystack.l_mark[0].integer;
		}
break;
case 5:
#line 93 "ll.y"
	{
			/*printf("Rule7\n");*/
			yyval.integer = 0;
		}
break;
case 6:
#line 99 "ll.y"
	{
			/*printf("Rule8\n");*/
			yyval.integer = yystack.l_mark[-1].integer * yystack.l_mark[0].integer;
   	}
break;
case 7:
#line 106 "ll.y"
	{
			/*printf("Rule9\n");*/
			yyval.integer = yystack.l_mark[-1].integer * yystack.l_mark[0].integer;
    }
break;
case 8:
#line 110 "ll.y"
	{
			/*printf("Rule10\n");*/
			yyval.integer = 1;
    }
break;
case 9:
#line 116 "ll.y"
	{
			/*printf("Rule11\n");*/
			yyval.integer = yystack.l_mark[-1].integer;
    }
break;
case 10:
#line 120 "ll.y"
	{
			/*printf("Rule12\n");*/
			yyval.integer = yystack.l_mark[0].integer;
    }
break;
case 11:
#line 127 "ll.y"
	{
			/*printf("Rule13\n");*/
			yyval.integer = yystack.l_mark[0].integer;
    }
break;
case 12:
#line 131 "ll.y"
	{
			/*printf("Rule14\n");*/
			yyval.integer = yystack.l_mark[0].integer;
    }
break;
case 13:
#line 135 "ll.y"
	{
			/*printf("Rule15\n");*/
			yyval.integer = yystack.l_mark[0].integer;
    }
break;
case 14:
#line 139 "ll.y"
	{
			/*printf("Rule16\n");		*/
			yyval.integer = yystack.l_mark[0].integer;
		}
break;
case 15:
#line 146 "ll.y"
	{ 
			/*printf("Rule17\n"); */
			yyval.integer = ind(yystack.l_mark[-3].integer,yystack.l_mark[-1].integer);
		}
break;
#line 593 "y.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            yychar = YYLEX;
            if (yychar < 0) yychar = YYEOF;
#if YYDEBUG
            if (yydebug)
            {
                if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == YYEOF) goto yyaccept;
        goto yyloop;
    }
    if (((yyn = yygindex[yym]) != 0) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    *++yystack.s_mark = (YYINT) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    YYERROR_CALL("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
