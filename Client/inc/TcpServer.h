//
// Created by danyl on 1/30/2021.
//

#ifndef MYSHELL_TCPSERVER_H
#define MYSHELL_TCPSERVER_H

#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include <string>

#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>

class TcpServer {
    int port;
    int server_fd;
    int listening_socket;
    int new_socket;
    int val_read;
    sockaddr_in hint;
    int opt = 1;

    TcpServer();

    createSocket() {
        listening_socket = socket(AF_INET, SOCK_STREAM, 0);
        if (listening_socket == -1) {
            std::cerr << "Can't create socket" << std::endl;
            throw std::runtime_error("Can't create socket");
        }
    };

    bindSocket() {
        hint.sin_family = AF_INET;
        hint.sin_port = htons(54000); // ntohs()
        inet_pton(AF_INET, "0.0.0.0", &hint.sin_addr);

        if (bind(listening_socket, AF_INET, &hint, sizeof(hint)) == -1) {
            std::cerr << "Can't bind to IP/port" << std::endl;
            throw std::runtime_error("Can't bind to IP/port");
        }

    };

    markListening() {
        if (listen(listening_socket, SOMAXCONN) == -1) {
            std::cerr << "Can't listen" << std::endl;
            throw std::runtime_error("Can't listen");
        }
    };

    acceptCall() {

    };

    closeSocket();



};


#endif //MYSHELL_TCPSERVER_H
