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

void *hndl_clnt(void *arg);
