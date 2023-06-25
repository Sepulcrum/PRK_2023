%{
/* Variable declaration */
int lines_done=0;
int void_lines_done=0;
int lines_comment=0;
int add_ops=0;
int mpy_ops=0;
int ind_function=0;
int br_left=0;
int br_right=0;
int int_values=0;
int bin_values = 0;
int octet_values=0;
int hexa_values=0;
int errors_detected=0;
int modulo_ops = 0;

#include "ll.h"

/* Function prototypes */

int process_pattern(int number, char *Message);

%}
%%
^#.*\n  {lines_comment=process_pattern(lines_comment,"Comment deleted.\n");}
\+      {printf("+ detected\n");add_ops=process_pattern(add_ops,"Add operator detected.");}
\*      {mpy_ops=process_pattern(mpy_ops,"Multiplication operator detected.");}
\(      {br_left=process_pattern(br_left,"Opening bracket detected.");}
\)	{br_right=process_pattern(br_right,"Closing bracket detected.");} 
[1-9][0-9]*	{int_values=process_pattern(int_values,"Ineger number detected.");}
0	{int_values=process_pattern(int_values,"Ineger number detected.");}
b[0-1]+ {bin_values=process_pattern(bin_values,"Binary number detected.");}
h[0-9A-F]+ 	{hexa_values=process_pattern(hexa_values,"Hexadecimal number detected.");}
IND\(	{ind_function=process_pattern(ind_function,"Ind function detected.");}
\%	{modulo_ops=process_pattern(modulo_ops, "Modulo detected.");}
o[0-7]+	{octet_values=process_pattern(octet_values,"Octet number detected.");}
^\n 	{void_lines_done++;printf("Void line detected.\n");}
\n     	{lines_done++;printf("Line detected.\n");}
.      	{errors_detected=process_pattern(errors_detected,"An error detected.\n");}
%%
/* Main part */
int yywrap(){};
int main()
    {
        yylex();
        printf("%d of total errors detected in input file.\n",errors_detected);
        printf("%d of int numbers detected.\n",int_values);
	printf("%d of bin numbers detected.\n",bin_values);
        printf("%d of hexa numbers detected.\n",hexa_values);
	printf("%d of octet numbers detected.\n",octet_values);
        printf("%d of comment lines canceled.\n",lines_comment);
        printf("%d of add operators detected.\n",add_ops);
        printf("%d of modulo operators detected.\n",modulo_ops);
        printf("%d of multiplication operators detected.\n",mpy_ops);
        printf("%d of opening brackets detected.\n",br_left);
        printf("%d of closing brackets detected.\n",br_right);
        printf("%d of ind function detected.\n",ind_function);
        printf("%d of void lines ignored.\nFile processed sucessfully.\n",void_lines_done);
        printf("Totally %d of valid code lines in file processed.\nFile processed sucessfully.\n",lines_done);
        
    }

/* Function declaration */

int process_pattern(int number,char* Message) {
    #ifdef VERBOSE 
        printf("%s",Message);
    #endif
    number++;
    return number;
}
