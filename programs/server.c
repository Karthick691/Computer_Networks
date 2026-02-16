#include <stdio.h>
#include <winsock2.h>
#include <time.h>

#pragma comment(lib, "ws2_32.lib")

int main() {
    WSADATA wsa;
    SOCKET serverSock, clientSock;
    struct sockaddr_in serverAddr;
    char buffer[100];
    time_t t;

    WSAStartup(MAKEWORD(2,2), &wsa);

    serverSock = socket(AF_INET, SOCK_STREAM, 0);

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(8080);
    serverAddr.sin_addr.s_addr = INADDR_ANY;

    bind(serverSock, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
    listen(serverSock, 1);

    printf("Server waiting for client...\n");
    clientSock = accept(serverSock, NULL, NULL);

    time(&t);
    strcpy(buffer, ctime(&t));

    send(clientSock, buffer, strlen(buffer), 0);

    closesocket(clientSock);
    closesocket(serverSock);
    WSACleanup();

    return 0;
}
