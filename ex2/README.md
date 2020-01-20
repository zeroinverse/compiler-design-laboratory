### Implementation of Lexical Analyzer using LEX tool

Write  Lexical  Analyzer  using  the  tool  LEX.  Your  scanner  will  run  through  the  source program  recognizing  C  tokens  in  the  order  in  which they  are  read,  until  end  of  file  is reached.  When  an  identifier  is  encountered,  it  should  be  stored  in  symbol  table  with  its attributes.  Symbol  table  consist  of  the  attributes identifier  name,  type,  no  of  bytes  and value. 

```
INPUT: from ./demo.txt
```

INPUT

```C
#include<stdio.h>

int main(){
    int a = 10, b = 20;
    if(a>b)
    printf("a is greater");
    else
    printf("b is greater");
}
```
OUTPUT

```

INPUT FILE
----------
1	#include<stdio.h>
2	
3	int main(){
4	    int a = 10, b = 20;
5	    if(a>b)
6	    printf("a is greater");
7	    else
8	printf("b is greater");
9	}

LEXICAL ANALYSIS
----------------

#include<stdio.h> PREPROCESSOR DIRECTIVE


	int is a KEYWORD 
FUNCTION 	main(	)

	{ SPECIAL CHARACTER
    
	int is a KEYWORD 
 a IDENTIFIER 
	 = is an ASSIGNMENT OPERATOR 10, 
 b IDENTIFIER 
	 = is an ASSIGNMENT OPERATOR 20;
    
FUNCTION 	if(
 a IDENTIFIER
	> is a RELATIONAL OPERATOR
 b IDENTIFIER	)

    
FUNCTION 	printf(
	 "a is greater" is a STRING	)
;
    
	else is a KEYWORD

FUNCTION 	printf(
	 "b is greater" is a STRING	)
;

	} SPECIAL CHARACTER

```