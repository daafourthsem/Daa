%option noyywrap
%{
#include<stdio.h>
int line=1;
%}
%%
"int "|"float "|"char "|"string "|"auto "|"register "|"return "|"if"|"else"|"switch"|"case"|"exit"|"void "|"struct " {printf("%s\t%d\n",yytext,line);}
[\n] {line++;}
. {}
%%
int main()
{
	yyin=fopen("sic.txt","r");
	yylex();
}

int yyerror()
{
	return 0;
}

/*
	lex prog4.l
	cc lex.yy.c
	./a.out
*/
