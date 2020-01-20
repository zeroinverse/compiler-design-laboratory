### Implementation of a Barebones Lexical Analyzer in C programming language- Lab Assignment

this by no means is a acceptible lexical analyzer; this exercise is just to get started with the lab. The programs will work only for ideal inputs.


```
INPUT: from ./demo.txt
```

INPUT

```C
#include<stdio.h>
#include<stdlib.h>

int main() {
int a, b ;
a = 3 ;
b = 5 ;
printf("\n%d",a+b) ;
}
```
OUTPUT

```

INPUT FILE
----------
1	#include<stdio.h>
2	#include<stdlib.h>
3	
4	int main() {
5	int a, b ;
6	a = 3 ;
7	b = 5 ;
8	printf("\n%d",a+b) ;
9	}



LEXICAL ANALYSIS
----------------
1: #include<stdio.h>  -Preprocessor Directive
2: #include<stdlib.h>  -Preprocessor Directive
3: 
4: {int -Keyword} {main() -Function Call}{{  -Special Symbol}
5: {int -Keyword} {a, -Identifier}{b -Identifier}{;  -Special Symbol}
6: {a -Identifier}{= -Opeartor} {3 -Integer Constant}{;  -Special Symbol}
7: {b -Identifier}{= -Opeartor} {5 -Integer Constant}{;  -Special Symbol}
8: {printf("\n%d",a+b) -Function Call}{;  -Special Symbol}
9: {}  -Special Symbol}


SYMBOL TABLE
------------
Identifier|Type |No of bytes  |Value
|a        |int  |2            |3
|b        |int  |2            |5


```
