#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <wchar.h>

int read_char_ptr(char l, char r){
    FILE *file_ptr = fopen("./old_file.txt", "r+");
    char i;
    if (!file_ptr)
    {
        printf("Error al abrir archivo\n");
        exit(1);
    }
    while (fscanf(file_ptr,"%c",&i)!=EOF)
    {
        if (i==l)
        {
            fseek(file_ptr, -1, SEEK_CUR);
            fputc(r, file_ptr);
            fflush(file_ptr);
        }
    }
    fclose(file_ptr);
    return 0;
}
int main()
{
    char old,new;
    printf("Digite la letra a reemplazar y por cual reemplazarla mediante un espacio entre las dos \n");
    scanf("%c %c", &old, &new);
    int a = read_char_ptr(old,new);
}

