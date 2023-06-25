%{
/*
PetrLang=syntax;
syntax=expr | fce;
expr=term, expr1;
expr1="+",term,expr1 |;
term=factor, term1;
term1="*", factor, term1 |;
factor="(", expr , ")"| number;
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
fce=fceName, "(", expr, mod,binNum,")";
fceName="IND";
*/

#include <stdio.h>
//#include "prk-stack.h"
//#include "prints.h"

int yylex();
void yyerror(const char *s);
extern int yylineno;

%}

%union {
  int int_value;
  char* str_value;
}

%token L_BR
%token R_BR
%token PLUS
%token MPY
%token MOD
%token HEX_NUM
%token INT_NUM
%token BIN_NUM
%token LINE_END
%token OCT_NUM
%token FCE_IND

%%

PetrLang:
    PetrLang syntax LINE_END { printf("Syntax OK, Rule1\n"); } //Rule1
    | syntax LINE_END { printf("Syntax OK, Rule2\n"); } //Rule2
    ;

syntax:
    expr { printf("Rule3\n"); } // Rule3
    | fce { printf("Rule4\n"); } // Rule4
    ;

expr:
    term expr1 { printf("Rule5\n"); } // Rule5
    ;

expr1:
    PLUS term expr1 { printf("Rule6\n"); } // Rule6
    | { printf("Rule7\n"); } // Rule7
    ;

term:
    factor term1 { printf("Rule8\n"); } // Rule8
    ;

term1:
    MPY factor term1 { printf("Rule9\n"); } // Rule9
    | { printf("Rule10\n"); } // Rule10
    ;

factor:
    L_BR expr R_BR{ printf("Rule11\n"); } // Rule11
    | number { printf("Rule12\n"); } // Rule12
    ;

number:
    HEX_NUM { printf("Rule13\n"); } // Rule13
    | INT_NUM { printf("Rule14\n"); } // Rule14
    | BIN_NUM { printf("Rule15\n"); } // Rule15
    | OCT_NUM { printf("Rule16\n"); } // Rule16
    ;

fce:
    fceName L_BR expr MOD BIN_NUM R_BR { printf("Rule17\n"); } // Rule17
    ;

fceName:
    FCE_IND { printf("Rule18\n"); } // Rule18
    ;

%%

void yyerror(const char *s) {
    printf("%s\n", s);
}

void main() {
    // yydebug = 1;
    printf("Entering the main");
    yyparse();
}
