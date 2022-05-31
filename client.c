#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<errno.h>
#include<stdarg.h>
#include<arpa/inet.h>
#include<unistd.h>

#define BUFF 1024

int main (int argc, char **argv)
{
    int sockfd, err;
    struct sockaddr_in  serveraddr;

    if (argc != 2) {
        err = errno;
        printf("Usage: %s [ message ]\n", argv[0]);
        return EINVAL;
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        err = errno;
        perror("socket");
        return err;
    }

    memset(&serveraddr, 0, sizeof(serveraddr));
    serveraddr.sin_family   = AF_INET;
    serveraddr.sin_port     = htons(8080);

    err = connect(sockfd, (const struct sockaddr*) &serveraddr, sizeof(serveraddr));
    if (err < 0) {
        err = errno;
        perror("connect");
        return err;
    }

    err = send(sockfd, argv[1], strlen(argv[1]), 0);
    if (err < 0) {
        err = errno;
        perror("send");
        return err;
    }
    printf("send message to server");

    close(sockfd);
    shutdown(sockfd, SHUT_RDWR);

    return 0;
}