%{
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
int COMMENT=0;
%}
identifier [a-zA-Z][a-zA-Z0-9]*
%option noyywrap
%%
#.* {printf("\n%s PREPROCESSOR DIRECTIVE",yytext);}

int |
float |
char |
double |
while |
for |
struct |
typedef |
do |
if |
break |
continue |
void |
switch |
return |
else |
goto {printf("\n\t%s is a KEYWORD",yytext);}

"/*" {COMMENT=1;}{printf("\n\t %s is a COMMENT",yytext);}

"*/" {COMMENT=0;}{printf("\n\t %s is a COMMENT",yytext);}

{identifier}\( {if(!COMMENT)printf("\nFUNCTION \t%s",yytext);}

\{  {if(!COMMENT)printf("\n\t%s SPECIAL CHARACTER", yytext);}

\}  {if(!COMMENT)printf("\n\t%s SPECIAL CHARACTER", yytext);}

{identifier}(\[[0-9]*\])? {if(!COMMENT) printf("\n %s IDENTIFIER", yytext);}

\)(\:)? {if(!COMMENT)printf("\t");ECHO;printf("\n");}

\".*\" {if(!COMMENT)printf("\n\t %s is a STRING",yytext);}

\( ECHO;
= {if(!COMMENT)printf("\n\t %s is an ASSIGNMENT OPERATOR",yytext);}

\<= |
\>= |
\< |
== |
\> {if(!COMMENT) printf("\n\t%s is a RELATIONAL OPERATOR",yytext);}
%%

int main() { 


	FILE *fp;
	char s[1024];
	int i = 1;
	printf("\nINPUT FILE");
	printf("\n----------\n");

	fp=fopen("demo.txt", "r");
	while(fgets(s, sizeof(s), fp)) {
		printf("%d\t", i++); 
		printf("%s",s);
	}
	printf("\n");
	printf("\n");
	fclose(fp);

	printf("LEXICAL ANALYSIS\n");
	printf("----------------\n");
	FILE *fd = fopen("demo.txt", "r");
	if(!fd) {
		printf("file opening error");
	}
	yyin = fd;
	yylex();
	printf("\n\n");
	return 0;
}
