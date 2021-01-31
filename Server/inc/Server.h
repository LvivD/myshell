//
// Created by sotnyk on 31.01.21.
//

#ifndef MYSHELL_SERVER_H
#define MYSHELL_SERVER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 4444

class Server {
public:

    Server();

    int startServer();



private:
    int sockfd, ret;
    struct sockaddr_in serverAddr;

    int newSocket;
    struct sockaddr_in newAddr;

    socklen_t addr_size;

    char buffer[1024];
    pid_t childpid;

};


#endif //MYSHELL_SERVER_H
