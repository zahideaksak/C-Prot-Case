#include <stdio.h>
#include "common.h"

int main(int argc, char *argv[]) {
    const char *usage = "<file path>";
    if (!checkArgs(argc, 2, usage)) {
        return 1;
    }

    const char *filePath = argv[1];
    FILE *file = fopen(filePath, "rb");

    if (!file) {
        perror("Dosya açılamadı.");
        return 1;
    }

    // Dosyanın ilk 2 baytı okunur
    unsigned char buffer[2];
    size_t bytesRead = fread(buffer, 1, 2, file);

    fclose(file);

    if (bytesRead < 2) {
        printf("Dosya okunamadı veya dosya 2 bayttan daha küçük\n");
        return 1;
    }

    printf("Dosyanın ilk iki baytı: %c%c\n", buffer[0], buffer[1]);

    return 0;
}
