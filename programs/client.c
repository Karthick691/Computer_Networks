#include <stdio.h>
#include <winsock2.h>

#pragma comment(lib, "ws2_32.lib")

int main() {
    WSADATA wsa;
    SOCKET sock;
    struct sockaddr_in serverAddr;
    char buffer[100];

    WSAStartup(MAKEWORD(2,2), &wsa);

    sock = socket(AF_INET, SOCK_STREAM, 0);

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(8080);
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    connect(sock, (struct sockaddr*)&serverAddr, sizeof(serverAddr));

    recv(sock, buffer, sizeof(buffer), 0);
    printf("Date and Time from Server: %s", buffer);

    closesocket(sock);
    WSACleanup();

    return 0;
}
