sum: bSearch.o bubble.o db.o main.o parse.o set.o stack.o sum.o
	gcc -o sum bSearch.o bubble.o db.o main.o parse.o set.o stack.o sum.o

bSearch.o:bSearch.c sortAndSearch.h
	gcc -c bSearch.c sortAndSearch.h
	
bubble.o:bubble.c defs.h
	gcc -c bubble.c defs.h
	
db.o:db.c defs.h
	gcc -c db.c defs.h
	
main.o:main.c sum.h
	gcc -c main.c sum.h
	
parse.o:parse.c parse.h
	gcc -c parse.c parse.h
	
set.o:set.c set.h db.h
	gcc -c set.c set.h db.h
	
stack.o:stack.c stack.h
	gcc -c stack.c stack.h

sum.o:sum.c sum.h
	gcc -c sum.c sum.h
	
clean :
	rm bSearch.o bubble.o db.o main.o parse.o set.o stack.o sum.o db.h.gch defs.h.gch parse.h.gch set.h.gch stack.h.gch sum.h.gch sortAndSearch.h.gch
	
run:
	./sum