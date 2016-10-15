#include <stdio.h>
#include <unistd.h> // close and write
#include <string.h> // strlen

#include "strings.h"
#include "defns.h"

void *hndl_clnt(void *arg) 
{
    struct client *client = (struct client *)arg;
    int cntr = 0;

    while (cntr++ < 20) {
        write(client->fd, NEW_SCREEN, strlen(NEW_SCREEN)); 
        write(client->fd, ULAVACHAKARA_MANY, strlen(ULAVACHAKARA_MANY));
        sleep(1);
    }

    close(client->fd);

	return NULL;
}
