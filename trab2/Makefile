all: saida entrada.txt
	./saida < entrada.txt

lex.yy.c: simple_compiler.l
	lex simple_compiler.l

saida: lex.yy.c 
	g++ lex.yy.c -o saida -ll
	
clean:
	rm saida lex.yy.c