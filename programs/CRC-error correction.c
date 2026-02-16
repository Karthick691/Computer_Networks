#include <stdio.h>
#include <string.h>

int main() {
    char data[50], divisor[20], temp[50];
    int dataLen, divLen, i, j;

    printf("Enter data bits: ");
    scanf("%s", data);

    printf("Enter divisor bits: ");
    scanf("%s", divisor);

    dataLen = strlen(data);
    divLen = strlen(divisor);

    /* Append zeros to data */
    for (i = 0; i < divLen - 1; i++) {
        data[dataLen + i] = '0';
    }
    data[dataLen + divLen - 1] = '\0';

    strcpy(temp, data);

    /* CRC Division */
    for (i = 0; i < dataLen; i++) {
        if (temp[i] == '1') {
            for (j = 0; j < divLen; j++) {
                temp[i + j] =
                    (temp[i + j] == divisor[j]) ? '0' : '1';
            }
        }
    }

    printf("CRC bits: ");
    for (i = dataLen; i < dataLen + divLen - 1; i++) {
        printf("%c", temp[i]);
    }

    printf("\nTransmitted frame: %s\n", data);
    return 0;
}
