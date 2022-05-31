#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <stdarg.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFF 1024

int main(int argc, char **argv)
{
	int             sockfd, err;
	ssize_t         ret;
	size_t          sendbytes;
	const char     *sendline;
	struct          sockaddr_in  serveraddr;

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
		close(sockfd);
		return err;
	}

	sendline = argv[1];
	sendbytes = strlen(argv[1]);

<<<<<<< HEAD
write_:
    ret = send(sockfd, sendline, sendbytes, 0);
    if (ret <= 0) {
        if (ret == 0) {
            puts("server error while send data");
            close(sockfd);
            return ENETDOWN;
        }

        err = errno;
        if (err == EINTR)
            goto write_; 
        
        perror("send");
        close(sockfd);
        return err;
    }
=======
	write_:
	ret = send(sockfd, sendline, sendbytes, 0);
	if (ret <= 0) {
		if (ret == 0) {
			puts("server error while send data");
			close(sockfd);
			return ENETDOWN;
		}

		err = errno;
		if (err == EINTR)
			goto write_; 
>>>>>>> 1942870 (v3)

		perror("send");
		close(sockfd);
		return err;
	}

	sendbytes -= (size_t)ret;
	if (sendbytes > 0) {
		sendline += (size_t)ret;
		goto write_;
	}

	printf("send message to server");

<<<<<<< HEAD
    return 0;
}
=======
	close(sockfd);

	return 0;
}
>>>>>>> 1942870 (v3)
