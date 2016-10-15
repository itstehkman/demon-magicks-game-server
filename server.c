#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <time.h>
#include <pthread.h>

#include "strings.h"
#include "defns.h"

int main(int argc, char **argv)
{
    int listenfd = 0, connfd = 0; 
    struct sockaddr_in serv_addr;

    char sendbfr[1025];
    time_t ticks;
    
    /* af_inet means ipv4, sock_stream means 2way bytestream
     * and 0 is default protocol, which kernel chooses as TCP
     */
    listenfd = socket(AF_INET, SOCK_STREAM, 0);

    // clear memory
    memset(&serv_addr, '0', sizeof(serv_addr));
    memset(sendbfr, '0', sizeof(sendbfr));
    
    // set address to localhost:5000
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY); // host2 ntwrk byte order 
    serv_addr.sin_port = htons(5000); // port 5000

    // associate the socket fd with the address
    bind(listenfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));

    fprintf(stderr, "%d:%d\n", serv_addr.sin_addr.s_addr, serv_addr.sin_port);
    // listen on the socket, with max connection queue len of 10
    listen(listenfd, 10);

    while (1) {
        // pop a listener off the connection queue (blocking)
        connfd = accept(listenfd, NULL, NULL);
      
        struct client *client = malloc(sizeof(struct client));
        client->fd = connfd;

        // handle client in its own thread
        pthread_t thread;
        pthread_create(&thread, NULL, hndl_clnt, (void *)client); 
    }

    pthread_exit(NULL);

    return 0;
}
