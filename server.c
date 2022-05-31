#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <stdarg.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFF 1024

int main(void)
{
	int sockfd, new_sock, err;
	ssize_t ret;
	struct sockaddr_in  serveraddr;
	char recv[BUFF];

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0) {
		err = errno;
		perror("socket");
		return err;
	}

	memset(&serveraddr, 0, sizeof(serveraddr));
<<<<<<< HEAD
	serveraddr.sin_family		= AF_INET;
=======
	serveraddr.sin_family	= AF_INET;
>>>>>>> 1942870 (v3)
	serveraddr.sin_port		= htons(8080);

	err = bind(sockfd, (struct sockaddr*) &serveraddr, sizeof(serveraddr));
	if (err < 0) {
		err = errno;
		perror("bind");
		close(sockfd);
		return err;
	}

	err = listen(sockfd, 1);
	if (err < 0) {
		err = errno;
		perror("listen");
		close(sockfd);
		return err;
	}

	socklen_t serveradrr_size = sizeof(serveraddr);
	new_sock = accept(sockfd, (struct sockaddr*) &serveraddr, &serveradrr_size);
	if (new_sock < 0) {
		err = errno;
		perror("accept");
		close(sockfd);
		close(new_sock);
		return err;
	}

read_:
	ret = read(new_sock, recv, sizeof(recv)-1);
	if (ret < 0) {
		perror("read");
		close(sockfd);
		close(new_sock);
		return ret;
	}

	if (ret == 0) {
		close(new_sock);
		close(sockfd);
		close(new_sock);
		return 0;
	}

	recv[ret] = '\0';
	printf("%s", recv);
<<<<<<< HEAD
	goto read_;
}
=======
	goto read_;2
}
>>>>>>> 1942870 (v3)
