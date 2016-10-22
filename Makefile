all:
	gcc -g server.c hndl_clnt.c -o ulavachakara

clean:
	rm -rf *.o ulavachakara *.dSYM
