flexbison:
	/usr/local/Cellar/flex/2.6.4_1/bin/flex scanner.fl
	/usr/local/Cellar/bison/3.6.4/bin/bison -d parser.y
	gcc -o result lex.yy.c parser.tab.c symbol.tab.c
	./result < ../input/input.txt 
