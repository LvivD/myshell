#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include "Shell.h"

#define PORT 4444

int main(){

    int sockfd, ret;
    struct sockaddr_in serverAddr;

    int newSocket;
    struct sockaddr_in newAddr;

    socklen_t addr_size;

    char buffer[1024];
    pid_t childpid;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0){
        printf("[-]Error in connection.\n");
        exit(1);
    }
    printf("[+]Server Socket is created.\n");

    memset(&serverAddr, '\0', sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    ret = bind(sockfd, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
    if(ret < 0){
        printf("[-]Error in binding.\n");
        exit(1);
    }
    printf("[+]Bind to port %d\n", 4444);

    if(listen(sockfd, 10) == 0){
        printf("[+]Listening....\n");
    }else{
        printf("[-]Error in binding.\n");
    }


    while(true){
        newSocket = accept(sockfd, (struct sockaddr*)&newAddr, &addr_size);
        if(newSocket < 0){
            exit(1);
        }
        printf("Connection accepted from %s:%d\n", inet_ntoa(newAddr.sin_addr), ntohs(newAddr.sin_port));

        if((childpid = fork()) == 0){
            close(sockfd);

            Shell curr_shell;

            curr_shell.get_pwd(buffer);

            const char* var = "hello\0";
            std::cout << var << " " << strlen(var) << std::endl;

            send(newSocket, buffer, strlen(buffer), 0);

            while(true){
                recv(newSocket, buffer, 1024, 0);
                if(strncmp(buffer, ":q", 2) == 0){                                                                      // TODO: fix comparison with strcmp as for not anything that starts with :exit will disconnect the user
                    printf("Disconnected from %s:%d\n", inet_ntoa(newAddr.sin_addr), ntohs(newAddr.sin_port));
                    break;
                }else{
                    buffer[strlen(buffer)-1] = '\0';                                                                    // TODO: smt wrong with buffer size
                    printf("Client: %s; buffer size: %lu\n", buffer, strlen(buffer));
                    size_t buffer_size = strlen(buffer);
                    curr_shell.exec_line(buffer, &buffer_size);
                    send(newSocket, buffer, strlen(buffer), 0);
                    bzero(buffer, sizeof(buffer));

                }
            }

            close(newSocket);

            return 0;
        }

    }





}