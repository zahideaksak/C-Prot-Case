#ifndef COMMON_H
#define COMMON_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

// Dosyanın "MALWARE" ifadesini içerip içermediğini kontrol eder
int searchInFile(const char *file_path, const char *search_term);

// Komut satırı argümanlarının sayısını kontrol eder
int checkArgs(int argc, int expected, const char *usage);

// Dosyanın PE formatında olup olmadığını kontrol eder
int isPEFile(const char *file_path);

// PE dosyasındaki "executable" flag'ına sahip section'larda arama yapar
int searchInPEFile(const char *file_path, const char *search_term);

#endif
