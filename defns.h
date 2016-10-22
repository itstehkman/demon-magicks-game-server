#include <stdio.h>

struct client {
    int fd;
    char *name;
    struct sockaddr_in *addr;
	struct player *player;
};

struct player {
	int health;
};

struct ulavachakara {
	int health;
};

/* A thread is spawned and runs this function to handle a single client 
 * arg should point to a struct client
 */
void *hndl_clnt(void *arg);

/* hndl_client calls write_to_client to repeatedly print art to the client */
void write_to_client(struct client *client);
