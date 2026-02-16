#include <stdio.h>
#include <winsock2.h>
#include <iphlpapi.h>

int main() {
    DWORD destIP;
    ULONG macAddr[2];
    ULONG macLen = 6;

    destIP = inet_addr("192.168.1.1");

    if (SendARP(destIP, 0, macAddr, &macLen) == NO_ERROR) {
        BYTE *mac = (BYTE*)macAddr;
        printf("MAC Address: %02X:%02X:%02X:%02X:%02X:%02X\n",
               mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);
    } else {
        printf("ARP request failed\n");
    }
    return 0;
}
