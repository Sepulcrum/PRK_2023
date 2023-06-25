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
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {
  int int_value;
  int integer;
  char* str_value;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
extern YYSTYPE yylval;
