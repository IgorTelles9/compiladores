all: saida entrada.txt
	./saida < entrada.txt

saida: lex.yy.c mini_js.tab.c
	g++ mini_js.tab.c -o saida -lfl	
	
lex.yy.c: mini_js.l
	lex mini_js.l
	
mini_js.tab.c: mini_js.y
	bison mini_js.y
	
clean: 
	rm -f lex.yy.c mini_js.tab.c saida