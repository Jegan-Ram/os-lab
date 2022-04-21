#include <stdio.h>
#include <stdlib.h>
  
int main()
{
    FILE *fptr1;
    char filename[100], c;
  
    printf("Enter the filename to open for reading \n");
    scanf("%s", filename);

    fptr1 = fopen(filename, "r");
    if (fptr1 == NULL)
    {
        printf("Cannot open file %s \n", filename);
        exit(0);
    }

    c = fgetc(fptr1);
    while (c != EOF)
    {
        printf("%c",c);
        c = fgetc(fptr1);
    }
    fclose(fptr1);
    return 0;
}