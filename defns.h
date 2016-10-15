#include <stdio.h>

struct client {
    int fd;
    char *name;
    struct sockaddr_in *addr;
};

void *hndl_clnt(void *arg);
