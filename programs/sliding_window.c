#include <stdio.h>

int main() {
    int windowSize, totalFrames;
    int sent = 0, ack;
    int i;   // <-- declare here (IMPORTANT)

    printf("Enter total number of frames: ");
    scanf("%d", &totalFrames);

    printf("Enter window size: ");
    scanf("%d", &windowSize);

    while (sent < totalFrames) {
        printf("\nSending frames: ");

        for (i = sent; i < sent + windowSize && i < totalFrames; i++) {
            printf("%d ", i);
        }

        printf("\nEnter last ACK received: ");
        scanf("%d", &ack);

        if (ack >= sent)
            sent = ack + 1;
        else
            printf("Invalid ACK\n");
    }

    printf("\nAll frames sent successfully.\n");
    return 0;
}
