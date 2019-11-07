alpha [a-zA-Z]
digit [0-9]

%%

[\t \n]
for	return FOR;
{digit}+	return NUM;
{alpha}({alpha}|{digit})*   return ID;

"<="	return LE;
">="	return GE;
"=="	return EQ;
"!="	return NE;
"||"	return OR;
"&&"	return AND;
.	return yytext[0];

%%



/*
	lex prog5.l
	yacc -d prog5.y
	cc y.tab.c -ll -ly
	./a.out <i.in
*/
