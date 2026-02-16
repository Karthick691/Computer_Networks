#include <stdio.h>
#include <string.h>
#include <winsock2.h>

#pragma comment(lib, "ws2_32.lib")

int main() {
    WSADATA wsa;
    SOCKET sock;
    struct sockaddr_in server, client;
    int len;
    char domain[100], ip[100];

    WSAStartup(MAKEWORD(2,2), &wsa);

    sock = socket(AF_INET, SOCK_DGRAM, 0);

    server.sin_family = AF_INET;
    server.sin_port = htons(53);
    server.sin_addr.s_addr = INADDR_ANY;

    bind(sock, (struct sockaddr*)&server, sizeof(server));

    printf("DNS Server running...\n");

    len = sizeof(client);
    recvfrom(sock, domain, sizeof(domain), 0,
             (struct sockaddr*)&client, &len);

    printf("Requested Domain: %s\n", domain);

    // Simple mapping
    if (strcmp(domain, "google.com") == 0)
        strcpy(ip, "142.250.72.14");
    else
        strcpy(ip, "IP not found");

    sendto(sock, ip, strlen(ip)+1, 0,
           (struct sockaddr*)&client, len);

    closesocket(sock);
    WSACleanup();
    return 0;
}
