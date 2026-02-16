#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <net/if_arp.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main() {
    int sock;
    struct arpreq req;

    sock = socket(AF_INET, SOCK_DGRAM, 0);

    memset(&req, 0, sizeof(req));

    // Set IP address
    struct sockaddr_in *sin = (struct sockaddr_in *)&req.arp_pa;
    sin->sin_family = AF_INET;
    sin->sin_addr.s_addr = inet_addr("192.168.1.1");

    // Network interface
    strcpy(req.arp_dev, "eth0");

    // Get ARP entry
    ioctl(sock, SIOCGARP, &req);

    // Print MAC address
    printf("MAC Address: %02X:%02X:%02X:%02X:%02X:%02X\n",
        (unsigned char)req.arp_ha.sa_data[0],
        (unsigned char)req.arp_ha.sa_data[1],
        (unsigned char)req.arp_ha.sa_data[2],
        (unsigned char)req.arp_ha.sa_data[3],
        (unsigned char)req.arp_ha.sa_data[4],
        (unsigned char)req.arp_ha.sa_data[5]);

    close(sock);
    return 0;
}
