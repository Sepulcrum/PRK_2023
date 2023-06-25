%{
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
//#include "prk-stack.h"
//#include "prints.h"

int yylex();
void yyerror(const char *s);
extern int yylineno;

int ind(int x, int bin);
%}

%union {
  int int_value;
  int integer;
  char* str_value;
}

%token L_BR
%token R_BR
%token PLUS
%token MPY
%token MOD
%token<integer> HEX_NUM
%token<integer> INT_NUM
%token<integer> BIN_NUM
%token<integer> OCT_NUM
%token LINE_END
%token FCE_IND

%type<integer> expr expr1 term term1 factor number
%type<integer> fceInd
%%

PetrLang:
    PetrLang fceInd LINE_END {
			//printf("Syntax OK, Rule1\n");
			//printf("Klasický tvar: %d\n", $2);
			printInd($2);
			printf("\n");
    } //Rule1
    /*| syntax LINE_END {
			printf("Syntax OK, Rule2\n");
			//printf("Klasický tvar: %d\n", $1);
			//printInd($1);
			printf("\n");
    } //Rule2*/
	| fceInd LINE_END{
			printf("Syntax OK, RULE IND\n");
			printInd($1);
	}	
    ;
/*syntax:
    expr {
			//printf("Rule3\n");
			$$ = $1;
    } // Rule3
    ;*/

expr:
    term expr1 {
			//printf("Rule5\n");
			$$ = $1 + $2;
		} // Rule5
    ;
expr1:
    PLUS term expr1 {
			//printf("Rule6\n");
			$$ = $2 + $3;
		} // Rule6
		| {
			//printf("Rule7\n");
			$$ = 0;
		} // Rule7
		;
term:
  	factor term1 {
			//printf("Rule8\n");
			$$ = $1 * $2;
   	} // Rule8
   	;

term1:
  	MPY factor term1 {
			//printf("Rule9\n");
			$$ = $2 * $3;
    } // Rule9
    | {
			//printf("Rule10\n");
			$$ = 1;
    } // Rule10
    ;
factor:
    L_BR expr R_BR{
			//printf("Rule11\n");
			$$ = $2;
    } // Rule11
    | number {
			//printf("Rule12\n");
			$$ = $1;
    } // Rule12
    ;

number:
    HEX_NUM {
			//printf("Rule13\n");
			$$ = $1;
    } // Rule13
    | INT_NUM {
			//printf("Rule14\n");
			$$ = $1;
    } // Rule14
    | BIN_NUM {
			//printf("Rule15\n");
			$$ = $1;
    } // Rule15
		| OCT_NUM{
			//printf("Rule16\n");		
			$$ = $1;
		} // Rule16
    ;

fceInd:
    FCE_IND L_BR expr MOD BIN_NUM R_BR { 
			//printf("Rule17\n"); 
			$$ = ind($3,$5);
		} // Rule17
    ;

%%

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
