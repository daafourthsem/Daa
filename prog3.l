%{
#include<stdio.h>
#include "y.tab.h"
extern int yylval;
%}

%%
[0-9]+ {
          yylval=atoi(yytext);
          return NUMBER;
       }
[\t] ;
[\n] return 0;
. return yytext[0];
%%
int yywrap()
{
return 1;
}




/*	lex prog2.l
	yacc -d prog2.y
	cc lex.yy.c y.tab.c -ll
	./a.out
*/
