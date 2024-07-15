#include <stdio.h>
#include "common.h"

int main(int argc, char *argv[]) {

    const char *usage = "<file path> <search term>";
    if (!checkArgs(argc, 3, usage)) {
        return 1;
    }

    // Dosya yolu ve aranacak ifade alınır.
    const char *file_path = argv[1];
    const char *search_term = argv[2];

    long offset = searchInFile(file_path, search_term);

    if (offset != -1) {
        printf("\"%s\" ifadesi %ld adresinde bulundu.\n", search_term, offset);
    } else {
        printf("\"%s\" ifadesi herhangi bir konumda bulunamadı.\n", search_term);
    }

    return 0;
}
