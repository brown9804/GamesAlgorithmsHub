#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <wchar.h>

int main(){
    FILE *file_ptr = fopen("./old_file.txt", "r");

    if (!file_ptr)
    {
        printf("Error al abrir archivo\n");
        exit(1);
    }
    fclose(file_ptr);
    rename("old_file.txt","new_file.txt");
    return 0;
}

