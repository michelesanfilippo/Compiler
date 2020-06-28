%{
	#include <stdio.h>
	#include "symbol.tab.h"
	int yylex();
	void yyerror (char const *);
%}

%define parse.error verbose

%union {
	char *string;
}

%token <string>		DATE AUTHOR TITLE CODE NAME FISCALCODE LOANCODE
%token				SEPARATOR_1 ARROW SEMICOLON DASH SEPARATOR_2 OPEN_ROUND CLOSE_ROUND 
					COLUMN DOT 

%start Start

%%

Start	: Head SEPARATOR_1 Body SEPARATOR_2 End 
		;

Head	: DATE
		;
		
Body	: Body AUTHOR ARROW BodyRow DASH { addAuthor($2); }
		| AUTHOR ARROW BodyRow DASH { addAuthor($1); }
		;

BodyRow : TITLE DOT CODE SEMICOLON BodyRow {
			insertBook($1, $3);
		}
        | TITLE DOT CODE { 
			insertBook($1, $3); 
		}
        ;

End     : NAME FISCALCODE OPEN_ROUND EndRow CLOSE_ROUND End
        | NAME FISCALCODE OPEN_ROUND EndRow CLOSE_ROUND 
        ;

EndRow  : LOANCODE COLUMN DATE SEMICOLON EndRow { 
			insertTaken($1, $3);
		}
        | LOANCODE COLUMN DATE { 
			insertTaken($1, $3);
		}
        |  
        ;

%%

void yyerror (char const *s) { 
	fprintf(stderr, "%s\n", s);
}

int main() {
	initialize();
	yyparse();
	print();
	return 0; 
}

