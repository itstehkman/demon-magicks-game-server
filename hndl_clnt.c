#include <stdio.h>
#include <stdlib.h> // malloc
#include <unistd.h> // close and write
#include <string.h> // strlen

#include "strings.h"
#include "defns.h"

void write_to_client(struct client *client) 
{
	char *healthstr = malloc(BUFSIZ);
	sprintf(healthstr, HEALTH, 100, 100);
	
	write(client->fd, NEW_SCREEN, strlen(NEW_SCREEN)); 
	write(client->fd, NAMES, strlen(NAMES));
	write(client->fd, ULAVACHAKARA_MANY, strlen(ULAVACHAKARA_MANY));
	write(client->fd, healthstr, strlen(healthstr));
	write(client->fd, SPELLS, strlen(SPELLS)); 
}

void *hndl_clnt(void *arg) 
{
    struct client *client = (struct client *)arg;
    
	while (1) {
		write_to_client(client);
        sleep(1);
    }

    close(client->fd);

	return NULL;
}
