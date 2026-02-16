#include <stdio.h>
#include <string.h>
#include <winsock2.h>

#pragma comment(lib, "ws2_32.lib")

int main() {
    WSADATA wsa;
    SOCKET sock;
    struct sockaddr_in server;
    char domain[100], ip[100];
    int len;

    WSAStartup(MAKEWORD(2,2), &wsa);

    sock = socket(AF_INET, SOCK_DGRAM, 0);

    server.sin_family = AF_INET;
    server.sin_port = htons(53);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    printf("Enter domain name: ");
    scanf("%s", domain);

    sendto(sock, domain, strlen(domain)+1, 0,
           (struct sockaddr*)&server, sizeof(server));

    len = sizeof(server);
    recvfrom(sock, ip, sizeof(ip), 0,
             (struct sockaddr*)&server, &len);

    printf("IP Address: %s\n", ip);

    closesocket(sock);
    WSACleanup();
    return 0;
}
