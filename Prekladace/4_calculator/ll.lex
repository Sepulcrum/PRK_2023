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
#include "y.tab.h"

/* Function prototypes */

int process_pattern(int number, char *Message, int Pattern);
void print_error(int ERRNO);
void print_msg(char *msg);
int bin_to_int(char* binary);
int oct_to_int(char* octal);
int hex_to_int(char* hexadecimal);

%}
%%
^#.*\n  {lines_comment=process_pattern(lines_comment,"Comment deleted.\n",PATT_NO);}
\+      {
	add_ops=process_pattern(add_ops,"Add operator detected.",PATT_PLUS);
	return PLUS;
	}
\*      {
	mpy_ops=process_pattern(mpy_ops,"Multiplication operator detected.",PATT_MPY);
	return MPY;
	}
\%      {
	modulo_ops=process_pattern(modulo_ops,"Multiplication operator detected.",PATT_MOD);
	return MOD;
	}
\(      {
	br_left=process_pattern(br_left,"Opening bracket detected.",PATT_L_BR);
	return L_BR;
	}
\)	{
	br_right=process_pattern(br_right,"Closing bracket detected.",PATT_R_BR);
	return R_BR;
	} 
(?:0|[1-9][0-9]*)  {
	int_values=process_pattern(int_values,"Integer number detected.",PATT_INT_NUM);
	yylval.integer = atoi(yytext);
        return INT_NUM;
	}
b[0-1]+ {
	bin_values=process_pattern(bin_values,"Binary number detected.",PATT_BIN_NUM);
	yylval.integer = bin_to_int(yytext);
	//yylval.str_value = strdup(yytext);
        return BIN_NUM;
	}
o[0-7]+ {
	octet_values=process_pattern(octet_values,"Octet number detected.",PATT_OCT_NUM);
	yylval.integer = oct_to_int(yytext);
	//yylval.str_value = strdup(yytext);
        return OCT_NUM;
	}
h[0-9A-F]+  {
	hexa_values=process_pattern(hexa_values,"Hexadecimal number detected.",PATT_HEX_NUM);
	yylval.integer = hex_to_int(yytext);
	//yylval.str_value = strdup(yytext);
        return HEX_NUM;
	}
IND	{
	ind_function=process_pattern(ind_function,"IND function detected.",PATT_FCE_IND);
	return FCE_IND;
	}
^\n 	{void_lines_done++;
	    print_msg("Void line detected.\n");
	}
\n     	{lines_done++;
	    print_msg("Line detected.\n");
	    return LINE_END;
	}
.      	{errors_detected=process_pattern(errors_detected,"An error detected.\n",PATT_ERR);}
%%

/* Function declaration */

int yywrap(void) {
return 1;
}

void print_msg(char *msg){
    #ifdef VERBOSE
        printf("%s",msg);
    #endif
}

void print_error(int ERRNO){
    #ifdef VERBOSE
    char *message = Err_Messages[ERRNO];
    printf("%s - %d - %s\n",ErrMsgMain,ERR_PATTERN,message);
    #endif
}

int process_pattern(int number,char* Message, int Pattern) {
    if (Pattern == PATT_ERR) {       
        print_error(ERR_PATTERN);        
        //exit(ERR_PATTERN);
    }    

    print_msg(Message);
    
    number++;
    return number;
}

int hex_to_int(char* hex) {
    int result = 0;
    int i = 0;
    // Ignorování prefixu "h"
    if (hex[0] == 'h')
        i = 1;
    // Konverze hexadecimálního čísla na integer
    for (; hex[i] != '\0'; i++) {
        result = result * 16;
        if (hex[i] >= '0' && hex[i] <= '9')
            result += hex[i] - '0';
        else if (hex[i] >= 'A' && hex[i] <= 'F')
            result += hex[i] - 'A' + 10;
        else {
            printf("Chybný vstup!\n");
            return 0;
        }
    }
    return result;
}

int oct_to_int(char* octalNumber) {
    int decimalNumber = 0;
	int i = 0;
    int power = 1;
    if (octalNumber[0] == 'o')
        i = 1;
    int result = 0;
    for (; octalNumber[i] != '\0'; i++) {
		result = result*10;
		result += octalNumber[i]-'0'; 
    }
    result = octalToDecimal(result);
    return result;
}
int octalToDecimal(int n)
{
    int decimalvalue = 0;
    int base = 1;
    int temp = n;
    while (temp)
    {
        int lastdigit = temp % 10;
        temp = temp / 10;
        decimalvalue += lastdigit * base;
        base = base * 8;
    }
    return decimalvalue;
}

int bin_to_int(char* expr) {
    int count = 0;
    int i = 0;
    // Ignorování prefixu "b"
    if (expr[0] == 'b')
        i = 1;
    // Počítání nul ve zbytku výrazu
    while (expr[i] != '\0') {
	count = count * 2;
        if (expr[i] == '1')
            count++;
        i++;
    }
    return count;
}

