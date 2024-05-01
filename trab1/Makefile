all: saida entrada.txt
	./saida < entrada.txt

lex.yy.c: analisadorLexico.l
	lex analisadorLexico.l

saida: lex.yy.c analisadorLexicoMain.cc 
	g++ lex.yy.c analisadorLexicoMain.cc -o saida -ll
	
clean:
	rm saida lex.yy.c
	