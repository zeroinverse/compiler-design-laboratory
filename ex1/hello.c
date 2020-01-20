#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>

char symbols[] = {',', '<', '>', '.', '_', '(', ')', ';', '$', ':',
				'%', '[', ']', '#', '?', '&', '{', '}', 
				'^', '!', '*', '/', '|', '-', '\\', '~', '+'};

const char* keywords[] = {
	"auto",	"double",	"int",	"struct",
	"break",	"else",	"long",	"switch",
	"case",	"enum",	"register",	"typedef",
	"char",	"extern",	"return",	"union",
	"continue",	"for",	"signed",	"void",
	"do", "if",	"static",	"while",
	"default",	"goto",	"sizeof",	"volatile",
	"const",	"float",	"short",	"unsigned"
};

char * operators[] = {"++" , "--", "+" , "–" , "*" , "/", "==", ">=" , 
					  "<=", "&&", "||", "!", "!=", "&", "|", "<<", ">>", "~",
					  "^", "=", "+=", "-=", "*=", "/=", "%="};


struct table {
	char s[10];
	char val[10];
};

struct table t[20];

int t_count = 0;

void add_id_to_table(char* ms) {
	strcpy(t[t_count].s, ms);
}
void add_val_to_table(char* mval) {
	strcpy(t[t_count++].val, mval);
}

void display_table() {
	printf("\nSYMBOL TABLE");
	printf("\n------------");
	printf("\nIdentifier \t|Type \t|No of bytes \t|Value");
	for(int i=0; i<t_count; i++) {
		printf("\n|%s \t\t|%s \t|%s \t\t|%s", t[i].s, "int", "2", t[i].val);
	}
}

int parse_tokens(char* l){

	// keyword
	for(int i=0; i<32; i++) {
		if(strcmp(l, keywords[i]) == 0) {
			printf("{%s -Keyword} ", l);
			return 0;
		}
	}

	// function
	int ln = strlen(l);
	if(l[ln-1] == '\n')
		l[ln-1] = ' ';
	for(int i=0; i<ln; i++) {
		if(l[i] == '(') {
			for(int j=i+1; j<ln; j++) {
				if(l[j] == ')') {
					printf("{%s -Function Call}", l);
					return 0;
				}
			}
			break;
		}
	}

	// special symbol
	if(ln <= 2) {
		for(int i=0; i<sizeof(symbols)/sizeof(symbols[0]); i++) {
			if(l[0] == symbols[i]) {
				printf("{%s -Special Symbol}", l);
				return 0;
			}
		}
	}

	// operators
	for(int i=0; i<25; i++) {
		if(strcmp(l, operators[i]) == 0) {
			printf("{%s -Opeartor} ", l);
			return 0;
		}
	}

	// ternary operator
	for(int i=0; i<ln; i++) {
		if(l[i] == '?') {
			for(int j=i+1; j<ln; j++) {
				if(l[j] == ':') {
					printf("{%s -Ternary Operator}", l);
					return 0;
				}
			}
			break;
		}
	}

	// identifier
	if(l[0]==' ' || l[0]=='\n' || l[0]=='\t')
		return 0;
	if(l[0]<'0' || l[0]>'9') {
		printf("{%s -Identifier}", l);
		add_id_to_table(l);
		return 1;
	}
	printf("{%s -Integer Constant}", l);
	add_val_to_table(l);
	return 0;
}

void parse_line(char* l) {
	
	// test for file decriptor
	if(l[0] == '#') {
		int ln = strlen(l);
		if(l[ln-1] == '\n')
		l[ln-1] = ' ';
		printf("%s -Preprocessor Directive\n", l);
		return;
	}

	char* token = strtok(l, " ");
	while (token != NULL) { 
        // printf("%s ", token);
        int r = parse_tokens(token);
        token = strtok(NULL, " "); 
    }
    printf("\n");
}


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
	printf("\nLEXICAL ANALYSIS");
	printf("\n----------------\n");
	i = 1;
	fp=fopen("demo.txt", "r");
	while(fgets(s, sizeof(s), fp)) {
		printf("%d: ", i++); parse_line(s);

	}
	fclose(fp);
	printf("\n");
	display_table();
	printf("\n\n");
}