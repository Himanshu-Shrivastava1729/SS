/*
============================================================================
Name : 34a.c
Author : Himanshu Shrivastava
Description :Write a program to create a concurrent server.
a. use fork
b. use pthread_create
Date: 21 Sept, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <pthread.h>
#include<stdbool.h>
#include<string.h>
#define BUFFER_SIZE 1024
#define PORT 8080
#define MAX_CLIENTS 3

void manage_client(int arg)
 {
    int clientSocket = arg;
    char buffer[BUFFER_SIZE];

    send(clientSocket,"ACK", strlen("ACK"),0);
    while (1) {
        int bytesRead = recv(clientSocket, buffer, sizeof(buffer), 0);
        if (bytesRead <= 0)
          {
            close(clientSocket);
            pthread_exit(NULL);
          }
         buffer[bytesRead] = '\0';

     
      if (strstr(buffer, "ACK") != NULL)
         {
                  send(clientSocket,"BYE", strlen("BYE"),0);
        }


}
    pthread_exit(NULL);
}



int main() 
  {
    int serverSocket, clientSocket;
    struct sockaddr_in serverAddress, clientAddress;
    socklen_t clientAddrLen = sizeof(clientAddress);

    
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == -1) 
    {
        perror("Socket error");
        exit(1);
    }

    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(PORT);
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    if (bind(serverSocket, (struct sockaddr *)&serverAddress, sizeof(serverAddress)) == -1) 
    {
        perror("Socket error");
        exit(1);
    }

    if (listen(serverSocket, MAX_CLIENTS) == -1)
    {
        perror("listen error");
        exit(1);
    }

    printf("Server is listening on port %d...\n", PORT);

    while (1)
{
      clientSocket = accept(serverSocket, (struct sockaddr *)&clientAddress, &clientAddrLen);
        if (clientSocket == -1) {
            perror("Accepting connection failed");
            continue;
        }

        int childPID = fork();
        if (childPID == -1) {
            perror("Fork failed");
            close(clientSocket);
        } else if (childPID == 0) {
            close(serverSocket); 
            manage_client(clientSocket);
            close(clientSocket);
            exit(0);
        } else {
            close(clientSocket);
   }

    close(serverSocket);

    return 0;
}

}
