#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"

#define BUFFER_SIZE 1024

int searchInFile(const char *file_path, const char *search_term) {
    FILE *file = fopen(file_path, "rb");
    if (!file) {
        perror("Dosya açılamadı");
        return 1;
    }

    size_t search_term_length = strlen(search_term);
    char buffer[BUFFER_SIZE];
    long offset = 0;

    while (fread(buffer, 1, BUFFER_SIZE, file) > 0) {
        for (size_t i = 0; i < BUFFER_SIZE - search_term_length + 1; i++) {
            if (strncmp(&buffer[i], search_term, search_term_length) == 0) {
                fclose(file); 
                return offset + i;
            }
        }
        offset += BUFFER_SIZE;
    }

    fclose(file);
    
    return -1;
}

int checkArgs(int argc, int expected, const char *usage) {
    if (argc != expected) {
        fprintf(stderr, "Kullanım: %s\n", usage);
        return 0;
    }
    return 1;
}

int isPEFile(const char *filePath) {
    FILE *file = fopen(filePath, "rb");
    if (!file) {
        perror("Dosya açılamadı");
        return 0;
    }

    unsigned char buffer[2];
    size_t bytesRead = fread(buffer, 1, 2, file);
    fclose(file);

    if (bytesRead < 2) {
        return 0;
    }

    return (buffer[0] == 'M' && buffer[1] == 'Z');
}

int searchInPEFile(const char *filePath, const char *searchTerm) {
    if (!isPEFile(filePath)) {
        printf("%s: Geçerli PE dosyası değil\n", filePath);
        return 0;
    }
    return searchInFile(filePath, searchTerm);
}
