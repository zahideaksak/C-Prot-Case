#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include "common.h"

int main(int argc, char *argv[]) {
    const char *usage = "<directory path> <search term>";
    if (!checkArgs(argc, 3, usage)) {
        return 1;
    }

    const char *directory_path = argv[1];
    const char *search_term = argv[2];

    DIR *dir = opendir(directory_path);
    if (!dir) {
        perror("Klasör açılamadı");
        return 1;
    }

    struct dirent *entry;
    char file_path[1024];

    // Dizin içindeki dosyalar okunur
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_name[0] == '.') continue; // Gizli dosyaları atla

        snprintf(file_path, sizeof(file_path), "%s/%s", directory_path, entry->d_name);
        struct stat file_stat;
        if (stat(file_path, &file_stat) == 0 && S_ISREG(file_stat.st_mode)) {
            if (isPEFile(file_path)) {
                searchInPEFile(file_path, search_term);
            } else {
                printf("%s: Geçerli PE dosyası değil\n", file_path);
            }
        }
    }

    closedir(dir);
    
    return 0;
}
