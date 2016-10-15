all:
	gcc -g server.c client.c -o ulavachakara

clean:
	rm -rf *.o ulavachakara
